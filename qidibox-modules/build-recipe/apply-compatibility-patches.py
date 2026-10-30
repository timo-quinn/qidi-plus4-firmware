#!/usr/bin/env python3
"""Apply the small compatibility delta used by the rebuilt Box modules."""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

UPSTREAM_SHA256 = "ae99d1504d71b6afe017459873c46f2c25158fe7cc913105399721ab8bd3e21e"
PATCHED_SHA256 = "f0c672807ab90c3d16909f9f238704604c8535372d3958bc229a6539da3f87be"

REPLACEMENTS = (
    (
        ("        self.exclude_tool = False\n"
        "        self.last_position = [0., 0., 0., 0.]\n"),
        ("        self.exclude_tool = False\n"
        "        self.is_tool_change = False\n"
        "        self.last_position = [0., 0., 0., 0.]\n"),
    ),
    (
        '        box_extras.save_variable("is_tool_change", 1)\n',
        ('        box_extras.save_variable("is_tool_change", 1)\n'
        "        self.is_tool_change = True\n"),
    ),
    (
        '        box_extras.save_variable("is_tool_change", 0)\n',
        ('        box_extras.save_variable("is_tool_change", 0)\n'
        "        self.is_tool_change = False\n"),
    ),
)


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def patch(source_dir: Path) -> None:
    source = source_dir / "box_extras.py"
    data = source.read_bytes().replace(b"\r\n", b"\n")
    current_hash = digest(data)

    if current_hash == PATCHED_SHA256:
        source.write_bytes(data)
        return
    if current_hash != UPSTREAM_SHA256:
        raise SystemExit(
            f"refusing to patch unexpected box_extras.py ({current_hash})"
        )

    text = data.decode("utf-8")
    for old, new in REPLACEMENTS:
        if text.count(old) != 1:
            raise SystemExit(f"compatibility patch context occurred {text.count(old)} times")
        text = text.replace(old, new)

    patched = text.encode("utf-8")
    patched_hash = digest(patched)
    if patched_hash != PATCHED_SHA256:
        raise SystemExit(f"patched source hash mismatch ({patched_hash})")
    source.write_bytes(patched)
    print(f"patched box_extras.py ({patched_hash})")


if __name__ == "__main__":
    patch(Path(sys.argv[1] if len(sys.argv) > 1 else "/work/src"))
