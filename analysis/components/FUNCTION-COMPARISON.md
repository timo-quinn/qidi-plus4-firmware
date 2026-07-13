# QIDI Box function comparison: 1.7.3 to 1.8.2

This is a navigation aid for the decompiled output. Function sizes are Ghidra
pseudocode character counts, not machine-code sizes, and should be treated as
change indicators rather than exact source metrics.

## `box_extras`

Both releases retain the same 68 named Cython `__pyx_f_*`, `__pyx_pf_*` and
`__pyx_pw_*` symbols. The strongest decompiler-level change indicators are:

| Function | 1.7.3 pseudocode chars | 1.8.2 pseudocode chars | Observation |
| --- | ---: | ---: | --- |
| `_create_drying_state_setter` | 11,958 | 6,150 | Substantially simplified/restructured |
| `set_box_temp` | 160,449 | 186,989 | Substantial new temperature/enable policy |
| `cmd_INIT_MAPPING_VALUE` | 33,011 | 38,018 | Mapping initialization changed |
| `cmd_BOX_PRINT_START` | 108,437 | 110,768 | Print-start Box handling changed |
| `update_e_endstop` | 22,657 | 22,744 | Small implementation change |

Exact string-set comparison adds three clear 1.8.2 constants:

```text
enable_box
Not using BOX, not turning on the heater.
BOX TEMP SET ERROR
```

This supports the conclusion that 1.8.2 added an `enable_box` guard and an
explicit error path around Box dryer temperature setting. Start with
`set_box_temp` and `_create_drying_state_setter` when reconstructing the policy.

## `box_stepper`

Both releases retain the same 34 named Cython method/implementation symbols.
The strongest implementation-size changes are:

| Function | 1.7.3 pseudocode chars | 1.8.2 pseudocode chars | Observation |
| --- | ---: | ---: | --- |
| `runout_button_callback` | 60,260 | 67,494 | Main runout behavior change |
| `cmd_SLOT_UNLOAD` implementation | 133,889 | 135,706 | Slot-unload path changed |
| `cmd_EXTRUDER_LOAD` implementation | 440,985 | 441,624 | Smaller load-path change |
| `cmd_EXTRUDER_LOAD` wrapper | 17,774 | 17,833 | Signature/wrapper detail changed |
| `slot_sync` | 54,481 | 54,482 | Likely address/constant-only difference |

The most useful exact string delta is:

```diff
- SET_FILAMENT_SENSOR SENSOR=box_motion_sensor ENABLE=0
+ filament_motion_sensor box_motion_sensor
+ filament_switch_sensor fila
+ runout_helper
+ sensor_enabled
```

The 1.8.2 implementation therefore appears to manipulate the QIDI Box motion
sensor and toolhead filament-switch runout helpers directly instead of issuing
the older G-code command. Inspect `runout_button_callback` first, then trace
references to `runout_helper` and `sensor_enabled` in the 1.8.2 pseudocode.

## Stable components

`aht20_f`, `box_detect`, `box_rfid` and `buttons_irq` have identical SHA-256
hashes across releases. Their duplicated decompilations provide a reference for
the complete QIDI Box host layer, but they do not explain behavioral differences
between firmware 1.7.3 and 1.8.2.

## New 1.8.2 controller

`multi_color_controller` is not a revision of an older compiled component. It
is a new facade over the existing Box implementation and a remote serial
implementation. Its wrapper-inclusive output covers 189 of 190 selected
functions. Useful entry points include:

* `LocalAdapter` methods to map the new API to QIDI Box G-code;
* `RemoteAdapter` methods for serial JSON commands, response correlation and
  status events;
* `UnifiedState` for the public nested state schema;
* `TaskQueueManager` for serialized operations and progress/error handling;
* `MaterialDatabase` for tool/gate metadata persistence;
* `MultiColorController.get_status` and `_publish_status` for Moonraker/xindi
  visibility;
* `cmd_multi_color_*` and `cmd_set_filament_dry` handlers for the G-code-facing
  API.

The only failed function is the enormous generated Cython module initializer.
Its ARM64 listing and strings are complete; operational class methods were
successfully decompiled.

## Caveat

Decompiler output changes when code addresses, compiler layout or inferred
types change. The tables above prioritize large size changes and corroborate
them with exact embedded-string differences. They are starting points for
manual review, not proof that unchanged-size functions are behaviorally
identical.
