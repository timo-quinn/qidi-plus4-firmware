# Tools

- `Backup-QidiPlus4.ps1` streams printer filesystem backups over SSH and SCP.
- `Analyze-QidiFirmware.py` compares extracted 1.7.3 and 1.8.2 filesystems.
- `Analyze-QidiFirmwareLineage.py` produces an ordered multi-release file,
  source-patch, native-component and `xindi` lineage.
- `Export-QidiComponentReference.ps1` extracts native component metadata and
  drives the digest-pinned Ghidra container.
- `Generate-QidiEstimatedSource.py` creates API-oriented Python outlines from
  retained Cython symbols.
- `Generate-QidiLineageSource.py` combines the published QIDI Box source with
  recovered API evidence.
- `Generate-QidiCythonBaseline.py` creates Cython C templates from the published
  Python baseline.
- [`ghidra/`](ghidra/) contains the Java scripts used by headless Ghidra.
- [`migration/`](migration/) contains the official Armbian image helper,
  reproducible MCU builder, upstream host bootstrap, SSH orchestrator, and
  guarded remote flashing helper.

Run tools from the repository root so the commands documented under
[`../docs/`](../docs/) use the expected relative paths.
