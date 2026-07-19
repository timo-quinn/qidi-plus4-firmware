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
        params={"HOTEND": 250, "EXTRUDER": 2}
    )

    assert "\n}\n" not in rendered
    assert "M83" in rendered
    assert "EXTRUDER_LOAD SLOT=slot2" in rendered


def test_standalone_extrusion_macros_preserve_gcode_state() -> None:
    for name in ("BOX_EXTRUDE", "BOX_AUTO_RELOAD_FILAMENT", "BOX_FLUSH_FILAMENT"):
        body = macro_body(name)
        assert "SAVE_GCODE_STATE" in body
        assert "M83" in body
        assert "RESTORE_GCODE_STATE" in body


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
