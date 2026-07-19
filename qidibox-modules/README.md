# QIDI Box Klipper modules, rebuilt from QIDI's GPLv3 source

Prebuilt QIDI Box Klipper extension modules compiled from QIDI's own Box source
(GPLv3; see Licensing below), for two Python targets:

| Directory | Target | Use for |
|---|---|---|
| [`cp312-aarch64/`](cp312-aarch64/) | CPython 3.12, aarch64 | Keeping the Box working after `klippy-env` is moved to Python 3.12 for a Cartographer/Survey probe |
| [`cp37-aarch64/`](cp37-aarch64/) | CPython 3.7, aarch64 (glibc 2.28) | An open, rebuildable equivalent of the modules QIDI already ships on the stock Debian 10 host |

Read [`../docs/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md`](../docs/BOX-CARTOGRAPHER-PYTHON-CONFLICT.md)
first for the full background. In short: QIDI ships these modules as compiled
Cython `.so` files locked to **Python 3.7**; installing Cartographer forces a
Python 3.12 environment; the 3.7 binaries then refuse to load. The `cp312`
build carries the same code compiled for 3.12; the `cp37` build reproduces the
stock-host target from open source. Both builds include the compatibility fix
described below.

## Which one — and is a binary even the right choice?

- **On stock QIDI firmware, installing Cartographer:** use `cp312-aarch64/`
  after moving `klippy-env` to Python 3.12.
- **On stock QIDI firmware, staying on Python 3.7:** you do not need these at
  all unless the log repeatedly reports `ToolChange` has no attribute
  `is_tool_change`. `cp37-aarch64/` is an open, inspectable replacement that
  also fixes that 1.8.2 compatibility error.

The community's recommended fix is actually the **pure-Python `.py`** modules,
because plain Python is not locked to any interpreter version. These prebuilt
binaries are a convenience for anyone who wants a drop-in matching QIDI's
compiled layout, but they trade that flexibility away:

- Each `.so` loads **only** under the exact CPython minor version and CPU
  architecture it was built for (3.12 or 3.7; aarch64/arm64 only).
- Upstream Klipper does not load `.so` extras by default — that is a QIDI patch
  to `klippy.py`. The stock QIDI host has it; mainline Klipper does not, so on
  mainline use the pure-Python `.py` modules instead.

If either constraint applies, use the preserved pure-Python source in this
repository and apply
[`build-recipe/apply-compatibility-patches.py`](build-recipe/apply-compatibility-patches.py)
before installing it.

## What these are (and are not)

