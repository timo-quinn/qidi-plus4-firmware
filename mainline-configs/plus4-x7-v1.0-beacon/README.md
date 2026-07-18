# Plus4 X-7 V1.0 with Beacon

This profile is a mainline operating configuration for a Plus4 with the
`X-7 1.0` mainboard marking, upstream Klipper on both MCUs, Beacon Rev H, and no
QIDI Box. Its pin map and UART links were checked against a live migrated
printer on 2026-07-14.

It deliberately excludes:

- QIDI Box and Happy Hare;
- Fluidd/Mainsail client macro packs;
- movement beyond the build area for the cutter, chute, or nozzle brush;
- `force_move`;
- saved PID, input-shaper, Beacon model, axis-twist, and bed-mesh data;
- Beacon Contact/TrueZero as the active homing workflow;
- Shake&Tune unless its optional include is enabled after installation.

The hardware profile is not ready to print immediately after installation.
An external Mainsail instance connects through Moonraker and does not require a
local Fluidd package or `fluidd.cfg`. Mainline-native print, pause, resume,
cancel, chamber, fan and compatibility macros are supplied by `operations.cfg`.

The mapping from the former qidi2 profile is recorded in
[`MIGRATION-NOTES.md`](MIGRATION-NOTES.md), including settings that were
translated, corrected, or deliberately withheld from mainline.

## Render and install

Find the stable Beacon path on the printer:

```bash
ls -1 /dev/serial/by-id/usb-Beacon_*
```

From the repository, render a unique copy. The value below is only an example:

```powershell
python .\tools\migration\qidi_plus4.py render-config `
  --beacon-serial '/dev/serial/by-id/usb-Beacon_Beacon_RevH_CHANGE_ME-if00' `
  --output .\artifacts\generated-configs\my-plus4
```

Review the three generated files. Back up the active configuration on the
printer, copy the generated `.cfg` files, and restart Klipper:

```powershell
$Printer = 'my-plus4'
$Generated = '.\artifacts\generated-configs\my-plus4'

ssh "mks@$Printer" 'stamp=$(date -u +%Y%m%dT%H%M%SZ); cp -a ~/printer_data/config ~/printer_data/config-before-mainline-$stamp'
scp "$Generated\printer.cfg" "$Generated\hardware.cfg" "$Generated\beacon.cfg" `
  "mks@${Printer}:/home/mks/printer_data/config/"
ssh "mks@$Printer" 'sudo systemctl restart klipper; sleep 5; tail -n 80 ~/printer_data/logs/klippy.log'
```

Continue only if Klipper reports ready and every temperature is plausible.

## Cold commissioning

Keep access to the power switch. Do not install a build plate you are unwilling
to damage during the first motion and Z tests.

1. Inspect `DUMP_TMC STEPPER=stepper_x`, `stepper_y`, `stepper_z`, `stepper_z1`,
   and `extruder`; resolve every communications or driver fault.
2. Confirm the hotend, bed, chamber, chamber guard, host, and both MCU
   temperatures while all targets remain zero.
3. Run `STEPPER_BUZZ` for X, Y, Z, and Z1 separately. Confirm direction and that
   the two Z motors move the bed in the same physical direction.
4. Test the part fan with `M106 S64` then `M107`. Test the auxiliary and chamber
   fans with `SET_FAN_SPEED FAN=... SPEED=0.25`, then return each to zero.
5. With the toolhead away from the end of travel, test sensorless homing one
   axis at a time at the proven 50 mm/s StallGuard speed. Abort immediately if
   an axis moves in the wrong direction or fails to stop.
6. Measure a commanded 100 mm X and Y move and a 10 mm Z move. Correct
   `rotation_distance` before raising motion limits.

Do not use `G28 Z` yet: there is intentionally no inherited Beacon model.

## Beacon and Z

After X/Y motion and the Beacon mount have been physically checked:

1. Home X/Y with `G28 X Y` and move to `X152.5 Y152.5`.
2. Run `BEACON_CALIBRATE` and complete the paper test with `TESTZ`, `ACCEPT`,
   and `SAVE_CONFIG`.
3. Restart, run `BEACON_QUERY`, then cautiously test `G28 Z` and
   `PROBE_ACCURACY`.
4. Run `Z_TILT_ADJUST`, re-home Z, then run
   `BED_MESH_CALIBRATE RUNS=2`. Beacon updates the `default` profile directly;
   finish with `SAVE_CONFIG` without a redundant `BED_MESH_PROFILE SAVE`.

The saved block now belongs to this printer. Do not copy it back into the
tracked template.

## Heater commissioning

Test one heater at a time while watching both the intended sensor and the
physical heater. Begin with a low target and stop if the wrong reading rises.
The template starts all heaters in bang-bang/watermark control and retains
qidi2's previous 50% chamber-heater power cap.

After the channels are proven, run fresh PID calibration for the hotend and bed.
Only then use `operations.cfg`. Its pressure-advance starting value is inherited
from the same printer's previous profile and must still be tuned per filament.
Calibrate input shaping before raising the conservative motion limits, and
commission Beacon Contact separately if desired.

## Slicer contract

The operating layer accepts either of these start-macro parameter styles:

```gcode
PRINT_START BED_TEMP=60 EXTRUDER_TEMP=220 CHAMBER_TEMP=0
PRINT_START BED=60 HOTEND=220 CHAMBER=0
```

It loads the saved `default` mesh unless `MESH=adaptive` or `MESH=none` is
provided. End G-code may call either `PRINT_END` or `END_PRINT`. Orca/QIDI fan
indexes map `P0` to the part fan, `P2` to the auxiliary fan and `P3` to chamber
circulation. Cutter, chute, brush, QIDI Box and Happy Hare behavior remains a
separate commissioning layer.

## Evidence and provenance

The starting pin map is derived from the live migrated printer and the
[reviewed community reference at commit e3551541](https://github.com/cgarwood82/plus4MainlineKlipperConfig/tree/e3551541f66860658de280b99f8c915a2bff5d34).
The Beacon mount offsets and dependent Z-tilt/screw coordinates match the
physical right-side mount and qidi1's preserved pre-change configuration. The
earlier qidi2 profile's `0,-18.8` values were for the different stew675 mount.
Successful parsing proves MCU pin ownership and driver communication; it does
not prove motion direction, heater routing, dimensional accuracy, or safe
homing. Those are the purpose of the steps above.

Beacon calibration follows the [official Beacon quick start](https://docs.beacon3d.com/quickstart/).
Contact is intentionally deferred to the separate
[official Contact safety and configuration guide](https://docs.beacon3d.com/contact/).
