#!/usr/bin/env python3
"""Plan or transactionally install the QIDI PLR runtime hardening.

Dry-run is the default.  Applying changes requires both ``--apply`` and the
explicit ``--klipper-stopped`` acknowledgement; the installer also refuses to
proceed unless the exact ``klipper.service`` unit is observably inactive.  It never
restarts a service or connects to a printer, which makes its JSON mode suitable
for a Printerlab-controlled upload-and-execute deployment.

This file intentionally remains compatible with CPython 3.7.
"""

from __future__ import annotations

import argparse
import hashlib
import io
import json
import os
import re
import shlex
import shutil
import stat
import subprocess
import sys
import tempfile

import patch_virtual_sdcard

try:
    import pwd
except ImportError:  # pragma: no cover - exercised by Windows development
    pwd = None


ROOT = os.path.dirname(os.path.abspath(__file__))
MANIFEST_PATH = os.path.join(ROOT, "manifest.json")
RUNTIME_MANIFEST_NAME = "plr-hardening-runtime.json"
KLIPPER_SERVICE = "klipper.service"
ACCOUNT_HOME_ROOT = "/home"
ACCOUNT_NAME = re.compile(r"^[a-z_][a-z0-9_-]{0,31}$")
TRANSACTION_ID = re.compile(r"^[A-Za-z0-9][A-Za-z0-9._-]{0,95}$")
PASSWD_LOOKUP = pwd.getpwnam if pwd is not None else None
IS_POSIX = os.name == "posix"
ENFORCE_POSIX_DIRECTORY_MODE = IS_POSIX


class InstallError(Exception):
    """Raised before or during a guarded installation."""


class TransactionError(InstallError):
    """A mutation failed after a durable recovery manifest was written."""

    def __init__(
        self,
        message,
        transaction_state,
        backup_manifest=None,
        safety_manifest=None,
        applied=None,
    ):
        super().__init__(message)
        self.transaction_state = transaction_state
        self.backup_manifest = backup_manifest
        self.safety_manifest = safety_manifest
        self.applied = applied


class DirectoryMetadataMutationError(InstallError):
    """A held directory inode may have been changed before an operation failed."""


def _sha256_bytes(data):
    return hashlib.sha256(data).hexdigest()


def _read_bytes(path):
    try:
        with io.open(path, "rb") as source_file:
            return source_file.read()
    except OSError as exc:
        raise InstallError("cannot read %s: %s" % (path, exc))


def _load_package_manifest():
    try:
        manifest = json.loads(_read_bytes(MANIFEST_PATH).decode("utf-8"))
    except (UnicodeDecodeError, ValueError) as exc:
        raise InstallError("package manifest is invalid: %s" % exc)
    if manifest.get("schema") != "qidi-plus4-plr-hardening/v1":
        raise InstallError("unsupported package manifest schema")
    assets = manifest.get("assets")
    if not isinstance(assets, list) or not assets:
        raise InstallError("package manifest has no assets")
    loaded = {}
    for item in assets:
        if not isinstance(item, dict):
            raise InstallError("package manifest asset is not an object")
        source = item.get("source")
        expected = item.get("sha256")
        if not isinstance(source, str) or os.path.basename(source) != source:
            raise InstallError("package manifest contains an unsafe source path")
        data = _read_bytes(os.path.join(ROOT, source))
        actual = _sha256_bytes(data)
        if actual != expected:
            raise InstallError(
                "package asset hash mismatch for %s: expected %s, got %s"
                % (source, expected, actual)
            )
        loaded[(source, item.get("target"))] = (item, data)
    return manifest, loaded


def _require_directory(path, label):
    path = os.path.realpath(os.path.abspath(path))
    if not os.path.isdir(path):
        raise InstallError("%s directory does not exist: %s" % (label, path))
    return path


def _require_file(path, label):
    path = os.path.realpath(os.path.abspath(path))
    if not os.path.isfile(path):
        raise InstallError("%s file does not exist: %s" % (label, path))
    return path


def _require_unlinked_directory(path, label):
    absolute = os.path.abspath(path)
    if os.path.realpath(absolute) != absolute or os.path.islink(absolute):
        raise InstallError("%s directory must not contain symlinks: %s" % (label, absolute))
    if not os.path.isdir(absolute):
        raise InstallError("%s directory does not exist: %s" % (label, absolute))
    return absolute


def _require_unlinked_file(path, label):
    absolute = os.path.abspath(path)
    if os.path.realpath(absolute) != absolute or os.path.islink(absolute):
        raise InstallError("%s file must not contain symlinks: %s" % (label, absolute))
    if not os.path.isfile(absolute):
        raise InstallError("%s file does not exist: %s" % (label, absolute))
    return absolute


def _require_executable_path(path, label):
    absolute = os.path.abspath(path)
    if not os.path.isfile(absolute):
        raise InstallError("%s file does not exist: %s" % (label, absolute))
    return absolute


def _canonical_layout(account):
    if not isinstance(account, str) or not ACCOUNT_NAME.fullmatch(account):
        raise InstallError("printer user is not a safe Linux account name")
    home = os.path.abspath(os.path.join(ACCOUNT_HOME_ROOT, account))
    printer_data = os.path.join(home, "printer_data")
    scripts_dir = os.path.join(home, "scripts", "plr")
    gcode_root = os.path.join(printer_data, "gcodes")
    return {
        "home": home,
        "klipper_dir": os.path.join(home, "klipper"),
        "printer_data": printer_data,
        "scripts_dir": scripts_dir,
        "python": os.path.join(home, "klippy-env", "bin", "python"),
        "gcode_root": gcode_root,
        "checkpoint": os.path.join(scripts_dir, "plr_checkpoint.json"),
        "record": os.path.join(scripts_dir, "plr_record"),
        "output": os.path.join(gcode_root, ".plr", "plr.gcode"),
    }


def _bind_canonical_layout(args):
    paths = _canonical_layout(args.printer_user)
    supplied = {
        "klipper_dir": args.klipper_dir,
        "printer_data": args.printer_data,
        "scripts_dir": args.scripts_dir,
        "python": args.python,
        "gcode_root": args.gcode_root,
        "checkpoint": args.checkpoint,
        "record": args.record,
        "output": args.output,
    }
    for key, value in supplied.items():
        if value is None:
            continue
        if os.path.abspath(value) != paths[key]:
            raise InstallError(
                "%s must be the canonical path for printer user %s: %s"
                % (key, args.printer_user, paths[key])
            )
    return paths


def _passwd_entry(account):
    if PASSWD_LOOKUP is None:
        raise InstallError("the OS passwd database is unavailable")
    try:
        entry = PASSWD_LOOKUP(account)
    except KeyError:
        raise InstallError("printer user is not present in the OS passwd database")
    if entry.pw_name != account:
        raise InstallError("OS passwd lookup returned a different printer user")
    return entry


def _account_identity(account, paths):
    entry = _passwd_entry(account)
    if entry.pw_dir != paths["home"]:
        raise InstallError(
            "printer user's passwd home must be exactly %s" % paths["home"]
        )
    try:
        uid = int(entry.pw_uid)
        gid = int(entry.pw_gid)
    except (TypeError, ValueError):
        raise InstallError("printer user's passwd ownership is invalid")
    if uid < 0 or gid < 0:
        raise InstallError("printer user's passwd ownership is invalid")
    return (uid, gid)


def _verify_account_owner(path, expected, label):
    stat_result = os.stat(path)
    actual = (int(stat_result.st_uid), int(stat_result.st_gid))
    if actual != tuple(expected):
        raise InstallError(
            "%s ownership does not match the printer user's passwd entry: %s"
            % (label, path)
        )


