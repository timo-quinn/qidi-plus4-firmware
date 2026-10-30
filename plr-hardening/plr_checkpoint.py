#!/usr/bin/env python3
"""Power-loss checkpoint support for QIDI's Klipper virtual SD extension.

This module intentionally supports CPython 3.7, which is the interpreter in
the stock Plus4 Klipper environment.  It is installed beside
``virtual_sdcard.py`` and is also used by the recovery-file generator.
"""

from __future__ import annotations

import hashlib
import json
import logging
import math
import os
import tempfile
import threading
import time

logger = logging.getLogger(__name__)

SCHEMA_VERSION = 2
SAMPLE_SIZE = 64 * 1024
DEFAULT_RECORD_PATH = "/home/mks/scripts/plr/plr_record"
DEFAULT_CHECKPOINT_PATH = "/home/mks/scripts/plr/plr_checkpoint.json"
IDENTITY_FIELDS = (
    "path",
    "device",
    "inode",
    "size",
    "mtime_ns",
    "sample_sha256",
)
AXES = ("X", "Y", "Z", "E")
FAN_PORTS = ("P0", "P2", "P3")
FAN_OBJECTS = {
    "P0": "fan_generic cooling_fan",
    "P2": "fan_generic auxiliary_cooling_fan",
    "P3": "fan_generic chamber_circulation_fan",
}


class CheckpointError(Exception):
    """Raised when a checkpoint is absent, malformed, or no longer valid."""


def _mtime_ns(stat_result):
    value = getattr(stat_result, "st_mtime_ns", None)
    if value is not None:
        return int(value)
    return int(stat_result.st_mtime * 1000000000)


def _is_within(path, directory):
    path = os.path.abspath(path)
    directory = os.path.abspath(directory)
    try:
        return os.path.commonpath((path, directory)) == directory
    except ValueError:
        return False


def is_recovery_path(path, gcode_root):
    """Return True for lexical or resolved paths below ``gcode_root/.plr``."""

    lexical_path = os.path.abspath(path)
    lexical_plr = os.path.abspath(os.path.join(gcode_root, ".plr"))
    if _is_within(lexical_path, lexical_plr):
        return True
    resolved_path = os.path.realpath(path)
    resolved_plr = os.path.realpath(os.path.join(gcode_root, ".plr"))
    return _is_within(resolved_path, resolved_plr)


def _pread(fd, length, offset):
    if hasattr(os, "pread"):
        return os.pread(fd, length, offset)
    current = os.lseek(fd, 0, os.SEEK_CUR)
    try:
        os.lseek(fd, offset, os.SEEK_SET)
        return os.read(fd, length)
    finally:
        os.lseek(fd, current, os.SEEK_SET)


def _sample_digest(fd, size):
    digest = hashlib.sha256()
    digest.update(b"QIDI-PLR-SOURCE-V1\0")
    digest.update(str(size).encode("ascii"))
    digest.update(b"\0")
    if size <= SAMPLE_SIZE * 2:
        digest.update(_pread(fd, size, 0))
    else:
        digest.update(_pread(fd, SAMPLE_SIZE, 0))
        digest.update(_pread(fd, SAMPLE_SIZE, size - SAMPLE_SIZE))
    return digest.hexdigest()


def source_identity(file_or_path):
    """Return a stable, inexpensive identity for an open or named G-code."""

    if not hasattr(file_or_path, "fileno"):
        with open(os.fspath(file_or_path), "rb") as source_file:
            return source_identity(source_file)
    fd = file_or_path.fileno()
    stat_result = os.fstat(fd)
    return {
        "path": os.path.realpath(file_or_path.name),
        "device": int(stat_result.st_dev),
        "inode": int(stat_result.st_ino),
        "size": int(stat_result.st_size),
        "mtime_ns": _mtime_ns(stat_result),
        "sample_sha256": _sample_digest(fd, int(stat_result.st_size)),
    }


def identities_match(expected, actual):
    return all(expected.get(field) == actual.get(field) for field in IDENTITY_FIELDS)


