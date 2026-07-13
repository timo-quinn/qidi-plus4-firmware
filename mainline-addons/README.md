# QIDI Plus4 mainline add-ons

This directory scaffolds optional, dependency-light additions for a Plus4 after
the base mainline migration is complete. Nothing here is enabled automatically.
The files deliberately avoid MCU pin definitions: those belong in the reviewed
printer configuration for the exact controller revision.

## Available add-ons

| Add-on | Purpose | External dependency |
|---|---|---|
| `diagnostics` | Report homing, MCU, heater and fan state | None |
| `adaptive-mesh` | Wrap Klipper's native adaptive bed mesh | Klipper 0.13+ |
| `chamber-control` | Bounded control of an existing `chamber` heater | None |
| `purge-park` | Safe configurable park point for purge/wipe work | None |
| `cutter-contract` | Stable hook for a future tested cutter sequence | None |
| `print-end-safety` | Common shutdown hook without replacing `END_PRINT` | None |

Optional integration templates are under `integrations/`:

- `beacon/` follows current Beacon installation and contact-homing semantics;
- `happy-hare/` defines where Plus4 cutter/purge behavior can attach without
  introducing a second material state machine.

These are scaffolds, not tested machine profiles. In particular, the cutter
implementation intentionally raises an error until its coordinates and sequence
have been verified on migrated hardware.

## Stage files on a printer

Run the installer on the migrated host as the normal Klipper user:

```bash
python3 install.py \
  --config-dir "$HOME/printer_data/config" \
  --addon diagnostics \
  --addon adaptive-mesh
```

It copies selected files to `plus4-addons/` and prints the include statements.
It does not edit `printer.cfg` or restart Klipper. Review the staged files, add
only the desired includes, then run a configuration restart.

Use `--list` to show choices and `--force` only when intentionally replacing a
previous staged copy.

## Recommended order

1. `diagnostics`
2. `adaptive-mesh` after object labels and the full mesh are proven
3. `chamber-control` after independent chamber thermal commissioning
4. `purge-park` after coordinates are measured at reduced speed
5. `cutter-contract` only after a real cutter sequence replaces the refusal
6. `print-end-safety` as a call from the existing end macro
7. Beacon or Happy Hare integrations separately

Mainline Klipper already provides adaptive meshing and object exclusion. Do not
install legacy KAMP solely for adaptive probing. Object definitions must still
be produced by the slicer or Moonraker preprocessing.

## Design rules

- All public macros use the `PLUS4_` prefix.
- No add-on overrides `PRINT_START`, `END_PRINT`, `PAUSE`, `RESUME`, `M106`,
  `M141`, or tool-change commands.
- No heater, fan, motor or output pin is declared here.
- Hardware actions validate prerequisites and conservative bounds at runtime.
- QIDI Box support remains experimental and is not enabled by this bundle.

## Upstream references

- [Klipper adaptive bed mesh](https://www.klipper3d.org/Bed_Mesh.html#adaptive-meshes)
- [Klipper exclude-object contract](https://www.klipper3d.org/Exclude_Object.html)
- [Beacon quick start](https://docs.beacon3d.com/quickstart/)
- [Beacon contact homing](https://docs.beacon3d.com/contact/)
- [Happy Hare installation](https://github.com/moggieuk/Happy-Hare/wiki/Installation)