def _metadata_from_stat(path, stat_result):
    return {
        "path": os.path.abspath(path),
        "dev": int(stat_result.st_dev),
        "ino": int(stat_result.st_ino),
        "uid": int(stat_result.st_uid),
        "gid": int(stat_result.st_gid),
        # S_IMODE deliberately includes the setuid, setgid, and sticky bits.
        # fchown may clear those bits, so ownership changes must restore this
        # complete mode afterwards rather than preserving only 0777.
        "mode": int(stat.S_IMODE(stat_result.st_mode)),
    }


def _same_directory_metadata(left, right):
    return all(
        left.get(key) == right.get(key)
        for key in ("path", "dev", "ino", "uid", "gid", "mode")
    )


def _same_directory_identity(left, right):
    return all(
        left.get(key) == right.get(key) for key in ("path", "dev", "ino")
    )


def _desired_scripts_directory_metadata(original, account_owner):
    desired = dict(original)
    desired["uid"] = int(account_owner[0])
    desired["gid"] = int(account_owner[1])
    if ENFORCE_POSIX_DIRECTORY_MODE:
        desired["mode"] = int(original["mode"]) & ~0o022
    return desired


def _open_verified_directory(path, label):
    """Open one exact real directory and bind the fd to its path identity."""

    absolute = _require_unlinked_directory(path, label)
    before = os.lstat(absolute)
    if not stat.S_ISDIR(before.st_mode) or stat.S_ISLNK(before.st_mode):
        raise InstallError("%s must be a real directory: %s" % (label, absolute))
    if not IS_POSIX:
        return None, _metadata_from_stat(absolute, before)
    nofollow = getattr(os, "O_NOFOLLOW", None)
    directory_flag = getattr(os, "O_DIRECTORY", None)
    if nofollow is None or directory_flag is None:
        raise InstallError(
            "cannot safely open %s because O_NOFOLLOW/O_DIRECTORY is unavailable"
            % label
        )
    flags = os.O_RDONLY | nofollow | directory_flag | getattr(os, "O_CLOEXEC", 0)
    try:
        fd = os.open(absolute, flags)
    except OSError as exc:
        raise InstallError("cannot safely open %s: %s" % (label, exc))
    try:
        opened = os.fstat(fd)
        after = os.lstat(absolute)
        identities = (
            (int(before.st_dev), int(before.st_ino)),
            (int(opened.st_dev), int(opened.st_ino)),
            (int(after.st_dev), int(after.st_ino)),
        )
        if (
            not stat.S_ISDIR(opened.st_mode)
            or stat.S_ISLNK(after.st_mode)
            or len(set(identities)) != 1
            or os.path.realpath(absolute) != absolute
        ):
            raise InstallError("%s directory identity changed while opening" % label)
        return fd, _metadata_from_stat(absolute, opened)
    except Exception:
        os.close(fd)
        raise


def _directory_metadata(path, label):
    fd, metadata = _open_verified_directory(path, label)
    if fd is not None:
        os.close(fd)
    return metadata


def _fsync_directory(path, label):
    """Durably publish directory entries through one verified directory fd."""

    if not IS_POSIX:
        return
    fd, _metadata = _open_verified_directory(path, label)
    try:
        os.fsync(fd)
    except OSError as exc:
        raise InstallError("cannot fsync %s: %s" % (label, exc))
    finally:
        if fd is not None:
            os.close(fd)


def _set_directory_metadata(path, desired, label, expected=None):
    """Set metadata on one held directory inode; never traverse its children."""

    fd, current = _open_verified_directory(path, label)
    mutation_started = False
    operation_error = None
    try:
        if not _same_directory_identity(current, desired):
            raise InstallError("%s directory identity no longer matches" % label)
        if expected is not None and not _same_directory_metadata(current, expected):
            raise InstallError("%s directory metadata changed after planning" % label)
        if not IS_POSIX:
            if not _same_directory_metadata(current, desired):
                raise InstallError("%s metadata changes require POSIX" % label)
            return
        if fd is None or not hasattr(os, "fchown") or not hasattr(os, "fchmod"):
            raise InstallError("cannot safely update %s metadata" % label)
        # fchown can clear setgid/setuid.  Reapply the complete recorded mode
        # after changing ownership, then fsync the directory inode itself.
        mutation_started = True
        os.fchown(fd, desired["uid"], desired["gid"])
        os.fchmod(fd, desired["mode"])
        os.fsync(fd)
    except Exception as exc:
        operation_error = exc
    finally:
        if fd is not None:
            try:
                os.close(fd)
            except Exception as exc:
                if operation_error is None:
                    operation_error = exc
    if operation_error is not None:
        if mutation_started:
            raise DirectoryMetadataMutationError(
                "%s metadata update may be partial: %s" % (label, operation_error)
            )
        raise operation_error
    try:
        verified = _directory_metadata(path, label)
        if not _same_directory_metadata(verified, desired):
            raise InstallError("%s metadata update was not verified" % label)
    except Exception as exc:
        if IS_POSIX:
            raise DirectoryMetadataMutationError(
                "%s metadata update may be partial: %s" % (label, exc)
            )
        raise


def _manifest_directory_metadata(metadata):
    return {
        "path": metadata["path"],
        "dev": int(metadata["dev"]),
        "ino": int(metadata["ino"]),
        "uid": int(metadata["uid"]),
        "gid": int(metadata["gid"]),
        "mode": "%04o" % int(metadata["mode"]),
    }


def _parse_manifest_directory_metadata(value, path, label):
    if not isinstance(value, dict) or value.get("path") != path:
        raise InstallError("%s metadata path is invalid" % label)
    try:
        metadata = {
            "path": path,
            "dev": int(value.get("dev")),
            "ino": int(value.get("ino")),
            "uid": int(value.get("uid")),
            "gid": int(value.get("gid")),
            "mode": int(str(value.get("mode")), 8),
        }
    except (TypeError, ValueError):
        raise InstallError("%s metadata is invalid" % label)
    if (
        metadata["dev"] < 0
        or metadata["ino"] <= 0
        or metadata["uid"] < 0
        or metadata["gid"] < 0
        or metadata["uid"] > 0xFFFFFFFF
        or metadata["gid"] > 0xFFFFFFFF
        or metadata["mode"] < 0
        or metadata["mode"] > 0o7777
    ):
        raise InstallError("%s metadata is unsafe" % label)
    return metadata


def _planned_manifest(scripts_dir, transaction_id, prefix, filename):
    if not isinstance(transaction_id, str) or not TRANSACTION_ID.fullmatch(
        transaction_id
    ):
        raise InstallError("a safe --transaction-id is required")
    directory = os.path.abspath(
        os.path.join(scripts_dir, "backups", prefix + transaction_id)
    )
    return os.path.join(directory, filename)


def _safe_shell_path(path, label):
    if "\x00" in path or "\n" in path or "\r" in path:
        raise InstallError("%s contains an unsafe character" % label)
    return shlex.quote(path)


def _render_wrapper(template, paths):
    try:
        text = template.decode("utf-8")
    except UnicodeDecodeError as exc:
        raise InstallError("wrapper template is not UTF-8: %s" % exc)
    replacements = {
        "@PYTHON@": _safe_shell_path(paths["python"], "Python path"),
        "@GENERATOR@": _safe_shell_path(paths["generator"], "generator path"),
        "@CHECKPOINT@": _safe_shell_path(paths["checkpoint"], "checkpoint path"),
        "@GCODE_ROOT@": _safe_shell_path(paths["gcode_root"], "G-code root"),
        "@OUTPUT@": _safe_shell_path(paths["output"], "output path"),
    }
    for token, value in replacements.items():
        if text.count(token) != 1:
            raise InstallError("wrapper token %s must occur exactly once" % token)
        text = text.replace(token, value)
    if "@" in text:
        raise InstallError("wrapper contains an unresolved template token")
    return text.encode("utf-8")


