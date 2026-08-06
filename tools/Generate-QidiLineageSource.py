#!/usr/bin/env python3
"""Build source-lineage estimates from QIDI's published Box Python source.

The generated files retain the published Box source as a readable GPLv3
baseline, annotate methods known to differ between 1.7.3 and 1.8.2, and add
non-runnable stubs for public binary APIs absent from the published snapshot.
The Plus4-Wiki snapshot's MIT label is retained as publication history but is
not the operative license; it is byte-identical to QIDI's GPLv3 Klipper source.
These files are analysis aids and must not be installed on a printer.
"""

from __future__ import annotations

import argparse
import ast
import csv
import re
import shutil
from dataclasses import dataclass
from pathlib import Path


MODULES = ("aht20_f", "box_detect", "box_extras", "box_rfid", "box_stepper")
VERSIONS = ("1.7.3", "1.8.2")
BASELINE_URL = (
    "https://github.com/qidi-community/Plus4-Wiki/tree/main/"
    "content/qidibox-on-orcaslicer/original_source"
)
VERSION_SENSITIVE = {
    "box_extras": {
        "BoxExtras._create_drying_state_setter",
        "BoxExtras.set_box_temp",
        "BoxExtras.cmd_INIT_MAPPING_VALUE",
        "BoxExtras.cmd_BOX_PRINT_START",
        "BoxExtras.update_e_endstop",
    },
    "box_stepper": {
        "BoxExtruderStepper.runout_button_callback",
        "BoxExtruderStepper.cmd_SLOT_UNLOAD",
        "BoxExtruderStepper.cmd_EXTRUDER_LOAD",
        "BoxExtruderStepper.slot_sync",
    },
}


@dataclass(frozen=True)
class Api:
    qualified_name: str
    signature: str
    line: int


def source_apis(path: Path) -> tuple[dict[str, Api], set[str]]:
    tree = ast.parse(path.read_text(encoding="utf-8-sig"), filename=str(path))
    found: dict[str, Api] = {}
    classes: set[str] = set()
    for node in tree.body:
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            found[node.name] = Api(node.name, signature(node), node.lineno)
        elif isinstance(node, ast.ClassDef):
            classes.add(node.name)
            for child in node.body:
                if isinstance(child, (ast.FunctionDef, ast.AsyncFunctionDef)):
                    name = f"{node.name}.{child.name}"
                    found[name] = Api(name, signature(child), child.lineno)
    return found, classes


def signature(node: ast.FunctionDef | ast.AsyncFunctionDef) -> str:
    args = node.args
    values = [arg.arg for arg in args.posonlyargs]
    if args.posonlyargs:
        values.append("/")
    values.extend(arg.arg for arg in args.args)
    if args.vararg:
        values.append("*" + args.vararg.arg)
    elif args.kwonlyargs:
        values.append("*")
    values.extend(arg.arg for arg in args.kwonlyargs)
    if args.kwarg:
        values.append("**" + args.kwarg.arg)
    prefix = "async def" if isinstance(node, ast.AsyncFunctionDef) else "def"
    return f"{prefix} {node.name}({', '.join(values)})"


def binary_apis(symbols: Path, module: str, classes: set[str]) -> set[str]:
    marker = f"_{len(module)}{module}_"
    found: set[str] = set()
    for line in symbols.read_text(encoding="utf-8", errors="replace").splitlines():
        match = re.search(r"(__pyx_pw_\S+)$", line)
        if not match or marker not in match.group(1):
            continue
        tail = match.group(1).split(marker, 1)[1]
        for class_name in sorted(classes, key=len, reverse=True):
            class_marker = f"{len(class_name)}{class_name}_"
            if tail.startswith(class_marker):
                method = re.sub(r"^\d+", "", tail[len(class_marker):])
                found.add(f"{class_name}.{method}")
                break
        else:
            found.add(re.sub(r"^\d+", "", tail))
    return found


def outer_binary_additions(names: set[str]) -> list[str]:
    additions = []
    for name in sorted(names):
        method = name.rsplit(".", 1)[-1]
        if "_1lambda" in method or method.endswith("_lambda"):
            continue
        if "_1set_drying_state" in method:
            continue
        additions.append(name)
    return additions


