#!/usr/bin/env python3
"""Strictly and idempotently patch QIDI's virtual_sdcard PLR extension.

The patch is deliberately structural and fail-closed: every vendor anchor must
occur exactly once, and both the input and output must parse as Python before a
caller is allowed to install the result.  CPython 3.7 compatibility is kept so
the tool can also run directly on a stock Plus4 host.
"""

from __future__ import annotations

import argparse
import ast
import json
import os
import sys

PATCH_MARKER = "# PLR_HARDENING_V1"
DEFAULT_CHECKPOINT_PATH = "/home/mks/scripts/plr/plr_checkpoint.json"
DEFAULT_RECORD_PATH = "/home/mks/scripts/plr/plr_record"


class PatchError(Exception):
    """Raised when the input is not the exact supported QIDI source shape."""


def _replace_once(source, old, new, label):
    count = source.count(old)
    if count != 1:
        raise PatchError(f"{label} anchor occurred {count:d} times (expected exactly 1)")
    return source.replace(old, new, 1)


def _path_literal(value, label):
    if not isinstance(value, str) or not os.path.isabs(value):
        raise PatchError(f"{label} must be an absolute path")
    if "\x00" in value or "\n" in value or "\r" in value:
        raise PatchError(f"{label} contains an unsafe character")
    return json.dumps(value)


def validate_patched(source, checkpoint_path, record_path):
    try:
        ast.parse(source, filename="virtual_sdcard.py")
    except SyntaxError as exc:
        raise PatchError(f"patched source is not valid Python: {exc}")
    required = (
        f"from . import plr_checkpoint  {PATCH_MARKER}",
        "self.plr_tracker = plr_checkpoint.CheckpointTracker(",
        "self.plr_tracker.start(",
        "self.plr_tracker.advance(self.lines)",
        "self.plr_tracker.complete(self.lines)",
        "self.plr_tracker.cancel(self.lines)",
        "self.plr_tracker.invalidate(",
        "checkpoint_path={}".format(_path_literal(checkpoint_path, "checkpoint path")),
        "record_path={}".format(_path_literal(record_path, "record path")),
    )
    for fragment in required:
        if fragment not in source:
            raise PatchError(f"patched source is missing required fragment: {fragment}")
    if source.count(PATCH_MARKER) != 1:
        raise PatchError("patch marker must occur exactly once")
    if source.count("self.plr_tracker.start(") != 1:
        raise PatchError("tracker start hook must occur exactly once")
    if source.count("self.plr_tracker.advance(") != 1:
        raise PatchError("tracker advance hook must occur exactly once")
    if "plr_file" in source or "self.plr_enabled" in source:
        raise PatchError("legacy PLR writer is still present")