def _target_action(path, data, mode):
    if not os.path.lexists(path):
        return "create"
    if not os.path.isfile(path) or os.path.islink(path):
        raise InstallError("refusing non-regular or symlink target: %s" % path)
    current = _read_bytes(path)
    current_mode = os.stat(path).st_mode & 0o777
    mode_matches = os.name != "posix" or mode is None or current_mode == mode
    if current == data and mode_matches:
        return "unchanged"
    return "replace"


def build_plan(args):
    if args.service != KLIPPER_SERVICE:
        raise InstallError("service must be exactly %s" % KLIPPER_SERVICE)
    bound_paths = _bind_canonical_layout(args)
    account_owner = _account_identity(args.printer_user, bound_paths)
    _package, assets = _load_package_manifest()
    home_dir = _require_unlinked_directory(bound_paths["home"], "printer home")
    klipper_dir = _require_unlinked_directory(bound_paths["klipper_dir"], "Klipper")
    printer_data = _require_unlinked_directory(
        bound_paths["printer_data"], "printer data"
    )
    scripts_dir = _require_unlinked_directory(
        bound_paths["scripts_dir"], "PLR scripts"
    )
    scripts_metadata = _directory_metadata(scripts_dir, "PLR scripts")
    scripts_desired_metadata = _desired_scripts_directory_metadata(
        scripts_metadata, account_owner
    )
    scripts_directory_action = (
        "normalize-metadata"
        if not _same_directory_metadata(scripts_metadata, scripts_desired_metadata)
        else "unchanged"
    )
    if (scripts_metadata["mode"] & 0o300) != 0o300:
        raise InstallError(
            "PLR scripts directory mode must grant its eventual owner write and execute"
        )
    extras_dir = _require_unlinked_directory(
        os.path.join(klipper_dir, "klippy", "extras"), "Klipper extras"
    )
    virtual_sdcard = _require_unlinked_file(
        os.path.join(extras_dir, "virtual_sdcard.py"), "virtual_sdcard.py"
    )
    python_path = _require_executable_path(bound_paths["python"], "Klippy Python")
    gcode_root = _require_unlinked_directory(
        bound_paths["gcode_root"], "G-code root"
    )
    for path, label in (
        (home_dir, "printer home"),
        (klipper_dir, "Klipper"),
        (printer_data, "printer data"),
        (gcode_root, "G-code root"),
    ):
        _verify_account_owner(path, account_owner, label)
    checkpoint = bound_paths["checkpoint"]
    record = bound_paths["record"]
    output = bound_paths["output"]
    plr_directory = os.path.abspath(os.path.join(gcode_root, ".plr"))
    gcode_stat = os.stat(gcode_root)
    plr_directory_action = "create"
    if os.path.lexists(plr_directory):
        if os.path.islink(plr_directory) or not os.path.isdir(plr_directory):
            raise InstallError("G-code root/.plr must be a real directory")
        plr_stat = os.stat(plr_directory)
        if os.name == "posix" and (
            plr_stat.st_uid != gcode_stat.st_uid or plr_stat.st_gid != gcode_stat.st_gid
        ):
            raise InstallError("G-code root/.plr ownership differs from the G-code root")
        plr_directory_action = "unchanged"
    try:
        output_within_plr = os.path.commonpath((output, plr_directory)) == plr_directory
    except ValueError:
        output_within_plr = False
    if not output_within_plr:
        raise InstallError("recovery output must be inside G-code root/.plr")
    for path, label in ((checkpoint, "checkpoint"), (record, "legacy record")):
        if os.path.dirname(path) != scripts_dir:
            raise InstallError("%s must be directly inside the PLR scripts directory" % label)

    try:
        patched_text, patch_needed = patch_virtual_sdcard.patch_file(
            virtual_sdcard, checkpoint, record
        )
    except patch_virtual_sdcard.PatchError as exc:
        raise InstallError(str(exc))
    patched_bytes = patched_text.encode("utf-8")
    helper = assets[("plr_checkpoint.py", "klipper-extra")][1]
    helper_scripts = assets[("plr_checkpoint.py", "scripts")][1]
    generator = assets[("generate_recovery.py", "scripts")][1]
    wrapper_template = assets[("plr.sh.in", "wrapper-template")][1]

    runtime_paths = {
        "python": python_path,
        "checkpoint": checkpoint,
        "record": record,
        "gcode_root": gcode_root,
        "output": output,
        "generator": os.path.join(scripts_dir, "generate_recovery.py"),
        "wrapper": os.path.join(scripts_dir, "plr.sh"),
    }
    wrapper = _render_wrapper(wrapper_template, runtime_paths)
    runtime_manifest_path = os.path.join(scripts_dir, RUNTIME_MANIFEST_NAME)
    runtime_manifest = {
        "schema": "qidi-plus4-plr-runtime/v1",
        "version": 1,
        "paths": runtime_paths,
        "virtual_sdcard": virtual_sdcard,
        "power_loss_resume_command": "bash %s" % runtime_paths["wrapper"],
        "update_gcode_lines_required": False,
        "assets": {},
    }
    descriptors = [
        {
            "role": "generator",
            "path": runtime_paths["generator"],
            "data": generator,
            "mode": 0o644,
        },
        {
            "role": "scripts-checkpoint-helper",
            "path": os.path.join(scripts_dir, "plr_checkpoint.py"),
            "data": helper_scripts,
            "mode": 0o644,
        },
        {
            "role": "power-loss-resume-wrapper",
            "path": runtime_paths["wrapper"],
            "data": wrapper,
            "mode": 0o755,
        },
        {
            "role": "klipper-checkpoint-helper",
            "path": os.path.join(extras_dir, "plr_checkpoint.py"),
            "data": helper,
            "mode": 0o644,
        },
        {
            "role": "virtual-sdcard-patch",
            "path": virtual_sdcard,
            "data": patched_bytes,
            "mode": None,
        },
    ]
    for descriptor in descriptors:
        runtime_manifest["assets"][descriptor["role"]] = {
            "path": descriptor["path"],
            "sha256": _sha256_bytes(descriptor["data"]),
        }
    manifest_bytes = (
        json.dumps(runtime_manifest, indent=2, sort_keys=True) + "\n"
    ).encode("utf-8")
    descriptors.append(
        {
            "role": "runtime-manifest",
            "path": runtime_manifest_path,
            "data": manifest_bytes,
            "mode": 0o644,
        }
    )
    seen = set()
    actions = []
    for descriptor in descriptors:
        normalized = os.path.abspath(descriptor["path"])
        if normalized in seen:
            raise InstallError("deployment target occurs more than once: %s" % normalized)
        seen.add(normalized)
        descriptor["path"] = normalized
        descriptor["action"] = _target_action(
            normalized, descriptor["data"], descriptor["mode"]
        )
        actions.append(
            {
                "role": descriptor["role"],
                "path": normalized,
                "action": descriptor["action"],
                "sha256": _sha256_bytes(descriptor["data"]),
            }
        )
    actions.append(
        {
            "role": "scripts-directory-ownership",
            "path": scripts_dir,
            "action": scripts_directory_action,
            "uid": int(scripts_desired_metadata["uid"]),
            "gid": int(scripts_desired_metadata["gid"]),
            "mode": "%04o" % int(scripts_desired_metadata["mode"]),
        }
    )
    plan_changed = (
        scripts_directory_action == "normalize-metadata"
        or plr_directory_action == "create"
        or any(item["action"] != "unchanged" for item in descriptors)
    )
    planned_backup_manifest = (
        _planned_manifest(
            scripts_dir,
            args.transaction_id,
            "plr-hardening-",
            "backup-manifest.json",
        )
        if plan_changed
        else None
    )
    return {
        "schema": "qidi-plus4-plr-install-plan/v1",
        "dry_run": not args.apply,
        "changed": plan_changed,
        "patch_needed": patch_needed,
        "actions": actions,
        "descriptors": descriptors,
        "plr_directory": plr_directory,
        "plr_directory_action": plr_directory_action,
        "plr_ownership": (int(gcode_stat.st_uid), int(gcode_stat.st_gid)),
        "account": args.printer_user,
        "paths": bound_paths,
        "backup_manifest": planned_backup_manifest,
        "safety_manifest": None,
        "scripts_dir": scripts_dir,
        "scripts_directory": {
            "path": scripts_dir,
            "action": scripts_directory_action,
            "original": scripts_metadata,
            "desired": scripts_desired_metadata,
        },
        "scripts_directory_action": scripts_directory_action,
        "service": KLIPPER_SERVICE,
        "power_loss_resume_command": "bash %s" % runtime_paths["wrapper"],
        "update_gcode_lines_required": False,
    }


