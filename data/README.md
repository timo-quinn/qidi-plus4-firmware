# Local data

`printer-backups/` contains private local evidence used by the analysis tools.
That directory is ignored by Git because the inputs may contain credentials,
API keys, databases, SSH material, and other private printer state.

After compaction, the retained layout is:

```text
data/printer-backups/retained/
|-- analysis-1.1.2.tar.gz
|-- analysis-1.7.3.tar.gz
|-- analysis-1.8.2.tar.gz
|-- factory-emmc-user-area.img.gz
|-- factory/             # boot prefix and source image manifest
|-- recovery/            # retained MCU flash readbacks
|-- source-manifests/    # original backup inventories and archive hashes
`-- retained-files.json  # size and SHA-256 inventory
```

Verify without extracting:

```console
python tools/Prepare-QidiAnalysisSnapshots.py --verify-only
```

For analysis, extract into a disposable Linux/WSL filesystem so modes and
symlinks are retained:

```console
python3 tools/Prepare-QidiAnalysisSnapshots.py \
  --output ~/qidi-plus4-analysis
```

Pass the resulting `1.1.2`, `1.7.3`, and `1.8.2` directories to
`Analyze-QidiFirmwareLineage.py`. The full factory image remains reproducible by
decompressing `factory-emmc-user-area.img.gz`; its decompressed hash is recorded
in both manifests.

Do not force-add the backup directory to Git. Publish only reviewed outputs from
`docs/`, `analysis/`, and `tools/`.