def patch_source(source, checkpoint_path=DEFAULT_CHECKPOINT_PATH, record_path=DEFAULT_RECORD_PATH):
    """Return ``(patched_source, changed)`` for one supported vendor source."""

    checkpoint_literal = _path_literal(checkpoint_path, "checkpoint path")
    record_literal = _path_literal(record_path, "record path")
    try:
        ast.parse(source, filename="virtual_sdcard.py")
    except SyntaxError as exc:
        raise PatchError(f"input source is not valid Python: {exc}")

    if PATCH_MARKER in source:
        validate_patched(source, checkpoint_path, record_path)
        return source, False

    source = _replace_once(
        source,
        "import os, sys, logging, io\n",
        f"import os, sys, logging, io\nfrom . import plr_checkpoint  {PATCH_MARKER}\n",
        "imports",
    )
    source = _replace_once(
        source,
        """        # power lose resume
        self.lines = 0
        self.save_every_n_lines = 50
        self.plr_enabled = config.getboolean('plr_enabled', True)
""",
        f"""        # Power-loss resume: publish source-bound checkpoints only after
        # successful dispatch.  Generated .plr files are ignored by the tracker.
        self.lines = 0
        self.save_every_n_lines = config.getint(
            'plr_save_every_n_lines', 50, minval=1, maxval=10000)
        self.plr_tracker = plr_checkpoint.CheckpointTracker(
            config, self.sdcard_dirname, self.save_every_n_lines,
            checkpoint_path={checkpoint_literal},
            record_path={record_literal})
""",
        "constructor PLR state",
    )
    source = _replace_once(
        source,
        """            self.current_file.close()
            self.current_file = None
            self.lines = 0
            self.print_stats.note_cancel()
""",
        """            self.plr_tracker.cancel(self.lines)
            self.current_file.close()
            self.current_file = None
            self.lines = 0
            self.print_stats.note_cancel()
""",
        "cancel lifecycle",
    )
    source = _replace_once(
        source,
        """            self.do_pause()
            self.current_file.close()
            self.current_file = None
        self.file_position = self.file_size = 0
""",
        """            self.do_pause()
            self.plr_tracker.cancel(self.lines)
            self.current_file.close()
            self.current_file = None
            self.lines = 0
        self.file_position = self.file_size = 0
""",
        "reset lifecycle",
    )
    source = _replace_once(
        source,
        """        # Recreate the file to balance the wear on the eMMC
        if self.plr_enabled:
            file_path = "/home/mks/scripts/plr/plr_record"
            if os.path.exists(file_path):
                os.remove(file_path)
            plr_file = open(file_path, 'w', buffering=1)
        while not self.must_pause_work:
""",
        """        self.plr_tracker.start(
            self.current_file, self.file_position, self.lines)
        while not self.must_pause_work:
""",
        "legacy writer creation",
    )
    source = _replace_once(
        source,
        """                except:
                    if self.plr_enabled:
                        plr_file.close()
                    logging.exception("virtual_sdcard read")
""",
        """                except:
                    logging.exception("virtual_sdcard read")
""",
        "read exception",
    )
    source = _replace_once(
        source,
        """                if not data:
                    # End of file
                    self.lines = 0
                    if self.plr_enabled:
                        plr_file.close()
                    self.current_file.close()
""",
        """                if not data:
                    # End of file
                    self.plr_tracker.complete(self.lines)
                    self.lines = 0
                    self.current_file.close()
""",
        "completion lifecycle",
    )
    source = _replace_once(
        source,
        """            try:
                self.lines += 1
                if self.lines % self.save_every_n_lines == 0 and self.plr_enabled:
                    plr_file.seek(0)
                    plr_file.write(str(self.lines))
                    plr_file.truncate()
                self.gcode.run_script(line)
""",
        """            try:
                self.gcode.run_script(line)
                # A failed command must never move the recovery checkpoint.
                self.lines += 1
                self.plr_tracker.advance(self.lines)
""",
        "dispatch checkpoint",
    )
    source = _replace_once(
        source,
        """            if self.next_file_position != next_file_position:
                try:
""",
        """            if self.next_file_position != next_file_position:
                self.plr_tracker.invalidate(
                    self.lines, "virtual SD file position changed")
                try:
""",
        "virtual SD seek invalidation",
    )
    source = _replace_once(
        source,
        """        logging.info("Exiting SD card print (position %d)", self.file_position)
        if self.plr_enabled:
            plr_file.close()
        self.work_timer = None
""",
        """        logging.info("Exiting SD card print (position %d)", self.file_position)
        self.work_timer = None
""",
        "legacy writer close",
    )
    validate_patched(source, checkpoint_path, record_path)
    return source, True


def patch_file(path, checkpoint_path=DEFAULT_CHECKPOINT_PATH, record_path=DEFAULT_RECORD_PATH):
    path = os.path.abspath(path)
    try:
        with open(path, "r", encoding="utf-8", newline="") as source_file:
            raw = source_file.read()
    except OSError as exc:
        raise PatchError(f"cannot read {path}: {exc}")
    newline = "\r\n" if "\r\n" in raw else "\n"
    normalized = raw.replace("\r\n", "\n")
    patched, changed = patch_source(normalized, checkpoint_path, record_path)
    return patched.replace("\n", newline), changed


def create_parser():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", help="virtual_sdcard.py to validate and render")
    parser.add_argument("--checkpoint", default=DEFAULT_CHECKPOINT_PATH)
    parser.add_argument("--record", default=DEFAULT_RECORD_PATH)
    parser.add_argument(
        "--output",
        help="write patched source here; omitted means validate and report only",
    )
    parser.add_argument("--json", action="store_true")
    return parser


def main(argv=None):
    args = create_parser().parse_args(argv)
    try:
        patched, changed = patch_file(args.source, args.checkpoint, args.record)
        if args.output:
            with open(args.output, "w", encoding="utf-8", newline="") as output_file:
                output_file.write(patched)
        result = {
            "ok": True,
            "changed": changed,
            "source": os.path.abspath(args.source),
            "output": os.path.abspath(args.output) if args.output else None,
        }
    except PatchError as exc:
        if args.json:
            print(json.dumps({"ok": False, "error": str(exc)}, sort_keys=True))
        else:
            print(f"PLR patch refused: {exc}", file=sys.stderr)
        return 1
    if args.json:
        print(json.dumps(result, sort_keys=True))
    else:
        print("validated {} ({})".format(args.source, "patch needed" if changed else "already patched"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
