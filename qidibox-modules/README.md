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
stock-host target from open source.

## Which one — and is a binary even the right choice?

- **On stock QIDI firmware, installing Cartographer:** use `cp312-aarch64/`
  after moving `klippy-env` to Python 3.12.
- **On stock QIDI firmware, staying on Python 3.7:** you do not need these at
  all — QIDI's own modules already work. `cp37-aarch64/` is only an open,
  inspectable, rebuildable equivalent (for verification, or as a base to add
  the missing commands noted below).

The community's recommended fix is actually the **pure-Python `.py`** modules,
because plain Python is not locked to any interpreter version. These prebuilt
binaries are a convenience for anyone who wants a drop-in matching QIDI's
compiled layout, but they trade that flexibility away:

- Each `.so` loads **only** under the exact CPython minor version and CPU
  architecture it was built for (3.12 or 3.7; aarch64/arm64 only).
- Upstream Klipper does not load `.so` extras by default — that is a QIDI patch
  to `klippy.py`. The stock QIDI host has it; mainline Klipper does not, so on
  mainline use the pure-Python `.py` modules instead.

If either constraint applies, use the pure-Python source from the
[community archive](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/qidibox-on-orcaslicer/original_source).

## What these are (and are not)

- **Are:** a clean compile of QIDI's own Box source, using Cython 3.0.12 (the
  same Cython version stamped in QIDI's binaries). The source is GPLv3 — see
  Licensing below.
- **Are not:** QIDI's proprietary firmware binaries. Nothing from QIDI's
  compiled `.so` files is redistributed here; these are built from source.

Full provenance, per-target build environments, and input/output hashes are in
[`build-recipe/SOURCE-MANIFEST.txt`](build-recipe/SOURCE-MANIFEST.txt).

`buttons_irq` is not included; the community procedure only replaces it on
firmware 1.7.2. Build it from the same source with the recipe below if needed.

## Caveat: three commands are missing

The 1.7.0 source predates the shipped firmware by three `BoxExtras`
commands — `cmd_TRY_RESUME_PRINT`, `cmd_BOX_PRINT_START`, and
`cmd_INIT_MAPPING_VALUE` (see
[`../analysis/components/LINEAGE-ANALYSIS.md`](../analysis/components/LINEAGE-ANALYSIS.md)).
Neither build provides those commands. The community procedure restores the
equivalent print-start/resume behaviour with a `box_macros.cfg` macro set. Full
Box parity is not guaranteed.

## Install (stock QIDI host)

1. Stop Klipper.
2. Back up the existing modules in `~/klipper/klippy/extras/`.
3. Copy the `.so` files from the matching target directory into
   `~/klipper/klippy/extras/`, replacing the existing versions. Pick the
   directory that matches your `klippy-env` Python version.
4. Install the runtime dependency if missing:
   `~/klippy-env/bin/pip install pyudev`.
5. For the Cartographer case, also add the community `box_macros.cfg` and the
   Cartographer-compatible `probe.py` as described in the Plus4 Wiki.
6. Start Klipper and confirm the Box objects load without a
   "compile time Python version" error.

## Rebuild them yourself

Do not trust a binary you cannot reproduce. The parameterized recipe is in
[`build-recipe/build-any.sh`](build-recipe/build-any.sh); it fetches nothing and
expects the five `.py` files under `src/`. From a machine with Docker + qemu
(buildx) for arm64:

```bash
mkdir -p src && cd src
base=https://raw.githubusercontent.com/qidi-community/Plus4-Wiki/main/content/qidibox-on-orcaslicer/original_source
for m in aht20_f box_detect box_extras box_rfid box_stepper; do curl -fsSLO "$base/$m.py"; done
cd ..

# CPython 3.12 / aarch64
tar -cf - src build-recipe/build-any.sh | docker run --rm -i --platform linux/arm64 \
  quay.io/pypa/manylinux2014_aarch64 bash -c \
  'mkdir -p /work && cd /work && tar -xf - && bash build-recipe/build-any.sh /opt/python/cp312-cp312/bin/python'

# CPython 3.7 / aarch64 (stock-host match)
tar -cf - src build-recipe/build-any.sh | docker run --rm -i --platform linux/arm64 \
  python:3.7-buster bash -c \
  'mkdir -p /work && cd /work && tar -xf - && bash build-recipe/build-any.sh'
```

Compare the input hashes in `SOURCE-MANIFEST.txt`. A Cython build is not
bit-for-bit reproducible, so verify behaviour, not the artifact hash.

## License

**GPLv3.** These modules are compiled from QIDI's own Box source, which is part
of QIDI's GPLv3 fork of Klipper (https://github.com/QIDITECH/klipper, branch
`PLUS4`, as shipped at tag `Plus4_v1.7.0`). The [LICENSE](LICENSE) in this
directory is the GPLv3.

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
