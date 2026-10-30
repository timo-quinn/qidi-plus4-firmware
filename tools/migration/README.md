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

Printerlab also exposes a one-time non-interactive bootstrap for an existing
printer account. Its inventory stores only `sshPasswordEnv`, the name of a
temporary environment variable, alongside a dedicated `identityFile`.
Printerlab launches this tool with `--password-env` and a private randomized,
one-use
`SSH_ASKPASS` gate. This tool then requires the named value and authenticated
askpass channel, disables public-key fallback and multiplexing for the initial
connection, and permits one password prompt. The password is never accepted as
an argument. After `setup-ssh --generate` succeeds, remove `sshPasswordEnv` and
use only the installed key.

## Refreshing a stale Klippee agent

The reviewed refresh operation restarts exactly the managed
`klippee-moonraker.service` user unit and verifies it reaches `active`:

```powershell
python .\tools\migration\qidi_plus4.py refresh-klippee-agent `
  --printer $Printer --confirm REFRESH-KLIPPEE-AGENT
```

It never restarts Klipper, deploys configuration, or reads printer files. It is
intended for orchestration such as `plab klippee refresh-agent`, not as an
implicit retry of a failed Klippee deployment.

## Installing the QIDI Box output clock guard

The clock-guard operation installs exactly the reviewed
`qidibox-modules/box_output_clock_guard.py` at the fixed stock Klipper extras
path. It verifies the local, staged, and installed SHA-256; preserves an
existing target in a timestamped rollback directory; and verifies owner `mks`
and mode `0644`:

```powershell
python .\tools\migration\qidi_plus4.py install-box-output-clock-guard `
  --printer $Printer `
  --confirm INSTALL-BOX-OUTPUT-CLOCK-GUARD
```

The JSON result contains the installed digest and the exact backup path, when a
backup was needed. This command never changes printer configuration and never
stops or restarts Klipper. Add `[box_output_clock_guard]` through the managed
configuration workflow, restart once while idle, and verify the object's status
before operating the Box. See
[`../../docs/fixes/QIDI-BOX-OUTPUT-CLOCK-GUARD.md`](../../docs/fixes/QIDI-BOX-OUTPUT-CLOCK-GUARD.md)
for the activation and verification procedure.


## Upgrading the managed Klippee agent

Use the guarded upgrade operation when a newly deployed Klippee CLI adds an
agent method or response schema:

```powershell
python .\tools\migration\qidi_plus4.py upgrade-klippee-agent `
  --printer $Printer --confirm UPGRADE-KLIPPEE-AGENT
```

The operation is intentionally narrower than remote command execution. It
accepts no executable path or download URL, requires the stock `mks` account,
streams a reviewed source-bound upgrader, and never executes the old CLI as an
upgrade authority. The helper downloads only
`https://klippee.xyz/install/klippee.py` with fixed HTTPS/curl controls,
validates the marker, version, size, UTF-8, and printer-Python syntax, then
atomically replaces only `/home/mks/.local/bin/klippee`. It validates the exact
managed user-unit directives, rejects systemd drop-ins, and proves both the old
and new PIDs run that fixed CLI as `mks`. When the fixed, non-symlink CLI
or unit directory is owned by `mks` but is group/world writable, the helper
normalizes that directory to `0755`. It also normalizes the fixed unit to `0600`
only after its complete contents pass validation. Unexpected ownership, type,
path resolution, inode changes, or unit directives still fail closed. A failed
changed-artifact activation rolls the CLI back and recovers the old agent. Its
JSON result includes the
before/after CLI versions and SHA-256 digests and explicit proof that it neither
restarted Klipper nor deployed configuration. Printerlab exposes this as
`plab klippee upgrade-agent` and first proves the current agent has no running
operation.

The SSH connection may use the dedicated management account created by this
tool. In that case the fixed helper is run only as `mks` through noninteractive
`sudo -u mks`; the management account cannot select another target user.

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
existing `printer.cfg`), restarts mainline Klipper, waits for both MCU objects
to reach `Ready`, and requires the full runtime tuning audit to pass. Failed
checks return a nonzero exit status and leave the inert config installed:

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

Read [`../../docs/migration/MAINLINE-MIGRATION.md`](../../docs/migration/MAINLINE-MIGRATION.md)
before using any action other than `Audit` or `Validate*`.

After both MCU links pass the inert smoke test, render a reviewed configuration
with the target printer's exact Beacon serial path. The runtime profile can
come directly from the companion config repository, which is the preferred
source for sanitized setup profiles. Per-printer state stays in Klippee:

```powershell
python .\tools\migration\qidi_plus4.py render-config `
  --commissioning `
  --profile-dir ..\qidi-plus4-configs\printers\mainline-klipper-beacon `
  --beacon-serial '/dev/serial/by-id/usb-Beacon_Beacon_RevH_CHANGE_ME-if00' `
  --output C:\printerlab-workspaces\my-plus4-mainline
```

Omit `--profile-dir` to keep using the bundled compatibility profile selected
by `--profile`. An output may be outside this repository. `--force` replaces
only a directory carrying `render-config`'s recognized `RENDER-METADATA.json`
marker; it refuses to recursively delete an arbitrary directory. A complete
replacement is staged beside the destination before the old managed render is
moved aside.

Rendered output may contain hardware serials and must be reviewed before
installation or publication. The bundled fallback remains documented under
[`../../mainline-configs/`](../../mainline-configs/).

`--commissioning` enables only the hardware and Beacon homing includes, uses
watermark heater control and conservative motion limits, clears source input
shaping and pressure advance, and leaves production/Box/Shake&Tune inactive.
Review PB4 fan wiring, Beacon offsets and accelerometer orientation before
installing it. Calibrate heaters, probe and motion on the target printer before
rendering/enabling the production profile. Printerlab resume uses this mode.

Build and bootstrap use immutable reviewed commits, and build rejects changed
source trees. On Windows, `build --wsl-distro Ubuntu` accepts Linux source
paths and translates absolute Windows output paths. The default install set is
listed in [the fix report](../../docs/history/QIDI1-MIGRATION-FIXES-2026-10-04.md).
`bootstrap-host --artifacts <directory>` checks the complete image manifest and
source pins before any SSH mutation. `--printer-user` selects the actual owner.
`--beacon-ref` installs only the pinned host module and never flashes a probe.

The toolhead Katapult wrapper saves a 64 KiB recovery dump on the workstation
before erase. It requires a second read from the attached target to match that
dump; failed download or verification leaves the chip unerased.
