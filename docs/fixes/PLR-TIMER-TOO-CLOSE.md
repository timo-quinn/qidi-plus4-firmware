# Manually patch the QIDI Plus4 PLR `Timer too close` failure

This guide installs the reviewed power-loss-recovery (PLR) hardening without
Klippee or Printerlab. Those tools automate deployment and verification; the
repair itself is the manifest-bound runtime bundle and the accompanying
Klipper configuration changes documented here.

This is **not a universal Klipper `Timer too close` fix**. It applies to a QIDI
Plus4 using QIDI's vendor PLR implementation when the failure occurs during a
power-loss resume. It does not require flashing any MCU.

## Diagnosed failure

The incident that prompted this patch had two independent failures:

1. A USB hub reset disconnected the QIDI Box, Beacon, and downstream USB
   devices. That remains a USB power, cabling, hub, grounding, or EMI problem.
2. After recovery, the legacy PLR builder replayed thousands of historical
   `M106` fan commands while `CLEAR_NOZZLE_PLR` still had purge-chute motion
   queued. Klippy saturated, its motion buffer drained, and the main motion MCU
   reported `Timer too close`.

This guide addresses the second failure only. The hardened generator restores
only the effective P0, P2, and P3 fan states, fences nozzle cleanup with
`M400`, binds the checkpoint to the exact source G-code, and prevents the
generated `.plr/plr.gcode` file from replacing the original checkpoint.

## Supported scope

