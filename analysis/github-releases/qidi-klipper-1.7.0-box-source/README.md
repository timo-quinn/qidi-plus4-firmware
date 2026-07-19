# QIDI Box modules — authoritative source (firmware 1.7.0)

These are QIDI's own Python source files for the QIDI Box Klipper extension
modules, taken from QIDI's public Klipper fork at the commit pinned by the
`Plus4_v1.7.0` release. This is the last firmware version in which QIDI shipped
these modules as open source; from `Plus4_v1.7.1` onward they are compiled
Cython `.so` binaries.

## Provenance

| Field | Value |
|---|---|
| Upstream repo | https://github.com/QIDITECH/klipper (branch `PLUS4`) |
| Commit | `1c4531a5c12c` (pinned by QIDITECH/QIDI_PLUS4 tag `Plus4_v1.7.0`) |
| Path | `klippy/extras/` |
| License | **GNU GPLv3** (QIDI's fork of Klipper; `COPYING` is GPLv3) |

The commit is orphaned on the upstream `PLUS4` branch (QIDI rebased it later),
so `git fetch` of the bare SHA is refused; the blobs were retrieved through the
GitHub contents API, which still serves them.

## Files

`aht20_f.py`, `box_detect.py`, `box_extras.py`, `box_rfid.py`, `box_stepper.py`.

`aht20_f.py` carries an explicit header: "Copyright (C) 2023 Scott Mudge ...
This file may be distributed under the terms of the GNU GPLv3 license." The
others have no per-file header but are part of QIDI's GPLv3 Klipper tree.

## Why this matters: the "MIT" community snapshot is this GPLv3 source

The community-archived snapshot commonly cited as MIT-licensed
(`qidi-community/Plus4-Wiki/.../qidibox-on-orcaslicer/original_source`,
"Copyright (c) 2024 stew675") is **byte-for-byte identical** to these files:

| File | SHA-256 |
|---|---|
| aht20_f.py | c3c8f716e5188e5ee2db04a01e57bad302a0bb91b7280eaa9c50753a26249c62 |
| box_detect.py | f05433e3a3407ca3244413625eb8ba89b3d8f9bb7d2714befd6c9384cd7602c3 |
| box_extras.py | ae99d1504d71b6afe017459873c46f2c25158fe7cc913105399721ab8bd3e21e |
| box_rfid.py | 242b943b566ae57414758600a33b6b4331b6847b23bc7b811653a1cfb8188dd7 |
| box_stepper.py | cb3def5cd019e32c65d45f1e1ad03460ff16e407f786802dd2f74d8ad6a4cf68 |

Because this is QIDI's GPLv3 code, the MIT label on that re-publication does not
govern it: GPLv3 code cannot be relicensed to MIT by a third party. These
modules — and anything built from them, including
[`../../../qidibox-modules/`](../../../qidibox-modules/) — are therefore GPLv3.
This directory records the authoritative GPLv3 origin.

## Relationship to the compiled binaries analyzed elsewhere

The repository's decompilation lineage matched this same published source to the
compiled 1.7.3 and 1.8.2 `box_*.so` binaries (all 116 public APIs present). The
binaries additionally expose three `BoxExtras` commands not in this snapshot
(`cmd_TRY_RESUME_PRINT`, `cmd_BOX_PRINT_START`, `cmd_INIT_MAPPING_VALUE`); see
[`../../components/LINEAGE-ANALYSIS.md`](../../components/LINEAGE-ANALYSIS.md).
