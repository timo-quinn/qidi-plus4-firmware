from __future__ import annotations

import importlib.util
import logging
from pathlib import Path

import pytest


MODULE_PATH = Path(__file__).resolve().parents[1] / "box_output_clock_guard.py"
SPEC = importlib.util.spec_from_file_location("box_output_clock_guard", MODULE_PATH)
assert SPEC and SPEC.loader
clock_guard = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(clock_guard)


class ConfigError(Exception):
    pass


class FakeMCU:
    def __init__(self, name: str) -> None:
        self.name = name
        self.estimate_calls = 0

    def get_name(self) -> str:
        return self.name

    def estimated_print_time(self, eventtime: float) -> float:
        self.estimate_calls += 1
        return eventtime


class FakeDigitalOut:
    def __init__(self, mcu: FakeMCU) -> None:
        self.mcu = mcu
        self.get_mcu_calls = 0
        self.set_calls: list[tuple[float, float]] = []

    def get_mcu(self) -> FakeMCU:
        self.get_mcu_calls += 1
        return self.mcu

    def set_digital(self, print_time: float, value: float) -> None:
        self.set_calls.append((print_time, value))


class FakeOutput:
    def __init__(self, mcu: FakeMCU, pin_mcu: FakeMCU) -> None:
        self.mcu = mcu
        self.digital_out = FakeDigitalOut(pin_mcu)
        self.set_pin_calls: list[float] = []

    def set_pin(self, value: float) -> None:
        self.set_pin_calls.append(value)


class RejectingOutput(FakeOutput):
    def __init__(self, mcu: FakeMCU, pin_mcu: FakeMCU) -> None:
        super().__init__(mcu, pin_mcu)
        self.reject_mcu_assignment = True

    def __setattr__(self, name: str, value: object) -> None:
        if name == "mcu" and getattr(self, "reject_mcu_assignment", False):
            raise AttributeError("mcu is read-only")
        super().__setattr__(name, value)


class FakeBoxExtras:
    def __init__(self, b_output: object, e_output: object) -> None:
        self.b_output = b_output
        self.e_output = e_output
        self.values: dict[str, object] = {}

    def get_value_by_key(self, name: str, default: object = None) -> object:
        return self.values.get(name, default)


class FakeGCode:
    def __init__(self) -> None:
        self.reload_calls: list[object] = []
        self.commands: dict[str, object] = {"RELOAD_ALL": self._reload_all}

    def _reload_all(self, gcmd: object) -> None:
        self.reload_calls.append(gcmd)

    def register_command(
        self,
        name: str,
        callback: object | None,
        desc: str | None = None,
    ) -> object | None:
        del desc
        if callback is None:
            return self.commands.pop(name, None)
        if name in self.commands:
            raise ValueError("command already registered")
        self.commands[name] = callback
        return None


class FakeGCmd:
    def __init__(self, **params: int) -> None:
        self.params = params
        self.responses: list[str] = []

    def get_int(self, name: str, default: int = 0) -> int:
        return self.params.get(name, default)

    def respond_info(self, message: str) -> None:
        self.responses.append(message)


class FakePrinter:
    def __init__(self, box_extras: object | None) -> None:
        self.box_extras = box_extras
        self.gcode = FakeGCode()
        self.handlers: dict[str, object] = {}

    def register_event_handler(self, name: str, callback: object) -> None:
        self.handlers[name] = callback

    def lookup_object(self, name: str) -> object:
        if name == "box_extras" and self.box_extras is not None:
            return self.box_extras
        if name == "gcode":
            return self.gcode
        raise KeyError(name)

    def connect(self) -> None:
        callback = self.handlers["klippy:connect"]
        assert callable(callback)
        callback()


class FakeConfig:
    error = ConfigError

    def __init__(self, printer: FakePrinter) -> None:
        self.printer = printer

    def get_printer(self) -> FakePrinter:
        return self.printer


