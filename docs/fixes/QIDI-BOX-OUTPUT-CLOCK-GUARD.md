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
4. changes only the stale `BoxOutput.mcu` reference; and
5. logs and publishes status for each corrected output.

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

## Manual integration

This is intentionally not an automated installer. On a stock QIDI 1.8.2 host,
an integration should:

1. back up any existing file with the target name;
2. copy `box_output_clock_guard.py` to
   `~/klipper/klippy/extras/box_output_clock_guard.py`;
3. add this empty section to the managed printer configuration:

   ```ini
   [box_output_clock_guard]
   ```

4. restart Klipper while the printer is idle; and
5. verify the Klippy log and Moonraker object status before operating the Box.

Successful stock output should identify both pins and their actual MCU, for
example:

```text
QIDI Box output clock guard: b_output corrected (mcu -> mcu_box1)
QIDI Box output clock guard: e_output corrected (mcu -> mcu_box1)
QIDI Box output clock guard: active; corrected=2 already-correct=0
```

Moonraker exposes the same proof under the `box_output_clock_guard` printer
object. Its `state` is `corrected` or `already-correct`, and `outputs` records
the previous and pin MCU name for `b_output` and `e_output`.

For Klippee/Printerlab integration, treat the module and config section as one
versioned deployment: upload by expected digest, preserve a rollback copy,
activate the section through the normal managed-config path, restart once, and
require both output statuses before reporting success. Removal is the reverse:
remove the managed section, restore/remove the extra, and restart Klipper.

## Safety boundary

This overlay addresses the cross-MCU scheduling error that can cause a
`Timer too close` shutdown. It does **not** prove or prevent a QIDI Box USB
disconnect, Box MCU watchdog, power brownout, EMI event, sensor wiring fault,
or host USB reset. A crash accompanied by a kernel `USB disconnect` or Klippy
`Lost communication with MCU 'mcu_box1'` still requires USB, power, reset-reason,
and harness diagnosis. Do not treat successful guard status as evidence that
those failure modes are fixed.
