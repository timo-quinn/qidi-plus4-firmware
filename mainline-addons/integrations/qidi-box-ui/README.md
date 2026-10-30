# QIDI Box control panel for stock Mainsail and Fluidd

An open replacement for the "Control Box" panel that QIDI ships inside its own
Fluidd fork, built entirely from Klipper macro prompts so that no front-end has
to be forked, patched, or replaced.

QIDI's panel is a Vue component compiled into their Fluidd bundle. Installing
upstream Fluidd or Mainsail after a mainline migration therefore loses the Box
UI even when the Box itself still works. This file restores the same actions on
an unmodified front-end.

## What it provides

`PLUS4_BOX` opens a dialog with one button per lane, arranged in rows of four
and labelled the way QIDI labels them (`1A`–`1D`, `2A`–`2D`, …), plus an entry
for the external spool that QIDI calls the "Rack". Selecting a lane opens its
action dialog:

| Action | Shown when |
|---|---|
| Load | the lane holds filament and is not already loaded |
| Unload | the lane is the one currently fed to the toolhead |
| Eject | the lane holds filament |
| Read RFID tag | any real lane (not the external spool) |

`PLUS4_BOX_STATUS` prints the same state to the console without opening a
dialog, for diagnostics and for front-ends without prompt support.

Actions are refused during a print unless `FORCE=1` is passed, because the load
and unload sequences move the toolhead.

## Requirements

- Klipper's `[respond]` module enabled.
- Mainsail 2.9.0 or newer, or a Fluidd release with prompt-dialog support.
  Both implement the same `action:prompt_*` protocol.
- A working QIDI Box backend publishing `box_extras`, `box_stepper slotN` and
  `save_variables` — currently the recompiled modules under
  [`../../../qidibox-modules/`](../../../qidibox-modules/).

## Install

```bash
cp ams-panel.cfg ~/printer_data/config/plus4-addons/
```

Add the include to `printer.cfg`, below the Box configuration:

```ini
[include plus4-addons/ams-panel.cfg]
```

Then run a configuration restart. `PLUS4_BOX` appears in the macro list; the
`_`-prefixed macros are internal and stay hidden.

## Optional: readable material names

QIDI stores each slot's vendor, material and colour as integer indices into
`officiall_filas_list.cfg`. Klipper macros cannot read that file, so the panel
shows lanes as `ready`/`loaded`/`empty` by default. Supply the indices you
actually use to get material names in the button labels, by editing
`variable_material_names` in `_PLUS4_BOX_CONFIG`:

```ini
variable_material_names: {1: 'PLA', 7: 'PLA Silk', 12: 'PETG'}
```

Resolving those names automatically requires reading the file over Moonraker's
file API, which is a front-end capability rather than a macro one.

## Deliberate limitations

Macro prompts are modal dialogs. They give a faithful **action** surface but
not an ambient one:

- no always-visible spool grid — the panel is opened on demand;
- no colour swatches, because prompt buttons only accept the five named colours
  `primary`, `secondary`, `info`, `warning`, `error`;
- vendor and colour selection are not exposed, since a dropdown of the full
  filament database does not fit the prompt protocol.

Those three gaps are what a standalone web panel on Moonraker's WebSocket API
would close. This file is the no-install, no-fork tier.

## Retargeting the backend

Everything backend-specific is confined to two places:

1. `_PLUS4_BOX_ACTION`, which maps the verbs `load`, `unload`, `eject` and
   `rfid` onto `E_LOAD`, `E_UNLOAD`, `E_BOX` and `RFID_READ`;
2. the `{% set %}` blocks at the top of each dialog macro, which read
   `runout_button`, `b_endstop_state`, `box_button_state`, `humidity` and the
   `save_variables` slot metadata.

The dialog macros never name a vendor object anywhere else, so pointing the
panel at an open Box reimplementation — or at Happy Hare's `mmu` object per
[HAPPY-HARE-INTEGRATION.md](../../../docs/integrations/HAPPY-HARE-INTEGRATION.md) — means
editing those two places only.

## Backend semantics

Recovered from QIDI's own front-end bundle and verified against the compiled
module strings under [`analysis/components/`](../../../analysis/components/):

| Meaning | Source |
|---|---|
| Lane holds filament | `[box_stepper slotN].runout_button == 0` |
| Shared path occupied | `[box_extras].b_endstop_state == 0` |
| Extruder path occupied | `[box_extras].e_endstop_state == 0` |
| Box busy with an operation | `[box_extras].box_button_state != 0` |
| Lane fed to the toolhead | `save_variables.last_load_slot == "slotN"` |
| Chamber humidity | `[aht20_f heater_boxN].humidity` |
| Number of Boxes | `save_variables.box_count` |
| Slot metadata | `save_variables.vendor_slotN`, `filament_slotN`, `color_slotN` |

Slot 16 is the external spool path, which is why it is always actionable and
has no RFID reader.

## Tests

The dialog logic is verified off the printer by rendering the templates against
synthetic printer state:

```bash
python -m pytest mainline-addons/tests/test_ams_panel.py
```
