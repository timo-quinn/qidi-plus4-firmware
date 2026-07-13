# Mainline migration tools

- `qidi_plus4.py` is the cross-platform entry point. It downloads and verifies
  the official Armbian Qidi X-6 image, builds all MCU images, audits printers,
  streams backups, bootstraps official Klipper/Moonraker, and invokes guarded
  flash phases.
- `bootstrap-mainline.sh` installs the upstream host stack on clean Armbian
  without FreeDi or KIAUH.
- `qidi-plus4-remote.sh` performs validation and flashing on the printer. It is
  normally streamed or uploaded by the PowerShell orchestrator.

Read [`../../docs/MAINLINE-MIGRATION.md`](../../docs/MAINLINE-MIGRATION.md)
before using any action other than `Audit` or `Validate*`.
