# Mainline migration tools

- `qidi_plus4.py` is the cross-platform entry point. It downloads and verifies
  the official Armbian Qidi X-6 image, builds all MCU images, audits printers,
  streams backups, bootstraps official Klipper/Moonraker, and invokes guarded
  flash phases.
- `bootstrap-mainline.sh` installs the upstream host stack on clean Armbian
  without FreeDi or KIAUH.
- `qidi-plus4-remote.sh` performs validation and flashing on the printer. It is
  normally streamed or uploaded by the PowerShell orchestrator.
- `image_factory_emmc.py` creates a guarded, verified raw image of the exact
  factory 32 GB eMMC layout. It requires a read-only source and refuses to
  overwrite existing evidence.

On Windows, first confirm the USB eMMC disk number in an Administrator
PowerShell and mark it read-only:

```powershell
Get-Disk -Number 1
Set-Disk -Number 1 -IsReadOnly $true
```

Removable readers may not support taking the disk offline. Read-only is the
required protection. Then, from an elevated terminal:

```powershell
python .\tools\migration\image_factory_emmc.py `
  --device '\\.\PhysicalDrive1' `
  --output .\data\printer-backups\factory-emmc `
  --confirm IMAGE-FACTORY-EMMC
```

The tool validates the exact disk size and MBR layout before copying. Never
change the disk number without repeating `Get-Disk` and checking its size.

Read [`../../docs/MAINLINE-MIGRATION.md`](../../docs/MAINLINE-MIGRATION.md)
before using any action other than `Audit` or `Validate*`.
