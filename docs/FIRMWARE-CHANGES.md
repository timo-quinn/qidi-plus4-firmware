# QIDI Plus4 firmware static analysis: 1.7.3 to 1.8.2

> A pristine factory 1.1.2 image is now included in the broader
> [three-way firmware lineage](FIRMWARE-LINEAGE.md). This document retains the
> detailed 1.7.3-to-1.8.2 source/API analysis.

This report compares freshly regenerated filesystem backups from:

* QIDI Plus4 firmware 1.7.3 (no QIDI Box);
* QIDI Plus4 firmware 1.8.2 with QIDI Box.

It covers the broader firmware stack, not only QIDI Box or Happy Hare-related
code. Printer-specific configuration and installed third-party customizations
are kept separate from vendor software conclusions.

## Executive summary

QIDI 1.8.2 is not a new Klipper base. Both releases identify as
`v0.12.0-65-g96ab9069-dirty` and share nearly all of QIDI's core Klipper patch
set. The direct installed Klipper change from 1.7.3 to 1.8.2 is limited to:

* changed `box_extras.so` and `box_stepper.so`;
* new `multi_color_controller.so`;
* new readable `print_stats_manager.py`;
* a small `webhooks.py` addition;
* a one-byte/comment-level `probe.py` difference.

The major 1.8.2 expansion is in Moonraker and the `xindi` touchscreen:

* QIDI partially backported Moonraker files from later 2023-2024 upstream
  commits while retaining the recorded `v0.8.0-379-g346a3d7-dirty` base;
* it added a persistent printer/account/settings table and API;
* it added cloud slice download/start-print and progress events;
* it compiled and replaced Moonraker's MQTT and extensions components;
* it added an FRP/QIDILink remote-tunnel manager;
* it expanded print history, metadata, file operations and status aggregation;
* `xindi` grew from 12,465,248 to 14,284,000 bytes and gained matching account,
  region, MQTT, history, file-monitoring, crypto, cloud and AMS support.

The kernel, boot files, vendor systemd units, init scripts and network
configuration are byte-identical in the captured paths. The release therefore
looks like an application-layer update, not an OS, kernel or MCU-platform
update.

## Evidence and reproducibility

Generated artifacts in this directory include:

* `file-changes.csv` - path, size, mode and SHA-256 comparison;
* `file-change-summary.json` - counts by logical subsystem;
* `xindi-metadata.json` - exact UI binary hashes and sizes;
* `xindi-symbols-*.txt` - filtered demangled symbol inventories and deltas;
* `xindi-filtered-strings-*.txt` - security-filtered feature string deltas;
* `patches/` - readable source patches against the recorded upstream commits;
* `patches/*-untracked-readable.patch` - additive patches for source files not
  tracked by the embedded Git repositories.

The comparison can be regenerated in Linux/WSL with:

```bash
python3 tools/Analyze-QidiFirmware.py \
  --old /path/to/extracted-1.7.3 \
  --new /path/to/extracted-1.8.2 \
  --output analysis/firmware
```

Linux extraction is required to preserve symlinks and permissions correctly.

## Klipper: QIDI changes common to both releases

Both installations use upstream commit `96ab906946ed` plus QIDI modifications.
After ignoring end-of-line noise, 1.8.2 has 34 changed tracked files with about
1,893 insertions and 1,402 deletions. All but `webhooks.py` are also modified
in 1.7.3.

### Configuration and persistence

`configfile.py` adds:

* separate runtime and deprecation warning lists;
* `SAVE_CONFIG_QD`;
* explicit `flush()`/`sync` before replacing configuration files;
* firmware restart after standard save rather than a host-only restart.

`save_variables.py` adds direct INI-style load/save helpers and publishes many
QIDI Box defaults as top-level status keys, including slot mappings, colors,
vendors, runout counts and automatic RFID/refill state.

`gcode_move.py` adds `SAVE_ZOFFSET_TO_VARIABLE` and
`LOAD_ZOFFSET_FROM_VARIABLE`.

### Bed mesh and probing

`bed_mesh.py` adds or changes:

