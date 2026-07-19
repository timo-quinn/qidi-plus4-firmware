# QIDI Plus4 GitHub release lineage (1.3.2 – 1.7.1)

QIDI published Plus4 firmware to <https://github.com/QIDITECH/QIDI_PLUS4> as
tagged releases whose `klipper` and `moonraker` submodules are pinned per
version. This extends the repository's filesystem-based lineage (1.1.2, 1.7.3,
1.8.2) with QIDI's own source for the intermediate versions, taken directly
from those tags. Unlike the compiled backups, these are readable source, so no
decompilation is required.

## Method

For each release tag the pinned submodule commits were read from the
`QIDITECH/QIDI_PLUS4` tree. Source was inspected from clones of
`QIDITECH/klipper` and `QIDITECH/moonraker`; the orphaned 1.7.0 Klipper commit
(unreachable after a later branch rebase) was read through the GitHub contents
API. Only readable source, file inventories, and hashes are recorded here; no
QIDI release archive (`.rar`/`.zip`) is redistributed.

## Version → submodule map

| Release tag | Klipper (`PLUS4`) | Moonraker (`PLUS4`) | Box modules |
|---|---|---|---|
| `Plus4_V1.3.2` | `b90736975bae` | `f8fad844d74e` | none |
| `Plus4_V1.4.0` | `b90736975bae` | `f8fad844d74e` | none |
| `Plus4_V1.4.2` | `b90736975bae` | `f8fad844d74e` | none |
| `Plus4_V1.4.3` | `b90736975bae` | `f8fad844d74e` | none |
| `Plus4_V1.6.0` | `a363ac03e0b4` | `f8fad844d74e` | none |
| `Plus4_v1.7.0` | `1c4531a5c12c` | `6a6d22641320` | **`.py` source** |
| `Plus4_v1.7.1` | `4bb7c6337936` | `6a6d22641320` | **compiled `.so`** |

1.3.2 through 1.4.3 share one Klipper and one Moonraker commit — those four
releases differ only in `config/`, `UI/`, and `other/`, not in MCU/host source.
There are four distinct Klipper commits and two distinct Moonraker commits
across the whole range.

## Headline finding: the Box source was open, then closed

The QIDI Box Klipper modules first appear at **1.7.0 as plain Python source**
and are **compiled to Cython `.so` at 1.7.1**. This pinpoints exactly when QIDI
closed the Box source — the change community issue
[QIDITECH/klipper#10](https://github.com/QIDITECH/klipper/issues/10) asks about.

QIDI-specific / Box `klippy/extras` modules by version:

| Module | ≤1.6.0 | 1.7.0 | 1.7.1 |
|---|---|---|---|
| `qdprobe.py`, `chamber_fan.py` | `.py` | `.py` | `.py` |
| `aht20_f`, `box_detect`, `box_extras`, `box_rfid`, `box_stepper` | — | **`.py`** | **`.so`** |
| `buttons_irq.py`, `box_heater_fan.py` | — | — | `.py` (new) |

QIDI's authoritative 1.7.0 `.py` source for the five Box modules is preserved,
with provenance and licensing, under
[`qidi-klipper-1.7.0-box-source/`](qidi-klipper-1.7.0-box-source/).

## Config surface

`config/` stays minimal (only `gcode_macro.cfg` and `printer.cfg`) from 1.3.2
through **1.7.0**, then expands at **1.7.1** to the full Box set: `box.cfg`,
`box1.cfg`–`box4.cfg`, `drying.conf`, `officiall_filas_list.cfg`,
`user_multi_color.qdini`, plus `saved_variables.cfg.bak`. The Box product's
configuration surface therefore lands together with the compiled modules at
1.7.1, not at the 1.7.0 source preview.

Per-version file inventories with sizes are in
[`config-inventory.csv`](config-inventory.csv); the module inventory is in
[`klippy-extras-inventory.csv`](klippy-extras-inventory.csv).

## Licensing note

QIDI's `klipper` fork is GPLv3 (its `COPYING` is the GPLv3 text), so all Box
source above is GPLv3. The widely-cited "MIT" community snapshot of these
modules is byte-identical to QIDI's GPLv3 1.7.0 source and does not override
that license. See [`qidi-klipper-1.7.0-box-source/README.md`](qidi-klipper-1.7.0-box-source/README.md)
and the repository [NOTICE](../../NOTICE).

## Not covered here

The release **archives** (`PLUS4_V*.rar` / `.zip`, 11–16 MB each) are packaged
update bundles (deb, MCU, UI). They are not analyzed or redistributed here; the
per-version source above is the more useful and more inspectable artifact and
corresponds to the same tags. Cataloging the binary bundles is a possible
follow-up.
