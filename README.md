# QIDI Plus4 firmware research

Technical reference material for QIDI Plus4 firmware versions 1.7.3 and 1.8.2,
including printer backups, static analysis, decompilation output, reconstructed
source, and MCU flashing research. The companion configuration profiles live in
[qidi-plus4-configs](https://github.com/timo-quinn/qidi-plus4-configs).

## Repository layout

- [`docs/`](docs/) contains the human-readable findings: the firmware change
  report, flashing research, AMS compatibility analysis, and Happy Hare notes.
- [`analysis/firmware/`](analysis/firmware/) contains generated filesystem,
  touchscreen, symbol, string, patch, and protocol evidence.
- [`analysis/components/`](analysis/components/) contains the compiled-component
  index, ARM64 disassembly, Ghidra pseudocode, and source reconstructions.
- [`tools/`](tools/) contains the backup, comparison, export, and reconstruction
  utilities. Ghidra helper scripts are grouped under [`tools/ghidra/`](tools/ghidra/).
- [`firmware-configs/`](firmware-configs/) contains reproducible Klipper and
  Katapult build fragments for the verified Plus4 controller boards.
- [`screen-bridge/`](screen-bridge/) scaffolds an independent Python bridge for
  retaining the stock serial touchscreen with mainline Moonraker.
- `data/printer-backups/` contains sensitive local inputs and is ignored by Git.

## Start here

- [Firmware changes from 1.7.3 to 1.8.2](docs/FIRMWARE-CHANGES.md)
- [Firmware lineage from factory 1.1.2 through 1.8.2](docs/FIRMWARE-LINEAGE.md)
- [Mainline Klipper migration](docs/MAINLINE-MIGRATION.md)
- [Firmware downloading and flashing](docs/FIRMWARE-FLASHING.md)
- [QIDI Box and third-party AMS compatibility](docs/AMS-COMPATIBILITY.md)
- [Happy Hare integration notes](docs/HAPPY-HARE-INTEGRATION.md)
- [Stock touchscreen bridge research](docs/SCREEN-BRIDGE.md)
- [Live hardware and runtime inventory](docs/LIVE-HARDWARE-INVENTORY.md)
- [Compiled component reference](analysis/components/INDEX.md)
- [Published-source lineage analysis](analysis/components/LINEAGE-ANALYSIS.md)

## Backing up a printer

From PowerShell on Windows:

```powershell
.\tools\Backup-QidiPlus4.ps1 `
  -Printer 'box=192.168.1.50','no-box=192.168.1.51'
```

Replace the example addresses. The script streams each compressed archive over
SSH, downloads the inventory with SCP, verifies the archive, and records its
SHA-256 digest. Use `-Expand` to extract verified archives locally.

Backups are written under `data/printer-backups/` and intentionally ignored by Git.
They may contain credentials, API keys, databases, and SSH material. These are
filesystem/source backups; MCU flash readbacks require the separately documented
procedures.

## Publication boundary

The contents of `docs/`, `analysis/`, and `tools/` are intended to be reviewable
and publishable. `data/printer-backups/` is local source material and may contain
credentials, API keys, databases, SSH keys, and other private printer state.
