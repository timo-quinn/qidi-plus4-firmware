# QIDI Box status compatibility

QIDI1's stock 1.8.2 `multi_color_controller.so` reads
`box_extras.tool_change.is_tool_change`. Its installed `box_extras.so` does not
provide that attribute, although its native `TOOL_CHANGE_START` and
`TOOL_CHANGE_END` handlers already maintain the saved `is_tool_change` flag.
The result is a recurring adapter exception and incomplete Box status.

[`box_status_compat.py`](../../qidibox-modules/box_status_compat.py) adds the
missing read-only property at `klippy:connect`. It reads the current saved flag
on every access, including changes made by native commands and macros. It
does not replace the compiled modules, register command wrappers, move motors,
write saved variables, or change heater control. Existing implementations of
the attribute are retained. Missing or incompatible prerequisite APIs stop
configuration loading with an explicit error.

Back up the managed configuration and any existing module before installation.
Copy the extra to `~/klipper/klippy/extras/box_status_compat.py`, then add this
section after the Box configuration through the normal managed-config path:

```ini
[box_status_compat]
```

Reload Klipper while idle. For a changed Python module, restart the Klipper
host service so it cannot reuse an old import. Check that Klipper is ready,
the `box_status_compat` object reports `corrected` or `already-provided`, and
`multi_color_controller.operation.error` no longer reports the compatibility
exception. Retain the original native `BOX_PRINT_START`, `INIT_MAPPING_VALUE`
and `TRY_RESUME_PRINT` commands; replacing the whole Box module with an older
source build would remove those commands.

Removal is the reverse: remove the managed section, remove or restore the extra,
and restart Klipper while idle. This corrects a status API mismatch; it is not
a fix or test for MCU timing, USB stability, or physical filament handling.
