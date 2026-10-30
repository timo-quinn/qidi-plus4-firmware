# QIDI Plus4 firmware 1.8.2 AMS analysis

This report compares filesystem snapshots from:

* A reference system on firmware 1.8.2, QIDI Box attached, Beacon installed.
* A reference system on firmware 1.7.3, no QIDI Box attached, Beacon installed.

Both snapshots were taken on 12 July 2026. Machine-specific configuration and
Beacon differences are excluded from the conclusions below. Credentials,
cloud tokens and personally identifying values are intentionally omitted.

## Executive findings

1. The reported Klipper base did not change. Both installations identify as
   `v0.12.0-65-g96ab9069-dirty` and use upstream commit `96ab9069` as their Git
   base.
2. The Box MCU image found on both systems is byte-for-byte identical. Its
   filename is `mcu_box_to_v1_1.1.1.bin` and its SHA-256 is
   `EB5C326E95B739B4C16BE957CEA18682F1B4EEE972CA47061077D28CF86EF362`.
   QIDI's version files report MCU `V0.12.0` in both releases.
3. The important 1.8.2 work is in the host software. QIDI added a proprietary
   `multi_color_controller.so`, updated the existing proprietary Box modules,
   modified Moonraker substantially, and expanded the proprietary touchscreen
   daemon (`xindi`).
4. QIDI's AMS implementation is not a mainline Klipper feature and cannot be
   carried to mainline by copying configuration alone.
5. A third-party AMS that supplies its own mainline Klipper integration should
   not need QIDI's controller. It must replace the entire QIDI Box software
   layer and reconcile QIDI's macros, sensors and tool mappings.

## Klipper delta: 1.7.3 to 1.8.2

Both trees use the same Git base. A direct comparison of their installed
`klippy` directories produced this meaningful delta:

| File | 1.8.2 change |
| --- | --- |
| `klippy/extras/multi_color_controller.so` | New proprietary controller, 7,206,256 bytes |
| `klippy/extras/print_stats_manager.py` | New readable status manager, 147 lines |
| `klippy/extras/box_extras.so` | Proprietary module updated from 3,852,728 to 3,880,952 bytes |
| `klippy/extras/box_stepper.so` | Proprietary module updated from 2,578,704 to 2,581,392 bytes |
| `klippy/webhooks.py` | Adds `multi_color_controller` to a `DEEP_COMPARISON_MODULES` constant |
| `klippy/extras/probe.py` | Formatting/comment-only change in a disabled vibration block |

Binary hashes:

| Binary | Firmware | SHA-256 |
| --- | --- | --- |
| `multi_color_controller.so` | 1.8.2 | `7D1025390705F6D8B108B8345F7B3AD81C2BDB516D6BDE897B9CCD1BB4AB5B6C` |
| `box_extras.so` | 1.7.3 | `5365CE78CFF4D0E5FB480EE1366ADDFAE227606EE7B28F16D97DA3224D490CD3` |
| `box_extras.so` | 1.8.2 | `FDEB7DF7366E7712D9A74E46267F28781C44680F9C00DA954B051FA7CB652D4C` |
| `box_stepper.so` | 1.7.3 | `D3168F9067CF81BAD1B5AD86C2219B72DE66A5A8D68BEA10E141FBE407CDA867` |
| `box_stepper.so` | 1.8.2 | `09BCCB521762F318DF59BE8D9AC26693E4853E1F302BA0FE8F29BC12F3ABB3D5` |

The updated `box_extras.so` contains a new `enable_box` check and messages for
declining heater activation when the Box is disabled. The updated
`box_stepper.so` now references the runout helpers for both
`filament_motion_sensor box_motion_sensor` and `filament_switch_sensor fila`
directly; the old embedded `SET_FILAMENT_SENSOR ... ENABLE=0` command string is
gone. This suggests QIDI moved sensor coordination into the compiled module.

## Proprietary multi-colour controller

`multi_color_controller.so` is an ARM64 Cython extension. It is not stripped
and includes debug/symbol information, which exposes its architecture even
though QIDI did not provide the Python source.

It implements:

* `MultiColorController`, `UnifiedState`, `TaskQueueManager` and
  `MaterialDatabase`.
* `BaseAdapter`, `LocalAdapter` and `RemoteAdapter` backends.
* Local control through QIDI Klipper objects and G-code commands.
* Remote serial control with JSON messages, command IDs, responses, events,
  heartbeats and status updates.
