#!/usr/bin/env python3
"""Upgrade only the fixed Klippee CLI and managed user agent.

qidi_plus4.py streams this reviewed helper to the stock QIDI printer account.
It accepts no arguments or caller-selected paths, URLs, services, or commands.
"""

from __future__ import annotations

import hashlib
import json
import os
import pwd
import re
import stat
import subprocess
import sys
import tempfile
import time

SCHEMA = "qidi-plus4-klippee-agent-upgrade/v1"
ACCOUNT = "mks"
CLI_PATH = "/home/mks/.local/bin/klippee"
CLI_PARENT = "/home/mks/.local/bin"
SOURCE_URL = "https://klippee.xyz/install/klippee.py"
CLI_MARKER = "Klippee's dependency-light config sync client."
CLI_VERSION = re.compile(
    r'^CLI_VERSION\s*=\s*["\']([0-9]{4}\.[0-9]{2}\.[0-9]{2}(?:\.[0-9]+)?)["\']\s*$',
    re.MULTILINE,
)
MAX_CLI_BYTES = 2_000_000
MAX_DIAGNOSTIC_BYTES = 4_000
SERVICE = "klippee-moonraker.service"
UNIT_PARENT = "/home/mks/.config/systemd/user"
UNIT_PATH = "/home/mks/.config/systemd/user/klippee-moonraker.service"
UNIT_EXEC = re.compile(
    r'^ExecStart="(/usr/bin/python3(?:\.[0-9]+)?)" '
    r'"/home/mks/\.local/bin/klippee" moonraker-agent$'
)
PYTHON_EXEC = re.compile(r"^/usr/bin/python3(?:\.[0-9]+)?$")
PROC_ROOT = "/proc"
SYSTEMCTL = "/bin/systemctl"
CURL = "/usr/bin/curl"
SAFE_PATH = "/usr/bin:/bin"


class UpgradeError(Exception):
    pass


def safe_error(error: BaseException) -> str:
    text = " ".join(str(error).replace("\x00", " ").split())
    return (text or error.__class__.__name__)[:500]


def version_key(value: str) -> tuple:
    return tuple(int(part) for part in value.split("."))


def secure_owned_directory(path: str, label: str) -> None:
    account = pwd.getpwnam(ACCOUNT)
    if os.path.realpath(path) != path:
        raise UpgradeError(f"{label} resolved outside its reviewed path")
    if not hasattr(os, "O_NOFOLLOW") or not hasattr(os, "O_DIRECTORY"):
        raise UpgradeError(f"host Python cannot enforce a non-symlink {label} open")
    flags = os.O_RDONLY | os.O_NOFOLLOW | os.O_DIRECTORY
    if hasattr(os, "O_CLOEXEC"):
        flags |= os.O_CLOEXEC
    descriptor = os.open(path, flags)
    try:
        metadata = os.fstat(descriptor)
        named_metadata = os.lstat(path)
        if (
            stat.S_ISLNK(named_metadata.st_mode)
            or not stat.S_ISDIR(metadata.st_mode)
            or metadata.st_dev != named_metadata.st_dev
            or metadata.st_ino != named_metadata.st_ino
            or metadata.st_uid != account.pw_uid
        ):
            raise UpgradeError(f"{label} has an unexpected owner or type")
        if stat.S_IMODE(metadata.st_mode) & 0o022:
            os.fchmod(descriptor, 0o755)
            metadata = os.fstat(descriptor)
        if stat.S_IMODE(metadata.st_mode) & 0o022:
            raise UpgradeError(f"{label} permissions could not be secured")
    finally:
        os.close(descriptor)


def checked_parent() -> None:
    secure_owned_directory(CLI_PARENT, "fixed Klippee CLI directory")


