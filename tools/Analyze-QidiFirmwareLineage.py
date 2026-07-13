#!/usr/bin/env python3
"""Generate an ordered, sanitized lineage across QIDI firmware snapshots.

Run inside Linux/WSL against extracted filesystem roots. The scanner records
paths, modes, sizes and hashes, but never file contents. User data, credentials,
logs, G-code, Git internals, databases, and Python environments are excluded.
"""

from __future__ import annotations

import argparse
import csv
import difflib
import importlib.util
import json
import re
import subprocess
from collections import Counter
from pathlib import Path
from typing import Any


SCRIPT_DIR = Path(__file__).resolve().parent
PAIRWISE_PATH = SCRIPT_DIR / "Analyze-QidiFirmware.py"
spec = importlib.util.spec_from_file_location("qidi_pairwise", PAIRWISE_PATH)
if spec is None or spec.loader is None:
    raise RuntimeError(f"Could not load {PAIRWISE_PATH}")
pairwise = importlib.util.module_from_spec(spec)
spec.loader.exec_module(pairwise)


AREAS = {
    "installed-klipper": "home/mks/klipper",
    "installed-moonraker": "home/mks/moonraker",
    "printer-config": "home/mks/printer_data/config",
    "systemd-local": "etc/systemd/system",
    "systemd-vendor": "lib/systemd/system",
    "init-scripts": "etc/init.d",
    "system-defaults": "etc/default",
    "network": "etc/network",
    "network-manager": "etc/NetworkManager",
    "boot": "boot",
    "xindi": "root/xindi",
    "qidi-data": "usr/data",
    "klipper-share": "usr/share/klipper",
}

KEY_FILES = (
    "boot/extlinux/extlinux.conf",
    "boot/Image",
    "boot/uInitrd",
    "boot/dtb/rockchip/rk3328-roc-cc.dtb",
    "root/xindi/version",
    "root/xindi/build/xindi",
    "root/800_480.tft",
    "root/800_480.tft.bak",
    "root/uart",
    "root/hid-flash",
    "home/mks/hid-flash",
    "home/mks/klipper/klippy/klippy.py",
    "home/mks/moonraker/moonraker/moonraker.py",
    "home/mks/mcu_box_to_v1_1.1.1.bin",
    "home/mks/mcu_update_BOX_to_v1.sh",
    *(f"home/mks/{name}" for name in pairwise.QIDI_TOOLS),
)


def snapshot_arg(value: str) -> tuple[str, Path]:
    try:
        label, raw_path = value.split("=", 1)
    except ValueError as exc:
        raise argparse.ArgumentTypeError("snapshot must be LABEL=PATH") from exc
    if not label or not raw_path:
        raise argparse.ArgumentTypeError("snapshot must be LABEL=PATH")
    return label, Path(raw_path).resolve()


def field_prefix(label: str) -> str:
    return "v" + re.sub(r"[^a-zA-Z0-9]+", "_", label).strip("_")


def metadata(path: Path) -> dict[str, object] | None:
    if path.is_symlink() or not path.is_file():
        return None
    stat = path.stat()
    return {
        "size": stat.st_size,
        "sha256": pairwise.sha256(path),
        "mode": oct(stat.st_mode & 0o7777),
    }


def transition(old: dict[str, object] | None, new: dict[str, object] | None) -> str:
    if old is None and new is not None:
        return "added"
    if old is not None and new is None:
        return "removed"
    if old is None and new is None:
        return "absent"
    assert old is not None and new is not None
    if old["sha256"] != new["sha256"]:
        return "changed"
    if old["mode"] != new["mode"]:
        return "mode-only"
    return "unchanged"


def read_version(root: Path) -> dict[str, str]:
    path = root / "root/xindi/version"
    if not path.is_file():
        return {}
    result: dict[str, str] = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if "=" in line:
            key, value = line.split("=", 1)
            result[key.strip()] = value.strip()
    return result


