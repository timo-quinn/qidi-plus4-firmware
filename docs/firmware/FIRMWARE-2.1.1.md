# QIDI Plus4 firmware 2.1.1 compared with 1.8.2

[Firmware research](README.md) · [Published evidence](../../analysis/firmware/2.1.1/README.md)

QIDI Plus4 2.1.1 substantially rewrites the host-side Box controller and
Moonraker cloud transport. The bundled Box MCU image, RFID, detection and button
modules remain byte-identical to the retained 1.8.2 baseline. Ordinary local
Moonraker access remains represented in the supplied stack; removal of local
API access or mandatory cloud connectivity for every Box operation is not
established by this comparison.

The principal integration changes are a new Box task/status model, new manual
operation commands, expiring MQTT focus subscriptions, a separate Moonraker
status notification, and expanded agent/P2P integration. Several Box V2
operations remain stubs, and accepted cloud-print parameters do not all reach
Klipper.

## Inputs and scope

The Aliyun OTA host and screen payloads were downloaded on **11 November 2026**.
Both HTTP `Last-Modified` headers report **19 October 2026**. The host payload's
`root/xindi/version` identifies SOC `V2.1.1`, UI `V211` and MCU `V0.12.0`.
The Debian package control version remains `1.0.1`; it is separate from the
printer firmware version. URLs, sizes and full SHA-256 hashes are recorded in
[provenance.json](../../analysis/firmware/2.1.1/provenance.json).

The old input is the retained `analysis-1.8.2.tar.gz` printer snapshot, verified
against its retained manifest. This compares an **update overlay** with an
**installed printer snapshot**:

- Files omitted from the update are not treated as deletions.
- Files absent from the snapshot are not assumed to be newly introduced.
- Installed `printer.cfg`, `gcode_macro.cfg`, `moonraker.conf` and generated
  `box.cfg` contain local/device-specific state. Their differences do not
  establish clean vendor release changes.

Of 1,165 regular payload files, 120 have matching paths in the snapshot:
106 are identical and 14 differ. The remaining 1,045 have no matching captured
path. All **16 supplied readable Klipper files are identical**. Of 77 supplied
Moonraker files, 72 are identical; three Python files and two native extensions
change. These inputs do not establish a new upstream Klipper or Moonraker
revision. See the [comparison summary](../../analysis/firmware/2.1.1/comparison-summary.json)
and [matching-file inventory](../../analysis/firmware/2.1.1/matched-files.csv).

## Native components and firmware images

| Component | 1.8.2 bytes | 2.1.1 bytes | Result |
| --- | ---: | ---: | --- |
| `box_extras.so` | 3,880,952 | 5,125,088 | Changed |
| `box_stepper.so` | 2,581,392 | 2,709,328 | Changed |
| `multi_color_controller.so` | 7,206,256 | 4,335,776 | Rewritten API |
| Moonraker `extensions.so` | 1,416,032 | 1,464,136 | Changed |
| Moonraker `mqtt.so` | 5,193,768 | 6,757,768 | Changed |
| `xindi` | 14,284,000 | 16,302,184 | Changed |

The [native component inventory](../../analysis/firmware/2.1.1/native-components.csv)
records exact hashes, including byte-identical `aht20_f.so`, `box_detect.so`,
`box_rfid.so`, `buttons_irq.so` and Moonraker `frp_manager.so`.

The bundled `mcu_box_to_v1_1.1.1.bin` remains 36,280 bytes, SHA-256
`eb5c326e95b739b4c16be957cea18682f1b4eee972ca47061077d28cf86ef362`.
Its update script is also unchanged. `box1.cfg` through `box4.cfg`,
`officiall_filas_list.cfg` and `saved_variables.cfg.bak` match the baseline.

The screen payload retains the recorded 1.8.2 image's 20,540,552-byte length
but has a different hash. These comparisons identify supplied images, rather
than every MCU image that could exist after installation.

## Box controller architecture and commands

| Area | 1.8.2 | 2.1.1 |
| --- | --- | --- |
| Adapters | `LocalAdapter`, `RemoteAdapter` | `BoxAdapterV1`, `BoxAdapterV2`, `ExternalAdapter` |
| State | `UnifiedState` and adapter state | Adapter status, operation status and task status |
| Flow control | Earlier queue/state API | `FlowTask`, retry/stop, completion callbacks and external flows |
| Material lookup | Legacy material database | Legacy database plus JSON profiles and ID/name/vendor helpers |

The old `RemoteAdapter` serial-search/heartbeat implementation and
`UnifiedState` are absent from the new module's named API. This is replacement
of that controller implementation, not evidence that the physical Box's
existing Klipper MCU connection was removed.

The new controller registers manual-operation commands including:

