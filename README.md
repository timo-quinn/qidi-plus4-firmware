# QIDI Plus4 firmware research

Technical reference material for QIDI Plus4 firmware versions 1.7.3 and 1.8.2,
including printer backups, static analysis, decompilation output, reconstructed
source, and MCU flashing research. Stock-fork profiles live in the companion
[qidi-plus4-configs](https://github.com/timo-quinn/qidi-plus4-configs)
repository; the new upstream-Klipper commissioning and operating profiles live
here.

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
- [`mainline-configs/`](mainline-configs/) contains conservative, per-printer
  renderable upstream-Klipper commissioning and operating profiles.
- [`mainline-addons/`](mainline-addons/) contains opt-in, safe-default Klipper
  macro scaffolds and separate Beacon/Happy Hare integration templates.
- [`screen-bridge/`](screen-bridge/) scaffolds an independent Python bridge for
  retaining the stock serial touchscreen with mainline Moonraker.
- [`qidibox-modules/`](qidibox-modules/) contains QIDI Box Klipper modules
  recompiled from QIDI's own GPLv3 source for CPython 3.12 and 3.7 (aarch64),
  for keeping the Box working alongside a Cartographer probe.
- `data/printer-backups/` contains sensitive local inputs and is ignored by Git.

## Start here

- [Firmware changes from 1.7.3 to 1.8.2](docs/FIRMWARE-CHANGES.md)
- [Firmware lineage from factory 1.1.2 through 1.8.2](docs/FIRMWARE-LINEAGE.md)
- [GitHub-published source releases 1.3.2–1.7.1](analysis/github-releases/README.md)
- [Mainline Klipper migration](docs/MAINLINE-MIGRATION.md)
- [Box-printer runbook: 1.8.2 + Box → mainline + KlipperFleet](docs/MIGRATION-WITH-BOX.md)
- [Mainline printer configurations](mainline-configs/README.md)
- [Optional mainline add-ons](mainline-addons/README.md)
- [Firmware downloading and flashing](docs/FIRMWARE-FLASHING.md)
- [Toolhead MCU firmware analysis (load cell, timing)](docs/TOOLHEAD-MCU-FIRMWARE.md)
- [QIDI Box and third-party AMS compatibility](docs/AMS-COMPATIBILITY.md)
- [QIDI Box vs. Cartographer compiled-Python conflict](docs/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md)
- [Disabling the legacy QIDILink client on stock firmware](docs/DISABLE-QIDI-CLOUD.md)
- [Happy Hare integration notes](docs/HAPPY-HARE-INTEGRATION.md)
- [Install Happy Hare after mainline migration](docs/HAPPY-HARE-INSTALLATION.md)
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

## Community resources

This repository focuses on firmware analysis and mainline migration. For
day-to-day mods, tuning, and how-to guides, the community
[qidi-community/Plus4-Wiki](https://github.com/qidi-community/Plus4-Wiki) is the
canonical reference. Directly relevant entries there include:

- [Customisable QIDI Box firmware](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/customisable_qidibox_firmware)
  — the pure-Python Box modules and `box_macros.cfg` (a copy of the latter is
  included under [`qidibox-modules/`](qidibox-modules/)).
- [Cartographer3D install guide](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/bed-scanning-probes/cartographer3d)
  — companion to [docs/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md](docs/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md).
- [Disabling the QIDILink client](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/disable%20QIDILink-client)
  — the procedure behind [docs/DISABLE-QIDI-CLOUD.md](docs/DISABLE-QIDI-CLOUD.md).
- Hardware mods, maintenance, and slicer profiles — out of scope here; see the
  wiki.

## Publication boundary

The contents of `docs/`, `analysis/`, and `tools/` are intended to be reviewable
and publishable. `data/printer-backups/` is local source material and may contain
credentials, API keys, databases, SSH keys, and other private printer state.

## License

Original work in this repository is released under the [MIT License](LICENSE).
The reverse-engineering analysis and material derived from other open-source
projects are governed by separate terms — see [NOTICE](NOTICE) for the full
scope and attributions.

## Disclaimer

This is an independent, unofficial project. It is **not affiliated with,
authorized, endorsed, or sponsored by QIDI Technology** or Makerbase/MKS. "QIDI",
"Plus4", "QIDI Box", and related names are trademarks of their respective owners,
used here only for identification and interoperability.

The firmware analysis is static reverse engineering published for
interoperability, repair, and independent security research. QIDI retains all
copyright in its firmware; no QIDI firmware binaries are redistributed here. See
[NOTICE](NOTICE) for details and for the GPLv3 status of Klipper- and
Moonraker-derived material.

Everything here is provided "as is", without warranty of any kind. Building,
flashing, or migrating printer firmware can permanently damage hardware, void
warranties, or render a printer unbootable. You are solely responsible for
verifying every step against your own hardware and for keeping the recovery
material described above. Use at your own risk.
