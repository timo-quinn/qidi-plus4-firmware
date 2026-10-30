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
import hashlib
import importlib.util
import itertools
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


def run_git(repo: Path, *arguments: str) -> subprocess.CompletedProcess[bytes]:
    return subprocess.run(
        ["git", "-c", f"safe.directory={repo}", "-c", "core.fileMode=false",
         "-C", str(repo), *arguments],
        capture_output=True,
        check=False,
    )


def git_output_bytes(repo: Path, *arguments: str) -> bytes:
    completed = run_git(repo, *arguments)
    if completed.returncode:
        error = completed.stderr.decode("utf-8", errors="replace")
        raise RuntimeError(f"git {' '.join(arguments)} failed in {repo}: {error}")
    return completed.stdout


def git_output(repo: Path, *arguments: str) -> str:
    return git_output_bytes(repo, *arguments).decode("utf-8", errors="replace")


def head_blob(repo: Path, relative: str) -> bytes | None:
    completed = run_git(repo, "show", f"HEAD:{relative}")
    return completed.stdout if completed.returncode == 0 else None


def bytes_summary(data: bytes | None) -> str:
    if data is None:
        return "absent"
    return f"{len(data)}:{hashlib.sha256(data).hexdigest()}"


def skipped_record(relative: str, reason: str, old: bytes | None, new: bytes | None) -> str:
    return (
        f"{relative}\t{reason}\thead={bytes_summary(old)}\t"
        f"worktree={bytes_summary(new)}"
    )


def readable_repo_patch_paths(repo: Path) -> tuple[list[str], list[str]]:
    """Select tracked changes that are safe to publish as a UTF-8 text patch."""
    names = git_output_bytes(
        repo, "diff", "--no-renames", "--name-only", "-z", "HEAD", "--"
    ).split(b"\0")
    readable: list[str] = []
    skipped: list[str] = []
    for raw_name in filter(None, names):
        try:
            relative = raw_name.decode("utf-8")
        except UnicodeDecodeError:
            skipped.append(
                f"<hex:{raw_name.hex()}>\tpath-not-utf8\thead=unknown\tworktree=unknown"
            )
            continue
        current = repo / relative
        old = head_blob(repo, relative)
        if current.is_symlink():
            skipped.append(skipped_record(relative, "worktree-symlink", old, None))
            continue
        if current.exists() and not current.is_file():
            skipped.append(skipped_record(relative, "worktree-not-file", old, None))
            continue
        new = current.read_bytes() if current.is_file() else None
        reason = ""
        for label, data in (("head", old), ("worktree", new)):
            if data is None:
                continue
            if b"\x00" in data:
                reason = f"{label}-contains-nul"
                break
            try:
                data.decode("utf-8")
            except UnicodeDecodeError:
                reason = f"{label}-not-utf8"
                break
        if reason:
            skipped.append(skipped_record(relative, reason, old, new))
        else:
            readable.append(relative)
    return readable, skipped


def repo_patch_text(repo: Path, paths: list[str], *options: str) -> str:
    if not paths:
        return ""
    data = git_output_bytes(repo, "diff", "--no-renames", *options, "HEAD", "--", *paths)
    if b"\x00" in data:
        raise RuntimeError(f"git produced a NUL-bearing published patch in {repo}")
    try:
        return data.decode("utf-8")
    except UnicodeDecodeError as exc:
        raise RuntimeError(f"git produced a non-UTF-8 published patch in {repo}") from exc


def write_skipped_manifest(path: Path, records: list[str]) -> None:
    header = "path\treason\thead=size:sha256\tworktree=size:sha256\n"
    path.write_text(header + "\n".join(records) + ("\n" if records else ""), encoding="utf-8")


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
            readable_paths, skipped = readable_repo_patch_paths(repo)
            patch = repo_patch_text(repo, readable_paths, "--binary")
            stat = git_output(repo, "diff", "--stat", "HEAD", "--")
            semantic_patch = repo_patch_text(
                repo, readable_paths, "--ignore-space-at-eol"
            )
            semantic_stat = (
                git_output(repo, "diff", "--no-renames", "--ignore-space-at-eol",
                           "--stat", "HEAD", "--", *readable_paths)
                if readable_paths else ""
            )
            untracked: list[str] = []
            untracked_skipped: list[str] = []
            raw_untracked = git_output_bytes(
                repo, "ls-files", "--others", "--exclude-standard", "-z"
            ).split(b"\0")
            for raw_name in filter(None, raw_untracked):
                try:
                    untracked.append(raw_name.decode("utf-8"))
                except UnicodeDecodeError:
                    untracked_skipped.append(
                        f"<hex:{raw_name.hex()}>\tpath-not-utf8\t"
                        "head=absent\tworktree=unknown"
                    )
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
            write_skipped_manifest(
                prefix.with_name(prefix.name + "-vs-recorded-head.skipped.txt"), skipped
            )
            prefix.with_name(prefix.name + "-untracked.txt").write_text(
                "\n".join(untracked) + ("\n" if untracked else ""), encoding="utf-8"
            )
            additions: list[str] = []
            for relative_path in untracked:
                path = repo / relative_path
                if path.is_symlink() or not path.is_file():
                    untracked_skipped.append(
                        skipped_record(relative_path, "not-regular-file", None, None)
                    )
                    continue
                data = path.read_bytes()
                if path.suffix.lower() not in readable_suffixes:
                    untracked_skipped.append(
                        skipped_record(relative_path, "unsupported-suffix", None, data)
                    )
                    continue
                if len(data) > 1024 * 1024:
                    untracked_skipped.append(
                        skipped_record(relative_path, "larger-than-1MiB", None, data)
                    )
                    continue
                if pairwise.should_skip(Path(relative_path)):
                    untracked_skipped.append(
                        skipped_record(relative_path, "publication-policy", None, data)
                    )
                    continue
                if b"\x00" in data:
                    untracked_skipped.append(
                        skipped_record(relative_path, "worktree-contains-nul", None, data)
                    )
                    continue
                try:
                    text = data.decode("utf-8")
                except UnicodeDecodeError:
                    untracked_skipped.append(
                        skipped_record(relative_path, "worktree-not-utf8", None, data)
                    )
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
            write_skipped_manifest(
                prefix.with_name(prefix.name + "-untracked-readable.skipped.txt"),
                untracked_skipped,
            )


def readable_lines(path: Path | None) -> list[str] | None:
    if path is None:
        return []
    if path.is_symlink() or not path.is_file() or path.stat().st_size > 1024 * 1024:
        return None
    data = path.read_bytes()
    if b"\x00" in data:
        return None
    try:
        text = data.decode("utf-8")
    except UnicodeDecodeError:
        return None
    if pairwise.SECRET_RE.search(text):
        return None
    return [line + "\n" for line in text.splitlines()]


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
    for (old_label, old_root), (new_label, new_root) in itertools.pairwise(snapshots):
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
            f"{old}->{new}": Counter() for old, new in itertools.pairwise(labels)
        }
        for relative in sorted(paths):
            states = [scans[label][area].get(relative) for label in labels]
            changes = [transition(old, new) for old, new in itertools.pairwise(states)]
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
    for old, new in itertools.pairwise(labels):
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
    for old, new in itertools.pairwise(labels):
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