* a runtime Z-fade/tool offset supplied with `ZFADE`;
* adaptive mesh bounds derived from `exclude_object` polygons;
* adaptive probe-count scaling and margins;
* `SAVE_Z_OFFSET_TO_BED_MESH`;
* optional subtraction of the last probe Z result from a generated mesh;
* per-mesh profile identity stored in `ZMesh` rather than only in the profile
  manager;
* removal of the deprecated relative reference index path.

The file is closest to a January 2024 upstream `bed_mesh.py`, but QIDI's
adaptive mesh and offset behavior is an additional vendor overlay.

`probe.py` adds:

* a `submaxmin` sample mode which removes the highest and lowest samples;
* vibration/retry recovery with a `Z_VIBRATE` macro;
* probe counters and periodic vibration;
* probe offsets in status;
* cancellation through QIDI's global G-code break flag.

It also changes “probe triggered prior to movement” from an exception to an
informational response. This is behaviorally important when moving to mainline:
mainline intentionally aborts that unsafe/invalid pre-trigger condition.

`qdprobe.py` is an untracked QIDI probe implementation. `smart_effector.py`
aliases a second probe wrapper.

### Heater and chamber behavior

`heaters.py`, `heater_bed.py` and `verify_heater.py` implement a coupled chamber
and bed policy:

* heater target minimum/maximum limits;
* chamber heating can automatically raise the bed target;
* chamber PWM can be suppressed until the bed reaches a QIDI-defined state;
* chamber heating is stopped when a homed toolhead rises above Z=270;
* heater waits can be interrupted through a webhook/global break flag;
* `MAX_HEAT_TIME` increases from five to ten seconds;
* a Box heater verification failure reports QIDI error `QDE_005_001` and turns
  that heater off without shutting down the whole printer;
* `CLOSE_BED_DEBUG` changes a bed-state control flag.

Untracked readable modules add `chamber_fan.py` and `box_heater_fan.py`.

### Motion, homing and MCU protocol behavior

`mcu.py` changes behavior below the configuration layer:

* adds synchronous `send_wait_ack` support;
* increases `TRSYNC_TIMEOUT` from 25 ms to 100 ms;
* staggers trsync reports across MCUs;
* adds sensor names and actual values to ADC-out-of-range shutdown messages;
* removes mainline's static digital/PWM path and dynamic PWM-cycle support from
  this host implementation.

These changes are a compatibility boundary for mainline migration. Extensions
compiled against QIDI's host assumptions should not be copied into a modern
mainline Klipper installation.

`stepper.py` adds a second set of Z endstops and a `REVERSE_HOMING` command,
switching Z homing direction, position, speed and endstop maps temporarily.

`toolhead.py` adds `SET_Z_VELOCITY_LIMIT`, which mutates the kinematic
`max_z_velocity` at runtime.

### G-code, printing and recovery

`virtual_sdcard.py` adds power-loss recovery enabled by default. It recreates
`/home/mks/scripts/plr/plr_record` at print start and writes the processed line
count every 50 lines. It also fixes file positions for multibyte text under
Python 3 and defaults error G-code to turn off heaters.

`gcode.py` adds a global macro-interrupt flag. While set, all commands other
than `CANCEL_PRINT` are skipped. It also suppresses the normal “Unknown
command” response. The untracked `gcode_macro_break.py` supplies the related
macro behavior.

`gcode_arcs.py` changes segment calculation from `floor` to `ceil`, preventing
an arc segment from exceeding the configured target length.

### Sensors and drivers

`filament_motion_sensor.py` adds IRQ/debounce input through `buttons_irq.so`,
runtime detection-length commands and QIDI Box-specific state reset logic.

`hall_filament_width_sensor.py` changes the configured diameter range into a
single threshold and comments out the upstream M221 extrusion-width
compensation. It therefore acts mainly as a detection sensor in QIDI's fork.

`temperature_sensor.py` records the last sample time. `tmc.py` retries clearing
`uv_cp`; `tmc2209.py` and `tmc2240.py` set vendor-specific thermal/register
defaults.

### Proprietary module loading

`klippy.py` treats `.so` files as valid extras and always loads `box_detect`,
which monitors serial devices. This is the mechanism that makes QIDI's Cython
extensions first-class Klipper objects.

## Direct Klipper changes from 1.7.3 to 1.8.2

