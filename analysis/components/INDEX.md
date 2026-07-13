# Decompiled component index

For a more readable API-level view, see `estimated-source/`. These generated
Python files are non-runnable outlines linked back to exact `decompiled.c`
lines; they are not recovered QIDI source.
For the five QIDI Box modules with an earlier published source baseline, start
with `LINEAGE-ANALYSIS.md` and `lineage-source/` instead.

This index summarizes the Ghidra reference generated from QIDI Plus4 firmware
1.7.3 and 1.8.2. The full SHA-256 values and installed paths are in
`manifest.csv` and `manifest.json`.

| Firmware | Subsystem | Component | Binary bytes | SHA-256 prefix | Decompiled functions | Pseudocode |
| --- | --- | --- | ---: | --- | ---: | ---: |
| 1.7.3 | Klipper | `aht20_f` | 896,960 | `430FA9F50019` | 22/22 | 0.60 MiB |
| 1.7.3 | Klipper | `box_detect` | 1,676,864 | `36479013701A` | 23/23 | 1.76 MiB |
| 1.7.3 | Klipper | `box_extras` | 3,852,728 | `5365CE78CFF4` | 78/78 | 3.33 MiB |
| 1.7.3 | Klipper | `box_rfid` | 539,144 | `D5282BE85179` | 13/13 | 0.32 MiB |
| 1.7.3 | Klipper | `box_stepper` | 2,578,704 | `D3168F9067CF` | 44/44 | 2.55 MiB |
| 1.7.3 | Klipper | `buttons_irq` | 563,376 | `24BF1383F305` | 16/16 | 0.34 MiB |
| 1.8.2 | Klipper | `aht20_f` | 896,960 | `430FA9F50019` | 22/22 | 0.60 MiB |
| 1.8.2 | Klipper | `box_detect` | 1,676,864 | `36479013701A` | 23/23 | 1.76 MiB |
| 1.8.2 | Klipper | `box_extras` | 3,880,952 | `FDEB7DF7366E` | 78/78 | 3.38 MiB |
| 1.8.2 | Klipper | `box_rfid` | 539,144 | `D5282BE85179` | 13/13 | 0.32 MiB |
| 1.8.2 | Klipper | `box_stepper` | 2,581,392 | `09BCCB521762` | 43/43 | 2.53 MiB |
| 1.8.2 | Klipper | `buttons_irq` | 563,376 | `24BF1383F305` | 16/16 | 0.34 MiB |
| 1.8.2 | Klipper | `multi_color_controller` | 7,206,256 | `7D1025390705` | 189/190 | 6.31 MiB |
| 1.8.2 | Moonraker | `extensions` | 1,416,032 | `A02201D8CBFE` | 31/31 | 0.61 MiB |
| 1.8.2 | Moonraker | `frp_manager` | 1,049,360 | `6358703140C6` | 22/22 | 0.28 MiB |
| 1.8.2 | Moonraker | `mqtt` | 5,193,768 | `1E722C8683EE` | 81/82 | 2.92 MiB |

The two failures are the very large Cython module-initialization functions
`__pyx_pymod_exec_multi_color_controller` and `__pyx_pymod_exec_mqtt`, which
exceeded the per-function decompiler timeout. Their complete ARM64 instructions,
symbols and strings are still present. All selected class methods and command
handlers completed.

## Cross-version result

The following Klipper extensions are byte-for-byte identical in 1.7.3 and
1.8.2:

* `aht20_f`
* `box_detect`
* `box_rfid`
* `buttons_irq`

`box_extras` and `box_stepper` changed. Their named Cython method-symbol sets
are the same in both releases, so QIDI changed implementations rather than the
public method layout. Ghidra found one additional anonymous DWARF-generated
function in the older `box_stepper`; it has no stable source-level name and is
not evidence of a removed public method.

The following compiled components exist only in the 1.8.2 installation:

* Klipper `multi_color_controller`
* Moonraker `extensions`
* Moonraker `frp_manager`
* Moonraker `mqtt`

Moonraker 1.7.3 has readable Python counterparts for `extensions` and `mqtt`.
Those source files should be diffed against the 1.8.2 pseudocode when tracing
QIDI's cloud, status-publication and file-transfer changes. `frp_manager` and
`multi_color_controller` are new layers rather than compiled replacements of
1.7.3 modules.

## Where to start for Happy Hare

1. Compare the two `box_stepper/decompiled.c` files around
   `runout_button_callback`, `slot_load`, `slot_sync`, `cmd_EXTRUDER_LOAD`,
   `cmd_EXTRUDER_UNLOAD`, `do_home` and `get_status`.
2. Compare `box_extras/decompiled.c` around `update_b_endstop`,
   `update_e_endstop`, the three button handlers, heater disable, RFID init and
   status publication.
3. In `multi_color_controller`, follow `LocalAdapter` first. It documents the
   translation between the new unified controller API and the older Box G-code
   commands. `RemoteAdapter` is useful only if reproducing QIDI's serial JSON
   protocol.
4. Treat RFID, drying and the QIDI touchscreen-status bridge as optional layers
   after four-lane motion and sensor ownership work under Happy Hare.

## Limitations

Ghidra pseudocode is an analysis aid, not buildable recovered Python or Cython.
Cython-generated reference counting and exception paths make it much noisier
than the original `.pyx`. Prefer configuration, stable symbols, embedded
constants and observed behavior when they conflict with an inferred Ghidra
type or variable name.

The original `.so` files are not duplicated in this directory. Re-run the
export script against locally extracted printer backups to reproduce or audit
the output.
