#!/usr/bin/env python3
"""Generate a bounded, source-verified QIDI power-loss recovery G-code.

The stock shell script selects an arbitrary cache file and copies prior source
commands into the recovery prologue.  This replacement uses the exact source
identity and authoritative live runtime snapshot recorded by
``plr_checkpoint.py`` and streams only the remaining G-code.

This file intentionally remains compatible with CPython 3.7.
"""

from __future__ import annotations

import argparse
import json
import math
import os
import re
import sys
import tempfile

import plr_checkpoint

FORMAT_VERSION = 2
START_MARKER = "; QIDI_PLR_HARDENED_V2"
CLEAN_MARKER = "; QIDI_PLR_CLEAN_COMPLETE"
FAN_MARKER = "; QIDI_PLR_FANS_RESTORED"
XY_MARKER = "; QIDI_PLR_XY_RESTORED"
Z_MARKER = "; QIDI_PLR_Z_RESTORED"
CONTINUATION_MARKER = "; QIDI_PLR_CONTINUATION"
MAX_THUMBNAIL_BYTES = 2 * 1024 * 1024
MAX_OBJECT_DEFINITION_BYTES = 8 * 1024 * 1024
COPY_CHUNK = 1024 * 1024

Z_PATTERNS = (
    re.compile(r"^\s*;\s*Z\s*:\s*([-+]?(?:\d+(?:\.\d*)?|\.\d+))\s*$", re.IGNORECASE),
    re.compile(
        r"^\s*;\s*Z_HEIGHT\s*:\s*([-+]?(?:\d+(?:\.\d*)?|\.\d+))\s*$",
        re.IGNORECASE,
    ),
)
COMMAND_PATTERN = re.compile(
    r"^\s*(?:N\d+\s*)?((?:G|M)\d+(?:\.\d+)?|[A-Za-z_][A-Za-z0-9_]*)\s*(.*)$",
    re.IGNORECASE,
)
PARAMETER_PATTERN = re.compile(
    r"([A-Za-z])\s*(?:=\s*)?([-+]?(?:\d+(?:\.\d*)?|\.\d+))"
)


class RecoveryError(Exception):
    """Raised when a recovery file cannot be proven safe to publish."""


def _is_within(path, directory):
    path = os.path.abspath(path)
    directory = os.path.abspath(directory)
    try:
        return os.path.commonpath((path, directory)) == directory
    except ValueError:
        return False


def _format_number(value):
    if int(value) == value:
        return str(int(value))
    return (f"{value:.6f}").rstrip("0").rstrip(".")


def _command_and_parameters(text):
    command_text = text.split(";", 1)[0]
    command_text = re.sub(r"\([^)]*\)", " ", command_text).strip()
    if not command_text:
        return "", {}
    match = COMMAND_PATTERN.match(command_text)
    if match is None:
        return "", {}
    command = match.group(1).upper()
    parameters = {}
    for letter, value in PARAMETER_PATTERN.findall(match.group(2)):
        parameters[letter.upper()] = value
    return command, parameters


def scan_prefix(source_file, completed_lines):
    """Scan the completed prefix and return bounded recovery metadata."""

    layer_z = None
    thumbnail = bytearray()
    in_thumbnail = False
    saw_thumbnail = False
    object_definitions = bytearray()
    continuation_offset = None

    for line_number in range(1, completed_lines + 1):
        line = source_file.readline()
        if not line:
            raise RecoveryError(
                f"checkpoint line {completed_lines:d} is beyond the end of the source"
            )
        try:
            text = line.decode("utf-8")
        except UnicodeDecodeError as exc:
            raise RecoveryError(f"source line {line_number:d} is not UTF-8: {exc}")
        stripped = text.strip()
        lower = stripped.lower()

        if not saw_thumbnail and lower.startswith("; thumbnail begin"):
            in_thumbnail = True
            saw_thumbnail = True
        if in_thumbnail:
            thumbnail.extend(line)
            if len(thumbnail) > MAX_THUMBNAIL_BYTES:
                raise RecoveryError("thumbnail exceeds the bounded recovery limit")
            if lower.startswith("; thumbnail end"):
                in_thumbnail = False

        command, _parameters = _command_and_parameters(text)
        if command == "EXCLUDE_OBJECT_DEFINE":
            object_definitions.extend(line)
            if len(object_definitions) > MAX_OBJECT_DEFINITION_BYTES:
                raise RecoveryError("object definitions exceed the bounded recovery limit")
        for pattern in Z_PATTERNS:
            match = pattern.match(text)
            if match:
                candidate = float(match.group(1))
                if not math.isfinite(candidate) or candidate < 0.0 or candidate > 400.0:
                    raise RecoveryError("recorded Z position is outside 0..400")
                layer_z = candidate
                break

    continuation_offset = source_file.tell()
    if in_thumbnail:
        raise RecoveryError("thumbnail block is incomplete at the checkpoint")
    source_size = os.fstat(source_file.fileno()).st_size
    if continuation_offset >= source_size:
        raise RecoveryError("checkpoint leaves no source G-code to resume")
    if layer_z is None:
        raise RecoveryError("completed prefix has no ;Z: or ; Z_HEIGHT: marker")
    return {
        "continuation_offset": continuation_offset,
        "object_definitions": bytes(object_definitions),
        "source_size": source_size,
        "thumbnail": bytes(thumbnail),
        "layer_z": layer_z,
    }


