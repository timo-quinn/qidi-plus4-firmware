# Published-source lineage analysis

## Result

The five Python files published by the QIDI community are a strong source
lineage match for the compiled QIDI Box modules in firmware 1.7.3 and 1.8.2.
They are substantially more useful than decompiler output for understanding
the common implementation.

Published baseline:

<https://github.com/qidi-community/Plus4-Wiki/tree/main/content/qidibox-on-orcaslicer/original_source>

The analysis used Plus4-Wiki tree revision
`9716c01355aa76f061f7dad35a719cbed91b22ee`. The five files were originally
added on 29 July 2025 in commits `82a938b`, `de93d12`, `11177e0`, `62a1c31`
and `a1a0270`, published there under an MIT license.

That MIT label, however, does not govern this source. The five files are
byte-identical to QIDI's own Box source in its GPLv3 Klipper fork at firmware
1.7.0 (see [`../github-releases/qidi-klipper-1.7.0-box-source/`](../github-releases/qidi-klipper-1.7.0-box-source/)),
so the material is GPLv3; a third party cannot relicense it to MIT. The MIT text
is retained only as a record of how the snapshot was published. Treat the
lineage source below as GPLv3.

## Exact API relationship

The published files define 116 module functions and class methods. Every one
of those APIs has a corresponding retained Cython wrapper symbol in both the
1.7.3 and 1.8.2 binaries. There are no published-only APIs.

| Module | Published APIs | Present in 1.7.3 | Present in 1.8.2 | Literal strings retained |
| --- | ---: | ---: | ---: | ---: |
| `aht20_f` | 13 | 13 | 13 | 27/30 (90%) |
| `box_detect` | 12 | 12 | 12 | 49/52 (94%) |
| `box_extras` | 58 | 58 | 58 | 121/154 (79%) |
| `box_rfid` | 8 | 8 | 8 | 13/13 (100%) |
| `box_stepper` | 25 | 25 | 25 | 103/112 (1.7.3), 102/112 (1.8.2) |

Literal matching is an additional lineage indicator, not an identity test.
Some source strings are transformed, concatenated or omitted by Cython, and a
same-name method can still have changed control flow.

Both firmware sets identify the generated runtime as Cython 3.0.12.
Regenerating C with that exact Cython version reproduces the same naming
scheme and supplies readable generated-C templates that can be aligned with
the target `__pyx_*` symbols. It does not reproduce QIDI's optimized ARM64
binary without the original source revisions, compiler, Python headers and
build flags.

## APIs added after the published baseline

Both binary versions add the same three externally callable `BoxExtras`
methods:

* `cmd_TRY_RESUME_PRINT(self, gcmd)`;
* `cmd_BOX_PRINT_START(self, gcmd)`;
* `cmd_INIT_MAPPING_VALUE(self, gcmd)`.

The other four binary-only wrapper names are compiler-generated nested
functions or lambdas inside `_create_drying_state_setter`,
`cmd_ENABLE_BOX_DRY` and `multi_complete`; they are not separate public
features.

This establishes that the published snapshot predates at least those three
commands. It does not establish whether every shared method body is identical
to either firmware.

## Confidence by module

* **High lineage confidence:** `aht20_f`, `box_detect` and `box_rfid`. Their
  APIs match the published source completely and their `.so` files are
  byte-identical between firmware versions.
* **Medium lineage confidence:** unchanged-looking methods in `box_extras`
  and `box_stepper`. Their complete API and high literal overlap establish a
  common source family, but the two binaries themselves changed.
* **Low body confidence:** the three binary-only commands and the methods
  already identified as changing between 1.7.3 and 1.8.2. Their published
  bodies must not be represented as recovered target source.

Known version-sensitive methods include:

* `BoxExtras._create_drying_state_setter`;
* `BoxExtras.set_box_temp`;
* `BoxExtras.update_e_endstop`;
* `BoxExtras.cmd_BOX_PRINT_START`;
* `BoxExtras.cmd_INIT_MAPPING_VALUE`;
* `BoxExtruderStepper.runout_button_callback`;
* `BoxExtruderStepper.cmd_SLOT_UNLOAD`;
* `BoxExtruderStepper.cmd_EXTRUDER_LOAD`;
* `BoxExtruderStepper.slot_sync`.

The strongest confirmed 1.8.2 semantic delta remains the new `enable_box`
guard and explicit Box heater error path. The stepper delta replaces an older
G-code-based motion-sensor disable path with direct manipulation of runout
helper state.

## Generated lineage source

`lineage-source/1.7.3/klipper` and `lineage-source/1.8.2/klipper` contain the
published baseline (GPLv3; see the licensing note above) with:

* provenance and deployment warnings;
* inline warnings on known version-sensitive published methods;
* explicit non-runnable stubs for the three binary-only public commands;
* `api-comparison.csv`, recording every published/binary API relationship;
* `LICENSE.published-baseline`, retaining the snapshot's MIT text as a record of
  how it was published (not the operative license — the source is GPLv3).

These files are the best readable starting point for a clean-room mainline
implementation, but they are deliberately not asserted to be deployable QIDI
firmware. Hardware-facing behavior should be rebuilt and tested method by
method, using the published body as context and the version-specific Ghidra
output as evidence.

Regenerate them after cloning the Plus4-Wiki repository:

```powershell
python tools/Generate-QidiLineageSource.py `
  --baseline C:\path\to\Plus4-Wiki\content\qidibox-on-orcaslicer\original_source `
  --source-revision 9716c01355aa76f061f7dad35a719cbed91b22ee
```

The more general `estimated-source/` outlines remain useful for components
that have no published baseline, especially `multi_color_controller`, MQTT,
extensions and FRP management.

For manual native-code alignment, generate matching-version Cython C into a
temporary directory with:

```powershell
python tools/Generate-QidiCythonBaseline.py `
  --baseline C:\path\to\Plus4-Wiki\content\qidibox-on-orcaslicer\original_source `
  --output C:\temp\qidi-cython-baseline
```