def git_revision(root: Path, relative: str) -> dict[str, str] | None:
    repo = root / relative
    if not (repo / ".git").exists():
        return None
    result: dict[str, str] = {}
    for name, command in (
        ("commit", ["rev-parse", "HEAD"]),
        ("describe", ["describe", "--always", "--tags", "--dirty"]),
    ):
        completed = subprocess.run(
            ["git", "-c", f"safe.directory={repo}", "-C", str(repo), *command],
            text=True,
            capture_output=True,
            check=False,
        )
        if completed.returncode == 0:
            result[name] = completed.stdout.strip()
    return result


def git_output(repo: Path, *arguments: str) -> str:
    completed = subprocess.run(
        [
            "git",
            "-c",
            f"safe.directory={repo}",
            "-c",
            "core.fileMode=false",
            "-C",
            str(repo),
            *arguments,
        ],
        text=True,
        errors="replace",
        capture_output=True,
        check=False,
    )
    if completed.returncode:
        raise RuntimeError(f"git {' '.join(arguments)} failed in {repo}: {completed.stderr}")
    return completed.stdout


def write_repo_patches(snapshots: list[tuple[str, Path]], output: Path) -> None:
    directory = output / "patches"
    directory.mkdir(exist_ok=True)
    readable_suffixes = {".c", ".cfg", ".conf", ".h", ".ini", ".md", ".py", ".sh", ".txt"}
    for label, root in snapshots:
        slug = field_prefix(label)
        for repo_name, relative in (
            ("klipper", "home/mks/klipper"),
            ("moonraker", "home/mks/moonraker"),
        ):
            repo = root / relative
            if not (repo / ".git").exists():
                continue
            prefix = directory / f"{slug}-{repo_name}"
            patch = git_output(repo, "diff", "--binary", "HEAD", "--")
            stat = git_output(repo, "diff", "--stat", "HEAD", "--")
            semantic_patch = git_output(repo, "diff", "--ignore-space-at-eol", "HEAD", "--")
            semantic_stat = git_output(
                repo, "diff", "--ignore-space-at-eol", "--stat", "HEAD", "--"
            )
            untracked = [
                line
                for line in git_output(repo, "ls-files", "--others", "--exclude-standard").splitlines()
                if line
            ]
            prefix.with_name(prefix.name + "-vs-recorded-head.patch").write_text(
                patch, encoding="utf-8"
            )
            prefix.with_name(prefix.name + "-vs-recorded-head.stat.txt").write_text(
                stat, encoding="utf-8"
            )
            prefix.with_name(prefix.name + "-vs-recorded-head.semantic.patch").write_text(
                semantic_patch, encoding="utf-8"
            )
            prefix.with_name(
                prefix.name + "-vs-recorded-head.semantic.stat.txt"
            ).write_text(semantic_stat, encoding="utf-8")
            prefix.with_name(prefix.name + "-untracked.txt").write_text(
                "\n".join(untracked) + ("\n" if untracked else ""), encoding="utf-8"
            )
            additions: list[str] = []
            for relative_path in untracked:
                path = repo / relative_path
                if (
                    path.is_symlink()
                    or not path.is_file()
                    or path.suffix.lower() not in readable_suffixes
                    or path.stat().st_size > 1024 * 1024
                    or pairwise.should_skip(Path(relative_path))
                ):
                    continue
                text = path.read_text(encoding="utf-8", errors="replace")
                if "\x00" in text:
                    continue
                additions.extend(
                    difflib.unified_diff(
                        [],
                        text.splitlines(keepends=True),
                        fromfile="/dev/null",
                        tofile=f"b/{relative_path}",
                    )
                )
            prefix.with_name(prefix.name + "-untracked-readable.patch").write_text(
                "".join(additions), encoding="utf-8"
            )


def readable_lines(path: Path | None) -> list[str] | None:
    if path is None:
        return []
    if path.is_symlink() or not path.is_file() or path.stat().st_size > 1024 * 1024:
        return None
    data = path.read_bytes()
    if b"\x00" in data or pairwise.SECRET_RE.search(data.decode("utf-8", errors="replace")):
        return None
    return [line + "\n" for line in data.decode("utf-8", errors="replace").splitlines()]


