# QIDI Box vs. Cartographer: the compiled-Python version conflict

A recurring community question is whether QIDI has released code to fix the
QIDI Box breaking when a Cartographer/Survey probe is installed, or whether
anyone has found a workaround. This note explains the root cause using this
repository's firmware analysis, records the current community solution, and
states what QIDI has and has not done.

## Symptom

After installing a Cartographer (Survey) probe on a printer that has a QIDI
Box, Klipper fails to start. The klippy log shows an import failure for a Box
module such as `box_extras`, with a Python-version message of the form:

```text
compile time Python version 3.7 of module 'box_extras' does not match runtime version 3.x
```

## Root cause

Two independent facts collide.

1. **QIDI's Box modules are compiled and version-locked.** Since firmware 1.7,
   the Box functionality ships as compiled Cython extension modules
   (`aht20_f`, `box_detect`, `box_extras`, `box_rfid`, `box_stepper`, and on
   1.7.2 also `buttons_irq`) rather than as plain `.py` files. This
   repository's analysis confirms they are **Cython 3.0.12** objects built
   against **CPython 3.7** — the binaries embed `/usr/include/python3.7m` and
   the Cython runtime guard string:

   ```text
   compile time Python version %d.%d of module '...' ... runtime version %d.%d
   ```

   A Cython `.so` only imports under the exact Python minor version it was
   built for. See [`../analysis/components/LINEAGE-ANALYSIS.md`](../analysis/components/LINEAGE-ANALYSIS.md).

2. **Cartographer needs a newer Python.** The Cartographer/Survey Klipper
   plugin requires Python 3.9+ (its numpy/scipy stack). QIDI stock is Python
   3.7 on Debian 10. Installing Cartographer therefore forces a rebuild of the
   Klipper virtual environment onto a newer interpreter (the community uses
   Python 3.12.3).

Once `klippy-env` is no longer Python 3.7, every compiled Box `.so` trips its
version guard on import and Klipper will not start. QIDI's modified `probe.py`
is separately incompatible with Cartographer.

## Has QIDI released a fix or the source?

No. The direct request to publish the Box modules as source —
[QIDITECH/klipper issue #10, "Why use compiled python for QidiBox"](https://github.com/QIDITECH/klipper/issues/10)
— is open and unanswered by QIDI. Earlier QIDI firmware exposed these modules
as Python source; since 1.7 QIDI ships them compiled and the sources were
removed. There is no official QIDI fix and no commitment to release one.

## The community solution

The [qidi-community Plus4 Wiki](https://github.com/qidi-community/Plus4-Wiki)
documents a working procedure. In outline:

1. Install precompiled **Python 3.12.3**, stop Klipper, delete and recreate the
   Klipper virtual environment (Klipper plugins must be reinstalled afterward).
2. **Delete the compiled Box `.so` modules and replace them with pure-Python
   `.py` equivalents.** Pure Python imports under any interpreter, so the
   version guard never fires. The replacements are a community-archived,
   MIT-licensed source snapshot (see below).
3. Replace QIDI's `probe.py` with the Cartographer-compatible community version.
4. Add a `box_macros.cfg` so the Box's print-start / purge / cleaning behavior,
   which used to live inside the `.so`, still runs.

The essential insight is that **the fix is pure-Python source, not a rebuilt
binary.** QIDI compiled these modules for obfuscation, not necessity — Klipper
loads `klippy/extras/*.py` natively. Recompiling them to a `.so` for a newer
Python would only re-introduce the same version lock and re-obfuscate readable
code, so the community deliberately does not do this.

## What this repository adds

This repo independently validates the fix and surfaces a caveat the bare
archive does not:

- **The archived Python source is a confirmed match.** The five modules
  published under the Plus4 Wiki (`.../qidibox-on-orcaslicer/original_source`,
  MIT, snapshot dated 29 July 2025) contain 116 public functions/methods, and
  every one has a corresponding Cython wrapper symbol in both the 1.7.3 and
  1.8.2 binaries. The swap-in source is a genuine lineage match, not a guess.
- **Three commands were added after that snapshot.** The shipped binaries
  expose three `BoxExtras` commands not present in the archived source:
  `cmd_TRY_RESUME_PRINT`, `cmd_BOX_PRINT_START`, and `cmd_INIT_MAPPING_VALUE`.
  This is precisely why the community procedure warns that some print-start and
  resume behavior changes, and why the `box_macros.cfg` step exists — those
  macros re-create the missing behavior. Full Box parity is not guaranteed, and
  the gap can shift with each QIDI firmware release.

For anyone who wants to understand or extend the pure-Python modules — or
reconstruct the three missing commands — the decompilation and lineage analysis
under [`../analysis/components/`](../analysis/components/) are a stronger
reference than the archive alone. Note that the reconstructed
`analysis/components/lineage-source/` files are analysis estimates marked "do
not install"; the installable source is the community archive, not this repo.

## Prebuilt modules in this repository

For convenience, [`../qidibox-modules/`](../qidibox-modules/) contains the Box
modules recompiled from the same MIT community source for two targets: CPython
3.12 / aarch64 (`cp312-aarch64/`, the Cartographer fix) and CPython 3.7 /
aarch64 (`cp37-aarch64/`, an open equivalent of the stock-host binaries). They
are a drop-in for anyone who wants to keep QIDI's compiled-module layout instead
of switching to plain `.py`.

They are only a convenience, and the pure-Python route is still the better
default: each prebuilt `.so` loads only under the exact CPython minor version
and architecture it was built for, and only where Klipper is patched to load
`.so` extras (the stock QIDI host is; mainline is not). Their build provenance,
hashes, caveats, and a reproducible recipe are documented in that directory.

## Bottom line

- QIDI has not released a fix or the source; the request sits open on QIDI's
  own tracker.
- A working community solution exists: move `klippy-env` to Python 3.12,
  replace the compiled Box `.so` modules with the community's pure-Python
  versions, swap `probe.py`, and restore Box behavior with macros.
- Prefer the **pure-Python source** — it is not locked to any interpreter
  version. Prebuilt CPython 3.12 / aarch64 binaries are available under
  [`../qidibox-modules/`](../qidibox-modules/) for those who specifically
  want a compiled drop-in, with the version/architecture limits noted there.

## References

- [QIDITECH/klipper issue #10](https://github.com/QIDITECH/klipper/issues/10)
- [Plus4 Wiki — Cartographer install guide](https://github.com/qidi-community/Plus4-Wiki/blob/main/content/bed-scanning-probes/cartographer3d/README.md)
- [Plus4 Wiki — customisable QidiBox firmware](https://github.com/qidi-community/Plus4-Wiki/blob/main/content/customisable_qidibox_firmware/README.md)
- [Plus4 Wiki — archived QidiBox Python source](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/qidibox-on-orcaslicer/original_source)
- [Cartographer 3D — troubleshooting](https://docs.cartographer3d.com/cartographer-probe/troubleshooting)