* Serial discovery using `/dev/ttyACM*` and `/dev/ttyUSB*`.
* Configurable `mode`, `port`, `baudrate` and `poll_interval`. The live local
  configuration resolves to mode `local`, baud rate `115200`, and a one-second
  poll interval.
* Up to 16 Box slots plus a special `slot16`, which represents the external
  spool path in the live state.
* Material/vendor/colour data read from
  `/home/mks/printer_data/config/officiall_filas_list.cfg`.

The RemoteAdapter contains enough evidence to establish that a serial JSON
protocol exists, including `{"cmd":"ping"}`, `command_response`,
`status_update`, `event_type`, `protocol_version`, `operation_progress` and
`operation_error`. The exact wire protocol and framing have not yet been
reconstructed. Its existence must not be interpreted as documented generic AMS
compatibility.

### Registered G-code API

The module registers these commands on the live 1.8.2 printer:

* `QUERY_MULTI_COLOR`
* `MULTI_COLOR_LOAD`
* `MULTI_COLOR_UNLOAD`
* `MULTI_COLOR_SWAP`
* `MULTI_COLOR_DRY`
* `MULTI_COLOR_READ_RFID`
* `MULTI_COLOR_SYNC`
* `MULTI_COLOR_CONFIG`
* `SET_FILAMENT_DRY`
* `MULTI_COLOR_BOX_UNLOAD`
* `MULTI_COLOR_INIT_RFID`
* `MULTI_COLOR_RELOAD_ALL`
* `MULTI_COLOR_AUTO_RELOAD`
* `MULTI_COLOR_RETRY`
* `MULTI_COLOR_TIGHTEN`
* `MULTI_COLOR_PRINT_START`
* `MULTI_COLOR_TRY_RESUME`
* `MULTI_COLOR_RESUME_PRINT`
* `MULTI_COLOR_INIT_MAPPING`
* `MULTI_COLOR_DISABLE_HEATER`
* `MULTI_COLOR_SET_TEMP`
* `MULTI_COLOR_CLEAR_RUNOUT`
* `MULTI_COLOR_CLEAR_FLUSH`
* `MULTI_COLOR_CLEAR_OOZE`
* `MULTI_COLOR_CUT_FILAMENT`
* `QUERY_SAVE_VARIABLES`
* `SET_SAVE_VARIABLE`
* `RESET_MULTI_COLOR_VARS`
* `USER_CONFIRM_CONTINUE`

Its local adapter delegates to QIDI's older commands and objects, including
`BOX_PRINT_START`, `BOX_LOAD`, `BOX_UNLOAD`, `BOX_CUT`, `BOX_EJECT`,
`BOX_WIPE`, `CUT_FILAMENT`, `TIGHTEN_FILAMENT`, `SLOT_RFID_READ`,
`ENABLE_BOX_DRY`, `DISABLE_BOX_DRY`, `BOX_TEMP_SET`, `CLEAR_RUNOUT_NUM`,
`CLEAR_FLUSH`, `CLEAR_OOZE`, `TRY_RESUME_PRINT` and `RESUME_PRINT_1`.

### Published Moonraker object

The live `multi_color_controller` object publishes nested state with this
shape:

```text
system: ready, mode
hardware: box_count, connected
slots: states, materials, last_loaded
extruder: loaded, target, filament_detected
operation: current, progress, error, box_button_state, operate_state,
           steps, is_waiting_user
print: printing, current_tool, next_tool
rfid: reading, results
drying: per-box drying state
sensors: b_endstop, e_endstop, runout_sensors, pressure_sensor
config: persisted save_variables values
config_summary: enable_box, auto-reload/RFID settings, slot and retry state
```

At the time of inspection the live object reported:

```text
Hardware Sync Error: 'ToolChange' object has no attribute 'is_tool_change'
```

That may be caused by the custom macro/config combination rather than stock
1.8.2, but it proves the controller can remain loaded while its internal state
synchronisation is partially broken. It should be resolved before using this
printer as a protocol reference.

## Print status manager

The new readable `print_stats_manager.py` exposes these commands:

* `SET_PRINT_MAIN_STATUS`
* `SET_PRINT_SUB_STATUS`
* `PUSH_PRINT_STATUS`
* `POP_PRINT_STATUS`

It publishes a main status, sub-status, status stacks and a current step. Its
known states explicitly include filament load/unload, print start, purging,
clear-nozzle, printing and completion phases. This is UI/status integration;
it does not drive AMS hardware itself.