def _validate_identity(value):
    if not isinstance(value, dict):
        raise CheckpointError("checkpoint source identity is not an object")
    _require_exact_keys(value, IDENTITY_FIELDS, "checkpoint source identity")
    for field in IDENTITY_FIELDS:
        if field not in value:
            raise CheckpointError(f"checkpoint source identity is missing {field}")
    if not isinstance(value["path"], str) or not os.path.isabs(value["path"]):
        raise CheckpointError("checkpoint source path must be absolute")
    for field in ("device", "inode", "size", "mtime_ns"):
        if isinstance(value[field], bool) or not isinstance(value[field], int):
            raise CheckpointError(f"checkpoint source {field} must be an integer")
        if value[field] < 0:
            raise CheckpointError(f"checkpoint source {field} must not be negative")
    digest = value["sample_sha256"]
    if (
        not isinstance(digest, str)
        or len(digest) != 64
        or any(character not in "0123456789abcdef" for character in digest)
    ):
        raise CheckpointError("checkpoint source sample hash is invalid")
    return {field: value[field] for field in IDENTITY_FIELDS}


def _require_exact_keys(value, expected, label):
    if not isinstance(value, dict):
        raise CheckpointError(f"{label} is not an object")
    actual = set(value)
    expected = set(expected)
    if actual != expected:
        missing = sorted(expected - actual)
        extra = sorted(actual - expected)
        detail = []
        if missing:
            detail.append("missing {}".format(",".join(missing)))
        if extra:
            detail.append("unexpected {}".format(",".join(extra)))
        raise CheckpointError("{} fields are invalid ({})".format(label, "; ".join(detail)))


def _finite_number(value, label, minimum, maximum):
    if isinstance(value, bool) or not isinstance(value, (int, float)):
        raise CheckpointError(f"{label} must be numeric")
    value = float(value)
    if not math.isfinite(value) or value < minimum or value > maximum:
        raise CheckpointError(
            f"{label} is outside {minimum:.6g}..{maximum:.6g}"
        )
    return value


def _validate_axes(value, label, minimum=-1000000000000.0, maximum=1000000000000.0):
    _require_exact_keys(value, AXES, label)
    return {
        axis: _finite_number(value[axis], f"{label}.{axis}", minimum, maximum)
        for axis in AXES
    }


def _close_enough(left, right):
    return abs(left - right) <= max(0.000001, max(abs(left), abs(right)) * 0.000000001)


