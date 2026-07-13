# Happy Hare integration for QIDI Plus4 and QIDI Box

This document separates two related goals:

1. Use the QIDI Box as a four-lane Happy Hare MMU on mainline Klipper.
2. Run Happy Hare with QIDI's Klipper fork, with or without the QIDI Box.

The preferred architecture is for Happy Hare to own the material state machine.
QIDI's `multi_color_controller`, `box_extras` and `box_stepper` must not also
react to the same tool changes, sensors or runout events.

## Short conclusion

The QIDI Box hardware is a good match for Happy Hare's type-B model:

* four independently driven filament lanes;
* no physical selector, so Happy Hare's `VirtualSelector` applies;
* one switch per lane;
* shared downstream switches and a filament-motion input;
* a dryer heater, two heater fans, a board fan and an AHT20 environment sensor;
* two RFID readers, which can be optional in the first implementation.

On mainline Klipper, the four proprietary `[box_stepper]` sections can be
represented by Happy Hare's ordinary `[stepper_mmu_gear]` through
`[stepper_mmu_gear_3]` sections. Most other Box hardware also has a mainline
equivalent. RFID requires a new open driver or can initially be omitted.

Current Happy Hare also contains explicit compatibility paths for older
Klipper versions. Its Klipper extras and Moonraker component parse as Python
3.7 code. This makes a QIDI-fork compatibility target realistic, although it
still needs an installation and runtime test on a printer. Parsing alone does
not prove that every QIDI-modified API behaves as Happy Hare expects.

## Hardware map recovered from QIDI 1.8.2

The first Box is connected as `mcu_box1`. Additional Boxes repeat the same
layout as `mcu_box2` through `mcu_box4` and provide gates 4 through 15.

| Function | Gate 0 | Gate 1 | Gate 2 | Gate 3 |
| --- | --- | --- | --- | --- |
| Step | `PC14` | `PB9` | `PC12` | `PC8` |
| Direction | `PC13` | `PB8` | `PC11` | `PB2` |
| Enable, active low | `PC15` | `PC0` | `PD2` | `PC10` |
| Lane switch | `PA0` | `PB3` | `PA13` | `PA7` |
| White LED | `PA1` | `PB4` | `PA14` | `PC4` |
| Red LED | `PA2` | `PB5` | `PA15` | `PC5` |

QIDI configures all four drives with 16 microsteps, a rotation distance of
13.6 and a 100 ns step pulse. No TMC UART configuration is present, so the
drivers appear to operate in standalone mode.

| Shared function | Pin/details |
| --- | --- |
| Box button | `PB1`, pull-up |
| `b_endstop` | `PA9` |
| `e_endstop` | `PA10` |
| Filament motion input | `PB0`, pull-up, QIDI IRQ/debounce extension |
| Dryer heater | `PA3` |
| Heater fan A | `PA4` |
| Heater fan B | `PA5` |
| Controller fan | `PA6` |
| Heater NTC A | `PC1` |
| Heater NTC B | `PC2` |
| AHT20 | hardware `i2c3`, address `0x38` |
| RFID chip select 1 | `PC6` |
| RFID chip select 2 | `PC7` |

The meaning and polarity of `b_endstop` and `e_endstop` should be verified
physically before assigning Happy Hare sensor roles. QIDI's binaries show that
both are homing endstops. The names alone are not enough to safely decide
whether `b_endstop` is a shared MMU gate/buffer sensor and whether `e_endstop`
is at the extruder entrance.

## Mainline Klipper and QIDI Box target

### Happy Hare machine model

Until `QidiBox` is an accepted Happy Hare vendor, it can be represented as:

```ini
[mmu_machine]
num_gates: 4
mmu_vendor: Other
mmu_version: 1.0
selector_type: VirtualSelector
variable_rotation_distances: 1
variable_bowden_lengths: 0
require_bowden_move: 1
filament_always_gripped: 1
can_crossload: 1
has_bypass: 0
environment_sensor: temperature_sensor qidi_box_environment
filament_heater: heater_generic qidi_box_dryer
max_concurrent_heaters: 1
```

These attributes match Happy Hare's existing BoxTurtle and QuattroBox type-B
model. A native `QidiBox` vendor entry should use the same defaults.