def make_guard(
    b_source: FakeMCU,
    b_target: FakeMCU,
    e_source: FakeMCU,
    e_target: FakeMCU,
) -> tuple[object, FakePrinter, FakeBoxExtras]:
    extras = FakeBoxExtras(
        FakeOutput(b_source, b_target),
        FakeOutput(e_source, e_target),
    )
    printer = FakePrinter(extras)
    guard = clock_guard.load_config(FakeConfig(printer))
    return guard, printer, extras


def test_corrects_both_outputs_to_each_pins_actual_mcu(caplog: pytest.LogCaptureFixture) -> None:
    primary = FakeMCU("mcu")
    b_pin_mcu = FakeMCU("mcu_box1")
    e_pin_mcu = FakeMCU("mcu_box2")
    guard, printer, extras = make_guard(primary, b_pin_mcu, primary, e_pin_mcu)

    with caplog.at_level(logging.INFO):
        printer.connect()

    assert extras.b_output.mcu is b_pin_mcu
    assert extras.e_output.mcu is e_pin_mcu
    assert guard.get_status() == {
        "state": "corrected",
        "corrected_count": 2,
        "corrected_outputs": ["b_output", "e_output"],
        "outputs": {
            "b_output": {
                "state": "corrected",
                "previous_mcu": "mcu",
                "pin_mcu": "mcu_box1",
            },
            "e_output": {
                "state": "corrected",
                "previous_mcu": "mcu",
                "pin_mcu": "mcu_box2",
            },
        },
        "reload_all_guarded": True,
    }
    assert "b_output corrected (mcu -> mcu_box1)" in caplog.text
    assert "e_output corrected (mcu -> mcu_box2)" in caplog.text
    assert "active; corrected=2 already-correct=0" in caplog.text


def test_already_correct_outputs_and_second_connect_are_no_ops(
    caplog: pytest.LogCaptureFixture,
) -> None:
    b_pin_mcu = FakeMCU("mcu_box1")
    e_pin_mcu = FakeMCU("mcu_box1")
    guard, printer, extras = make_guard(b_pin_mcu, b_pin_mcu, e_pin_mcu, e_pin_mcu)

    with caplog.at_level(logging.INFO):
        printer.connect()
        printer.connect()

    assert extras.b_output.mcu is b_pin_mcu
    assert extras.e_output.mcu is e_pin_mcu
    assert guard.get_status()["state"] == "already-correct"
    assert guard.get_status()["corrected_count"] == 0
    assert "active; corrected=0 already-correct=2" in caplog.text
    assert "already applied; no changes made" in caplog.text


@pytest.mark.parametrize(
    ("break_vendor_shape", "expected_message"),
    [
        (
            lambda extras: delattr(extras, "e_output"),
            "box_extras has no e_output attribute",
        ),
        (
            lambda extras: delattr(extras.e_output, "digital_out"),
            "box_extras.e_output has no digital_out attribute",
        ),
        (
            lambda extras: setattr(extras.e_output.digital_out, "get_mcu", None),
            "digital_out has no callable get_mcu()",
        ),
        (
            lambda extras: setattr(extras.e_output.digital_out, "set_digital", None),
            "digital_out has no callable set_digital()",
        ),
        (
            lambda extras: setattr(extras.e_output, "set_pin", None),
            "box_extras.e_output has no callable set_pin()",
        ),
    ],
)
def test_incompatible_second_output_fails_before_changing_first(
    break_vendor_shape: object,
    expected_message: str,
) -> None:
    primary = FakeMCU("mcu")
    b_pin_mcu = FakeMCU("mcu_box1")
    e_pin_mcu = FakeMCU("mcu_box1")
    guard, printer, extras = make_guard(primary, b_pin_mcu, primary, e_pin_mcu)
    original_b_mcu = extras.b_output.mcu
    assert callable(break_vendor_shape)
    break_vendor_shape(extras)

    with pytest.raises(ConfigError, match=expected_message):
        printer.connect()

    assert extras.b_output.mcu is original_b_mcu
    assert extras.b_output.set_pin_calls == []
    assert extras.b_output.digital_out.set_calls == []
    assert primary.estimate_calls == 0
    assert b_pin_mcu.estimate_calls == 0
    assert guard.get_status()["state"] == "error"


