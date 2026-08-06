from __future__ import annotations

import ast
import hashlib
from pathlib import Path
import re
import subprocess
import sys

from jinja2 import Environment


MODULE_DIR = Path(__file__).resolve().parents[1]
REPO_ROOT = MODULE_DIR.parent
MACROS = MODULE_DIR / "box_macros.cfg"
PATCHER = MODULE_DIR / "build-recipe" / "apply-compatibility-patches.py"
UPSTREAM_SOURCE = (
    REPO_ROOT
    / "analysis"
    / "github-releases"
    / "qidi-klipper-1.7.0-box-source"
    / "box_extras.py"
)


def macro_body(name: str) -> str:
    text = MACROS.read_text(encoding="utf-8")
    match = re.search(
        rf"^\[gcode_macro {re.escape(name)}\]\n.*?^gcode:\n(?P<body>.*?)(?=^\[|\Z)",
        text,
        flags=re.MULTILINE | re.DOTALL,
    )
    assert match is not None
    return match.group("body")


def klipper_environment() -> Environment:
    return Environment(
        block_start_string="{%",
        block_end_string="%}",
        variable_start_string="{",
        variable_end_string="}",
        autoescape=False,
    )


def test_all_macro_jinja_parses() -> None:
    klipper_environment().parse(MACROS.read_text(encoding="utf-8"))


def test_auto_reload_macro_renders_without_stray_gcode() -> None:
    rendered = klipper_environment().from_string(macro_body("BOX_AUTO_RELOAD_FILAMENT")).render(
        params={"HOTEND": 250, "EXTRUDER": 2},
        printer={
            "configfile": {
                "config": {
                    "extruder": {"min_extrude_temp": 170, "max_temp": 350}
                }
            }
        },
        action_raise_error=lambda message: "ERROR: %s" % message,
    )

    assert "\n}\n" not in rendered
    assert "M83" in rendered
    assert "EXTRUDER_LOAD SLOT=slot2" in rendered
    assert "BOX_HOME_XY" in rendered
    assert "MOVE_TO_TRASH" in rendered
    assert "CLEAR_FLUSH" in rendered


def test_standalone_extrusion_macros_preserve_gcode_state() -> None:
    for name in ("BOX_EXTRUDE", "BOX_AUTO_RELOAD_FILAMENT", "BOX_FLUSH_FILAMENT"):
        body = macro_body(name)
        assert "SAVE_GCODE_STATE" in body
        assert "M83" in body
        assert "RESTORE_GCODE_STATE" in body


def test_motion_macros_use_absolute_mode_and_terminal_barriers() -> None:
    for name in (
        "BOX_CLEAR_FLUSH",
        "BOX_CLEAR_OOZE",
        "_BOX_MOVE_TO_CUTTER_AFTER_HOME",
        "BOX_DO_CUT",
    ):
        body = macro_body(name)
        assert "G90" in body
        assert "M400" in body
        assert "RESTORE_GCODE_STATE" not in body
    assert "F120000" not in macro_body("BOX_CLEAR_OOZE")
    assert "SET_VELOCITY_LIMIT ACCEL={previous_accel}" in macro_body("BOX_CLEAR_FLUSH")
    assert "SET_VELOCITY_LIMIT ACCEL={previous_accel}" in macro_body("BOX_CLEAR_OOZE")
    assert "SET_VELOCITY_LIMIT ACCEL={previous_accel}" in macro_body(
        "_BOX_MOVE_TO_CUTTER_AFTER_HOME"
    )


def test_cutter_move_keeps_its_physical_endpoint_for_do_cut() -> None:
    parent = macro_body("BOX_MOVE_TO_CUTTER")
    move = macro_body("_BOX_MOVE_TO_CUTTER_AFTER_HOME")
    assert parent.index("BOX_HOME_XY") < parent.index("M400") < parent.index(
        "_BOX_MOVE_TO_CUTTER_AFTER_HOME"
    )
    assert "printer.gcode_move.position" not in parent
    assert move.rfind("G1 X304") < move.rfind("G1 Y20") < move.rfind("M400")
    assert "RESTORE_GCODE_STATE" not in move


def test_cutter_clearance_is_rendered_from_post_home_position() -> None:
    template = klipper_environment().from_string(
        macro_body("_BOX_MOVE_TO_CUTTER_AFTER_HOME")
    )
    common = {
        "params": {"PREVIOUS_ACCEL": 3000},
        "action_raise_error": lambda message: "ERROR: %s" % message,
    }
    high = template.render(printer={"gcode_move": {"position": {"y": 310}}}, **common)
    low = template.render(printer={"gcode_move": {"position": {"y": 10}}}, **common)
    middle = template.render(
        printer={"gcode_move": {"position": {"y": 150}}}, **common
    )

    assert "G1 Y300 F9000" in high
    assert "G1 Y25 F9000" not in high
    assert "G1 Y25 F9000" in low
    assert "G1 Y300 F9000" not in low
    assert "G1 Y300 F9000" not in middle
    assert "G1 Y25 F9000" not in middle


