# Firmware analysis artifacts

Start with the [three-way lineage report](../../docs/firmware/FIRMWARE-LINEAGE.md), then
the detailed [firmware change report](../../docs/firmware/FIRMWARE-CHANGES.md). They
cover factory 1.1.2 through 1.8.2 across Klipper, Moonraker,
`xindi`, QIDILink, the release payload, services and captured firmware images.
See [firmware flashing research](../../docs/firmware/FIRMWARE-FLASHING.md) for the recovered offline,
online, toolhead, QIDI Box and touchscreen update paths.

Supporting evidence:

* `file-changes.csv` and `file-change-summary.json` contain the selected
  filesystem comparison;
* [`lineage/`](lineage/) contains the ordered 1.1.2-to-1.7.3-to-1.8.2 file,
  native-component, source-patch and `xindi` evidence;
* `patches/` contains readable diffs against each embedded repository's
  recorded upstream commit, plus additive patches for untracked source;
  `*.skipped.txt` records source paths excluded because they were binary,
  NUL-bearing, or not UTF-8;
* `xindi-metadata.json`, `xindi-symbols-*.txt` and
  `xindi-filtered-strings-*.txt` contain the touchscreen binary comparison;
* `toolhead-mcu-dictionary.json` is the Klipper command dictionary extracted
  from the toolhead flash dump (stock Klipper; see
  [`../../docs/firmware/TOOLHEAD-MCU-FIRMWARE.md`](../../docs/firmware/TOOLHEAD-MCU-FIRMWARE.md));
* `../components/` contains ELF metadata, symbols, strings, ARM64
  disassembly and Ghidra pseudocode for QIDI's compiled Python extensions;
* `../components/estimated-source/` contains generated, non-runnable
  Python-shaped API outlines for those extensions.

Regenerate the filesystem and `xindi` artifacts with
`tools/Analyze-QidiFirmware.py`. Regenerate the estimated source outlines
with `tools/Generate-QidiEstimatedSource.py`. The original Cython source
cannot be recovered exactly from native `.so` files; the outlines are an
index into retained binary evidence, not replacement firmware.
