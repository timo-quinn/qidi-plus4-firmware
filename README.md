# QIDI Plus4 firmware research

Firmware research, recovery references, and mainline Klipper migration tools
for the QIDI Plus4. The research covers factory 1.1.2, installed 1.7.3 and
1.8.2 systems, and QIDI's published source releases from 1.3.2 to 1.7.1.

## Find what you need

| I want to… | Start here |
| --- | --- |
| Find firmware files or backups, including v1.8.2 | [Firmware and backup locations](data/README.md) |
| Understand firmware versions and changes | [Firmware research](docs/firmware/README.md) |
| Understand downloading, flashing, and recovery | [Firmware flashing reference](docs/firmware/FIRMWARE-FLASHING.md) |
| Migrate to mainline Klipper | [Migration guides](docs/migration/README.md) |
| Work with QIDI Box, Happy Hare, or the stock screen | [Integration research](docs/integrations/README.md) |
| Fix stock-firmware problems | [Fixes and compatibility](docs/fixes/README.md) |
| Back up a printer or regenerate research | [Tools](tools/README.md) |
| Contribute or run checks | [Contributing](CONTRIBUTING.md) |

The [documentation index](docs/README.md) covers every guide. Dated printer
reviews and implementation notes are kept separately in [history](docs/history/README.md).

## Repository map

| Directory | Contents |
| --- | --- |
| [docs/](docs/README.md) | Guides and findings, grouped by topic |
| [tools/](tools/README.md) | Backup, analysis, and migration utilities |
| [analysis/](analysis/README.md) | Generated evidence and preserved vendor source |
| [firmware-configs/](firmware-configs/README.md) | MCU build fragments for Klipper and Katapult |
| [mainline-configs/](mainline-configs/README.md) | Transitional runtime configuration profiles |
| [mainline-addons/](mainline-addons/README.md) | Optional macros and integration templates |
| [qidibox-modules/](qidibox-modules/README.md) | Rebuildable Box modules and compatibility overlays |
| [plr-hardening/](plr-hardening/README.md) | Stock power-loss recovery repair |
| [screen-bridge/](screen-bridge/README.md) | Experimental stock touchscreen bridge |
| [data/](data/README.md) | Private local inputs; backups are ignored by Git |
| [artifacts/](artifacts/README.md) | Local build output, downloads, and live captures; ignored by Git |

Runtime profile development belongs in the companion
[qidi-plus4-configs](https://github.com/cl-tim/qidi-plus4-configs) repository.
The bundled `mainline-configs/` profiles remain a compatibility fallback;
`render-config --profile-dir` can consume external profiles directly.

## Community resources

This repository focuses on firmware analysis and mainline migration. For
day-to-day mods, tuning, and how-to guides, the community
[qidi-community/Plus4-Wiki](https://github.com/qidi-community/Plus4-Wiki) is the
canonical reference. Directly relevant entries there include:

- [Customisable QIDI Box firmware](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/customisable_qidibox_firmware)
  — the pure-Python Box modules and `box_macros.cfg` (a copy of the latter is
  included under [`qidibox-modules/`](qidibox-modules/)).
- [Cartographer3D install guide](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/bed-scanning-probes/cartographer3d)
  — companion to [docs/integrations/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md](docs/integrations/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md).
- [Disabling the QIDILink client](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/disable%20QIDILink-client)
  — the procedure behind [docs/fixes/DISABLE-QIDI-CLOUD.md](docs/fixes/DISABLE-QIDI-CLOUD.md).
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
