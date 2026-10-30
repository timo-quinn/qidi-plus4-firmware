# Mainline migration

[All documentation](../README.md) · [Repository home](../../README.md)

Read these guides in order as they apply to your hardware. The mainline guide
contains the backup, audit, recovery, and commissioning gates.

1. [Mainline Klipper migration](MAINLINE-MIGRATION.md): prepare the host and
   MCU stack and commission a conservative printer configuration.
2. [Migration with QIDI Box](MIGRATION-WITH-BOX.md): the 1.8.2 Box-printer
   runbook, including the KlipperFleet workflow and Box-specific constraints.
3. [Happy Hare installation](HAPPY-HARE-INSTALLATION.md): post-migration
   installation, commissioning, and OrcaSlicer workflow; read its hardware
   compatibility requirements first.

## Tools and configuration

- [Migration CLI and helpers](../../tools/migration/README.md).
- [MCU build fragments](../../firmware-configs/README.md).
- [Bundled runtime profiles](../../mainline-configs/README.md).
- [Optional macros and integrations](../../mainline-addons/README.md).
- [Firmware and recovery file locations](../../data/README.md).

The [dated QIDI1 reviews](../history/README.md) provide implementation evidence
and printer-specific context. Check them alongside the guides when following
the QIDI1 route.
