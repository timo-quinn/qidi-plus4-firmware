# Analysis output

Reviewable generated evidence derived from the local printer backups:

- [`firmware/`](firmware/) contains filesystem comparisons, readable patches,
  touchscreen symbols and strings, and decompiled update/USB protocol routines.
- [`components/`](components/) contains compiled Klipper and Moonraker component
  metadata, symbols, disassembly, Ghidra pseudocode, and source estimates.

The original printer backups are deliberately excluded from Git. See
[`../data/README.md`](../data/README.md) for the local input layout and
[`../tools/README.md`](../tools/README.md) for regeneration commands.
