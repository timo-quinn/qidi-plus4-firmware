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
import shlex
import shutil
import struct
import subprocess
import tarfile
import tempfile
import urllib.request
from datetime import datetime, timezone


SCRIPT_DIR = pathlib.Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent.parent
REMOTE_HELPER = SCRIPT_DIR / "qidi-plus4-remote.sh"
BOOTSTRAP_HELPER = SCRIPT_DIR / "bootstrap-mainline.sh"
BACKUP_HELPER = SCRIPT_DIR / "backup-remote.sh"
LAYOUTS_FILE = SCRIPT_DIR / "mcu-layouts.json"
SMOKE_TEST_CONFIG = SCRIPT_DIR / "smoke-test-printer.cfg"
DEFAULT_ARTIFACTS = REPO_ROOT / "artifacts"
MAINLINE_CONFIGS = REPO_ROOT / "mainline-configs"
DEFAULT_CONFIG_PROFILE = "plus4-x7-v1.0-beacon"
BEACON_SERIAL_TOKEN = "CHANGE_ME_BEACON_SERIAL"


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


def identity_options(args: argparse.Namespace) -> list[str]:
    identity = getattr(args, "identity", None)
    if not identity:
        return []
    path = pathlib.Path(identity).expanduser()
    if not path.exists():
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
    ssh = require_command("ssh")
    target = f"{args.user}@{args.printer}"
    options = (["-p", str(args.port), "-o", "ConnectTimeout=10",
                "-o", "ServerAliveInterval=15", "-o", "ServerAliveCountMax=2"]
               + identity_options(args) + mux_options())
    return ([ssh] + options + [target], target)


def scp_base(args: argparse.Namespace) -> list[str]:
    scp = require_command("scp")
    return ([scp, "-P", str(args.port), "-o", "ConnectTimeout=10"]
            + identity_options(args) + mux_options())


def audit(args: argparse.Namespace) -> None:
    ssh, _ = ssh_base(args)
    run(ssh + ["bash -s -- audit"], input_data=REMOTE_HELPER.read_bytes())


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
    remote_helper = f"/tmp/{base}-backup.sh"
    remote_manifest = f"/tmp/{base}-manifest.txt"
    run(scp + [str(BACKUP_HELPER), f"{target}:{remote_helper}"])
    run(ssh + [f"chmod 700 {shlex.quote(remote_helper)}"])
    command = [shlex.quote(remote_helper), shlex.quote(remote_manifest),
               "1" if args.include_gcodes else "0",
               "1" if args.include_logs else "0",
               "1" if args.include_environments else "0"]
    print(f"Streaming backup to {archive}")
    try:
        with archive.open("wb") as stream:
            result = subprocess.run(ssh + [" ".join(command)], stdout=stream)
        if result.returncode:
            archive.unlink(missing_ok=True)
            raise SystemExit(f"Remote backup failed with exit code {result.returncode}")
        run(scp + [f"{target}:{remote_manifest}", str(manifest)])
    finally:
        subprocess.run(ssh + [f"rm -f {shlex.quote(remote_helper)} {shlex.quote(remote_manifest)}"])
    with tarfile.open(archive, "r:gz") as bundle:
        bundle.getmembers()
    digest = sha256(archive)
    archive.with_suffix(archive.suffix + ".sha256").write_text(
        f"{digest}  {archive.name}\n", encoding="ascii"
    )
    print(f"Verified {archive}\nSHA-256 {digest}")


def bootstrap_host(args: argparse.Namespace) -> None:
    if args.confirm != "BOOTSTRAP-HOST":
        raise SystemExit("This action requires --confirm BOOTSTRAP-HOST")
    ssh, target = ssh_base(args)
    remote = f"/home/{args.user}/bootstrap-mainline.sh"
    run(scp_base(args) + [str(BOOTSTRAP_HELPER), f"{target}:{remote}"])
    environment = " ".join((
        f"KLIPPER_REF={shlex.quote(args.klipper_ref)}",
        f"MOONRAKER_REF={shlex.quote(args.moonraker_ref)}",
        f"KATAPULT_REF={shlex.quote(args.katapult_ref)}",
    ))
    run(ssh + [f"chmod 700 {shlex.quote(remote)} && {environment} {shlex.quote(remote)}"])


