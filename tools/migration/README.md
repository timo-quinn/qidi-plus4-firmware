# Mainline migration tools

- `qidi_plus4.py` is the cross-platform entry point. It downloads and verifies
  the official Armbian Qidi X-6 image, builds all MCU images, audits printers,
  streams backups, bootstraps official Klipper/Moonraker, renders per-printer
  configurations, and invokes guarded flash phases.
- `bootstrap-mainline.sh` installs the upstream host stack on clean Armbian
  without FreeDi or KIAUH.
- `qidi-plus4-remote.sh` performs validation and flashing on the printer. It is
  normally streamed or uploaded by the PowerShell orchestrator.
- `mcu-layouts.json` holds the per-board flash/SRAM vector bounds used to
  validate images. It is the single source shared by `qidi_plus4.py` and
  `qidi-plus4-remote.sh`; the remote helper falls back to an identical inline
  table only when the file was not staged beside it.
- `image_factory_emmc.py` creates a guarded, verified raw image of the exact
  factory 32 GB eMMC layout. It requires a read-only source and refuses to
  overwrite existing evidence.

## Password-free SSH

Every remote action opens several SSH/SCP connections, so password
authentication is entered repeatedly across a migration. Install a key once and
later commands need no password:

```powershell
python .\tools\migration\qidi_plus4.py setup-ssh --printer $Printer --generate
```

This prompts for the printer password a single time, installs your public key
(generating an `ed25519` key if you have none), and verifies key login. A
default `~/.ssh/id_ed25519` is used automatically; for any other key, pass
`--identity <path>` to the remaining commands. On Linux/macOS the tool also
multiplexes one connection per phase, limiting keyless runs to a single prompt
per command. Windows OpenSSH does not support multiplexing, so key setup is the
way to avoid repeated prompts there.

## Staging the mainboard microSD image

`stage-mainboard-sdcard` re-validates a built mainboard image, copies it to a
FAT32 card (or a staging directory) as `qd_mcu.bin`, and writes a `.sha256`
sidecar, so the wrong image or filename cannot reach the resident bootloader:

```powershell
python .\tools\migration\qidi_plus4.py stage-mainboard-sdcard `
  --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin `
  --output E:\
```

## Post-flash connectivity check

`smoke-test` installs the inert two-MCU `smoke-test-printer.cfg` (backing up any
existing `printer.cfg`), restarts mainline Klipper, and prints the recent
`klippy.log` so both MCUs can be seen reaching `Ready` before the real
configuration is installed:

```powershell
python .\tools\migration\qidi_plus4.py smoke-test --printer $Printer
```

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

After both MCU links pass the inert smoke test, render a reviewed configuration
with the target printer's exact Beacon serial path:

```powershell
python .\tools\migration\qidi_plus4.py render-config `
  --beacon-serial '/dev/serial/by-id/usb-Beacon_Beacon_RevH_CHANGE_ME-if00' `
  --output .\artifacts\generated-configs\my-plus4
```

The output is ignored by Git and must be reviewed before installation. See the
profile's own README under [`../../mainline-configs/`](../../mainline-configs/).
