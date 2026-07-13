# Install Happy Hare after the mainline migration

This guide starts after [MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md): the
Plus4 is running upstream Klipper and Moonraker, both printer MCUs connect, and
ordinary single-material printing has been commissioned successfully.

> **Support boundary:** Happy Hare can be installed normally for a supported
> third-party MMU. The QIDI Box is not yet a drop-in Happy Hare device. Its
> stock MCU firmware, dryer, RFID readers and shared sensors still need an open,
> mainline-compatible integration. Installing Happy Hare alone does not provide
> that integration.

The commands below are based on Happy Hare 3.4.2 at upstream commit
`73d39aab2110deebb64dfb7899c6838a706edcea`, verified on 2026-07-13. Happy Hare
changes regularly, so read its current upgrade notice before updating an
existing installation.

## 1. Choose the applicable path

### Supported third-party MMU

Use the normal Happy Hare installer if the attached unit appears in the
[current supported-MMU list](https://github.com/moggieuk/Happy-Hare/wiki), or
has a documented generic/custom configuration and mainline-compatible MCU
firmware.

Follow the MMU manufacturer's flashing and wiring instructions. This repository
does not replace board-specific bootloader, CAN, USB or firmware guidance.

### QIDI Box

Do not use this guide to make the QIDI Box operational yet. Leave the Box MCU
on its retained stock image and leave its config excluded from `printer.cfg`.
Continue with [HAPPY-HARE-INTEGRATION.md](HAPPY-HARE-INTEGRATION.md), which
records the recovered pin map and the remaining host/MCU compatibility work.

Once that port has passed hardware testing, its expected Happy Hare shape is a
four-gate `VirtualSelector`/type-B machine with four independent gear steppers.
Drying, RFID and automatic runout recovery should remain disabled during the
first motion-and-sensor milestone.

## 2. Record and back up the working printer

SSH to the migrated printer as its normal user, not as `root`:

```bash
ssh <user>@<printer-hostname-or-ip>
```

Confirm that the baseline is healthy and record its revisions:

```bash
systemctl --user is-active klipper 2>/dev/null || systemctl is-active klipper
systemctl --user is-active moonraker 2>/dev/null || systemctl is-active moonraker
git -C ~/klipper rev-parse HEAD
git -C ~/moonraker rev-parse HEAD
```

The migration bootstrap currently creates system services, so the second form
of each service check is expected. Do not proceed unless Klipper and Moonraker
are active and the printer can complete a known-good single-material print.

Create a local configuration snapshot:

```bash
timestamp=$(date +%Y%m%d-%H%M%S)
cp -a ~/printer_data/config ~/printer_data/config-before-happy-hare-$timestamp
```

Also download that snapshot or retain it with the rest of the printer backup.

## 3. Connect and identify the MMU controller

For a supported USB controller, use its stable by-id path:

```bash
ls -l /dev/serial/by-id/
```

For CAN hardware, obtain its UUID with the procedure documented for that
controller. Do not substitute a changing `/dev/ttyACM0` or `/dev/ttyUSB0` path
when a stable by-id path exists.

Before the Happy Hare install, confirm that:

- the controller has firmware built for the same mainline Klipper revision;
- its bootloader and recovery method are documented;
- power, ground and bus wiring have been checked;
- any selector, servo, gear and sensor pin definitions match the exact board;
- heater or dryer outputs are physically disconnected or disabled during
  initial commissioning.

## 4. Clone and inspect Happy Hare

```bash
cd ~
git clone https://github.com/moggieuk/Happy-Hare.git
cd Happy-Hare
git rev-parse HEAD
git status --short
```

For a reproducible first installation, record the displayed commit in the
printer's maintenance notes. The installer normally checks upstream and can
self-update. If exact reproducibility matters, review the current installer
before allowing that update rather than assuming an old command line is still
valid.

Do not run `install.sh` with `sudo`. It installs links and configuration for the
current Klipper user.

## 5. Run the interactive installer

The mainline migration uses the standard Happy Hare directory layout. Specify
the paths explicitly so the action is unambiguous:

```bash
cd ~/Happy-Hare
./install.sh -i \
  -k "$HOME/klipper" \
  -m "$HOME/moonraker" \
  -c "$HOME/printer_data/config"
```

During the interview:

1. Select the exact supported MMU and controller board where available.
2. Enter the physical number of gates.
3. Select the stable serial path or CAN UUID identified earlier.
4. Initially disable optional selector-touch and clog detection features unless
   their sensors have already been verified.
5. Initially disable EndlessSpool; enable it after basic runout recovery works.
6. Allow the installer to include `mmu/base/*.cfg`.
7. Include `mmu/optional/client_macros.cfg` only if the printer does not already
   have working `PAUSE`, `RESUME` and `CANCEL_PRINT` macros. Otherwise retain the
   printer macros and adapt them to Happy Hare's documented contract.
8. Do not enable Blobifier, EREC, LEDs, spool motors or other add-ons during the
   first installation.

The installer should create `~/printer_data/config/mmu/`, link Happy Hare's
Klipper and Moonraker components, add its Moonraker update-manager entries and
avoid restarting Klipper automatically so the new configuration can be reviewed
before it is loaded.

## 6. Review the generated configuration

The four primary user-edited files are:

- `mmu/base/mmu.cfg` - MCU connection and machine identity;
- `mmu/base/mmu_hardware.cfg` - pins, motors and sensors;
- `mmu/base/mmu_parameters.cfg` - loading, unloading and behavior;
- `mmu/base/mmu_macro_vars.cfg` - printer-specific macro choices.

Check that `printer.cfg` includes the base files near its beginning:

```ini
[include mmu/base/*.cfg]
```

Only add the client macros include if it does not duplicate existing macros:

```ini
[include mmu/optional/client_macros.cfg]
```

Before starting Klipper, search for unresolved template values, placeholder
serial paths and duplicate sections:

```bash
grep -RInE 'XXX|REPLACE|{[^}]+}' ~/printer_data/config/mmu
grep -RIn '^\[gcode_macro \(PAUSE\|RESUME\|CANCEL_PRINT\)\]' \
  ~/printer_data/config
```

Review motor current, direction, endstop polarity and pull-ups against the
actual MMU documentation. A generated configuration is a starting point, not a
substitute for checking the hardware.

## 7. Start the software without moving hardware

Restart Moonraker first so its component is loaded, then start Klipper:

```bash
sudo systemctl restart moonraker
sudo systemctl restart klipper
systemctl --no-pager --full status moonraker klipper
```

If either service fails, do not repeatedly restart it. Inspect the first error:

```bash
journalctl -u moonraker -u klipper -n 200 --no-pager
tail -n 200 ~/printer_data/logs/klippy.log
tail -n 200 ~/printer_data/logs/moonraker.log
```

Once both services are healthy, use the Klipper console:

```text
MMU_STATUS SHOWCONFIG=1
MMU_SENSORS
MMU_HELP TESTING=1
MMU_MOTORS_OFF
```

Confirm the reported machine type, gate count, controller, sensors and optional
features. `MMU_HELP TESTING=1` is preferable to copying old diagnostic commands,
because the available test interface can change between Happy Hare releases.

## 8. Commission one subsystem at a time

Keep the hotend cold and filament removed initially.

1. Trigger every MMU and toolhead filament sensor by hand and verify its state.
2. Test one gear motor at low speed and short distance, then immediately disable
   it. Correct direction and distance before testing the next motor.
3. Test the selector and servo only for MMUs that physically have them.
4. Verify the extruder-entry/toolhead sensor independently.
5. Leave clog detection, EndlessSpool, cutter automation, dryer control and RFID
   disabled.
6. Re-check `klippy.log` for communication or timing errors.

Never correct a reversed motor by swapping live wiring. Power down first, or use
the documented configuration inversion for the controller.

## 9. Calibrate Happy Hare

Follow the current upstream calibration page for the exact MMU type. The normal
dependency order is:

1. gear rotation distance;
2. encoder or proportional sensor, if fitted;
3. selector positions for a physical selector (skip for `VirtualSelector`);
4. reference Bowden length;
5. per-gate correction;
6. toolhead and cutter distances;
7. tip forming and purge behavior.

Happy Hare exposes the corresponding `MMU_CALIBRATE_*` commands. Use
`MMU_HELP` and the [current command reference](https://github.com/moggieuk/Happy-Hare/wiki/Command-Reference)
rather than applying measurements from another Plus4 or MMU.

After calibration:

```text
MMU_STATUS SHOWCONFIG=1
MMU_SENSORS
MMU_STATS
```

First test manual load/unload for one gate, then every gate. Test a single
toolchange before enabling failure recovery or a multi-hour print.

## 10. Configure OrcaSlicer

Yes, the slicer profile must be updated after Happy Hare is operational. Keep a
separate copy of the known-good single-material Plus4 profile.

Create an MMU profile with the correct number of logical tools and configure it
as a single-nozzle, multi-material printer. Follow Happy Hare's
[current slicer setup](https://github.com/moggieuk/Happy-Hare/wiki/Slicer-Setup)
for the complete, release-specific placeholder list.

The required ordering is:

1. `MMU_START_SETUP` with the current slicer placeholders;
2. `MMU_START_CHECK`;
3. the existing Plus4 start macro, excluding nozzle purge/prime operations;
4. `MMU_START_LOAD_INITIAL_TOOL`;
5. the Plus4 nozzle clean, purge and prime operations after filament is loaded.

End G-code should call `MMU_END` before the existing Plus4 end macro. Toolchange
G-code should remain a `T[next_extruder]` operation. Happy Hare also recommends
`_MMU_UPDATE_HEIGHT` after each layer for sequential-print tracking.

Start with Happy Hare performing tip forming and OrcaSlicer providing a normal
wipe tower. Disable OrcaSlicer's own filament tip-forming movements so the two
systems do not both retract and shape the same filament. Inspect a sliced G-code
file around every toolchange before printing; there should be no unexpected
large unload/reload extrusion surrounding the `Tn` command.

Do not replace the ordinary QIDI/Plus4 OrcaSlicer profile until this MMU profile
has completed a small two-tool test successfully.

## 11. Enable optional features gradually

After repeatable load, unload, toolchange, pause and resume tests:

1. enable runout/clog detection and test a deliberate runout;
2. enable EndlessSpool and test one controlled handoff;
3. tune cutter or standalone tip-forming behavior;
4. tune wipe-tower or an alternate purge system;
5. enable LEDs, Spoolman and other software-only conveniences;
6. commission any heater/dryer last, with independent temperature validation
   and shutdown protection.

For the QIDI Box, RFID and dryer support remain separate integration milestones.
They must not be used as prerequisites for proving the four material lanes.

## Updating, rollback and diagnostics

For a normal update, upstream documents rerunning the installer without `-i`:

```bash
cd ~/Happy-Hare
./install.sh \
  -k "$HOME/klipper" \
  -m "$HOME/moonraker" \
  -c "$HOME/printer_data/config"
```

Read the [Happy Hare upgrade notice](https://github.com/moggieuk/Happy-Hare/wiki/Upgrade-Notice)
first. The installer makes dated configuration backups, but retain the external
snapshot as well.

To back out before commissioning, restore the pre-Happy-Hare config snapshot,
remove the Happy Hare includes and follow the installer's supported uninstall
path (`./install.sh -d` with the same explicit paths). Do not manually delete
linked Klipper modules while services are running.

When asking for help, retain:

- Happy Hare, Klipper and Moonraker commits;
- `mmu/base/*.cfg` with network credentials or identifiers sanitized;
- `klippy.log`, `moonraker.log` and `MMU_STATUS SHOWCONFIG=1`;
- exact MMU/controller revision and firmware build;
- the smallest G-code file that reproduces the failure.

## Upstream references

- [Happy Hare installation](https://github.com/moggieuk/Happy-Hare/wiki/Installation)
- [Happy Hare configuration overview](https://github.com/moggieuk/Happy-Hare/wiki)
- [Happy Hare hardware configuration](https://github.com/moggieuk/Happy-Hare/wiki/Configuring-mmu_hardware.cfg)
- [Happy Hare type-B calibration](https://github.com/moggieuk/Happy-Hare/wiki/MMU-Calibration-TypeB)
- [Happy Hare slicer setup](https://github.com/moggieuk/Happy-Hare/wiki/Slicer-Setup)
- [Happy Hare command reference](https://github.com/moggieuk/Happy-Hare/wiki/Command-Reference)
