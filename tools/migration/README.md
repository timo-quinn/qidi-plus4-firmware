# Mainline migration tools

- `qidi_plus4.py` is the cross-platform entry point. It downloads and verifies
  the official Armbian Qidi X-6 image, builds all MCU images, audits and probes
  printers, streams backups, bootstraps official Klipper/Moonraker, renders
  per-printer configurations, and invokes guarded flash phases.
- `bootstrap-mainline.sh` installs the upstream host stack on clean Armbian
  without FreeDi or KIAUH. It also installs persistent RK3328 CPU and UART IRQ
  affinity tuning before Klipper is enabled.
- `qidi-host-tuning.sh` audits or installs the dedicated-printer host tuning.
  It sets the performance governor before Klipper starts, then splits the two
  MCU UART IRQs across CPUs 1 and 2 after Klipper has opened the serial ports.
  The post-start step waits through the host's 60-second boot-settle window and
  runs again on every Klipper restart. It also binds Klipper to CPUs 1 and 2
  and keeps Moonraker and known UI/camera services on CPUs 0 and 3.
- `probes.py` turns the facts collected by `qidi-plus4-remote.sh probe` into
  per-stage judgements. It holds no I/O, so every rule is unit-tested against
  recorded fixtures rather than hardware.
- `qidi-plus4-remote.sh` performs validation, probing and flashing on the
  printer. It is normally streamed or uploaded by the PowerShell orchestrator.
- `mcu-layouts.json` holds the per-board flash/SRAM vector bounds used to
  validate images. It is the single source shared by `qidi_plus4.py` and
  `qidi-plus4-remote.sh`; the remote helper falls back to an identical inline
  table only when the file was not staged beside it.
- `image_factory_emmc.py` creates a guarded, verified raw image of the exact
  factory 32 GB eMMC layout. It requires a read-only source and refuses to
  overwrite existing evidence.

## Machine-readable printer state

`audit` prints a human-readable report. `audit --json` collects the same
observations as a single JSON object instead, and `probe` evaluates those
observations to say which migration stages are already complete on a printer:

```powershell
python .\tools\migration\qidi_plus4.py probe --printer $Printer
python .\tools\migration\qidi_plus4.py probes            # list available probes
```

Each probe reports one of three statuses, and the third is not a rounding
error:

| Status | Meaning |
|---|---|
| `satisfied` | the stage's effect is present on the machine |
| `unsatisfied` | the stage's effect is definitively absent |
| `indeterminate` | the facts needed to decide were not available |

`indeterminate` must never be collapsed into either neighbour. Reading it as
`unsatisfied` re-runs a stage that may be destructive; reading it as
`satisfied` skips a stage that never ran. It means "ask the operator".

An unreachable printer is a normal answer, not a crash: every probe becomes
`indeterminate`, `reachable` is `false`, and the exit status stays 0. This
matters because the host is legitimately absent during the eMMC swap and the
toolhead is unreadable while it is erased — precisely the moments when a
resume decision has to be made. A non-zero exit from `probe` therefore means
the tool itself failed, never that the printer is in a particular state.

Facts can be captured and replayed offline, which is how fixtures for new
probes are built:

```powershell
python .\tools\migration\qidi_plus4.py audit --printer $Printer --json > facts.json
python .\tools\migration\qidi_plus4.py probe --printer $Printer --facts-file facts.json
```

Pass `--probe <id>` (repeatable) to evaluate a subset, and `--include-facts` to
embed the raw observations in the report.

Collection and judgement are deliberately separate: `qidi-plus4-remote.sh`
observes and never concludes, so a probe rule can be changed and tested without
a printer. Every collector there is individually guarded, so one unreadable
path cannot deny the caller the remaining facts; failures appear in the
`errors` array instead.

## Password-free SSH

Every remote action opens several SSH/SCP connections, so password
authentication is entered repeatedly across a migration. Install a key once and
later commands need no password:

```powershell
python .\tools\migration\qidi_plus4.py setup-ssh --printer $Printer --generate
```

This prompts for the printer password a single time, installs your public key
(generating an `ed25519` key if you have none), and verifies key login. A
default `~/.ssh/id_ed25519` is used automatically; for any other key, pass
`--identity <path>` to the remaining commands. On Linux/macOS the tool also
multiplexes one connection per phase, limiting keyless runs to a single prompt
per command. Windows OpenSSH does not support multiplexing, so key setup is the
way to avoid repeated prompts there.

## Staging the mainboard microSD image

`stage-mainboard-sdcard` re-validates a built mainboard image, copies it to a
FAT32 card (or a staging directory) as `qd_mcu.bin`, and writes a `.sha256`
sidecar, so the wrong image or filename cannot reach the resident bootloader:

```powershell
python .\tools\migration\qidi_plus4.py stage-mainboard-sdcard `
  --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin `
  --output E:\
```

## Post-flash connectivity check

Hosts bootstrapped by the current migration tool are tuned automatically. Audit
the effective settings after reboot:

```powershell
python .\tools\migration\qidi_plus4.py audit-host-tuning --printer $Printer
```

For a printer migrated with an older checkout, install the same tuning
idempotently. The command refuses to restart services while Moonraker reports a
printing or paused job:

```powershell
python .\tools\migration\qidi_plus4.py tune-host `
  --printer $Printer --confirm TUNE-HOST
```

The installer masks `irqbalance` so it cannot overwrite the explicit UART IRQ
assignments and masks Debian's late `ondemand.service` so it cannot restore the
scaling governor after boot. Klipper requires the early governor service and
does not complete startup unless the post-start UART affinity check succeeds.
The installer does not change Klipper's baud rate, timer thresholds, MCU
firmware, or `printer.cfg`.

`smoke-test` installs the inert two-MCU `smoke-test-printer.cfg` (backing up any
existing `printer.cfg`), restarts mainline Klipper, and prints the recent
`klippy.log` so both MCUs can be seen reaching `Ready` before the real
configuration is installed:

```powershell
python .\tools\migration\qidi_plus4.py smoke-test --printer $Printer
```

On Windows, first confirm the USB eMMC disk number in an Administrator
PowerShell and mark it read-only:

```powershell
Get-Disk -Number 1
Set-Disk -Number 1 -IsReadOnly $true
```

Removable readers may not support taking the disk offline. Read-only is the
required protection. Then, from an elevated terminal:

```powershell
python .\tools\migration\image_factory_emmc.py `
  --device '\\.\PhysicalDrive1' `
  --output .\data\printer-backups\factory-emmc `
  --confirm IMAGE-FACTORY-EMMC
```

The tool validates the exact disk size and MBR layout before copying. Never
change the disk number without repeating `Get-Disk` and checking its size.

Read [`../../docs/MAINLINE-MIGRATION.md`](../../docs/MAINLINE-MIGRATION.md)
before using any action other than `Audit` or `Validate*`.

After both MCU links pass the inert smoke test, render a reviewed configuration
with the target printer's exact Beacon serial path:

```powershell
python .\tools\migration\qidi_plus4.py render-config `
  --beacon-serial '/dev/serial/by-id/usb-Beacon_Beacon_RevH_CHANGE_ME-if00' `
  --output .\artifacts\generated-configs\my-plus4
```

The output is ignored by Git and must be reviewed before installation. See the
profile's own README under [`../../mainline-configs/`](../../mainline-configs/).
