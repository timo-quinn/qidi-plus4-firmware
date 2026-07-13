#!/usr/bin/env python3
"""Regenerate Cython 3.0.12 C templates from published QIDI Box source.

The C output is not QIDI's target source or a reproducible target binary. It
is a readable structural template whose ``__pyx_*`` names can be aligned with
the retained symbols and Ghidra output from the ARM64 firmware binaries.
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path


EXPECTED_CYTHON = "3.0.12"
MODULES = ("aht20_f", "box_detect", "box_extras", "box_rfid", "box_stepper")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()

    try:
        import Cython  # type: ignore
    except ImportError as exc:
        raise SystemExit(
            f"Cython {EXPECTED_CYTHON} is required. Install it in a temporary "
            f"environment with: {sys.executable} -m pip install "
            f"Cython=={EXPECTED_CYTHON}"
        ) from exc
    if Cython.__version__ != EXPECTED_CYTHON:
        raise SystemExit(
            f"Expected Cython {EXPECTED_CYTHON}, found {Cython.__version__}"
        )

    args.output.mkdir(parents=True, exist_ok=True)
    for module in MODULES:
        source = args.baseline / f"{module}.py"
        if not source.exists():
            raise SystemExit(f"Missing published baseline module: {source}")
        target = args.output / f"{module}.c"
        subprocess.run([
            sys.executable, "-m", "cython", "-3", "--output-file",
            str(target), str(source),
        ], check=True)
        print(f"Generated {target}")


if __name__ == "__main__":
    main()