def recovery_header(checkpoint, metadata):
    runtime = checkpoint["runtime"]
    move = runtime["gcode_move"]
    physical = move["position"]
    gcode_position = move["gcode_position"]
    origin = move["homing_origin"]
    temperatures = runtime["heaters"]
    toolhead = runtime["toolhead"]
    extruder = runtime["extruder"]
    fans = runtime["fans"]
    filter_minimum = runtime["macros"]["M106"]["filter_minimum"]
    lines = [
        START_MARKER,
        f"; checkpoint_line={checkpoint['line']:d}",
        f"; source_size={checkpoint['source']['size']:d}",
    ]
    header = ("\n".join(lines) + "\n").encode("ascii")
    if metadata["thumbnail"]:
        header += metadata["thumbnail"]
        if not header.endswith(b"\n"):
            header += b"\n"
    header += (
        "SET_KINEMATIC_POSITION Z={}\n".format(_format_number(physical["Z"]))
    ).encode("ascii")
    header += metadata["object_definitions"]
    if metadata["object_definitions"] and not header.endswith(b"\n"):
        header += b"\n"
    commands = [
        "M140 S{}".format(_format_number(temperatures["bed"])),
        "M104 S{}".format(_format_number(temperatures["extruder"])),
        "M141 S{}".format(_format_number(temperatures["chamber"])),
        "G91",
        "G1 Z5 F600",
        "G90",
        "G28 X Y",
        "G28 X",
        "CLEAR_NOZZLE_PLR HOTEND={}".format(_format_number(temperatures["extruder"])),
        f"M400 {CLEAN_MARKER}",
    ]
    if temperatures["bed"] > 0.0:
        commands.append("M190 S{}".format(_format_number(temperatures["bed"])))
    if temperatures["chamber"] > 0.0:
        commands.append("M191 S{}".format(_format_number(temperatures["chamber"])))
    commands.append(
        f"SET_GCODE_VARIABLE MACRO=M106 VARIABLE=filter_minimum VALUE={_format_number(filter_minimum)}"
    )
    for port, name in (
        ("P0", "cooling_fan"),
        ("P2", "auxiliary_cooling_fan"),
        ("P3", "chamber_circulation_fan"),
    ):
        commands.append(
            f"SET_FAN_SPEED FAN={name} SPEED={_format_number(fans[port] / 255.0)}"
        )
    commands.extend(
        (
            f"M400 {FAN_MARKER}",
            # CLEAR_NOZZLE_PLR has intentionally moved through a temporary
            # coordinate frame.  Re-home XY, then zero the homing-origin frame
            # so the following coordinates name the checkpoint's physical XYZ
            # rather than inheriting a saved Z offset or other startup offset.
            "G28 X Y",
            "M400",
            "SET_GCODE_OFFSET X=0 Y=0 Z=0 E=0",
            "G90",
            "G1 X{} Y{} F12000".format(
                _format_number(physical["X"]),
                _format_number(physical["Y"]),
            ),
            f"M400 {XY_MARKER}",
            "G1 Z{} F600".format(_format_number(physical["Z"])),
            f"M400 {Z_MARKER}",
            "SET_VELOCITY_LIMIT VELOCITY={} ACCEL={} ACCEL_TO_DECEL={} SQUARE_CORNER_VELOCITY={}".format(
                _format_number(toolhead["max_velocity"]),
                _format_number(toolhead["max_accel"]),
                _format_number(toolhead["max_accel_to_decel"]),
                _format_number(toolhead["square_corner_velocity"]),
            ),
            "SET_PRESSURE_ADVANCE ADVANCE={} SMOOTH_TIME={}".format(
                _format_number(extruder["pressure_advance"]),
                _format_number(extruder["smooth_time"]),
            ),
            "M220 S{}".format(_format_number(move["speed_factor"])),
            "M221 S{}".format(_format_number(move["extrude_factor"])),
            "SET_GCODE_OFFSET X={} Y={} Z={} E={}".format(*tuple(_format_number(origin[axis]) for axis in "XYZE")),
            "G92 X{} Y{} Z{} E{}".format(*tuple(_format_number(gcode_position[axis]) for axis in "XYZE")),
            "M82" if move["absolute_extrude"] else "M83",
            "G90" if move["absolute_coordinates"] else "G91",
            "G1 F{}".format(_format_number(move["feed_rate"])),
            "ENABLE_ALL_SENSOR",
            CONTINUATION_MARKER,
        )
    )
    return header + ("\n".join(commands) + "\n").encode("ascii")


