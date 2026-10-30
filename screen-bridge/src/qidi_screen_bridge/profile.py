"""Versioned screen-profile loading and conservative validation."""

from __future__ import annotations

import json
from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass(frozen=True)
class ScreenProfile:
    path: Path
    schema_version: int
    profile_id: str
    printer_model: str
    firmware_release: str
    serial_device: str
    runtime_baud: int | None
    screen_resource_sha256: str | None
    screen_resource_size: int | None
    ui_version: str | None
    mappings: dict[str, Any]
    unknowns: tuple[str, ...]


def load_profile(path: str | Path) -> ScreenProfile:
    source = Path(path)
    data = json.loads(source.read_text(encoding="utf-8"))
    required = {
        "schema_version",
        "profile_id",
        "printer_model",
        "firmware_release",
        "serial",
        "mappings",
        "unknowns",
    }
    missing = sorted(required.difference(data))
    if missing:
        raise ValueError(f"{source}: missing keys: {', '.join(missing)}")
    if data["schema_version"] != 1:
        raise ValueError(f"{source}: unsupported schema_version {data['schema_version']!r}")

    serial = data["serial"]
    if not isinstance(serial, dict) or not isinstance(serial.get("device"), str):
        # Malformed JSON values retain the profile loader ValueError contract.
        raise ValueError(f"{source}: serial.device must be a string")  # noqa: TRY004
    baud = serial.get("runtime_baud")
    if baud is not None and (not isinstance(baud, int) or baud <= 0):
        raise ValueError(f"{source}: serial.runtime_baud must be a positive integer or null")
    if not isinstance(data["mappings"], dict):
        # Malformed JSON values retain the profile loader ValueError contract.
        raise ValueError(f"{source}: mappings must be an object")  # noqa: TRY004
    if not isinstance(data["unknowns"], list) or not all(
        isinstance(item, str) for item in data["unknowns"]
    ):
        raise ValueError(f"{source}: unknowns must be an array of strings")

    resource = data.get("screen_resource", {})
    if not isinstance(resource, dict):
        # Malformed JSON values retain the profile loader ValueError contract.
        raise ValueError(f"{source}: screen_resource must be an object")  # noqa: TRY004
    digest = resource.get("sha256")
    if digest is not None and (
        not isinstance(digest, str)
        or len(digest) != 64
        or any(character not in "0123456789abcdefABCDEF" for character in digest)
    ):
        raise ValueError(f"{source}: screen_resource.sha256 must be a SHA-256 hex digest")
    resource_size = resource.get("size")
    if resource_size is not None and (
        not isinstance(resource_size, int) or resource_size <= 0
    ):
        raise ValueError(f"{source}: screen_resource.size must be a positive integer")

    return ScreenProfile(
        path=source,
        schema_version=1,
        profile_id=str(data["profile_id"]),
        printer_model=str(data["printer_model"]),
        firmware_release=str(data["firmware_release"]),
        serial_device=serial["device"],
        runtime_baud=baud,
        screen_resource_sha256=digest.lower() if digest else None,
        screen_resource_size=resource_size,
        ui_version=resource.get("ui_version"),
        mappings=data["mappings"],
        unknowns=tuple(data["unknowns"]),
    )
