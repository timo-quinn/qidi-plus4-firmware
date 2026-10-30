# QIDI1 mainline migration review — 2026-10-04

Follow-up: findings below describe the review-time implementation.
See [implemented fixes and preparation](QIDI1-MIGRATION-FIXES-2026-10-04.md)
for their current status and remaining physical gates.

## Decision

Use QIDI2's proven route for QIDI1: spare Armbian eMMC, the retained QIDI
mainboard microSD bootloader, and a one-time ST-Link installation of toolhead
Katapult. The owner chose **single-material commissioning first, QIDI Box
restoration later**. Leave the Box MCU and stock display firmware unchanged
during the base migration.

The physical route remains appropriate. The main improvements are preparing the
replacement host and config before the outage, pinning build inputs, and fixing
or explicitly avoiding the automation gaps below. This review did not flash
firmware, restart services, install software on a printer, or change printer
configuration.

The [upstream research appendix](QIDI1-UPSTREAM-REVIEW-2026-10-04.md) records
dated sources, changes that have merged, and alternatives that remain untested
on this hardware.

## What actually worked on QIDI2

Read-only SSH, Moonraker queries and the checked-in host-tuning audit on
2026-10-04 confirmed:

| Evidence | QIDI1 | QIDI2 |
| --- | --- | --- |
| Current state | Stock QIDI stack, ready and standby | Mainline stack, ready and standby |
| Host OS | Debian 10 / Python 3.7.3 | Debian 13 / Python 3.13.5 |
| Kernel | 5.16.20-rockchip64 | 6.18.54-current-rockchip64 |
| Armbian identity | Vendor Makerbase image | Qidi X-6, 26.11.0-trunk.68, nightly |
| Host Klipper commit | `96ab906946ed558b961a7d8e0e56fb6aebf15316` | `214fdb2877ff4640e9316a663c1b8b2e232c86fd` |
| Host Moonraker commit | `346a3d7c9dca6499bdef2957ca39a23c702b0268` | `1cfb0c41e468645951a371621f06d32777b6107c` |
| Katapult checkout | Absent | `ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e` |
| Connected devices | Toolhead, mainboard, Beacon, Box | Toolhead, mainboard, Beacon |
| Serial gettys | Disabled | Masked |
| Klipper service owner | `mks` (existing inventory) | `mks` (live service) |

QIDI2's bootstrap receipt is dated 2026-07-13. Its two MCUs still report
`v0.13.0-707-gf604aeeea`, STM32F103xE toolhead and STM32F401xC mainboard,
both at 500000 baud. This agrees with the retained July build metadata; its
host has subsequently been updated. Both MCUs report `mcu_kconfig: null`,
consistent with firmware built before Klipper added embedded build configs.

QIDI2's effective tuning audit passed: performance governor, Klipper CPUs 1–2,
toolhead UART IRQ on CPU 1, mainboard UART IRQ on CPU 2, Moonraker CPUs 0 and 3,
and no active irqbalance/ondemand service. Reuse this established tuning. Camera
and display workloads already live on companion hosts; putting them back on
the RK3328 would add migration work and load.

The old statement that official Armbian had not been boot-tested is obsolete.
However, the working nightly installation does not prove that the current
download alias has the same kernel or fixes. Record and check the actual image
chosen for QIDI1.

## Recent discoveries that matter

