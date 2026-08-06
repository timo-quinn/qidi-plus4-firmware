# Documentation

Human-readable findings and practical integration guidance:

- [FIRMWARE-CHANGES.md](FIRMWARE-CHANGES.md) compares firmware 1.7.3 and 1.8.2
  across Klipper, Moonraker, QIDI services, the touchscreen, and update payloads.
- [FIRMWARE-LINEAGE.md](FIRMWARE-LINEAGE.md) extends that analysis backward
  through the pristine factory 1.1.2 image.
- [FIRMWARE-FLASHING.md](FIRMWARE-FLASHING.md) documents QIDI's update sources,
  package flow, and the known flashing paths for each controller.
- [MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md) provides the guarded,
  SSH-first conversion workflow for a clean mainline host and MCU stack.
- [AMS-COMPATIBILITY.md](AMS-COMPATIBILITY.md) focuses on QIDI Box and
  third-party AMS interoperability.
- [QIDI-BOX-CONFIG-REGENERATION.md](QIDI-BOX-CONFIG-REGENERATION.md) documents
  how stock `box_detect` regenerates `box.cfg` from `/home/mks/cfg_with_N` and
  the consequences for configuration synchronization.
- [HAPPY-HARE-INTEGRATION.md](HAPPY-HARE-INTEGRATION.md) records the QIDI Box
  hardware interface and possible Happy Hare integration approaches.
- [HAPPY-HARE-INSTALLATION.md](HAPPY-HARE-INSTALLATION.md) provides the guarded
  post-migration install, commissioning and OrcaSlicer workflow.
- [SCREEN-BRIDGE.md](SCREEN-BRIDGE.md) defines the evidence, capture plan,
  safety boundary, and staged independent replacement for QIDI's `xindi`.
- [LIVE-HARDWARE-INVENTORY.md](LIVE-HARDWARE-INVENTORY.md) records the
  sanitized runtime hardware, boot, MCU, USB, and service comparison.
- [PLR-TIMER-TOO-CLOSE.md](PLR-TIMER-TOO-CLOSE.md) provides the standalone,
  transactional repair and rollback procedure for the diagnosed QIDI
  power-loss-recovery `Timer too close` failure.

Generated evidence supporting these documents is under [`../analysis/`](../analysis/).
