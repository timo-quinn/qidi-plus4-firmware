# Plus4 2.1.1 comparison evidence

[Findings](../../../docs/firmware/FIRMWARE-2.1.1.md) · [Firmware evidence](../README.md)

These reviewed outputs compare the Aliyun Plus4 2.1.1 OTA overlay downloaded
on 11 November 2026 with matching paths in the retained installed 1.8.2
snapshot. They contain hashes, a readable source diff and named API/function
metadata. Firmware binaries, private configuration contents and unrestricted
binary strings remain local.

| File | Contents |
| --- | --- |
| [provenance.json](provenance.json) | Input URLs, versions, sizes, hashes, capture date and Ghidra image |
| [comparison-summary.json](comparison-summary.json) | Payload and subsystem counts, with comparison exclusions |
| [matched-files.csv](matched-files.csv) | All 120 matching paths: status, sizes and old/new hashes |
| [native-components.csv](native-components.csv) | Ten Klipper/Moonraker extensions and the `xindi` executable |
| [native-api-diff.json](native-api-diff.json) | Added, removed and retained Cython wrapper names for the five changed extensions |
| [selected-native-evidence.json](selected-native-evidence.json) | Selected methods, ELF symbol addresses, identifiers and local raw-output locators |
| [moonraker.patch](moonraker.patch) | All three readable Moonraker source changes, normalized for line endings |

`not_in_snapshot` means a supplied path was not captured in the baseline;
it does not mean the file was introduced by 2.1.1. Paths omitted from the
update are not counted as removals. Four changed installed configuration files
are included as hash records, but their contents can include local state and
are excluded from vendor source conclusions.

API deltas describe named wrappers, not behavioral equivalence. Nested
generator/lambda names may change with compilation. Native identifiers and
schemas come from static inspection; they are not captured runtime responses.
The `local_raw_file`/`local_raw_line` fields locate the retained original
Ghidra output, while ELF symbols/addresses allow independent navigation without
that local directory.

## Reproduction

The exact inputs are identified by SHA-256 in `provenance.json`. OTA URLs
are mutable, so a later download is the same input only when its hash matches.
The retained baseline is private; use the
[snapshot preparation tool](../../../tools/Prepare-QidiAnalysisSnapshots.py)
to verify/extract it on a machine that holds the retained archives.

The original local inputs, scripts and raw outputs remain under the ignored
`artifacts/vendor-firmware/2026-11-11/` directory:

```text
aliyun/QD_Plus4_SOC                 host update package
aliyun/QD_Plus4_UI                  screen payload
aliyun/rootfs/                     regular files unpacked from the host update
baseline-1.8.2/                    selected baseline files
comparison.json                    all 1,165 supplied paths
native/<component>/<version>/      symbols, rodata and native metadata
native/<component>/2.1.1/           Ghidra pseudocode and disassembly
```

The retained local `compare_payload.py` verifies the archive, compares supplied
paths only and generates the source patches. `native_diff.py` exports native
metadata; `index_evidence.py` indexes recovered functions and wrapper deltas.
`publish_documentation_evidence.py` generates the reviewed subset here.

Independent reproduction follows the same operations:

1. Verify both downloads and the baseline archive against the published hashes.
   The host payload is a Debian package. `dpkg-deb --extract` and
   `dpkg-deb --control` inspect it without running maintainer scripts.
2. For each supplied regular file, compare its path/size/SHA-256 with the same
   path under the baseline's `1.8.2/` prefix. Report absent captured paths
   separately. Normalize only line endings when producing the readable diff.
3. Export `nm -an --demangle`, `readelf -hSWn`, `readelf -dW` and
   `readelf -p .rodata` for each changed extension and `xindi`.
   [Generate-QidiEstimatedSource.py](../../../tools/Generate-QidiEstimatedSource.py)
   supplies `decode_wrapper` and `decompiled_chunks` for API/function indexing.
4. Import changed extensions with the pinned Ghidra image from `provenance.json`.
   Use [ExportCythonDecompilation.java](../../../tools/ghidra/ExportCythonDecompilation.java)
   for named routines/disassembly and
   [ExportCoroutineBodies.java](../../../tools/ghidra/ExportCoroutineBodies.java)
   for actual Cython coroutine bodies. Inspect the latter for async MQTT and
   agent handlers; their wrappers alone do not contain the implementation.

For a container with the input at `/input/mqtt.so`, scripts at `/scripts` and
a writable output directory at `/output`, the headless invocation is:

```console
/ghidra/support/analyzeHeadless /tmp plus4_211_mqtt \
  -import /input/mqtt.so -analysisTimeoutPerFile 300 -max-cpu 4 \
  -scriptPath /scripts \
  -postScript ExportCythonDecompilation.java /output/decompiled.c /output/disassembly.txt \
  -postScript ExportCoroutineBodies.java /output/coroutines.c \
  -deleteProject
```

Mount input/scripts read-only and output separately; no printer, package
installation, network access or vendor-code execution is needed for these
operations. Existing `Export-QidiComponentReference.ps1` selects 1.7.3/1.8.2
paths, so its default selection does not regenerate this release.

## Coverage and limitations

Named routine export succeeded for 95/96 BoxExtras functions, 45/45 BoxStepper
functions, 155/156 controller functions, 102/103 MQTT functions and 32/32
extensions functions. The three failures are Cython module initializers.
All 40 MQTT and 13 extensions coroutine bodies exported successfully.
BoxExtras automatic analysis reached its 300-second limit before routine
export. Full source recovery and physical/runtime validation are not claimed.

These artifacts follow the repository [NOTICE](../../../NOTICE). The readable
Moonraker diff remains derived GPLv3 material; reverse-engineered metadata does
not relicense QIDI firmware or constitute firmware to install.