def _validate_runtime_snapshot(value, line):
    """Strictly validate one self-consistent, live Klipper runtime snapshot."""

    _require_exact_keys(
        value,
        ("captured_after_line", "gcode_move", "toolhead", "extruder", "fans", "heaters", "macros"),
        "checkpoint runtime",
    )
    captured_line = value["captured_after_line"]
    if isinstance(captured_line, bool) or not isinstance(captured_line, int):
        raise CheckpointError("checkpoint runtime line must be an integer")
    if captured_line != line:
        raise CheckpointError("checkpoint runtime line does not match checkpoint line")

    move = value["gcode_move"]
    _require_exact_keys(
        move,
        (
            "absolute_coordinates",
            "absolute_extrude",
            "base_position",
            "extrude_factor",
            "feed_rate",
            "gcode_position",
            "homing_origin",
            "position",
            "speed_factor",
        ),
        "checkpoint gcode_move",
    )
    for name in ("absolute_coordinates", "absolute_extrude"):
        if not isinstance(move[name], bool):
            raise CheckpointError(f"checkpoint gcode_move.{name} must be boolean")
    position = _validate_axes(move["position"], "checkpoint gcode_move.position")
    gcode_position = _validate_axes(
        move["gcode_position"], "checkpoint gcode_move.gcode_position"
    )
    base_position = _validate_axes(
        move["base_position"], "checkpoint gcode_move.base_position"
    )
    homing_origin = _validate_axes(
        move["homing_origin"], "checkpoint gcode_move.homing_origin"
    )
    if position["Z"] < -10.0 or position["Z"] > 400.0:
        raise CheckpointError("checkpoint physical Z is outside -10..400")
    speed_factor = _finite_number(
        move["speed_factor"], "checkpoint gcode_move.speed_factor", 0.000001, 1000.0
    )
    extrude_factor = _finite_number(
        move["extrude_factor"], "checkpoint gcode_move.extrude_factor", 0.000001, 1000.0
    )
    feed_rate = _finite_number(
        move["feed_rate"], "checkpoint gcode_move.feed_rate", 0.000001, 10000000.0
    )
    for axis in ("X", "Y", "Z"):
        expected = position[axis] - base_position[axis]
        if not _close_enough(expected, gcode_position[axis]):
            raise CheckpointError(
                f"checkpoint {axis} coordinate mapping is inconsistent"
            )
    expected_e = (position["E"] - base_position["E"]) / (extrude_factor / 100.0)
    if not _close_enough(expected_e, gcode_position["E"]):
        raise CheckpointError("checkpoint E coordinate mapping is inconsistent")

    toolhead = value["toolhead"]
    _require_exact_keys(
        toolhead,
        (
            "active_extruder",
            "max_accel",
            "max_accel_to_decel",
            "max_velocity",
            "square_corner_velocity",
        ),
        "checkpoint toolhead",
    )
    if toolhead["active_extruder"] != "extruder":
        raise CheckpointError("checkpoint active extruder is unsupported")
    normalized_toolhead = {
        "active_extruder": "extruder",
        "max_velocity": _finite_number(
            toolhead["max_velocity"], "checkpoint toolhead.max_velocity", 0.000001, 10000.0
        ),
        "max_accel": _finite_number(
            toolhead["max_accel"], "checkpoint toolhead.max_accel", 0.000001, 1000000.0
        ),
        "max_accel_to_decel": _finite_number(
            toolhead["max_accel_to_decel"],
            "checkpoint toolhead.max_accel_to_decel",
            0.000001,
            1000000.0,
        ),
        "square_corner_velocity": _finite_number(
            toolhead["square_corner_velocity"],
            "checkpoint toolhead.square_corner_velocity",
            0.0,
            10000.0,
        ),
    }

    extruder = value["extruder"]
    _require_exact_keys(extruder, ("pressure_advance", "smooth_time"), "checkpoint extruder")
    normalized_extruder = {
        "pressure_advance": _finite_number(
            extruder["pressure_advance"], "checkpoint extruder.pressure_advance", 0.0, 10.0
        ),
        "smooth_time": _finite_number(
            extruder["smooth_time"], "checkpoint extruder.smooth_time", 0.0, 0.2
        ),
    }

    fans = value["fans"]
    _require_exact_keys(fans, FAN_PORTS, "checkpoint fans")
    normalized_fans = {
        port: _finite_number(fans[port], f"checkpoint fans.{port}", 0.0, 255.0)
        for port in FAN_PORTS
    }

    heaters = value["heaters"]
    _require_exact_keys(heaters, ("bed", "chamber", "extruder"), "checkpoint heaters")
    normalized_heaters = {
        "bed": _finite_number(heaters["bed"], "checkpoint heaters.bed", 0.0, 150.0),
        "chamber": _finite_number(
            heaters["chamber"], "checkpoint heaters.chamber", 0.0, 100.0
        ),
        "extruder": _finite_number(
            heaters["extruder"], "checkpoint heaters.extruder", 150.0, 400.0
        ),
    }

    macros = value["macros"]
    _require_exact_keys(macros, ("M106",), "checkpoint macros")
    _require_exact_keys(macros["M106"], ("filter_minimum",), "checkpoint macros.M106")
    normalized_macros = {
        "M106": {
            "filter_minimum": _finite_number(
                macros["M106"]["filter_minimum"],
                "checkpoint macros.M106.filter_minimum",
                0.0,
                1.0,
            )
        }
    }

    return {
        "captured_after_line": captured_line,
        "gcode_move": {
            "absolute_coordinates": move["absolute_coordinates"],
            "absolute_extrude": move["absolute_extrude"],
            "base_position": base_position,
            "extrude_factor": extrude_factor,
            "feed_rate": feed_rate,
            "gcode_position": gcode_position,
            "homing_origin": homing_origin,
            "position": position,
            "speed_factor": speed_factor,
        },
        "toolhead": normalized_toolhead,
        "extruder": normalized_extruder,
        "fans": normalized_fans,
        "heaters": normalized_heaters,
        "macros": normalized_macros,
    }


def checkpoint_bytes(path):
    try:
        stat_result = os.stat(path)
    except OSError as exc:
        raise CheckpointError(f"checkpoint is unavailable: {exc}")
    if stat_result.st_size <= 0 or stat_result.st_size > 64 * 1024:
        raise CheckpointError("checkpoint size is invalid")
    try:
        with open(path, "rb") as checkpoint_file:
            return checkpoint_file.read()
    except OSError as exc:
        raise CheckpointError(f"checkpoint cannot be read: {exc}")


