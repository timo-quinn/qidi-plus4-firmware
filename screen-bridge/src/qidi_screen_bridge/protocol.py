"""Small, side-effect-free helpers for the TJC/Nextion serial protocol.

Only common response types are named here. QIDI-specific messages must be
captured and documented before being added to a screen profile.
"""

from __future__ import annotations

from dataclasses import dataclass
from enum import Enum

TERMINATOR = b"\xff\xff\xff"


class EventKind(str, Enum):
    TOUCH = "touch"
    PAGE = "page"
    STRING = "string"
    NUMBER = "number"
    READY = "ready"
    ACK = "ack"
    ERROR = "error"
    UNKNOWN = "unknown"


@dataclass(frozen=True)
class ScreenEvent:
    kind: EventKind
    raw: bytes
    page_id: int | None = None
    component_id: int | None = None
    pressed: bool | None = None
    value: int | str | None = None
    code: int | None = None

    def as_dict(self) -> dict[str, object]:
        result: dict[str, object] = {"kind": self.kind.value, "raw_hex": self.raw.hex(" ")}
        for name in ("page_id", "component_id", "pressed", "value", "code"):
            value = getattr(self, name)
            if value is not None:
                result[name] = value
        return result


class PacketFramer:
    """Split an arbitrary byte stream at the three-byte HMI terminator."""

    def __init__(self, max_packet_size: int = 65536) -> None:
        if max_packet_size < len(TERMINATOR):
            raise ValueError("max_packet_size is too small")
        self._buffer = bytearray()
        self._max_packet_size = max_packet_size

    def feed(self, data: bytes) -> list[bytes]:
        self._buffer.extend(data)
        packets: list[bytes] = []
        while (end := self._buffer.find(TERMINATOR)) >= 0:
            if end > self._max_packet_size:
                self._buffer.clear()
                raise ValueError("screen packet exceeded the size limit")
            packets.append(bytes(self._buffer[:end]))
            del self._buffer[: end + len(TERMINATOR)]
        if len(self._buffer) > self._max_packet_size:
            self._buffer.clear()
            raise ValueError("unterminated screen packet exceeded the size limit")
        return packets


def encode_command(command: str) -> bytes:
    """Encode one ASCII HMI command.

    The bridge must use a separate escaping helper before interpolating text;
    accepting terminators or control characters here would make command
    boundaries ambiguous.
    """

    if not command or any(ord(char) < 0x20 for char in command):
        raise ValueError("command must be non-empty and contain no control characters")
    encoded = command.encode("ascii")
    if TERMINATOR in encoded:
        raise ValueError("command contains a packet terminator")
    return encoded + TERMINATOR


def quote_text(value: str) -> str:
    """Quote text for an HMI string property using a conservative character set."""

    if any(char in value for char in ('"', "\r", "\n", "\x00")):
        raise ValueError("screen text contains an unsupported character")
    return f'"{value}"'


def decode_packet(packet: bytes) -> ScreenEvent:
    """Decode a packet body (with or without its trailing terminator)."""

    packet = packet.removesuffix(TERMINATOR)
    if not packet:
        return ScreenEvent(EventKind.UNKNOWN, packet)

    code = packet[0]
    if code == 0x65 and len(packet) == 4:
        return ScreenEvent(
            EventKind.TOUCH,
            packet,
            page_id=packet[1],
            component_id=packet[2],
            pressed=bool(packet[3]),
        )
    if code == 0x66 and len(packet) == 2:
        return ScreenEvent(EventKind.PAGE, packet, page_id=packet[1])
    if code == 0x70:
        return ScreenEvent(EventKind.STRING, packet, value=packet[1:].decode("utf-8", "replace"))
    if code == 0x71 and len(packet) == 5:
        return ScreenEvent(EventKind.NUMBER, packet, value=int.from_bytes(packet[1:], "little"))
    if code == 0x88 and len(packet) == 1:
        return ScreenEvent(EventKind.READY, packet)
    if code == 0x01 and len(packet) == 1:
        return ScreenEvent(EventKind.ACK, packet, code=code)
    if code in {0x00, 0x02, 0x03, 0x04, 0x05, 0x11, 0x12, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F}:
        return ScreenEvent(EventKind.ERROR, packet, code=code)
    return ScreenEvent(EventKind.UNKNOWN, packet, code=code)