def _remove_output(path, strict=False):
    try:
        os.unlink(path)
    except FileNotFoundError:
        return
    except OSError as exc:
        if strict:
            raise RecoveryError(f"stale recovery output cannot be removed: {exc}")
        return
    try:
        _fsync_directory(os.path.dirname(os.path.abspath(path)))
    except OSError as exc:
        if strict:
            raise RecoveryError(f"recovery directory cannot be synchronized: {exc}")


def _validate_output(path, header, expected_size):
    stat_result = os.stat(path)
    if stat_result.st_size != expected_size:
        raise RecoveryError("generated recovery size does not match its source tail")
    with open(path, "rb") as output_file:
        actual_header = output_file.read(len(header))
    if actual_header != header:
        raise RecoveryError("generated recovery header failed byte validation")
    decoded = header.decode("utf-8")
    markers = (
        START_MARKER,
        CLEAN_MARKER,
        FAN_MARKER,
        XY_MARKER,
        Z_MARKER,
        CONTINUATION_MARKER,
    )
    if any(decoded.count(marker) != 1 for marker in markers):
        raise RecoveryError("generated recovery marker validation failed")
    prologue = decoded.split(CONTINUATION_MARKER, 1)[0]
    commands = [line.split(";", 1)[0].strip().upper() for line in prologue.splitlines()]
    if sum(command.startswith("SET_FAN_SPEED ") for command in commands) != 3:
        raise RecoveryError("generated recovery must contain exactly three fan restores")
    clear_index = next(
        index for index, command in enumerate(commands) if command.startswith("CLEAR_NOZZLE_PLR ")
    )
    clean_index = next(
        index for index, line in enumerate(prologue.splitlines()) if CLEAN_MARKER in line
    )
    first_motion_after_clear = next(
        (
            index
            for index, command in enumerate(commands[clear_index + 1 :], clear_index + 1)
            if command.startswith(("G0 ", "G1 ", "G2 ", "G3 "))
        ),
        len(commands),
    )
    if clean_index <= clear_index or clean_index >= first_motion_after_clear:
        raise RecoveryError("CLEAR_NOZZLE_PLR is not fenced by M400 before motion")


def _fsync_directory(directory):
    try:
        directory_fd = os.open(directory, os.O_RDONLY)
    except OSError:
        return
    try:
        os.fsync(directory_fd)
    finally:
        os.close(directory_fd)