def load_checkpoint(path):
    """Load and strictly validate an active checkpoint."""

    raw = checkpoint_bytes(path)
    try:
        value = json.loads(raw.decode("utf-8"))
    except (UnicodeDecodeError, ValueError) as exc:
        raise CheckpointError(f"checkpoint is not valid UTF-8 JSON: {exc}")
    if not isinstance(value, dict):
        raise CheckpointError("checkpoint root is not an object")
    if value.get("version") != SCHEMA_VERSION:
        raise CheckpointError("unsupported checkpoint version")
    if value.get("state") != "active":
        raise CheckpointError(
            "checkpoint is not resumable (state={})".format(value.get("state"))
        )
    _require_exact_keys(
        value, ("version", "state", "line", "source", "runtime"), "checkpoint root"
    )
    line = value.get("line")
    if isinstance(line, bool) or not isinstance(line, int) or line <= 0:
        raise CheckpointError("checkpoint line must be a positive integer")
    runtime = _validate_runtime_snapshot(value.get("runtime"), line)
    return {
        "version": SCHEMA_VERSION,
        "state": "active",
        "line": line,
        "source": _validate_identity(value.get("source")),
        "runtime": runtime,
    }


def atomic_write(path, data, mode=0o600):
    """Durably replace ``path`` using a temporary file in the same directory."""

    path = os.path.abspath(path)
    directory = os.path.dirname(path)
    if not os.path.isdir(directory):
        raise OSError(f"destination directory does not exist: {directory}")
    fd, temporary = tempfile.mkstemp(
        prefix=f".{os.path.basename(path)}.", suffix=".tmp", dir=directory
    )
    try:
        if hasattr(os, "fchmod"):
            os.fchmod(fd, mode)
        with os.fdopen(fd, "wb") as output:
            fd = -1
            output.write(data)
            output.flush()
            os.fsync(output.fileno())
        os.replace(temporary, path)
        # Directory fsync is supported by the Linux runtime on the printer.  A
        # few development hosts (notably Windows) cannot open a directory as a
        # file descriptor; the file itself has still been flushed there.
        try:
            directory_fd = os.open(directory, os.O_RDONLY)
        except OSError:
            directory_fd = None
        if directory_fd is None:
            return
        try:
            os.fsync(directory_fd)
        finally:
            os.close(directory_fd)
    except Exception:
        if fd >= 0:
            os.close(fd)
        try:
            os.unlink(temporary)
        except OSError:
            pass
        raise


def durable_unlink(path):
    """Remove a checkpoint and durably publish the directory change on Linux."""

    try:
        os.unlink(path)
    except FileNotFoundError:
        return
    directory = os.path.dirname(os.path.abspath(path))
    try:
        directory_fd = os.open(directory, os.O_RDONLY)
    except OSError:
        return
    try:
        os.fsync(directory_fd)
    finally:
        os.close(directory_fd)


def _checkpoint_document(state, line, identity, runtime=None, reason=None):
    document = {
        "version": SCHEMA_VERSION,
        "state": state,
        "line": int(line),
        "source": identity,
    }
    if state == "active":
        document["runtime"] = _validate_runtime_snapshot(runtime, int(line))
    if reason:
        document["reason"] = str(reason)
    return (json.dumps(document, sort_keys=True, separators=(",", ":")) + "\n").encode(
        "utf-8"
    )


def _write_checkpoint_files(record_path, checkpoint_path, job):
    state = job["state"]
    line = job["line"]
    document = _checkpoint_document(
        state,
        line,
        job["identity"],
        runtime=job.get("runtime"),
        reason=job.get("reason"),
    )
    legacy = (str(line if state == "active" else 0) + "\n").encode("ascii")
    if state == "active":
        # JSON is authoritative.  Publish it last so interruption can only
        # leave the preceding, still-consistent checkpoint.
        atomic_write(record_path, legacy)
        atomic_write(checkpoint_path, document)
    else:
        # Publish terminal state first so legacy data cannot resurrect it.
        atomic_write(checkpoint_path, document)
        atomic_write(record_path, legacy)


