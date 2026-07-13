# QIDI compiled component reference

This directory contains reproducible reverse-engineering output for compiled
Klipper and Moonraker components recovered from QIDI Plus4 firmware 1.7.3 and
1.8.2 installations.

See `INDEX.md` for component coverage, decompiler success counts and the most
useful starting points for QIDI Box/Happy Hare interoperability work.
See `FUNCTION-COMPARISON.md` for a method-level 1.7.3-to-1.8.2 navigation guide
covering the changed Box modules.
See `LINEAGE-ANALYSIS.md` for the comparison with QIDI's earlier published,
MIT-licensed Box Python source and the higher-readability derived sources.
Generated Python-shaped, non-runnable source outlines are under
`estimated-source/`; regenerate them with
`tools/Generate-QidiEstimatedSource.py`.
Published-baseline lineage estimates are under `lineage-source/`; regenerate
them with `tools/Generate-QidiLineageSource.py` and a Plus4-Wiki checkout.

The output is technical reference material for interoperability work. Files
named `decompiled.c` are Ghidra pseudocode, not QIDI's original source and not
guaranteed to compile. Generated variable types, control flow, names and
signatures may be wrong. The retained Cython symbols and strings are often more
authoritative than a decompiler's inferred types.

## Rebuilding the reference

From the repository root on Windows:

```powershell
.\tools\Export-QidiComponentReference.ps1
```

Requirements:

* compact snapshots prepared below `data/printer-backups/work/1.7.3` and
  `1.8.2` with `tools/Prepare-QidiAnalysisSnapshots.py`;
* Docker Desktop;
* Docker access to the digest-pinned `blacktop/ghidra` analysis image selected
  by the script.

Use `-Scope ChangedOnly` to export only components added or changed between the
two releases. Use `-SkipDecompilation` for a quick ELF/symbol/string/disassembly
pass. `-Force` regenerates existing pseudocode.

Each component directory contains:

* `elf-header.txt`, `sections.txt`, `dynamic.txt` and `notes.txt`;
* `symbols.txt`, retaining Cython's original method-oriented symbol names;
* `strings.txt`, with hexadecimal file offsets;
* `disassembly.txt`, the complete ARM64 instruction listing (generated with
  the Ghidra pass);
* `decompiled.c`, named Cython implementation (`__pyx_pf_*`, `__pyx_f_*`) and
  wrapper (`__pyx_pw_*`) functions rendered as Ghidra C-like pseudocode.

`manifest.csv` and `manifest.json` record firmware version, subsystem, original
installed path, byte size, SHA-256 and whether the component changed between
the two releases. Original `.so` files are intentionally not copied here.

## Interpretation priorities

For QIDI Box and Happy Hare interoperability, inspect these first:

1. `box_stepper`: movement, homing, load/unload and sensor state transitions;
2. `box_extras`: shared endstops, heater policy, buttons and orchestration;
3. `multi_color_controller`: QIDI's 1.8.2 local/remote adapter and public state;
4. `box_rfid`: FM17550 MCU command and card result handling;
5. `aht20_f`, `box_detect` and `buttons_irq`: peripheral behavior;
6. 1.8.2 Moonraker `extensions`, `mqtt` and `frp_manager`: cloud/UI transport,
   which is not required for an open Happy Hare hardware backend.

Do not infer electrical safety limits solely from pseudocode. Validate heater,
fan, motor and endstop behavior against the printer configuration and hardware.
