"""Read-only UART capture support."""

from __future__ import annotations

import json
import time
from pathlib import Path
from typing import BinaryIO

from .protocol import PacketFramer, decode_packet


def capture_serial(
    device: str,
    baud: int,
    output: Path,
    *,
    timeout: float = 0.25,
    raw_stream: BinaryIO | None = None,
) -> None:
    """Capture screen-to-host packets without transmitting any bytes."""

    import serial

    framer = PacketFramer()
    output.parent.mkdir(parents=True, exist_ok=True)
    with serial.Serial(device, baudrate=baud, timeout=timeout) as port, output.open(
        "a", encoding="utf-8"
    ) as log:
        while True:
            chunk = port.read(port.in_waiting or 1)
            if not chunk:
                continue
            if raw_stream is not None:
                raw_stream.write(chunk)
                raw_stream.flush()
            for packet in framer.feed(chunk):
                record = {"timestamp": time.time(), **decode_packet(packet).as_dict()}
                log.write(json.dumps(record, sort_keys=True) + "\n")
                log.flush()
