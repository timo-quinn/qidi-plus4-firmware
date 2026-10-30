#!/usr/bin/env python3
"""Build a static comparison from two extracted QIDI Plus4 backups.

Run this inside Linux/WSL so symlinks and permissions from the printer archive
are preserved. It intentionally excludes user data, logs, Git internals,
bytecode caches, and likely credential material.
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import re
import subprocess
from collections import Counter
from pathlib import Path

SKIP_PARTS = {
    ".git", "__pycache__", ".cache", "logs", "gcodes", "timelapse",
    "history", "certs", "ssh", ".ssh", ".gnupg",
}
SKIP_SUFFIXES = {".pyc", ".pyo", ".log", ".sqlite", ".db", ".journal"}
TEXT_LIMIT = 8 * 1024 * 1024

AREAS = {
    "installed-klipper": ("home/mks/klipper", "home/mks/klipper"),
    "installed-moonraker": ("home/mks/moonraker", "home/mks/moonraker"),
    "systemd-local": ("etc/systemd/system", "etc/systemd/system"),
    "systemd-vendor": ("lib/systemd/system", "lib/systemd/system"),
    "init-scripts": ("etc/init.d", "etc/init.d"),
    "system-defaults": ("etc/default", "etc/default"),
    "network": ("etc/network", "etc/network"),
    "network-manager": ("etc/NetworkManager", "etc/NetworkManager"),
    "boot": ("boot", "boot"),
    "xindi": ("root/xindi", "root/xindi"),
    "release-payload": (
        "home/mks/qidi-1.7.3-root/root",
        "home/mks/update182/root",
    ),
}

QIDI_TOOLS = (
    "gene4.py", "hid-flash", "json_reader", "libColPic.so",
    "mcu_box_to_v1_1.1.1.bin", "mcu_update_BOX_to_v1.sh", "serial_com",
    "serial_com_dict", "tjc", "zlib_decompress",
)

XINDI_TERMS = {
    "account", "alias", "avatar", "bind", "box", "cloud", "config",
    "database", "download", "dry", "filament", "firmware", "frp",
    "history", "https", "login", "metadata", "mqtt", "multi_color",
    "network", "password", "print", "qidi", "qrcode", "region", "rfid",
    "server", "slot", "sqlite", "ssl", "status", "time", "token",
    "update", "upload", "user", "wifi",
}

SECRET_RE = re.compile(
    r"(BEGIN (?:RSA|OPENSSH|PRIVATE)|Bearer\s+|eyJ[A-Za-z0-9_-]{12,}\."
    r"|(?:api|access|secret)[_-]?key\s*[:=])",
    re.IGNORECASE,
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest().upper()


def should_skip(relative: Path) -> bool:
    return (
        any(part in SKIP_PARTS for part in relative.parts)
        or relative.suffix.lower() in SKIP_SUFFIXES
    )


def scan_tree(root: Path) -> dict[str, dict[str, object]]:
    result: dict[str, dict[str, object]] = {}
    if not root.exists():
        return result
    for path in root.rglob("*"):
        if path.is_symlink() or not path.is_file():
            continue
        relative = path.relative_to(root)
        if should_skip(relative):
            continue
        try:
            stat = path.stat()
            result[relative.as_posix()] = {
                "size": stat.st_size,
                "sha256": sha256(path),
                "mode": oct(stat.st_mode & 0o7777),
            }
        except OSError:
            continue
    return result


def compare_area(
    area: str,
    old_root: Path,
    new_root: Path,
    old_relative: str,
    new_relative: str,
) -> list[dict[str, object]]:
    old = scan_tree(old_root / old_relative)
    new = scan_tree(new_root / new_relative)
    rows: list[dict[str, object]] = []
    for path in sorted(old.keys() | new.keys()):
        if path not in old:
            change = "added"
        elif path not in new:
            change = "removed"
        elif old[path]["sha256"] != new[path]["sha256"]:
            change = "changed"
        elif old[path]["mode"] != new[path]["mode"]:
            change = "mode-only"
        else:
            continue
        rows.append({
            "area": area,
            "change": change,
            "path": path,
            "old_size": old.get(path, {}).get("size", ""),
            "new_size": new.get(path, {}).get("size", ""),
            "old_sha256": old.get(path, {}).get("sha256", ""),
            "new_sha256": new.get(path, {}).get("sha256", ""),
            "old_mode": old.get(path, {}).get("mode", ""),
            "new_mode": new.get(path, {}).get("mode", ""),
        })
    return rows


def compare_named_files(old_root: Path, new_root: Path) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for name in QIDI_TOOLS:
        old_path = old_root / "home/mks" / name
        new_path = new_root / "home/mks" / name
        old = ({"size": old_path.stat().st_size, "sha256": sha256(old_path),
                "mode": oct(old_path.stat().st_mode & 0o7777)}
               if old_path.is_file() else None)
        new = ({"size": new_path.stat().st_size, "sha256": sha256(new_path),
                "mode": oct(new_path.stat().st_mode & 0o7777)}
               if new_path.is_file() else None)
        if old is None and new is not None:
            change = "added"
        elif old is not None and new is None:
            change = "removed"
        elif old is not None and new is not None and old["sha256"] != new["sha256"]:
            change = "changed"
        elif old is not None and new is not None and old["mode"] != new["mode"]:
            change = "mode-only"
        else:
            continue
        rows.append({
            "area": "qidi-tools", "change": change, "path": name,
            "old_size": (old or {}).get("size", ""),
            "new_size": (new or {}).get("size", ""),
            "old_sha256": (old or {}).get("sha256", ""),
            "new_sha256": (new or {}).get("sha256", ""),
            "old_mode": (old or {}).get("mode", ""),
            "new_mode": (new or {}).get("mode", ""),
        })
    return rows


def run_lines(*args: str) -> list[str]:
    completed = subprocess.run(
        args, check=True, text=True, errors="replace", stdout=subprocess.PIPE
    )
    return completed.stdout.splitlines()


def defined_symbols(path: Path) -> list[str]:
    lines = run_lines("nm", "-anC", str(path))
    symbols: set[str] = set()
    for line in lines:
        match = re.match(r"^[0-9a-fA-F]+\s+([TtWw])\s+(.+)$", line)
        if not match:
            continue
        name = match.group(2).strip()
        if name == "$x" or any(
            marker in name for marker in (
                "std::", "boost::", "fmt::", "websocketpp::", "nlohmann::",
                "__gnu_cxx::", "qrcodegen::",
            )
        ):
            continue
        symbols.add(name)
    return sorted(symbols, key=str.casefold)


def filtered_strings(path: Path) -> set[str]:
    values: set[str] = set()
    for value in run_lines("strings", "-a", str(path)):
        value = value.strip()
        lowered = value.lower()
        if not 4 <= len(value) <= 240:
            continue
        if SECRET_RE.search(value):
            continue
        if any(term in lowered for term in XINDI_TERMS):
            values.add(value)
    return values


def write_lines(path: Path, lines: list[str] | set[str]) -> None:
    path.write_text("\n".join(sorted(lines, key=str.casefold)) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--old", required=True, type=Path, help="Extracted 1.7.3 archive root")
    parser.add_argument("--new", required=True, type=Path, help="Extracted 1.8.2 archive root")
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()

    output: Path = args.output
    output.mkdir(parents=True, exist_ok=True)

    rows: list[dict[str, object]] = []
    for area, (old_relative, new_relative) in AREAS.items():
        rows.extend(compare_area(area, args.old, args.new, old_relative, new_relative))
    rows.extend(compare_named_files(args.old, args.new))

    fields = [
        "area", "change", "path", "old_size", "new_size", "old_sha256",
        "new_sha256", "old_mode", "new_mode",
    ]
    with (output / "file-changes.csv").open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)

    summary: dict[str, dict[str, int]] = {}
    for area in [*AREAS, "qidi-tools"]:
        counts = Counter(str(row["change"]) for row in rows if row["area"] == area)
        summary[area] = dict(sorted(counts.items()))
    (output / "file-change-summary.json").write_text(
        json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )

    old_xindi = args.old / "root/xindi/build/xindi"
    new_xindi = args.new / "root/xindi/build/xindi"
    if old_xindi.exists() and new_xindi.exists():
        old_symbols = set(defined_symbols(old_xindi))
        new_symbols = set(defined_symbols(new_xindi))
        write_lines(output / "xindi-symbols-1.7.3.txt", old_symbols)
        write_lines(output / "xindi-symbols-1.8.2.txt", new_symbols)
        write_lines(output / "xindi-symbols-added.txt", new_symbols - old_symbols)
        write_lines(output / "xindi-symbols-removed.txt", old_symbols - new_symbols)

        old_strings = filtered_strings(old_xindi)
        new_strings = filtered_strings(new_xindi)
        write_lines(output / "xindi-filtered-strings-added.txt", new_strings - old_strings)
        write_lines(output / "xindi-filtered-strings-removed.txt", old_strings - new_strings)

        metadata = {
            "1.7.3": {"bytes": old_xindi.stat().st_size, "sha256": sha256(old_xindi)},
            "1.8.2": {"bytes": new_xindi.stat().st_size, "sha256": sha256(new_xindi)},
        }
        (output / "xindi-metadata.json").write_text(
            json.dumps(metadata, indent=2) + "\n", encoding="utf-8"
        )

    print(f"Wrote {len(rows)} file-change records to {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
