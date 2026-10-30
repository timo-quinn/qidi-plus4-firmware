# Firmware research

[All documentation](../README.md) · [Repository home](../../README.md)

Start with the lineage report for an overview, then use the detailed comparison
or controller-specific reference.

| Guide | Scope |
| --- | --- |
| [Firmware lineage](FIRMWARE-LINEAGE.md) | Factory 1.1.2 → installed 1.7.3 → installed 1.8.2 |
| [Firmware changes](FIRMWARE-CHANGES.md) | Detailed 1.7.3 vs. 1.8.2 comparison: Klipper, Moonraker, QIDI services, touchscreen, update payloads |
| [Downloading and flashing](FIRMWARE-FLASHING.md) | Update sources, package flow, controller flashing and recovery paths |
| [Toolhead MCU](TOOLHEAD-MCU-FIRMWARE.md) | Load-cell handling, timing, and recovered command dictionary |
| [Hardware inventory](LIVE-HARDWARE-INVENTORY.md) | Captured hardware, boot, MCU, USB, and service comparison |

## Files and supporting evidence

- [Firmware files and private backups](../../data/README.md), including v1.8.2 snapshots and MCU readbacks.
- [Generated firmware evidence](../../analysis/firmware/README.md).
- [Published source releases, 1.3.2–1.7.1](../../analysis/github-releases/README.md).
- [Compiled component reference](../../analysis/components/INDEX.md).
- [Analysis tools](../../tools/README.md#firmware-analysis).

For an operational conversion workflow, use the [migration guides](../migration/README.md).