def write_transition_patches(snapshots: list[tuple[str, Path]], output: Path) -> None:
    directory = output / "transitions"
    directory.mkdir(exist_ok=True)
    areas = (
        "installed-klipper",
        "installed-moonraker",
        "systemd-local",
        "systemd-vendor",
        "init-scripts",
        "xindi",
    )
    for (old_label, old_root), (new_label, new_root) in zip(snapshots, snapshots[1:]):
        transition_name = f"{old_label}-to-{new_label}"
        for area in areas:
            relative_root = AREAS[area]
            old_scan = pairwise.scan_tree(old_root / relative_root)
            new_scan = pairwise.scan_tree(new_root / relative_root)
            patch_lines: list[str] = []
            skipped: list[str] = []
            for relative in sorted(old_scan.keys() | new_scan.keys()):
                old_meta = old_scan.get(relative)
                new_meta = new_scan.get(relative)
                if transition(old_meta, new_meta) not in {"added", "changed", "removed"}:
                    continue
                old_path = old_root / relative_root / relative if old_meta else None
                new_path = new_root / relative_root / relative if new_meta else None
                old_lines = readable_lines(old_path)
                new_lines = readable_lines(new_path)
                if old_lines is None or new_lines is None:
                    skipped.append(relative)
                    continue
                patch_lines.extend(
                    difflib.unified_diff(
                        old_lines,
                        new_lines,
                        fromfile=f"a/{old_label}/{area}/{relative}" if old_meta else "/dev/null",
                        tofile=f"b/{new_label}/{area}/{relative}" if new_meta else "/dev/null",
                    )
                )
            base = directory / f"{transition_name}-{area}"
            base.with_name(base.name + ".patch").write_text(
                "".join(patch_lines), encoding="utf-8"
            )
            base.with_name(base.name + ".skipped.txt").write_text(
                "\n".join(skipped) + ("\n" if skipped else ""), encoding="utf-8"
            )


