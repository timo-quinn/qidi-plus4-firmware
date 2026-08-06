# Three-way firmware lineage evidence

Generated, publishable evidence for the ordered QIDI Plus4 comparison:

1. factory firmware 1.1.2 / UI V112;
2. firmware 1.7.3 / UI V173;
3. firmware 1.8.2 / UI V182 with QIDI Box.

Start with [`../../../docs/FIRMWARE-LINEAGE.md`](../../../docs/FIRMWARE-LINEAGE.md).

- `file-lineage.csv` contains changed path metadata and both transitions.
- `transition-summary.json` includes changed and unchanged counts per area.
- `key-files.json` records boot, screen, updater and firmware-tool anchors.
- `native-components.json` inventories installed native Klipper/Moonraker
  components for every snapshot.
- `xindi/` contains metadata, symbols, and security-filtered string deltas.
- `transitions/` contains readable installed-source and service patches;
  `.skipped.txt` files identify native/binary changes not represented as text.
- `patches/` contains each source tree's NUL-free UTF-8 tracked diff against its
  recorded Git HEAD, plus untracked-source indexes and readable additive
  patches. Sibling `*.skipped.txt` manifests record binary, NUL-bearing, or
  non-UTF-8 paths excluded from readable publication, with content hashes when
  generated from a snapshot.
- `snapshots.json` records release identities and Git revisions without local
  input paths.

Regenerate with `tools/Analyze-QidiFirmwareLineage.py` inside Linux/WSL after
mounting the factory root and boot partitions read-only and extracting later
backups into Unix-native storage. The ordered interface is:

```console
python3 tools/Analyze-QidiFirmwareLineage.py \
  --snapshot 1.1.2=/path/to/factory-root \
  --snapshot 1.7.3=/path/to/extracted-1.7.3 \
  --snapshot 1.8.2=/path/to/extracted-1.8.2 \
  --output analysis/firmware/lineage
```

Some older Klipper patch blobs are retained as text evidence placeholders
because the original generated diff embedded NUL bytes from vendor header
files. Each placeholder records the original commit, path, byte count, and
SHA-256 so the exact historical blob remains recoverable. A Linux/WSL
regeneration with the current tool will replace it with the filtered readable
patch and a hashed skipped-path manifest.

Printer configurations are retained as metadata evidence but contain owner
customizations and must not be treated as vendor-only changes.