### Provisional four-drive mapping

This is a pin-map starting point, not yet a drop-in tested configuration:

```ini
[mcu mmu]
serial: /dev/serial/by-id/usb-Klipper_QIDI_BOX_V1_1.1.1_REPLACE_ME-if00
restart_method: command

[stepper_mmu_gear]
step_pin: mmu:PC14
dir_pin: mmu:PC13
enable_pin: !mmu:PC15
microsteps: 16
rotation_distance: 13.6
full_steps_per_rotation: 200
step_pulse_duration: 0.000000100

[stepper_mmu_gear_1]
step_pin: mmu:PB9
dir_pin: mmu:PB8
enable_pin: !mmu:PC0

[stepper_mmu_gear_2]
step_pin: mmu:PC12
dir_pin: mmu:PC11
enable_pin: !mmu:PD2

[stepper_mmu_gear_3]
step_pin: mmu:PC8
dir_pin: mmu:PB2
enable_pin: !mmu:PC10

[mmu_sensors]
pre_gate_switch_pin_0: ^mmu:PA0
pre_gate_switch_pin_1: ^mmu:PB3
pre_gate_switch_pin_2: ^mmu:PA13
pre_gate_switch_pin_3: ^mmu:PA7
```

The lane switches are provisionally mapped as pre-gate sensors because each
belongs to one spool lane. Their exact mechanical position and polarity must
be confirmed with `QUERY_ENDSTOPS` or Happy Hare's sensor diagnostics.

Do not add `PA9`, `PA10` or `PB0` to the Happy Hare configuration until their
physical roles and polarity have been observed. Likely candidates are a shared
gate/post-gear sensor, extruder-entry sensor and encoder/motion sensor.

### Dryer and fans

Mainline Klipper has building blocks for most of the dryer:

* `[heater_generic]` for `PA3`;
* two `[temperature_sensor]` NTC inputs on `PC1` and `PC2` for independent
  over-temperature observation;
* `[heater_fan]` on `PA4` and `PA5`;
* `[controller_fan]` or an output controlled by macros on `PA6`;
* the mainline `AHT10` driver is intended to support AHT10/AHT20/AHT21 and
  reports both temperature and humidity.

QIDI's `AHT20_F`, `box_heater_fan`, `target_max_temp` and
`is_box_heater` options are vendor extensions and cannot be copied verbatim to
mainline. The dryer must retain independent thermal shutdown protection while
its control is ported. Heater testing should start with the heater output
disabled and temperature reporting only.

### RFID

The Box uses two FM17550-compatible readers. QIDI's host module sends an MCU
command whose response format appears in the binary as:

```text
fm17550_read_card_return oid=%c status=%c data=%*s
```

The backup contains `box_rfid.so` but not the corresponding MCU source. A
mainline implementation therefore has two choices:

1. make RFID optional and bring up motion, sensors and drying first; or
2. document the existing MCU command dictionary and implement an open Klipper
   host driver, provided the stored QIDI Box MCU firmware remains compatible.

RFID metadata should populate Happy Hare's gate/spool metadata; it should not
introduce a second tool-change state machine.

### Box MCU firmware warning

The stored Box image is `mcu_box_to_v1_1.1.1.bin` and reports a Klipper/QIDI
Box USB identity. Both QIDI firmware releases contain the exact same image.
That does not guarantee compatibility with a newer mainline Klipper host:
Klipper host and MCU command dictionaries must agree.

Its SHA-256 is
`EB5C326E95B739B4C16BE957CEA18682F1B4EEE972CA47061077D28CF86EF362`.

Before flashing anything:

* retain the original 36,280-byte image and verify its hash;
* identify the Box MCU model, bootloader and flash offset from the PCB or a
  non-destructive MCU query;
* verify that a recovery/DFU path works;
* capture `mcu_constants` and the command dictionary from a successful QIDI
  connection;
* expect to build and flash a matching mainline MCU image if the host rejects
  the QIDI image.

## Happy Hare on QIDI's Klipper fork

