# Legacy stock-fork profile migration notes

Source reviewed:

`qidi-plus4-configs/qidi-plus4-1.7.3-beacon-config`

These notes separate physical reference-printer settings from QIDI-fork behavior. They are
kept beside the generic X-7 V1.0 profile because each rendered printer still
receives its own serial identifier and calibration state.

## Migrated

| Legacy setting | Mainline result |
| --- | --- |
| Beacon mount offset `14,-11` | Mount-dependent — set your own to match your installed mount. This value is for a right-side mount; corrected from the stew675-specific `0,-18.8` values after verifying the reference printer's physical right-side mount and the Box unit's preserved factory-mount configuration |
| Beacon/Z reference center `152.5,152.5` | Retained |
| Y-before-X homing and X/Y current reductions | Retained with slower 100 mm/s travel and 50 mm/s move-away |
| Beacon Contact sensitivity `1`, latency `2`, tolerance `0.012` | Retained, but normal homing remains proximity mode |
| Z motor locations and probe points | Motor locations retained; nozzle probe points corrected for the right-side Beacon offset |
| Z-tilt tolerance `0.006` | Retained |
| Mesh envelope `22,22` to `283,283` and 14-by-14 sampling | Retained without a saved mesh |
| Physical bed-screw locations | Retained; the duplicated front-right coordinate in the old `screws_tilt_adjust` section was corrected and all nozzle probe positions were adjusted for both Beacon offsets |
| Hall filament-width calibration `14197/15058` | Retained but disabled by default |
| Chamber output cap `0.5` and PWM cycle `0.135335` | Retained |
| Slow chamber verification window | Retained |
| Full-speed fan behavior during MCU shutdown | Retained |
| Case light and mainboard beeper pins | Retained |
| Part-cooling fan pin and tachometer | Translated from `fan_generic cooling_fan` to upstream Klipper's standard `[fan]` |
| QIDI `chamber_fan` output | Translated to upstream `[heater_fan chamber_heater_fan]` |
| Pressure advance `0.032` | Retained as a starting value after extrusion commissioning; tune it for each filament and toolpath |
| Slicer fan indexes and print lifecycle macros | Reimplemented in `operations.cfg` using mainline object and command names |

The old profile's Beacon serial is not retained. Every Beacon has a unique
serial, so you must supply your own: find it with `ls /dev/serial/by-id/` and
pass it to `render-config`, which substitutes it for the
`CHANGE_ME_BEACON_SERIAL` placeholder. Do not reuse another printer's serial.

## Deliberately not migrated

| Legacy setting | Reason |
| --- | --- |
| `endstop_pin_reverse`, `position_endstop_reverse`, `homing_speed_reverse`, `homing_positive_dir_reverse` | QIDI-fork extensions absent from upstream Klipper |
| `gcode_macro_break` and `chamber_fan` modules | QIDI-fork extensions; the required chamber-fan behavior is translated above |
| `force_move` | Unnecessary for normal operation and unsafe during commissioning |
| PID coefficients | Must be recalibrated on this printer after heater-channel verification |
| Input-shaper values, Beacon model, axis-twist data and saved mesh | Per-printer calibration output; generate afresh |
| X/Y `rotation_distance 38.86` | The mainline starting value remains `38.82` until a measured travel test determines the correct value |
| Fork-era microstep choices | The proven community-mainline values remain in use; microsteps do not define physical travel distance |
| 270 C Beacon contact ceiling | Reduced to 180 C until hot-contact safety is deliberately commissioned |
| 300 mm/s Beacon home travel | Reduced to 100 mm/s for commissioning |
| Combined chamber sensor weighted by three copies of toolhead MCU temperature | Mainline uses the actual PA1 chamber thermistor for control and keeps PC2 as an independent guard reading |
| `plr.cfg`, `time_update.cfg`, `timelapse.cfg`, KAMP and the monolithic QIDI macro file | Host/UI integrations, fork-only commands, stale object names, or movement outside the commissioned build envelope |

The optional cutter, wipe, Box and Happy Hare layers should be reviewed
independently after cold motion, heater, Beacon, extrusion and ordinary
single-material printing have passed.