def test_missing_box_extras_defers_without_halting_klipper() -> None:
    printer = FakePrinter(None)
    guard = clock_guard.load_config(FakeConfig(printer))

    printer.connect()

    assert guard.get_status() == {
        "state": "inactive-no-box",
        "corrected_count": 0,
        "corrected_outputs": [],
        "outputs": {},
        "reload_all_guarded": False,
    }


def test_automatic_reload_is_quarantined_but_manual_reload_is_forwarded() -> None:
    primary = FakeMCU("mcu")
    pin_mcu = FakeMCU("mcu_box1")
    guard, printer, extras = make_guard(primary, pin_mcu, primary, pin_mcu)
    printer.connect()
    guarded_reload = printer.gcode.commands["RELOAD_ALL"]
    assert callable(guarded_reload)

    automatic = FakeGCmd(RFID=1, FIRST=2)
    guarded_reload(automatic)
    assert printer.gcode.reload_calls == []
    assert automatic.responses and "automatic insertion is disabled" in automatic.responses[0]

    manual = FakeGCmd(FIRST=2)
    guarded_reload(manual)
    assert printer.gcode.reload_calls == [manual]
    assert guard.get_status()["reload_all_guarded"] is True


def test_explicit_saved_variable_enables_automatic_reload() -> None:
    primary = FakeMCU("mcu")
    pin_mcu = FakeMCU("mcu_box1")
    _, printer, extras = make_guard(primary, pin_mcu, primary, pin_mcu)
    extras.values["qidi_box_auto_insert"] = 1
    printer.connect()

    automatic = FakeGCmd(RFID=1)
    guarded_reload = printer.gcode.commands["RELOAD_ALL"]
    assert callable(guarded_reload)
    guarded_reload(automatic)

    assert printer.gcode.reload_calls == [automatic]
    assert automatic.responses == []


def test_missing_vendor_reload_command_rolls_back_output_corrections() -> None:
    primary = FakeMCU("mcu")
    pin_mcu = FakeMCU("mcu_box1")
    guard, printer, extras = make_guard(primary, pin_mcu, primary, pin_mcu)
    printer.gcode.commands.clear()

    with pytest.raises(ConfigError, match="RELOAD_ALL command is not registered"):
        printer.connect()

    assert extras.b_output.mcu is primary
    assert extras.e_output.mcu is primary
    assert guard.get_status()["state"] == "error"
    assert guard.get_status()["reload_all_guarded"] is False


def test_invalid_pin_mcu_fails_before_changing_either_output() -> None:
    primary = FakeMCU("mcu")
    b_pin_mcu = FakeMCU("mcu_box1")
    e_pin_mcu = FakeMCU("mcu_box1")
    guard, printer, extras = make_guard(primary, b_pin_mcu, primary, e_pin_mcu)
    extras.e_output.digital_out.mcu = None

    with pytest.raises(ConfigError, match=r"get_mcu\(\) returned None"):
        printer.connect()

    assert extras.b_output.mcu is primary
    assert extras.e_output.mcu is primary
    assert extras.b_output.set_pin_calls == []
    assert extras.e_output.set_pin_calls == []
    assert guard.get_status()["state"] == "error"


def test_rejected_assignment_rolls_back_an_earlier_output() -> None:
    primary = FakeMCU("mcu")
    pin_mcu = FakeMCU("mcu_box1")
    b_output = FakeOutput(primary, pin_mcu)
    e_output = RejectingOutput(primary, pin_mcu)
    extras = FakeBoxExtras(b_output, e_output)
    printer = FakePrinter(extras)
    guard = clock_guard.load_config(FakeConfig(printer))

    with pytest.raises(ConfigError, match="could not apply correction"):
        printer.connect()

    assert b_output.mcu is primary
    assert e_output.mcu is primary
    assert b_output.set_pin_calls == []
    assert e_output.set_pin_calls == []
    assert b_output.digital_out.set_calls == []
    assert e_output.digital_out.set_calls == []
    assert guard.get_status()["state"] == "error"