The regenerated backups verify the same 16 compiled-component hashes recorded
in the decompilation reference.

| Change | Result |
| --- | --- |
| `box_extras.so` | Changed implementation; same named Cython API |
| `box_stepper.so` | Changed implementation; same named Cython API |
| `multi_color_controller.so` | New in 1.8.2 |
| `print_stats_manager.py` | New readable status stack/state manager |
| `webhooks.py` | Adds `DEEP_COMPARISON_MODULES = ["multi_color_controller"]` |
| `probe.py` | One-byte/comment-format difference in the installed snapshots |

The defined `DEEP_COMPARISON_MODULES` constant does not appear to be consumed
by the readable 1.8.2 `webhooks.py`; it may be unfinished or expected by a
separate component.

Detailed Box and controller analysis remains in the compiled-component index
and function comparison.

## Moonraker 1.7.3 baseline modifications

Both releases record Moonraker commit `346a3d7c9dca`
(`v0.8.0-379-g346a3d7-dirty`). QIDI 1.7.3 modifies only four tracked
components materially:

* `authorization.py` adds `/access/user/password_by_name`;
* `metadata.py` adds QIDIStudio/QIDISlicer recognition, screen thumbnails,
  `gimage`, `simage`, preset colors and used extruders;
* `klippy_apis.py` adds endpoint listing, `breakheater`, `breakmacro`, metadata
  forwarding and print-cache copying;
* `machine.py` exposes the board serial number.

The password endpoint accepts a username and replacement password. Whether it
is exploitable depends on Moonraker authorization configuration, but it changes
the trust model and should be reviewed before exposing port 7125 beyond a
trusted LAN.

## Moonraker 1.8.2 architecture and provenance

The apparent 1.8.2 Moonraker diff is a mixture of upstream backports and QIDI
features. Static blob/proximity comparison against fetched official Moonraker
history found exact upstream copies of:

* `announcements.py` (August 2024);
* `http_client.py` (August 2024);
* `job_queue.py` (June 2024);
* `confighelper.py` and `loghelper.py` (August 2024);
* update-manager `python_deploy.py` and `web_deploy.py`;
* top-level `klippy_connection.py` from the upstream package refactor;
* `utils/__init__.py`, `utils/exceptions.py` and `utils/source_info.py`.

Several others are 98-99.9% line-similar to later upstream files and have a
small QIDI overlay: `app.py`, `common.py`, file manager, Klippy connection,
machine, power, websockets, event loop and server. These should not all be
described as QIDI inventions.

The vendor-heavy files are database, metadata, history, Klippy APIs and the
compiled MQTT/extensions/FRP components.

### Persistent printer configuration database

`database.py` adds a `config` SQL table and API endpoints:

* `/server/database/config/select`
* `/server/database/config/select_all`
* `/server/database/config/update`
* `/server/database/config/delete`
* `/server/database/config/update_batch`

Defaults cover Box behavior, AI detection toggles, cache, fans, language,
lights, sleep, LAN/WLAN, user identity/region/token and MQTT credentials. The
default printer alias is derived from the board serial number. Updates emit
account login/password/region events consumed by the UI and MQTT layer.

### Cloud printing and status transport

`klippy_apis.py` adds remote slice download/start-print support, including
download progress events and a cache below `/home/qidi/printer_data/.cache`.
It sends:

* `cloud:slice_download_print`
* `cloud:slice_print_progress`

It also forwards metadata as synthetic G-code responses, exposes endpoint
listing and retains QIDI's heater/macro interruption APIs.

`klippy_connection.py` detects MQTT connections and forces a full cached
object-status push every 30 seconds. Incremental updates are still used between
full pushes.

`proc_stats.py` includes MQTT, database configuration and timelapse status in
its periodic event. `history.py` adds a single-job update endpoint and MQTT job
state publication support. File manager adds batch deletion; job queue exposes
a remote start method.

### Compiled Moonraker components

In 1.8.2:

* readable `extensions.py` is replaced by `extensions.so`;
* readable `mqtt.py` is replaced by `mqtt.so`;
* `frp_manager.so` is new.

