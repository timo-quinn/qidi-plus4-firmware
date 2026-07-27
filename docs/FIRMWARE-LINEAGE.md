# QIDI Plus4 firmware lineage: 1.1.2 to 1.7.3 to 1.8.2

This report extends the detailed 1.7.3-to-1.8.2 analysis with a pristine,
factory-installed 1.1.2 eMMC image. It separates long-standing QIDI fork
behavior from later QIDI Box, cloud, and UI additions.

QIDI also published tagged source releases (1.3.2 through 1.7.1) to
<https://github.com/QIDITECH/QIDI_PLUS4>. Those intermediate versions are
analyzed from source — not decompilation — in
[`../analysis/github-releases/`](../analysis/github-releases/), which fills the
gap between the 1.1.2 factory image and the 1.7.3 backup. Its headline result:
the QIDI Box Klipper modules were shipped as **open `.py` source at 1.7.0 and
compiled to `.so` at 1.7.1**, pinpointing when QIDI closed that source.

## Evidence boundary

The ordered snapshots are:

| Version | Source | Screen/UI | Notes |
| --- | --- | --- | --- |
| 1.1.2 | Verified factory eMMC image | `V112` | Brand-new spare X-7 V1.0 controller eMMC |
| 1.7.3 | Fresh printer backup | `V173` | Live printer without QIDI Box |
| 1.8.2 | Fresh printer backup | `V182` | Live printer with QIDI Box |

The factory partitions were mounted read-only, with ext4 journal recovery
disabled. The later archives were extracted into WSL-native ext4 storage to
preserve modes and symlinks. The scanner excludes logs, G-code, databases,
credentials, Git internals, caches, certificates, SSH data and Python
environments.

The 1.7.3 and 1.8.2 printer configurations contain owner customizations such as
Beacon and dated backup files. `printer-config` lineage is retained as
diagnostic evidence but is not used to attribute vendor changes.

## Executive summary

QIDI did not replace the host platform or rebase Klipper/Moonraker across these
releases. All three snapshots contain the same:

- Debian 10 host generation;
- kernel, initramfs, disk device tree and extlinux configuration;
- recorded Klipper commit `96ab906946ed558b961a7d8e0e56fb6aebf15316`;
- recorded Moonraker commit `346a3d7c9dca6499bdef2957ca39a23c702b0268`;
- `/root/uart` touchscreen updater;
- `/root/hid-flash` mainboard flasher.

All 380 scanned boot files, 231 vendor systemd files, 29 system-default files
and 22 network/NetworkManager files are byte-identical across the lineage.
QIDI's releases are application/configuration overlays on a frozen host stack.

The software evolution has two distinct stages:

1. **1.1.2 -> 1.7.3:** QIDI added the low-level Box MCU/sensor/heater/stepper
   stack, multi-material screen UI, slicer colour/tool metadata, and host CPU
   tuning. Moonraker itself changed in only one installed file.
2. **1.7.3 -> 1.8.2:** QIDI added the coordinating
   `multi_color_controller`, expanded/changed the Box modules, heavily modified
   Moonraker, and introduced the compiled MQTT/FRP/cloud architecture.

Most non-AMS compatibility work predates both stages. Factory 1.1.2 already
contains QIDI's custom mesh/probe behavior, Z-offset persistence, interruptible
G-code/heater waits, MCU/stepper changes, QIDI metadata/API endpoints and
touchscreen daemon.

## Quantitative transition

The counts below cover the installed source trees and exclude unchanged paths:

| Area | 1.1.2 -> 1.7.3 | 1.7.3 -> 1.8.2 |
| --- | ---: | ---: |
| Installed Klipper | 7 added, 10 changed | 2 added, 4 changed |
| Installed Moonraker | 1 changed | 11 added, 22 changed, 2 removed |
| Native `.so` components | 0 -> 6 | 6 -> 10 |
| `xindi` symbols | 574 -> 922 | 922 -> 1,223 |
| Filtered `xindi` strings | 3,347 -> 4,665 | 4,665 -> 6,672 |

`xindi` grew from 9,380,776 bytes to 12,465,248 and then 14,284,000:
32.9% growth in the first transition, 14.6% in the second, and 52.3% overall.

## Factory 1.1.2 was already a substantial fork

Relative to the Git commits recorded inside the factory filesystem, 1.1.2
already modifies at least these behaviorally relevant Klipper areas:

- `SAVE_CONFIG_QD` and QIDI restart/save semantics;
- adaptive/offset-aware bed mesh including `ZFADE`;
- saved-variable Z-offset commands;
- hall filament-width/tangle behavior;
- interruptible heater waits;
- `submaxmin` probing, vibration/retry handling and `Z_VIBRATE`;
- cancellation through a global G-code break flag;
- virtual-SD, MCU, stepper and toolhead behavior;
- untracked `chamber_fan.py`, `gcode_macro_break.py`,
  `gcode_shell_command.py` and `qdprobe.py` modules.

Factory Moonraker already changes authorization, metadata, Klippy APIs and
machine information. In particular, the custom
`/access/user/password_by_name` password-reset endpoint exists in 1.1.2. It
must therefore be treated as a long-standing QIDI fork/security property, not
as a feature introduced by 1.8.2.