- **Are:** a compile of QIDI's own Box source plus the documented
  `is_tool_change` compatibility patch, using Cython 3.0.12 (the same Cython
  version stamped in QIDI's binaries). The source is GPLv3 — see Licensing
  below.
- **Are not:** QIDI's proprietary firmware binaries. Nothing from QIDI's
  compiled `.so` files is redistributed here; these are built from source.

Full provenance, per-target build environments, and input/output hashes are in
[`build-recipe/SOURCE-MANIFEST.txt`](build-recipe/SOURCE-MANIFEST.txt).

QIDI's 1.8.2 `multi_color_controller` reads
`box_extras.tool_change.is_tool_change`, but QIDI's published 1.7.0
`ToolChange` class never creates that attribute. The build-time patch initializes
it and keeps it synchronized in `TOOL_CHANGE_START` and `TOOL_CHANGE_END`.
This removes the repeated adapter-status exception without changing the saved
Klipper variable used by the macros.

`buttons_irq` is not included; the community procedure only replaces it on
firmware 1.7.2. Build it from the same source with the recipe below if needed.

## Caveat: three commands are missing (and the macros that cover them)

The 1.7.0 source predates the shipped firmware by three `BoxExtras`
commands — `cmd_TRY_RESUME_PRINT`, `cmd_BOX_PRINT_START`, and
`cmd_INIT_MAPPING_VALUE` (see
[`../analysis/components/LINEAGE-ANALYSIS.md`](../analysis/components/LINEAGE-ANALYSIS.md)).
Neither build provides those commands. The equivalent print-start / resume /
filament-change behaviour is restored by the companion macro set
[`box_macros.cfg`](box_macros.cfg), included here. Full Box parity is not
guaranteed.

### `box_macros.cfg` (companion, not built by us)

`box_macros.cfg` is a Klipper macro configuration (14 `[gcode_macro]` blocks:
`TRY_RESUME_PRINT`, `BOX_PRINT_START`, `BOX_CHANGE_FILAMENT`, flush/cut/reload,
etc.) that re-creates the Box behaviour the compiled-only commands provided.

- Source: qidi-community Plus4 Wiki,
  `content/customisable_qidibox_firmware/box_macros.cfg`
  (<https://github.com/qidi-community/Plus4-Wiki>), used as the base.
- Upstream SHA-256: `6f83ac0a5ef3c2538dce8ba0662a100cf4f01902ea8d3b40940487aab7e54b88`.
- Local fixes remove a stray Jinja brace and preserve relative-extrusion state
  in the standalone reload, extrusion, and flush macros.
- It is community-authored configuration, not part of the compiled modules and
  not produced by the build recipe. Attribution and licensing follow the Plus4
  Wiki; see [`LICENSE.box_macros`](LICENSE.box_macros) and the repository
  [NOTICE](../NOTICE).

## Install (stock QIDI host)

1. Stop Klipper.
2. Back up the existing modules in `~/klipper/klippy/extras/`.
3. Copy the `.so` files from the matching target directory into
   `~/klipper/klippy/extras/`, replacing the existing versions. Pick the
   directory that matches your `klippy-env` Python version.
4. Install the runtime dependency if missing:
   `~/klippy-env/bin/pip install pyudev`.
5. Include the companion [`box_macros.cfg`](box_macros.cfg) from this directory
   in your printer config to restore the Box macro behaviour. For the
   Cartographer case, also apply the Cartographer-compatible `probe.py` as
   described in the Plus4 Wiki.
6. Start Klipper and confirm the Box objects load without a
   "compile time Python version" error.

## Rebuild them yourself

Do not trust a binary you cannot reproduce. The parameterized recipe is in
[`build-recipe/build-any.sh`](build-recipe/build-any.sh); it fetches nothing,
verifies and patches the preserved upstream `box_extras.py`, and expects the
five `.py` files under `src/`. From this directory on a machine with Docker +
qemu (buildx) for arm64:

```bash
mkdir -p src out/cp312-aarch64 out/cp37-aarch64
cp ../analysis/github-releases/qidi-klipper-1.7.0-box-source/*.py src/

# CPython 3.12 / aarch64
tar -cf - src build-recipe | docker run --rm -i --platform linux/arm64 \
  -v "$PWD/out/cp312-aarch64:/work/out" \
  quay.io/pypa/manylinux2014_aarch64@sha256:a89d9ab0b9452ab8f748153a3d49b3a12a36638ceee285d5b468c6127024018b bash -c \
  'mkdir -p /work && cd /work && tar -xf - && sed -i "s/\r$//" build-recipe/*.sh && bash build-recipe/build-any.sh /opt/python/cp312-cp312/bin/python'

# CPython 3.7 / aarch64 (stock-host match)
tar -cf - src build-recipe | docker run --rm -i --platform linux/arm64 \
  -v "$PWD/out/cp37-aarch64:/work/out" \
  python:3.7-buster bash -c \
  'mkdir -p /work && cd /work && tar -xf - && sed -i "s/\r$//" build-recipe/*.sh && bash build-recipe/build-any.sh'
```

The bind mounts retain the outputs on the host. Compare them with the artifact
hashes in `SOURCE-MANIFEST.txt`. A Cython build is not bit-for-bit reproducible
across toolchain changes, so also verify behaviour.

Run the distribution checks with:

```bash
python -m pip install -r ../requirements-test.txt
cd ..
python -m pytest
```

## License

**GPLv3.** These modules are compiled from QIDI's own Box source, which is part
of QIDI's GPLv3 fork of Klipper (https://github.com/QIDITECH/klipper, branch
`PLUS4`, as shipped at tag `Plus4_v1.7.0`). The [LICENSE](LICENSE) in this
directory is the GPLv3. The compatibility patch and resulting binaries remain
GPLv3.

The build source is byte-identical to the community snapshot often cited as
"MIT" (Copyright (c) 2024 stew675); because that snapshot is QIDI's GPLv3 code,
the MIT label does not govern it — GPLv3 code cannot be relicensed to MIT by a
third party. The authoritative GPLv3 source, its provenance, and the identity
proof are preserved at
[`../analysis/github-releases/qidi-klipper-1.7.0-box-source/`](../analysis/github-releases/qidi-klipper-1.7.0-box-source/).

Because these are GPLv3 binaries, the corresponding source must be available to
recipients: it is, both upstream (QIDI's fork) and in this repository at the
path above, and the exact build recipe is in `build-recipe/`. See the
repository [NOTICE](../NOTICE) for how this fits the rest of the project.
