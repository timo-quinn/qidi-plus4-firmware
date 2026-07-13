import json

import pytest

from qidi_screen_bridge.cli import _expand_profiles
from qidi_screen_bridge.profile import load_profile


def test_load_profile(tmp_path):
    path = tmp_path / "profile.json"
    path.write_text(
        json.dumps(
            {
                "schema_version": 1,
                "profile_id": "test",
                "printer_model": "Plus4",
                "firmware_release": "test",
                "serial": {"device": "/dev/ttyS1", "runtime_baud": None},
                "screen_resource": {
                    "size": 1234,
                    "sha256": "a" * 64,
                    "ui_version": "test-ui",
                },
                "mappings": {},
                "unknowns": ["everything"],
            }
        ),
        encoding="utf-8",
    )
    profile = load_profile(path)
    assert profile.serial_device == "/dev/ttyS1"
    assert profile.runtime_baud is None
    assert profile.screen_resource_size == 1234
    assert profile.screen_resource_sha256 == "a" * 64
    assert profile.ui_version == "test-ui"


def test_reject_unknown_schema(tmp_path):
    path = tmp_path / "profile.json"
    path.write_text(
        json.dumps(
            {
                "schema_version": 2,
                "profile_id": "test",
                "printer_model": "Plus4",
                "firmware_release": "test",
                "serial": {"device": "/dev/ttyS1"},
                "mappings": {},
                "unknowns": [],
            }
        ),
        encoding="utf-8",
    )
    with pytest.raises(ValueError, match="unsupported schema_version"):
        load_profile(path)


def test_profile_globs_expand_on_windows_and_unix(tmp_path):
    (tmp_path / "one.json").write_text("{}", encoding="utf-8")
    (tmp_path / "two.json").write_text("{}", encoding="utf-8")
    assert sorted(path.name for path in _expand_profiles([tmp_path / "*.json"])) == [
        "one.json",
        "two.json",
    ]