def read_unit() -> None:
    account = pwd.getpwnam(ACCOUNT)
    secure_owned_directory(UNIT_PARENT, "managed Klippee unit directory")
    if os.path.realpath(UNIT_PATH) != UNIT_PATH:
        raise UpgradeError("managed Klippee unit resolved outside its reviewed path")
    flags = os.O_RDONLY | os.O_NOFOLLOW
    if hasattr(os, "O_CLOEXEC"):
        flags |= os.O_CLOEXEC
    descriptor = os.open(UNIT_PATH, flags)
    try:
        metadata = os.fstat(descriptor)
        named_metadata = os.lstat(UNIT_PATH)
        if (
            stat.S_ISLNK(named_metadata.st_mode)
            or not stat.S_ISREG(metadata.st_mode)
            or metadata.st_dev != named_metadata.st_dev
            or metadata.st_ino != named_metadata.st_ino
            or metadata.st_uid != account.pw_uid
            or not 0 < metadata.st_size <= 4096
        ):
            raise UpgradeError("managed Klippee unit has unsafe metadata")
        with os.fdopen(descriptor, "rb", closefd=False) as stream:
            raw = stream.read(4097)
        try:
            lines = raw.decode("utf-8").splitlines()
        except UnicodeDecodeError as error:
            raise UpgradeError("managed Klippee unit is not UTF-8") from error
        nonempty = [line for line in lines if line]
        if len(nonempty) != 12:
            raise UpgradeError("managed Klippee unit has an unexpected directive count")
        expected = (
            "[Unit]",
            "Description=Klippee Moonraker integration agent",
            "After=network-online.target",
            "[Service]",
            "Type=simple",
            None,
            'Environment="KLIPPEE_MOONRAKER_SOCKET=/home/mks/printer_data/comms/moonraker.sock"',
            'Environment="KLIPPEE_STATE_DIR=/home/mks/.klippee"',
            "Restart=on-failure",
            "RestartSec=5",
            "[Install]",
            "WantedBy=default.target",
        )
        for observed, required in zip(nonempty, expected):
            if required is None:
                if UNIT_EXEC.fullmatch(observed) is None:
                    raise UpgradeError("managed Klippee unit has an unexpected ExecStart")
            elif observed != required:
                raise UpgradeError("managed Klippee unit has an unexpected directive")
        if stat.S_IMODE(metadata.st_mode) & 0o022:
            os.fchmod(descriptor, 0o600)
            metadata = os.fstat(descriptor)
        if stat.S_IMODE(metadata.st_mode) & 0o022:
            raise UpgradeError("managed Klippee unit permissions could not be secured")
    finally:
        os.close(descriptor)


def read_cli() -> dict:
    checked_parent()
    account = pwd.getpwnam(ACCOUNT)
    if os.path.realpath(CLI_PATH) != CLI_PATH:
        raise UpgradeError("fixed Klippee CLI resolved outside its reviewed path")
    if not hasattr(os, "O_NOFOLLOW"):
        raise UpgradeError("host Python cannot enforce a non-symlink CLI open")
    flags = os.O_RDONLY | os.O_NOFOLLOW
    if hasattr(os, "O_CLOEXEC"):
        flags |= os.O_CLOEXEC
    descriptor = os.open(CLI_PATH, flags)
    try:
        metadata = os.fstat(descriptor)
        named_metadata = os.lstat(CLI_PATH)
        if (
            stat.S_ISLNK(named_metadata.st_mode)
            or not stat.S_ISREG(metadata.st_mode)
            or metadata.st_dev != named_metadata.st_dev
            or metadata.st_ino != named_metadata.st_ino
        ):
            raise UpgradeError("fixed Klippee CLI changed during inspection")
        if metadata.st_uid != account.pw_uid:
            raise UpgradeError("fixed Klippee CLI is not owned by mks")
        mode = stat.S_IMODE(metadata.st_mode)
        if mode != 0o700:
            raise UpgradeError("fixed Klippee CLI mode is not 0700")
        if not 0 < metadata.st_size <= MAX_CLI_BYTES:
            raise UpgradeError("fixed Klippee CLI has an invalid size")
        with os.fdopen(descriptor, "rb", closefd=False) as stream:
            source = stream.read(MAX_CLI_BYTES + 1)
    finally:
        os.close(descriptor)
    return validate_source(source, CLI_PATH, mode)


def validate_source(source: bytes, label: str, mode: int = 0o700) -> dict:
    if not source or len(source) > MAX_CLI_BYTES:
        raise UpgradeError(f"{label} has an invalid size")
    try:
        text = source.decode("utf-8")
    except UnicodeDecodeError as error:
        raise UpgradeError(f"{label} is not UTF-8") from error
    if CLI_MARKER not in text:
        raise UpgradeError(f"{label} is not the Klippee CLI")
    match = CLI_VERSION.search(text)
    if match is None:
        raise UpgradeError(f"{label} has no valid version")
    try:
        compile(text, label, "exec")
    except SyntaxError as error:
        raise UpgradeError(f"{label} is incompatible with printer Python") from error
    return {
        "version": match.group(1),
        "sha256": hashlib.sha256(source).hexdigest(),
        "mode": mode,
        "source": source,
    }


def safe_environment() -> dict:
    uid = pwd.getpwnam(ACCOUNT).pw_uid
    return {
        "PATH": SAFE_PATH,
        "HOME": "/home/mks",
        "USER": ACCOUNT,
        "LOGNAME": ACCOUNT,
        "LANG": "C",
        "LC_ALL": "C",
        "XDG_RUNTIME_DIR": f"/run/user/{uid}",
        "DBUS_SESSION_BUS_ADDRESS": f"unix:path=/run/user/{uid}/bus",
    }