1. **Armbian support improved.** Qidi X-6 was promoted to standard support on
   2026-08-13; its board definition is now `.conf`, not `.csc`. Imager first-boot
   profiles can prepare the account and SSH key before installation. Imager
   2.0.4 also fixes preset handling and displays the kernel version. These can
   reduce first-boot account/network work. Confirm passwordless sudo separately.
   [Board promotion](https://github.com/armbian/build/pull/10412),
   [Imager release](https://github.com/armbian/imager/releases/tag/v2.0.4).

2. **A newer serial-driver fix deserves an image gate.** The August UART DMA
   reopen fix addresses a specific crash when a port is reopened. The current
   image alias inspected by the upstream review still resolves to kernel
   6.18.44, predating that stable-kernel fix; QIDI2 currently runs 6.18.54.
   Check the selected kernel and its backports rather than assuming the latest
   download alias contains the fix. This is not evidence that all Klipper
   timing failures have been solved. See the appendix for the patch chain.

3. **Firmware verification is better.** September Klipper changes embed the
   build configuration and expose `mcu_kconfig`. Fresh QIDI1 firmware can
   therefore be checked for the intended MCU, UART, baud and flash offset
   after it connects. Retain binary hashes and source commits as well.
   [Embedded config change](https://github.com/Klipper3d/klipper/commit/8aa2ed3),
   [MCU status change](https://github.com/Klipper3d/klipper/commit/8c29c0a).

4. **The later Box phase has a better starting point.** Happy Hare 4 was
   released on 2026-08-30, and current upstream has a QIDI Box board/type
   preset. This supersedes the assumption that an entirely bespoke integration
   is the only starting point. The preset still needs comparison with QIDI1's
   retained Box pin map, Plus4 toolhead namespace and shared sensors. Stock
   serial recognition does not prove protocol compatibility or factory RFID
   parity on our Box revision. Keep it outside the base migration.
   [Release](https://github.com/moggieuk/Happy-Hare/releases/tag/v4.0.0),
   [Board preset](https://github.com/moggieuk/Happy-Hare/blob/main/installer/boards/custom/Kconfig.qidi_box).

The reviewed Plus4 flashing guides have not gained a confirmed new shortcut
that removes the initial toolhead SWD step. FreeDi changes still under review
are not a reason to replace the proven host installation. Mainboard Katapult
via an SD-loaded deployer is an older maintenance alternative, not a necessary
step for this migration.

## Local process findings

### Resolve before using automatic resume

**Stock config is accepted as completed mainline commissioning — reproduced.**
The current `plab mainline state qidi1` reports `install-config` satisfied and
skips `smoke-test` as superseded while QIDI1 is still stock. The
[`config.installed` probe](../../tools/migration/probes.py) only checks for a
non-placeholder config containing at least two MCU sections. It does not
establish mainline provenance or successful commissioning. If the stock config
is restored onto the new host, that same classification can hide an essential
check. Use explicit smoke-test and install-config gates; repair the probe before
relying on resume. QIDI2's journal also does not record its historical flashes,
so an empty stage entry is not proof that a commissioned printer needs flashing.

**Bootstrap account selection conflicts with this inventory — source review.**
The inventory uses `user: plab` and `printerUser: mks`. The
[`bootstrap_host` action](../../tools/migration/qidi_plus4.py) uploads and executes
the bootstrap under the SSH user's home; the
[`bootstrap script`](../../tools/migration/bootstrap-mainline.sh) makes that user
the service owner. It ignores `--printer-user`. Running the current command
with that inventory would create the host stack under `plab`, while probes and
flash helpers expect `mks`. Bootstrap the new host explicitly as `mks`, with its
own authorized key, until account selection is fixed. Re-establish the separate
management account on the new image afterward.

**Fresh-host transitions need explicit handling — source review.** Printerlab
resume requires a Moonraker `print_stats` idle response for host bootstrap and
smoke-test. A fresh image has no Moonraker, and the inert smoke config has no
`print_stats`; automatic progression can stop at those transitions. Explicit
stage commands expose `--allow-unverified-idle` for physical confirmation.
That flag does not choose the correct user or fix the config probe.

The bootstrap also runs a strict runtime tuning audit while deliberately
leaving Klipper stopped. Late UART affinity is applied by Klipper's post-start
hook. On a clean host, the audit can fail before the bootstrap receipt is
written. Rehearse the current bootstrap on the spare host and separate
installation/early-tuning success from the later smoke-test/runtime audit;
do not remove the post-start tuning check to work around it.

### Straightforward preparation improvements

- **Build current Printerlab before use.** The local `bin/plab.exe` was older
  than the inventory's `hlab`/`klipperScreen` fields and rejected the config.
  A fresh `bin/plab-review.exe` build parsed it and passed QIDI1's read-only
  preflight. This was a stale executable, not a malformed inventory.
- **Use the renamed sanitized profile.** Both flashing docs and the QIDI2
  inventory still referenced `printers/qidi2`, which no longer exists. The
  reviewed source is `qidi-plus4-configs/printers/mainline-klipper-beacon`.
  QIDI1 currently has no migration build/source/card/Beacon defaults. The dry
  run halts at missing `klipperDir` and `katapultDir`.
- **Pin one install set.** The retained MCU images were built from July
  Klipper `f604aeeea3398b70df0456851931f955d981cfc4`; bootstrap defaults to
  current `master`, and resume hardcodes those moving refs. For the new install,
  build both MCU apps from one reviewed commit and pass that same commit to
  host bootstrap. Record Moonraker, Katapult, compiler and image hashes too.
  QIDI2 proves its current host can run the older MCUs; matching initial builds
  nevertheless makes provenance and recovery easier.
- **Prepare host dependencies explicitly.** Core bootstrap does not install
  Beacon, Shake&Tune, nginx/Mainsail or a display UI. The selected profile has
  active Beacon and Shake&Tune sections. Install the chosen plugins before
  enabling those includes, or defer optional tuning includes until installed.
  The existing companion screen avoids making touchscreen firmware part of
  the migration.
- **Keep the first config minimal.** The sanitized full profile carries
  measured shapers/PIDs, PB4 fan modifications and rear service-area moves.
  The renderer substitutes a Beacon path; it does not strip source-printer
  calibration. QIDI1's local config also shows a PB4 cooling fan and X=14,
  Y=-11 Beacon mount, but physical wiring still needs confirmation. Recalibrate
  QIDI1 and enable production macros only after cold hardware checks.
- **Refresh the backup gate.** QIDI1's journal records backup/audit complete
  on 2026-08-06 and therefore skips them. Take a current backup immediately
  before migration. Retained 1.8.2 mainboard, toolhead and Box full dumps
  were rehashed during this review and all match their manifest. Filesystem
  backup remains distinct from MCU recovery evidence.
- **Preserve recovery evidence off the printer.** The SWD helper's new
  toolhead readback stays in its remote backup directory. Copy and verify it
  on the workstation before removing the new host or considering rollback.
  An eMMC swap restores the host only; MCU rollback is a separate operation.

## Revised QIDI1 sequence

| Phase | Work | Gate |
| --- | --- | --- |
| Prepare workstation | Build current CLI, choose pinned sources and artifact paths, render a separate QIDI1 mainline candidate | No stale profile paths or copied machine identity/calibration |
| Prepare replacement host | Image spare eMMC, prepare `mks` account/key, boot-test network and UART nodes, rehearse core/bootstrap dependencies | Keep original eMMC intact; correct service owner; record image/kernel |
| Refresh recovery | Current QIDI1 filesystem backup, verify existing MCU dumps and planned images | Backup and hashes available on workstation |
| Mainboard | Stage matching 32 KiB-offset app as `qd_mcu.bin` on FAT32 microSD and perform the established power-cycle procedure | `qd_mcu.CUR` success marker; do not use disabled direct SSH flasher |
| Replacement host | Finish/verify mainline host under `mks` before toolhead flashing | UART nodes, disabled gettys, required flash tools and pinned checkouts |
| Toolhead | One SWD full readback/erase/Katapult install; disconnect programmer, restore harness, flash matching 8 KiB-offset Klipper by UART | Readback/hash verified; one power source; matching 500000 baud |
| Inert smoke test | Two UART MCUs only; check API/logs and effective runtime tuning | Both MCUs ready; intended firmware/build settings; tuning audit passes |
| Commission single-material | Install QIDI1 candidate, verify temperatures/pins/fans/endstops, calibrate, then prove a print | Correct physical hardware and QIDI1 calibration |
| Restore integrations | Reconnect Klippee and companion UI; later test Happy Hare's current Box preset in a separate phase | Single-material fallback remains usable; Box kept on stock firmware initially |

Preparing or rehearsing the spare host does not require connecting successfully
to the still-stock MCUs. The inert smoke-test gate comes after both MCU apps
are migrated. Carry out the physical flashing phases only when the operator is
ready to perform and observe them.

## Verification performed for this review

The rebuilt CLI's status, plan, preflight, state and `resume --dry-run` commands
were exercised. Both printers were ready/standby at the sampled time; QIDI2's
host-tuning audit passed. Existing three-image vectors were validated, and
the retained QIDI1/1.8.2 recovery dumps matched recorded SHA-256 hashes.

The machine-readable audit could not read `/root/hid-flash` after switching to
`mks`; a separate read-only sudo hash check on QIDI1 matched the documented
flasher. No UART was opened by an extra reader, and no motion/heater command
was sent. No new image or fresh-host install was qualified by this review.