```text
LOAD_FILAMENT_CONTROL       UNLOAD_FILAMENT_CONTROL
EJECT_FILAMENT_CONTROL      FLOW_RETRY
FLOW_STOP                   READ_RFID
UPDATE_FILAMENT_INFORMATION  SET_ENABLE_RFID_READ
SET_ENABLE_INIT_READ_RFID    SET_ENABLE_AUTO_RELOAD
SET_BOX_TEMP_CONTROL        BOX_START_DRYING
BOX_STOP_DRYING              EX_START_DRYING
EX_STOP_DRYING
```

The old controller's `MULTI_COLOR_LOAD`/`UNLOAD`/`SWAP` family,
`QUERY_MULTI_COLOR`, `QUERY_SAVE_VARIABLES` and `USER_CONFIRM_CONTINUE`
no longer appear in the new command constants/API. Clients using them need
adaptation. The established tool-change path is still present: supplied
`T0`–`T15` macros use `EXTRUDER_LOAD`, and unload macros use `EXTRUDER_UNLOAD`,
with saved `value_tN` mappings when `enable_box` is set.

**Box V2 is partially implemented.** Inspected `set_filament_information`,
`enable_box_drying`, `rfid_init_read` and `try_resume_print` methods return
`None` without hardware actions. `load_filament` returns `True` without
hardware actions. Status/material helpers exist, but these methods do not
establish working second-generation Box support on the Plus4.

See the [named API delta](../../analysis/firmware/2.1.1/native-api-diff.json)
and [selected native evidence](../../analysis/firmware/2.1.1/selected-native-evidence.json)
for symbols and inspection locations.

## Box status and material information

The recovered `MultiColorController.get_status` builds `task`, `box`,
`box_warning_info`, `extra`, `filament_dry_extra` and `operation` structures.
Other fields include `box_count`, `extruder_limit_state`, `enable_box`,
`auto_init_detect`, `auto_read_rfid`, `auto_reload_detect` and `load_retry_num`.
Operation status exposes `active_slot`, `operate_state` and `box_button_state`;
task status exposes its flow ID, queue, step and pause state. The uninitialized
path returns empty/default structures. These are reconstructed schemas, not
responses captured from a running 2.1.1 printer.

`BoxExtras` builds nested Box/slot, buffer and loaded-slot status, caches
stepper/heater/AHT objects, and groups refill information by material/colour.
Filament entries carry identifiers, vendor/type/name, colour, temperature and
drying information. Empty/offline compatibility records include constant
defaults and counters; clients should not treat every field as a live sensor
measurement. Refill-group status alone does not validate runout/refill behavior.

`box_stepper` adds `slot_rfid_read`, whose recovered body coordinates reads
with slot movement/homing, sensor checks and reader start/stop. The lower-level
RFID module and MCU image remain unchanged.

The update supplies `filament-0.4.json`, including profiles such as
`QIDI PLA Basic` → `QFA00`, nozzle ranges and drying recommendations.
`MaterialDatabaseJosn` (vendor spelling) adds JSON lookup alongside the legacy
database. The unchanged `officiall_filas_list.cfg` remains a separate input.

## Local Moonraker and agent integration

| Interface | Recovered behavior |
| --- | --- |
| `POST /printer/multi_color_controller/flow_stop` | New explicit Moonraker route forwarding to Klipper's flow-stop handler, which calls `TaskQueueManager.stop` |
| Klipper `multi_color_controller/set_filament_info` | Requires slot and filament, processes colour/vendor information, and routes to a Box or external-spool adapter |
| `notify_moonraker_status_update` | Separate JSON-RPC notification with `[status, eventtime]`; ordinary `notify_status_update` remains |
| `/printer/connection/send_event_to_all` | New WebSocket-only route for agent connections, broadcasting `agent_event` and emitting internal `agent:agent_event` |

The unchanged `klippy_connection.py` discovers non-reserved Klipper endpoints
and bridges them into Moonraker. HTTP exposure of `set_filament_info` is
therefore expected through discovery, but was not queried on a live printer.

`common.py` adds `BaseRemoteConnection.send_moonraker_status`. MQTT adds the
corresponding sender/status-update path, and `xindi` contains the matching
notification name. Consumers should distinguish Moonraker-side status from
Klipper object deltas.

The new agent broadcast handler checks the client connection's agent type,
accepts event/data, sends an `agent_event` notification and emits
`agent:agent_event`. MQTT handles that internal event and forwards notifications
through its cloud event path. This extends the existing extension/agent bridge;
the broadcast route is not an ordinary REST endpoint.

The three readable Moonraker changes are preserved in the
[source patch](../../analysis/firmware/2.1.1/moonraker.patch).

## MQTT subscriptions and remote connectivity

The compiled MQTT module adds `focus.start`, `focus.renew` and `focus.full`
handling with `expireAt`, `objects`, `intervalMs` and `fullSyncIntervalSec`.
It synchronizes Klipper subscriptions, filters requested objects/fields,
rate-limits detailed status, expires focus, and handles full/incremental reports.
The unchanged readable Klippy connection still contains its older 30-second
full-cache push; the new filtering happens downstream in MQTT.

