"""Stable boundaries for future UART and Moonraker implementations.

These protocols intentionally describe capabilities rather than selecting a
serial or HTTP library. They let captured protocol fixtures drive development
without requiring a printer connection.
"""

from __future__ import annotations

from collections.abc import AsyncIterator
from dataclasses import dataclass, field
from typing import Protocol

from .protocol import ScreenEvent


@dataclass(frozen=True)
class PrinterSnapshot:
    """Backend-neutral state suitable for the first read-only milestone."""

    state: str
    extruder_temperature: float | None = None
    extruder_target: float | None = None
    bed_temperature: float | None = None
    bed_target: float | None = None
    progress: float | None = None
    filename: str | None = None
    position: tuple[float, float, float] | None = None
    extra: dict[str, object] = field(default_factory=dict)


class ScreenTransport(Protocol):
    """A TJC screen connection; read and write enablement stay separate."""

    def events(self) -> AsyncIterator[ScreenEvent]: ...

    async def send(self, command: str) -> None: ...


class PrinterBackend(Protocol):
    """Moonraker-facing boundary using normalized bridge state and actions."""

    def snapshots(self) -> AsyncIterator[PrinterSnapshot]: ...

    async def invoke(self, action: str, parameters: dict[str, object]) -> None: ...


@dataclass(frozen=True)
class BridgePolicy:
    """Fail-closed policy applied before any future printer action."""

    screen_writes_enabled: bool = False
    printer_actions_enabled: bool = False
    allowed_actions: frozenset[str] = frozenset()

    def permits_action(self, action: str) -> bool:
        return self.printer_actions_enabled and action in self.allowed_actions