The reviewed runtime is pinned to firmware commit
[`97c0b91`](https://github.com/timo-quinn/qidi-plus4-firmware/commit/97c0b91f55346acfb0392563ef552bc9f081fd79).
It has been tested against QIDI's vendor `virtual_sdcard.py` shape, the stock
`/home/mks` account layout, and the printer's Python 3.7 Klippy environment.

The installer deliberately refuses an unexpected `virtual_sdcard.py`, unsafe
paths, an incomplete or modified bundle, and an active or indeterminate
`klipper.service`. Do not bypass those checks.

Before starting, ensure that:

- the printer is idle, with no print or recovery in progress;
- SSH and `sudo` access work;
- physical access is available if the printer does not return to service;
- the current printer configuration has been backed up separately; and
- the exact runtime `backup_manifest` returned during installation will be
  retained.

## 1. Download and stage the pinned bundle

On a workstation with Git and OpenSSH, check out the reviewed commit:

```bash
git clone https://github.com/timo-quinn/qidi-plus4-firmware.git
git -C qidi-plus4-firmware checkout 97c0b91f55346acfb0392563ef552bc9f081fd79
```

Copy the complete `plr-hardening` directory to a unique staging directory on
the printer. Replace `PRINTER_IP` with the printer's address or hostname:

```bash
scp -r qidi-plus4-firmware/plr-hardening \
  mks@PRINTER_IP:/tmp/plr-hardening-97c0b91
ssh mks@PRINTER_IP
cd /tmp/plr-hardening-97c0b91
```

Do not copy or cherry-pick individual Python files. `manifest.json` binds the
installer to the complete reviewed set:

- `install.py`
- `patch_virtual_sdcard.py`
- `plr_checkpoint.py`
- `generate_recovery.py`
- `plr.sh.in`
- `manifest.json`

## 2. Run the read-only plan

Create one unique, filesystem-safe transaction ID and retain it for the apply
step:

```bash
plr_tx="manual-$(date -u +%Y%m%dT%H%M%SZ)"

sudo /home/mks/klippy-env/bin/python ./install.py \
  --printer-user mks \
  --transaction-id "$plr_tx" \
  --json
```

This is a dry-run. It must return `"ok": true`. Review every target path and
action. A changed plan also returns the exact future `backup_manifest` path.
Stop if the installer rejects the vendor source or reports an unexpected path.

## 3. Stop Klipper and apply

Stopping Klipper terminates any active print. Run these as separate commands:

```bash
sudo systemctl stop klipper.service
systemctl is-active klipper.service
```

The second command must print `inactive`. Its non-zero shell status in that
state is normal. Do not apply if it prints `active`, `activating`, or `unknown`.

Apply with the same transaction ID used for the dry-run:

```bash
sudo /home/mks/klippy-env/bin/python ./install.py \
  --printer-user mks \
  --transaction-id "$plr_tx" \
  --apply \
  --klipper-stopped \
  --json
```

The installer never starts Klipper. Save the exact `backup_manifest` from the
JSON result; it is the opaque rollback handle for the files just replaced.

Before starting Klipper, repeat the dry-run:

```bash
sudo /home/mks/klippy-env/bin/python ./install.py \
  --printer-user mks \
  --transaction-id "$plr_tx" \
  --json
```

Require `"ok": true`, `"changed": false`, and `"patch_needed": false`.

## 4. Back up and edit the printer configuration

The runtime installer backs up the files it owns. It does **not** back up
`gcode_macro.cfg` or `plr.cfg`, so make a separate configuration backup before
editing them:

```bash
cfg_backup="/home/mks/manual-config-backups/$plr_tx"
mkdir -p "$cfg_backup"
cp /home/mks/printer_data/config/gcode_macro.cfg "$cfg_backup"/
cp /home/mks/printer_data/config/plr.cfg "$cfg_backup"/
```

Merge only the following sections. Do not replace the complete printer profile:
it may contain machine-specific serial numbers, offsets, saved calibration, or
other local values.

### Keep the hardened PLR entry point

In `plr.cfg`, retain:

```ini
[gcode_shell_command POWER_LOSS_RESUME]
command: bash /home/mks/scripts/plr/plr.sh
timeout: 120
```

Remove the obsolete shell-command section, if present:

```ini
[gcode_shell_command UPDATE_GCODE_LINES]
command: bash /home/mks/scripts/plr/update_gcode_lines.sh
```

Also remove this invocation from `RESUME_INTERRUPTED`:

```gcode
RUN_SHELL_COMMAND CMD=UPDATE_GCODE_LINES
```

The hardened JSON checkpoint supplies the source identity and recovery line;
the legacy line updater must no longer participate in source selection.

### Harden the purge-chute move

In `gcode_macro.cfg`, replace the existing `_MOVE_TO_CHUTE` macro with these
two macros:

```ini
[gcode_macro _MOVE_TO_CHUTE]
description: Safely move nozzle over the purge chute if not already there
gcode:
    _CG28
    _MOVE_TO_CHUTE_HOMED

[gcode_macro _MOVE_TO_CHUTE_HOMED]
description: Complete the guarded purge-chute move after homing
gcode:
    G90
    M400
    {% set x = printer.gcode_move.position.x|float %}
    {% set y = printer.gcode_move.position.y|float %}
    {% if ((x - 95.0)|abs > 0.01) or ((y - 324.0)|abs > 0.01) %}
        {% if x < 56.0 %}
            G1 X56 F12000
        {% endif %}
        {% if (y - 300.0)|abs > 0.01 %}
            G1 Y300 F12000
        {% endif %}
        {% if x > 56.0 %}
            G1 X56 F12000
        {% endif %}
        G1 Y324 F600
        G1 X95 F600
        M400
    {% endif %}
```

Splitting the macro prevents its position-dependent Jinja expressions from
being rendered against stale pre-homing state. The final approach uses the
Plus4's safe X56/Y300 corridor and enters the rear service area slowly.

These coordinates are specific to the QIDI Plus4. Do not copy this macro to a
printer with different mechanics or purge-chute coordinates.

### Fence `CLEAR_NOZZLE_PLR`

Add a final motion barrier after the last wipe move:

```ini
[gcode_macro CLEAR_NOZZLE_PLR]
# Existing macro body remains unchanged above this point.
    G1 Y316 F12000
    G1 Y312 F600
    M400
```

The standalone `M400` is a necessary queue barrier, but it is not by itself the
fan-replay fix. The hardened runtime generator is still required.

### Route recovery resume through the guarded move

In the non-tool-change branch of `RESUME_PRINT`, replace:

```ini
G1 X95 F12000
G1 Y324 F12000
```

with:

```ini
_MOVE_TO_CHUTE
```

The reviewed QIDI1 configuration context is pinned at config commit
[`2a7d418`](https://github.com/cl-tim/qidi-plus4-configs/commit/2a7d4182a614c034203bb2a481b1c958b009605e).

## 5. Start and verify Klipper

Start the service explicitly:

```bash
sudo systemctl start klipper.service
systemctl is-active klipper.service
```

The second command must print `active`. Verify that Moonraker reports Klippy
ready, then inspect the Klipper journal:

```bash
curl -fsS http://127.0.0.1:7125/printer/info
journalctl -u klipper.service -n 100 --no-pager
```

Do not proceed to a recovery test until the web UI reports ready and every
configured MCU is connected without an initialization or configuration error.

With an empty build plate and an unobstructed printer, perform a cold motion
test from the Klipper console:

```gcode
G28
G90
G1 Z35 F900
_MOVE_TO_CHUTE
```

Watch the entire move. The toolhead should use the X56/Y300 safe corridor and
then enter the chute slowly. Stop immediately if the machine's geometry or
installed hardware differs from the reviewed Plus4 configuration.

## Roll back the runtime

Use the exact saved `backup_manifest`. First run a read-only rollback plan with
a new transaction ID:

```bash
backup_manifest='/home/mks/scripts/plr/backups/REPLACE_ME/backup-manifest.json'
rollback_tx="manual-rollback-$(date -u +%Y%m%dT%H%M%SZ)"

sudo /home/mks/klippy-env/bin/python \
  /tmp/plr-hardening-97c0b91/install.py \
  --printer-user mks \
  --transaction-id "$rollback_tx" \
  --rollback-manifest "$backup_manifest" \
  --json
```

Review the plan, stop Klipper, and prove it inactive before applying rollback:

```bash
sudo systemctl stop klipper.service
systemctl is-active klipper.service

sudo /home/mks/klippy-env/bin/python \
  /tmp/plr-hardening-97c0b91/install.py \
  --printer-user mks \
  --transaction-id "$rollback_tx" \
  --rollback-manifest "$backup_manifest" \
  --apply \
  --klipper-stopped \
  --json
```

Rollback deliberately leaves Klipper stopped. Restore `gcode_macro.cfg` and
`plr.cfg` from the separate configuration backup, review the resulting state,
and only then start Klipper again.

## When this guide does not apply

Do not treat every `Timer too close` shutdown as this PLR defect:

- A QIDI Box or Beacon disappearing from USB is a transport, power, hub, cable,
  grounding, or EMI incident. This patch cannot prevent it.
- A TTC during an ordinary print can result from host CPU starvation, storage
  stalls, USB latency, clock instability, excessive MCU load, or unusually
  high step rates.
- A TTC during homing or probing may involve QIDI's host-side MCU/trsync
  behavior and requires separate analysis.
- A failure without `RESUME_INTERRUPTED`, `POWER_LOSS_RESUME`, or
  `.plr/plr.gcode` in the nearby G-code context should not be attributed to the
  PLR fan-replay bug without additional evidence.

Capture `klippy.log`, the system journal, host load and memory telemetry, and
USB/kernel events around any different TTC before changing firmware or macros.

## Status and references

As of 2026-08-06, the public changes are reviewable but not released from the
repositories' default branches. Pin the reviewed commits rather than assuming
that `main` contains them:

- [Firmware PR #1: PLR runtime hardening](https://github.com/timo-quinn/qidi-plus4-firmware/pull/1)
- [Firmware commit `97c0b91`](https://github.com/timo-quinn/qidi-plus4-firmware/commit/97c0b91f55346acfb0392563ef552bc9f081fd79)
- [Configuration PR #1: QIDI-firmware purge/recovery hardening](https://github.com/cl-tim/qidi-plus4-configs/pull/1)
- [Configuration commit `2a7d418`](https://github.com/cl-tim/qidi-plus4-configs/commit/2a7d4182a614c034203bb2a481b1c958b009605e)
- [`plr-hardening/README.md`](../../plr-hardening/README.md) for implementation,
  durability-boundary, and managed-deployment details
