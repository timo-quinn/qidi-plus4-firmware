#!/usr/bin/env python3
"""Exercise the ToolChange state contract expected by QIDI firmware 1.8.2."""

from __future__ import annotations

import sys
from pathlib import Path


class GCode:
    def register_command(self, _name, _handler):
        pass


class BoxExtras:
    def __init__(self):
        self.saved = []

    def get_value_by_key(self, key, _default):
        return key

    def save_variable(self, key, value):
        self.saved.append((key, value))


class Printer:
    def __init__(self):
        self.gcode = GCode()
        self.box_extras = BoxExtras()

    def lookup_object(self, name):
        return {"gcode": self.gcode, "box_extras": self.box_extras}[name]

    def load_object(self, _config, name):
        if name != "gcode_move":
            raise AssertionError(f"unexpected object request: {name}")
        return object()


class Config:
    def __init__(self, printer):
        self.printer = printer

    def get_printer(self):
        return self.printer


class Command:
    def __init__(self, **values):
        self.values = values

    def get_int(self, name, default):
        return self.values.get(name, default)


def main(module_dir: Path) -> None:
    sys.path.insert(0, str(module_dir))
    import box_extras

    printer = Printer()
    tool_change = box_extras.ToolChange(Config(printer))
    assert tool_change.is_tool_change is False

    tool_change.cmd_TOOL_CHANGE_START(Command(F=0, T=1))
    assert tool_change.is_tool_change is True

    tool_change.cmd_TOOL_CHANGE_END(Command())
    assert tool_change.is_tool_change is False
    assert printer.box_extras.saved == [
        ("is_tool_change", 1),
        ("is_tool_change", 0),
    ]
    print(f"OK box_extras ToolChange contract under {sys.version.split()[0]}")


if __name__ == "__main__":
    main(Path(sys.argv[1] if len(sys.argv) > 1 else "/work/out"))
