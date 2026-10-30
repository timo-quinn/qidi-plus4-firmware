"""Render the Box control panel macros against synthetic printer state.

The panel is pure Klipper Jinja, so its dialog logic can be verified off the
printer. These tests encode the backend semantics recovered from QIDI's own
front-end bundle: `runout_button == 0` means a lane holds filament,
`b_endstop_state == 0` means the shared path is occupied, and `last_load_slot`
names the lane currently fed to the toolhead.
"""

from __future__ import annotations

import ast
import re
from pathlib import Path

import pytest
from jinja2 import Environment

PANEL = (
    Path(__file__).resolve().parents[1]
    / "integrations"
    / "qidi-box-ui"
    / "ams-panel.cfg"
)


class MacroError(Exception):
    """Raised in place of Klipper's action_raise_error."""


def klipper_environment() -> Environment:
    return Environment(
        block_start_string="{%",
        block_end_string="%}",
        variable_start_string="{",
        variable_end_string="}",
        autoescape=False,
    )


def macro_body(name: str) -> str:
    text = PANEL.read_text(encoding="utf-8")
    match = re.search(
        rf"^\[gcode_macro {re.escape(name)}\]\n.*?^gcode:\n(?P<body>.*?)(?=^\[|\Z)",
        text,
        flags=re.MULTILINE | re.DOTALL,
    )
    assert match is not None, f"macro not found: {name}"
    return match.group("body")


def config_variables() -> dict[str, object]:
    text = PANEL.read_text(encoding="utf-8")
    section = text.split("[gcode_macro _PLUS4_BOX_CONFIG]", 1)[1].split("gcode:", 1)[0]
    variables: dict[str, object] = {}
    for name, raw in re.findall(r"^variable_(\w+):\s*(.+)$", section, re.MULTILINE):
        variables[name] = ast.literal_eval(raw.strip())
    return variables


def printer_state(
    *,
    boxes: int = 1,
    present: tuple[int, ...] = (0, 3),
    loaded: int | None = None,
    busy: bool = False,
    printing: bool = False,
    humidity: float = 48.0,
) -> dict[str, object]:
    """Build a printer status dict shaped like QIDI's compiled Box modules."""
    state: dict[str, object] = {
        "gcode_macro _PLUS4_BOX_CONFIG": config_variables(),
        "save_variables": {
            "variables": {
                "box_count": boxes,
                "enable_box": 1,
                "last_load_slot": f"slot{loaded}" if loaded is not None else "",
                "filament_slot0": 7,
                "color_slot0": 3,
            }
        },
        "box_extras": {
            "b_endstop_state": 0 if loaded is not None else 1,
            "e_endstop_state": 1,
            "box_button_state": 1 if busy else 0,
        },
        "print_stats": {"state": "printing" if printing else "standby"},
    }
    for index in range(boxes * 4):
        state[f"box_stepper slot{index}"] = {
            "runout_button": 0 if index in present else 1,
            "rfid_state": "idle",
        }
    for box in range(boxes):
        state[f"aht20_f heater_box{box + 1}"] = {"humidity": humidity}
    return state


def render(macro: str, printer: dict[str, object], **params: object) -> str:
    def raise_error(message: str) -> None:
        raise MacroError(message)

    return klipper_environment().from_string(macro_body(macro)).render(
        printer=printer,
        params={key: str(value) for key, value in params.items()},
        action_respond_info=lambda message: "",
        action_raise_error=raise_error,
    )


def buttons(rendered: str) -> dict[str, str]:
    """Map prompt button labels to their colour."""
    found = {}
    for label, _gcode, colour in re.findall(
        r"action:prompt_(?:footer_)?button ([^|\"]+)\|([^|\"]*)\|?([a-z]*)", rendered
    ):
        found[label.strip()] = colour
    return found


def macro_names() -> list[str]:
    text = PANEL.read_text(encoding="utf-8")
    return re.findall(r"^\[gcode_macro (\S+)\]$", text, re.MULTILINE)


def test_every_macro_body_is_valid_jinja() -> None:
    # Klipper renders the `gcode:` bodies, not the whole file, so each body is
    # parsed on its own. Config values such as the material-name dict default
    # are Python literals and are deliberately not Jinja.
    names = macro_names()
    assert "PLUS4_BOX" in names
    for name in names:
        klipper_environment().parse(macro_body(name))


def test_config_defaults_are_python_literals() -> None:
    variables = config_variables()

    assert variables["slots_per_box"] == 4
    assert variables["external_slot"] == 16
    assert variables["material_names"] == {}
    assert variables["block_while_printing"] is True


