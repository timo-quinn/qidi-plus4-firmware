#!/usr/bin/env python3
"""Install the reviewed QIDI Box output clock guard on a stock QIDI host.

This helper is streamed to the printer by ``qidi_plus4.py``.  Its command-line
surface intentionally has no target, owner, mode, or service arguments: those
properties are fixed here so the orchestration command cannot become a generic
remote-code installer.
"""

import argparse
import grp
import hashlib
import json
import os
import pathlib
import pwd
import re
import shutil
import stat
import sys
import tempfile


SCHEMA = "qidi-plus4-box-output-clock-guard-install/v1"
OWNER = "mks"
TARGET = pathlib.Path(
    "/home/mks/klipper/klippy/extras/box_output_clock_guard.py"
)
MODE = 0o644
CONFIG_SECTION = "[box_output_clock_guard]"
STAGED_SOURCE = re.compile(
    r"/tmp/qidi-box-clock-guard\.[A-Za-z0-9]+/box_output_clock_guard\.py"
)
TRANSACTION_ID = re.compile(r"\d{8}T\d{6}Z-[0-9a-f]{16}")
SHA256 = re.compile(r"[0-9a-f]{64}")


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def _regular_file(path, label):
    try:
        details = path.lstat()
    except OSError as exc:
        raise RuntimeError("%s is not readable: %s" % (label, exc))
    if stat.S_ISLNK(details.st_mode) or not stat.S_ISREG(details.st_mode):
        raise RuntimeError("%s must be a regular file, not a symlink" % label)
    return details


def _canonical_directory(path, label):
    try:
        details = path.lstat()
    except OSError as exc:
        raise RuntimeError("%s is not accessible: %s" % (label, exc))
    if stat.S_ISLNK(details.st_mode) or not stat.S_ISDIR(details.st_mode):
        raise RuntimeError("%s must be a real directory, not a symlink" % label)
    if pathlib.Path(os.path.realpath(str(path))) != path:
        raise RuntimeError("%s does not resolve to its fixed path" % label)
    return details


def _ensure_backup_root(parent, owner):
    root = parent / ".qidi-plus4-backups"
    if os.path.lexists(str(root)):
        _canonical_directory(root, "backup directory")
    else:
        root.mkdir(mode=0o700)
    os.chown(str(root), owner.pw_uid, owner.pw_gid)
    os.chmod(str(root), 0o700)
    return root


def _copy_to_path(source, destination, mode, uid, gid, expected_digest):
    """Publish a fully written copy with one same-filesystem rename."""

    descriptor, temporary_name = tempfile.mkstemp(
        prefix=".%s." % destination.name,
        suffix=".tmp",
        dir=str(destination.parent),
    )
    temporary = pathlib.Path(temporary_name)
    try:
        with os.fdopen(descriptor, "wb") as output, source.open("rb") as input_stream:
            shutil.copyfileobj(input_stream, output, length=1024 * 1024)
            output.flush()
            os.fsync(output.fileno())
        copied_digest = sha256(temporary)
        if copied_digest != expected_digest:
            raise RuntimeError(
                "atomic copy SHA-256 mismatch: expected %s, got %s"
                % (expected_digest, copied_digest)
            )
        os.chmod(str(temporary), mode)
        os.chown(str(temporary), uid, gid)
        os.replace(str(temporary), str(destination))
        directory_fd = os.open(str(destination.parent), os.O_RDONLY)
        try:
            os.fsync(directory_fd)
        finally:
            os.close(directory_fd)
    finally:
        try:
            temporary.unlink()
        except FileNotFoundError:
            pass


def _file_status(path):
    details = _regular_file(path, "installed clock guard")
    return {
        "path": str(path),
        "sha256": sha256(path),
        "owner": pwd.getpwuid(details.st_uid).pw_name,
        "group": grp.getgrgid(details.st_gid).gr_name,
        "mode": "%04o" % stat.S_IMODE(details.st_mode),
    }


