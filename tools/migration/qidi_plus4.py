#!/usr/bin/env python3
"""Cross-platform QIDI Plus4 mainline migration utility."""

from __future__ import annotations

import argparse
import atexit
import hashlib
import json
import os
import pathlib
import platform
import re
import secrets
import shlex
import shutil
import struct
import subprocess
import sys
import tarfile
import tempfile
import time
import urllib.request
from datetime import datetime, timezone

SCRIPT_DIR = pathlib.Path(__file__).resolve().parent

# probes.py is a sibling module. Running this file as a script puts its own
# directory on sys.path, but loading it by path — as the tests and any external
# orchestrator may — does not, so make the import work either way.
if str(SCRIPT_DIR) not in sys.path:
    sys.path.insert(0, str(SCRIPT_DIR))

import probes  # noqa: E402  - depends on the sys.path entry above


REPO_ROOT = SCRIPT_DIR.parent.parent
REMOTE_HELPER = SCRIPT_DIR / "qidi-plus4-remote.sh"
BOOTSTRAP_HELPER = SCRIPT_DIR / "bootstrap-mainline.sh"
HOST_TUNING_HELPER = SCRIPT_DIR / "qidi-host-tuning.sh"
PLR_HARDENING_DIR = REPO_ROOT / "plr-hardening"
PLR_DEPLOYMENT_ASSETS = (
    "install.py",
    "patch_virtual_sdcard.py",
    "plr_checkpoint.py",
    "generate_recovery.py",
    "plr.sh.in",
    "manifest.json",
)
KLIPPEE_AGENT_SERVICE = "klippee-moonraker.service"
KLIPPEE_AGENT_ACCOUNT = "mks"
KLIPPEE_AGENT_CLI_PATH = "/home/mks/.local/bin/klippee"
KLIPPEE_AGENT_UPGRADE_SOURCE = "https://klippee.xyz/install/klippee.py"
KLIPPEE_AGENT_UPGRADE_ACTION = "UPGRADE-KLIPPEE-AGENT"
KLIPPEE_AGENT_UPGRADE_SCHEMA = "qidi-plus4-klippee-agent-upgrade/v1"
KLIPPEE_AGENT_UPGRADE_HELPER = SCRIPT_DIR / "upgrade-klippee-agent.py"
KLIPPEE_AGENT_VERSION = re.compile(
    r"^[0-9]{4}\.[0-9]{2}\.[0-9]{2}(?:\.[0-9]+)?$"
)
KLIPPEE_AGENT_SHA256 = re.compile(r"^[0-9a-f]{64}$")
KLIPPEE_AGENT_MAX_RESULT_BYTES = 64 * 1024
KLIPPER_SERVICE = "klipper.service"
KLIPPER_START_STABILITY_CHECKS = 5
KLIPPER_START_STABILITY_INTERVAL_SECONDS = 1.0
BACKUP_HELPER = SCRIPT_DIR / "backup-remote.sh"
LAYOUTS_FILE = SCRIPT_DIR / "mcu-layouts.json"
SMOKE_TEST_CONFIG = SCRIPT_DIR / "smoke-test-printer.cfg"
DEFAULT_ARTIFACTS = REPO_ROOT / "artifacts"
MAINLINE_CONFIGS = REPO_ROOT / "mainline-configs"
DEFAULT_CONFIG_PROFILE = "plus4-x7-v1.0-beacon"
BEACON_SERIAL_TOKEN = "CHANGE_ME_BEACON_SERIAL"
RENDER_METADATA_FILE = "RENDER-METADATA.json"
RENDER_METADATA_SCHEMA = "qidi-plus4-config-render/v1"
RENDER_METADATA_MANAGER = "qidi-plus4-firmware/render-config"


def load_layouts() -> dict[str, tuple[int, int, int, int]]:
    raw = json.loads(LAYOUTS_FILE.read_text(encoding="utf-8"))
    return {kind: tuple(int(value, 16) for value in bounds) for kind, bounds in raw.items()}


# Canonical source is mcu-layouts.json, shared with qidi-plus4-remote.sh.
LAYOUTS = load_layouts()

# Reuse one authenticated SSH connection across the many ssh/scp calls a single
# phase makes, so the printer password (or key passphrase) is entered at most
# once. OpenSSH connection multiplexing is unavailable on Windows; there, set up
# key authentication with `setup-ssh` for a password-free run.
_MUX_DIR: str | None = None
ENVIRONMENT_NAME = re.compile(r"^[A-Za-z_][A-Za-z0-9_]{0,127}$")
UNIX_ACCOUNT_NAME = re.compile(r"^[a-z_][a-z0-9_-]{0,31}$")
HOST_LABEL = re.compile(r"^[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?$")
RESERVED_PASSWORD_ENVIRONMENTS = {
    "DISPLAY",
    "SSH_ASKPASS",
    "SSH_ASKPASS_REQUIRE",
    "PLAB_INTERNAL_SSH_ASKPASS_TOKEN",
    "PLAB_INTERNAL_SSH_ASKPASS_GATE",
    "PLAB_INTERNAL_SSH_PASSWORD_ENV",
}


def mux_options() -> list[str]:
    if platform.system() == "Windows":
        return []
    global _MUX_DIR
    if _MUX_DIR is None:
        _MUX_DIR = tempfile.mkdtemp(prefix="qidi-ssh-mux-")
        atexit.register(shutil.rmtree, _MUX_DIR, ignore_errors=True)
    return ["-o", "ControlMaster=auto",
            "-o", f"ControlPath={os.path.join(_MUX_DIR, '%C')}",
            "-o", "ControlPersist=120"]


def password_environment_name(value: str) -> str:
    if not ENVIRONMENT_NAME.fullmatch(value):
        raise argparse.ArgumentTypeError(
            f"environment name must match {ENVIRONMENT_NAME.pattern}"
        )
    if value.upper() in RESERVED_PASSWORD_ENVIRONMENTS:
        raise argparse.ArgumentTypeError(f"environment name {value!r} is reserved")
    return value


def connection_user(value: str) -> str:
    if not UNIX_ACCOUNT_NAME.fullmatch(value):
        raise argparse.ArgumentTypeError(
            "account name must be a simple Linux user matching "
            f"{UNIX_ACCOUNT_NAME.pattern}"
        )
    return value


def connection_host(value: str) -> str:
    if not value or len(value) > 253 or value != value.strip():
        raise argparse.ArgumentTypeError("printer host must be 1-253 characters")
    labels = value[:-1].split(".") if value.endswith(".") else value.split(".")
    if not labels or any(not HOST_LABEL.fullmatch(label) for label in labels):
        raise argparse.ArgumentTypeError(
            "printer host must be an IPv4 address or DNS hostname without options, paths, or ports"
        )
    return value


def connection_port(value: str | int) -> int:
    try:
        port = int(value)
    except (TypeError, ValueError) as exc:
        raise argparse.ArgumentTypeError("SSH port must be an integer") from exc
    if not 1 <= port <= 65535:
        raise argparse.ArgumentTypeError("SSH port must be between 1 and 65535")
    return port


def validate_connection(args: argparse.Namespace) -> tuple[str, str, int]:
    try:
        host = connection_host(args.printer)
        user = connection_user(args.user)
        port = connection_port(args.port)
        printer_user = getattr(args, "printer_user", None)
        if printer_user:
            connection_user(printer_user)
    except argparse.ArgumentTypeError as exc:
        raise SystemExit(f"Invalid SSH connection: {exc}") from exc
    return host, user, port


def password_auth_options(args: argparse.Namespace) -> list[str]:
    name = getattr(args, "password_env", None)
    if not name:
        return []
    try:
        password_environment_name(name)
    except argparse.ArgumentTypeError as exc:
        raise SystemExit(f"Invalid --password-env: {exc}") from exc
    if not os.environ.get(name):
        raise SystemExit(f"SSH password environment variable {name} is empty or unset")
    askpass = os.environ.get("SSH_ASKPASS", "")
    if not askpass:
        raise SystemExit("--password-env requires SSH_ASKPASS to be configured")
    askpass_path = pathlib.Path(askpass).expanduser()
    if not askpass_path.is_absolute() or not askpass_path.is_file():
        raise SystemExit("SSH_ASKPASS must name an absolute executable file")
    if platform.system() != "Windows" and not os.access(askpass_path, os.X_OK):
        raise SystemExit("SSH_ASKPASS must be executable")
    if os.environ.get("SSH_ASKPASS_REQUIRE") != "force":
        raise SystemExit("--password-env requires SSH_ASKPASS_REQUIRE=force")
    return [
        "-o", "BatchMode=no",
        "-o", "PubkeyAuthentication=no",
        "-o", "PreferredAuthentications=password,keyboard-interactive",
        "-o", "NumberOfPasswordPrompts=1",
    ]


def identity_options(args: argparse.Namespace) -> list[str]:
    if getattr(args, "password_env", None):
        return []
    identity = getattr(args, "identity", None)
    if not identity:
        return []
    if any(character in str(identity) for character in ("\x00", "\n", "\r")):
        raise SystemExit("SSH identity path contains an unsafe control character")
    path = pathlib.Path(identity).expanduser().resolve()
    if not path.is_file():
        raise SystemExit(f"SSH identity not found: {path}")
    return ["-i", str(path), "-o", "IdentitiesOnly=yes"]


def require_command(name: str) -> str:
    path = shutil.which(name)
    if path is None:
        raise SystemExit(f"Required command not found: {name}")
    return path


def run(command: list[str], *, input_data: bytes | None = None) -> None:
    print("+", " ".join(shlex.quote(part) for part in command))
    result = subprocess.run(command, input=input_data)
    if result.returncode:
        raise SystemExit(f"Command failed with exit code {result.returncode}")


def capture(command: list[str], *, input_data: bytes | None = None
            ) -> subprocess.CompletedProcess[bytes]:
    """Run a command, capturing its output instead of inheriting stdout.

    The machine-readable commands print one JSON document and nothing else, so
    the traced command line goes to stderr here rather than to stdout.
    """
    print("+", " ".join(shlex.quote(part) for part in command), file=sys.stderr)
    return subprocess.run(command, input=input_data, capture_output=True)


def output(command: list[str]) -> str:
    return subprocess.check_output(command, text=True).strip()