The MQTT component adds credential storage/decryption, QIDI cloud topics,
status forwarding, job-state traffic, UI messages, server switching and FRP
lifecycle control. The binary contains a hard-coded symmetric-looking security
constant. Its exact value is omitted from this report; coordinate responsible
disclosure before publishing a security-focused write-up.

The `mqtt.so` credential path does not decrypt the stored password itself. Its
`_qidiclient_decrypt_hex` helper calls the remote method
`qidiclient.crypto.aes_decrypt_hex`, which is provided by a separate closed
`qidiclient` extension agent registered through `extensions.so`; when no such
agent is present it fails with `Decrypt failed: No extension agents found`.
Device identity is keyed on the SoC serial read from
`/proc/device-tree/serial-number`. The migration-relevant consequence is that
removing the cloud stack means omitting not only `mqtt.so`, `frp_manager.so`
and `extensions.so` but also the `qidiclient` agent binary that holds the AES
key. The hard-coded constant noted above was not located inside `mqtt.so` in
this review, so it may live in `xindi` or in that agent rather than in the
MQTT component.

FRP/QIDILink provides a remote tunnel. This is separate from Klipper and is a
meaningful new external trust boundary.

## Python environment changes

The Klippy environment is identical across the two backups. Moonraker 1.8.2
adds these packages:

* `aiohttp`, `aiosignal`, `asynctest`, `attrs`, `frozenlist`, `multidict`,
  `yarl` - asynchronous HTTP/download support;
* `pycryptodome` - credential/config cryptography.

Both releases remain on Debian 10 and Python 3.7-era environments.

## `xindi` touchscreen and UI

| Firmware | Bytes | SHA-256 |
| --- | ---: | --- |
| 1.7.3 | 12,465,248 | `E65DFA302F964A8D28EFCEE05C71D036199247F7755A59975171F11229C214FD` |
| 1.8.2 | 14,284,000 | `492D57792B08FFBA9B9F1567CA21A8999140F4DFAB7D8A04F63EF62938DE8EFD` |

Both are non-stripped ARM64 C++ executables. Version 1.8.2 adds dependencies on
OpenSSL/crypto and SQLite. After filtering standard-library/template noise,
the symbol inventory grows from 922 to 1,223, with 303 added and only two
removed.

New symbol families show:

* `PrinterDataManager` expansion for persistent config, user identity, MQTT,
  history, cached print state and firmware manifests;
* `FileMonitor` for recursive G-code discovery, deletion and metadata parsing;
* `PrintFileInfo` and print object/plate/filament metadata;
* `HistoryList` and job records;
* `QRCodeUtils` for device binding, region and time-zone behavior;
* `HmacSha256` and AES-related operations;
* `Config::RegionDomains` and region-specific API domains;
* MQTT server switching and status;
* QIDILink/FRP configuration;
* all QIDI Box/multi-color state described in the AMS report;
* firmware/update progress and offline update state.

The UI is therefore coupled not only to the new AMS schema, but also to QIDI's
database, account, history, MQTT and cloud-print APIs.

The touchscreen resource image `800_480.tft.bak` also changes. The top-level
`tjc` blob changes from 31,384 to 20,396 bytes; it is encoded touchscreen data,
not an ELF executable.

## QIDILink release payload

The FRP executable itself is unchanged. QIDI moves it from `QIDILink-client`
to `QIDILink-client-DoNotTouch`, changes `frpc.json`, retains the same
`servers.json`, and adds:

* a QR-code image;
* a small `udp_server` executable.

Shell history, Vim state and wget history also differ in the update payload;
these are packaging residue, not product features.

## OS, services and firmware that did not change

Within the captured paths, there are no 1.7.3-to-1.8.2 byte changes in:

* `/boot`;
* vendor `/lib/systemd/system` units;
* init scripts;
* `/etc/default`;
* `/etc/network` or NetworkManager configuration.

One local systemd override clears `systemd-timesyncd`'s executable condition on
the 1.8.2 printer. It is not present in the release payload, so attribution to
the firmware update is uncertain.

The following QIDI tools/images are identical:

* Box MCU firmware and updater;
* `hid-flash`;
* `json_reader`;
* `libColPic.so`;
* `serial_com` and `serial_com_dict`;
* `zlib_decompress`;
* `gene4.py`.