def download_cli() -> dict:
    command = [
        CURL,
        "--disable",
        "--fail",
        "--silent",
        "--show-error",
        "--proto",
        "=https",
        "--proto-redir",
        "=https",
        "--max-redirs",
        "0",
        "--connect-timeout",
        "10",
        "--max-time",
        "60",
        "--max-filesize",
        str(MAX_CLI_BYTES),
        SOURCE_URL,
    ]
    completed = subprocess.run(
        command,
        capture_output=True,
        env=safe_environment(),
        timeout=70,
        check=False,
    )
    if completed.returncode != 0:
        raise UpgradeError(f"official Klippee download exited {completed.returncode}")
    return validate_source(completed.stdout, SOURCE_URL)


def atomic_replace(source: bytes, mode: int) -> None:
    checked_parent()
    descriptor, temporary = tempfile.mkstemp(
        prefix=".klippee.upgrade-", dir=CLI_PARENT
    )
    try:
        with os.fdopen(descriptor, "wb") as stream:
            stream.write(source)
            stream.flush()
            os.fsync(stream.fileno())
            os.fchmod(stream.fileno(), mode)
        os.replace(temporary, CLI_PATH)
        temporary = ""
        directory = os.open(CLI_PARENT, os.O_RDONLY)
        try:
            os.fsync(directory)
        finally:
            os.close(directory)
    finally:
        if temporary:
            try:
                os.unlink(temporary)
            except FileNotFoundError:
                pass


def run_systemctl(*arguments: str) -> subprocess.CompletedProcess:
    return subprocess.run(
        [SYSTEMCTL, "--user", *arguments],
        capture_output=True,
        text=True,
        env=safe_environment(),
        timeout=15,
        check=False,
    )


def systemctl_property(name: str) -> str:
    result = run_systemctl("show", "--property", name, "--value", SERVICE)
    if result.returncode != 0:
        raise UpgradeError(f"could not read managed Klippee unit property {name}")
    return result.stdout.strip()


def validate_unit() -> None:
    read_unit()
    if systemctl_property("FragmentPath") != UNIT_PATH:
        raise UpgradeError("systemd loaded Klippee agent from an unexpected unit path")
    if systemctl_property("DropInPaths"):
        raise UpgradeError("managed Klippee unit has unreviewed systemd drop-ins")
    if systemctl_property("NeedDaemonReload") != "no":
        raise UpgradeError("managed Klippee unit has unapplied on-disk changes")


def validate_agent_process(pid: int) -> None:
    if not 0 < pid <= 2_147_483_647:
        raise UpgradeError("managed Klippee agent returned an invalid PID")
    proc = f"{PROC_ROOT}/{pid}"
    with open(proc + "/cmdline", "rb") as stream:
        raw = stream.read(4097)
    if not raw or len(raw) > 4096:
        raise UpgradeError("managed Klippee agent command line is invalid")
    try:
        command = [part.decode("utf-8") for part in raw.rstrip(b"\x00").split(b"\x00")]
    except UnicodeDecodeError as error:
        raise UpgradeError("managed Klippee agent command line is not UTF-8") from error
    if (
        len(command) != 3
        or PYTHON_EXEC.fullmatch(command[0]) is None
        or command[1:] != [CLI_PATH, "moonraker-agent"]
    ):
        raise UpgradeError("active service process is not the fixed Klippee agent")
    executable = os.path.realpath(proc + "/exe")
    if PYTHON_EXEC.fullmatch(executable) is None:
        raise UpgradeError("managed Klippee agent uses an unexpected interpreter")
    account = pwd.getpwnam(ACCOUNT)
    with open(proc + "/status", "r", encoding="utf-8") as stream:
        uid_line = next((line for line in stream if line.startswith("Uid:")), "")
    try:
        uids = [int(value) for value in uid_line.split()[1:]]
    except ValueError as error:
        raise UpgradeError("managed Klippee agent returned invalid UID evidence") from error
    if len(uids) != 4 or any(value != account.pw_uid for value in uids):
        raise UpgradeError("managed Klippee agent is not running entirely as mks")


def service_evidence() -> dict:
    state = run_systemctl("is-active", SERVICE)
    observed = state.stdout.strip().lower() or "unknown"
    pid = 0
    if state.returncode == 0 and observed == "active":
        pid_result = run_systemctl("show", "--property", "MainPID", "--value", SERVICE)
        if pid_result.returncode == 0:
            try:
                pid = int(pid_result.stdout.strip())
            except ValueError:
                pid = 0
        validate_agent_process(pid)
    return {"observed_state": observed, "state_exit": state.returncode, "pid": pid}


