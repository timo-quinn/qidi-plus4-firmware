# QIDI Box output clock guard

QIDI firmware 1.8.2 constructs the Box `b_output` and `e_output` pins on the
Box MCU, but its compiled `box_extras.so` schedules both outputs with the
primary printer MCU's `estimated_print_time()`. The clocks normally track each
other, but they are not interchangeable. Using one MCU's print-time estimate
for a command queued on another MCU can produce a `Timer too close` shutdown.

[`box_output_clock_guard.py`](../../qidibox-modules/box_output_clock_guard.py) is a
small post-load Klipper extra. At `klippy:connect` it:

1. finds the already-loaded stock `box_extras` object;
2. validates both known `BoxOutput` objects and their digital-output APIs;
3. asks each digital output for its owning MCU with `get_mcu()`;
4. changes only the stale `BoxOutput.mcu` reference;
5. preserves and post-load wraps QIDI's dynamically registered `RELOAD_ALL`;
6. blocks automatic `RFID=1` insertion unless `qidi_box_auto_insert=1`, while
   forwarding explicit/manual calls to QIDI's original callback; and
7. logs and publishes status for each correction and the insertion guard.

It does not replace `box_extras.so`, wrap `set_pin()`, alter the 10 ms scheduling
lead time, move a motor, or issue any MCU command during installation. Both
outputs are validated before either is changed, and a failed assignment rolls
back earlier assignments.

The compatibility assumptions were checked against the retained PLUS4 1.8.2
host and the exact analyzed 1.8.2 binary. Its `MCU_digital_out` implements
`get_mcu()` by returning the pin's `_mcu`. The analyzed `box_extras.so` creates
`BoxOutput` as a normal Python class with `__Pyx_Py3ClassCreate`, and its own
initializer writes `mcu` through Python's normal `tp_setattro` path. The guard
still treats either missing API or a rejected assignment as fatal and leaves
the pair unchanged.

## Guarded installation

The migration CLI has a narrowly scoped installer for the reviewed module:

```powershell
python .\tools\migration\qidi_plus4.py install-box-output-clock-guard `
  --printer $Printer `
  --confirm INSTALL-BOX-OUTPUT-CLOCK-GUARD
```

The operation has no source, destination, owner, mode, or service options. It
uploads only this repository's `box_output_clock_guard.py`, calculates its
SHA-256 locally, requires the staged and installed copies to match that digest,
and fixes the destination at
`/home/mks/klipper/klippy/extras/box_output_clock_guard.py`, owned by `mks` with
mode `0644`. If a different target file exists, it is first copied to a
timestamped directory below
`klippy/extras/.qidi-plus4-backups/`; the structured result contains that exact
rollback path and both digests. A symlinked source, target, target directory, or
backup directory is rejected.

The installer deliberately does **not** edit configuration, stop Klipper, or
restart any service. After reviewing its JSON proof:

1. add this empty section through the normal managed printer configuration:

   ```ini
   [box_output_clock_guard]
   ```

2. deploy that configuration through the normal Klippee/Printerlab workflow;
3. restart Klipper once while the printer is idle; and
4. verify the Klippy log and Moonraker object status before operating the Box.

When connecting with a dedicated management account, pass both the connection
owner and the fixed Klipper owner, for example `--user plab --printer-user mks`.
The installer rejects any `--printer-user` other than `mks` because this overlay
targets the known stock QIDI layout only.

Successful stock output should identify both pins and their actual MCU, for
example:

```text
QIDI Box output clock guard: b_output corrected (mcu -> mcu_box1)
QIDI Box output clock guard: e_output corrected (mcu -> mcu_box1)
QIDI Box output clock guard: active; corrected=2 already-correct=0 reload-all-guarded=True
```

Moonraker exposes the same proof under the `box_output_clock_guard` printer
object. Its `state` is `corrected` or `already-correct`, `outputs` records the
previous and pin MCU name for `b_output` and `e_output`, and
`reload_all_guarded` proves the post-load insertion guard is active.

For Klippee/Printerlab integration, treat the module and config section as one
versioned deployment: run the guarded installer, preserve its structured
rollback handle, activate the section through the normal managed-config path,
restart `klipper.service` so Python imports the installed source, and require
both output statuses plus `reload_all_guarded: true` before reporting success.
A G-code `RESTART` or `FIRMWARE_RESTART` may retain the already imported module
inside QIDI's host process and is not sufficient after changing this file.
Removal is the reverse: remove the managed section, restore/remove the extra,
and restart `klipper.service`.

## Safety boundary

This overlay addresses the cross-MCU scheduling error that can cause a
`Timer too close` shutdown. It does **not** prove or prevent a QIDI Box USB
disconnect, Box MCU watchdog, power brownout, EMI event, sensor wiring fault,
or host USB reset. A crash accompanied by a kernel `USB disconnect` or Klippy
`Lost communication with MCU 'mcu_box1'` still requires USB, power, reset-reason,
and harness diagnosis. Do not treat successful guard status as evidence that
those failure modes are fixed.