def decompiled_line(reference: Path, version: str, module: str, method: str) -> int | None:
    path = reference / version / "klipper" / module / "decompiled.c"
    if not path.exists():
        return None
    for number, line in enumerate(path.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
        if line.startswith(" * Symbol:") and method in line:
            return number
    return None


def annotated_source(
    path: Path,
    version: str,
    module: str,
    additions: list[str],
    reference: Path,
    revision: str,
) -> str:
    original = path.read_text(encoding="utf-8-sig")
    lines = original.splitlines()
    apis, _ = source_apis(path)
    inserts: dict[int, list[str]] = {}

    for name in VERSION_SENSITIVE.get(module, set()):
        api = apis.get(name)
        if api:
            indent = re.match(r"\s*", lines[api.line - 1]).group(0)
            inserts.setdefault(api.line - 1, []).extend([
                f"{indent}# LINEAGE WARNING: this method changes between QIDI 1.7.3 and",
                f"{indent}# 1.8.2; the published body below is a baseline, not a recovered {version} body.",
            ])

    if additions:
        tree = ast.parse(original)
        class_nodes = {node.name: node for node in tree.body if isinstance(node, ast.ClassDef)}
        grouped: dict[str, list[str]] = {}
        for name in additions:
            class_name, method = name.split(".", 1)
            grouped.setdefault(class_name, []).append(method)
        for class_name, methods in grouped.items():
            node = class_nodes[class_name]
            block = ["", "    # Binary-only public APIs absent from the published baseline."]
            for method in methods:
                evidence = decompiled_line(reference, version, module, method)
                location = f"decompiled.c:{evidence}" if evidence else "symbols.txt"
                block.extend([
                    f"    def {method}(self, gcmd):",
                    f"        \"\"\"Estimated signature; binary evidence: {location}.\"\"\"",
                    "        raise NotImplementedError('Binary-only behavior requires manual reconstruction')",
                    "",
                ])
            inserts.setdefault(node.end_lineno, []).extend(block)

    rendered: list[str] = []
    banner = [
        '"""SOURCE-LINEAGE ESTIMATE -- DO NOT INSTALL ON A PRINTER.',
        "",
        f"Published Box-source snapshot (GPLv3 origin): {BASELINE_URL}",
        f"Baseline revision: {revision}",
        f"Estimated target firmware: {version}",
        "",
        "All published public APIs were observed in this target's Cython symbols.",
        "Unannotated bodies are readable lineage candidates, not proof of byte-for-byte",
        "or behavior-for-behavior identity. See LINEAGE-ANALYSIS.md and the binary",
        "evidence before implementing or testing hardware behavior.",
        '"""',
        "",
    ]
    rendered.extend(banner)
    for index, line in enumerate(lines):
        rendered.extend(inserts.get(index, []))
        rendered.append(line)
    rendered.extend(inserts.get(len(lines), []))
    return "\n".join(rendered).rstrip() + "\n"


def find_license(start: Path) -> Path:
    for directory in (start, *start.parents):
        candidate = directory / "LICENSE"
        if candidate.exists():
            return candidate
    raise FileNotFoundError("Could not find the published repository LICENSE")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baseline", required=True, type=Path)
    parser.add_argument("--reference-root", type=Path,
                        default=Path("analysis/components"))
    parser.add_argument("--output", type=Path,
                        default=Path("analysis/components/lineage-source"))
    parser.add_argument("--source-revision", default="unknown")
    args = parser.parse_args()

    args.output.mkdir(parents=True, exist_ok=True)
    # Preserve the license text distributed with the selected snapshot as
    # publication evidence. NOTICE and the generated README explain why the
    # snapshot remains governed by its QIDI/Klipper GPLv3 origin.
    shutil.copyfile(find_license(args.baseline), args.output / "LICENSE.published-baseline")
    rows: list[dict[str, object]] = []

    for module in MODULES:
        source_path = args.baseline / f"{module}.py"
        published, classes = source_apis(source_path)
        for version in VERSIONS:
            symbols = args.reference_root / version / "klipper" / module / "symbols.txt"
            binary = binary_apis(symbols, module, classes)
            for name in sorted(set(published) | binary):
                if name in published and name in binary:
                    state = "published-and-binary"
                elif name in binary:
                    state = "binary-only"
                else:
                    state = "published-only"
                rows.append({
                    "firmware": version,
                    "module": module,
                    "api": name,
                    "state": state,
                    "published_signature": published[name].signature if name in published else "",
                    "published_line": published[name].line if name in published else "",
                    "version_sensitive": name in VERSION_SENSITIVE.get(module, set()),
                })

            additions = outer_binary_additions(binary - set(published))
            target = args.output / version / "klipper" / f"{module}.py"
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_text(annotated_source(
                source_path, version, module, additions, args.reference_root,
                args.source_revision,
            ), encoding="utf-8", newline="\n")

    with (args.output / "api-comparison.csv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)

    (args.output / "README.md").write_text(
        "# Generated source-lineage estimates\n\n"
        "These files combine the published Box source (GPLv3 — the Plus4-Wiki "
        "snapshot's MIT label does not govern it; see `../LINEAGE-ANALYSIS.md`) "
        "with API evidence from QIDI firmware binaries. They are analysis aids, "
        "not recovered source or deployable printer software. See "
        "`../LINEAGE-ANALYSIS.md` for confidence levels, licensing, and "
        "methodology.\n\n"
        f"Published baseline: {BASELINE_URL}\n\n"
        f"Baseline revision: `{args.source_revision}`\n",
        encoding="utf-8",
        newline="\n",
    )

    print(f"Generated source-lineage estimates in {args.output}")


if __name__ == "__main__":
    main()