def sha256(path: pathlib.Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def validate_image(kind: str, path: pathlib.Path) -> dict[str, int | str]:
    try:
        base, limit, ram_start, ram_limit = LAYOUTS[kind]
    except KeyError as exc:
        raise SystemExit(f"Unknown image kind: {kind}") from exc
    data = path.read_bytes()
    if len(data) < 32 or len(data) > limit - base:
        raise SystemExit(f"Invalid {kind} image size: {len(data)} bytes")
    stack, reset = struct.unpack_from("<II", data)
    reset_address = reset & ~1
    if not ram_start <= stack < ram_limit:
        raise SystemExit(f"Stack vector outside expected SRAM: 0x{stack:08x}")
    if not base <= reset_address < limit or not reset & 1:
        raise SystemExit(f"Reset vector outside expected Thumb image: 0x{reset:08x}")
    result = {
        "kind": kind,
        "size": len(data),
        "stack": f"0x{stack:08x}",
        "reset": f"0x{reset:08x}",
        "sha256": sha256(path),
    }
    print(json.dumps(result, indent=2))
    return result


def git_commit(directory: pathlib.Path) -> str:
    return output([require_command("git"), "-C", str(directory), "rev-parse", "HEAD"])


def build_firmware(args: argparse.Namespace) -> None:
    make = require_command("make")
    require_command("git")
    klipper = args.klipper_dir.resolve()
    katapult = args.katapult_dir.resolve()
    for name, directory in (("Klipper", klipper), ("Katapult", katapult)):
        if not (directory / ".git").exists():
            raise SystemExit(f"{name} path is not a Git checkout: {directory}")

    output_dir = args.output.resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    configs = REPO_ROOT / "firmware-configs"
    saved: dict[pathlib.Path, bytes | None] = {}
    for directory in (klipper, katapult):
        config = directory / ".config"
        saved[config] = config.read_bytes() if config.exists() else None

    def make_project(directory: pathlib.Path) -> None:
        run([make, "-C", str(directory), "olddefconfig"])
        run([make, "-C", str(directory), "clean"])
        run([make, "-C", str(directory), f"-j{os.cpu_count() or 1}"])

    try:
        builds = (
            (configs / "klipper/plus4-mainboard.config", klipper,
             klipper / "out/klipper.bin", output_dir / "plus4-mainboard-klipper.bin",
             "mainboard"),
            (configs / "klipper/plus4-toolhead.config", klipper,
             klipper / "out/klipper.bin", output_dir / "plus4-toolhead-klipper.bin",
             "toolhead-app"),
            (configs / "katapult/plus4-toolhead.config", katapult,
             katapult / "out/katapult.bin", output_dir / "plus4-toolhead-katapult.bin",
             "toolhead-katapult"),
        )
        for fragment, source, built, target, kind in builds:
            shutil.copyfile(fragment, source / ".config")
            make_project(source)
            if not built.exists():
                raise SystemExit(f"Expected build output was not created: {built}")
            shutil.copyfile(built, target)
            validate_image(kind, target)
    finally:
        for config, content in saved.items():
            if content is None:
                config.unlink(missing_ok=True)
            else:
                config.write_bytes(content)

    try:
        toolchain = output([require_command("arm-none-eabi-gcc"), "--version"]).splitlines()[0]
    except (SystemExit, subprocess.SubprocessError, OSError):
        toolchain = "unknown"
    metadata = [
        f"built_at_utc={datetime.now(timezone.utc).isoformat()}",
        f"klipper_commit={git_commit(klipper)}",
        f"katapult_commit={git_commit(katapult)}",
        f"arm_none_eabi_gcc={toolchain}",
    ]
    for image in sorted(output_dir.glob("*.bin")):
        metadata.append(f"{sha256(image)}  {image.name}")
    text = "\n".join(metadata) + "\n"
    (output_dir / "BUILD-METADATA.txt").write_text(text, encoding="utf-8")
    print(text, end="")


def download_file(url: str, target: pathlib.Path) -> None:
    request = urllib.request.Request(url, headers={"User-Agent": "qidi-plus4-firmware"})
    with urllib.request.urlopen(request, timeout=60) as response, target.open("wb") as stream:
        total = int(response.headers.get("Content-Length", "0"))
        copied = 0
        while chunk := response.read(1024 * 1024):
            stream.write(chunk)
            copied += len(chunk)
            if total:
                print(f"\r{target.name}: {copied * 100 / total:5.1f}%", end="", flush=True)
    print()


def armbian_image(args: argparse.Namespace) -> None:
    base = "https://dl.armbian.com/qidi-x6/Trixie_current_minimal"
    print("Official Armbian Qidi X-6 / Plus4 minimal image")
    print("https://www.armbian.com/boards/qidi-x6")
    print("Build: ./compile.sh BOARD=qidi-x6 RELEASE=trixie "
          "BUILD_DESKTOP=no BUILD_MINIMAL=yes KERNEL_CONFIGURE=no")
    if args.list_only:
        return
    args.output.mkdir(parents=True, exist_ok=True)
    target = args.output / "Armbian_qidi-x6_trixie_current_minimal.img.xz"
    sha_target = target.with_suffix(target.suffix + ".sha")
    try:
        download_file(base, target)
        download_file(base + ".sha", sha_target)
    except BaseException:
        # Leave no truncated image behind on an interrupted or failed download.
        target.unlink(missing_ok=True)
        sha_target.unlink(missing_ok=True)
        raise
    expected = sha_target.read_text(encoding="utf-8").split()[0].lower()
    actual = sha256(target)
    if actual != expected:
        target.unlink(missing_ok=True)
        sha_target.unlink(missing_ok=True)
        raise SystemExit(f"Armbian image SHA-256 mismatch: expected {expected}, got {actual}")
    print(f"Verified SHA-256 {actual}")


def ssh_base(args: argparse.Namespace) -> tuple[list[str], str]:
    host, user, port = validate_connection(args)
    ssh = require_command("ssh")
    target = f"{user}@{host}"
    password_options = password_auth_options(args)
    connection_reuse = [] if password_options else mux_options()
    options = (["-p", str(port), "-o", "ConnectTimeout=10",
                "-o", "ServerAliveInterval=15", "-o", "ServerAliveCountMax=2"]
               + password_options + identity_options(args) + connection_reuse)
    return ([ssh] + options + ["--", target], target)


def scp_base(args: argparse.Namespace) -> list[str]:
    _host, _user, port = validate_connection(args)
    scp = require_command("scp")
    password_options = password_auth_options(args)
    connection_reuse = [] if password_options else mux_options()
    return ([scp, "-P", str(port), "-o", "ConnectTimeout=10"]
            + password_options + identity_options(args) + connection_reuse + ["--"])


def collect_facts(args: argparse.Namespace) -> tuple[dict | None, str]:
    """Collect machine-readable migration facts over SSH.

    Returns `(facts, reason)`. `facts` is None when the printer could not be
    read, in which case `reason` says why. An unreachable printer is a normal
    outcome here, not an error: the host is legitimately absent during the eMMC
    swap, which is exactly when a resume decision has to be made.
    """
    ssh, _ = ssh_base(args)
    # Both arguments are always sent, empty when unset, so their positions stay
    # fixed. The printer user makes the collector read the Klipper account's
    # home rather than the home of whichever account was used to connect.
    data_dir = getattr(args, "data_dir", "") or ""
    printer_user = getattr(args, "printer_user", None) or ""
    remote = (f"bash -s -- probe {shlex.quote(data_dir)} "
              f"{shlex.quote(printer_user)}")
    completed = capture(ssh + [remote], input_data=REMOTE_HELPER.read_bytes())
    stderr = completed.stderr.decode("utf-8", errors="replace").strip()
    if completed.returncode != 0:
        detail = stderr.splitlines()[-1] if stderr else ""
        reason = f"probe command exited {completed.returncode}"
        return None, f"{reason}: {detail}" if detail else reason
    text = completed.stdout.decode("utf-8", errors="replace")
    try:
        facts = json.loads(text)
    except json.JSONDecodeError as exc:
        return None, f"probe output was not valid JSON: {exc}"
    if not isinstance(facts, dict):
        return None, "probe output was not a JSON object"
    if stderr:
        print(stderr, file=sys.stderr)
    return facts, ""


def audit(args: argparse.Namespace) -> None:
    if getattr(args, "json", False):
        facts, reason = collect_facts(args)
        document = facts if facts is not None else {
            "schema": probes.SCHEMA_VERSION, "reachable": False, "reason": reason
        }
        print(json.dumps(document, indent=2, sort_keys=True))
        return
    ssh, _ = ssh_base(args)
    run(ssh + ["bash -s -- audit"], input_data=REMOTE_HELPER.read_bytes())


def list_probes(_args: argparse.Namespace) -> None:
    print(json.dumps(
        [{"id": probe.id, "stage": probe.stage, "description": probe.description}
         for probe in probes.PROBES],
        indent=2,
    ))


def probe_printer(args: argparse.Namespace) -> None:
    """Report which migration stages are observably complete on a printer.

    Always exits 0 when it produced a well-formed report. Whether the printer
    answered is carried by `reachable` and by per-probe `indeterminate` results,
    so that "the tool broke" stays distinguishable from "the printer could not
    tell us". Collapsing those two into one exit code is precisely the ambiguity
    this command exists to remove.
    """
    try:
        selected = probes.select(args.probe or None)
    except KeyError as exc:
        raise SystemExit(str(exc).strip('"')) from exc
    ids = [probe.id for probe in selected]

    if args.facts_file:
        try:
            facts = json.loads(args.facts_file.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise SystemExit(f"Could not read facts file {args.facts_file}: {exc}") from exc
        if not isinstance(facts, dict):
            raise SystemExit(f"Facts file is not a JSON object: {args.facts_file}")
        reason = ""
    else:
        facts, reason = collect_facts(args)

    if facts is None:
        results = probes.unreachable(reason, ids)
        document = probes.report(args.printer, None, results, reachable=False)
    else:
        results = probes.evaluate(facts, ids=ids)
        document = probes.report(args.printer, facts, results, reachable=True)
    if not args.include_facts:
        document.pop("facts", None)
    print(json.dumps(document, indent=2, sort_keys=True))


def backup_printer(args: argparse.Namespace) -> None:
    ssh, target = ssh_base(args)
    scp = scp_base(args)
    safe_name = "".join(c if c.isalnum() or c in "._-" else "-" for c in (args.name or args.printer)).strip("-")
    timestamp = datetime.now().strftime("%Y%m%d-%H%M%S")
    base = f"qidi-plus4-{safe_name or 'printer'}-{timestamp}"
    destination = args.output.resolve() / safe_name
    destination.mkdir(parents=True, exist_ok=True)
    archive = destination / f"{base}.tar.gz"
    manifest = destination / f"{base}-manifest.txt"
    checksum = archive.with_suffix(archive.suffix + ".sha256")
    archive_partial = archive.with_name(archive.name + ".partial")
    manifest_partial = manifest.with_name(manifest.name + ".partial")
    checksum_partial = checksum.with_name(checksum.name + ".partial")
    final_paths = (archive, manifest, checksum)
    partial_paths = (archive_partial, manifest_partial, checksum_partial)
    occupied = [
        path
        for path in (*final_paths, *partial_paths)
        if path.exists() or path.is_symlink()
    ]
    if occupied:
        raise SystemExit(
            "Refusing to overwrite an existing backup artifact: "
            + ", ".join(str(path) for path in occupied)
        )
    remote_helper = f"/tmp/{base}-backup.sh"
    remote_manifest = f"/tmp/{base}-manifest.txt"
    run(scp + [str(BACKUP_HELPER), f"{target}:{remote_helper}"])
    run(ssh + [f"chmod 700 {shlex.quote(remote_helper)}"])
    command = [shlex.quote(remote_helper), shlex.quote(remote_manifest),
               "1" if args.include_gcodes else "0",
               "1" if args.include_logs else "0",
               "1" if args.include_environments else "0"]
    print(f"Streaming backup to {archive_partial}")
    published: list[pathlib.Path] = []
    try:
        with archive_partial.open("xb") as stream:
            result = subprocess.run(ssh + [" ".join(command)], stdout=stream)
        if result.returncode:
            raise SystemExit(f"Remote backup failed with exit code {result.returncode}")
        run(scp + [f"{target}:{remote_manifest}", str(manifest_partial)])
        if not manifest_partial.is_file():
            raise SystemExit("Remote backup did not return its manifest")
        with tarfile.open(archive_partial, "r:gz") as bundle:
            bundle.getmembers()
        digest = sha256(archive_partial)
        with checksum_partial.open("x", encoding="ascii", newline="\n") as stream:
            stream.write(f"{digest}  {archive.name}\n")

        # Publish the archive last. A consumer can only observe the final
        # archive name after its manifest and checksum have been fully written.
        for partial, final in (
            (manifest_partial, manifest),
            (checksum_partial, checksum),
            (archive_partial, archive),
        ):
            os.replace(partial, final)
            published.append(final)
    except BaseException:
        for partial in partial_paths:
            partial.unlink(missing_ok=True)
        if archive not in published:
            for final in published:
                final.unlink(missing_ok=True)
        raise
    finally:
        subprocess.run(
            ssh
            + [
                f"rm -f {shlex.quote(remote_helper)} "
                f"{shlex.quote(remote_manifest)}"
            ]
        )
    print(f"Verified {archive}\nSHA-256 {digest}")


def bootstrap_host(args: argparse.Namespace) -> None:
    if args.confirm != "BOOTSTRAP-HOST":
        raise SystemExit("This action requires --confirm BOOTSTRAP-HOST")
    ssh, target = ssh_base(args)
    remote = f"/home/{args.user}/bootstrap-mainline.sh"
    remote_tuning = f"/home/{args.user}/qidi-host-tuning.sh"
    run(scp_base(args) + [str(BOOTSTRAP_HELPER), f"{target}:{remote}"])
    run(scp_base(args) + [str(HOST_TUNING_HELPER), f"{target}:{remote_tuning}"])
    environment = " ".join((
        f"KLIPPER_REF={shlex.quote(args.klipper_ref)}",
        f"MOONRAKER_REF={shlex.quote(args.moonraker_ref)}",
        f"KATAPULT_REF={shlex.quote(args.katapult_ref)}",
        f"QIDI_HOST_TUNING_HELPER={shlex.quote(remote_tuning)}",
    ))
    run(ssh + [f"chmod 700 {shlex.quote(remote)} && {environment} {shlex.quote(remote)}"])


def host_tuning(args: argparse.Namespace) -> None:
    if args.command == "tune-host" and args.confirm != "TUNE-HOST":
        raise SystemExit("This action requires --confirm TUNE-HOST")

    ssh, target = ssh_base(args)
    if args.command == "audit-host-tuning":
        run(ssh + ["bash -s -- audit"], input_data=HOST_TUNING_HELPER.read_bytes())
        return

    remote = "/tmp/qidi-host-tuning.sh"
    run(scp_base(args) + [str(HOST_TUNING_HELPER), f"{target}:{remote}"])
    cleanup = f"rm -f {shlex.quote(remote)}"
    # The tuning targets the account that owns Klipper, which is not necessarily
    # the account this connection uses.
    printer_user = getattr(args, "printer_user", None) or args.user
    command = (
        f"trap {shlex.quote(cleanup)} EXIT; "
        f"chmod 700 {shlex.quote(remote)} && "
        f"sudo -n bash {shlex.quote(remote)} install "
        f"--printer-user {shlex.quote(printer_user)}"
    )
    run(ssh + [command])


def _checked_capture(command: list[str]) -> bytes:
    completed = capture(command)
    if completed.returncode:
        stderr = completed.stderr.decode("utf-8", errors="replace").strip()
        detail = f": {stderr.splitlines()[-1]}" if stderr else ""
        raise SystemExit(
            f"Command failed with exit code {completed.returncode}{detail}"
        )
    return completed.stdout


class RemoteJsonError(Exception):
    """A remote JSON operation failed, possibly after returning useful proof."""

    def __init__(
        self,
        message: str,
        *,
        document: dict | None = None,
        returncode: int | None = None,
    ) -> None:
        super().__init__(message)
        self.document = document
        self.returncode = returncode


def _remote_json(ssh: list[str], command: str) -> dict:
    completed = capture(ssh + [command])
    raw = completed.stdout
    try:
        result = json.loads(raw.decode("utf-8"))
    except (UnicodeDecodeError, json.JSONDecodeError) as exc:
        raise RemoteJsonError(
            f"Remote PLR installer returned invalid JSON: {exc}",
            returncode=completed.returncode,
        ) from exc
    if not isinstance(result, dict):
        raise RemoteJsonError(
            "Remote PLR installer did not return a JSON object",
            returncode=completed.returncode,
        )
    if completed.returncode:
        stderr = completed.stderr.decode("utf-8", errors="replace").strip()
        remote_error = result.get("error")
        if isinstance(remote_error, str) and remote_error.strip():
            # ``install.py --json`` deliberately writes its structured failure
            # document to stdout.  Preserve that authoritative diagnostic when
            # the process also exits non-zero; stderr is normally empty in this
            # mode and used to reduce every preflight refusal to the unhelpful
            # ``Remote PLR installer exited 1``.
            detail = f": {remote_error.strip().splitlines()[-1]}"
        else:
            detail = f": {stderr.splitlines()[-1]}" if stderr else ""
        raise RemoteJsonError(
            f"Remote PLR installer exited {completed.returncode}{detail}",
            document=result,
            returncode=completed.returncode,
        )
    if not result.get("ok"):
        raise RemoteJsonError(
            f"Remote PLR installer refused: {result.get('error', 'unknown error')}",
            document=result,
            returncode=completed.returncode,
        )
    return result


def deploy_plr_hardening(args: argparse.Namespace) -> None:
    """Upload, plan, stop, apply, and verify PLR hardening without restart."""

    if args.confirm != "DEPLOY-PLR-HARDENING":
        raise SystemExit(
            "This action requires --confirm DEPLOY-PLR-HARDENING"
    )
    service = _validated_plr_service(args.service)
    account, paths = _validated_plr_layout(args)
    transaction_id = _plr_transaction_id()
    assets = PLR_DEPLOYMENT_ASSETS
    missing = [name for name in assets if not (PLR_HARDENING_DIR / name).is_file()]
    if missing:
        raise SystemExit(f"PLR deployment assets missing: {', '.join(missing)}")
    ssh, target = ssh_base(args)
    stage: str | None = None
    stopped = False
    phase = "staging"
    plan: dict | None = None
    installation: dict | None = None
    verification: dict | None = None
    backup_manifest: str | None = None
    try:
        stage_raw = _checked_capture(
            ssh + ["mktemp -d /tmp/qidi-plr-hardening.XXXXXXXX"]
        ).decode("utf-8", errors="strict").strip()
        if not re.fullmatch(r"/tmp/qidi-plr-hardening\.[A-Za-z0-9]+", stage_raw):
            raise SystemExit(f"Unsafe remote staging path returned: {stage_raw!r}")
        stage = stage_raw
        for name in assets:
            _checked_capture(
                scp_base(args)
                + [str(PLR_HARDENING_DIR / name), f"{target}:{stage}/{name}"]
            )
        installer = [
            "sudo", "-n", args.remote_python, f"{stage}/install.py",
            "--printer-user", account,
            "--transaction-id", transaction_id,
            "--klipper-dir", args.klipper_dir,
            "--printer-data", args.printer_data,
            "--scripts-dir", args.scripts_dir,
            "--python", args.remote_python,
            "--service", service,
            "--json",
        ]
        install_command = " ".join(shlex.quote(part) for part in installer)
        phase = "plan"
        plan = _remote_json(ssh, install_command)
        _validate_remote_plr_identity(plan, account, paths)
        planned_backup = plan.get("backup_manifest")
        if plan.get("changed"):
            if not isinstance(planned_backup, str):
                raise SystemExit("Changed PLR plan omitted its backup manifest")
            backup_manifest = _validated_plr_backup_manifest(
                planned_backup, paths["scripts_dir"]
            )
        elif planned_backup is not None:
            raise SystemExit("Unchanged PLR plan returned a backup manifest")
        if not plan.get("changed"):
            result = {
                "schema": "qidi-plus4-plr-deployment/v1",
                "ok": True,
                "changed": False,
                "applied": False,
                "verified": True,
                "klipper_left_stopped": False,
                "backup_manifest": None,
                "safety_manifest": None,
                "transaction_state": "not_started",
                "account": account,
                "paths": paths,
                "plan": plan,
            }
            print(json.dumps(result, indent=2, sort_keys=True))
            return

        phase = "stop"
        _checked_capture(
            ssh + [f"sudo -n systemctl stop {shlex.quote(service)}"]
        )
        state = capture(ssh + [f"systemctl is-active {shlex.quote(service)}"])
        observed = state.stdout.decode("utf-8", errors="replace").strip()
        if state.returncode != 3 or observed != "inactive":
            raise SystemExit(
                f"Could not prove {service} inactive after stop "
                f"(exit {state.returncode}, state={observed!r})"
            )
        stopped = True
        phase = "apply"
        installation = _remote_json(
            ssh, install_command + " --apply --klipper-stopped"
        )
        _validate_remote_plr_identity(installation, account, paths)
        backup_manifest = installation.get("backup_manifest")
        if backup_manifest != plan.get("backup_manifest"):
            raise SystemExit(
                "PLR installer changed its predeclared backup_manifest"
            )
        phase = "verify"
        verification = _remote_json(ssh, install_command)
        _validate_remote_plr_identity(verification, account, paths)
        if verification.get("changed"):
            raise SystemExit("Post-install PLR verification is not idempotent")
        result = {
            "schema": "qidi-plus4-plr-deployment/v1",
            "ok": True,
            "changed": True,
            "applied": True,
            "verified": True,
            "klipper_left_stopped": True,
            # Keep this at the top level so orchestration can hand the exact
            # opaque rollback handle to a later start or rollback command
            # without scraping files from the printer. The complete installer
            # result remains nested for auditability.
            "backup_manifest": backup_manifest,
            "safety_manifest": None,
            "transaction_state": "applied",
            "account": account,
            "paths": paths,
            "plan": plan,
            "installation": installation,
            "verification": verification,
            "next_step": (
                f"Review the installed manifest and start {service} explicitly; "
                "this command never restarts Klipper"
            ),
        }
        print(json.dumps(result, indent=2, sort_keys=True))
    except BaseException as exc:
        remote_document = (
            exc.document if isinstance(exc, RemoteJsonError) else None
        )
        identity_error = None
        if remote_document is not None and (
            remote_document.get("account") != account
            or remote_document.get("paths") != paths
        ):
            identity_error = (
                "remote failure result did not match the validated account and paths"
            )
            remote_document = None
        if remote_document is not None:
            if phase == "plan":
                plan = remote_document
            elif phase == "apply":
                installation = remote_document
            elif phase == "verify":
                verification = remote_document
            candidate = remote_document.get("backup_manifest")
            if candidate not in (None, backup_manifest):
                identity_error = "remote failure result changed the backup manifest"
                remote_document = None
        safety_manifest = None
        if remote_document is not None:
            candidate = remote_document.get("safety_manifest")
            if candidate is not None:
                identity_error = "deploy result unexpectedly returned a safety manifest"
                remote_document = None
        if identity_error is not None and remote_document is None:
            if phase == "plan":
                plan = None
            elif phase == "apply":
                installation = None
            elif phase == "verify":
                verification = None
        error = identity_error or str(exc).strip() or exc.__class__.__name__
        remote_state = (
            remote_document.get("transaction_state")
            if remote_document is not None
            else None
        )
        if phase == "verify" and installation is not None:
            transaction_state = "indeterminate"
            applied: bool | None = None
        elif remote_state in {
            "not_started",
            "auto_rolled_back",
            "partial",
            "indeterminate",
        }:
            transaction_state = remote_state
            applied = (
                None
                if remote_state in {"partial", "indeterminate"}
                else False
            )
        else:
            transaction_state = "not_started" if not stopped else "indeterminate"
            applied = False if transaction_state == "not_started" else None
        exposed_backup_manifest = (
            None if transaction_state == "not_started" else backup_manifest
        )
        failure = {
            "schema": "qidi-plus4-plr-deployment/v1",
            "ok": False,
            "changed": bool(plan and plan.get("changed")),
            "applied": applied,
            "verified": False,
            "klipper_left_stopped": stopped,
            "service": service,
            "phase": phase,
            "backup_manifest": exposed_backup_manifest,
            "safety_manifest": safety_manifest,
            "transaction_state": transaction_state,
            "account": account,
            "paths": paths,
            "plan": plan,
            "installation": installation,
            "verification": verification,
            "error": error,
        }
        if exposed_backup_manifest:
            failure["next_command"] = (
                "rollback-plr-hardening --backup-manifest %s "
                "--confirm ROLLBACK-PLR-HARDENING" % exposed_backup_manifest
            )
        print(json.dumps(failure, indent=2, sort_keys=True))
        if stopped:
            print(
                f"PLR deployment stopped {service}; it has deliberately been left "
                "stopped after the failure.",
                file=sys.stderr,
            )
        raise SystemExit(1)
    finally:
        if stage is not None:
            # The path is accepted only after the strict /tmp regex above.
            subprocess.run(
                ssh + [f"rm -rf -- {shlex.quote(stage)}"],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )


def _validated_plr_service(service: str) -> str:
    if service != KLIPPER_SERVICE:
        raise SystemExit(
            f"PLR operations target exactly {KLIPPER_SERVICE}; got {service!r}"
        )
    return service


def _validated_plr_layout(args: argparse.Namespace) -> tuple[str, dict[str, str]]:
    account = getattr(args, "printer_user", None) or args.user
    try:
        account = connection_user(account)
    except argparse.ArgumentTypeError as exc:
        raise SystemExit(f"Invalid PLR printer account: {exc}") from exc
    home = f"/home/{account}"
    printer_data = f"{home}/printer_data"
    scripts_dir = f"{home}/scripts/plr"
    gcode_root = f"{printer_data}/gcodes"
    paths = {
        "home": home,
        "klipper_dir": f"{home}/klipper",
        "printer_data": printer_data,
        "scripts_dir": scripts_dir,
        "python": f"{home}/klippy-env/bin/python",
        "gcode_root": gcode_root,
        "checkpoint": f"{scripts_dir}/plr_checkpoint.json",
        "record": f"{scripts_dir}/plr_record",
        "output": f"{gcode_root}/.plr/plr.gcode",
    }
    supplied = {
        "klipper_dir": args.klipper_dir,
        "printer_data": args.printer_data,
        "scripts_dir": args.scripts_dir,
        "python": args.remote_python,
    }
    for key, value in supplied.items():
        if value != paths[key]:
            raise SystemExit(
                f"PLR {key} must match printer account {account}: {paths[key]}"
            )
    return account, paths


def _plr_transaction_id() -> str:
    stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    return f"{stamp}-{secrets.token_hex(8)}"


def _validate_remote_plr_identity(
    document: dict, account: str, paths: dict[str, str]
) -> None:
    if document.get("account") != account or document.get("paths") != paths:
        raise RemoteJsonError(
            "Remote PLR result did not match the validated printer account and paths",
            document=document,
        )


def refresh_klippee_agent(args: argparse.Namespace) -> None:
    """Restart only Klippee's managed user service and verify it is active."""

    if args.confirm != "REFRESH-KLIPPEE-AGENT":
        raise SystemExit(
            "This action requires --confirm REFRESH-KLIPPEE-AGENT"
        )
    ssh, _target = ssh_base(args)
    agent_user = getattr(args, "printer_user", None) or args.user
    # validate_connection() inside ssh_base validated both account names. If a
    # dedicated management account is used, run systemctl against the Klipper
    # owner's user bus rather than silently targeting a same-named unit under
    # the management account.
    if agent_user == args.user:
        systemctl = "systemctl --user"
    else:
        quoted_user = shlex.quote(agent_user)
        systemctl = (
            f"uid=$(id -u -- {quoted_user}) && "
            f"sudo -n -u {quoted_user} env XDG_RUNTIME_DIR=/run/user/$uid "
            "DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/$uid/bus systemctl --user"
        )
    restart = capture(
        ssh + [f"{systemctl} restart {KLIPPEE_AGENT_SERVICE}"]
    )
    state = capture(
        ssh + [f"{systemctl} is-active {KLIPPEE_AGENT_SERVICE}"]
    )
    observed = state.stdout.decode("utf-8", errors="replace").strip()
    ok = restart.returncode == 0 and state.returncode == 0 and observed == "active"
    result = {
        "schema": "qidi-plus4-klippee-agent-refresh/v1",
        "ok": ok,
        "service": KLIPPEE_AGENT_SERVICE,
        "scope": "user",
        "account": agent_user,
        "observed_state": observed or "unknown",
        "restart_exit": restart.returncode,
        "state_exit": state.returncode,
        "klipper_actions_performed": False,
        "config_deployment_performed": False,
    }
    if not ok:
        result["error"] = "Klippee Moonraker agent did not reach the active state"
    print(json.dumps(result, indent=2, sort_keys=True))
    if not ok:
        raise SystemExit(1)


def _decode_unique_json(raw: bytes, label: str) -> dict:
    if not raw or len(raw) > KLIPPEE_AGENT_MAX_RESULT_BYTES:
        raise SystemExit(f"{label} returned an invalid result size")

    def unique_object(pairs: list[tuple[str, object]]) -> dict:
        result = {}
        for name, value in pairs:
            if name in result:
                raise ValueError(f"duplicate field {name!r}")
            result[name] = value
        return result

    try:
        document = json.loads(
            raw.decode("utf-8"), object_pairs_hook=unique_object
        )
    except (UnicodeDecodeError, json.JSONDecodeError, ValueError) as exc:
        raise SystemExit(f"{label} returned invalid JSON: {exc}") from exc
    if not isinstance(document, dict):
        raise SystemExit(f"{label} did not return one JSON object")
    return document


def _klippee_agent_version_key(value: str) -> tuple[int, ...]:
    if not KLIPPEE_AGENT_VERSION.fullmatch(value):
        raise SystemExit(f"Invalid Klippee agent version: {value!r}")
    return tuple(int(part) for part in value.split("."))


def _validate_klippee_agent_artifact(value: object, label: str) -> dict:
    if not isinstance(value, dict) or set(value) != {"version", "sha256"}:
        raise SystemExit(f"Klippee agent upgrade returned invalid {label} evidence")
    version = value.get("version")
    digest = value.get("sha256")
    if not isinstance(version, str) or not KLIPPEE_AGENT_VERSION.fullmatch(version):
        raise SystemExit(f"Klippee agent upgrade returned an invalid {label} version")
    if not isinstance(digest, str) or not KLIPPEE_AGENT_SHA256.fullmatch(digest):
        raise SystemExit(f"Klippee agent upgrade returned an invalid {label} SHA-256")
    return value


def _validate_klippee_agent_upgrade_result(
    document: dict, *, returncode: int
) -> dict:
    required = {
        "schema", "ok", "changed", "account", "cli_path", "source_url",
        "before", "after", "service", "scope", "observed_state",
        "before_pid", "after_pid", "upgrade_exit", "state_exit",
        "upgrade_reported_success", "agent_restart_performed",
        "klipper_actions_performed", "config_deployment_performed",
    }
    allowed = required | {"error"}
    if not required.issubset(document) or not set(document).issubset(allowed):
        raise SystemExit("Klippee agent upgrade returned an unexpected contract")
    if (
        document.get("schema") != KLIPPEE_AGENT_UPGRADE_SCHEMA
        or document.get("account") != KLIPPEE_AGENT_ACCOUNT
        or document.get("cli_path") != KLIPPEE_AGENT_CLI_PATH
        or document.get("source_url") != KLIPPEE_AGENT_UPGRADE_SOURCE
        or document.get("service") != KLIPPEE_AGENT_SERVICE
        or document.get("scope") != "user"
    ):
        raise SystemExit("Klippee agent upgrade returned an unexpected fixed identity")
    boolean_fields = (
        "ok", "changed", "upgrade_reported_success",
        "agent_restart_performed", "klipper_actions_performed",
        "config_deployment_performed",
    )
    if any(not isinstance(document.get(name), bool) for name in boolean_fields):
        raise SystemExit("Klippee agent upgrade returned an invalid boolean proof")
    if (
        document["klipper_actions_performed"]
        or document["config_deployment_performed"]
    ):
        raise SystemExit("Klippee agent upgrade did not prove zero Klipper/config actions")

    before = _validate_klippee_agent_artifact(document.get("before"), "before")
    after = _validate_klippee_agent_artifact(document.get("after"), "after")
    if _klippee_agent_version_key(after["version"]) < _klippee_agent_version_key(before["version"]):
        raise SystemExit("Klippee agent upgrade reported a version downgrade")
    changed = (
        before["version"] != after["version"]
        or before["sha256"] != after["sha256"]
    )
    if document["changed"] != changed:
        raise SystemExit("Klippee agent upgrade returned inconsistent artifact evidence")

    state = document.get("observed_state")
    integer_fields = ("before_pid", "after_pid", "upgrade_exit", "state_exit")
    if (
        not isinstance(state, str)
        or not state
        or len(state) > 32
        or re.fullmatch(r"[a-z-]+", state) is None
        or any(
            isinstance(document.get(name), bool)
            or not isinstance(document.get(name), int)
            for name in integer_fields
        )
        or not 0 < document["before_pid"] <= 2_147_483_647
        or not 0 <= document["after_pid"] <= 2_147_483_647
        or not 0 <= document["upgrade_exit"] <= 255
        or not 0 <= document["state_exit"] <= 255
    ):
        raise SystemExit("Klippee agent upgrade returned invalid process/service evidence")
    if document["upgrade_reported_success"] != (document["upgrade_exit"] == 0):
        raise SystemExit("Klippee agent upgrade returned inconsistent exit evidence")
    if (state == "active") != (document["state_exit"] == 0):
        raise SystemExit("Klippee agent upgrade returned inconsistent service evidence")
    if document["agent_restart_performed"]:
        if document["before_pid"] == document["after_pid"]:
            raise SystemExit("Klippee agent upgrade returned inconsistent restart evidence")
    elif document["before_pid"] != document["after_pid"]:
        raise SystemExit("Klippee agent upgrade returned unexplained process churn")

    ok = document["ok"]
    error = document.get("error")
    if ok:
        if returncode != 0:
            raise SystemExit("Klippee agent upgrade exited nonzero after reporting success")
        if "error" in document and error:
            raise SystemExit("Klippee agent upgrade reported success with an error")
        if (
            state != "active"
            or document["upgrade_exit"] != 0
            or not document["upgrade_reported_success"]
            or not document["agent_restart_performed"]
            or document["after_pid"] <= 0
        ):
            raise SystemExit("Klippee agent upgrade omitted required success proof")
    else:
        if returncode == 0:
            raise SystemExit("Klippee agent upgrade exited zero after reporting failure")
        if not isinstance(error, str) or not error.strip() or len(error) > 2_000:
            raise SystemExit("Klippee agent upgrade failure omitted its bounded error")
    return document


def upgrade_klippee_agent(args: argparse.Namespace) -> None:
    """Run the reviewed source-bound Klippee upgrader over SSH stdin."""

    if args.confirm != KLIPPEE_AGENT_UPGRADE_ACTION:
        raise SystemExit(
            f"This action requires --confirm {KLIPPEE_AGENT_UPGRADE_ACTION}"
        )
    account = getattr(args, "printer_user", None) or args.user
    if account != KLIPPEE_AGENT_ACCOUNT:
        raise SystemExit(
            "Klippee agent upgrade requires the fixed mks printer account"
        )
    ssh, _target = ssh_base(args)
    helper = KLIPPEE_AGENT_UPGRADE_HELPER
    if (
        helper.is_symlink()
        or not helper.is_file()
        or not 0 < helper.stat().st_size <= 128 * 1024
    ):
        raise SystemExit(f"Reviewed Klippee upgrade helper not found: {helper}")
    isolated_python = (
        "/usr/bin/env -i HOME=/home/mks USER=mks LOGNAME=mks "
        "PATH=/usr/bin:/bin LANG=C LC_ALL=C /usr/bin/python3 -I -"
    )
    if args.user == KLIPPEE_AGENT_ACCOUNT:
        remote_command = "exec " + isolated_python
    else:
        remote_command = (
            "exec /usr/bin/sudo -n -u mks " + isolated_python
        )
    completed = capture(
        ssh + [remote_command],
        input_data=helper.read_bytes(),
    )
    if not completed.stdout and completed.returncode:
        detail = " ".join(
            completed.stderr.decode("utf-8", errors="replace").split()
        )[:500]
        suffix = f": {detail}" if detail else ""
        raise SystemExit(
            f"Klippee agent upgrade exited {completed.returncode}{suffix}"
        )
    result = _decode_unique_json(completed.stdout, "Klippee agent upgrade")
    _validate_klippee_agent_upgrade_result(
        result, returncode=completed.returncode
    )
    print(json.dumps(result, indent=2, sort_keys=True))
    if completed.returncode:
        raise SystemExit(completed.returncode)


def _validated_plr_backup_manifest(path: str, scripts_dir: str) -> str:
    scripts_dir = scripts_dir.rstrip("/")
    pattern = (
        re.escape(scripts_dir)
        + r"/backups/plr-hardening-[A-Za-z0-9._-]+/backup-manifest\.json"
    )
    if not scripts_dir.startswith("/") or not re.fullmatch(pattern, path):
        raise SystemExit(
            "Rollback manifest must be an exact PLR installer backup-manifest.json "
            f"below {scripts_dir}/backups"
        )
    return path


def _validated_plr_safety_manifest(path: str, scripts_dir: str) -> str:
    scripts_dir = scripts_dir.rstrip("/")
    pattern = (
        re.escape(scripts_dir)
        + r"/backups/plr-rollback-safety-[A-Za-z0-9._-]+/safety-manifest\.json"
    )
    if not scripts_dir.startswith("/") or not re.fullmatch(pattern, path):
        raise SystemExit(
            "Safety manifest must be an exact safety-manifest.json below "
            f"{scripts_dir}/backups"
        )
    return path


def start_klipper(args: argparse.Namespace) -> None:
    """Explicitly start exactly one reviewed Klipper unit and verify active."""

    if args.confirm != "START-KLIPPER":
        raise SystemExit("This action requires --confirm START-KLIPPER")
    service = _validated_plr_service(args.service)
    rollback_hint = None
    if args.rollback_manifest:
        rollback_hint = _validated_plr_backup_manifest(
            args.rollback_manifest, args.scripts_dir
        )
    ssh, _target = ssh_base(args)
    start = capture(ssh + [f"sudo -n systemctl start {shlex.quote(service)}"])
    samples = []
    state = None
    for index in range(KLIPPER_START_STABILITY_CHECKS):
        state = capture(ssh + [f"systemctl is-active {shlex.quote(service)}"])
        observed = state.stdout.decode("utf-8", errors="replace").strip()
        samples.append({"state": observed or "unknown", "exit": state.returncode})
        if state.returncode != 0 or observed != "active":
            break
        if index + 1 < KLIPPER_START_STABILITY_CHECKS:
            time.sleep(KLIPPER_START_STABILITY_INTERVAL_SECONDS)
    assert state is not None
    observed = samples[-1]["state"]
    stable = (
        len(samples) == KLIPPER_START_STABILITY_CHECKS
        and all(item["exit"] == 0 and item["state"] == "active" for item in samples)
    )
    ok = start.returncode == 0 and stable
    result = {
        "schema": "qidi-plus4-klipper-start/v1",
        "ok": ok,
        "service": service,
        "observed_state": observed or "unknown",
        "start_exit": start.returncode,
        "state_exit": state.returncode,
        "stability_checks_required": KLIPPER_START_STABILITY_CHECKS,
        "stability_interval_seconds": KLIPPER_START_STABILITY_INTERVAL_SECONDS,
        "stability_samples": samples,
        "config_or_file_reads_performed": False,
        "rollback_manifest": rollback_hint,
    }
    if not ok:
        result["error"] = (
            "Klipper activation did not remain active for the bounded stability window"
        )
        if rollback_hint:
            result["next_command"] = (
                "rollback-plr-hardening --backup-manifest %s "
                "--confirm ROLLBACK-PLR-HARDENING" % rollback_hint
            )
    print(json.dumps(result, indent=2, sort_keys=True))
    if not ok:
        raise SystemExit(1)


def rollback_plr_hardening(args: argparse.Namespace) -> None:
    """Restore one validated installer backup and leave Klipper stopped."""

    if args.confirm != "ROLLBACK-PLR-HARDENING":
        raise SystemExit(
            "This action requires --confirm ROLLBACK-PLR-HARDENING"
    )
    service = _validated_plr_service(args.service)
    account, paths = _validated_plr_layout(args)
    transaction_id = _plr_transaction_id()
    manifest = _validated_plr_backup_manifest(
        args.backup_manifest, paths["scripts_dir"]
    )
    missing = [
        name
        for name in PLR_DEPLOYMENT_ASSETS
        if not (PLR_HARDENING_DIR / name).is_file()
    ]
    if missing:
        raise SystemExit(f"PLR deployment assets missing: {', '.join(missing)}")
    ssh, target = ssh_base(args)
    stage: str | None = None
    stopped = False
    phase = "staging"
    plan: dict | None = None
    rollback_result: dict | None = None
    verification: dict | None = None
    safety_manifest: str | None = None
    try:
        stage_raw = _checked_capture(
            ssh + ["mktemp -d /tmp/qidi-plr-hardening.XXXXXXXX"]
        ).decode("utf-8", errors="strict").strip()
        if not re.fullmatch(r"/tmp/qidi-plr-hardening\.[A-Za-z0-9]+", stage_raw):
            raise SystemExit(f"Unsafe remote staging path returned: {stage_raw!r}")
        stage = stage_raw
        for name in PLR_DEPLOYMENT_ASSETS:
            _checked_capture(
                scp_base(args)
                + [str(PLR_HARDENING_DIR / name), f"{target}:{stage}/{name}"]
            )
        installer = [
            "sudo", "-n", args.remote_python, f"{stage}/install.py",
            "--printer-user", account,
            "--transaction-id", transaction_id,
            "--klipper-dir", args.klipper_dir,
            "--printer-data", args.printer_data,
            "--scripts-dir", args.scripts_dir,
            "--python", args.remote_python,
            "--service", service,
            "--rollback-manifest", manifest,
            "--json",
        ]
        command = " ".join(shlex.quote(part) for part in installer)
        phase = "plan"
        plan = _remote_json(ssh, command)
        _validate_remote_plr_identity(plan, account, paths)
        if plan.get("backup_manifest") != manifest:
            raise SystemExit("Rollback plan did not echo the exact backup manifest")
        planned_safety = plan.get("safety_manifest")
        if plan.get("changed"):
            if not isinstance(planned_safety, str):
                raise SystemExit("Changed rollback plan omitted safety_manifest")
            safety_manifest = _validated_plr_safety_manifest(
                planned_safety, paths["scripts_dir"]
            )
        elif planned_safety is not None:
            raise SystemExit("Unchanged rollback plan returned safety_manifest")
        if not plan.get("changed"):
            print(json.dumps({
                "schema": "qidi-plus4-plr-rollback/v1",
                "ok": True,
                "changed": False,
                "applied": False,
                "verified": True,
                "klipper_left_stopped": False,
                "backup_manifest": manifest,
                "safety_manifest": None,
                "transaction_state": "not_started",
                "account": account,
                "paths": paths,
                "plan": plan,
            }, indent=2, sort_keys=True))
            return
        phase = "stop"
        _checked_capture(
            ssh + [f"sudo -n systemctl stop {shlex.quote(service)}"]
        )
        state = capture(ssh + [f"systemctl is-active {shlex.quote(service)}"])
        observed = state.stdout.decode("utf-8", errors="replace").strip()
        if state.returncode != 3 or observed != "inactive":
            raise SystemExit(
                f"Could not prove {service} inactive before rollback "
                f"(exit {state.returncode}, state={observed!r})"
            )
        stopped = True
        phase = "apply"
        rollback_result = _remote_json(
            ssh, command + " --apply --klipper-stopped"
        )
        _validate_remote_plr_identity(rollback_result, account, paths)
        if rollback_result.get("backup_manifest") != manifest:
            raise SystemExit("Rollback result changed the backup manifest handle")
        safety_candidate = rollback_result.get("safety_manifest")
        if safety_candidate != plan.get("safety_manifest"):
            raise SystemExit("Rollback changed its predeclared safety_manifest")
        phase = "verify"
        verification = _remote_json(ssh, command)
        _validate_remote_plr_identity(verification, account, paths)
        if verification.get("backup_manifest") != manifest:
            raise SystemExit("Rollback verification changed the backup manifest handle")
        if verification.get("changed"):
            raise SystemExit("Post-rollback verification is not idempotent")
        print(json.dumps({
            "schema": "qidi-plus4-plr-rollback/v1",
            "ok": True,
            "changed": True,
            "applied": True,
            "verified": True,
            "klipper_left_stopped": True,
            "backup_manifest": manifest,
            "safety_manifest": safety_manifest,
            "transaction_state": "rolled_back",
            "account": account,
            "paths": paths,
            "plan": plan,
            "rollback": rollback_result,
            "verification": verification,
        }, indent=2, sort_keys=True))
    except BaseException as exc:
        remote_document = (
            exc.document if isinstance(exc, RemoteJsonError) else None
        )
        identity_error = None
        if remote_document is not None and (
            remote_document.get("account") != account
            or remote_document.get("paths") != paths
        ):
            identity_error = (
                "remote failure result did not match the validated account and paths"
            )
            remote_document = None
        if remote_document is not None:
            if phase == "plan":
                plan = remote_document
            elif phase == "apply":
                rollback_result = remote_document
            elif phase == "verify":
                verification = remote_document
            echoed = remote_document.get("backup_manifest")
            if echoed not in (None, manifest):
                identity_error = "remote failure result changed the backup manifest"
                remote_document = None
            elif isinstance(remote_document.get("safety_manifest"), str):
                try:
                    safety_manifest = _validated_plr_safety_manifest(
                        remote_document["safety_manifest"], paths["scripts_dir"]
                    )
                except SystemExit as safety_error:
                    identity_error = str(safety_error)
                    remote_document = None
                    safety_manifest = None
        remote_state = (
            remote_document.get("transaction_state")
            if remote_document is not None
            else None
        )
        if phase == "verify" and rollback_result is not None:
            transaction_state = "indeterminate"
            applied: bool | None = None
        elif remote_state in {
            "not_started",
            "safety_restored",
            "partial",
            "indeterminate",
        }:
            transaction_state = remote_state
            applied = (
                None
                if remote_state in {"partial", "indeterminate"}
                else False
            )
        else:
            transaction_state = "not_started" if not stopped else "indeterminate"
            applied = False if transaction_state == "not_started" else None
        exposed_safety_manifest = (
            None if transaction_state == "not_started" else safety_manifest
        )
        failure = {
            "schema": "qidi-plus4-plr-rollback/v1",
            "ok": False,
            "changed": bool(plan and plan.get("changed")),
            "applied": applied,
            "verified": False,
            "klipper_left_stopped": stopped,
            "service": service,
            "phase": phase,
            "transaction_state": transaction_state,
            "backup_manifest": manifest,
            "safety_manifest": exposed_safety_manifest,
            "account": account,
            "paths": paths,
            "plan": plan,
            "rollback": rollback_result,
            "verification": verification,
            "error": identity_error or str(exc).strip() or exc.__class__.__name__,
        }
        print(json.dumps(failure, indent=2, sort_keys=True))
        if stopped:
            print(
                f"Rollback has deliberately left {service} stopped.",
                file=sys.stderr,
            )
        raise SystemExit(1)
    finally:
        if stage is not None:
            subprocess.run(
                ssh + [f"rm -rf -- {shlex.quote(stage)}"],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )


def config_profile_source(args: argparse.Namespace) -> tuple[pathlib.Path, str]:
    profile_dir = getattr(args, "profile_dir", None)
    if profile_dir is not None:
        source = profile_dir.expanduser().resolve()
        if not source.is_dir():
            raise SystemExit(f"Config profile directory does not exist: {source}")
        return source, source.name

    profile = args.profile or DEFAULT_CONFIG_PROFILE
    source = MAINLINE_CONFIGS / profile
    if source.is_dir():
        return source, profile
    available = ", ".join(
        path.name for path in sorted(MAINLINE_CONFIGS.iterdir()) if path.is_dir()
    )
    raise SystemExit(f"Unknown config profile {profile!r}. Available: {available}")


def managed_render_directory(path: pathlib.Path) -> bool:
    """Return whether path carries a render-config ownership marker.

    Early versions wrote three metadata fields without a schema. Accept that
    exact shape so existing generated configs remain replaceable, while new
    outputs carry an explicit schema and manager.
    """
    if path.is_symlink() or not path.is_dir():
        return False
    marker = path / RENDER_METADATA_FILE
    if marker.is_symlink() or not marker.is_file():
        return False
    try:
        metadata = json.loads(marker.read_text(encoding="utf-8"))
    except (OSError, UnicodeDecodeError, json.JSONDecodeError):
        return False
    if not isinstance(metadata, dict):
        return False
    profile = metadata.get("profile")
    serial = metadata.get("beacon_serial")
    rendered_at = metadata.get("rendered_at_utc")
    if not all(
        isinstance(value, str) and value for value in (profile, serial, rendered_at)
    ):
        return False
    if (not serial.startswith("/dev/serial/by-id/usb-Beacon_") or
            any(character.isspace() for character in serial)):
        return False
    schema = metadata.get("schema")
    manager = metadata.get("managed_by")
    if schema is None and manager is None:
        return set(metadata) == {"profile", "beacon_serial", "rendered_at_utc"}
    return schema == RENDER_METADATA_SCHEMA and manager == RENDER_METADATA_MANAGER


def install_rendered_directory(staging: pathlib.Path, destination: pathlib.Path) -> None:
    """Install a complete staged render without first deleting its predecessor."""
    if not destination.exists():
        os.replace(staging, destination)
        return

    backup = staging.with_name(staging.name + ".previous")
    os.replace(destination, backup)
    try:
        os.replace(staging, destination)
    except BaseException:
        os.replace(backup, destination)
        raise
    try:
        shutil.rmtree(backup)
    except OSError as exc:
        print(f"Warning: rendered config was installed but old copy remains at {backup}: {exc}",
              file=sys.stderr)


def render_config(args: argparse.Namespace) -> None:
    source, profile = config_profile_source(args)

    serial = args.beacon_serial.strip()
    if (not serial.startswith("/dev/serial/by-id/usb-Beacon_") or
            any(character.isspace() for character in serial)):
        raise SystemExit(
            "--beacon-serial must be the complete whitespace-free "
            "/dev/serial/by-id/usb-Beacon_... path"
        )

    destination = pathlib.Path(os.path.abspath(args.output.expanduser()))
    if destination == source:
        raise SystemExit("Config output must not replace its source profile directory")
    if destination.exists():
        if not args.force:
            raise SystemExit(f"Output already exists (use --force to replace it): {destination}")
        if not managed_render_directory(destination):
            raise SystemExit(
                f"Refusing to replace unmanaged output directory: {destination}. "
                f"Only directories carrying a recognized {RENDER_METADATA_FILE} marker "
                "may be replaced."
            )
    elif destination.is_symlink():
        raise SystemExit(f"Config output must not be a symlink: {destination}")

    destination.parent.mkdir(parents=True, exist_ok=True)
    staging = pathlib.Path(tempfile.mkdtemp(
        prefix=f".{destination.name}.render-", dir=destination.parent
    ))
    try:
        rendered = 0
        for source_file in sorted(source.glob("*.cfg")):
            text = source_file.read_text(encoding="utf-8")
            text = text.replace(BEACON_SERIAL_TOKEN, serial)
            (staging / source_file.name).write_text(
                text, encoding="utf-8", newline="\n"
            )
            rendered += 1
        if not rendered:
            raise SystemExit(f"No .cfg files found in profile: {source}")
        remaining = [
            path.name for path in staging.glob("*.cfg")
            if BEACON_SERIAL_TOKEN in path.read_text(encoding="utf-8")
        ]
        if remaining:
            raise SystemExit(f"Unresolved Beacon serial token in: {', '.join(remaining)}")

        metadata = {
            "schema": RENDER_METADATA_SCHEMA,
            "managed_by": RENDER_METADATA_MANAGER,
            "profile": profile,
            "beacon_serial": serial,
            "rendered_at_utc": datetime.now(timezone.utc).isoformat(),
        }
        (staging / RENDER_METADATA_FILE).write_text(
            json.dumps(metadata, indent=2) + "\n", encoding="utf-8", newline="\n"
        )
        install_rendered_directory(staging, destination)
    finally:
        if staging.exists():
            shutil.rmtree(staging)
    print(f"Rendered {rendered} configuration files to {destination}")
    print("Review them before copying them to a printer; this profile is not calibrated.")


def stage(args: argparse.Namespace, kind: str) -> tuple[list[str], str, str]:
    ssh, target = ssh_base(args)
    image = args.image.resolve()
    validate_image(kind, image)
    remote_image = f"{args.remote_directory}/{kind}.bin"
    remote_helper = f"{args.remote_directory}/qidi-plus4-remote.sh"
    remote_layouts = f"{args.remote_directory}/mcu-layouts.json"
    remote_dir = shlex.quote(args.remote_directory)
    scp = scp_base(args)
    run(ssh + [f"mkdir -p {remote_dir}"])
    run(scp + [str(REMOTE_HELPER), f"{target}:{remote_helper}"])
    run(scp + [str(LAYOUTS_FILE), f"{target}:{remote_layouts}"])
    run(scp + [str(image), f"{target}:{remote_image}"])
    return ssh, remote_helper, remote_image


def remote_action(args: argparse.Namespace) -> None:
    if args.command == "flash-mainboard":
        raise SystemExit(
            "Direct SSH mainboard flashing is disabled: repeated live tests on "
            "the stock Plus4 did not enter QIDI's UART bootloader. No firmware "
            "pages were transferred. Copy plus4-mainboard-klipper.bin to a FAT32 "
            "microSD card as qd_mcu.bin and follow docs/MAINLINE-MIGRATION.md."
        )
    actions = {
        "validate-mainboard": ("mainboard", "validate", None),
        "validate-toolhead-katapult": ("toolhead-katapult", "validate", None),
        "validate-toolhead": ("toolhead-app", "validate", None),
        "flash-toolhead-katapult": ("toolhead-katapult", "flash-toolhead-katapult", "ERASE-TOOLHEAD"),
        "flash-toolhead": ("toolhead-app", "flash-toolhead", "FLASH-TOOLHEAD"),
    }
    kind, remote_command, required_confirmation = actions[args.command]
    if required_confirmation and args.confirm != required_confirmation:
        raise SystemExit(f"This action requires --confirm {required_confirmation}")
    ssh, helper, image = stage(args, kind)
    digest = sha256(args.image.resolve())
    parts = [shlex.quote(helper), remote_command]
    if remote_command == "validate":
        parts += [kind, shlex.quote(image)]
    else:
        parts += [shlex.quote(image), digest, required_confirmation]
        if remote_command == "flash-toolhead-katapult":
            parts.append(shlex.quote(f"{args.remote_directory}/backups"))
        elif remote_command == "flash-toolhead":
            parts.append(shlex.quote(args.katapult_directory))
    run(ssh + [f"chmod 700 {shlex.quote(helper)} && " + " ".join(parts)])


def default_private_key() -> pathlib.Path | None:
    ssh_dir = pathlib.Path.home() / ".ssh"
    for name in ("id_ed25519", "id_ecdsa", "id_rsa"):
        if (ssh_dir / f"{name}.pub").exists():
            return ssh_dir / name
    return None


def is_default_key(private: pathlib.Path) -> bool:
    return (private.parent == (pathlib.Path.home() / ".ssh")
            and private.name in ("id_ed25519", "id_ecdsa", "id_rsa"))


def setup_ssh(args: argparse.Namespace) -> None:
    ssh = require_command("ssh")
    host, user, port = validate_connection(args)
    # Validate noninteractive password mode before generating or reading any
    # key material, so a missing bootstrap secret leaves no partial setup.
    password_options = password_auth_options(args)
    if args.identity:
        private = pathlib.Path(args.identity).expanduser()
        if private.suffix == ".pub":
            private = private.with_suffix("")
    else:
        found = default_private_key()
        private = found if found is not None else (pathlib.Path.home() / ".ssh" / "id_ed25519")
    public = private.with_name(private.name + ".pub")

    if not public.exists():
        if not args.generate:
            raise SystemExit(
                f"Public key not found: {public}. Re-run with --generate to create an "
                "ed25519 key, or pass --identity <existing-key>."
            )
        private.parent.mkdir(mode=0o700, parents=True, exist_ok=True)
        run([require_command("ssh-keygen"), "-t", "ed25519", "-N", "", "-f", str(private)])
        if not public.exists():
            raise SystemExit(f"Key generation did not produce {public}")

    key_line = public.read_text(encoding="utf-8").strip()
    target = f"{user}@{host}"
    # This first connection authenticates with the printer password. It uses
    # neither the identity nor multiplexing, so the operator is prompted exactly
    # once here; every later command reuses the installed key.
    install = ([ssh, "-p", str(port), "-o", "ConnectTimeout=10"]
               + password_options + ["--", target,
               'set -e; install -d -m 700 "$HOME/.ssh"; '
               'touch "$HOME/.ssh/authorized_keys"; chmod 600 "$HOME/.ssh/authorized_keys"; '
               'key="$(cat)"; '
               'grep -qxF "$key" "$HOME/.ssh/authorized_keys" '
               '|| printf "%s\\n" "$key" >> "$HOME/.ssh/authorized_keys"'])
    if password_options:
        print(f"Installing {public.name} on {target} through configured SSH askpass.")
    else:
        print(f"Installing {public.name} on {target}. Enter the printer password once when prompted.")
    run(install, input_data=(key_line + "\n").encode("utf-8"))

    verify = [ssh, "-p", str(port), "-o", "ConnectTimeout=10", "-o", "BatchMode=yes",
              "-i", str(private), "-o", "IdentitiesOnly=yes", "--", target, "true"]
    print("Verifying key-based login...")
    if subprocess.run(verify).returncode:
        raise SystemExit(
            "Key installed, but key-based login did not succeed. Confirm the printer "
            "permits public-key authentication."
        )
    print("Key-based SSH is working; later commands will not prompt for a password.")
    if not is_default_key(private):
        print(f"Pass --identity {private} to the other qidi_plus4.py commands.")


def setup_management_user(args: argparse.Namespace) -> None:
    """Create a dedicated management account, leaving the Klipper account alone.

    This runs through an account that already has passwordless sudo, so no
    password is entered anywhere. The new account is key-only: no password is
    ever set on it, and the password field is locked.
    """
    if args.confirm != "CREATE-MANAGEMENT-USER":
        raise SystemExit("This action requires --confirm CREATE-MANAGEMENT-USER")
    try:
        new_user = connection_user(args.new_user)
    except argparse.ArgumentTypeError as exc:
        raise SystemExit(f"Invalid management user: {exc}") from exc

    public = pathlib.Path(args.pubkey).expanduser()
    if public.suffix != ".pub":
        public = public.with_name(public.name + ".pub")
    if not public.is_file():
        raise SystemExit(f"Public key not found: {public}")
    key_line = public.read_text(encoding="utf-8").strip()
    if not key_line.startswith(("ssh-", "ecdsa-")):
        raise SystemExit(f"{public} does not look like an OpenSSH public key")
    if "\n" in key_line:
        raise SystemExit(f"{public} holds more than one key; pass a single key file")

    ssh, _ = ssh_base(args)
    remote = " ".join((
        "bash -s -- setup-management-user",
        shlex.quote(new_user),
        shlex.quote(key_line),
        "CREATE-MANAGEMENT-USER",
    ))
    print(f"Creating management account {new_user!r} on {args.printer}...")
    run(ssh + [remote], input_data=REMOTE_HELPER.read_bytes())

    private = public.with_suffix("")
    if not private.is_file():
        print(f"Account created. Private key {private} is not present here, so "
              "key login was not verified.")
        return
    host, _user, port = validate_connection(args)
    verify = [require_command("ssh"), "-p", str(port),
              "-o", "ConnectTimeout=10", "-o", "BatchMode=yes",
              "-i", str(private), "-o", "IdentitiesOnly=yes",
              "--", f"{new_user}@{host}",
              "id -un; sudo -n true && echo sudo=ok"]
    print(f"Verifying key login as {args.new_user}...")
    if subprocess.run(verify).returncode:
        raise SystemExit(
            f"The account was created but key login as {new_user} did not "
            "succeed. Check the printer's sshd configuration before relying on it."
        )
    print(f"{new_user} is ready. Point the inventory's `user` at it and keep "
          "`printerUser` on the account that owns Klipper.")


def stage_mainboard_sdcard(args: argparse.Namespace) -> None:
    image = args.image.resolve()
    validate_image("mainboard", image)
    destination = args.output.resolve()
    destination.mkdir(parents=True, exist_ok=True)
    target = destination / "qd_mcu.bin"
    if target.exists() and not args.force:
        raise SystemExit(f"{target} already exists (use --force to overwrite).")
    shutil.copyfile(image, target)
    digest = sha256(target)
    (destination / "qd_mcu.bin.sha256").write_text(f"{digest}  qd_mcu.bin\n", encoding="ascii")
    print(f"Staged validated mainboard image to {target}")
    print(f"SHA-256 {digest}")
    print("Copy qd_mcu.bin to the root of a FAT32 microSD card, insert it into the "
          "mainboard, and power on. A successful update renames it to qd_mcu.CUR. "
          "See docs/MAINLINE-MIGRATION.md.")


def smoke_test(args: argparse.Namespace) -> None:
    if not SMOKE_TEST_CONFIG.exists():
        raise SystemExit(f"Smoke-test config missing: {SMOKE_TEST_CONFIG}")
    ssh, target = ssh_base(args)
    remote_tmp = "/tmp/qidi-smoke-test-printer.cfg"
    remote_cfg = f"{args.data_dir}/config/printer.cfg"
    remote_log = f"{args.data_dir}/logs/klippy.log"
    run(scp_base(args) + [str(SMOKE_TEST_CONFIG), f"{target}:{remote_tmp}"])
    # The config belongs to the Klipper account, which is not necessarily the
    # account this connection uses. Copy through sudo and hand ownership back,
    # so a dedicated management account can install it without owning the
    # directory.
    owner = shlex.quote(getattr(args, "printer_user", None) or args.user)
    install = (
        f"set -e; cfg={shlex.quote(remote_cfg)}; tmp={shlex.quote(remote_tmp)}; "
        f"owner={owner}; "
        "ts=$(date -u +%Y%m%dT%H%M%SZ); "
        'if [ -s "$cfg" ]; then sudo -n cp -p "$cfg" "$cfg.$ts.bak"; '
        'echo "Backed up existing printer.cfg to $cfg.$ts.bak"; fi; '
        'sudo -n install -m 644 -o "$owner" -g "$owner" "$tmp" "$cfg"; '
        "sudo -n systemctl restart klipper"
    )
    print("Installing the inert smoke-test printer.cfg and restarting mainline Klipper...")
    run(ssh + [install])
    inspect = (f"log={shlex.quote(remote_log)}; sleep 8; "
               'if [ -f "$log" ]; then tail -n 40 "$log"; '
               'else echo "klippy.log not found at $log"; fi')
    print('Recent klippy.log output (both MCUs should reach "Ready"):')
    run(ssh + [inspect])
    print('\nIf either MCU reports "is not responding" or the host stays in shutdown, '
          "recheck that board's firmware and UART before installing the real configuration.")


def add_connection(parser: argparse.ArgumentParser, *, image: bool = False) -> None:
    parser.add_argument("--printer", required=True, type=connection_host)
    parser.add_argument("--user", default="mks", type=connection_user)
    parser.add_argument("--printer-user", type=connection_user,
                        help="Account that owns Klipper on the printer, when it "
                             "differs from the account used to connect")
    parser.add_argument("--port", type=connection_port, default=22)
    parser.add_argument("--identity", help="SSH private key for password-free login (see setup-ssh)")
    parser.add_argument(
        "--password-env",
        type=password_environment_name,
        help="temporary bootstrap password environment name (requires forced SSH_ASKPASS)",
    )
    if image:
        parser.add_argument("--image", type=pathlib.Path, required=True)
        parser.add_argument("--remote-directory", default="/home/mks/qidi-mainline-migration")


def create_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)

    build = sub.add_parser("build", help="Build all three MCU images")
    build.add_argument("--klipper-dir", type=pathlib.Path, required=True)
    build.add_argument("--katapult-dir", type=pathlib.Path, required=True)
    build.add_argument("--output", type=pathlib.Path,
                       default=DEFAULT_ARTIFACTS / "mainline-firmware")
    build.set_defaults(func=build_firmware)

    image = sub.add_parser("armbian-image", help="Download and verify the official Qidi X-6 image")
    image.add_argument("--output", type=pathlib.Path, default=DEFAULT_ARTIFACTS / "armbian")
    image.add_argument("--list-only", action="store_true")
    image.set_defaults(func=armbian_image)

    setup = sub.add_parser("setup-ssh", help="Install an SSH key so later commands need no password")
    add_connection(setup)
    setup.add_argument("--generate", action="store_true",
                       help="Create an ed25519 key if none exists")
    setup.set_defaults(func=setup_ssh)

    manage = sub.add_parser(
        "setup-management-user",
        help="Create a dedicated key-only management account with passwordless sudo",
    )
    add_connection(manage)
    manage.add_argument("--new-user", default="plab",
                        help="Account to create (default: plab)")
    manage.add_argument("--pubkey", required=True,
                        help="OpenSSH public key to install for the new account")
    manage.add_argument("--confirm", required=True)
    manage.set_defaults(func=setup_management_user)

    audit_parser = sub.add_parser("audit", help="Run a read-only live printer audit")
    add_connection(audit_parser)
    audit_parser.add_argument("--json", action="store_true",
                              help="Emit collected facts as JSON instead of text")
    audit_parser.add_argument("--data-dir", default="",
                              help="Remote printer_data directory (default: ~/printer_data)")
    audit_parser.set_defaults(func=audit)

    probe_parser = sub.add_parser(
        "probe", help="Report which migration stages are observably complete"
    )
    add_connection(probe_parser)
    probe_parser.add_argument("--data-dir", default="",
                              help="Remote printer_data directory (default: ~/printer_data)")
    probe_parser.add_argument("--probe", action="append", default=[],
                              help="Evaluate only this probe; repeat for several")
    probe_parser.add_argument("--include-facts", action="store_true",
                              help="Embed the raw collected facts in the report")
    probe_parser.add_argument("--facts-file", type=pathlib.Path,
                              help="Evaluate a saved facts document instead of "
                                   "connecting (for replay and testing)")
    probe_parser.set_defaults(func=probe_printer)

    probe_list = sub.add_parser("probes", help="List the available migration probes")
    probe_list.set_defaults(func=list_probes)

    backup = sub.add_parser("backup", help="Stream a filesystem/source backup over SSH")
    add_connection(backup)
    backup.add_argument("--name")
    backup.add_argument("--output", type=pathlib.Path,
                        default=REPO_ROOT / "data/printer-backups")
    backup.add_argument("--include-gcodes", action="store_true")
    backup.add_argument("--include-logs", action="store_true")
    backup.add_argument("--include-environments", action="store_true")
    backup.set_defaults(func=backup_printer)

    bootstrap = sub.add_parser("bootstrap-host", help="Install official Klipper and Moonraker")
    add_connection(bootstrap)
    bootstrap.add_argument("--confirm", required=True)
    bootstrap.add_argument("--klipper-ref", default="master")
    bootstrap.add_argument("--moonraker-ref", default="master")
    bootstrap.add_argument("--katapult-ref", default="master")
    bootstrap.set_defaults(func=bootstrap_host)

    tuning_audit = sub.add_parser(
        "audit-host-tuning",
        help="Read and verify CPU, service, and UART IRQ affinity on a migrated host",
    )
    add_connection(tuning_audit)
    tuning_audit.set_defaults(func=host_tuning)

    tuning_install = sub.add_parser(
        "tune-host",
        help="Install persistent RK3328 CPU and UART latency tuning",
    )
    add_connection(tuning_install)
    tuning_install.add_argument("--confirm", required=True)
    tuning_install.set_defaults(func=host_tuning)

    refresh_agent = sub.add_parser(
        "refresh-klippee-agent",
        help="Restart only the managed Klippee Moonraker user service and verify active",
    )
    add_connection(refresh_agent)
    refresh_agent.add_argument("--confirm", required=True)
    refresh_agent.set_defaults(func=refresh_klippee_agent)

    upgrade_agent = sub.add_parser(
        "upgrade-klippee-agent",
        help="Upgrade the fixed Klippee CLI and prove its managed agent restarted",
    )
    add_connection(upgrade_agent)
    upgrade_agent.add_argument("--confirm", required=True)
    upgrade_agent.set_defaults(func=upgrade_klippee_agent)

    plr_deploy = sub.add_parser(
        "deploy-plr-hardening",
        help="Safely install source-bound PLR runtime assets and leave Klipper stopped",
    )
    add_connection(plr_deploy)
    plr_deploy.add_argument("--confirm", required=True)
    plr_deploy.add_argument("--klipper-dir", default="/home/mks/klipper")
    plr_deploy.add_argument("--printer-data", default="/home/mks/printer_data")
    plr_deploy.add_argument("--scripts-dir", default="/home/mks/scripts/plr")
    plr_deploy.add_argument("--remote-python", default="/home/mks/klippy-env/bin/python")
    plr_deploy.add_argument(
        "--service", default=KLIPPER_SERVICE, choices=(KLIPPER_SERVICE,)
    )
    plr_deploy.set_defaults(func=deploy_plr_hardening)

    start_service = sub.add_parser(
        "start-klipper",
        help="Explicitly start one Klipper service and verify it reaches active",
    )
    add_connection(start_service)
    start_service.add_argument("--confirm", required=True)
    start_service.add_argument(
        "--service", default=KLIPPER_SERVICE, choices=(KLIPPER_SERVICE,)
    )
    start_service.add_argument(
        "--rollback-manifest",
        help="validated PLR backup path to include as a failure recovery hint",
    )
    start_service.add_argument("--scripts-dir", default="/home/mks/scripts/plr")
    start_service.set_defaults(func=start_klipper)

    rollback_plr = sub.add_parser(
        "rollback-plr-hardening",
        help="Restore one PLR installer backup and leave Klipper stopped",
    )
    add_connection(rollback_plr)
    rollback_plr.add_argument("--confirm", required=True)
    rollback_plr.add_argument("--backup-manifest", required=True)
    rollback_plr.add_argument("--klipper-dir", default="/home/mks/klipper")
    rollback_plr.add_argument("--printer-data", default="/home/mks/printer_data")
    rollback_plr.add_argument("--scripts-dir", default="/home/mks/scripts/plr")
    rollback_plr.add_argument("--remote-python", default="/home/mks/klippy-env/bin/python")
    rollback_plr.add_argument(
        "--service", default=KLIPPER_SERVICE, choices=(KLIPPER_SERVICE,)
    )
    rollback_plr.set_defaults(func=rollback_plr_hardening)

    config = sub.add_parser(
        "render-config", help="Render a per-printer mainline config from a reviewed profile"
    )
    source = config.add_mutually_exclusive_group()
    source.add_argument("--profile", default=DEFAULT_CONFIG_PROFILE,
                        help="Bundled profile name (default: %(default)s)")
    source.add_argument("--profile-dir", type=pathlib.Path,
                        help="Exact external profile directory, for example from qidi-plus4-configs")
    config.add_argument("--beacon-serial", required=True)
    config.add_argument("--output", type=pathlib.Path, required=True)
    config.add_argument(
        "--force", action="store_true",
        help=f"replace an existing output only when it has a recognized {RENDER_METADATA_FILE}",
    )
    config.set_defaults(func=render_config)

    sdcard = sub.add_parser(
        "stage-mainboard-sdcard",
        help="Validate a mainboard image and stage it as qd_mcu.bin for the microSD route",
    )
    sdcard.add_argument("--image", type=pathlib.Path, required=True)
    sdcard.add_argument("--output", type=pathlib.Path, required=True,
                        help="microSD card root or a staging directory")
    sdcard.add_argument("--force", action="store_true")
    sdcard.set_defaults(func=stage_mainboard_sdcard)

    smoke = sub.add_parser(
        "smoke-test", help="Install the inert two-MCU config and confirm both MCUs connect"
    )
    add_connection(smoke)
    smoke.add_argument("--data-dir", default="/home/mks/printer_data")
    smoke.set_defaults(func=smoke_test)

    for name in ("validate-mainboard", "validate-toolhead-katapult", "validate-toolhead",
                 "flash-mainboard", "flash-toolhead-katapult", "flash-toolhead"):
        action = sub.add_parser(name)
        add_connection(action, image=True)
        if name.startswith("flash-"):
            action.add_argument("--confirm", required=True)
        if name == "flash-toolhead":
            action.add_argument("--katapult-directory", default="/home/mks/katapult")
        action.set_defaults(func=remote_action)
    return parser


def main() -> None:
    args = create_parser().parse_args()
    if hasattr(args, "printer"):
        validate_connection(args)
    # Validate the bootstrap channel before any command can create local
    # artifacts or alter remote state. Individual ssh/scp builders repeat this
    # validation so library callers receive the same fail-closed behavior.
    password_auth_options(args)
    args.func(args)


if __name__ == "__main__":
    main()
