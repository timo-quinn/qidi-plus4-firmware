# Local artifacts

[Repository home](../README.md) · [Stock firmware and backups](../data/README.md)

This directory is for reproducible build output, downloaded images, rendered
printer configurations, and temporary migration evidence. Everything except
this README is ignored by Git.

Files here are never an authoritative printer configuration. Rendered profiles
may contain device serial numbers, and live captures may contain other private
machine state. Review and sanitize them before copying anything into a tracked
repository.

`tools/migration/qidi_plus4.py` writes its default firmware and image output
here. `render-config` may also write to an explicit external workspace; it will
only replace a directory previously marked as managed by that command.

| Default location | Output |
| --- | --- |
| `artifacts/mainline-firmware/` | Built mainboard Klipper, toolhead Klipper, toolhead Katapult, and build metadata |
| `artifacts/armbian/` | Downloaded host images and checksum sidecars |

See the [migration tools](../tools/migration/README.md) for output options.
Stock v1.8.2 snapshots and MCU readbacks are under
`data/printer-backups/retained/`; see the [file location index](../data/README.md).