QIDI 1.7.3 and 1.8.2 are both based on Klipper
`v0.12.0-65-g96ab9069-dirty`. Current Happy Hare contains compatibility code
for old `PrinterRail`, toolhead look-ahead, sensor callback and ADC APIs. Its
current Python source also parses with Python 3.7, including `mmu_server.py`;
the latter uses postponed annotations, so its modern-looking annotations are
not by themselves a Python 3.7 syntax blocker.

The integration should still be treated as a distinct CI/test target because
QIDI changed core Klipper files, not only extras. In particular, the installed
tree modifies `stepper.py`, `toolhead.py`, `homing.py`, `tmc.py`, heaters,
runout handling, save variables, G-code dispatch and MCU handling.

### Installation shape

The standard Happy Hare paths already match QIDI's layout:

* Klipper: `/home/mks/klipper`
* Moonraker: `/home/mks/moonraker`
* config: `/home/mks/printer_data/config`
* services: `klipper.service` and `moonraker.service`

Use Happy Hare's path options explicitly in automation even though they match
the defaults. Do not run an unreviewed installer against the only working
printer. First clone the backup or use a disposable second installation.

### Required QIDI-fork profile

A supported profile should:

1. refuse or warn when `[multi_color_controller]`, `[box_extras]` or
   `[box_stepper]` is active;
2. disable QIDI `T0`-`T15`, `EXTRUDER_LOAD`, `EXTRUDER_UNLOAD`, Box runout and
   resume macros that would compete with Happy Hare;
3. install Happy Hare extras without overwriting QIDI core files;
4. make the Moonraker component optional until its APIs are runtime-tested
   against QIDI's heavily modified Moonraker;
5. preserve QIDI touchscreen behavior expectations, while clearly stating
   that the stock screen will not display Happy Hare's `mmu` object without a
   separate UI/status bridge;
6. record the QIDI firmware release, Klipper commit, Python version and Happy
   Hare commit in diagnostics.

### Minimum compatibility tests

Run these in order, stopping at the first failure:

1. import/load Happy Hare extras with all motors and heaters disabled;
2. confirm Moonraker starts with `mmu_server.py`, or document operation without
   it;
3. enumerate the `mmu`, sensor and machine objects through Moonraker;
4. buzz each Box drive independently at low speed;
5. verify every switch and motion input without executing load macros;
6. calibrate one lane, then all four lanes;
7. test load/unload without cutter or automatic recovery;
8. test the Plus4 cutter and purge path;
9. test pause/resume, runout and failed-load recovery one at a time;
10. enable dryer control only after independent temperature and shutdown tests.

## Suggested upstream work split

Keep the changes reviewable and useful outside this repository:

1. **QIDI Plus4 printer macros**: cutter, purge/chute, toolhead sensor and safe
   pause/resume hooks for Happy Hare.
2. **QIDI Box hardware profile**: `QidiBox` type-B defaults plus a documented
   four-stepper pin map for one Box.
3. **Mainline peripherals**: environment sensor, dryer/fans and LEDs, with
   RFID optional.
4. **QIDI-fork compatibility check**: installer detection, conflict warnings
   and a small runtime test matrix; avoid a broad fork if existing compatibility
   paths work.
5. **Optional QIDI UI bridge**: translate Happy Hare's `mmu` status into the
   nested `multi_color_controller` schema expected by `xindi`. Keep this out of
   Happy Hare's material-control core.

The first useful milestone is deliberately small: connect one Box to mainline
Klipper, expose four ordinary Happy Hare gear steppers and four lane switches,
and complete repeatable manual load/unload tests with RFID and drying disabled.
That proves the core reuse case without depending on QIDI's proprietary host
modules.

## Evidence used

* QIDI 1.8.2 `box.cfg` and `box1.cfg` from the local printer backup.
* Installed QIDI Klipper source at `v0.12.0-65-g96ab9069-dirty`.
* Symbols and strings in `box_extras.so`, `box_stepper.so`, `box_rfid.so` and
  `aht20_f.so`.
* Happy Hare commit `73d39aab2110deebb64dfb7899c6838a706edcea` inspected on
  2026-07-12.

This is a reverse-engineered integration plan, not a claim of QIDI support or
a hardware-tested drop-in configuration yet.