The stored QIDI Box MCU image remains 36,280 bytes with SHA-256
`EB5C326E95B739B4C16BE957CEA18682F1B4EEE972CA47061077D28CF86EF362`.
No new mainboard or toolhead MCU image is present in the backup, and both UI
version files still report MCU `V0.12.0`.

## Compatibility and risk observations

These are static-review findings, not claims of an exploitable vulnerability:

1. QIDI's Moonraker password-reset-by-name endpoint should be reviewed before
   any untrusted network exposure.
2. Cloud download-and-print accepts an external download flow and starts local
   printing; URL validation, authentication and TLS handling deserve focused
   dynamic testing.
3. MQTT credential encryption uses a compiled-in symmetric-looking constant;
   this is obfuscation/key management, not protection against an attacker who
   possesses the firmware. Decryption is delegated to a separate closed
   `qidiclient` agent (`qidiclient.crypto.aes_decrypt_hex`) rather than
   performed in `mqtt.so`, so the key material is held in that agent; a
   review of the agent binary is required to assess it.
4. FRP/QIDILink intentionally creates a remote-access path and should be
   disabled or firewalled when cloud features are unwanted.
5. Suppressing unknown G-code and demoting a pre-triggered probe error can hide
   configuration or hardware faults.
6. QIDI's altered PWM, trsync, homing and heater semantics make direct copying
   of compiled extensions into mainline Klipper unsafe.
7. Debian 10, Python 3.7 and OpenSSL 1.1 are obsolete foundations for an
   Internet-connected cloud service even if QIDI's application code is correct.

## Estimated source for Cython `.so` files

The original `.py` or `.pyx` files cannot be recovered exactly. Cython has
already transformed Python control flow, argument parsing, exceptions and
reference counting into optimized C. The binaries contain native code, not
Python bytecode, so tools such as `uncompyle6` are not applicable.

QIDI's own source for `aht20_f`, `box_detect`, `box_extras`, `box_rfid` and
`box_stepper` is available: it shipped as open `.py` in firmware 1.7.0 (GPLv3,
in QIDI's Klipper fork) and is preserved at
`../analysis/github-releases/qidi-klipper-1.7.0-box-source/`. A community
snapshot published as "MIT" is byte-identical to it and is therefore also
GPLv3. All 116 published APIs occur in both firmware binary sets, with no
published-only APIs, making this source the preferred readable lineage baseline
for those five modules. See `../analysis/components/LINEAGE-ANALYSIS.md` and
`../analysis/components/lineage-source/`. Same-name bodies are still not assumed
to be identical, and the binaries add three public `BoxExtras` commands.

This repository now provides four readability levels:

1. `strings.txt` and `symbols.txt` for authoritative retained names/constants;
2. `decompiled.c` for detailed Ghidra control-flow evidence;
3. `estimated-source/` for generated Python-shaped API outlines;
4. `lineage-source/` for published-baseline-derived Box source with explicit
   confidence warnings and binary-only stubs.

The estimated files reconstruct package/module/class/method names, likely
G-code handler signatures, detectable async methods, selected evidence
identifiers and exact `decompiled.c` line references. They are valid Python
syntax but intentionally raise `NotImplementedError`; they are technical maps,
not replacement firmware.

Generate them with:

```powershell
python tools/Generate-QidiEstimatedSource.py `
  --reference-root analysis/components `
  --output analysis/components/estimated-source
```

A genuinely runnable clean-room implementation requires manual semantic
reconstruction and hardware tests. The best route is to use readable upstream
or 1.7.3 implementations as a baseline, implement one method from the Ghidra
evidence at a time, and validate only externally observable behavior rather
than trying to reproduce Cython's generated internals.

## Scope limitations

* The backup is a filesystem/source snapshot, not a block-level eMMC image.
* Running MCU firmware was not read back from flash.
* User-installed Beacon, KAMP and configuration changes are not attributed to
  QIDI.
* Package-manager state was not captured correctly because the backup manifest
  hit a shell `Bad substitution`; Python environment inventories were captured.
* Static analysis cannot prove runtime authentication, cloud policy, hardware
  timing or failure behavior. Those require controlled dynamic tests.