def _check_service_stopped(service):
    if service != KLIPPER_SERVICE:
        raise InstallError("service must be exactly %s" % KLIPPER_SERVICE)
    systemctl = shutil.which("systemctl")
    if systemctl is None:
        raise InstallError(
            "cannot prove %s inactive because systemctl is unavailable" % service
        )
    completed = subprocess.run(
        [systemctl, "is-active", "--quiet", service],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    if completed.returncode == 0:
        raise InstallError("refusing installation while %s is active" % service)
    if completed.returncode != 3:
        raise InstallError(
            "could not prove %s inactive (systemctl exit %d)"
            % (service, completed.returncode)
        )
    return "inactive"


def _atomic_install(path, data, mode, ownership=None):
    directory = os.path.dirname(path)
    fd, temporary = tempfile.mkstemp(
        prefix=".%s." % os.path.basename(path), suffix=".tmp", dir=directory
    )
    try:
        desired_mode = mode if mode is not None else 0o644
        if hasattr(os, "fchmod"):
            os.fchmod(fd, desired_mode)
        if ownership is not None and hasattr(os, "fchown"):
            try:
                os.fchown(fd, ownership[0], ownership[1])
            except PermissionError:
                if (os.getuid() if hasattr(os, "getuid") else ownership[0]) != ownership[0]:
                    raise
        with os.fdopen(fd, "wb") as output_file:
            fd = -1
            output_file.write(data)
            output_file.flush()
            os.fsync(output_file.fileno())
        os.replace(temporary, path)
        if os.name == "posix":
            directory_fd = os.open(
                directory,
                os.O_RDONLY | getattr(os, "O_DIRECTORY", 0),
            )
            try:
                os.fsync(directory_fd)
            finally:
                os.close(directory_fd)
    except Exception:
        if fd >= 0:
            os.close(fd)
        try:
            os.unlink(temporary)
        except OSError:
            pass
        raise


def _ensure_plr_directory(plan):
    path = plan["plr_directory"]
    expected_owner = tuple(plan["plr_ownership"])
    if not os.path.lexists(path):
        os.mkdir(path, 0o755)
        if hasattr(os, "chown"):
            try:
                os.chown(path, expected_owner[0], expected_owner[1])
            except PermissionError:
                current_uid = os.getuid() if hasattr(os, "getuid") else expected_owner[0]
                if current_uid != expected_owner[0]:
                    raise
    if os.path.islink(path) or not os.path.isdir(path):
        raise InstallError("G-code root/.plr became unsafe")
    stat_result = os.stat(path)
    if os.name == "posix" and (
        stat_result.st_uid != expected_owner[0] or stat_result.st_gid != expected_owner[1]
    ):
        raise InstallError("G-code root/.plr has unsafe ownership")


def _mode(path):
    return os.stat(path).st_mode & 0o777


def _effective_owner():
    if os.name != "posix":
        return None
    return (os.geteuid(), os.getegid())


def _verify_owner(path, expected, label):
    if os.name != "posix" or expected is None:
        return
    stat_result = os.stat(path)
    if (stat_result.st_uid, stat_result.st_gid) != tuple(expected):
        raise InstallError("%s has unsafe ownership: %s" % (label, path))


def _secure_backup_root(scripts_dir, create, allow_legacy_scripts_mode=False):
    scripts_dir = _require_unlinked_directory(scripts_dir, "PLR scripts")
    if IS_POSIX and _mode(scripts_dir) & 0o022 and not allow_legacy_scripts_mode:
        raise InstallError("PLR scripts directory must not be group/world writable")
    backup_root = os.path.abspath(os.path.join(scripts_dir, "backups"))
    if os.path.dirname(backup_root) != scripts_dir:
        raise InstallError("backup root is not directly inside PLR scripts")
    created = False
    if os.path.lexists(backup_root):
        if os.path.islink(backup_root) or not os.path.isdir(backup_root):
            raise InstallError("backup root must be a real directory")
    elif create:
        os.mkdir(backup_root, 0o700)
        if os.name == "posix":
            os.chmod(backup_root, 0o700)
        created = True
    else:
        raise InstallError("backup root does not exist: %s" % backup_root)
    if os.path.realpath(backup_root) != backup_root:
        raise InstallError("backup root must not contain symlinks")
    try:
        contained = os.path.commonpath((backup_root, scripts_dir)) == scripts_dir
    except ValueError:
        contained = False
    if not contained:
        raise InstallError("backup root escapes PLR scripts")
    _verify_owner(backup_root, _effective_owner(), "backup root")
    if IS_POSIX and _mode(backup_root) != 0o700:
        raise InstallError("backup root mode must be exactly 0700")
    if created:
        _fsync_directory(scripts_dir, "PLR scripts")
    return backup_root


def _secure_transaction_directory(path, backup_root, prefix):
    path = os.path.abspath(path)
    if os.path.dirname(path) != backup_root or not os.path.basename(path).startswith(
        prefix
    ):
        raise InstallError("transaction directory is outside the secure backup root")
    if os.path.realpath(path) != path or os.path.islink(path) or not os.path.isdir(path):
        raise InstallError("transaction directory must be a real contained directory")
    _verify_owner(path, _effective_owner(), "transaction directory")
    if os.name == "posix" and _mode(path) != 0o700:
        raise InstallError("transaction directory mode must be exactly 0700")
    return path


def _create_transaction_directory(backup_root, prefix):
    path = tempfile.mkdtemp(prefix=prefix, dir=backup_root)
    if os.name == "posix":
        os.chmod(path, 0o700)
    path = _secure_transaction_directory(path, backup_root, prefix)
    _fsync_directory(backup_root, "backup root")
    return path


def _verify_target_state(path, data, mode, ownership):
    if data is None:
        if os.path.lexists(path):
            raise InstallError("target should be absent: %s" % path)
        return
    if os.path.islink(path) or not os.path.isfile(path):
        raise InstallError("target is not a regular file: %s" % path)
    if _sha256_bytes(_read_bytes(path)) != _sha256_bytes(data):
        raise InstallError("target hash mismatch: %s" % path)
    if os.name == "posix":
        stat_result = os.stat(path)
        if (stat_result.st_mode & 0o777) != mode:
            raise InstallError("target mode mismatch: %s" % path)
        if (stat_result.st_uid, stat_result.st_gid) != tuple(ownership):
            raise InstallError("target ownership mismatch: %s" % path)


def _inspect_removable_plr_directory(path, ownership):
    absolute = os.path.abspath(path)
    if (
        os.path.realpath(absolute) != absolute
        or os.path.islink(absolute)
        or not os.path.isdir(absolute)
    ):
        raise InstallError("installer-created .plr path is not a real directory")
    stat_result = os.stat(absolute)
    actual_owner = (int(stat_result.st_uid), int(stat_result.st_gid))
    if actual_owner != tuple(ownership):
        raise InstallError(
            "installer-created .plr directory ownership no longer matches "
            "the printer account"
        )
    if os.listdir(absolute):
        raise InstallError("installer-created .plr directory is not empty")
    return stat_result.st_mode & 0o777


def _remove_created_plr_directory(path, ownership):
    _inspect_removable_plr_directory(path, ownership)
    os.rmdir(path)
    if os.path.lexists(path):
        raise InstallError("installer-created .plr directory removal was not verified")


def _restore_plr_directory(path, mode, ownership):
    if os.path.lexists(path):
        _inspect_removable_plr_directory(path, ownership)
    else:
        os.mkdir(path, mode)
        if hasattr(os, "chown"):
            os.chown(path, ownership[0], ownership[1])
    if os.name == "posix":
        os.chmod(path, mode)
    restored_mode = _inspect_removable_plr_directory(path, ownership)
    if os.name == "posix" and restored_mode != mode:
        raise InstallError("installer-created .plr directory mode was not restored")


def apply_plan(plan):
    changed = [
        item for item in plan["descriptors"] if item["action"] != "unchanged"
    ]
    create_plr_directory = plan["plr_directory_action"] == "create"
    normalize_scripts_directory = (
        plan["scripts_directory_action"] == "normalize-metadata"
    )
    if not changed and not create_plr_directory and not normalize_scripts_directory:
        return None
    current_scripts_metadata = _directory_metadata(
        plan["scripts_dir"], "PLR scripts"
    )
    if not _same_directory_metadata(
        current_scripts_metadata, plan["scripts_directory"]["original"]
    ):
        raise InstallError("PLR scripts directory metadata changed after planning")
    backup_root = _secure_backup_root(
        plan["scripts_dir"],
        create=True,
        allow_legacy_scripts_mode=bool(
            plan["scripts_directory"]["original"]["mode"] & 0o022
        ),
    )
    manifest_path = plan["backup_manifest"]
    backup_dir = os.path.dirname(manifest_path)
    if os.path.lexists(backup_dir):
        raise InstallError("planned backup transaction directory already exists")
    os.mkdir(backup_dir, 0o700)
    if os.name == "posix":
        os.chmod(backup_dir, 0o700)
    _secure_transaction_directory(backup_dir, backup_root, "plr-hardening-")
    _fsync_directory(backup_root, "backup root")
    original = []
    backup_manifest = {
        "schema": "qidi-plus4-plr-backup/v1",
        "account": plan["account"],
        "paths": plan["paths"],
        "plr_directory_created": create_plr_directory,
        "scripts_directory": {
            "original": _manifest_directory_metadata(
                plan["scripts_directory"]["original"]
            ),
            "desired": _manifest_directory_metadata(
                plan["scripts_directory"]["desired"]
            ),
        },
        "scripts_directory_metadata_normalized": normalize_scripts_directory,
        "files": [],
    }
    backup_manifest_bytes = None
    try:
        for index, item in enumerate(changed):
            target = item["path"]
            if os.path.lexists(target):
                if os.path.islink(target) or not os.path.isfile(target):
                    raise InstallError("installation target became unsafe: %s" % target)
                stat_result = os.stat(target)
                data = _read_bytes(target)
                backup = os.path.join(
                    backup_dir, "%02d-%s" % (index, os.path.basename(target))
                )
                # Backup payloads contain the original file bytes but do not
                # need the original access mode.  Keep every recovery artifact
                # private; the original mode is recorded separately below.
                _atomic_install(backup, data, 0o600)
                original.append((item, data, stat_result, backup))
                backup_manifest["files"].append(
                    {
                        "target": target,
                        "backup": backup,
                        "sha256": _sha256_bytes(data),
                        "mode": "%04o" % (stat_result.st_mode & 0o777),
                        "uid": int(stat_result.st_uid),
                        "gid": int(stat_result.st_gid),
                    }
                )
            else:
                original.append((item, None, None, None))
                backup_manifest["files"].append(
                    {"target": target, "backup": None, "created_by_install": True}
                )
        backup_manifest_bytes = (
            json.dumps(backup_manifest, indent=2, sort_keys=True) + "\n"
        ).encode("utf-8")
        _atomic_install(
            manifest_path,
            backup_manifest_bytes,
            0o600,
        )
    except Exception as exc:
        shutil.rmtree(backup_dir, ignore_errors=True)
        raise InstallError(
            "could not create durable installation backup: %s" % exc
        )
    normalization_started = False
    normalization_completed = False
    try:
        if normalize_scripts_directory:
            try:
                _set_directory_metadata(
                    plan["scripts_dir"],
                    plan["scripts_directory"]["desired"],
                    "PLR scripts",
                    expected=plan["scripts_directory"]["original"],
                )
            except DirectoryMetadataMutationError:
                normalization_started = True
                raise
            normalization_completed = True
        # The legacy parent may have been group/world writable while the
        # recovery artifacts were created.  Once its exact held inode has been
        # normalized, re-resolve every recovery handle before touching .plr or
        # any deployment target.  A one-shot rename, swap, or content change
        # therefore refuses the install while compensation can still restore
        # the original directory metadata.
        verified_backup_root = _secure_backup_root(
            plan["scripts_dir"], create=False
        )
        if verified_backup_root != backup_root:
            raise InstallError("installation backup root changed after planning")
        _secure_transaction_directory(
            backup_dir, verified_backup_root, "plr-hardening-"
        )
        verified_manifest = _require_unlinked_file(
            manifest_path, "installation backup manifest"
        )
        _verify_owner(
            verified_manifest, _effective_owner(), "installation backup manifest"
        )
        if os.name == "posix" and _mode(verified_manifest) != 0o600:
            raise InstallError("installation backup manifest mode must be exactly 0600")
        if _read_bytes(verified_manifest) != backup_manifest_bytes:
            raise InstallError("installation backup manifest changed after publication")
        _ensure_plr_directory(plan)
        for item, _old_data, old_stat, _backup in original:
            mode = item["mode"]
            if mode is None and old_stat is not None:
                mode = old_stat.st_mode & 0o777
            if old_stat is not None:
                ownership = (old_stat.st_uid, old_stat.st_gid)
            else:
                parent_stat = os.stat(os.path.dirname(item["path"]))
                ownership = (parent_stat.st_uid, parent_stat.st_gid)
            _atomic_install(item["path"], item["data"], mode, ownership)
            _verify_target_state(item["path"], item["data"], mode, ownership)
    except Exception as exc:
        rollback_errors = []
        for item, old_data, old_stat, _backup in reversed(original):
            try:
                if old_data is None:
                    if os.path.lexists(item["path"]):
                        os.unlink(item["path"])
                    _verify_target_state(item["path"], None, None, None)
                else:
                    ownership = (old_stat.st_uid, old_stat.st_gid)
                    old_mode = old_stat.st_mode & 0o777
                    _atomic_install(
                        item["path"],
                        old_data,
                        old_mode,
                        ownership,
                    )
                    _verify_target_state(
                        item["path"], old_data, old_mode, ownership
                    )
            except Exception as rollback_exc:
                rollback_errors.append("%s: %s" % (item["path"], rollback_exc))
        if create_plr_directory:
            try:
                if os.path.isdir(plan["plr_directory"]) and not os.listdir(
                    plan["plr_directory"]
                ):
                    os.rmdir(plan["plr_directory"])
                if os.path.lexists(plan["plr_directory"]):
                    raise InstallError("created .plr directory is not empty")
            except Exception as rollback_exc:
                rollback_errors.append(
                    "%s: %s" % (plan["plr_directory"], rollback_exc)
                )
        if normalization_started or normalization_completed:
            try:
                _set_directory_metadata(
                    plan["scripts_dir"],
                    plan["scripts_directory"]["original"],
                    "PLR scripts",
                    expected=(
                        plan["scripts_directory"]["desired"]
                        if normalization_completed
                        else None
                    ),
                )
            except Exception as rollback_exc:
                rollback_errors.append(
                    "%s: %s" % (plan["scripts_dir"], rollback_exc)
                )
        elif normalize_scripts_directory:
            try:
                observed = _directory_metadata(plan["scripts_dir"], "PLR scripts")
                if not _same_directory_metadata(
                    observed, plan["scripts_directory"]["original"]
                ):
                    raise InstallError(
                        "PLR scripts metadata changed outside the transaction"
                    )
            except Exception as rollback_exc:
                rollback_errors.append(
                    "%s: %s" % (plan["scripts_dir"], rollback_exc)
                )
        detail = (
            "; rollback errors: %s" % "; ".join(rollback_errors)
            if rollback_errors
            else ""
        )
        state = "partial" if rollback_errors else "auto_rolled_back"
        applied = None if rollback_errors else False
        raise TransactionError(
            "installation failed and rollback was attempted: %s%s" % (exc, detail),
            state,
            backup_manifest=manifest_path,
            applied=applied,
        )
    return backup_dir


def build_rollback_plan(args):
    if args.service != KLIPPER_SERVICE:
        raise InstallError("service must be exactly %s" % KLIPPER_SERVICE)
    bound_paths = _bind_canonical_layout(args)
    account_owner = _account_identity(args.printer_user, bound_paths)
    home_dir = _require_unlinked_directory(bound_paths["home"], "printer home")
    scripts_dir = _require_unlinked_directory(
        bound_paths["scripts_dir"], "PLR scripts"
    )
    klipper_dir = _require_unlinked_directory(bound_paths["klipper_dir"], "Klipper")
    printer_data = _require_unlinked_directory(
        bound_paths["printer_data"], "printer data"
    )
    gcode_root = _require_unlinked_directory(
        bound_paths["gcode_root"], "G-code root"
    )
    for path, label in (
        (home_dir, "printer home"),
        (klipper_dir, "Klipper"),
        (printer_data, "printer data"),
        (gcode_root, "G-code root"),
    ):
        _verify_account_owner(path, account_owner, label)
    extras_dir = _require_unlinked_directory(
        os.path.join(klipper_dir, "klippy", "extras"), "Klipper extras"
    )
    manifest_path = os.path.abspath(args.rollback_manifest)
    backup_root = os.path.abspath(os.path.join(scripts_dir, "backups"))
    backup_dir = os.path.dirname(manifest_path)
    if os.path.basename(manifest_path) != "backup-manifest.json":
        raise InstallError("rollback path must name backup-manifest.json")
    if os.path.dirname(backup_dir) != backup_root or not os.path.basename(
        backup_dir
    ).startswith("plr-hardening-"):
        raise InstallError("rollback manifest is outside a PLR hardening backup directory")
    # The original canonical directory may deliberately be group/world
    # writable after a completed explicit rollback.  The root-owned 0700
    # backup tree and manifest are validated first; the exact original mode is
    # then authorized only by that durable manifest below.
    backup_root = _secure_backup_root(
        scripts_dir, create=False, allow_legacy_scripts_mode=True
    )
    _secure_transaction_directory(backup_dir, backup_root, "plr-hardening-")
    manifest_path = _require_unlinked_file(manifest_path, "rollback manifest")
    _verify_owner(manifest_path, _effective_owner(), "rollback manifest")
    if os.name == "posix" and _mode(manifest_path) != 0o600:
        raise InstallError("rollback manifest mode must be exactly 0600")
    try:
        manifest = json.loads(_read_bytes(manifest_path).decode("utf-8"))
    except (UnicodeDecodeError, ValueError) as exc:
        raise InstallError("rollback manifest is invalid: %s" % exc)
    if manifest.get("schema") != "qidi-plus4-plr-backup/v1":
        raise InstallError("unsupported rollback manifest schema")
    if manifest.get("account") != args.printer_user:
        raise InstallError("rollback manifest printer account does not match")
    if manifest.get("paths") != bound_paths:
        raise InstallError("rollback manifest canonical paths do not match")
    scripts_original_metadata = _parse_manifest_directory_metadata(
        (
            manifest.get("scripts_directory", {}).get("original")
            if isinstance(manifest.get("scripts_directory"), dict)
            else None
        ),
        scripts_dir,
        "rollback original PLR scripts",
    )
    if (scripts_original_metadata["mode"] & 0o300) != 0o300:
        raise InstallError(
            "rollback PLR scripts mode denies its eventual owner write and execute"
        )
    scripts_manifest_desired = _parse_manifest_directory_metadata(
        (
            manifest.get("scripts_directory", {}).get("desired")
            if isinstance(manifest.get("scripts_directory"), dict)
            else None
        ),
        scripts_dir,
        "rollback desired PLR scripts",
    )
    scripts_metadata_normalized = manifest.get(
        "scripts_directory_metadata_normalized"
    )
    if not isinstance(scripts_metadata_normalized, bool):
        raise InstallError("rollback PLR scripts normalization state is invalid")
    scripts_desired_metadata = _desired_scripts_directory_metadata(
        scripts_original_metadata, account_owner
    )
    if not _same_directory_metadata(
        scripts_manifest_desired, scripts_desired_metadata
    ):
        raise InstallError("rollback desired PLR scripts metadata is invalid")
    metadata_was_different = not _same_directory_metadata(
        scripts_original_metadata, scripts_desired_metadata
    )
    if scripts_metadata_normalized != metadata_was_different:
        raise InstallError("rollback PLR scripts normalization state is inconsistent")
    scripts_current_metadata = _directory_metadata(scripts_dir, "PLR scripts")
    if not _same_directory_identity(
        scripts_current_metadata, scripts_original_metadata
    ):
        raise InstallError("rollback PLR scripts directory identity does not match")
    if not (
        _same_directory_metadata(
            scripts_current_metadata, scripts_original_metadata
        )
        or _same_directory_metadata(
            scripts_current_metadata, scripts_desired_metadata
        )
    ):
        raise InstallError(
            "rollback PLR scripts metadata is neither installed nor original"
        )
    scripts_directory_changed = not _same_directory_metadata(
        scripts_current_metadata, scripts_original_metadata
    )
    scripts_directory_action = (
        "restore-metadata" if scripts_directory_changed else "already-restored"
    )
    plr_directory_created = manifest.get("plr_directory_created")
    if not isinstance(plr_directory_created, bool):
        raise InstallError("rollback manifest .plr directory state is invalid")
    plr_directory = os.path.dirname(bound_paths["output"])
    plr_directory_action = "preserve-existing"
    plr_directory_changed = False
    plr_directory_mode = None
    if plr_directory_created:
        if os.path.lexists(plr_directory):
            plr_directory_mode = _inspect_removable_plr_directory(
                plr_directory, account_owner
            )
            plr_directory_action = "remove-created"
            plr_directory_changed = True
        else:
            plr_directory_action = "already-absent"
    files = manifest.get("files")
    if not isinstance(files, list) or (
        not files
        and manifest.get("plr_directory_created") is not True
        and scripts_metadata_normalized is not True
    ):
        raise InstallError("rollback manifest has no files")
    allowed = {
        os.path.abspath(os.path.join(extras_dir, "virtual_sdcard.py")),
        os.path.abspath(os.path.join(extras_dir, "plr_checkpoint.py")),
        os.path.abspath(os.path.join(scripts_dir, "plr_checkpoint.py")),
        os.path.abspath(os.path.join(scripts_dir, "generate_recovery.py")),
        os.path.abspath(os.path.join(scripts_dir, "plr.sh")),
        os.path.abspath(os.path.join(scripts_dir, RUNTIME_MANIFEST_NAME)),
    }
    descriptors = []
    seen = set()
    for entry in files:
        if not isinstance(entry, dict):
            raise InstallError("rollback file entry is not an object")
        target = os.path.abspath(str(entry.get("target", "")))
        if target not in allowed or target in seen:
            raise InstallError("rollback target is unexpected or duplicated: %s" % target)
        seen.add(target)
        backup = entry.get("backup")
        if backup is None:
            if entry.get("created_by_install") is not True:
                raise InstallError("rollback entry without backup is not marked as created")
            data = None
            mode = None
            ownership = None
            changed = os.path.lexists(target)
        else:
            backup = os.path.abspath(str(backup))
            if os.path.dirname(backup) != backup_dir or os.path.islink(backup):
                raise InstallError("rollback backup escapes its manifest directory")
            backup = _require_unlinked_file(backup, "rollback backup")
            _verify_owner(backup, _effective_owner(), "rollback backup")
            if os.name == "posix" and _mode(backup) & 0o022:
                raise InstallError("rollback backup must not be group/world writable")
            data = _read_bytes(backup)
            if _sha256_bytes(data) != entry.get("sha256"):
                raise InstallError("rollback backup hash mismatch: %s" % backup)
            try:
                mode = int(str(entry.get("mode")), 8)
            except (TypeError, ValueError):
                raise InstallError("rollback backup mode is invalid: %s" % backup)
            if mode < 0 or mode > 0o777:
                raise InstallError("rollback backup mode is unsafe: %s" % backup)
            try:
                uid = int(entry.get("uid"))
                gid = int(entry.get("gid"))
            except (TypeError, ValueError):
                raise InstallError("rollback backup ownership is invalid: %s" % backup)
            if uid < 0 or gid < 0 or uid > 0xFFFFFFFF or gid > 0xFFFFFFFF:
                raise InstallError("rollback backup ownership is unsafe: %s" % backup)
            ownership = (uid, gid)
            changed = (
                not os.path.isfile(target)
                or os.path.islink(target)
                or _read_bytes(target) != data
                or (os.name == "posix" and (os.stat(target).st_mode & 0o777) != mode)
                or (
                    os.name == "posix"
                    and (os.stat(target).st_uid, os.stat(target).st_gid) != ownership
                )
            )
        descriptors.append(
            {
                "target": target,
                "backup": backup,
                "data": data,
                "mode": mode,
                "ownership": ownership,
                "changed": changed,
            }
        )
    rollback_changed = (
        scripts_directory_changed
        or plr_directory_changed
        or any(item["changed"] for item in descriptors)
    )
    planned_safety_manifest = (
        _planned_manifest(
            scripts_dir,
            args.transaction_id,
            "plr-rollback-safety-",
            "safety-manifest.json",
        )
        if rollback_changed
        else None
    )
    return {
        "schema": "qidi-plus4-plr-rollback-plan/v1",
        "manifest": manifest_path,
        "backup_manifest": manifest_path,
        "safety_manifest": planned_safety_manifest,
        "backup_dir": backup_dir,
        "account": args.printer_user,
        "paths": bound_paths,
        "scripts_dir": scripts_dir,
        "scripts_directory": {
            "path": scripts_dir,
            "action": scripts_directory_action,
            "original": scripts_original_metadata,
            "installed": scripts_desired_metadata,
            "current": scripts_current_metadata,
        },
        "scripts_directory_action": scripts_directory_action,
        "plr_directory": plr_directory,
        "plr_directory_created": plr_directory_created,
        "plr_directory_action": plr_directory_action,
        "plr_directory_mode": plr_directory_mode,
        "plr_ownership": account_owner,
        "changed": rollback_changed,
        "descriptors": descriptors,
        "actions": [
            {
                "target": item["target"],
                "action": "restore" if item["data"] is not None else "remove-created",
                "changed": item["changed"],
            }
            for item in descriptors
        ] + [{
            "target": plr_directory,
            "action": plr_directory_action,
            "changed": plr_directory_changed,
        }, {
            "target": scripts_dir,
            "action": scripts_directory_action,
            "changed": scripts_directory_changed,
        }],
    }


def apply_rollback_plan(plan):
    changed = [item for item in plan["descriptors"] if item["changed"]]
    remove_plr_directory = plan["plr_directory_action"] == "remove-created"
    restore_scripts_directory = (
        plan["scripts_directory_action"] == "restore-metadata"
    )
    if not changed and not remove_plr_directory and not restore_scripts_directory:
        return None
    current_scripts_metadata = _directory_metadata(
        plan["scripts_dir"], "PLR scripts"
    )
    if not _same_directory_metadata(
        current_scripts_metadata, plan["scripts_directory"]["current"]
    ):
        raise InstallError("PLR scripts directory metadata changed after planning")
    backup_root = _secure_backup_root(plan["scripts_dir"], create=False)
    safety_manifest_path = plan["safety_manifest"]
    safety_dir = os.path.dirname(safety_manifest_path)
    if os.path.lexists(safety_dir):
        raise InstallError("planned safety transaction directory already exists")
    os.mkdir(safety_dir, 0o700)
    if os.name == "posix":
        os.chmod(safety_dir, 0o700)
    _secure_transaction_directory(
        safety_dir, backup_root, "plr-rollback-safety-"
    )
    _fsync_directory(backup_root, "backup root")
    safety_manifest = {
        "schema": "qidi-plus4-plr-safety/v1",
        "account": plan["account"],
        "paths": plan["paths"],
        "backup_manifest": plan["backup_manifest"],
        "files": [],
        "plr_directory": None,
        "scripts_directory": _manifest_directory_metadata(
            current_scripts_metadata
        ),
    }
    current = []
    try:
        if remove_plr_directory:
            current_mode = _inspect_removable_plr_directory(
                plan["plr_directory"], plan["plr_ownership"]
            )
            safety_manifest["plr_directory"] = {
                "path": plan["plr_directory"],
                "present": True,
                "mode": "%04o" % current_mode,
                "uid": int(plan["plr_ownership"][0]),
                "gid": int(plan["plr_ownership"][1]),
            }
        for index, item in enumerate(changed):
            target = item["target"]
            if os.path.lexists(target):
                if not os.path.isfile(target) or os.path.islink(target):
                    raise InstallError("rollback target became unsafe: %s" % target)
                stat_result = os.stat(target)
                data = _read_bytes(target)
                safety = os.path.join(
                    safety_dir, "%02d-%s" % (index, os.path.basename(target))
                )
                _atomic_install(safety, data, 0o600)
                current.append((item, data, stat_result))
                safety_manifest["files"].append(
                    {
                        "target": target,
                        "safety": safety,
                        "sha256": _sha256_bytes(data),
                        "mode": "%04o" % (stat_result.st_mode & 0o777),
                        "uid": int(stat_result.st_uid),
                        "gid": int(stat_result.st_gid),
                    }
                )
            else:
                current.append((item, None, None))
                safety_manifest["files"].append(
                    {"target": target, "safety": None, "missing_before_rollback": True}
                )
        _atomic_install(
            safety_manifest_path,
            (json.dumps(safety_manifest, indent=2, sort_keys=True) + "\n").encode(
                "utf-8"
            ),
            0o600,
        )
    except Exception as exc:
        shutil.rmtree(safety_dir, ignore_errors=True)
        raise InstallError(
            "could not create durable rollback safety backup: %s" % exc
        )
    scripts_restore_started = False
    try:
        for item, _current_data, current_stat in current:
            target = item["target"]
            if item["data"] is None:
                if os.path.lexists(target):
                    if os.path.islink(target) or not os.path.isfile(target):
                        raise InstallError("rollback target became unsafe: %s" % target)
                    os.unlink(target)
                _verify_target_state(target, None, None, None)
            else:
                ownership = item["ownership"]
                _atomic_install(target, item["data"], item["mode"], ownership)
                _verify_target_state(
                    target, item["data"], item["mode"], ownership
                )
        if remove_plr_directory:
            _remove_created_plr_directory(
                plan["plr_directory"], plan["plr_ownership"]
            )
        if restore_scripts_directory:
            try:
                _set_directory_metadata(
                    plan["scripts_dir"],
                    plan["scripts_directory"]["original"],
                    "PLR scripts",
                    expected=plan["scripts_directory"]["current"],
                )
            except DirectoryMetadataMutationError:
                scripts_restore_started = True
                raise
    except Exception as exc:
        errors = []
        if remove_plr_directory:
            try:
                _restore_plr_directory(
                    plan["plr_directory"],
                    plan["plr_directory_mode"],
                    plan["plr_ownership"],
                )
            except Exception as restore_exc:
                errors.append(
                    "%s: %s" % (plan["plr_directory"], restore_exc)
                )
        for item, current_data, current_stat in reversed(current):
            try:
                if current_data is None:
                    if os.path.lexists(item["target"]):
                        os.unlink(item["target"])
                    _verify_target_state(item["target"], None, None, None)
                else:
                    ownership = (current_stat.st_uid, current_stat.st_gid)
                    current_mode = current_stat.st_mode & 0o777
                    _atomic_install(
                        item["target"],
                        current_data,
                        current_mode,
                        ownership,
                    )
                    _verify_target_state(
                        item["target"], current_data, current_mode, ownership
                    )
            except Exception as restore_exc:
                errors.append("%s: %s" % (item["target"], restore_exc))
        if scripts_restore_started:
            try:
                _set_directory_metadata(
                    plan["scripts_dir"],
                    plan["scripts_directory"]["current"],
                    "PLR scripts",
                )
            except Exception as restore_exc:
                errors.append("%s: %s" % (plan["scripts_dir"], restore_exc))
        elif restore_scripts_directory:
            try:
                observed = _directory_metadata(plan["scripts_dir"], "PLR scripts")
                if not _same_directory_metadata(
                    observed, plan["scripts_directory"]["current"]
                ):
                    raise InstallError(
                        "PLR scripts metadata changed outside the rollback"
                    )
            except Exception as restore_exc:
                errors.append("%s: %s" % (plan["scripts_dir"], restore_exc))
        detail = (
            "; safety-restore errors: %s" % "; ".join(errors) if errors else ""
        )
        state = "partial" if errors else "safety_restored"
        applied = None if errors else False
        raise TransactionError(
            "rollback failed; installed state restore attempted: %s%s" % (exc, detail),
            state,
            backup_manifest=plan["backup_manifest"],
            safety_manifest=safety_manifest_path,
            applied=applied,
        )
    return safety_dir


def _public_plan(plan):
    return {key: value for key, value in plan.items() if key != "descriptors"}


def create_parser():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--printer-user", default="mks")
    parser.add_argument("--klipper-dir")
    parser.add_argument("--printer-data")
    parser.add_argument("--scripts-dir")
    parser.add_argument("--python")
    parser.add_argument("--gcode-root")
    parser.add_argument("--checkpoint")
    parser.add_argument("--record")
    parser.add_argument("--output")
    parser.add_argument("--transaction-id")
    parser.add_argument("--rollback-manifest")
    parser.add_argument("--service", default=KLIPPER_SERVICE, choices=(KLIPPER_SERVICE,))
    parser.add_argument("--apply", action="store_true")
    parser.add_argument(
        "--klipper-stopped",
        action="store_true",
        help="explicitly acknowledge that Klipper has been stopped",
    )
    parser.add_argument("--json", action="store_true")
    return parser


def main(argv=None):
    args = create_parser().parse_args(argv)
    account = args.printer_user
    paths = None
    validated_backup_manifest = None
    service_state = None
    try:
        paths = _canonical_layout(account)
        if args.apply and not args.klipper_stopped:
            raise InstallError("--apply requires --klipper-stopped")
        if args.rollback_manifest:
            rollback = build_rollback_plan(args)
            validated_backup_manifest = rollback["backup_manifest"]
            safety_backup = None
            if args.apply:
                service_state = _check_service_stopped(args.service)
                safety_backup = apply_rollback_plan(rollback)
            result = {
                key: value
                for key, value in rollback.items()
                if key != "descriptors"
            }
            result.update(
                {
                    "ok": True,
                    "dry_run": not args.apply,
                    "applied": bool(args.apply and rollback["changed"]),
                    "safety_backup": safety_backup,
                    "backup_manifest": validated_backup_manifest,
                    "safety_manifest": (
                        os.path.join(safety_backup, "safety-manifest.json")
                        if safety_backup
                        else None
                    ),
                    "transaction_state": (
                        "rolled_back"
                        if args.apply and rollback["changed"]
                        else "not_started"
                    ),
                    "service_state": service_state,
                    "restart_performed": False,
                }
            )
        else:
            plan = build_plan(args)
            planned_backup_manifest = plan.get("backup_manifest")
            if plan["changed"]:
                if not isinstance(planned_backup_manifest, str):
                    raise InstallError("changed plan omitted its backup manifest")
            elif planned_backup_manifest is not None:
                raise InstallError("unchanged plan returned a backup manifest")
            backup = None
            if args.apply:
                service_state = _check_service_stopped(args.service)
                backup = apply_plan(plan)
                applied_backup_manifest = (
                    os.path.join(backup, "backup-manifest.json")
                    if backup
                    else None
                )
                if applied_backup_manifest != planned_backup_manifest:
                    raise TransactionError(
                        "applied backup manifest differs from the predeclared plan",
                        "indeterminate",
                        backup_manifest=planned_backup_manifest,
                        applied=None,
                    )
                plan["dry_run"] = False
            result = _public_plan(plan)
            result.update(
                {
                    "ok": True,
                    "applied": bool(args.apply and plan["changed"]),
                    "backup": backup,
                    # The plan is the single source of truth for this opaque
                    # rollback handle.  Preserve it during dry-run and require
                    # apply to produce that exact same path.
                    "backup_manifest": planned_backup_manifest,
                    "safety_manifest": None,
                    "transaction_state": (
                        "applied"
                        if args.apply and plan["changed"]
                        else "not_started"
                    ),
                    "service_state": service_state,
                    "restart_performed": False,
                }
            )
    except TransactionError as exc:
        result = {
            "ok": False,
            "error": str(exc),
            "account": account,
            "paths": paths,
            "applied": exc.applied,
            "transaction_state": exc.transaction_state,
            "backup_manifest": exc.backup_manifest,
            "safety_manifest": exc.safety_manifest,
            "service_state": service_state,
            "restart_performed": False,
        }
        if args.json:
            print(json.dumps(result, sort_keys=True))
        else:
            print(json.dumps(result, indent=2, sort_keys=True), file=sys.stderr)
        return 1
    except InstallError as exc:
        result = {
            "ok": False,
            "error": str(exc),
            "account": account if paths is not None else None,
            "paths": paths,
            "applied": False,
            "transaction_state": "not_started",
            "backup_manifest": validated_backup_manifest,
            "safety_manifest": None,
            "service_state": service_state,
            "restart_performed": False,
        }
        if args.json:
            print(json.dumps(result, sort_keys=True))
        else:
            print("PLR installation refused: %s" % exc, file=sys.stderr)
        return 1
    if args.json:
        print(json.dumps(result, sort_keys=True))
    else:
        print(json.dumps(result, indent=2, sort_keys=True))
        if not args.apply and result["changed"]:
            print("Dry run only; rerun with --apply --klipper-stopped after review.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