def write_native_components(snapshots: list[tuple[str, Path]], output: Path) -> None:
    records: dict[str, list[dict[str, object]]] = {}
    for label, root in snapshots:
        components: list[dict[str, object]] = []
        for base in (
            root / "home/mks/klipper/klippy/extras",
            root / "home/mks/moonraker/moonraker/components",
        ):
            if not base.is_dir():
                continue
            for path in sorted(base.rglob("*.so")):
                item = metadata(path)
                if item is not None:
                    components.append(
                        {"path": path.relative_to(root).as_posix(), **item}
                    )
        records[label] = components
    (output / "native-components.json").write_text(
        json.dumps(records, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


def build_lineage(
    snapshots: list[tuple[str, Path]], output: Path
) -> tuple[list[dict[str, object]], dict[str, Any]]:
    scans: dict[str, dict[str, dict[str, dict[str, object]]]] = {}
    for label, root in snapshots:
        scans[label] = {}
        for area, relative in AREAS.items():
            scans[label][area] = pairwise.scan_tree(root / relative)

    rows: list[dict[str, object]] = []
    summary: dict[str, Any] = {}
    labels = [label for label, _ in snapshots]
    for area in AREAS:
        paths: set[str] = set()
        for label in labels:
            paths.update(scans[label][area])
        area_counts: dict[str, Counter[str]] = {
            f"{old}->{new}": Counter() for old, new in zip(labels, labels[1:])
        }
        for relative in sorted(paths):
            states = [scans[label][area].get(relative) for label in labels]
            changes = [transition(old, new) for old, new in zip(states, states[1:])]
            for pair, change in zip(area_counts, changes):
                area_counts[pair][change] += 1
            if all(change == "unchanged" for change in changes):
                continue
            row: dict[str, object] = {"area": area, "path": relative}
            for label, state in zip(labels, states):
                prefix = field_prefix(label)
                row[f"{prefix}_present"] = state is not None
                row[f"{prefix}_size"] = (state or {}).get("size", "")
                row[f"{prefix}_sha256"] = (state or {}).get("sha256", "")
                row[f"{prefix}_mode"] = (state or {}).get("mode", "")
            for old, new, change in zip(labels, labels[1:], changes):
                row[f"transition_{field_prefix(old)}_to_{field_prefix(new)}"] = change
            rows.append(row)
        summary[area] = {
            pair: dict(sorted(counts.items())) for pair, counts in area_counts.items()
        }

    fields = ["area", "path"]
    for label in labels:
        prefix = field_prefix(label)
        fields.extend(
            f"{prefix}_{suffix}" for suffix in ("present", "size", "sha256", "mode")
        )
    for old, new in zip(labels, labels[1:]):
        fields.append(f"transition_{field_prefix(old)}_to_{field_prefix(new)}")
    with (output / "file-lineage.csv").open("w", newline="", encoding="utf-8") as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)
    return rows, summary


def write_key_files(snapshots: list[tuple[str, Path]], output: Path) -> None:
    records: dict[str, dict[str, object | None]] = {}
    for relative in dict.fromkeys(KEY_FILES):
        values = {label: metadata(root / relative) for label, root in snapshots}
        if any(value is not None for value in values.values()):
            records[relative] = values
    (output / "key-files.json").write_text(
        json.dumps(records, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


def write_xindi(snapshots: list[tuple[str, Path]], output: Path) -> None:
    directory = output / "xindi"
    directory.mkdir(exist_ok=True)
    symbols: dict[str, set[str]] = {}
    strings: dict[str, set[str]] = {}
    metadata_records: dict[str, dict[str, object]] = {}
    for label, root in snapshots:
        path = root / "root/xindi/build/xindi"
        if not path.is_file():
            continue
        symbols[label] = set(pairwise.defined_symbols(path))
        strings[label] = pairwise.filtered_strings(path)
        metadata_records[label] = {
            "bytes": path.stat().st_size,
            "sha256": pairwise.sha256(path),
            "symbols": len(symbols[label]),
            "filtered_strings": len(strings[label]),
        }
        pairwise.write_lines(directory / f"symbols-{label}.txt", symbols[label])
    labels = [label for label, _ in snapshots if label in symbols]
    for old, new in zip(labels, labels[1:]):
        pairwise.write_lines(directory / f"symbols-added-{old}-to-{new}.txt", symbols[new] - symbols[old])
        pairwise.write_lines(directory / f"symbols-removed-{old}-to-{new}.txt", symbols[old] - symbols[new])
        pairwise.write_lines(directory / f"strings-added-{old}-to-{new}.txt", strings[new] - strings[old])
        pairwise.write_lines(directory / f"strings-removed-{old}-to-{new}.txt", strings[old] - strings[new])
    (directory / "metadata.json").write_text(
        json.dumps(metadata_records, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--snapshot", action="append", required=True, type=snapshot_arg)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    snapshots: list[tuple[str, Path]] = args.snapshot
    if len(snapshots) < 2:
        raise SystemExit("At least two ordered --snapshot arguments are required")
    labels = [label for label, _ in snapshots]
    if len(set(labels)) != len(labels):
        raise SystemExit("Snapshot labels must be unique")
    for label, root in snapshots:
        if not root.is_dir():
            raise SystemExit(f"Snapshot root does not exist for {label}: {root}")

    output = args.output.resolve()
    output.mkdir(parents=True, exist_ok=True)
    rows, summary = build_lineage(snapshots, output)
    write_key_files(snapshots, output)
    write_xindi(snapshots, output)
    write_repo_patches(snapshots, output)
    write_transition_patches(snapshots, output)
    write_native_components(snapshots, output)
    snapshot_records = {
        label: {
            "version": read_version(root),
            "klipper": git_revision(root, "home/mks/klipper"),
            "moonraker": git_revision(root, "home/mks/moonraker"),
        }
        for label, root in snapshots
    }
    (output / "snapshots.json").write_text(
        json.dumps(snapshot_records, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    (output / "transition-summary.json").write_text(
        json.dumps(summary, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    print(f"Wrote {len(rows)} changed lineage records to {output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