def generate(checkpoint_path, gcode_root, output_path):
    """Generate and atomically publish one recovery file."""

    checkpoint_path = os.path.abspath(checkpoint_path)
    gcode_root = os.path.realpath(gcode_root)
    output_path = os.path.abspath(output_path)
    plr_directory = os.path.join(gcode_root, ".plr")
    if not os.path.isdir(gcode_root):
        raise RecoveryError("G-code root does not exist")
    if not os.path.isdir(plr_directory):
        raise RecoveryError(f"recovery directory does not exist: {plr_directory}")
    if os.path.islink(plr_directory):
        raise RecoveryError("recovery directory must not be a symlink")
    if not _is_within(os.path.realpath(plr_directory), gcode_root):
        raise RecoveryError("resolved recovery directory escapes the G-code root")
    if not _is_within(output_path, plr_directory):
        raise RecoveryError("output must be inside the G-code root's .plr directory")
    if not _is_within(os.path.realpath(os.path.dirname(output_path)), os.path.realpath(plr_directory)):
        raise RecoveryError("resolved output directory escapes the .plr directory")

    # Fail closed before inspecting any untrusted or potentially stale state.
    _remove_output(output_path, strict=True)
    temporary = None
    try:
        checkpoint_raw = plr_checkpoint.checkpoint_bytes(checkpoint_path)
        checkpoint = plr_checkpoint.load_checkpoint(checkpoint_path)
        source_path = checkpoint["source"]["path"]
        if not _is_within(source_path, gcode_root):
            raise RecoveryError("checkpoint source is outside the G-code root")
        if plr_checkpoint.is_recovery_path(source_path, gcode_root):
            raise RecoveryError("a generated recovery file cannot be a recovery source")
        if os.path.realpath(output_path) == os.path.realpath(source_path):
            raise RecoveryError("source and recovery output resolve to the same file")
        with open(source_path, "rb") as source_file:
            before = plr_checkpoint.source_identity(source_file)
            if not plr_checkpoint.identities_match(checkpoint["source"], before):
                raise RecoveryError("checkpoint source identity no longer matches")
            metadata = scan_prefix(source_file, checkpoint["line"])
            header = recovery_header(checkpoint, metadata)
            fd, temporary = tempfile.mkstemp(
                prefix=f".{os.path.basename(output_path)}.",
                suffix=".tmp",
                dir=os.path.dirname(output_path),
            )
            if hasattr(os, "fchmod"):
                os.fchmod(fd, 0o644)
            with os.fdopen(fd, "wb") as output_file:
                output_file.write(header)
                source_file.seek(metadata["continuation_offset"])
                while True:
                    chunk = source_file.read(COPY_CHUNK)
                    if not chunk:
                        break
                    output_file.write(chunk)
                output_file.flush()
                os.fsync(output_file.fileno())
            expected_size = len(header) + (
                metadata["source_size"] - metadata["continuation_offset"]
            )
            _validate_output(temporary, header, expected_size)
            after_fd = plr_checkpoint.source_identity(source_file)
            after_path = plr_checkpoint.source_identity(source_path)
            if not plr_checkpoint.identities_match(before, after_fd):
                raise RecoveryError("source changed while recovery was generated")
            if not plr_checkpoint.identities_match(before, after_path):
                raise RecoveryError("source path changed while recovery was generated")
        if plr_checkpoint.checkpoint_bytes(checkpoint_path) != checkpoint_raw:
            raise RecoveryError("checkpoint changed while recovery was generated")
        os.replace(temporary, output_path)
        temporary = None
        _fsync_directory(os.path.dirname(output_path))
        return {
            "schema": "qidi-plr-recovery/v2",
            "output": output_path,
            "source": source_path,
            "checkpoint_line": checkpoint["line"],
            "z": checkpoint["runtime"]["gcode_move"]["position"]["Z"],
            "layer_z": metadata["layer_z"],
            "fan_state": dict(checkpoint["runtime"]["fans"]),
            "bytes": os.path.getsize(output_path),
        }
    except (OSError, plr_checkpoint.CheckpointError) as exc:
        raise RecoveryError(str(exc))
    finally:
        if temporary is not None:
            try:
                os.unlink(temporary)
            except OSError:
                pass
        # No failed path may leave a stale or partially validated recovery.
        if sys.exc_info()[0] is not None:
            _remove_output(output_path)


def create_parser():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--checkpoint", required=True)
    parser.add_argument("--gcode-root", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--json", action="store_true", help="emit one JSON result")
    return parser


def main(argv=None):
    args = create_parser().parse_args(argv)
    try:
        result = generate(
            args.checkpoint, args.gcode_root, args.output
        )
    except RecoveryError as exc:
        if args.json:
            print(json.dumps({"ok": False, "error": str(exc)}, sort_keys=True))
        else:
            print(f"PLR generation refused: {exc}", file=sys.stderr)
        return 1
    result["ok"] = True
    if args.json:
        print(json.dumps(result, sort_keys=True))
    else:
        print(
            f"Generated {result['output']} from {result['source']} "
            f"after line {result['checkpoint_line']:d} at Z={result['z']}"
        )
    return 0


if __name__ == "__main__":
    sys.exit(main())
