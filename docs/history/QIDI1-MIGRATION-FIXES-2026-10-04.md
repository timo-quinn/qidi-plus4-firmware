# QIDI1 migration fixes and preparation — 2026-10-04

The software and workstation findings from the
[migration review](QIDI1-MIGRATION-REVIEW-2026-10-04.md) have been addressed.
QIDI1 remains stock. No board was flashed, eMMC replaced, printer configuration
changed, or printer service restarted. QIDI Box restoration remains a separate
phase after single-material commissioning.

## Implemented fixes

| Finding | Correction |
| --- | --- |
| Stock config incorrectly superseded smoke-test | Installed-config evidence requires a mainline bootstrap receipt and live, ready MCU evidence. Both Plus4 naming conventions are accepted; missing evidence stays indeterminate. |
| Sparse historical QIDI2 journal suggested repeat work | Resume and dry-run recognize a proven commissioned mainline baseline without rewriting history or repeating migration. |
| Bootstrap ignored the printer owner | Helpers stream into the `--printer-user` shell through sudo. `mks` owns the stack even when SSH connects as `plab`. Private temporary helpers are cleaned up. Firmware staging also uses the printer owner. |
| Runtime tuning audited before UARTs opened | Bootstrap performs `audit-early`. Smoke-test requires the full strict UART/runtime audit after startup. |
| Fresh host could not report idle | Interactive resume can require physical idle/heaters-off acknowledgement for known unavailable states or the exact inert smoke config. Printing, paused, authorization and arbitrary malformed responses cannot be overridden; unattended execution halts. |
| Moving source refs and unmatched images | Full commit SHAs replace moving defaults. Dirty or mismatched source trees fail before build. Printerlab verifies complete image manifests before bootstrap, card staging and flash actions. |
| Native Windows build could not use Linux tooling | WSL support accepts Linux source paths and translates Windows artifact paths. The inventory-driven build has succeeded. |
| Old audit/backup entries authorized preparation | Stock preparation records expire after 24 hours before cutover starts. Original journal records remain intact; recovery evidence does not expire after cutover. A fresh QIDI1 backup was verified. |
| Smoke action only printed logs | It waits for the inert config and both ready MCUs, then requires runtime tuning. Failures return nonzero and retain the inert config. |
| Toolhead recovery dump stayed on the host | Before erase, the wrapper transfers and verifies a 64 KiB workstation dump. A second attached-board read must match its hash before erase. |
| Copied calibration and optional includes on first start | `--commissioning` enables hardware/Beacon only, uses uncalibrated conservative defaults, clears active copied shapers/PIDs/pressure advance, and disables production/Box/Shake&Tune includes. Production files remain available for later review. |
| Beacon host dependency absent | `--beacon-ref` installs the pinned host module without updating probe firmware. The upstream [installer](https://github.com/beacon3d/beacon_klipper/blob/3eb0134607664734ccf5cd94cb51840e1c8b27b3/install.sh) combines host installation with probe updates; bootstrap performs only the host steps. |
| Armbian alias resolved to an older kernel | Downloader resolves the exact filename before transfer, checks a reviewed minimum (default `6.18.54`), accepts an exact HTTPS URL, and records URL/kernel/checksum. Boot/UART qualification remains separate. |
| Stale executable and profile path | Rebuilt `printerlab/bin/plab.exe`, corrected QIDI2's profile path, and added separate QIDI1 source, firmware, render and Beacon settings. The previous inventory was preserved beside the updated file. |

## Prepared install set

| Component | Pinned source |
| --- | --- |
| Klipper host and MCU applications | `214fdb2877ff4640e9316a663c1b8b2e232c86fd` |
| Moonraker | `1cfb0c41e468645951a371621f06d32777b6107c` |
| Katapult | `ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e` |
| Beacon host plugin | `3eb0134607664734ccf5cd94cb51840e1c8b27b3` |
| ARM compiler | GNU Arm Embedded `13.2.1 20231009` |

Built firmware is in ignored `artifacts/qidi1-mainline-firmware/`, separate
from QIDI2's retained July artifacts. Two builds produced identical images.
The manifest records commits, compiler, build time and hashes.

| Image | Bytes | SHA-256 |
| --- | ---: | --- |
| Mainboard app, `0x08008000` | 43508 | `a30a33b5bb1e9b951897ccbbd61858d0f78a4a3e35d560c9a934be0910ae5780` |
| Toolhead app, `0x08002000` | 41748 | `914f9ccaede00f1da924b0fd50dd0f968f3e5dbf7460376f19878a107503c5a1` |
| Toolhead Katapult, `0x08000000` | 3064 | `0dd57900801553b64e8729878e6e0f126e555a411965e9b82ba43f001c6c6e7f` |

QIDI1's private candidate is in ignored `artifacts/qidi1-mainline-config/`.
Its entry point is the commissioning profile. Machine serials remain in local
inventory and ignored render metadata; the current stock desktop workspace and
live printer config are unchanged.

The fresh filesystem backup is
`artifacts/backups/qidi1-pre-mainline-20261004/qidi1/qidi-plus4-qidi1-20261004-143902.tar.gz`,
SHA-256 `94dc2ff873ce1b0b676960cb5e659beda286ebf704395d3befd118922281e515`.
Audit, backup, build and render are recorded in QIDI1's local journal.
Filesystem recovery and MCU recovery remain distinct.

## Verification and remaining gates

- Full Windows Python suite: **259 passed, 10 shell cases skipped**.
- Linux migration suite: **130 passed**, including those shell cases.
- Ruff, shell syntax checks, Go tests/vet and executable build: passed.
- Real WSL firmware builds and inventory-driven commissioning render: passed.
- Read-only live reconciliation: QIDI1 remains uncommissioned; QIDI2 qualifies.
- QIDI1 dry-run halts at missing `migration.sdcard`; QIDI2 dry-run executes
  nothing and recognizes its commissioned baseline.

Bootstrap and flash behavior have regression coverage, but neither operation
was run on a live printer during this fix work. Physical qualification remains
required. Identify the actual FAT32 card, qualify the replacement eMMC image,
kernel and UARTs, prepare `mks`/management access, configure Moonraker
authentication or a controlled SSH loopback tunnel, and confirm PB4 fan wiring
and the Beacon mount. Review the candidate before installation. Accelerometer
orientation, heaters, probe, homing and motion require target commissioning and
calibration. Refresh the backup if the stock printer changes or preparation
ages past its gate.
