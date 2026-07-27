# Firmware analysis artifacts

Start with the [three-way lineage report](../../docs/FIRMWARE-LINEAGE.md), then
the detailed [firmware change report](../../docs/FIRMWARE-CHANGES.md). They
cover factory 1.1.2 through 1.8.2 across Klipper, Moonraker,
`xindi`, QIDILink, the release payload, services and captured firmware images.
See [firmware flashing research](../../docs/FIRMWARE-FLASHING.md) for the recovered offline,
online, toolhead, QIDI Box and touchscreen update paths.

Supporting evidence:

* `file-changes.csv` and `file-change-summary.json` contain the selected
  filesystem comparison;
* [`lineage/`](lineage/) contains the ordered 1.1.2-to-1.7.3-to-1.8.2 file,
  native-component, source-patch and `xindi` evidence;
* `patches/` contains readable diffs against each embedded repository's
  recorded upstream commit, plus additive patches for untracked source;
* `xindi-metadata.json`, `xindi-symbols-*.txt` and
  `xindi-filtered-strings-*.txt` contain the touchscreen binary comparison;
* `toolhead-mcu-dictionary.json` is the Klipper command dictionary extracted
  from the toolhead flash dump (stock Klipper; see
  [`../../docs/TOOLHEAD-MCU-FIRMWARE.md`](../../docs/TOOLHEAD-MCU-FIRMWARE.md));
* `../components/` contains ELF metadata, symbols, strings, ARM64
  disassembly and Ghidra pseudocode for QIDI's compiled Python extensions;
* `../components/estimated-source/` contains generated, non-runnable
  Python-shaped API outlines for those extensions.

Regenerate the filesystem and `xindi` artifacts with
`tools/Analyze-QidiFirmware.py`. Regenerate the estimated source outlines
with `tools/Generate-QidiEstimatedSource.py`. The original Cython source
cannot be recovered exactly from native `.so` files; the outlines are an
index into retained binary evidence, not replacement firmware.
