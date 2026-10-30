#!/usr/bin/env python3
"""Stage selected Plus4 add-on configs without modifying printer.cfg."""

from __future__ import annotations

import argparse
import json
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parent
MANIFEST = json.loads((ROOT / "manifest.json").read_text(encoding="utf-8"))
ADDONS: dict[str, dict[str, object]] = MANIFEST["addons"]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config-dir", type=Path, help="Klipper config directory")
    parser.add_argument(
        "--addon",
        action="append",
        choices=sorted(ADDONS),
        default=[],
        help="add-on to stage; repeat for multiple add-ons",
    )
    parser.add_argument("--force", action="store_true", help="replace staged files")
    parser.add_argument("--list", action="store_true", help="list available add-ons")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    if args.list:
        for name, item in sorted(ADDONS.items()):
            requirements = ", ".join(item["requires"]) or "none"
            print(f"{name}: requires {requirements}")
        return
    if args.config_dir is None or not args.addon:
        raise SystemExit("--config-dir and at least one --addon are required")
    config_dir = args.config_dir.expanduser().resolve()
    if not config_dir.is_dir():
        raise SystemExit(f"Config directory does not exist: {config_dir}")
    destination = config_dir / "plus4-addons"
    destination.mkdir(exist_ok=True)
    for name in dict.fromkeys(args.addon):
        source = ROOT / str(ADDONS[name]["file"])
        target = destination / source.name
        if target.exists() and not args.force:
            raise SystemExit(f"Refusing to replace {target}; use --force after review")
        shutil.copy2(source, target)
        print(f"Staged {name}: {target}")
        print(f"  [include plus4-addons/{target.name}]")


if __name__ == "__main__":
    main()

