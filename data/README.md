# Firmware files and local backups

[Repository home](../README.md) · [Firmware research](../docs/firmware/README.md)

## Where are the firmware files?

Stock firmware evidence is kept locally under `data/printer-backups/retained/`.
These files are ignored by Git and are not included when someone clones the
repository. The tracked [flashing reference](../docs/firmware/FIRMWARE-FLASHING.md)
documents QIDI's update sources and package flow.

| What you need | Path from the repository root |
| --- | --- |
| Factory 1.1.2 analysis snapshot | `data/printer-backups/retained/analysis-1.1.2.tar.gz` |
| Stock 1.7.3 analysis snapshot | `data/printer-backups/retained/analysis-1.7.3.tar.gz` |
| Stock 1.8.2 analysis snapshot | `data/printer-backups/retained/analysis-1.8.2.tar.gz` |
| Stock 1.8.2 mainboard flash readback | `data/printer-backups/retained/recovery/1.8.2/mainboard-full-flash-1.8.2.bin` |
| Stock 1.8.2 toolhead flash readback | `data/printer-backups/retained/recovery/1.8.2/toolhead-full-flash-1.8.2.bin` |
| Stock 1.8.2 QIDI Box flash readback | `data/printer-backups/retained/recovery/1.8.2/qidi-box-full-flash-1.8.2.bin` |
| Factory eMMC user-area image | `data/printer-backups/retained/factory-emmc-user-area.img.gz` |
| Locally built mainline MCU firmware | `artifacts/mainline-firmware/` by default; see [build fragments](../firmware-configs/README.md) |

The analysis archives are filesystem/source snapshots. The recovery `.bin`
files are full MCU flash readbacks; neither is a standard QIDI update package.
Mainline build output is separate from the stock firmware evidence.

## Private input layout

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

## Verify and extract snapshots

Verify without extracting, from the repository root:

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
