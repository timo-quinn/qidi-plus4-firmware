from __future__ import annotations

import argparse
import ast
import json
import sys
import threading
from pathlib import Path
from types import SimpleNamespace

import pytest

REPO_ROOT = Path(__file__).resolve().parents[1]
PLR_DIR = REPO_ROOT / "plr-hardening"
if str(PLR_DIR) not in sys.path:
    sys.path.insert(0, str(PLR_DIR))

import generate_recovery
import install
import patch_virtual_sdcard
import plr_checkpoint


@pytest.fixture(autouse=True)
def isolated_installer_home(
    tmp_path: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    home_root = tmp_path / "home"
    home_root.mkdir(exist_ok=True)
    monkeypatch.setattr(install, "ACCOUNT_HOME_ROOT", str(home_root))

    def fake_passwd_lookup(account: str) -> SimpleNamespace:
        account_home = home_root / account
        owner_source = account_home if account_home.exists() else home_root
        owner = owner_source.stat()
        return SimpleNamespace(
            pw_name=account,
            pw_dir=str(account_home),
            pw_uid=owner.st_uid,
            pw_gid=owner.st_gid,
        )

    monkeypatch.setattr(install, "PASSWD_LOOKUP", fake_passwd_lookup)


def vendor_virtual_sdcard_fixture() -> str:
    return '''import os, sys, logging, io

class VirtualSD:
    def __init__(self, config):
        self.sdcard_dirname = config.get('path')
        # power lose resume
        self.lines = 0
        self.save_every_n_lines = 50
        self.plr_enabled = config.getboolean('plr_enabled', True)

    def do_cancel(self):
        if self.current_file is not None:
            self.do_pause()
            self.current_file.close()
            self.current_file = None
            self.lines = 0
            self.print_stats.note_cancel()
        self.file_position = self.file_size = 0

    def _reset_file(self):
        if self.current_file is not None:
            self.do_pause()
            self.current_file.close()
            self.current_file = None
        self.file_position = self.file_size = 0

    def work_handler(self, eventtime):
        lines = []
        # Recreate the file to balance the wear on the eMMC
        if self.plr_enabled:
            file_path = "/home/mks/scripts/plr/plr_record"
            if os.path.exists(file_path):
                os.remove(file_path)
            plr_file = open(file_path, 'w', buffering=1)
        while not self.must_pause_work:
            if not lines:
                try:
                    data = self.current_file.read(8192)
                except:
                    if self.plr_enabled:
                        plr_file.close()
                    logging.exception("virtual_sdcard read")
                    break
                if not data:
                    # End of file
                    self.lines = 0
                    if self.plr_enabled:
                        plr_file.close()
                    self.current_file.close()
                    self.current_file = None
                    logging.info("Finished SD card print")
                    self.gcode.respond_raw("Done printing file")
                    break
                lines = [data]
            line = lines.pop()
            try:
                self.lines += 1
                if self.lines % self.save_every_n_lines == 0 and self.plr_enabled:
                    plr_file.seek(0)
                    plr_file.write(str(self.lines))
                    plr_file.truncate()
                self.gcode.run_script(line)
            except Exception:
                break
            if self.next_file_position != next_file_position:
                try:
                    self.current_file.seek(self.file_position)
                except Exception:
                    break
        logging.info("Exiting SD card print (position %d)", self.file_position)
        if self.plr_enabled:
            plr_file.close()
        self.work_timer = None
'''


class FakeMcu:
    def __init__(self) -> None:
        self.estimated = 100.0

    def estimated_print_time(self, _eventtime: float) -> float:
        return self.estimated


class FakeToolhead:
    def __init__(self) -> None:
        self.mcu = FakeMcu()
        self.callbacks: list[object] = []
        self.status: dict[str, object] = {
            "extruder": "extruder",
            "max_accel": 3000.0,
            "max_accel_to_decel": 1500.0,
            "max_velocity": 600.0,
            "square_corner_velocity": 8.0,
        }

    def register_lookahead_callback(self, callback: object) -> None:
        self.callbacks.append(callback)

    def fire(self, move_end: float) -> None:
        callback = self.callbacks.pop(0)
        callback(move_end)  # type: ignore[operator]

    def get_status(self, _eventtime: float) -> dict[str, object]:
        return dict(self.status)


class FakeStatusObject:
    def __init__(self, status: dict[str, object]) -> None:
        self.status = status

    def get_status(self, _eventtime: float) -> dict[str, object]:
        return dict(self.status)


class FakeGcodeMove(FakeStatusObject):
    def __init__(self) -> None:
        self.base_position = [0.0, 0.0, 0.0, 0.0]
        super().__init__(
            {
                "absolute_coordinates": True,
                "absolute_extrude": False,
                "extrude_factor": 1.0,
                "gcode_position": [10.0, 20.0, 1.0, 5.0],
                "homing_origin": [0.0, 0.0, 0.0, 0.0],
                "position": [10.0, 20.0, 1.0, 5.0],
                "speed": 1800.0,
                # Klipper exposes this as a multiplier; the checkpoint stores
                # the corresponding M220 percentage.
                "speed_factor": 1.0,
            }
        )


class FakeReactor:
    def monotonic(self) -> float:
        return 1.0


class FakePrinter:
    def __init__(self) -> None:
        self.reactor = FakeReactor()
        self.toolhead = FakeToolhead()
        self.gcode_move = FakeGcodeMove()
        self.objects: dict[str, object] = {
            "toolhead": self.toolhead,
            "gcode_move": self.gcode_move,
            "extruder": FakeStatusObject(
                {
                    "pressure_advance": 0.04,
                    "smooth_time": 0.04,
                    "target": 220.0,
                }
            ),
            "heater_bed": FakeStatusObject({"target": 55.0}),
            "heater_generic chamber": FakeStatusObject({"target": 0.0}),
            "fan_generic cooling_fan": FakeStatusObject({"speed": 0.0}),
            "fan_generic auxiliary_cooling_fan": FakeStatusObject({"speed": 0.0}),
            "fan_generic chamber_circulation_fan": FakeStatusObject(
                {"speed": 0.0}
            ),
            "gcode_macro M106": SimpleNamespace(
                variables={"filter_minimum": 0.2}
            ),
        }

    def get_reactor(self) -> FakeReactor:
        return self.reactor

    def lookup_object(self, name: str, default: object = None) -> object:
        return self.objects.get(name, default)


class FakeConfig:
    def __init__(self, printer: FakePrinter) -> None:
        self.printer = printer

    def get_printer(self) -> FakePrinter:
        return self.printer

    def getboolean(self, _name: str, default: bool) -> bool:
        return default

    def get(self, _name: str, default: str) -> str:
        return default


def identity() -> dict[str, object]:
    return {
        "path": "/gcodes/job.gcode",
        "device": 1,
        "inode": 2,
        "size": 3,
        "mtime_ns": 4,
        "sample_sha256": "0" * 64,
    }


def runtime_snapshot(
    line: int,
    *,
    position: tuple[float, float, float, float] = (11.0, 22.0, 1.0, 2.0),
    gcode_position: tuple[float, float, float, float] | None = None,
    base_position: tuple[float, float, float, float] | None = None,
    absolute_coordinates: bool = True,
    absolute_extrude: bool = True,
    speed_factor: float = 100.0,
    extrude_factor: float = 100.0,
    feed_rate: float = 2400.0,
    fans: tuple[float, float, float] = (0.0, 100.0, 0.0),
) -> dict[str, object]:
    if gcode_position is None:
        gcode_position = position
    if base_position is None:
        factor = extrude_factor / 100.0
        base_position = (
            position[0] - gcode_position[0],
            position[1] - gcode_position[1],
            position[2] - gcode_position[2],
            position[3] - gcode_position[3] * factor,
        )
    axes = "XYZE"

    def axis_dict(values: tuple[float, float, float, float]) -> dict[str, float]:
        return dict(zip(axes, values))
    return {
        "captured_after_line": line,
        "gcode_move": {
            "absolute_coordinates": absolute_coordinates,
            "absolute_extrude": absolute_extrude,
            "base_position": axis_dict(base_position),
            "extrude_factor": extrude_factor,
            "feed_rate": feed_rate,
            "gcode_position": axis_dict(gcode_position),
            "homing_origin": axis_dict((0.25, -0.5, 0.1, 0.0)),
            "position": axis_dict(position),
            "speed_factor": speed_factor,
        },
        "toolhead": {
            "active_extruder": "extruder",
            "max_accel": 3210.0,
            "max_accel_to_decel": 1605.0,
            "max_velocity": 555.0,
            "square_corner_velocity": 7.5,
        },
        "extruder": {"pressure_advance": 0.045, "smooth_time": 0.035},
        "fans": {"P0": fans[0], "P2": fans[1], "P3": fans[2]},
        "heaters": {"bed": 55.0, "chamber": 35.0, "extruder": 220.0},
        "macros": {"M106": {"filter_minimum": 0.2}},
    }


def test_source_identity_preserves_caller_owned_file(tmp_path: Path) -> None:
    source = tmp_path / "print.gcode"
    source.write_bytes(b"G1 X10\n" * 20000)
    expected = plr_checkpoint.source_identity(source)

    with source.open("rb") as stream:
        stream.seek(13)
        assert plr_checkpoint.source_identity(stream) == expected
        assert not stream.closed
        assert stream.tell() == 13
        assert stream.read(1) == source.read_bytes()[13:14]


def test_runtime_python_parses_as_python_37() -> None:
    for name in (
        "plr_checkpoint.py",
        "generate_recovery.py",
        "patch_virtual_sdcard.py",
        "install.py",
    ):
        ast.parse(
            (PLR_DIR / name).read_text(encoding="utf-8"),
            filename=name,
            feature_version=(3, 7),
        )


def test_patcher_is_strict_and_idempotent() -> None:
    source = vendor_virtual_sdcard_fixture()
    patched, changed = patch_virtual_sdcard.patch_source(source)

    assert changed is True
    assert "PLR_HARDENING_V1" in patched
    assert "plr_file" not in patched
    assert patched.index("self.gcode.run_script(line)") < patched.index(
        "self.plr_tracker.advance(self.lines)"
    )
    assert "virtual SD file position changed" in patched
    assert patch_virtual_sdcard.patch_source(patched) == (patched, False)

    with pytest.raises(patch_virtual_sdcard.PatchError, match="anchor occurred 0 times"):
        patch_virtual_sdcard.patch_source(source.replace("# power lose resume", "# changed"))


def test_line_zero_checkpoint_is_explicitly_not_resumable(tmp_path: Path) -> None:
    root = tmp_path / "gcodes"
    root.mkdir()
    scripts = tmp_path / "scripts"
    scripts.mkdir()
    source = root / "job.gcode"
    source.write_text("G90\n" * 100, encoding="utf-8")
    checkpoint = scripts / "checkpoint.json"
    record = scripts / "record"
    printer = FakePrinter()
    tracker = plr_checkpoint.CheckpointTracker(
        FakeConfig(printer),
        str(root),
        50,
        checkpoint_path=str(checkpoint),
        record_path=str(record),
    )

    with source.open("rb") as source_file:
        assert tracker.start(source_file, 0, 0) is True

    document = json.loads(checkpoint.read_text(encoding="utf-8"))
    assert document["state"] == "not_ready"
    assert document["line"] == 0
    assert record.read_text(encoding="ascii") == "0\n"
    with pytest.raises(plr_checkpoint.CheckpointError, match="not resumable"):
        plr_checkpoint.load_checkpoint(str(checkpoint))


def test_checkpoint_is_published_only_after_motion_time(tmp_path: Path) -> None:
    root = tmp_path / "gcodes"
    root.mkdir()
    scripts = tmp_path / "scripts"
    scripts.mkdir()
    source = root / "job.gcode"
    source.write_text("G1 X1\n" * 100, encoding="utf-8")
    checkpoint = scripts / "checkpoint.json"
    printer = FakePrinter()
    tracker = plr_checkpoint.CheckpointTracker(
        FakeConfig(printer),
        str(root),
        50,
        checkpoint_path=str(checkpoint),
        record_path=str(scripts / "record"),
    )
    with source.open("rb") as source_file:
        assert tracker.start(source_file, 0, 0)
        for line in range(1, 51):
            tracker.advance(line)
    assert json.loads(checkpoint.read_text(encoding="utf-8"))["state"] == "not_ready"
    assert len(printer.toolhead.callbacks) == 1

    printer.toolhead.fire(100.0)
    assert tracker.writer.flush(timeout=2.0)
    loaded = plr_checkpoint.load_checkpoint(str(checkpoint))
    assert loaded["line"] == 50
    assert loaded["runtime"]["captured_after_line"] == 50


def test_checkpoint_freezes_box_macro_and_ui_runtime_state(tmp_path: Path) -> None:
    root = tmp_path / "gcodes"
    root.mkdir()
    scripts = tmp_path / "scripts"
    scripts.mkdir()
    source = root / "job.gcode"
    source.write_text("T2\nG1 X1\n", encoding="utf-8")
    checkpoint = scripts / "checkpoint.json"
    printer = FakePrinter()
    tracker = plr_checkpoint.CheckpointTracker(
        FakeConfig(printer),
        str(root),
        1,
        checkpoint_path=str(checkpoint),
        record_path=str(scripts / "record"),
    )
    with source.open("rb") as source_file:
        assert tracker.start(source_file, 0, 0)
        # Model the authoritative state after T2 expanded through the Box
        # macros plus concurrent UI overrides.  None of this is inferable from
        # the raw source line itself.
        printer.gcode_move.base_position = [10.0, 10.0, 0.5, 12.5]
        printer.gcode_move.status.update(
            {
                "absolute_coordinates": False,
                "absolute_extrude": True,
                "extrude_factor": 0.95,
                "gcode_position": [90.0, 100.0, 11.5, 50.0],
                "homing_origin": [0.25, -0.5, 0.1, 0.0],
                "position": [100.0, 110.0, 12.0, 60.0],
                "speed": 4321.0,
                "speed_factor": 0.75,
            }
        )
        printer.toolhead.status.update(
            {
                "max_accel": 4321.0,
                "max_accel_to_decel": 2100.0,
                "max_velocity": 500.0,
                "square_corner_velocity": 6.5,
            }
        )
        extruder = printer.objects["extruder"]
        assert isinstance(extruder, FakeStatusObject)
        extruder.status.update(
            {"pressure_advance": 0.055, "smooth_time": 0.03, "target": 245.0}
        )
        bed = printer.objects["heater_bed"]
        chamber = printer.objects["heater_generic chamber"]
        assert isinstance(bed, FakeStatusObject)
        assert isinstance(chamber, FakeStatusObject)
        bed.status["target"] = 70.0
        chamber.status["target"] = 45.0
        macro = printer.objects["gcode_macro M106"]
        macro.variables["filter_minimum"] = 0.2  # type: ignore[attr-defined]
        tracker.advance(1)

        # Later lines/UI activity must not rewrite the candidate's frozen
        # motion, heater, macro, velocity, or pressure-advance state.
        printer.gcode_move.status["speed"] = 9999.0
        extruder.status["target"] = 300.0
        bed.status["target"] = 100.0
        macro.variables["filter_minimum"] = 0.0  # type: ignore[attr-defined]
        for name, speed in (
            ("fan_generic cooling_fan", 0.25),
            ("fan_generic auxiliary_cooling_fan", 0.0),
            ("fan_generic chamber_circulation_fan", 0.8),
        ):
            fan = printer.objects[name]
            assert isinstance(fan, FakeStatusObject)
            fan.status["speed"] = speed
        printer.toolhead.fire(100.0)
    assert tracker.writer.flush(timeout=2.0)

    runtime = plr_checkpoint.load_checkpoint(str(checkpoint))["runtime"]
    assert runtime["gcode_move"]["position"] == {
        "X": 100.0,
        "Y": 110.0,
        "Z": 12.0,
        "E": 60.0,
    }
    assert runtime["gcode_move"]["feed_rate"] == 4321.0
    assert runtime["gcode_move"]["speed_factor"] == 75.0
    assert runtime["heaters"] == {"bed": 70.0, "chamber": 45.0, "extruder": 245.0}
    assert runtime["toolhead"]["max_accel"] == 4321.0
    assert runtime["extruder"]["pressure_advance"] == 0.055
    assert runtime["macros"]["M106"]["filter_minimum"] == 0.2
    assert runtime["fans"] == {"P0": 63.75, "P2": 0.0, "P3": 204.0}


def test_recovery_file_never_touches_checkpoint_files(tmp_path: Path) -> None:
    root = tmp_path / "gcodes"
    recovery_dir = root / ".plr"
    recovery_dir.mkdir(parents=True)
    scripts = tmp_path / "scripts"
    scripts.mkdir()
    source = recovery_dir / "plr.gcode"
    source.write_text("G90\n", encoding="utf-8")
    checkpoint = scripts / "checkpoint.json"
    record = scripts / "record"
    checkpoint.write_bytes(b"checkpoint-sentinel")
    record.write_bytes(b"record-sentinel")
    tracker = plr_checkpoint.CheckpointTracker(
        FakeConfig(FakePrinter()),
        str(root),
        50,
        checkpoint_path=str(checkpoint),
        record_path=str(record),
    )

    with source.open("rb") as source_file:
        assert tracker.start(source_file, 0, 0) is False

    assert checkpoint.read_bytes() == b"checkpoint-sentinel"
    assert record.read_bytes() == b"record-sentinel"


def test_checkpoint_writer_coalesces_active_work(monkeypatch: pytest.MonkeyPatch, tmp_path: Path) -> None:
    entered = threading.Event()
    release = threading.Event()
    calls: list[tuple[str, int]] = []

    def slow_write(_record: str, _checkpoint: str, job: dict[str, object]) -> None:
        calls.append((str(job["state"]), int(job["line"])))
        if len(calls) == 1:
            entered.set()
            assert release.wait(2.0)

    monkeypatch.setattr(plr_checkpoint, "_write_checkpoint_files", slow_write)
    writer = plr_checkpoint._CheckpointWriter(
        str(tmp_path / "record"), str(tmp_path / "checkpoint")
    )
    assert writer.enqueue("active", 50, identity())
    assert entered.wait(1.0)
    assert writer.enqueue("active", 100, identity())
    assert writer.enqueue("active", 150, identity())
    release.set()
    assert writer.flush(2.0)

    assert calls == [("active", 50), ("active", 150)]
    assert writer.coalesced == 1


def test_terminal_replaces_delayed_active_before_io(monkeypatch: pytest.MonkeyPatch, tmp_path: Path) -> None:
    calls: list[tuple[str, int]] = []

    def record_write(_record: str, _checkpoint: str, job: dict[str, object]) -> None:
        calls.append((str(job["state"]), int(job["line"])))

    monkeypatch.setattr(plr_checkpoint, "_write_checkpoint_files", record_write)
    writer = plr_checkpoint._CheckpointWriter(
        str(tmp_path / "record"), str(tmp_path / "checkpoint")
    )
    assert writer.enqueue("active", 50, identity(), delay=1.0)
    assert writer.enqueue("cancelled", 61, identity())
    assert writer.flush(2.0)

    assert calls == [("cancelled", 61)]


def test_terminal_supersedes_active_checkpoint_already_inside_slow_fsync(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    entered = threading.Event()
    release = threading.Event()
    original_write = plr_checkpoint._write_checkpoint_files

    def slow_write(record: str, checkpoint: str, job: dict[str, object]) -> None:
        if job["state"] == "active":
            entered.set()
            assert release.wait(2.0)
        original_write(record, checkpoint, job)

    monkeypatch.setattr(plr_checkpoint, "_write_checkpoint_files", slow_write)
    checkpoint = tmp_path / "checkpoint.json"
    writer = plr_checkpoint._CheckpointWriter(str(tmp_path / "record"), str(checkpoint))
    assert writer.enqueue("active", 50, identity(), runtime=runtime_snapshot(50))
    assert entered.wait(1.0)
    result: list[bool] = []
    terminal = threading.Thread(
        target=lambda: result.append(
            writer.commit_terminal("cancelled", 51, identity())
        )
    )
    terminal.start()
    release.set()
    terminal.join(2.0)

    assert result == [True]
    document = json.loads(checkpoint.read_text(encoding="utf-8"))
    assert document["state"] == "cancelled"
    assert document["line"] == 51
    with pytest.raises(plr_checkpoint.CheckpointError, match="not resumable"):
        plr_checkpoint.load_checkpoint(str(checkpoint))


def test_disable_cancels_delayed_active_checkpoint_without_resurrection(
    tmp_path: Path,
) -> None:
    root = tmp_path / "gcodes"
    root.mkdir()
    checkpoint = tmp_path / "checkpoint.json"
    record = tmp_path / "record"
    checkpoint.write_text("stale active", encoding="utf-8")
    tracker = plr_checkpoint.CheckpointTracker(
        FakeConfig(FakePrinter()),
        str(root),
        50,
        checkpoint_path=str(checkpoint),
        record_path=str(record),
    )
    tracker.identity = identity()
    tracker.active = True
    assert tracker.writer.enqueue(
        "active", 50, tracker.identity, runtime=runtime_snapshot(50), delay=1.0
    )

    tracker._disable_after_error("test failure")

    assert tracker.writer.flush(2.0) is False
    assert not checkpoint.exists()
    assert record.read_text(encoding="ascii") == "0\n"


def test_active_source_mismatch_supersedes_checkpoint_inside_slow_fsync(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    entered = threading.Event()
    release = threading.Event()
    original_write = plr_checkpoint._write_checkpoint_files

    def slow_write(record: str, checkpoint: str, job: dict[str, object]) -> None:
        if job["state"] == "active":
            entered.set()
            assert release.wait(2.0)
        original_write(record, checkpoint, job)

    monkeypatch.setattr(plr_checkpoint, "_write_checkpoint_files", slow_write)
    root = tmp_path / "gcodes"
    root.mkdir()
    first = root / "first.gcode"
    second = root / "second.gcode"
    first.write_text("G1 X1\n", encoding="utf-8")
    second.write_text("G1 X2\n", encoding="utf-8")
    checkpoint = tmp_path / "checkpoint.json"
    tracker = plr_checkpoint.CheckpointTracker(
        FakeConfig(FakePrinter()),
        str(root),
        50,
        checkpoint_path=str(checkpoint),
        record_path=str(tmp_path / "record"),
    )
    with first.open("rb") as first_file:
        assert tracker.start(first_file, 0, 0)
    assert tracker.writer.enqueue(
        "active", 50, tracker.identity, runtime=runtime_snapshot(50)
    )
    assert entered.wait(1.0)
    result: list[bool] = []

    def start_second() -> None:
        with second.open("rb") as second_file:
            result.append(tracker.start(second_file, 0, 50))

    mismatch = threading.Thread(target=start_second)
    mismatch.start()
    release.set()
    mismatch.join(2.0)

    assert result == [False]
    assert tracker.writer.flush(2.0)
    document = json.loads(checkpoint.read_text(encoding="utf-8"))
    assert document["state"] == "invalid"
    assert document["reason"] == "source changed"
    with pytest.raises(plr_checkpoint.CheckpointError, match="not resumable"):
        plr_checkpoint.load_checkpoint(str(checkpoint))


def test_writer_failure_removes_stale_authoritative_checkpoint(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    checkpoint = tmp_path / "checkpoint"
    checkpoint.write_text("stale active", encoding="utf-8")

    def fail_write(_record: str, _checkpoint: str, _job: dict[str, object]) -> None:
        raise OSError("slow eMMC failed")

    monkeypatch.setattr(plr_checkpoint, "_write_checkpoint_files", fail_write)
    writer = plr_checkpoint._CheckpointWriter(str(tmp_path / "record"), str(checkpoint))
    assert writer.enqueue("active", 50, identity())
    assert writer.flush(2.0) is False
    assert not checkpoint.exists()


def write_recovery_case(
    tmp_path: Path,
    prefix: list[str],
    tail: list[str],
    runtime: dict[str, object] | None = None,
) -> tuple[Path, Path, dict[str, object]]:
    gcode_root = tmp_path / "gcodes"
    (gcode_root / ".plr").mkdir(parents=True)
    source = gcode_root / "job.gcode"
    source.write_text("\n".join(prefix + tail) + "\n", encoding="utf-8")
    checkpoint = tmp_path / "checkpoint.json"
    checkpoint.write_text(
        json.dumps(
            {
                "version": plr_checkpoint.SCHEMA_VERSION,
                "state": "active",
                "line": len(prefix),
                "source": plr_checkpoint.source_identity(str(source)),
                "runtime": runtime or runtime_snapshot(len(prefix)),
            }
        )
        + "\n",
        encoding="utf-8",
    )
    output = gcode_root / ".plr" / "plr.gcode"
    result = generate_recovery.generate(str(checkpoint), str(gcode_root), str(output))
    return output, source, result


def test_generator_restores_authoritative_live_snapshot_and_exact_tail(
    tmp_path: Path,
) -> None:
    prefix = [
        "G90",
        "M82",
        "M220 S10",
        "M221 S20",
        "M106 S255",
        "T2",
        "SET_GCODE_OFFSET X_ADJUST=999",
        ";Z:11.5",
    ]
    tail = ["G1 X12 Y23 E3", "M106 P2 S0", "EXCLUDE_OBJECT_END NAME=part"]
    runtime = runtime_snapshot(
        len(prefix),
        position=(100.0, 110.0, 12.0, 60.0),
        gcode_position=(90.0, 100.0, 11.5, 50.0),
        base_position=(10.0, 10.0, 0.5, 12.5),
        absolute_coordinates=False,
        absolute_extrude=True,
        speed_factor=75.0,
        extrude_factor=95.0,
        feed_rate=4321.0,
        fans=(63.75, 0.0, 204.0),
    )
    runtime["heaters"] = {"bed": 70.0, "chamber": 45.0, "extruder": 245.0}
    output, _source, result = write_recovery_case(
        tmp_path, prefix, tail, runtime
    )
    text = output.read_text(encoding="utf-8")
    prologue, continuation = text.split(generate_recovery.CONTINUATION_MARKER + "\n", 1)

    assert prologue.count("SET_FAN_SPEED FAN=") == 3
    assert "SET_FAN_SPEED FAN=cooling_fan SPEED=0.25" in prologue
    assert "SET_FAN_SPEED FAN=auxiliary_cooling_fan SPEED=0" in prologue
    assert "SET_FAN_SPEED FAN=chamber_circulation_fan SPEED=0.8" in prologue
    assert "M140 S70" in prologue
    assert "M104 S245" in prologue
    assert "M141 S45" in prologue
    assert "M190 S70" in prologue
    assert "M191 S45" in prologue
    assert "SET_KINEMATIC_POSITION Z=12" in prologue
    assert prologue.count("G28 X Y") == 2
    assert "SET_GCODE_OFFSET X=0 Y=0 Z=0 E=0" in prologue
    assert "G1 X100 Y110 F12000" in prologue
    assert "G1 Z12 F600" in prologue
    assert (
        "SET_VELOCITY_LIMIT VELOCITY=555 ACCEL=3210 "
        "ACCEL_TO_DECEL=1605 SQUARE_CORNER_VELOCITY=7.5"
    ) in prologue
    assert "SET_PRESSURE_ADVANCE ADVANCE=0.045 SMOOTH_TIME=0.035" in prologue
    assert "M220 S75" in prologue
    assert "M221 S95" in prologue
    assert "SET_GCODE_OFFSET X=0.25 Y=-0.5 Z=0.1 E=0" in prologue
    assert "G92 X90 Y100 Z11.5 E50" in prologue
    assert prologue.rstrip().endswith("M82\nG91\nG1 F4321\nENABLE_ALL_SENSOR")
    assert "\nT2\n" not in prologue
    assert "\nM106 S255\n" not in prologue
    assert continuation == "\n".join(tail) + "\n"
    assert result["schema"] == "qidi-plr-recovery/v2"
    assert result["fan_state"] == {"P0": 63.75, "P2": 0.0, "P3": 204.0}


@pytest.mark.parametrize(
    ("absolute_coordinates", "absolute_extrude", "coordinate_command", "extrusion_command"),
    [
        (True, True, "G90", "M82"),
        (True, False, "G90", "M83"),
        (False, True, "G91", "M82"),
        (False, False, "G91", "M83"),
    ],
)
def test_generator_restores_all_coordinate_and_extrusion_mode_combinations(
    tmp_path: Path,
    absolute_coordinates: bool,
    absolute_extrude: bool,
    coordinate_command: str,
    extrusion_command: str,
) -> None:
    prefix = ["G91", "M83", "G1 X999 E999", ";Z:1"]
    runtime = runtime_snapshot(
        len(prefix),
        absolute_coordinates=absolute_coordinates,
        absolute_extrude=absolute_extrude,
    )
    output, _source, _result = write_recovery_case(
        tmp_path, prefix, ["G1 X1"], runtime
    )
    prologue = output.read_text(encoding="utf-8").split(
        generate_recovery.CONTINUATION_MARKER, 1
    )[0]
    final_lines = prologue.rstrip().splitlines()[-4:]
    assert final_lines[0] == extrusion_command
    assert final_lines[1] == coordinate_command
    assert final_lines[2] == "G1 F2400"
    assert final_lines[3] == "ENABLE_ALL_SENSOR"


def test_generator_uses_checkpoint_z_not_layer_z_during_zhop(tmp_path: Path) -> None:
    prefix = [
        "G90",
        "M83",
        "G92 E0",
        "G1 X10 Y20 Z1 E1 F1800",
        ";Z:1",
        "G1 Z1.4 F900",
    ]
    runtime = runtime_snapshot(
        len(prefix),
        position=(10.0, 20.0, 1.4, 1.0),
        gcode_position=(10.0, 20.0, 1.4, 1.0),
    )
    output, _source, result = write_recovery_case(
        tmp_path, prefix, ["G1 Z1 F900"], runtime
    )
    prologue = output.read_text(encoding="utf-8").split(
        generate_recovery.CONTINUATION_MARKER, 1
    )[0]

    assert "SET_KINEMATIC_POSITION Z=1.4" in prologue
    assert "G1 Z1.4 F600" in prologue
    assert result["z"] == 1.4
    assert result["layer_z"] == 1.0


def test_generator_restores_modal_feed_and_nondefault_factors(tmp_path: Path) -> None:
    prefix = [
        "G90",
        "M83",
        "G92 E0",
        "M220 S75",
        "M221 S95",
        "G1 X10 Y20 Z1 E1 F4321",
        ";Z:1",
    ]
    tail = ["G1 X11 Y21 E1"]
    runtime = runtime_snapshot(
        len(prefix), speed_factor=75.0, extrude_factor=95.0, feed_rate=4321.0
    )
    output, _source, _result = write_recovery_case(
        tmp_path, prefix, tail, runtime
    )
    prologue, continuation = output.read_text(encoding="utf-8").split(
        generate_recovery.CONTINUATION_MARKER + "\n", 1
    )

    assert "M220 S75" in prologue
    assert "M221 S95" in prologue
    assert prologue.rstrip().endswith("G1 F4321\nENABLE_ALL_SENSOR")
    assert continuation.startswith("G1 X11 Y21 E1")


@pytest.mark.parametrize(
    ("case", "match"),
    [
        ("version", "unsupported checkpoint version"),
        ("missing_runtime", "checkpoint root fields are invalid"),
        ("line_mismatch", "runtime line does not match"),
        ("nonfinite", "position.X is outside"),
        ("inconsistent", "X coordinate mapping is inconsistent"),
        ("missing_macro", "macros.M106 fields are invalid"),
        ("source_extra", "source identity fields are invalid"),
    ],
)
def test_generator_fails_closed_on_malformed_runtime_snapshot(
    tmp_path: Path, case: str, match: str
) -> None:
    prefix = ["G90", "G1 X10 Y20 Z1 E1 F1800", ";Z:1"]
    gcode_root = tmp_path / "gcodes"
    (gcode_root / ".plr").mkdir(parents=True)
    source = gcode_root / "job.gcode"
    source.write_text("\n".join(prefix + ["G1 X11"]) + "\n", encoding="utf-8")
    document: dict[str, object] = {
        "version": plr_checkpoint.SCHEMA_VERSION,
        "state": "active",
        "line": len(prefix),
        "source": plr_checkpoint.source_identity(str(source)),
        "runtime": runtime_snapshot(len(prefix)),
    }
    if case == "version":
        document["version"] = 1
    elif case == "missing_runtime":
        document.pop("runtime")
    elif case == "line_mismatch":
        document["runtime"]["captured_after_line"] = 999  # type: ignore[index]
    elif case == "nonfinite":
        document["runtime"]["gcode_move"]["position"]["X"] = float("nan")  # type: ignore[index]
    elif case == "inconsistent":
        document["runtime"]["gcode_move"]["base_position"]["X"] = 999.0  # type: ignore[index]
    elif case == "missing_macro":
        document["runtime"]["macros"]["M106"].pop("filter_minimum")  # type: ignore[index]
    elif case == "source_extra":
        document["source"]["unexpected"] = True  # type: ignore[index]
    checkpoint = tmp_path / "checkpoint.json"
    checkpoint.write_text(json.dumps(document), encoding="utf-8")
    output = gcode_root / ".plr" / "plr.gcode"
    output.write_text("stale recovery", encoding="utf-8")

    with pytest.raises(generate_recovery.RecoveryError, match=match):
        generate_recovery.generate(str(checkpoint), str(gcode_root), str(output))
    assert not output.exists()


def test_generator_still_requires_a_completed_layer_marker(tmp_path: Path) -> None:
    prefix = ["G90", "G1 X10 Y20 Z1 E1 F1800"]
    gcode_root = tmp_path / "gcodes"
    (gcode_root / ".plr").mkdir(parents=True)
    source = gcode_root / "job.gcode"
    source.write_text("\n".join(prefix + ["G1 X11"]) + "\n", encoding="utf-8")
    checkpoint = tmp_path / "checkpoint.json"
    checkpoint.write_text(
        json.dumps(
            {
                "version": plr_checkpoint.SCHEMA_VERSION,
                "state": "active",
                "line": len(prefix),
                "source": plr_checkpoint.source_identity(str(source)),
                "runtime": runtime_snapshot(len(prefix)),
            }
        ),
        encoding="utf-8",
    )
    output = gcode_root / ".plr" / "plr.gcode"
    output.write_text("stale recovery", encoding="utf-8")

    with pytest.raises(generate_recovery.RecoveryError, match="no ;Z:"):
        generate_recovery.generate(str(checkpoint), str(gcode_root), str(output))
    assert not output.exists()


def installer_args(tmp_path: Path, *, apply: bool = False) -> argparse.Namespace:
    paths = install._canonical_layout("mks")
    home = Path(paths["home"])
    home.mkdir(parents=True, exist_ok=True)
    klipper = Path(paths["klipper_dir"])
    extras = klipper / "klippy" / "extras"
    extras.mkdir(parents=True)
    (extras / "virtual_sdcard.py").write_text(
        vendor_virtual_sdcard_fixture(), encoding="utf-8"
    )
    printer_data = Path(paths["printer_data"])
    (printer_data / "config").mkdir(parents=True)
    (printer_data / "gcodes").mkdir()
    (printer_data / "config" / "saved_variables.cfg").write_text(
        "[Variables]\n", encoding="utf-8"
    )
    scripts = Path(paths["scripts_dir"])
    scripts.mkdir(parents=True)
    python = Path(paths["python"])
    python.parent.mkdir(parents=True)
    python.write_bytes(b"python-placeholder")
    return argparse.Namespace(
        printer_user="mks",
        klipper_dir=str(klipper),
        printer_data=str(printer_data),
        scripts_dir=str(scripts),
        python=str(python),
        variables=None,
        gcode_root=None,
        checkpoint=None,
        record=None,
        output=None,
        transaction_id="pytest-transaction",
        rollback_manifest=None,
        service="klipper.service",
        apply=apply,
        klipper_stopped=apply,
        json=True,
    )


def test_manifest_installer_is_dry_run_idempotent_and_preserves_shell_command(
    tmp_path: Path,
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)

    assert plan["dry_run"] is True
    assert plan["changed"] is True
    assert plan["plr_directory_action"] == "create"
    assert plan["power_loss_resume_command"].endswith(str(Path("scripts/plr/plr.sh")))
    assert plan["update_gcode_lines_required"] is False
    wrapper = next(
        item for item in plan["descriptors"] if item["role"] == "power-loss-resume-wrapper"
    )["data"].decode("utf-8")
    assert "generate_recovery.py" in wrapper
    assert "--checkpoint" in wrapper
    assert "--gcode-root" in wrapper
    assert "--json" in wrapper
    assert "--variables" not in wrapper

    backup = install.apply_plan(plan)
    assert backup is not None
    plr_directory = Path(plan["plr_directory"])
    gcode_root = Path(args.printer_data) / "gcodes"
    assert plr_directory.is_dir()
    assert (plr_directory.stat().st_uid, plr_directory.stat().st_gid) == (
        gcode_root.stat().st_uid,
        gcode_root.stat().st_gid,
    )
    second = install.build_plan(args)
    assert second["changed"] is False
    assert second["plr_directory_action"] == "unchanged"
    assert all(action["action"] == "unchanged" for action in second["actions"])


def test_apply_requires_observably_inactive_exact_service(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    with pytest.raises(install.InstallError, match="exactly klipper.service"):
        install._check_service_stopped("custom-klipper.service")

    monkeypatch.setattr(install.shutil, "which", lambda _name: None)
    with pytest.raises(install.InstallError, match="systemctl is unavailable"):
        install._check_service_stopped("klipper.service")

    monkeypatch.setattr(install.shutil, "which", lambda _name: "/bin/systemctl")
    monkeypatch.setattr(
        install.subprocess,
        "run",
        lambda *_args, **_kwargs: SimpleNamespace(returncode=4),
    )
    with pytest.raises(install.InstallError, match="could not prove"):
        install._check_service_stopped("klipper.service")

    monkeypatch.setattr(
        install.subprocess,
        "run",
        lambda *_args, **_kwargs: SimpleNamespace(returncode=3),
    )
    assert install._check_service_stopped("klipper.service") == "inactive"


def test_installer_plan_rejects_a_service_alias(tmp_path: Path) -> None:
    args = installer_args(tmp_path)
    args.service = "klipper"

    with pytest.raises(install.InstallError, match="exactly klipper.service"):
        install.build_plan(args)


def test_installer_rollback_uses_only_validated_backup_manifest(tmp_path: Path) -> None:
    args = installer_args(tmp_path)
    virtual_sdcard = Path(args.klipper_dir) / "klippy" / "extras" / "virtual_sdcard.py"
    original = virtual_sdcard.read_bytes()
    install_plan = install.build_plan(args)
    backup_dir = install.apply_plan(install_plan)
    assert backup_dir is not None
    assert virtual_sdcard.read_bytes() != original

    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    rollback = install.build_rollback_plan(args)
    assert rollback["changed"] is True
    safety = install.apply_rollback_plan(rollback)
    assert safety is not None
    assert virtual_sdcard.read_bytes() == original
    assert not (Path(args.scripts_dir) / "generate_recovery.py").exists()
    assert not Path(install_plan["plr_directory"]).exists()

    verified = install.build_rollback_plan(args)
    assert verified["changed"] is False


def test_directory_only_install_rollback_is_changed_and_removes_created_plr(
    tmp_path: Path,
) -> None:
    args = installer_args(tmp_path)
    initial_plan = install.build_plan(args)
    install.apply_plan(initial_plan)
    plr_directory = Path(initial_plan["plr_directory"])
    plr_directory.rmdir()

    args.transaction_id = "pytest-directory-only"
    directory_plan = install.build_plan(args)
    assert directory_plan["changed"] is True
    assert all(
        item["action"] == "unchanged"
        for item in directory_plan["descriptors"]
    )
    backup_dir = install.apply_plan(directory_plan)
    assert backup_dir is not None
    assert plr_directory.is_dir()

    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-directory-only-rollback"
    rollback = install.build_rollback_plan(args)
    assert rollback["changed"] is True
    assert rollback["plr_directory_action"] == "remove-created"
    assert not [item for item in rollback["descriptors"] if item["changed"]]

    safety_dir = install.apply_rollback_plan(rollback)
    assert safety_dir is not None
    assert not plr_directory.exists()
    safety_manifest = json.loads(
        (Path(safety_dir) / "safety-manifest.json").read_text(encoding="utf-8")
    )
    assert safety_manifest["plr_directory"]["path"] == str(plr_directory)


def test_rollback_refuses_nonempty_installer_created_plr_directory(
    tmp_path: Path,
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)
    backup_dir = install.apply_plan(plan)
    assert backup_dir is not None
    plr_directory = Path(plan["plr_directory"])
    (plr_directory / "unexpected.gcode").write_text("unsafe\n", encoding="utf-8")
    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-nonempty-plr"

    with pytest.raises(install.InstallError, match=r"\.plr directory is not empty"):
        install.build_rollback_plan(args)


def test_installer_binds_account_to_passwd_home_and_ownership(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    canonical_home = install._canonical_layout("mks")["home"]
    owner = Path(canonical_home).stat()

    def missing_account(_account: str) -> SimpleNamespace:
        raise KeyError("mks")

    monkeypatch.setattr(install, "PASSWD_LOOKUP", missing_account)
    with pytest.raises(install.InstallError, match="not present"):
        install.build_plan(args)

    monkeypatch.setattr(
        install,
        "PASSWD_LOOKUP",
        lambda account: SimpleNamespace(
            pw_name=account,
            pw_dir=str(tmp_path / "different-home"),
            pw_uid=owner.st_uid,
            pw_gid=owner.st_gid,
        ),
    )
    with pytest.raises(install.InstallError, match="passwd home must be exactly"):
        install.build_plan(args)

    monkeypatch.setattr(
        install,
        "PASSWD_LOOKUP",
        lambda account: SimpleNamespace(
            pw_name=account,
            pw_dir=canonical_home,
            pw_uid=owner.st_uid + 1,
            pw_gid=owner.st_gid,
        ),
    )
    with pytest.raises(install.InstallError, match="ownership does not match"):
        install.build_plan(args)


def test_scripts_directory_legacy_owner_is_a_directory_only_transaction(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    first = install.build_plan(args)
    install.apply_plan(first)
    monkeypatch.setattr(install, "ENFORCE_POSIX_DIRECTORY_MODE", True)
    scripts = Path(args.scripts_dir)
    unknown = scripts / "legacy-unknown-helper.sh"
    unknown.write_bytes(b"#!/bin/sh\nexit 0\n")
    unknown_before = (unknown.read_bytes(), unknown.stat().st_mode)

    real_directory_metadata = install._directory_metadata
    actual = real_directory_metadata(str(scripts), "PLR scripts")
    original = dict(actual)
    original["uid"] = int(actual["uid"]) + 10000
    state = {"metadata": original}
    mutations: list[tuple[dict[str, object], dict[str, object] | None]] = []

    def fake_directory_metadata(path: str, label: str) -> dict[str, object]:
        if Path(path) == scripts:
            return dict(state["metadata"])
        return real_directory_metadata(path, label)

    def fake_set_directory_metadata(
        path: str,
        desired: dict[str, object],
        _label: str,
        expected: dict[str, object] | None = None,
    ) -> None:
        assert Path(path) == scripts
        if expected is not None:
            assert install._same_directory_metadata(state["metadata"], expected)
        assert install._same_directory_identity(state["metadata"], desired)
        mutations.append((dict(desired), dict(expected) if expected else None))
        state["metadata"] = dict(desired)

    monkeypatch.setattr(install, "_directory_metadata", fake_directory_metadata)
    monkeypatch.setattr(
        install, "_set_directory_metadata", fake_set_directory_metadata
    )

    args.transaction_id = "pytest-owner-only"
    plan = install.build_plan(args)
    assert plan["changed"] is True
    assert plan["scripts_directory_action"] == "normalize-metadata"
    assert plan["plr_directory_action"] == "unchanged"
    assert all(item["action"] == "unchanged" for item in plan["descriptors"])
    assert next(
        item for item in plan["actions"]
        if item["role"] == "scripts-directory-ownership"
    )["action"] == "normalize-metadata"

    backup_dir = install.apply_plan(plan)
    assert backup_dir is not None
    manifest = json.loads(
        (Path(backup_dir) / "backup-manifest.json").read_text(encoding="utf-8")
    )
    assert manifest["files"] == []
    assert manifest["scripts_directory_metadata_normalized"] is True
    manifest_original = manifest["scripts_directory"]["original"]
    manifest_desired = manifest["scripts_directory"]["desired"]
    assert manifest_original["uid"] == original["uid"]
    assert manifest_original["gid"] == original["gid"]
    assert manifest_original["mode"] == "{:04o}".format(original["mode"])
    assert manifest_original["dev"] == original["dev"]
    assert manifest_original["ino"] == original["ino"]
    assert manifest_desired["uid"] == actual["uid"]
    assert manifest_desired["gid"] == actual["gid"]
    assert manifest_desired["mode"] == "%04o" % (original["mode"] & ~0o022)
    assert state["metadata"] == plan["scripts_directory"]["desired"]

    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-owner-only-rollback"
    rollback = install.build_rollback_plan(args)
    assert rollback["changed"] is True
    assert rollback["scripts_directory_action"] == "restore-metadata"
    assert not rollback["descriptors"]
    safety_dir = install.apply_rollback_plan(rollback)
    assert safety_dir is not None
    safety = json.loads(
        (Path(safety_dir) / "safety-manifest.json").read_text(encoding="utf-8")
    )
    assert safety["scripts_directory"]["uid"] == actual["uid"]
    assert state["metadata"] == original
    verified = install.build_rollback_plan(args)
    assert verified["changed"] is False
    assert verified["scripts_directory_action"] == "already-restored"
    assert unknown.read_bytes() == unknown_before[0]
    assert unknown.stat().st_mode == unknown_before[1]
    assert len(mutations) == 2


def test_scripts_owner_is_auto_restored_after_install_failure(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    first = install.build_plan(args)
    install.apply_plan(first)
    scripts = Path(args.scripts_dir)
    unknown = scripts / "legacy-state.txt"
    unknown.write_text("preserve me\n", encoding="utf-8")

    real_directory_metadata = install._directory_metadata
    actual = real_directory_metadata(str(scripts), "PLR scripts")
    original = dict(actual)
    original["gid"] = int(actual["gid"]) + 10000
    state = {"metadata": original}
    expected_states: list[dict[str, object] | None] = []

    def fake_directory_metadata(path: str, label: str) -> dict[str, object]:
        if Path(path) == scripts:
            return dict(state["metadata"])
        return real_directory_metadata(path, label)

    def fake_set_directory_metadata(
        _path: str,
        desired: dict[str, object],
        _label: str,
        expected: dict[str, object] | None = None,
    ) -> None:
        expected_states.append(dict(expected) if expected is not None else None)
        if expected is not None:
            assert install._same_directory_metadata(state["metadata"], expected)
        state["metadata"] = dict(desired)

    monkeypatch.setattr(install, "_directory_metadata", fake_directory_metadata)
    monkeypatch.setattr(
        install, "_set_directory_metadata", fake_set_directory_metadata
    )
    args.transaction_id = "pytest-owner-auto-rollback"
    plan = install.build_plan(args)

    def fail_after_owner_normalization(_plan: dict[str, object]) -> None:
        raise OSError("simulated post-normalization failure")

    monkeypatch.setattr(install, "_ensure_plr_directory", fail_after_owner_normalization)
    with pytest.raises(install.TransactionError) as failure:
        install.apply_plan(plan)

    assert failure.value.transaction_state == "auto_rolled_back"
    assert Path(failure.value.backup_manifest).is_file()
    assert state["metadata"] == original
    assert expected_states == [
        plan["scripts_directory"]["original"],
        plan["scripts_directory"]["desired"],
    ]
    assert unknown.read_text(encoding="utf-8") == "preserve me\n"


def test_scripts_directory_mode_only_normalization_strips_no_other_bits(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    first = install.build_plan(args)
    install.apply_plan(first)
    monkeypatch.setattr(install, "ENFORCE_POSIX_DIRECTORY_MODE", True)
    scripts = Path(args.scripts_dir)
    unknown = scripts / "mode-only-legacy.txt"
    unknown.write_text("untouched\n", encoding="utf-8")

    real_directory_metadata = install._directory_metadata
    actual = real_directory_metadata(str(scripts), "PLR scripts")
    original = dict(actual)
    original["mode"] = int(actual["mode"]) | 0o2022
    state = {"metadata": original}

    def fake_directory_metadata(path: str, label: str) -> dict[str, object]:
        if Path(path) == scripts:
            return dict(state["metadata"])
        return real_directory_metadata(path, label)

    def fake_set_directory_metadata(
        _path: str,
        desired: dict[str, object],
        _label: str,
        expected: dict[str, object] | None = None,
    ) -> None:
        if expected is not None:
            assert install._same_directory_metadata(state["metadata"], expected)
        assert install._same_directory_identity(state["metadata"], desired)
        state["metadata"] = dict(desired)

    monkeypatch.setattr(install, "_directory_metadata", fake_directory_metadata)
    monkeypatch.setattr(
        install, "_set_directory_metadata", fake_set_directory_metadata
    )
    args.transaction_id = "pytest-mode-only"
    plan = install.build_plan(args)
    desired = plan["scripts_directory"]["desired"]
    assert plan["changed"] is True
    assert plan["scripts_directory_action"] == "normalize-metadata"
    assert desired["uid"] == original["uid"]
    assert desired["gid"] == original["gid"]
    assert desired["mode"] == original["mode"] & ~0o022
    assert desired["mode"] & 0o2000
    assert desired["mode"] | original["mode"] == original["mode"]

    backup_dir = install.apply_plan(plan)
    assert backup_dir is not None
    assert state["metadata"] == desired
    manifest = json.loads(
        (Path(backup_dir) / "backup-manifest.json").read_text(encoding="utf-8")
    )
    assert manifest["files"] == []
    assert manifest["scripts_directory_metadata_normalized"] is True
    assert manifest["scripts_directory"]["original"]["mode"] == (
        "{:04o}".format(original["mode"])
    )
    assert manifest["scripts_directory"]["desired"]["mode"] == (
        "{:04o}".format(desired["mode"])
    )

    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-mode-only-rollback"
    rollback = install.build_rollback_plan(args)
    assert rollback["scripts_directory_action"] == "restore-metadata"
    install.apply_rollback_plan(rollback)
    assert state["metadata"] == original
    assert install.build_rollback_plan(args)["changed"] is False
    assert unknown.read_text(encoding="utf-8") == "untouched\n"


def test_post_normalization_manifest_tamper_refuses_before_target_mutation(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    first = install.build_plan(args)
    install.apply_plan(first)
    monkeypatch.setattr(install, "ENFORCE_POSIX_DIRECTORY_MODE", True)
    scripts = Path(args.scripts_dir)
    real_directory_metadata = install._directory_metadata
    actual = real_directory_metadata(str(scripts), "PLR scripts")
    original = dict(actual)
    original["mode"] = int(actual["mode"]) | 0o022
    state = {"metadata": original}
    plan_holder: dict[str, object] = {}
    mutations = 0

    def fake_directory_metadata(path: str, label: str) -> dict[str, object]:
        if Path(path) == scripts:
            return dict(state["metadata"])
        return real_directory_metadata(path, label)

    def tamper_after_normalization(
        _path: str,
        desired: dict[str, object],
        _label: str,
        expected: dict[str, object] | None = None,
    ) -> None:
        nonlocal mutations
        if expected is not None:
            assert install._same_directory_metadata(state["metadata"], expected)
        state["metadata"] = dict(desired)
        mutations += 1
        if mutations == 1:
            Path(str(plan_holder["backup_manifest"])).write_bytes(b"tampered\n")

    monkeypatch.setattr(install, "_directory_metadata", fake_directory_metadata)
    monkeypatch.setattr(
        install, "_set_directory_metadata", tamper_after_normalization
    )
    args.transaction_id = "pytest-manifest-tamper"
    plan = install.build_plan(args)
    plan_holder.update(plan)
    assert all(item["action"] == "unchanged" for item in plan["descriptors"])
    ensure_called = False

    def record_unexpected_target_phase(_plan: dict[str, object]) -> None:
        nonlocal ensure_called
        ensure_called = True

    monkeypatch.setattr(
        install, "_ensure_plr_directory", record_unexpected_target_phase
    )
    with pytest.raises(
        install.TransactionError, match="manifest changed after publication"
    ) as failure:
        install.apply_plan(plan)

    assert failure.value.transaction_state == "auto_rolled_back"
    assert ensure_called is False
    assert mutations == 2
    assert state["metadata"] == original


def test_partial_owner_normalization_uses_identity_bound_compensation(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    first = install.build_plan(args)
    install.apply_plan(first)
    scripts = Path(args.scripts_dir)
    real_directory_metadata = install._directory_metadata
    actual = real_directory_metadata(str(scripts), "PLR scripts")
    original = dict(actual)
    original["uid"] = int(actual["uid"]) + 10000
    state = {"metadata": original}
    expected_states: list[dict[str, object] | None] = []

    def fake_directory_metadata(path: str, label: str) -> dict[str, object]:
        if Path(path) == scripts:
            return dict(state["metadata"])
        return real_directory_metadata(path, label)

    def partially_fail_then_restore(
        _path: str,
        desired: dict[str, object],
        _label: str,
        expected: dict[str, object] | None = None,
    ) -> None:
        expected_states.append(dict(expected) if expected is not None else None)
        if len(expected_states) == 1:
            assert install._same_directory_metadata(state["metadata"], expected)
            state["metadata"] = dict(desired)
            state["metadata"]["mode"] = 0o700
            raise install.DirectoryMetadataMutationError(
                "simulated fchmod failure after fchown"
            )
        assert expected is None
        assert install._same_directory_identity(state["metadata"], desired)
        state["metadata"] = dict(desired)

    monkeypatch.setattr(install, "_directory_metadata", fake_directory_metadata)
    monkeypatch.setattr(
        install, "_set_directory_metadata", partially_fail_then_restore
    )
    args.transaction_id = "pytest-owner-partial-normalization"
    plan = install.build_plan(args)

    with pytest.raises(install.TransactionError) as failure:
        install.apply_plan(plan)

    assert failure.value.transaction_state == "auto_rolled_back"
    assert state["metadata"] == original
    assert expected_states == [plan["scripts_directory"]["original"], None]


def test_scripts_directory_mode_must_support_the_eventual_owner(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    scripts = Path(args.scripts_dir)
    real_directory_metadata = install._directory_metadata

    def owner_read_only(path: str, label: str) -> dict[str, object]:
        metadata = real_directory_metadata(path, label)
        if Path(path) == scripts:
            metadata["mode"] = 0o500
        return metadata

    monkeypatch.setattr(install, "_directory_metadata", owner_read_only)
    with pytest.raises(install.InstallError, match="eventual owner write and execute"):
        install.build_plan(args)


def test_directory_metadata_update_chowns_then_restores_full_mode_and_fsyncs(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    original = {
        "path": "/home/mks/scripts/plr",
        "dev": 7,
        "ino": 11,
        "uid": 0,
        "gid": 0,
        "mode": 0o2750,
    }
    desired = dict(original)
    desired.update({"uid": 1000, "gid": 1000})
    events: list[tuple[object, ...]] = []

    monkeypatch.setattr(install, "IS_POSIX", True)
    monkeypatch.setattr(
        install, "_open_verified_directory", lambda _path, _label: (17, original)
    )
    monkeypatch.setattr(
        install, "_directory_metadata", lambda _path, _label: desired
    )
    monkeypatch.setattr(
        install.os, "fchown", lambda fd, uid, gid: events.append(("chown", fd, uid, gid)),
        raising=False,
    )
    monkeypatch.setattr(
        install.os, "fchmod", lambda fd, mode: events.append(("chmod", fd, mode)),
        raising=False,
    )
    monkeypatch.setattr(
        install.os, "fsync", lambda fd: events.append(("fsync", fd))
    )
    monkeypatch.setattr(
        install.os, "close", lambda fd: events.append(("close", fd))
    )

    install._set_directory_metadata(
        original["path"], desired, "PLR scripts", expected=original
    )

    assert events == [
        ("chown", 17, 1000, 1000),
        ("chmod", 17, 0o2750),
        ("fsync", 17),
        ("close", 17),
    ]


def test_install_failure_emits_durable_backup_and_auto_rollback_state(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)
    fail_target = Path(args.scripts_dir) / "plr_checkpoint.py"
    original_atomic = install._atomic_install
    failed = False

    def fail_second_install(
        path: str,
        data: bytes,
        mode: int | None,
        ownership: tuple[int, int] | None = None,
    ) -> None:
        nonlocal failed
        if Path(path) == fail_target and not failed:
            failed = True
            raise OSError("simulated install failure")
        original_atomic(path, data, mode, ownership)

    monkeypatch.setattr(install, "_atomic_install", fail_second_install)

    with pytest.raises(install.TransactionError) as failure:
        install.apply_plan(plan)

    error = failure.value
    assert error.transaction_state == "auto_rolled_back"
    assert error.applied is False
    assert error.safety_manifest is None
    assert Path(error.backup_manifest).is_file()
    manifest = json.loads(Path(error.backup_manifest).read_text(encoding="utf-8"))
    assert manifest["account"] == "mks"
    assert manifest["paths"] == plan["paths"]
    assert all(
        {"uid", "gid"}.issubset(entry)
        for entry in manifest["files"]
        if entry.get("backup") is not None
    )
    if install.os.name == "posix":
        assert all(
            Path(entry["backup"]).stat().st_mode & 0o777 == 0o600
            for entry in manifest["files"]
            if entry.get("backup") is not None
        )
    assert not (Path(args.scripts_dir) / "generate_recovery.py").exists()


def test_installer_main_emits_partial_state_and_durable_handle(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: Path,
    capsys: pytest.CaptureFixture[str],
) -> None:
    args = installer_args(tmp_path, apply=True)
    args.transaction_id = "pytest-cli-partial"

    monkeypatch.setattr(
        install, "_check_service_stopped", lambda _service: "inactive"
    )

    def fail_after_backup(plan: dict[str, object]) -> None:
        raise install.TransactionError(
            "simulated post-backup failure",
            "partial",
            backup_manifest=plan["backup_manifest"],
            applied=None,
        )

    monkeypatch.setattr(install, "apply_plan", fail_after_backup)
    exit_code = install.main([
        "--printer-user", args.printer_user,
        "--transaction-id", args.transaction_id,
        "--klipper-dir", args.klipper_dir,
        "--printer-data", args.printer_data,
        "--scripts-dir", args.scripts_dir,
        "--python", args.python,
        "--service", args.service,
        "--apply",
        "--klipper-stopped",
        "--json",
    ])

    assert exit_code == 1
    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is False
    assert result["transaction_state"] == "partial"
    assert result["applied"] is None
    assert result["account"] == "mks"
    assert result["paths"] == install._canonical_layout("mks")
    manifest_path = Path(result["backup_manifest"])
    assert manifest_path.name == "backup-manifest.json"
    assert manifest_path.parent.name == "plr-hardening-pytest-cli-partial"
    assert result["safety_manifest"] is None


def test_installer_main_preserves_predeclared_manifest_across_plan_and_apply(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: Path,
    capsys: pytest.CaptureFixture[str],
) -> None:
    args = installer_args(tmp_path)
    transaction_id = "pytest-cli-manifest-contract"
    base = [
        "--printer-user", args.printer_user,
        "--transaction-id", transaction_id,
        "--klipper-dir", args.klipper_dir,
        "--printer-data", args.printer_data,
        "--scripts-dir", args.scripts_dir,
        "--python", args.python,
        "--service", args.service,
        "--json",
    ]
    monkeypatch.setattr(
        install, "_check_service_stopped", lambda _service: "inactive"
    )

    assert install.main(base) == 0
    dry_run = json.loads(capsys.readouterr().out)
    expected_manifest = str(
        Path(args.scripts_dir)
        / "backups"
        / ("plr-hardening-" + transaction_id)
        / "backup-manifest.json"
    )
    assert dry_run["changed"] is True
    assert dry_run["dry_run"] is True
    assert dry_run["backup"] is None
    assert dry_run["backup_manifest"] == expected_manifest

    assert install.main(base + ["--apply", "--klipper-stopped"]) == 0
    applied = json.loads(capsys.readouterr().out)
    assert applied["changed"] is True
    assert applied["dry_run"] is False
    assert applied["applied"] is True
    assert applied["backup_manifest"] == dry_run["backup_manifest"]
    assert str(Path(applied["backup"]) / "backup-manifest.json") == (
        applied["backup_manifest"]
    )

    unchanged_id = "pytest-cli-manifest-unchanged"
    unchanged_base = list(base)
    unchanged_base[3] = unchanged_id
    assert install.main(unchanged_base) == 0
    unchanged = json.loads(capsys.readouterr().out)
    assert unchanged["changed"] is False
    assert unchanged["backup_manifest"] is None
    assert unchanged["backup"] is None

    assert install.main(
        unchanged_base + ["--apply", "--klipper-stopped"]
    ) == 0
    unchanged_apply = json.loads(capsys.readouterr().out)
    assert unchanged_apply["changed"] is False
    assert unchanged_apply["applied"] is False
    assert unchanged_apply["backup_manifest"] is None
    assert unchanged_apply["backup"] is None


def test_installer_main_rejects_a_divergent_applied_manifest_handle(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: Path,
    capsys: pytest.CaptureFixture[str],
) -> None:
    args = installer_args(tmp_path)
    monkeypatch.setattr(
        install, "_check_service_stopped", lambda _service: "inactive"
    )
    monkeypatch.setattr(
        install,
        "apply_plan",
        lambda _plan: str(tmp_path / "unexpected-backup-directory"),
    )
    exit_code = install.main([
        "--printer-user", args.printer_user,
        "--transaction-id", "pytest-cli-divergent-handle",
        "--klipper-dir", args.klipper_dir,
        "--printer-data", args.printer_data,
        "--scripts-dir", args.scripts_dir,
        "--python", args.python,
        "--service", args.service,
        "--apply",
        "--klipper-stopped",
        "--json",
    ])

    assert exit_code == 1
    result = json.loads(capsys.readouterr().out)
    assert result["transaction_state"] == "indeterminate"
    assert result["applied"] is None
    divergent_manifest = Path(result["backup_manifest"])
    assert divergent_manifest.name == "backup-manifest.json"
    assert divergent_manifest.parent.name == (
        "plr-hardening-pytest-cli-divergent-handle"
    )


def test_failed_install_rollback_reports_partial_with_usable_manifest(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)
    first_target = Path(args.scripts_dir) / "generate_recovery.py"
    fail_target = Path(args.scripts_dir) / "plr_checkpoint.py"
    original_atomic = install._atomic_install
    original_unlink = install.os.unlink
    failed = False

    def fail_second_install(
        path: str,
        data: bytes,
        mode: int | None,
        ownership: tuple[int, int] | None = None,
    ) -> None:
        nonlocal failed
        if Path(path) == fail_target and not failed:
            failed = True
            raise OSError("simulated install failure")
        original_atomic(path, data, mode, ownership)

    def fail_compensation(path: str) -> None:
        if Path(path) == first_target:
            raise OSError("simulated compensation failure")
        original_unlink(path)

    monkeypatch.setattr(install, "_atomic_install", fail_second_install)
    monkeypatch.setattr(install.os, "unlink", fail_compensation)

    with pytest.raises(install.TransactionError) as failure:
        install.apply_plan(plan)

    error = failure.value
    assert error.transaction_state == "partial"
    assert error.applied is None
    assert Path(error.backup_manifest).is_file()
    assert first_target.is_file()


def test_rollback_failure_emits_safety_manifest_and_partial_state(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    install_plan = install.build_plan(args)
    backup_dir = install.apply_plan(install_plan)
    assert backup_dir is not None
    virtual_sdcard = Path(args.klipper_dir) / "klippy" / "extras" / "virtual_sdcard.py"
    installed_data = virtual_sdcard.read_bytes()
    original_data = next(
        entry["data"]
        for entry in install_plan["descriptors"]
        if entry["role"] == "virtual-sdcard-patch"
    )
    assert installed_data == original_data
    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-rollback-partial"
    rollback = install.build_rollback_plan(args)
    backup_document = json.loads(Path(args.rollback_manifest).read_text(encoding="utf-8"))
    original_virtual = next(
        Path(entry["backup"]).read_bytes()
        for entry in backup_document["files"]
        if entry["target"] == str(virtual_sdcard)
    )
    original_atomic = install._atomic_install

    def fail_virtual_restores(
        path: str,
        data: bytes,
        mode: int | None,
        ownership: tuple[int, int] | None = None,
    ) -> None:
        if Path(path) == virtual_sdcard and data in (original_virtual, installed_data):
            raise OSError("simulated rollback and safety restore failure")
        original_atomic(path, data, mode, ownership)

    monkeypatch.setattr(install, "_atomic_install", fail_virtual_restores)

    with pytest.raises(install.TransactionError) as failure:
        install.apply_rollback_plan(rollback)

    error = failure.value
    assert error.transaction_state == "partial"
    assert error.applied is None
    assert error.backup_manifest == args.rollback_manifest
    assert Path(error.safety_manifest).is_file()
    safety = json.loads(Path(error.safety_manifest).read_text(encoding="utf-8"))
    assert safety["schema"] == "qidi-plus4-plr-safety/v1"
    assert safety["backup_manifest"] == args.rollback_manifest
    assert all(
        {"uid", "gid"}.issubset(entry)
        for entry in safety["files"]
        if entry.get("safety") is not None
    )


def test_rollback_restores_manifest_ownership_even_when_target_is_missing(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)
    virtual_sdcard = Path(args.klipper_dir) / "klippy" / "extras" / "virtual_sdcard.py"
    original_stat = virtual_sdcard.stat()
    backup_dir = install.apply_plan(plan)
    assert backup_dir is not None
    virtual_sdcard.unlink()
    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-missing-owner"
    rollback = install.build_rollback_plan(args)
    captured: list[tuple[int, int] | None] = []
    original_atomic = install._atomic_install

    def capture_ownership(
        path: str,
        data: bytes,
        mode: int | None,
        ownership: tuple[int, int] | None = None,
    ) -> None:
        if Path(path) == virtual_sdcard:
            captured.append(ownership)
        original_atomic(path, data, mode, ownership)

    monkeypatch.setattr(install, "_atomic_install", capture_ownership)
    install.apply_rollback_plan(rollback)

    assert captured[0] == (original_stat.st_uid, original_stat.st_gid)
    assert virtual_sdcard.is_file()


def test_installer_rejects_symlinked_backup_root_and_scripts_parent(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path,
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)
    scripts = Path(args.scripts_dir)
    backup_root = scripts / "backups"
    backup_root.mkdir()
    original_islink = install.os.path.islink
    with monkeypatch.context() as context:
        context.setattr(
            install.os.path,
            "islink",
            lambda path: Path(path) == backup_root or original_islink(path),
        )
        with pytest.raises(install.InstallError, match="backup root"):
            install.apply_plan(plan)
    backup_root.rmdir()

    original_realpath = install.os.path.realpath
    with monkeypatch.context() as context:
        context.setattr(
            install.os.path,
            "realpath",
            lambda path: (
                str(tmp_path / "redirected")
                if Path(path) == scripts
                else original_realpath(path)
            ),
        )
        with pytest.raises(install.InstallError, match="must not contain symlinks"):
            install.build_plan(args)


def test_secure_backup_root_allows_only_explicit_legacy_mode_exception(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    scripts = tmp_path / "scripts" / "plr"
    backup_root = scripts / "backups"
    backup_root.mkdir(parents=True)
    real_mode = install._mode

    def legacy_mode(path: str) -> int:
        if Path(path) == scripts:
            return 0o777
        if Path(path) == backup_root:
            return 0o700
        return real_mode(path)

    monkeypatch.setattr(install, "IS_POSIX", True)
    monkeypatch.setattr(install, "_mode", legacy_mode)
    with pytest.raises(install.InstallError, match="group/world writable"):
        install._secure_backup_root(str(scripts), create=False)
    assert install._secure_backup_root(
        str(scripts), create=False, allow_legacy_scripts_mode=True
    ) == str(backup_root)


def test_transaction_directory_entries_are_published_with_parent_fsync(
    monkeypatch: pytest.MonkeyPatch, tmp_path: Path
) -> None:
    args = installer_args(tmp_path)
    plan = install.build_plan(args)
    scripts = Path(args.scripts_dir)
    backup_root = scripts / "backups"
    calls: list[Path] = []
    real_fsync_directory = install._fsync_directory

    def record_fsync(path: str, label: str) -> None:
        calls.append(Path(path))
        real_fsync_directory(path, label)

    monkeypatch.setattr(install, "_fsync_directory", record_fsync)
    backup_dir = install.apply_plan(plan)
    assert backup_dir is not None
    assert calls[:2] == [scripts, backup_root]

    args.rollback_manifest = str(Path(backup_dir) / "backup-manifest.json")
    args.transaction_id = "pytest-parent-fsync-rollback"
    rollback = install.build_rollback_plan(args)
    calls.clear()
    safety_dir = install.apply_rollback_plan(rollback)
    assert safety_dir is not None
    assert calls == [backup_root]


def test_rollback_rejects_manifest_outside_installer_backup_tree(tmp_path: Path) -> None:
    args = installer_args(tmp_path)
    outside = tmp_path / "backup-manifest.json"
    outside.write_text(
        json.dumps({"schema": "qidi-plus4-plr-backup/v1", "files": []}),
        encoding="utf-8",
    )
    args.rollback_manifest = str(outside)

    with pytest.raises(install.InstallError, match="outside"):
        install.build_rollback_plan(args)
