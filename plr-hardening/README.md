# QIDI Plus4 power-loss recovery hardening

This directory replaces QIDI's unbounded shell recovery builder and hardens
the vendor `virtual_sdcard.py` checkpoint extension.  It is specifically aimed
at the stock Python 3.7 runtime, but all deployment is source-based and
manifest-verified.

The incident that prompted this work was not a QIDI Box USB failure.  The
generated recovery file replayed thousands of historical `M106` commands while
`CLEAR_NOZZLE_PLR` still had queued chute motion.  Klippy saturated, the motion
buffer drained, and the main motion MCU reported `Timer too close`.  A separate
vendor bug also allowed printing `.plr/plr.gcode` to overwrite the checkpoint
for the original source file.

## What changes

- `plr_checkpoint.py` records an atomic JSON checkpoint bound to the exact
  source path, device/inode, size, mtime, and sampled source hash.  A `.plr`
  source cannot create, truncate, or update either checkpoint file.
- Checkpoint fsync runs in one bounded, coalescing background writer rather
  than Klippy's reactor.  Lookahead callbacks delay publication until the MCU
  print time associated with that line has passed.  A terminal state can
  replace an active snapshot that has not begun IO.
- `generate_recovery.py` streams the continuation from the exact checkpointed
  source.  It restores only the effective P0/P2/P3 fan state (including
  `M107`), fences nozzle cleanup with `M400`, restores checkpoint XY/Z/E,
  G90/G91, M82/M83, nominal F, M220, and M221, then copies the unprocessed tail.
- `patch_virtual_sdcard.py` accepts only the expected QIDI vendor source shape,
  requires every anchor exactly once, parses input/output as Python, and is
  idempotent.
- `install.py` is dry-run by default.  Apply requires a stopped, observably
  inactive exact systemd unit, uses atomic writes and directory ownership,
  backs up every replaced file, rolls back a partial failure, and never starts
  a service.
- Legacy metadata on the exact canonical
  `/home/<printer-user>/scripts/plr` directory is repaired as an explicit
  transaction action.  The desired uid/gid come from the printer account's
  passwd entry, and the desired full mode is the original mode with only
  group/world write removed.  No permission is added; a mode that lacks owner
  write/execute is refused.  The installer binds the real directory by
  device/inode, records both original and desired metadata in the durable
  backup manifest, revalidates the published recovery artifacts after
  normalization, and restores the exact original uid, gid, and full mode during
  automatic or explicit rollback.  It never recursively changes or rejects
  unrelated legacy children.  Other unsafe paths, symlinks, and unexpected
  metadata transitions remain fail-closed.

An authoritative checkpoint deliberately remains `state=not_ready, line=0`
until a positive line is physically eligible and durably published.  The
generator accepts only `state=active` with a positive line.

### Honest recovery boundary

Durability can lag the live print by a lookahead interval and eMMC write time.
It can never intentionally point ahead of motion known to be physically due,
but the printer may have executed later commands after the last durable line.
Recovery can therefore repeat a small region.  Inspect the generated
checkpoint metadata and print before choosing to resume; this is not an
automatic-resume mechanism.

## Printer configuration

The installer preserves `/home/mks/scripts/plr/plr.sh` as a generated wrapper,
so the existing command stays exactly:

```ini
[gcode_shell_command POWER_LOSS_RESUME]
command = bash /home/mks/scripts/plr/plr.sh
timeout = 120
```

`UPDATE_GCODE_LINES` is obsolete.  The JSON checkpoint supplies the line and
source identity, so remove both of these from the printer config:

```ini
[gcode_shell_command UPDATE_GCODE_LINES]
command = bash /home/mks/scripts/plr/update_gcode_lines.sh
```

```gcode
RUN_SHELL_COMMAND CMD=UPDATE_GCODE_LINES
```

Leaving them temporarily in place does not select the recovery source and does
not alter the hardened generator, but removal avoids two competing notions of
the recovery line.  This `.cfg` cleanup can be deployed through Klippee; the
Python and shell runtime assets cannot.

## Reviewed deployment commands

Printerlab can invoke the existing migration CLI.  Deployment uploads the
manifest bundle, runs a JSON dry-run, stops and proves `klipper.service`
inactive, applies, reruns the dry-run as an idempotence check, and leaves
Klipper stopped:

```bash
python tools/migration/qidi_plus4.py deploy-plr-hardening \
  --printer qidi1 \
  --user plab \
  --identity /path/to/plab_ed25519 \
  --confirm DEPLOY-PLR-HARDENING
```

Success emits `qidi-plus4-plr-deployment/v1`.  A changed deployment exposes
`backup_manifest` at the top level and retains the same value in the nested
installation result; retain that exact opaque remote path.  Deployment never
starts or restarts Klipper.

After review, activation is a separate exact command.  It performs no printer
config or runtime-file reads; it only starts the selected unit and verifies
that systemd remains `active` throughout a bounded stability window:

```bash
python tools/migration/qidi_plus4.py start-klipper \
  --printer qidi1 \
  --user plab \
  --identity /path/to/plab_ed25519 \
  --rollback-manifest /home/mks/scripts/plr/backups/PLR_BACKUP/backup-manifest.json \
  --confirm START-KLIPPER
```

Success emits `qidi-plus4-klipper-start/v1` with all stability samples. A
higher-level caller should additionally wait for Moonraker to report Klippy
`ready`; stable systemd state alone cannot prove imports and configuration
finished successfully. If activation fails, use the explicit rollback command;
rollback validates the backup manifest and every
target/hash, stops and proves the unit inactive, restores atomically, verifies
idempotence, and also leaves Klipper stopped:

```bash
python tools/migration/qidi_plus4.py rollback-plr-hardening \
  --printer qidi1 \
  --user plab \
  --identity /path/to/plab_ed25519 \
  --backup-manifest /home/mks/scripts/plr/backups/PLR_BACKUP/backup-manifest.json \
  --confirm ROLLBACK-PLR-HARDENING
```

Success emits `qidi-plus4-plr-rollback/v1` and echoes the exact
`backup_manifest`. Neither start nor rollback is retried implicitly.

For an already-local bundle, `install.py --json` returns a read-only plan.
Only this form writes files, and it still refuses an active, missing, or
unknown unit:

```bash
/home/mks/klippy-env/bin/python install.py \
  --apply --klipper-stopped --json
```

## Scope exclusion: QIDI Box binaries

No `cp37-aarch64/box_extras.so` or other QIDI Box binary is included in this
runtime bundle.  The repository's rebuilt 1.7 source lacks commands used by the
factory QIDI1 module (`TRY_RESUME_PRINT`, `BOX_PRINT_START`, and
`INIT_MAPPING_VALUE`), so replacing that module without a full compatibility
preflight would be unsafe.  The macro-only fixes in `qidibox-modules` remain a
separate, reviewed config change.

## Tests

```bash
python -m pytest tests/test_plr_hardening.py \
  qidibox-modules/tests/test_distribution.py \
  tools/migration/tests/test_qidi_plus4.py
```

The suite covers Python 3.7 syntax, strict/idempotent patching, source identity,
line-zero fail-closed behavior, motion-time checkpoint publication, slow-fsync
coalescing and terminal ordering, `.plr` poisoning prevention, fan compaction,
absolute/relative XYZE modes, Z-hop recovery, modal feed/factors, atomic
installer/rollback behavior, and the stopped deployment/start boundary.