def test_panel_renders_one_button_per_slot_with_correct_labels() -> None:
    rendered = render("PLUS4_BOX", printer_state(present=(0, 3), loaded=0))

    assert "action:prompt_begin Control Box" in rendered
    assert "humidity 48%" in rendered
    labels = buttons(rendered)
    assert labels["1A - loaded"] == "primary"
    assert labels["1B - empty"] == "secondary"
    assert labels["1C - empty"] == "secondary"
    assert labels["1D - ready"] == "info"
    assert "External spool (Rack)" in labels
    assert rendered.count("action:prompt_button_group_start") == 1
    assert rendered.rstrip().endswith("action:prompt_show")


def test_panel_reports_missing_box_instead_of_rendering_slots() -> None:
    rendered = render("PLUS4_BOX", printer_state(boxes=0))

    assert "No QIDI Box detected" in rendered
    assert "_PLUS4_BOX_SLOT" not in rendered


def test_two_boxes_produce_two_rows_and_continuous_labels() -> None:
    rendered = render("PLUS4_BOX", printer_state(boxes=2, present=(4,)))

    assert rendered.count("action:prompt_button_group_start") == 2
    labels = buttons(rendered)
    assert "1A - empty" in labels
    assert "2A - ready" in labels
    assert "SLOT=4" in rendered


def test_empty_slot_offers_no_load_or_unload() -> None:
    rendered = render("_PLUS4_BOX_SLOT", printer_state(present=()), SLOT=1)

    labels = buttons(rendered)
    assert "Load" not in labels
    assert "Unload" not in labels
    assert "Eject" not in labels
    assert "Read RFID tag" in labels
    assert "No filament detected" in rendered


def test_ready_slot_offers_load_but_not_unload() -> None:
    rendered = render("_PLUS4_BOX_SLOT", printer_state(present=(1,)), SLOT=1)

    labels = buttons(rendered)
    assert labels["Load"] == "primary"
    assert "Unload" not in labels
    assert labels["Eject"] == "warning"


def test_loaded_slot_offers_unload_but_not_load() -> None:
    rendered = render("_PLUS4_BOX_SLOT", printer_state(present=(1,), loaded=1), SLOT=1)

    labels = buttons(rendered)
    assert "Load" not in labels
    assert labels["Unload"] == "warning"
    assert "Loaded to the toolhead" in rendered


def test_other_slot_stays_loadable_while_a_different_slot_is_loaded() -> None:
    rendered = render("_PLUS4_BOX_SLOT", printer_state(present=(0, 1), loaded=0), SLOT=1)

    assert "Load" in buttons(rendered)


def test_busy_box_hides_all_actions() -> None:
    rendered = render("_PLUS4_BOX_SLOT", printer_state(present=(1,), busy=True), SLOT=1)

    labels = buttons(rendered)
    assert "Load" not in labels
    assert "Eject" not in labels
    assert "currently busy" in rendered


def test_external_slot_is_always_actionable_and_has_no_rfid() -> None:
    rendered = render("_PLUS4_BOX_SLOT", printer_state(), SLOT=16)

    labels = buttons(rendered)
    assert "Unload" in labels
    assert "Read RFID tag" not in labels
    assert "Eject" not in labels


def test_actions_map_to_the_backend_commands() -> None:
    state = printer_state(present=(2,))
    assert "E_LOAD slot=2" in render("_PLUS4_BOX_ACTION", state, VERB="load", SLOT=2)
    assert "E_UNLOAD slot=2" in render("_PLUS4_BOX_ACTION", state, VERB="unload", SLOT=2)
    assert "E_BOX slot=2" in render("_PLUS4_BOX_ACTION", state, VERB="eject", SLOT=2)
    assert "RFID_READ SLOT=slot2" in render("_PLUS4_BOX_ACTION", state, VERB="rfid", SLOT=2)


def test_unknown_action_is_rejected() -> None:
    with pytest.raises(MacroError, match="Unknown Box action"):
        render("_PLUS4_BOX_ACTION", printer_state(), VERB="purge", SLOT=0)


def test_slot_action_refuses_to_run_during_a_print() -> None:
    with pytest.raises(MacroError, match="during a print"):
        render(
            "_PLUS4_BOX_RUN",
            printer_state(present=(1,), printing=True),
            VERB="load",
            SLOT=1,
        )


def test_slot_action_during_a_print_can_be_forced() -> None:
    rendered = render(
        "_PLUS4_BOX_RUN",
        printer_state(present=(1,), printing=True),
        VERB="load",
        SLOT=1,
        FORCE=1,
    )

    assert "_PLUS4_BOX_ACTION VERB=load SLOT=1" in rendered


def test_out_of_range_slot_is_rejected() -> None:
    for slot in (-1, 17):
        with pytest.raises(MacroError, match="out of range"):
            render("_PLUS4_BOX_RUN", printer_state(), VERB="load", SLOT=slot)


def test_status_macro_reports_every_slot() -> None:
    rendered = render("PLUS4_BOX_STATUS", printer_state(present=(0, 3), loaded=0))

    assert "action:prompt" not in rendered
