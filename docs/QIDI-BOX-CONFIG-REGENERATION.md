# QIDI Box `box.cfg` regeneration on stock firmware

Stock QIDI Plus4 firmware does not treat
`/home/mks/printer_data/config/box.cfg` as the source of truth. The QIDI
`box_detect` Klipper extra regenerates it from a root-owned template selected
for the number of attached QIDI Box devices:

| Detected Box devices | Source template | Generated file |
| ---: | --- | --- |
| 0 | `/home/mks/cfg_with_0` | `/home/mks/printer_data/config/box.cfg` |
| 1 | `/home/mks/cfg_with_1` | `/home/mks/printer_data/config/box.cfg` |
| 2 | `/home/mks/cfg_with_2` | `/home/mks/printer_data/config/box.cfg` |
| 3 | `/home/mks/cfg_with_3` | `/home/mks/printer_data/config/box.cfg` |
| 4 | `/home/mks/cfg_with_4` | `/home/mks/printer_data/config/box.cfg` |

This matters whenever `box.cfg` is managed by Git, a configuration sync tool,
or a remote desired-state service. A successful write to `box.cfg` can appear
to apply correctly and then be partly or completely replaced at the next
Klipper start.

## Confirmed live behaviour

This was reproduced on 2026-07-30 on a stock-fork, one-Box Plus4:

1. A desired `box.cfg` was written and compared successfully with the remote
   desired version.
2. A Klipper `RESTART` completed normally.
3. The generated `box.cfg` reverted to the contents of
   `/home/mks/cfg_with_1`, with the detected Box MCU `/dev/serial/by-id/` path
   inserted.
4. Updating only `box.cfg` and restarting reproduced the drift.
5. Backing up and updating `/home/mks/cfg_with_1`, then restarting, preserved
   the functional macro changes.
6. The generated file still omitted a comment from the template because the
   rewrite passes through Python `ConfigParser`. Removing that cosmetic
   difference from the desired file produced a stable, exact comparison after
   repeated restarts.

The Klippy log made the regeneration visible:

```text
Detected 1 devices: {'/dev/ttyACM1': '/dev/serial/by-id/usb-Klipper_QIDI_BOX_...'}
Updated new device path: /dev/serial/by-id/usb-Klipper_QIDI_BOX_...
```

The regenerated file's timestamp matched the subsequent Klipper start.

## Source evidence

QIDI's published GPLv3 `box_detect.py` defines:

```python
self.dst_box_cfg = '/home/mks/printer_data/config/box.cfg'
self.src_box_cfg_with_0 = '/home/mks/cfg_with_0'
self.src_box_cfg_with_1 = '/home/mks/cfg_with_1'
self.src_box_cfg_with_2 = '/home/mks/cfg_with_2'
self.src_box_cfg_with_3 = '/home/mks/cfg_with_3'
self.src_box_cfg_with_4 = '/home/mks/cfg_with_4'
```

Its startup `monitor_serial_devices()` path:

1. enumerates QIDI Box serial devices with `pyudev`;
2. selects the corresponding `cfg_with_N` file;
3. copies that template to `box.cfg`;
4. uses `ConfigParser` to set each `[mcu mcu_boxN]` `serial` value;
5. rewrites `saved_variables.cfg` with the Box count.

The long-running `BoxDetect` object also monitors device-count and serial-path
changes. When the include count or serial mapping no longer matches the
attached devices, it can copy the template again, update `box.cfg`, and request
a Klipper restart.

The relevant preserved source is
[`analysis/github-releases/qidi-klipper-1.7.0-box-source/box_detect.py`](../analysis/github-releases/qidi-klipper-1.7.0-box-source/box_detect.py).
The same paths and functions are present in the analyzed 1.7.3 and 1.8.2
compiled modules; see
[`analysis/components/1.7.3/klipper/box_detect/strings.txt`](../analysis/components/1.7.3/klipper/box_detect/strings.txt)
and the
[`estimated 1.8.2 source outline`](../analysis/components/estimated-source/1.8.2/klipper/box_detect.py).

## Why formatting and comments disappear

After copying the selected template, `box_detect` reads `box.cfg` with:

```python
configparser.ConfigParser(delimiters=':')
```

It sets the detected MCU serial and writes the complete parsed configuration
back to disk. That serialization normalizes spacing and drops comments.
Therefore a semantically identical desired file can still show a persistent
text diff unless it is normalized to the generated representation.

This is not evidence that a sync client failed. The file can be applied
correctly, acknowledged as the current version, and then changed locally by
QIDI's Klipper extension.

## Safe persistence procedure on stock firmware

Do this only while the printer is idle, and keep a timestamped backup of both
the generated file and the selected template.

```bash
stamp="$(date +%Y%m%d-%H%M%S)"
cp -p ~/printer_data/config/box.cfg \
  ~/printer_data/config/box.cfg.before-template-change-"$stamp"
sudo cp -p /home/mks/cfg_with_1 \
  /home/mks/cfg_with_1.before-template-change-"$stamp"
```

For a one-Box printer, apply the intended persistent changes to
`/home/mks/cfg_with_1`, not only to `box.cfg`. Use the matching `cfg_with_N`
template for the actual number of attached devices. Preserve its include
layout and `[mcu mcu_boxN]` sections; `box_detect` will replace the serial paths
with the currently detected devices.

After updating the template:

1. issue a Klipper `RESTART`;
2. wait for Klipper to return to `ready`;
3. inspect `klippy.log` for the detected device count and updated path;
4. compare the regenerated `box.cfg` with the desired configuration;
5. test again after another restart.

Do not use `qidi-klipper-backup/printer_data/config/box.cfg` as the active
template. On the observed installation it matched the old generated file, but
the compiled module and published source point to `/home/mks/cfg_with_N`.

## Guidance for configuration-management tools

A stock-firmware integration should model `box.cfg` as generated state:

- detect the active Box count and manage the corresponding `cfg_with_N`
  template, or explicitly warn that a direct `box.cfg` change is not durable;
- verify files again after Klipper reaches `ready`, not only immediately after
  upload;
- do not rely solely on a remote "applied version" marker;
- expect `ConfigParser` formatting and comment loss;
- keep template changes separate from dynamic MCU serial paths;
- re-evaluate the selected template whenever the attached Box count changes.

On a mainline migration where QIDI's `box_detect` module is removed, this
specific regeneration path no longer applies and `box.cfg` can be managed as a
normal static Klipper include.
