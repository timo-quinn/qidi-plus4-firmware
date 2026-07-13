#!/usr/bin/env python3
"""Create a guarded, verified raw image of a factory QIDI Plus4 eMMC.

The tool is deliberately limited to the verified 32 GB QIDI factory layout.
It only opens the source for reading and refuses to overwrite prior evidence.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import pathlib
import re
import shutil
import struct
import subprocess
import sys
import time
from datetime import datetime, timezone


EXPECTED_SIZE = 31_037_849_600
SECTOR_SIZE = 512
PREFIX_SIZE = 16 * 1024 * 1024
CONFIRMATION = "IMAGE-FACTORY-EMMC"
CHUNK_SIZE = 8 * 1024 * 1024
EXPECTED_PARTITIONS = (
    # The 256 MiB BOOT volume is FAT16 LBA (0x0e), despite Windows exposing
    # only the generic XINT13 partition label.
    {"type": 0x0E, "start_lba": 32_768, "sectors": 524_288},
    {"type": 0x83, "start_lba": 557_056, "sectors": 59_441_152},
)


def sha256_file(path: pathlib.Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(CHUNK_SIZE), b""):
            digest.update(chunk)
    return digest.hexdigest()


def parse_mbr(sector: bytes) -> list[dict[str, int]]:
    if len(sector) != SECTOR_SIZE or sector[510:512] != b"\x55\xaa":
        raise SystemExit("Source does not contain a valid MBR signature")
    partitions: list[dict[str, int]] = []
    for index in range(4):
        entry = sector[446 + index * 16 : 462 + index * 16]
        partition_type = entry[4]
        start_lba, sectors = struct.unpack_from("<II", entry, 8)
        if partition_type or start_lba or sectors:
            partitions.append(
                {
                    "index": index + 1,
                    "type": partition_type,
                    "start_lba": start_lba,
                    "sectors": sectors,
                }
            )
    return partitions


def validate_layout(partitions: list[dict[str, int]]) -> None:
    if len(partitions) != len(EXPECTED_PARTITIONS):
        raise SystemExit(f"Expected two MBR partitions, found {len(partitions)}")
    for actual, expected in zip(partitions, EXPECTED_PARTITIONS, strict=True):
        for key, value in expected.items():
            if actual[key] != value:
                raise SystemExit(
                    f"Partition {actual['index']} {key} is "
                    f"{actual[key]:#04x}, expected {value:#04x}"
                    if key == "type"
                    else f"Partition {actual['index']} {key} is {actual[key]}, expected {value}"
                )


def windows_disk_info(device: str) -> dict[str, object]:
    match = re.fullmatch(r"\\\\\.\\PhysicalDrive(\d+)", device, re.IGNORECASE)
    if not match:
        raise SystemExit("On Windows, --device must look like \\\\.\\PhysicalDrive1")
    number = int(match.group(1))
    command = [
        "powershell.exe",
        "-NoProfile",
        "-NonInteractive",
        "-Command",
        (
            f"$d=Get-Disk -Number {number} -ErrorAction Stop; "
            "$d | Select-Object Number,FriendlyName,BusType,PartitionStyle,Size,"
            "IsReadOnly,IsOffline | ConvertTo-Json -Compress"
        ),
    ]
    try:
        info = json.loads(subprocess.check_output(command, text=True))
    except (subprocess.CalledProcessError, json.JSONDecodeError) as exc:
        raise SystemExit(f"Could not inspect Windows disk {number}: {exc}") from exc
    if info.get("BusType") != "USB":
        raise SystemExit(f"Refusing non-USB Windows disk: {info.get('BusType')!r}")
    if info.get("PartitionStyle") != "MBR":
        raise SystemExit(f"Expected MBR partitioning, found {info.get('PartitionStyle')!r}")
    if info.get("Size") != EXPECTED_SIZE:
        raise SystemExit(f"Disk size is {info.get('Size')}, expected {EXPECTED_SIZE}")
    if info.get("IsReadOnly") is not True:
        raise SystemExit("Windows disk is not marked read-only; run Set-Disk first")
    return info


def posix_device_info(device: str) -> dict[str, object]:
    path = pathlib.Path(device)
    if not path.exists():
        raise SystemExit(f"Source device does not exist: {device}")
    if shutil.which("blockdev"):
        size = int(subprocess.check_output(["blockdev", "--getsize64", device], text=True))
        readonly = subprocess.check_output(["blockdev", "--getro", device], text=True).strip()
        if readonly != "1":
            raise SystemExit("Source block device is not read-only")
    else:
        with path.open("rb", buffering=0) as source:
            size = source.seek(0, os.SEEK_END)
    if size != EXPECTED_SIZE:
        raise SystemExit(f"Device size is {size}, expected {EXPECTED_SIZE}")
    return {"device": device, "size": size, "read_only": True}


def inspect_source(device: str) -> dict[str, object]:
    return windows_disk_info(device) if os.name == "nt" else posix_device_info(device)


def image_device(device: str, output_dir: pathlib.Path, source_info: dict[str, object]) -> None:
    output_dir = output_dir.resolve()
    image = output_dir / "factory-emmc-user-area.img"
    image_partial = image.with_suffix(image.suffix + ".partial")
    prefix = output_dir / "emmc-prefix-16MiB.bin"
    prefix_partial = prefix.with_suffix(prefix.suffix + ".partial")
    manifest = output_dir / "manifest.json"

    existing = [path for path in (image, image_partial, prefix, prefix_partial, manifest) if path.exists()]
    if existing:
        raise SystemExit("Refusing to overwrite existing evidence: " + ", ".join(map(str, existing)))
    output_dir.mkdir(parents=True, exist_ok=True)
    required_free = EXPECTED_SIZE + PREFIX_SIZE + 1024 * 1024 * 1024
    free = shutil.disk_usage(output_dir).free
    if free < required_free:
        raise SystemExit(
            f"Need at least {required_free / 2**30:.1f} GiB free; "
            f"only {free / 2**30:.1f} GiB is available"
        )

    digest = hashlib.sha256()
    copied = 0
    next_progress = 1024 * 1024 * 1024
    started = time.monotonic()
    partitions: list[dict[str, int]] | None = None
    try:
        with open(device, "rb", buffering=0) as source, image_partial.open("xb") as target, \
                prefix_partial.open("xb") as prefix_target:
            while copied < EXPECTED_SIZE:
                chunk = source.read(min(CHUNK_SIZE, EXPECTED_SIZE - copied))
                if not chunk:
                    raise OSError(f"Unexpected end of source after {copied} bytes")
                if copied == 0:
                    partitions = parse_mbr(chunk[:SECTOR_SIZE])
                    validate_layout(partitions)
                target.write(chunk)
                if copied < PREFIX_SIZE:
                    prefix_target.write(chunk[: min(len(chunk), PREFIX_SIZE - copied)])
                digest.update(chunk)
                copied += len(chunk)
                if copied >= next_progress or copied == EXPECTED_SIZE:
                    elapsed = max(time.monotonic() - started, 0.001)
                    print(
                        f"copied={copied / 2**30:.1f}GiB "
                        f"progress={copied / EXPECTED_SIZE:.1%} "
                        f"rate={copied / elapsed / 2**20:.1f}MiB/s",
                        flush=True,
                    )
                    next_progress += 1024 * 1024 * 1024
            target.flush()
            prefix_target.flush()
            os.fsync(target.fileno())
            os.fsync(prefix_target.fileno())
        if image_partial.stat().st_size != EXPECTED_SIZE:
            raise OSError("Image size validation failed")
        if prefix_partial.stat().st_size != PREFIX_SIZE:
            raise OSError("Prefix size validation failed")
        image_partial.replace(image)
        prefix_partial.replace(prefix)
    except BaseException:
        image_partial.unlink(missing_ok=True)
        prefix_partial.unlink(missing_ok=True)
        raise

    source_hash = digest.hexdigest()
    print("Verifying the completed image...", flush=True)
    image_hash = sha256_file(image)
    if image_hash != source_hash:
        raise SystemExit(f"Image verification failed: source={source_hash} image={image_hash}")

    record = {
        "created_utc": datetime.now(timezone.utc).isoformat(),
        "source": source_info,
        "layout": {
            "sector_size": SECTOR_SIZE,
            "size": EXPECTED_SIZE,
            "partitions": partitions,
        },
        "artifacts": {
            image.name: {"size": image.stat().st_size, "sha256": image_hash},
            prefix.name: {"size": prefix.stat().st_size, "sha256": sha256_file(prefix)},
        },
    }
    manifest.write_text(json.dumps(record, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(f"Factory image verified: {image}")
    print(f"SHA-256: {image_hash}")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--device", required=True, help=r"Raw device, e.g. \\.\PhysicalDrive1")
    parser.add_argument("--output", required=True, type=pathlib.Path)
    parser.add_argument("--confirm", required=True)
    return parser


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    if args.confirm != CONFIRMATION:
        raise SystemExit(f"Confirmation must be exactly {CONFIRMATION}")
    source_info = inspect_source(args.device)
    print(json.dumps(source_info, indent=2))
    image_device(args.device, args.output, source_info)
    return 0


if __name__ == "__main__":
    sys.exit(main())