def wait_for_service(previous_pid: int) -> dict:
    deadline = time.monotonic() + 10.0
    evidence = service_evidence()
    while (
        time.monotonic() < deadline
        and not (
            evidence["observed_state"] == "active"
            and evidence["state_exit"] == 0
            and evidence["pid"] > 0
            and evidence["pid"] != previous_pid
        )
    ):
        time.sleep(0.2)
        evidence = service_evidence()
    return evidence


def emit_result(
    before: dict,
    after: dict,
    before_service: dict,
    after_service: dict,
    *,
    ok: bool,
    error: str = "",
) -> int:
    changed = (
        before["version"] != after["version"]
        or before["sha256"] != after["sha256"]
    )
    restarted = before_service["pid"] != after_service["pid"]
    result = {
        "schema": SCHEMA,
        "ok": ok,
        "changed": changed,
        "account": ACCOUNT,
        "cli_path": CLI_PATH,
        "source_url": SOURCE_URL,
        "before": {
            "version": before["version"],
            "sha256": before["sha256"],
        },
        "after": {
            "version": after["version"],
            "sha256": after["sha256"],
        },
        "service": SERVICE,
        "scope": "user",
        "observed_state": after_service["observed_state"],
        "before_pid": before_service["pid"],
        "after_pid": after_service["pid"],
        "upgrade_exit": 0 if ok else 1,
        "state_exit": after_service["state_exit"],
        "upgrade_reported_success": ok,
        "agent_restart_performed": restarted,
        "klipper_actions_performed": False,
        "config_deployment_performed": False,
    }
    if not ok:
        result["error"] = error or "Klippee agent upgrade failed"
    encoded = json.dumps(result, sort_keys=True)
    if len(encoded.encode("utf-8")) > MAX_DIAGNOSTIC_BYTES:
        raise UpgradeError("upgrade result exceeded its diagnostic bound")
    print(encoded)
    return 0 if ok else 1


def main() -> int:
    before = read_cli()
    validate_unit()
    before_service = service_evidence()
    if (
        before_service["observed_state"] != "active"
        or before_service["state_exit"] != 0
        or before_service["pid"] <= 0
    ):
        raise UpgradeError("managed Klippee agent must be active before upgrade")

    rollback_needed = False
    restart_attempted = False
    try:
        downloaded = download_cli()
        if downloaded["source"] != before["source"]:
            if version_key(downloaded["version"]) <= version_key(before["version"]):
                raise UpgradeError("official Klippee artifact is not a newer version")
            rollback_needed = True
            atomic_replace(downloaded["source"], before["mode"])
        after = read_cli()
        expected = downloaded if rollback_needed else before
        if (
            after["version"] != expected["version"]
            or after["sha256"] != expected["sha256"]
        ):
            raise UpgradeError("installed Klippee CLI did not match the validated artifact")
        restart_attempted = True
        restart = run_systemctl("restart", SERVICE)
        if restart.returncode != 0:
            raise UpgradeError("managed Klippee agent restart failed")
        after_service = wait_for_service(before_service["pid"])
        if (
            after_service["observed_state"] != "active"
            or after_service["state_exit"] != 0
            or after_service["pid"] <= 0
            or after_service["pid"] == before_service["pid"]
        ):
            raise UpgradeError("managed Klippee agent restart was not proven")
        return emit_result(
            before, after, before_service, after_service, ok=True
        )
    except (OSError, UpgradeError, subprocess.SubprocessError) as error:
        failure = safe_error(error)
        if rollback_needed:
            try:
                atomic_replace(before["source"], before["mode"])
            except (OSError, UpgradeError) as rollback_error:
                failure += "; CLI rollback failed: " + safe_error(rollback_error)
        if rollback_needed or restart_attempted:
            recovery = run_systemctl("restart", SERVICE)
            if recovery.returncode != 0:
                failure += "; managed agent recovery restart failed"
                after_service = service_evidence()
            else:
                after_service = wait_for_service(before_service["pid"])
        else:
            after_service = service_evidence()
        try:
            after = read_cli()
        except (OSError, UpgradeError) as inspection_error:
            raise UpgradeError(
                failure + "; final CLI inspection failed: " + safe_error(inspection_error)
            ) from inspection_error
        return emit_result(
            before,
            after,
            before_service,
            after_service,
            ok=False,
            error=failure,
        )


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (OSError, UpgradeError, subprocess.SubprocessError) as error:
        print("klippee-agent-upgrade: " + safe_error(error), file=sys.stderr)
        sys.exit(1)