## Moonraker changes

Both installations report the same Moonraker Git base,
`v0.8.0-379-g346a3d7-dirty`, but the installed 1.8.2 tree is substantially
different: approximately 5,157 inserted and 1,284 removed readable lines,
before binary components and generated bytecode are counted.

Notable changes include:

* `extensions.py` replaced by proprietary `extensions.so`.
* `mqtt.py` replaced by proprietary `mqtt.so`.
* New proprietary `frp_manager.so`.
* New/reworked application, WebSocket, database, history, file management,
  update deployment, timelapse and Klippy connection code.
* Cloud print-download and progress events.
* An MQTT-specific 30-second full status snapshot sourced from Moonraker's
  authoritative subscription cache.

| Binary | Size | SHA-256 |
| --- | ---: | --- |
| `extensions.so` | 1,416,032 | `A02201D8CBFE1DBF5FBCFAC81A3A9BBD967302DA8E02276EEC05CA256808711A` |
| `mqtt.so` | 5,193,768 | `1E722C8683EEFFD82E79EB82875855914162EAFD3A032C08F50789F44CE8E49E` |
| `frp_manager.so` | 1,049,360 | `6358703140C69822444F539A2B9053169200D4F680843D89D479473AFC9EB5C9` |

Mainline Moonraker already transports arbitrary Klipper object status, so a
third-party AMS does not inherently require these QIDI cloud components.
QIDI's touchscreen and cloud integration may require their exact behavior.

## Touchscreen daemon (`xindi`)

The 1.8.2 `xindi` binary grew by about 1.8 MB and adds parsing/storage for:

* `multi_color_controller`
* Box extras, steppers, heaters and temperature sensors
* slot filament, colour and vendor information
* Box serial numbers and Box firmware version
* auto-reload and automatic RFID settings
* Box drying state
* slicer filament type, colour, weight and used extruders

| Firmware | Size | SHA-256 |
| --- | ---: | --- |
| 1.7.3 | 12,465,248 | `E65DFA302F964A8D28EFCEE05C71D036199247F7755A59975171F11229C214FD` |
| 1.8.2 | 14,284,000 | `492D57792B08FFBA9B9F1567CA21A8999140F4DFAB7D8A04F63EF62938DE8EFD` |

This UI is coupled to QIDI's object names and nested status schema. A
third-party controller publishing an `mmu` or `AFC` object should not be
expected to appear in the stock touchscreen without an adapter that emulates
QIDI's `multi_color_controller` schema.

## Mainline and third-party AMS compatibility

For a Happy Hare-specific implementation plan and the recovered Box pin map,
see `HAPPY-HARE-INTEGRATION.md`.

### What will not carry over automatically

* `[multi_color_controller]`, `[box_extras]`, `[box_stepper]`, `[box_rfid]`
  and related QIDI sections are not part of mainline Klipper.
* Copying QIDI's `.so` files into a modern mainline environment is not a sound
  migration plan. They are ARM64 Cython extensions built on Debian Buster with
  GCC 8.3 and against the printer's CPython 3.7 runtime. They use non-limited
  Python C APIs and QIDI-specific Klipper objects.
* The stock touchscreen expects QIDI's status object, G-code names and saved
  variables. It will not automatically understand Happy Hare or AFC.

### Expected viable path

Install mainline Klipper/Moonraker and let the selected third-party project own
the complete material-control layer:

* Happy Hare supplies Klipper extra modules, a Moonraker component, macros and
  broad MMU support.
* AFC-Klipper-Add-On supports systems such as BoxTurtle and NightOwl and
  currently requires Klipper 0.12+, Moonraker and Python 3.8+.

The current QIDI runtime is Python 3.7, so AFC should be installed only after
the mainline environment has moved to a supported Python version.

### Integration conflicts to resolve

1. Remove QIDI's multi-colour controller and Box-only config sections unless a
   deliberate compatibility bridge is being developed.
2. Remove or rename QIDI `T0` through `T15`, load/unload, tool-change and Box
   macros that overlap the third-party software.
3. Reconcile wrappers around `PAUSE`, `RESUME`, `CANCEL_PRINT`, `PRINT_START`
   and `PRINT_END` in the order required by the chosen AMS project.
4. Assign filament runout, motion, toolhead and cutter sensors to one owner.
   Do not allow both QIDI and third-party modules to react to the same event.
5. Replace QIDI save-variable keys and OrcaSlicer tool/slot mapping with the
   third-party project's mapping model.
