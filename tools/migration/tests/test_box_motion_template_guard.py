from __future__ import annotations

import importlib.util
import os
from pathlib import Path

import pytest


MODULE_PATH = Path(__file__).resolve().parents[1] / "box_motion_template_guard.py"
SPEC = importlib.util.spec_from_file_location("box_motion_template_guard", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
guard = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(guard)


def test_hardened_content_disables_irq_and_removes_debounce() -> None:
    raw = b"""[include box1.cfg]\n\n[filament_motion_sensor box_motion_sensor]\nuse_irq : True\ndebounce_us : 50\nswitch_pin : ^mcu_box1:PB0\n\n[mcu mcu_box1]\nserial : example\n"""

    hardened = guard.hardened_content(raw)

    assert b"use_irq : False\n" in hardened
    assert b"debounce_us" not in hardened
    assert b"[mcu mcu_box1]\nserial : example" in hardened
    assert guard.hardened_content(hardened) == hardened


@pytest.mark.parametrize(
    "raw",
    [
        b"[mcu mcu_box1]\nserial: example\n",
        b"[filament_motion_sensor box_motion_sensor]\nswitch_pin: PB0\n",
        b"[filament_motion_sensor box_motion_sensor]\nuse_irq: True\nuse_irq: False\n",
    ],
)
def test_hardened_content_rejects_ambiguous_templates(raw: bytes) -> None:
    with pytest.raises(RuntimeError):
        guard.hardened_content(raw)


@pytest.mark.skipif(os.name == "nt", reason="remote helper targets a POSIX QIDI host")
def test_install_creates_verified_backup_and_is_idempotent(tmp_path: Path) -> None:
    target = tmp_path / "cfg_with_1"
    target.write_text(
        "[filament_motion_sensor box_motion_sensor]\nuse_irq: True\ndebounce_us: 50\n",
        encoding="utf-8",
    )
    transaction = "20260806T010203Z-0123456789abcdef"

    first = guard.install(1, transaction, target=target)

    assert first["changed"] is True
    assert first["verified"] is True
    assert first["backup"]["sha256"] == first["target"]["before_sha256"]
    assert target.read_text(encoding="utf-8") == (
        "[filament_motion_sensor box_motion_sensor]\nuse_irq : False\n"
    )

    second = guard.install(
        1,
        "20260806T010204Z-fedcba9876543210",
        target=target,
    )
    assert second["changed"] is False
    assert second["backup"] is None
    assert second["target"]["before_sha256"] == second["target"]["after_sha256"]
