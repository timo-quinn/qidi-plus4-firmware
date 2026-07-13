# Documentation

Human-readable findings and practical integration guidance:

- [FIRMWARE-CHANGES.md](FIRMWARE-CHANGES.md) compares firmware 1.7.3 and 1.8.2
  across Klipper, Moonraker, QIDI services, the touchscreen, and update payloads.
- [FIRMWARE-FLASHING.md](FIRMWARE-FLASHING.md) documents QIDI's update sources,
  package flow, and the known flashing paths for each controller.
- [MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md) provides the guarded,
  SSH-first conversion workflow for a clean mainline host and MCU stack.
- [AMS-COMPATIBILITY.md](AMS-COMPATIBILITY.md) focuses on QIDI Box and
  third-party AMS interoperability.
- [HAPPY-HARE-INTEGRATION.md](HAPPY-HARE-INTEGRATION.md) records the QIDI Box
  hardware interface and possible Happy Hare integration approaches.
- [SCREEN-BRIDGE.md](SCREEN-BRIDGE.md) defines the evidence, capture plan,
  safety boundary, and staged independent replacement for QIDI's `xindi`.

Generated evidence supporting these documents is under [`../analysis/`](../analysis/).