No native Klipper or Moonraker `.so` components were found in the factory
installed trees. The factory fork is largely readable Python plus the native
`xindi` application.

## Transition from 1.1.2 to 1.7.3

### Low-level QIDI Box stack

1.7.3 adds six native Klipper extensions:

- `aht20_f.so`;
- `box_detect.so`;
- `box_extras.so`;
- `box_rfid.so`;
- `box_stepper.so`;
- `buttons_irq.so`.

It also adds readable `box_heater_fan.py`. Related changes integrate IRQ-based
filament motion, Box runout state, chamber/bed/Box heater coordination,
Box-specific verification error `QDE_005_001`, device discovery and Box saved
variables.

The installed tools gain the Box application image
`mcu_box_to_v1_1.1.1.bin`, its updater, `serial_com`, `serial_com_dict`,
`json_reader`, and `zlib_decompress`. These files remain byte-identical in
1.8.2.

### Slicer and screen preparation

Moonraker changes only `file_manager/metadata.py`, adding extraction of slicer
`filament_colour` and `used_extruders` values. This is the bridge between
multi-tool G-code metadata and the Box/UI layer.

`xindi` adds 352 retained symbols with only four removals. The meaningful new
surface includes the large `MultiColorSlots` class family for:

- one to four boxes and slot selection;
- load, unload, retry and RFID actions;
- filament type/vendor/colour editing;
- Box drying pages and state;
- multi-colour print pages and slot assignment;
- connection ordering and Box error pages.

It also adds account/device binding, network-detection, HTTP/certificate and
structured logging code. This shows that 1.7.3 already contained most of the
stock-screen Box experience, even on the reference printer without a Box.

### Host service changes

1.7.3 adds an init script that fixes CPU frequency, process affinity, IRQ
affinity and niceness for Klipper, Moonraker, `xindi`, nginx and the camera.

The normally named `QIDILink-client.service` file is removed and retained only
with a `.masked` filename. `xindi/build/start.sh` also comments out the legacy
`/root/QIDILink-client/udp_server` launch. Thus remote access existed in the
factory image, but this particular path was disabled by 1.7.3.

## Transition from 1.7.3 to 1.8.2

The detailed source/API analysis remains in
[FIRMWARE-CHANGES.md](FIRMWARE-CHANGES.md). In lineage terms, 1.8.2:

- adds `multi_color_controller.so` and `print_stats_manager.py`;
- changes `box_extras.so` and `box_stepper.so`;
- makes small installed Klipper changes in `probe.py` and `webhooks.py`;
- replaces readable Moonraker `extensions.py` and `mqtt.py` with compiled
  extensions;
- adds compiled `frp_manager.so`;
- adds/reworks application, database, history, metadata, file management,
  Klippy API, machine, power, WebSocket and update-related Moonraker paths;
- expands `xindi` with another 303 symbols and 2,043 filtered strings.

The MQTT/FRP architecture is therefore not QIDI's first remote-access code. It
is a later replacement/expansion of the QIDILink capability present in the
factory image and disabled through the inspected 1.7.3 startup path.

## Screen-resource lineage

| Version | `xindi` bytes | Screen resource bytes | Screen resource SHA-256 | `tjc` bytes |
| --- | ---: | ---: | --- | ---: |
| 1.1.2 | 9,380,776 | 28,972,292 | `7ab12a2b...a733b` | 10,276 |
| 1.7.3 | 12,465,248 | 20,480,808 | `3374f5eb...93dc25` | 31,384 |
| 1.8.2 | 14,284,000 | 20,540,552 | `a64a9c47...b19397` | 20,396 |

The screen resource shrank by 29.3% at 1.7.3 while the host daemon grew by
32.9%, consistent with more UI/state logic moving into `xindi` alongside the
new Box pages. File sizes alone do not establish internal resource structure,
so page/component mapping still requires TJC project data or UART capture.

## Compatibility conclusions

- Mainline migration must account for QIDI's core fork behavior even on a
  printer with no Box; those modifications already exist in factory 1.1.2.
- The low-level QIDI Box protocol stack is principally a 1.7.3 addition.
- The coordinating AMS object, deep Moonraker integration and current cloud
  layer are principally 1.8.2 additions.
- QIDI Box functionality can be treated as layers: stock Box MCU protocol,
  Klipper device modules, normalized material state, and UI/cloud consumers.
- The frozen host/boot layer supports replacing the OS independently from
  reconstructing QIDI application behavior.
- The factory eMMC does not prove that the physical factory mainboard/toolhead
  MCU flash equals later releases. It only reports MCU version `V0.12.0`; the
  verified raw MCU equality currently applies to the 1.7.3 and 1.8.2 printers.

## Generated evidence

The publishable artifacts under [`../analysis/firmware/lineage/`](../analysis/firmware/lineage/)
include:

- an ordered file hash/mode/size lineage and transition summary;
- exact key-file and native-component inventories;
- retained `xindi` symbols and security-filtered string deltas;
- readable transition patches with binary/skipped-file indexes;
- each snapshot's tracked diff against its recorded Git HEAD;
- readable additive patches for untracked source.

The factory raw image, live root-resource captures and extracted working trees
remain under ignored/private storage.