6. Validate cutter movement, purge location, maximum safe Z, heater shutdown,
   runout recovery and power-loss recovery independently.
7. Use Mainsail, Fluidd or the third-party KlipperScreen integration for AMS
   control unless a QIDI touchscreen schema bridge is implemented.

### Front-end control surface

QIDI's "Control Box" panel is not a Klipper or Moonraker feature and is not
part of upstream Fluidd. It is a Vue component compiled into QIDI's own Fluidd
fork at `/home/mks/fluidd`, identifiable by the `Qidi Tech` theme preset in its
`config.json`. The panel is present in the bundle even on a printer with no Box
attached, so it is the printer objects, not an install step, that make it
appear.

It is a pure Moonraker client. It subscribes to `box_stepper slotN`,
`box_extras`, `aht20_f heater_boxN` and `save_variables`, fetches
`officiall_filas_list.cfg` through the file API for its vendor/material/colour
dropdowns, and sends every action as ordinary G-code:

| Control | Command |
| --- | --- |
| Uninstall / Load / Unload | `E_BOX slot=N` / `E_LOAD slot=N` / `E_UNLOAD slot=N` |
| RFID refresh | `RFID_READ SLOT=slotN` |
| Vendor / filament / colour | `SAVE_VARIABLE VARIABLE=vendor_slotN\|filament_slotN\|color_slotN` |
| Box enable toggle | `SAVE_VARIABLE VARIABLE=enable_box VALUE=0\|1` |

`E_BOX`, `E_LOAD`, `E_UNLOAD` and `RFID_READ` are registered by the compiled
`box_extras` module, not by `box_macros.cfg`.

The practical consequence is that installing upstream Fluidd or Mainsail after
a migration removes the Box UI even when the Box still works. Neither front-end
has a plugin or panel API, so the supported way to restore control without
forking them is Klipper's `action:prompt_*` dialog protocol. That replacement
is provided by
[`../../mainline-addons/integrations/qidi-box-ui/`](../../mainline-addons/integrations/qidi-box-ui/).
It covers the actions but not the ambient spool grid; a standalone web panel on
Moonraker's WebSocket API remains the option that reaches full visual parity.

## Recommended compatibility test matrix

Before a real multi-colour print, verify each of these independently:

| Area | Test |
| --- | --- |
| MCU communication | All printer and AMS MCUs connect after repeated firmware restarts |
| Sensors | Each pre-gate, post-gear, toolhead, runout and cutter sensor changes only its intended state |
| Extruder sync | AMS gear sync/unsync does not leave either stepper enabled unexpectedly |
| Load/unload | Every lane loads and unloads without heating or motion outside safe limits |
| Cutter | Cutter operation clears the toolhead and returns to a known position |
| Mapping | Orca tool numbers select the expected physical lanes |
| Runout | Runout pauses once, selects the intended replacement and resumes once |
| Error recovery | Jam, absent filament, failed load and user-confirm flows are recoverable |
| Drying/heaters | Box/chamber heaters respect limits and always shut down on cancellation/error |
| UI/API | Moonraker object subscriptions remain stable during nested AMS state changes |
| Resource use | Long multi-colour prints do not trigger `Timer too close` on the 1 GB SBC |
| Power loss | Recovery behavior is either verified end-to-end or explicitly disabled |

## Evidence and limitations

* The comparison is based on installed files and QIDI update-root snapshots,
  not an official source release.
* The active printer configurations include local Beacon/custom changes.
  Conclusions about host binaries use direct file comparisons and are not
  inferred from those configs.
* The backup contains no distinct mainboard/toolhead MCU images. QIDI's version
  records say the MCU version remained `V0.12.0`; the separately stored QIDI
  Box MCU image is identical across both snapshots.
* The RemoteAdapter protocol can likely be documented further from the Cython
  symbols/debug data and controlled serial traces, but that work is not needed
  when adopting a third-party system with its own mainline driver.

## Third-party references

* [Happy Hare repository](https://github.com/moggieuk/Happy-Hare)
* [Happy Hare installation](https://github.com/moggieuk/Happy-Hare/wiki/Installation)
* [AFC-Klipper-Add-On requirements](https://www.armoredturtle.xyz/docs/afc-klipper-add-on/installation/getting-started.html)
* [BoxTurtle software installation](https://www.armoredturtle.xyz/docs/boxturtle/initial_startup/03-install-plugin.html)
