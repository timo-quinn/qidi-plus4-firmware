# QIDI Plus4 stock-screen bridge

This is an early, independent replacement for QIDI's proprietary `xindi`
touchscreen daemon. The intended end state is to retain the original Plus4
front panel as a secondary local interface while mainline Klipper and Moonraker
run on the printer and a full KlipperScreen instance runs elsewhere.

The stock panel is a TJC/Nextion-style serial HMI. It renders pages from its own
touchscreen firmware and exchanges commands and events with the host over
`/dev/ttyS1`; it is not a Linux framebuffer. Consequently this project maps
Moonraker state and actions to the panel's serial protocol rather than trying
to run KlipperScreen on it.

## Current status

Research scaffold only. It currently provides:

- a dependency-free packet framer and decoder for common TJC/Nextion responses;
- a read-only serial capture command;
- versioned, deliberately incomplete screen-profile files;
- profile validation and unit tests;
- design, safety, capture, and clean-room implementation notes.

It does **not** yet update the screen, control a printer, replace `xindi`, or
install a service. Serial writes and printer actions must remain opt-in when
they are added.

## Development

```console
cd screen-bridge
python -m venv .venv
.venv/bin/python -m pip install -e '.[dev]'
.venv/bin/python -m pytest
```

On Windows, use `.venv\Scripts\python` instead.

Decode a captured packet without opening a serial port:

```console
python -m qidi_screen_bridge decode "65 01 02 01 ff ff ff"
```

Validate the research profiles:

```console
python -m qidi_screen_bridge validate-profile profiles/*.json
```

Capture bytes from a disconnected test panel or while `xindi` is stopped:

```console
sudo qidi-screen-bridge capture \
  --device /dev/ttyS1 \
  --baud <verified-runtime-baud> \
  --output captures/plus4-1.8.2.jsonl
```

This command only reads. It cannot passively observe bytes that `xindi` writes
to the same UART. See [the research guide](../docs/integrations/SCREEN-BRIDGE.md) for safe
bidirectional capture approaches.

## Publication boundary

Do not commit QIDI touchscreen binaries, printer backups, credentials, or raw
captures containing private data here. Profiles should contain independently
documented protocol mappings only. A future installer can copy the owner's
existing touchscreen resource from their own backup instead of redistributing
it.