class _CheckpointWriter:
    """One bounded, coalescing durability worker shared by a tracker.

    Klippy's reactor must not wait for eMMC fsync.  There is at most one job in
    flight and one pending job; newer active snapshots coalesce, while a later
    terminal state always follows (or replaces) a queued active snapshot.
    """

    def __init__(self, record_path, checkpoint_path):
        self.record_path = record_path
        self.checkpoint_path = checkpoint_path
        self.condition = threading.Condition()
        self.pending = None
        self.writing = False
        self.error = None
        self.coalesced = 0
        self.lifecycle_epoch = 0
        self.io_lock = threading.Lock()
        self.thread = threading.Thread(
            target=self._run, name="qidi-plr-checkpoint-writer"
        )
        self.thread.daemon = True
        self.thread.start()

    def enqueue(self, state, line, identity, runtime=None, reason=None, delay=0.0):
        job = {
            "state": state,
            "line": int(line),
            "identity": dict(identity),
            "runtime": runtime,
            "reason": reason,
            "not_before": time.monotonic() + max(0.0, float(delay)),
        }
        with self.condition:
            job["epoch"] = self.lifecycle_epoch
            if self.error is not None:
                return False
            if self.pending is None:
                self.pending = job
            elif state == "active" and self.pending["state"] == "active":
                self.pending = job
                self.coalesced += 1
            elif state != "active":
                # A terminal state supersedes an active snapshot.  Replacing a
                # terminal state is also safe: the newest lifecycle decision
                # is authoritative and no subsequent active job is accepted
                # until start() has flushed the worker.
                self.pending = job
                self.coalesced += 1
            else:
                # start() flushes terminal work before a new session.  Seeing
                # an active job behind a terminal job is therefore a lifecycle
                # violation; fail closed instead of reordering it.
                self.error = CheckpointError(
                    "active checkpoint was queued behind a terminal state"
                )
                self.condition.notify_all()
                return False
            self.condition.notify_all()
            return True

    def commit_terminal(self, state, line, identity, reason=None):
        """Synchronously make a terminal lifecycle decision authoritative.

        Active checkpoints remain off-reactor.  Cancellation, invalidation and
        physical completion are rare and must not return while a slow active
        fsync can still publish resumable JSON after the terminal decision.
        """

        if state == "active":
            raise CheckpointError("terminal checkpoint cannot be active")
        job = {
            "state": state,
            "line": int(line),
            "identity": dict(identity),
            "runtime": None,
            "reason": reason,
        }
        with self.condition:
            self.lifecycle_epoch += 1
            self.pending = None
            epoch = self.lifecycle_epoch
            self.condition.notify_all()
        try:
            with self.io_lock:
                _write_checkpoint_files(self.record_path, self.checkpoint_path, job)
        except Exception as exc:  # noqa: BLE001
            # Invalidate the checkpoint on any durability failure.
            try:
                durable_unlink(self.checkpoint_path)
            except OSError:
                pass
            with self.condition:
                self.error = exc
                self.condition.notify_all()
            return False
        with self.condition:
            # A newer terminal decision could only be made serially by this
            # tracker.  Keep the check explicit so future callers cannot make
            # an older lifecycle write appear current.
            if epoch != self.lifecycle_epoch:
                self.error = CheckpointError("terminal checkpoint epoch changed")
                return False
            self.condition.notify_all()
        return True

    def abort(self, reason):
        """Cancel every lifecycle write and durably remove resumable state."""

        with self.condition:
            self.lifecycle_epoch += 1
            self.pending = None
            self.condition.notify_all()
        failure = CheckpointError(str(reason))
        try:
            with self.io_lock:
                atomic_write(self.record_path, b"0\n")
                durable_unlink(self.checkpoint_path)
        except Exception as exc:  # noqa: BLE001
            # Record any abort failure before notifying the writer.
            failure = exc
            try:
                durable_unlink(self.checkpoint_path)
            except OSError:
                pass
        with self.condition:
            self.error = failure
            self.pending = None
            self.condition.notify_all()
        return not os.path.exists(self.checkpoint_path)

    def flush(self, timeout=30.0):
        deadline = time.monotonic() + float(timeout)
        with self.condition:
            while self.pending is not None or self.writing:
                remaining = deadline - time.monotonic()
                if remaining <= 0.0:
                    return False
                self.condition.wait(remaining)
            return self.error is None

    def get_error(self):
        with self.condition:
            return self.error

    def _run(self):
        while True:
            with self.condition:
                while self.pending is None:
                    self.condition.wait()
                # Leave delayed work pending and the condition unlocked while
                # waiting.  A cancellation/completion can then replace an
                # active job that has not started durable IO yet.
                while self.pending is not None:
                    delay = self.pending["not_before"] - time.monotonic()
                    if delay <= 0.0:
                        break
                    self.condition.wait(delay)
                job = self.pending
                self.pending = None
                self.writing = True
            try:
                with self.io_lock:
                    with self.condition:
                        stale = job["epoch"] != self.lifecycle_epoch
                    if not stale:
                        _write_checkpoint_files(
                            self.record_path, self.checkpoint_path, job
                        )
            except Exception as exc:
                logger.exception(
                    "PLR background checkpoint write failed; recovery disabled"
                )
                try:
                    durable_unlink(self.checkpoint_path)
                except OSError as unlink_exc:
                    logger.critical(
                        "PLR could not remove a stale authoritative checkpoint: %s",
                        unlink_exc,
                    )
                with self.condition:
                    self.error = exc
                    self.pending = None
            finally:
                with self.condition:
                    self.writing = False
                    self.condition.notify_all()


