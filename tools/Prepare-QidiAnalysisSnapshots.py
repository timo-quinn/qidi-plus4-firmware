#!/usr/bin/env python3
"""Verify and extract the compact local QIDI firmware analysis snapshots."""

from __future__ import annotations

import argparse
import hashlib
import json
import posixpath
import tarfile
from pathlib import Path, PurePosixPath

REPO_ROOT = Path(__file__).resolve().parents[1]
DEFAULT_RETAINED = REPO_ROOT / "data/printer-backups/retained"
ARCHIVES = {
    "1.1.2": "analysis-1.1.2.tar.gz",
    "1.7.3": "analysis-1.7.3.tar.gz",
    "1.8.2": "analysis-1.8.2.tar.gz",
}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def safe_members(archive: tarfile.TarFile, label: str):
    prefix = label + "/"
    for member in archive:
        path = PurePosixPath(member.name)
        if path.is_absolute() or ".." in path.parts:
            raise RuntimeError(f"Unsafe archive path: {member.name}")
        if member.name != label and not member.name.startswith(prefix):
            raise RuntimeError(f"Unexpected snapshot path: {member.name}")
        if member.issym() or member.islnk():
            link = PurePosixPath(member.linkname)
            if link.is_absolute():
                continue
            if member.issym():
                resolved = posixpath.normpath(
                    posixpath.join(posixpath.dirname(member.name), member.linkname)
                )
            else:
                resolved = posixpath.normpath(member.linkname)
            if resolved != label and not resolved.startswith(prefix):
                continue
        yield member


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--retained", type=Path, default=DEFAULT_RETAINED)
    parser.add_argument("--output", type=Path)
    parser.add_argument("--verify-only", action="store_true")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    retained = args.retained.resolve()
    records = json.loads(
        (retained / "retained-files.json").read_text(encoding="utf-8-sig")
    )
    expected = {item["path"]: item for item in records}
    for label, filename in ARCHIVES.items():
        path = retained / filename
        record = expected.get(filename)
        if record is None:
            raise SystemExit(f"Missing manifest record: {filename}")
        if path.stat().st_size != record["size"] or sha256(path) != record["sha256"]:
            raise SystemExit(f"Integrity check failed: {path}")
        print(f"Verified {label}: {path}")
    if args.verify_only:
        return
    if args.output is None:
        raise SystemExit("--output is required unless --verify-only is used")
    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    for label, filename in ARCHIVES.items():
        target = output / label
        if target.exists():
            raise SystemExit(f"Refusing existing snapshot: {target}")
        with tarfile.open(retained / filename, "r:gz") as archive:
            archive.extractall(output, members=safe_members(archive, label))
        print(f"Extracted {label}: {target}")


if __name__ == "__main__":
    main()
