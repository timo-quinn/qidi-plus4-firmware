# Tools

[Repository home](../README.md) · [Documentation](../docs/README.md)

Run tools from the repository root unless a command says otherwise.

## Back up a printer

[`Backup-QidiPlus4.ps1`](Backup-QidiPlus4.ps1) streams printer filesystem
backups over SSH and SCP. From PowerShell on Windows:

```powershell
.\tools\Backup-QidiPlus4.ps1 `
  -Printer 'box=192.168.1.50','no-box=192.168.1.51'
```

Replace the example addresses. The script downloads the inventory, verifies
each compressed archive, and records its SHA-256 digest. Use `-Expand` to
extract verified archives locally.

Output goes under `data/printer-backups/`, which is ignored by Git. Backups may
contain credentials, databases, and SSH material. These are filesystem/source
backups; MCU flash readbacks use the procedures in the
[flashing reference](../docs/firmware/FIRMWARE-FLASHING.md).

## Firmware analysis

- [`Prepare-QidiAnalysisSnapshots.py`](Prepare-QidiAnalysisSnapshots.py)
  verifies and extracts the compact private 1.1.2, 1.7.3 and 1.8.2 snapshots.
  Start with the [local data guide](../data/README.md#verify-and-extract-snapshots).
- [`Analyze-QidiFirmware.py`](Analyze-QidiFirmware.py) compares extracted
  1.7.3 and 1.8.2 filesystems.
- [`Analyze-QidiFirmwareLineage.py`](Analyze-QidiFirmwareLineage.py) produces an ordered multi-release file,
  source-patch, native-component and `xindi` lineage.
- [`Export-QidiComponentReference.ps1`](Export-QidiComponentReference.ps1) extracts native component metadata and
  drives the digest-pinned Ghidra container.
- [`Generate-QidiEstimatedSource.py`](Generate-QidiEstimatedSource.py) creates API-oriented Python outlines from
  retained Cython symbols.
- [`Generate-QidiLineageSource.py`](Generate-QidiLineageSource.py) combines the published QIDI Box source with
  recovered API evidence.
- [`Generate-QidiCythonBaseline.py`](Generate-QidiCythonBaseline.py) creates Cython C templates from the published
  Python baseline.
- [`ghidra/`](ghidra/) contains the Java scripts used by headless Ghidra.

See the [analysis indexes](../analysis/README.md) for output locations and
component-specific regeneration instructions.

## Mainline migration

[`migration/`](migration/README.md) contains the Armbian image helper,
reproducible MCU builder, upstream host bootstrap, SSH orchestrator, and guarded
remote flashing helper. Start with the [migration guides](../docs/migration/README.md)
before using printer-facing commands.