def test_flush_macro_honours_call_parameters_and_validates_preconditions() -> None:
    body = macro_body("BOX_FLUSH_FILAMENT")
    assert 'printer["gcode_macro BOX_CHANGE_FILAMENT"]' not in body
    rendered = klipper_environment().from_string(body).render(
        params={"RETRACT_LENGTH": 7, "FLUSH_LENGTH": 80, "FLUSH_RATE": 1234},
        printer={"toolhead": {"homed_axes": "xyz"}},
        action_raise_error=lambda message: "ERROR: %s" % message,
    )

    assert "G1 E7.0 F300" in rendered
    assert "F1234.0" in rendered
    assert "CLEAR_FLUSH" in rendered
    assert rendered.rfind("M400") < rendered.rfind("RESTORE_GCODE_STATE")


def test_cut_and_reload_macros_have_fail_closed_preconditions() -> None:
    assert "requires homed X and Y axes" in macro_body("BOX_DO_CUT")
    assert "requires BOX_MOVE_TO_CUTTER first" in macro_body("BOX_DO_CUT")
    reload_body = macro_body("BOX_AUTO_RELOAD_FILAMENT")
    assert "outside the configured safe range" in reload_body
    assert "EXTRUDER must be a finite integer from 0..15" in reload_body


def test_box_macros_reject_nonfinite_parameters() -> None:
    reload_template = klipper_environment().from_string(
        macro_body("BOX_AUTO_RELOAD_FILAMENT")
    )
    for nonfinite in ("nan", "inf", "-inf"):
        reload_rendered = reload_template.render(
            params={"HOTEND": nonfinite, "EXTRUDER": nonfinite},
            printer={
                "configfile": {
                    "config": {
                        "extruder": {"min_extrude_temp": 170, "max_temp": 350}
                    }
                }
            },
            action_raise_error=lambda message: "ERROR: %s" % message,
        )
        assert "ERROR: BOX_AUTO_RELOAD_FILAMENT HOTEND" in reload_rendered
        assert "ERROR: BOX_AUTO_RELOAD_FILAMENT EXTRUDER" in reload_rendered

    flush_template = klipper_environment().from_string(
        macro_body("BOX_FLUSH_FILAMENT")
    )
    for parameter in ("RETRACT_LENGTH", "FLUSH_LENGTH", "FLUSH_RATE"):
        for nonfinite in ("nan", "inf", "-inf"):
            params = {"RETRACT_LENGTH": 3, "FLUSH_LENGTH": 50, "FLUSH_RATE": 50}
            params[parameter] = nonfinite
            rendered = flush_template.render(
                params=params,
                printer={"toolhead": {"homed_axes": "xyz"}},
                action_raise_error=lambda message: "ERROR: %s" % message,
            )
            assert "ERROR: BOX_FLUSH_FILAMENT" in rendered

    cutter_template = klipper_environment().from_string(
        macro_body("_BOX_MOVE_TO_CUTTER_AFTER_HOME")
    )
    for nonfinite in ("nan", "inf", "-inf"):
        rendered = cutter_template.render(
            params={"PREVIOUS_ACCEL": nonfinite},
            printer={"gcode_move": {"position": {"y": 150}}},
            action_raise_error=lambda message: "ERROR: %s" % message,
        )
        assert "ERROR: _BOX_MOVE_TO_CUTTER_AFTER_HOME PREVIOUS_ACCEL" in rendered


def test_compatibility_patch_exposes_tool_change_state(tmp_path: Path) -> None:
    source_dir = tmp_path / "src"
    source_dir.mkdir()
    source = source_dir / "box_extras.py"
    source.write_bytes(UPSTREAM_SOURCE.read_bytes())

    subprocess.run([sys.executable, str(PATCHER), str(source_dir)], check=True)
    subprocess.run([sys.executable, str(PATCHER), str(source_dir)], check=True)

    module = ast.parse(source.read_text(encoding="utf-8"))
    tool_change = next(
        node for node in module.body if isinstance(node, ast.ClassDef) and node.name == "ToolChange"
    )
    assignments = {
        method.name: [
            node.value.value
            for node in ast.walk(method)
            if isinstance(node, ast.Assign)
            and any(
                isinstance(target, ast.Attribute)
                and target.attr == "is_tool_change"
                for target in node.targets
            )
            and isinstance(node.value, ast.Constant)
        ]
        for method in tool_change.body
        if isinstance(method, ast.FunctionDef)
    }

    assert assignments["__init__"] == [False]
    assert assignments["cmd_TOOL_CHANGE_START"] == [True]
    assert assignments["cmd_TOOL_CHANGE_END"] == [False]


def test_distributed_artifact_hashes_match_manifest() -> None:
    manifest = (MODULE_DIR / "build-recipe" / "SOURCE-MANIFEST.txt").read_text(
        encoding="utf-8"
    )
    for target in ("cp312-aarch64", "cp37-aarch64"):
        section = manifest.split(f"--- {target} ---", 1)[1].split("---", 1)[0]
        expected = dict(re.findall(r"^  ([0-9a-f]{64})  (\S+\.so)$", section, re.MULTILINE))
        assert len(expected) == 5
        for digest, filename in expected.items():
            data = (MODULE_DIR / target / filename).read_bytes()
            assert hashlib.sha256(data).hexdigest() == digest
