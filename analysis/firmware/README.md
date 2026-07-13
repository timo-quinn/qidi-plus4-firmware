# Firmware analysis artifacts

Start with the [firmware change report](../../docs/FIRMWARE-CHANGES.md). It
summarizes the full 1.7.3-to-1.8.2 comparison across Klipper, Moonraker,
`xindi`, QIDILink, the release payload, services and captured firmware images.
See [firmware flashing research](../../docs/FIRMWARE-FLASHING.md) for the recovered offline,
online, toolhead, QIDI Box and touchscreen update paths.

Supporting evidence:

* `file-changes.csv` and `file-change-summary.json` contain the selected
  filesystem comparison;
* `patches/` contains readable diffs against each embedded repository's
  recorded upstream commit, plus additive patches for untracked source;
* `xindi-metadata.json`, `xindi-symbols-*.txt` and
  `xindi-filtered-strings-*.txt` contain the touchscreen binary comparison;
* `../components/` contains ELF metadata, symbols, strings, ARM64
  disassembly and Ghidra pseudocode for QIDI's compiled Python extensions;
* `../components/estimated-source/` contains generated, non-runnable
  Python-shaped API outlines for those extensions.

Regenerate the filesystem and `xindi` artifacts with
`tools/Analyze-QidiFirmware.py`. Regenerate the estimated source outlines
with `tools/Generate-QidiEstimatedSource.py`. The original Cython source
cannot be recovered exactly from native `.so` files; the outlines are an
index into retained binary evidence, not replacement firmware.