def _coordinate_dict(value, label):
    try:
        values = [getattr(value, axis.lower()) for axis in AXES]
    except AttributeError:
        try:
            values = list(value)
        except TypeError:
            raise CheckpointError(f"{label} is not a coordinate")
        if len(values) != len(AXES):
            raise CheckpointError(f"{label} does not contain XYZE")
    return {axis: values[index] for index, axis in enumerate(AXES)}


def _status(object_value, eventtime, label):
    try:
        value = object_value.get_status(eventtime)
    except Exception as exc:  # noqa: BLE001
        # Convert arbitrary plugin status failures into checkpoint errors.
        raise CheckpointError(f"cannot read {label} status: {exc}")
    if not isinstance(value, dict):
        raise CheckpointError(f"{label} status is not an object")
    return value


def _clone(value):
    return json.loads(json.dumps(value, allow_nan=False))


class CheckpointTracker:
    """Track completed lines without allowing recovery files to poison state."""

    def __init__(
        self,
        config,
        gcode_root,
        save_every_n_lines,
        checkpoint_path=None,
        record_path=None,
    ):
        self.enabled = config.getboolean("plr_enabled", True)
        self.printer = config.get_printer()
        self.reactor = self.printer.get_reactor()
        self.gcode_root = os.path.realpath(gcode_root)
        self.save_every_n_lines = int(save_every_n_lines)
        self.record_path = config.get(
            "plr_record_path", record_path or DEFAULT_RECORD_PATH
        )
        self.checkpoint_path = config.get(
            "plr_checkpoint_path", checkpoint_path or DEFAULT_CHECKPOINT_PATH
        )
        self.active = False
        self.identity = None
        self.last_line = 0
        self.last_published_line = 0
        self.generation = 0
        self.callback_pending = False
        self.fan_objects = {
            port: config.get(
                f"plr_fan_{port.lower()}_object", default_object
            )
            for port, default_object in FAN_OBJECTS.items()
        }
        self.writer = _CheckpointWriter(self.record_path, self.checkpoint_path)

    def _remove_authoritative_checkpoint(self):
        try:
            durable_unlink(self.checkpoint_path)
        except OSError:
            pass

    def _disable_after_error(self, operation):
        logger.exception("PLR checkpoint %s failed; recovery disabled", operation)
        self.writer.abort(f"PLR checkpoint {operation} failed")
        self.active = False
        self.identity = None

    def _commit_sync(self, state, line, runtime=None, reason=None):
        if state == "active":
            raise CheckpointError("synchronous active checkpoint is forbidden")
        if not self.writer.commit_terminal(
            state, int(line), self.identity, reason=reason
        ):
            raise CheckpointError("terminal checkpoint commit failed")

    def _queue(self, state, line, runtime=None, reason=None, delay=0.0):
        if not self.writer.enqueue(
            state,
            line,
            self.identity,
            runtime=runtime,
            reason=reason,
            delay=delay,
        ):
            self.active = False
            return False
        return True

    def _terminal(self, state, line, reason=None):
        if not self.writer.commit_terminal(
            state, int(line), self.identity, reason=reason
        ):
            self.writer.abort("terminal checkpoint commit failed")
            self.active = False
            return False
        return True

    def _lookup(self, name):
        try:
            value = self.printer.lookup_object(name, None)
        except TypeError:
            try:
                value = self.printer.lookup_object(name)
            except Exception:  # noqa: BLE001
                # Treat arbitrary Klipper lookup failures as unavailable objects.
                value = None
        if value is None:
            raise CheckpointError(f"required Klipper object is unavailable: {name}")
        return value

    def _capture_fans(self, eventtime):
        result = {}
        for port in FAN_PORTS:
            object_name = self.fan_objects[port]
            status = _status(self._lookup(object_name), eventtime, object_name)
            if "speed" not in status:
                raise CheckpointError(f"{object_name} status has no speed")
            result[port] = float(status["speed"]) * 255.0
        return result

    def _capture_runtime(self, completed_lines):
        eventtime = self.reactor.monotonic()
        move_object = self._lookup("gcode_move")
        move = _status(move_object, eventtime, "gcode_move")
        toolhead = _status(self._lookup("toolhead"), eventtime, "toolhead")
        extruder = _status(self._lookup("extruder"), eventtime, "extruder")
        bed = _status(self._lookup("heater_bed"), eventtime, "heater_bed")
        chamber = _status(
            self._lookup("heater_generic chamber"), eventtime, "heater_generic chamber"
        )
        macro = self._lookup("gcode_macro M106")
        variables = getattr(macro, "variables", None)
        if not isinstance(variables, dict) or "filter_minimum" not in variables:
            raise CheckpointError("gcode_macro M106.filter_minimum is unavailable")
        base_position = getattr(move_object, "base_position", None)
        if base_position is None:
            raise CheckpointError("gcode_move.base_position is unavailable")
        snapshot = {
            "captured_after_line": int(completed_lines),
            "gcode_move": {
                "absolute_coordinates": move.get("absolute_coordinates"),
                "absolute_extrude": move.get("absolute_extrude"),
                "base_position": _coordinate_dict(
                    base_position, "gcode_move.base_position"
                ),
                "extrude_factor": float(move.get("extrude_factor")) * 100.0,
                "feed_rate": move.get("speed"),
                "gcode_position": _coordinate_dict(
                    move.get("gcode_position"), "gcode_move.gcode_position"
                ),
                "homing_origin": _coordinate_dict(
                    move.get("homing_origin"), "gcode_move.homing_origin"
                ),
                "position": _coordinate_dict(move.get("position"), "gcode_move.position"),
                # gcode_move exposes M220 as a 0..n multiplier while the
                # command accepts a percentage.  Store the command-domain
                # value so the recovery file can restore it without relying
                # on implementation details from a new Klippy process.
                "speed_factor": float(move.get("speed_factor")) * 100.0,
            },
            "toolhead": {
                "active_extruder": toolhead.get("extruder"),
                "max_accel": toolhead.get("max_accel"),
                "max_accel_to_decel": toolhead.get("max_accel_to_decel"),
                "max_velocity": toolhead.get("max_velocity"),
                "square_corner_velocity": toolhead.get("square_corner_velocity"),
            },
            "extruder": {
                "pressure_advance": extruder.get("pressure_advance"),
                "smooth_time": extruder.get("smooth_time"),
            },
            # Fan callbacks are lookahead-timed.  These values are refreshed
            # inside our candidate callback after earlier callbacks attached
            # to the same move have applied, while every other field remains
            # frozen at the end of this source line's macro expansion.
            "fans": self._capture_fans(eventtime),
            "heaters": {
                "bed": bed.get("target"),
                "chamber": chamber.get("target"),
                "extruder": extruder.get("target"),
            },
            "macros": {"M106": {"filter_minimum": variables["filter_minimum"]}},
        }
        return _validate_runtime_snapshot(snapshot, int(completed_lines))

    def _estimated_print_time(self):
        toolhead = self.printer.lookup_object("toolhead")
        eventtime = self.reactor.monotonic()
        return float(toolhead.mcu.estimated_print_time(eventtime))

    def _motion_scheduled(self, generation, completed_lines, runtime, move_end):
        self.callback_pending = False
        if not self.active or generation != self.generation:
            return
        if completed_lines <= self.last_published_line:
            return
        try:
            eventtime = self.reactor.monotonic()
            runtime = _clone(runtime)
            runtime["fans"] = self._capture_fans(eventtime)
            runtime = _validate_runtime_snapshot(runtime, completed_lines)
            delay = max(0.0, float(move_end) - self._estimated_print_time())
            # The callback identifies when all motion associated with this line has
            # been scheduled.  The durability worker waits off-reactor until that
            # MCU print time has passed before publishing it.
            if self._queue(
                "active", completed_lines, runtime=runtime, delay=delay + 0.050
            ):
                self.last_published_line = completed_lines
        except Exception:  # noqa: BLE001
            # Log callback failures and disable recovery through the shared handler.
            self._disable_after_error("physical-state capture")

    def _schedule_physical_checkpoint(self, completed_lines, runtime):
        if self.callback_pending:
            return
        self.callback_pending = True
        generation = self.generation
        toolhead = self.printer.lookup_object("toolhead")
        toolhead.register_lookahead_callback(
            lambda move_end: self._motion_scheduled(
                generation, int(completed_lines), runtime, move_end
            )
        )

    def start(self, file_object, file_position, completed_lines):
        if not self.enabled or file_object is None:
            self.active = False
            return False
        if is_recovery_path(file_object.name, self.gcode_root):
            # Most importantly: never create, truncate, or update either
            # checkpoint while printing a generated .plr file.
            self.active = False
            self.identity = None
            return False
        try:
            identity = source_identity(file_object)
            if not _is_within(identity["path"], self.gcode_root):
                raise CheckpointError("source is outside the virtual SD root")
            if self.active:
                if not identities_match(self.identity, identity):
                    self.identity = identity
                    self._commit_sync(
                        "invalid", completed_lines, reason="source changed"
                    )
                    self.active = False
                    return False
                if int(completed_lines) != self.last_line:
                    self._commit_sync(
                        "invalid",
                        completed_lines,
                        reason="line count changed while paused",
                    )
                    self.active = False
                    return False
                return True
            # This is a new print, before its first command.  It is safe here
            # to wait for a preceding terminal job and synchronously invalidate
            # stale recovery.  Pause/resume took the branch above and never
            # waits on eMMC durability.
            if not self.writer.flush():
                raise CheckpointError("checkpoint writer did not flush")
            if self.writer.get_error() is not None:
                raise CheckpointError("checkpoint writer previously failed")
            self.identity = identity
            if file_position != 0 or completed_lines != 0:
                self._commit_sync(
                    "invalid",
                    completed_lines,
                    reason="non-zero start without an in-memory checkpoint",
                )
                self.active = False
                return False
            self.last_line = 0
            self.last_published_line = 0
            self.generation += 1
            self.callback_pending = False
            self.active = True
            # An active line-zero document is internally contradictory because
            # there is nothing to resume.  Publish an explicit non-resumable
            # state until a physically completed positive candidate exists.
            self._commit_sync(
                "not_ready", 0, reason="no durable print line yet"
            )
            return True
        except Exception:  # noqa: BLE001
            # Log host failures and disable recovery through the shared handler.
            self._disable_after_error("start")
            return False

    def advance(self, completed_lines):
        if not self.active:
            return
        try:
            if self.writer.get_error() is not None:
                self.active = False
                return
            completed_lines = int(completed_lines)
            if completed_lines != self.last_line + 1:
                self._terminal(
                    "invalid", completed_lines, "non-monotonic line count"
                )
                self.active = False
                return
            self.last_line = completed_lines
            if completed_lines % self.save_every_n_lines == 0:
                runtime = self._capture_runtime(completed_lines)
                self._schedule_physical_checkpoint(completed_lines, runtime)
        except Exception:  # noqa: BLE001
            # Log host failures and disable recovery through the shared handler.
            self._disable_after_error("update")

    def complete(self, completed_lines):
        if not self.active:
            return
        try:
            self.last_line = int(completed_lines)
            generation = self.generation
            line = self.last_line
            identity = dict(self.identity)

            def finish_after_moves(_move_end):
                if generation != self.generation:
                    return
                # EOF has no remaining source to resume.  Once lookahead has
                # accepted the final queue, make that terminal decision
                # durable immediately rather than allowing an older active
                # checkpoint to survive an in-flight fsync.
                self.writer.commit_terminal("complete", line, identity)

            self.printer.lookup_object("toolhead").register_lookahead_callback(
                finish_after_moves
            )
        except Exception:  # noqa: BLE001
            # Log host failures and disable recovery through the shared handler.
            self._disable_after_error("completion")
        finally:
            self.active = False

    def cancel(self, completed_lines):
        if not self.active:
            return
        try:
            self.last_line = int(completed_lines)
            self._terminal("cancelled", self.last_line)
        except Exception:  # noqa: BLE001
            # Log host failures and disable recovery through the shared handler.
            self._disable_after_error("cancellation")
        finally:
            self.active = False

    def invalidate(self, completed_lines, reason):
        if not self.active:
            return
        try:
            self.last_line = int(completed_lines)
            self._terminal("invalid", self.last_line, str(reason))
        except Exception:  # noqa: BLE001
            # Log host failures and disable recovery through the shared handler.
            self._disable_after_error("invalidation")
        finally:
            self.active = False

    def reset(self):
        self.active = False
        self.identity = None
        self.last_line = 0
        self.last_published_line = 0
        self.generation += 1
        self.callback_pending = False