def render_config(args: argparse.Namespace) -> None:
    source = MAINLINE_CONFIGS / args.profile
    if not source.is_dir():
        available = ", ".join(path.name for path in sorted(MAINLINE_CONFIGS.iterdir())
                              if path.is_dir())
        raise SystemExit(f"Unknown config profile {args.profile!r}. Available: {available}")

    serial = args.beacon_serial.strip()
    if (not serial.startswith("/dev/serial/by-id/usb-Beacon_") or
            any(character.isspace() for character in serial)):
        raise SystemExit(
            "--beacon-serial must be the complete whitespace-free "
            "/dev/serial/by-id/usb-Beacon_... path"
        )

    destination = args.output.resolve()
    artifact_root = DEFAULT_ARTIFACTS.resolve()
    if destination == artifact_root or artifact_root not in destination.parents:
        raise SystemExit(f"Config output must be a child directory of {artifact_root}")
    if destination.exists():
        if not args.force:
            raise SystemExit(f"Output already exists (use --force to replace it): {destination}")
        shutil.rmtree(destination)
    destination.mkdir(parents=True)

    rendered = 0
    for source_file in sorted(source.glob("*.cfg")):
        text = source_file.read_text(encoding="utf-8")
        text = text.replace(BEACON_SERIAL_TOKEN, serial)
        (destination / source_file.name).write_text(text, encoding="utf-8", newline="\n")
        rendered += 1
    if not rendered:
        raise SystemExit(f"No .cfg files found in profile: {source}")
    remaining = [path.name for path in destination.glob("*.cfg")
                 if BEACON_SERIAL_TOKEN in path.read_text(encoding="utf-8")]
    if remaining:
        raise SystemExit(f"Unresolved Beacon serial token in: {', '.join(remaining)}")

    metadata = {
        "profile": args.profile,
        "beacon_serial": serial,
        "rendered_at_utc": datetime.now(timezone.utc).isoformat(),
    }
    (destination / "RENDER-METADATA.json").write_text(
        json.dumps(metadata, indent=2) + "\n", encoding="utf-8", newline="\n"
    )
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
    target = f"{args.user}@{args.printer}"
    # This first connection authenticates with the printer password. It uses
    # neither the identity nor multiplexing, so the operator is prompted exactly
    # once here; every later command reuses the installed key.
    install = [ssh, "-p", str(args.port), "-o", "ConnectTimeout=10", target,
               'set -e; install -d -m 700 "$HOME/.ssh"; '
               'touch "$HOME/.ssh/authorized_keys"; chmod 600 "$HOME/.ssh/authorized_keys"; '
               'key="$(cat)"; '
               'grep -qxF "$key" "$HOME/.ssh/authorized_keys" '
               '|| printf "%s\\n" "$key" >> "$HOME/.ssh/authorized_keys"']
    print(f"Installing {public.name} on {target}. Enter the printer password once when prompted.")
    run(install, input_data=(key_line + "\n").encode("utf-8"))

    verify = [ssh, "-p", str(args.port), "-o", "ConnectTimeout=10", "-o", "BatchMode=yes",
              "-i", str(private), "-o", "IdentitiesOnly=yes", target, "true"]
    print("Verifying key-based login...")
    if subprocess.run(verify).returncode:
        raise SystemExit(
            "Key installed, but key-based login did not succeed. Confirm the printer "
            "permits public-key authentication."
        )
    print("Key-based SSH is working; later commands will not prompt for a password.")
    if not is_default_key(private):
        print(f"Pass --identity {private} to the other qidi_plus4.py commands.")


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
    install = (
        f"set -e; cfg={shlex.quote(remote_cfg)}; tmp={shlex.quote(remote_tmp)}; "
        "ts=$(date -u +%Y%m%dT%H%M%SZ); "
        'if [ -s "$cfg" ]; then cp "$cfg" "$cfg.$ts.bak"; '
        'echo "Backed up existing printer.cfg to $cfg.$ts.bak"; fi; '
        'cp "$tmp" "$cfg"; sudo -n systemctl restart klipper'
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
    parser.add_argument("--printer", required=True)
    parser.add_argument("--user", default="mks")
    parser.add_argument("--port", type=int, default=22)
    parser.add_argument("--identity", help="SSH private key for password-free login (see setup-ssh)")
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

    audit_parser = sub.add_parser("audit", help="Run a read-only live printer audit")
    add_connection(audit_parser)
    audit_parser.set_defaults(func=audit)

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

    config = sub.add_parser(
        "render-config", help="Render a per-printer mainline config from a reviewed profile"
    )
    config.add_argument("--profile", default=DEFAULT_CONFIG_PROFILE)
    config.add_argument("--beacon-serial", required=True)
    config.add_argument("--output", type=pathlib.Path, required=True)
    config.add_argument("--force", action="store_true")
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
    args.func(args)


if __name__ == "__main__":
    main()
