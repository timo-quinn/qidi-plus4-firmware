#!/usr/bin/env python3
"""Cross-platform QIDI Plus4 mainline migration utility."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import pathlib
import shlex
import shutil
import struct
import subprocess
import tarfile
import urllib.request
from datetime import datetime, timezone


SCRIPT_DIR = pathlib.Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parent.parent
REMOTE_HELPER = SCRIPT_DIR / "qidi-plus4-remote.sh"
BOOTSTRAP_HELPER = SCRIPT_DIR / "bootstrap-mainline.sh"
BACKUP_HELPER = SCRIPT_DIR / "backup-remote.sh"
DEFAULT_ARTIFACTS = REPO_ROOT / "artifacts"

LAYOUTS = {
    "mainboard": (0x08008000, 0x08040000, 0x20000000, 0x20020000),
    "toolhead-katapult": (0x08000000, 0x08002000, 0x20000000, 0x20010000),
    "toolhead-app": (0x08002000, 0x08010000, 0x20000000, 0x20010000),
}


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

    metadata = [
        f"built_at_utc={datetime.now(timezone.utc).isoformat()}",
        f"klipper_commit={git_commit(klipper)}",
        f"katapult_commit={git_commit(katapult)}",
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
    download_file(base, target)
    download_file(base + ".sha", sha_target)
    expected = sha_target.read_text(encoding="utf-8").split()[0].lower()
    actual = sha256(target)
    if actual != expected:
        target.unlink(missing_ok=True)
        raise SystemExit(f"Armbian image SHA-256 mismatch: expected {expected}, got {actual}")
    print(f"Verified SHA-256 {actual}")


def ssh_base(args: argparse.Namespace) -> tuple[list[str], str]:
    ssh = require_command("ssh")
    target = f"{args.user}@{args.printer}"
    return ([ssh, "-p", str(args.port), "-o", "ConnectTimeout=10",
             "-o", "ServerAliveInterval=15", "-o", "ServerAliveCountMax=2", target], target)


def audit(args: argparse.Namespace) -> None:
    ssh, _ = ssh_base(args)
    run(ssh + ["bash -s -- audit"], input_data=REMOTE_HELPER.read_bytes())


def backup_printer(args: argparse.Namespace) -> None:
    ssh, target = ssh_base(args)
    scp = require_command("scp")
    safe_name = "".join(c if c.isalnum() or c in "._-" else "-" for c in (args.name or args.printer)).strip("-")
    timestamp = datetime.now().strftime("%Y%m%d-%H%M%S")
    base = f"qidi-plus4-{safe_name or 'printer'}-{timestamp}"
    destination = args.output.resolve() / safe_name
    destination.mkdir(parents=True, exist_ok=True)
    archive = destination / f"{base}.tar.gz"
    manifest = destination / f"{base}-manifest.txt"
    remote_helper = f"/tmp/{base}-backup.sh"
    remote_manifest = f"/tmp/{base}-manifest.txt"
    scp_base = [scp, "-P", str(args.port), "-o", "ConnectTimeout=10"]
    run(scp_base + [str(BACKUP_HELPER), f"{target}:{remote_helper}"])
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
        run(scp_base + [f"{target}:{remote_manifest}", str(manifest)])
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
    scp = require_command("scp")
    remote = f"/home/{args.user}/bootstrap-mainline.sh"
    run([scp, "-P", str(args.port), "-o", "ConnectTimeout=10",
         str(BOOTSTRAP_HELPER), f"{target}:{remote}"])
    environment = " ".join((
        f"KLIPPER_REF={shlex.quote(args.klipper_ref)}",
        f"MOONRAKER_REF={shlex.quote(args.moonraker_ref)}",
        f"KATAPULT_REF={shlex.quote(args.katapult_ref)}",
    ))
    run(ssh + [f"chmod 700 {shlex.quote(remote)} && {environment} {shlex.quote(remote)}"])


def stage(args: argparse.Namespace, kind: str) -> tuple[list[str], str, str]:
    ssh, target = ssh_base(args)
    scp = require_command("scp")
    image = args.image.resolve()
    validate_image(kind, image)
    remote_image = f"{args.remote_directory}/{kind}.bin"
    remote_helper = f"{args.remote_directory}/qidi-plus4-remote.sh"
    remote_dir = shlex.quote(args.remote_directory)
    run(ssh + [f"mkdir -p {remote_dir}"])
    scp_options = [scp, "-P", str(args.port), "-o", "ConnectTimeout=10"]
    run(scp_options + [str(REMOTE_HELPER), f"{target}:{remote_helper}"])
    run(scp_options + [str(image), f"{target}:{remote_image}"])
    run(ssh + [f"chmod 700 {shlex.quote(remote_helper)}"])
    return ssh, remote_helper, remote_image


def remote_action(args: argparse.Namespace) -> None:
    actions = {
        "validate-mainboard": ("mainboard", "validate", None),
        "validate-toolhead-katapult": ("toolhead-katapult", "validate", None),
        "validate-toolhead": ("toolhead-app", "validate", None),
        "flash-mainboard": ("mainboard", "flash-mainboard", "FLASH-MAINBOARD"),
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
    run(ssh + [" ".join(parts)])


def add_connection(parser: argparse.ArgumentParser, *, image: bool = False) -> None:
    parser.add_argument("--printer", required=True)
    parser.add_argument("--user", default="mks")
    parser.add_argument("--port", type=int, default=22)
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