Separate summary publication tracks online/work-state/job changes. Generalized
job-state handling replaces the old fake-job-state handler names. Topic and
credential handling adds user IDs and `mqtt.shard`. Payloads are wrapped with
`v`, `serialNumber`, `event`, `ts`, `ver`, `version` and `data`, with optional
`action`. Cloud consumers should not assume unchanged topics/envelopes or
continuous delivery of detailed status when focus is inactive.

MQTT's new account-bound/LAN-mode checks control FRP activation: the recovered
`_sync_frp_state` starts FRP when bound and outside LAN-only mode, stopping it
otherwise. `frp_manager.so` is unchanged; its caller's policy changes.

`database.py` adds `user.userId`, `mqtt.shard`, `p2p.license`, `p2p.connect`,
`p2p.peer` and `p2p.p2pPassword` defaults. It stops logging initial configuration
row contents and changes config-select-all to return `self.config_items`.
The baseline called `get_config_items()`, which has no implementation in that
class.

## Cloud print requests

The print-start handler now accepts `fileurl`, `consumable`, `plateindex`,
`uid` and `need_extract`. In the `fileurl` branch it sets `enable_box` from
whether `consumable` is nonempty, writes `value_tN = "slotN"` for entries other
than `-1`, schedules download/start asynchronously and immediately returns
`"ok"`. Entries skipped as `-1` are not cleared, so earlier mappings may remain.
Only that branch applies these consumable mappings.

Downloads move from `/home/qidi/printer_data/.cache` to
`/home/mks/printer_data/.cache`. The new handler retains the cache directory
while clearing its contents, reports `uid`/`plateIndex` and progress through
`cloud:slice_download_print`, passes an absolute cached filename to
`start_print`, sets `jobState=failed` on exceptions and cleans a residual
temporary file.

**Accepted parameters do not establish working plate selection or extraction.**
`start_print` accepts `plateindex`, `uid` and `need_extract` but does not use
them in its body. The emitted G-code remains only
`SDCARD_PRINT_FILE FILENAME="..."`.

## Touchscreen and installation

`xindi` grows by about 2 MB. Named additions include P2P session handling,
`P2PManager.stop`/`stopInternal`, `PrinterDataManager.tryStartP2PConfig`, LAN
discovery and CPG networking SDK functions. Together with the new database
fields, this shows expanded P2P/LAN connectivity code. It does not establish
transport selection, camera quality or connection reliability in use.

The overlay supplies Fluidd `v1.30.4`, but the baseline lacks the corresponding
frontend tree, so a frontend release diff cannot be established. The evidence
does not establish removal of local Fluidd/Moonraker access, or compatibility
of every older Box widget with the new status model.

The supplied `box.cfg` is a commented no-Box template; `cfg_with_1` through
`cfg_with_4` provide Box-count-specific templates. Comparing it with the
installed single-Box configuration does not establish loss of Box support.
Similarly, default `moonraker.conf` lacks this machine's `force_logins` and
custom CORS settings; that difference cannot date a vendor policy change.

The installer backs up printer/macro configuration, removes old native module
variants, runs `depmod`, enables time synchronization, restarts Klipper and
Moonraker, and conditionally starts QIDILink according to the connection method.
These are observed 2.1.1 installation actions; earlier maintainer scripts were
not available for a clean script comparison. Included AIC8800 wireless
drivers/firmware target `5.16.20-rockchip64`, rather than establishing a kernel
upgrade.

## Implications for Klippee and mainline integration

Keep ordinary LAN Moonraker HTTP/WebSocket transport as the integration base.
The supplied local connection, authorization, file-manager, metadata, history,
print-status manager and Klipper webhook source match the baseline.

- Feature-detect controller schemas and commands. Normalize 1.8.2 state and
  2.1.1 task/operation/Box/external-spool structures separately.
- Retain low-level diagnostics and the legacy tool-change path. Adapt clients
  that call the older `MULTI_COLOR_*` controller commands.
- Keep stopping a multicolour flow distinct from canceling a print.
- Handle `notify_moonraker_status_update` and `agent_event` when integrating
  QIDI agents. Inactive cloud focus is not proof of an offline printer/Box.
- Do not assume the new native controller is a drop-in mainline addon: it
  depends on QIDI Box objects, saved variables, material databases, macros,
  task/status conventions and printer-specific services.

## Validation and remaining checks

The comparison verifies input hashes, matching-file hashes, readable source
diffs, native symbols/rodata and recovered function bodies. All 40 MQTT and
13 extensions coroutine bodies exported. Cython module-initializer decompilation
failed for `box_extras`, `multi_color_controller` and `mqtt`. BoxExtras automatic
analysis reached its 300-second limit; its named routines still exported.
The [evidence index](../../analysis/firmware/2.1.1/README.md) records the toolchain,
selected function locators and reproduction procedure.

Runtime verification remains necessary for returned status shapes, dynamic
endpoint exposure, load/unload/retry/stop sequencing, RFID movement, refill/runout
behavior, UI event delivery and cloud job/plate behavior. This is a static
interoperability comparison, not complete source recovery or physical validation.
