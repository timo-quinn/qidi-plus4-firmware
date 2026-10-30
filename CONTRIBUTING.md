# Contributing

[Repository home](README.md) · [Documentation](docs/README.md)

## Choose the right location

| Area | Editing rule |
| --- | --- |
| [docs/](docs/README.md) | Maintained findings and guides. Put new guides in the relevant topic directory and link them from that directory's README. |
| [docs/history/](docs/history/README.md) | Dated printer reviews and implementation records. Keep the date and scope explicit. |
| [tools/](tools/README.md) | Maintained utilities; migration CLI compatibility is part of the printerlab contract. |
| [firmware-configs/](firmware-configs/README.md) | Authoritative MCU Kconfig fragments, distinct from runtime printer configurations. |
| [mainline-configs/](mainline-configs/README.md) | Transitional bundled runtime profiles. New live/profile work belongs in `qidi-plus4-configs`; use `render-config --profile-dir` to consume it. |
| [mainline-addons/](mainline-addons/README.md) | Optional runtime templates, never per-printer saved state. |
| [qidibox-modules/](qidibox-modules/README.md) | Maintained compatibility overlays, recipes, and provenance; compiled `.so` files are derived artifacts. |
| [plr-hardening/](plr-hardening/README.md) | Stock power-loss recovery implementation and installation tooling. |
| [screen-bridge/](screen-bridge/README.md) | Independent touchscreen bridge code and protocol profiles. |
| [analysis/](analysis/README.md) | Generated evidence: regenerate decompilation, disassembly, inventories, and reconstructed outlines with the documented tools. |
| [Preserved QIDI Box source](analysis/github-releases/qidi-klipper-1.7.0-box-source/README.md) | Immutable upstream GPLv3 snapshot used for provenance and rebuilds. |
| [data/](data/README.md) | Private local inputs; printer backups are ignored by Git. |
| [artifacts/](artifacts/README.md) | Local generated output, downloads, and live copies; never configuration authority. |

Keep runnable tools and component directories at their existing paths: the
migration commands, tests, and external printerlab integration use those paths.
When moving a guide, update links from the other guides, component READMEs, and
CLI messages. Commands in guides are run from the repository root unless stated
otherwise.

## Local checks

Use Python 3.10 or later for development. Install the test dependencies in a
virtual environment from the repository root:

```console
python -m venv .venv
```

Activate it with `.venv\Scripts\Activate.ps1` in PowerShell or
`source .venv/bin/activate` in a POSIX shell, then run:

```console
python -m pip install -r requirements-test.txt
python -m pytest
python -m ruff check .
```

`pytest.ini` collects tests from the root tests, screen bridge, Box modules,
mainline add-ons, and migration tools. Some host-specific checks require a
Linux/WSL environment; follow the component's README for its build and runtime
requirements. Printer-side code must retain the Python compatibility documented
by its component, including the stock Python 3.7 runtime where applicable.

For documentation changes, check relative links from each file's new location,
including links in component READMEs. Keep the topic indexes complete.

## Publication and licensing

Do not commit private backups, credentials, databases, SSH keys, device
identities, unsanitized captures, or generated live configurations. Keep inputs
under `data/printer-backups/` and local output under `artifacts/`.

Check [NOTICE](NOTICE) before publishing derived material. Original project
work, preserved upstream source, and derived analysis have different licensing
and attribution requirements.