def install(source, expected_digest, transaction_id, target=TARGET, owner_name=OWNER):
    """Install one verified module and return its machine-readable proof.

    ``target`` and ``owner_name`` are injectable only for unit tests.  The
    command-line entry point always calls this with the fixed module constants.
    """

    if not SHA256.fullmatch(expected_digest):
        raise RuntimeError("expected SHA-256 must be 64 lowercase hexadecimal characters")
    if not TRANSACTION_ID.fullmatch(transaction_id):
        raise RuntimeError("invalid clock-guard transaction identifier")
    source = pathlib.Path(source)
    target = pathlib.Path(target)
    _regular_file(source, "staged clock guard")
    source_digest = sha256(source)
    if source_digest != expected_digest:
        raise RuntimeError(
            "staged clock guard SHA-256 mismatch: expected %s, got %s"
            % (expected_digest, source_digest)
        )

    owner = pwd.getpwnam(owner_name)
    parent = target.parent
    _canonical_directory(parent, "fixed Klipper extras directory")
    if pathlib.Path(os.path.realpath(str(target))) != target:
        raise RuntimeError("clock-guard destination does not resolve to its fixed path")

    existing = None
    existing_digest = None
    if os.path.lexists(str(target)):
        existing = _regular_file(target, "existing clock guard")
        existing_digest = sha256(target)

    expected_mode = "%04o" % MODE
    already_correct = bool(
        existing
        and existing_digest == source_digest
        and existing.st_uid == owner.pw_uid
        and existing.st_gid == owner.pw_gid
        and stat.S_IMODE(existing.st_mode) == MODE
    )
    backup = None
    if not already_correct and existing is not None:
        backup_root = _ensure_backup_root(parent, owner)
        backup_dir = backup_root / ("box-output-clock-guard-%s" % transaction_id)
        backup_dir.mkdir(mode=0o700)
        os.chown(str(backup_dir), owner.pw_uid, owner.pw_gid)
        backup_path = backup_dir / target.name
        _copy_to_path(
            target,
            backup_path,
            stat.S_IMODE(existing.st_mode),
            existing.st_uid,
            existing.st_gid,
            existing_digest,
        )
        backup = _file_status(backup_path)
        # Refuse to replace a file that changed after it was inspected and
        # backed up.  The backup remains as recovery evidence.
        current = _regular_file(target, "existing clock guard")
        if (
            sha256(target) != existing_digest
            or current.st_ino != existing.st_ino
            or current.st_dev != existing.st_dev
        ):
            raise RuntimeError("existing clock guard changed during installation")

    if not already_correct:
        _copy_to_path(
            source,
            target,
            MODE,
            owner.pw_uid,
            owner.pw_gid,
            source_digest,
        )

    installed = _file_status(target)
    if installed["sha256"] != source_digest:
        raise RuntimeError("post-install clock-guard SHA-256 verification failed")
    if installed["owner"] != owner_name or installed["mode"] != expected_mode:
        raise RuntimeError("post-install clock-guard ownership or mode verification failed")

    return {
        "schema": SCHEMA,
        "ok": True,
        "changed": not already_correct,
        "applied": not already_correct,
        "verified": True,
        "account": owner_name,
        "transaction_id": transaction_id,
        "source_sha256": source_digest,
        "target": installed,
        "backup": backup,
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "config_changed": False,
        "activation_required": True,
        "required_config_section": CONFIG_SECTION,
    }


def create_parser():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", required=True)
    parser.add_argument("--expected-sha256", required=True)
    parser.add_argument("--transaction-id", required=True)
    return parser


def main():
    args = create_parser().parse_args()
    base = {
        "schema": SCHEMA,
        "ok": False,
        "account": OWNER,
        "transaction_id": args.transaction_id,
        "source_sha256": args.expected_sha256,
        "target": {"path": str(TARGET)},
        "backup": None,
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "config_changed": False,
        "activation_required": True,
        "required_config_section": CONFIG_SECTION,
    }
    try:
        if not STAGED_SOURCE.fullmatch(args.source):
            raise RuntimeError("source must be the guarded temporary clock-module path")
        result = install(args.source, args.expected_sha256, args.transaction_id)
    except Exception as exc:
        if TRANSACTION_ID.fullmatch(args.transaction_id):
            backup_path = (
                TARGET.parent
                / ".qidi-plus4-backups"
                / ("box-output-clock-guard-%s" % args.transaction_id)
                / TARGET.name
            )
            if os.path.lexists(str(backup_path)):
                try:
                    base["backup"] = _file_status(backup_path)
                except Exception:
                    # The primary failure remains authoritative. A malformed
                    # backup path must not hide it behind a second exception.
                    pass
        base["verified"] = False
        base["error"] = str(exc)
        print(json.dumps(base, indent=2, sort_keys=True))
        return 1
    print(json.dumps(result, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    sys.exit(main())
