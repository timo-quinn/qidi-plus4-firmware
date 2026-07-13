#!/usr/bin/env python3
"""Generate readable API-oriented Python estimates from Cython ELF symbols.

This does not recover original source. It turns retained Cython wrapper names
and Ghidra evidence into valid, non-runnable Python skeletons that are easier to
navigate during interoperability analysis.
"""

from __future__ import annotations

import argparse
import keyword
import re
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path


WRAPPER_PREFIX = "__pyx_pw_"
IGNORE_IDENTIFIERS = {
    "args", "kwds", "self", "result", "retval", "values", "PyObject",
    "PyErr", "PyTuple", "PyUnicode", "PyLong", "PyDict", "PyList",
    "Py_None", "Py_True", "Py_False", "mstate_global_static",
}


@dataclass(frozen=True)
class RecoveredMethod:
    symbol: str
    class_name: str | None
    method_name: str
    line: int | None
    identifiers: tuple[str, ...]
    is_async: bool


def decode_wrapper(symbol: str) -> tuple[list[str], str] | None:
    if not symbol.startswith(WRAPPER_PREFIX):
        return None
    remaining = symbol[len(WRAPPER_PREFIX):]
    components: list[str] = []

    while remaining:
        if remaining.startswith("_"):
            candidate = remaining[1:]
            separator = 1
        else:
            candidate = remaining
            separator = 0
        length_match = re.match(r"(\d+)", candidate)
        if not length_match:
            break
        digits = length_match.group(1)

        # Once a class component has been decoded, the next integer is the
        # Cython method-table ordinal. It is not another string length. This
        # matters for names such as ``18cmd_ENABLE_BOX_DRY_lambda``, where the
        # ordinal accidentally equals the length of the first name segment.
        if components and components[-1][:1].isupper():
            return components, candidate[len(digits):]

        length = int(digits)
        start = len(digits)
        value = candidate[start:start + length]
        after = candidate[start + length:]
        if len(value) != length:
            # A non-matching length marks the final method-table ordinal for
            # a module-level function.
            return components, candidate[start:]

        # Encoded package/module/class components are followed by another
        # underscore-delimited encoded field. The final numeric field is a
        # Cython method-table index, not a string length.
        if after.startswith("_"):
            components.append(value)
            remaining = after
            continue

        remaining = remaining[separator:]
        index_match = re.match(r"_?(\d+)", remaining)
        if not index_match:
            return None
        method_name = remaining[index_match.end():]
        return components, method_name
    return None


def safe_identifier(value: str, fallback: str) -> str:
    value = re.sub(r"\W", "_", value)
    if not value or value[0].isdigit() or keyword.iskeyword(value):
        value = fallback
    return value


def decompiled_chunks(path: Path) -> dict[str, tuple[int, str]]:
    text = path.read_text(encoding="utf-8", errors="replace")
    starts = list(re.finditer(r"^ \* Symbol:  (.+)$", text, re.MULTILINE))
    chunks: dict[str, tuple[int, str]] = {}
    for index, match in enumerate(starts):
        end = starts[index + 1].start() if index + 1 < len(starts) else len(text)
        line = text.count("\n", 0, match.start()) + 1
        chunks[match.group(1)] = (line, text[match.start():end])
    return chunks


def evidence_identifiers(chunk: str) -> tuple[str, ...]:
    found: set[str] = set()
    for value in re.findall(r"__pyx_(?:n_s|n_u|k|kp_[su]|v)_([A-Za-z][A-Za-z0-9_]*)", chunk):
        if value in IGNORE_IDENTIFIERS or value.startswith("Py"):
            continue
        if "security" in value.lower() or "secret" in value.lower():
            found.add("REDACTED_SECURITY_CONSTANT")
            continue
        if len(value) < 3:
            continue
        found.add(value)
    return tuple(sorted(found, key=str.casefold)[:32])


def recover_methods(component_dir: Path, module_name: str) -> list[RecoveredMethod]:
    chunks = decompiled_chunks(component_dir / "decompiled.c")
    symbols: set[str] = set()
    for line in (component_dir / "symbols.txt").read_text(errors="replace").splitlines():
        parts = line.split()
        if parts and parts[-1].startswith(WRAPPER_PREFIX):
            symbols.add(parts[-1])

    methods: list[RecoveredMethod] = []
    for symbol in sorted(symbols):
        decoded = decode_wrapper(symbol)
        if decoded is None:
            continue
        components, method_name = decoded
        method_name = safe_identifier(method_name, "unknown_method")

        class_name: str | None = None
        if module_name in components:
            module_index = components.index(module_name)
            if module_index + 1 < len(components):
                class_name = safe_identifier(components[module_index + 1], "UnknownClass")
                nested = components[module_index + 2:]
                if nested:
                    method_name = "__".join([*nested, method_name])
                    method_name = safe_identifier(method_name, "unknown_nested_method")

        line, chunk = chunks.get(symbol, (None, ""))
        methods.append(RecoveredMethod(
            symbol=symbol,
            class_name=class_name,
            method_name=method_name,
            line=line,
            identifiers=evidence_identifiers(chunk),
            is_async="__Pyx_Coroutine" in chunk or "__pyx_Coroutine" in chunk,
        ))
    return methods


def signature(method: RecoveredMethod) -> str:
    name = method.method_name
    if method.class_name is None:
        if name.startswith("load_"):
            return "config"
        return "*args, **kwargs"
    if name.startswith("cmd_"):
        return "self, gcmd"
    if name == "get_status":
        return "self, eventtime=None"
    return "self, *args, **kwargs"


def render_module(
    version: str,
    subsystem: str,
    module_name: str,
    component_dir: Path,
    methods: list[RecoveredMethod],
) -> str:
    module_functions = [method for method in methods if method.class_name is None]
    classes: dict[str, list[RecoveredMethod]] = defaultdict(list)
    for method in methods:
        if method.class_name is not None:
            classes[method.class_name].append(method)

    lines = [
        '"""ESTIMATED reverse-engineered source outline.',
        "",
        "This is not QIDI's original source and is intentionally non-runnable.",
        "It reconstructs API shape from Cython symbols and Ghidra evidence.",
        f"Firmware: {version}; subsystem: {subsystem}; module: {module_name}.",
        '"""',
        "",
    ]

    def add_method(method: RecoveredMethod, indent: str = "") -> None:
        async_prefix = "async " if method.is_async else ""
        lines.append(f"{indent}{async_prefix}def {method.method_name}({signature(method)}):")
        lines.append(f'{indent}    """Estimated from `{method.symbol}`.')
        if method.line is not None:
            lines.append(f"{indent}    Ghidra reference: decompiled.c:{method.line}.")
        if method.identifiers:
            lines.append(f"{indent}    Evidence identifiers: {', '.join(method.identifiers)}.")
        lines.append(f'{indent}    """')
        lines.append(f"{indent}    raise NotImplementedError('Reverse-engineered outline only')")
        lines.append("")

    for method in sorted(module_functions, key=lambda item: item.method_name.casefold()):
        add_method(method)

    for class_name in sorted(classes, key=str.casefold):
        lines.append(f"class {class_name}:")
        class_methods = sorted(classes[class_name], key=lambda item: item.method_name.casefold())
        if not class_methods:
            lines.append("    pass")
            lines.append("")
            continue
        for method in class_methods:
            add_method(method, "    ")

    if not methods:
        lines.extend(["# No Cython wrapper symbols were recovered.", ""])
    return "\n".join(lines).rstrip() + "\n"


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--reference-root", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()

    count = 0
    for version_dir in sorted(args.reference_root.iterdir()):
        if not version_dir.is_dir() or not re.match(r"\d+\.\d+\.\d+", version_dir.name):
            continue
        for subsystem_dir in sorted(version_dir.iterdir()):
            if not subsystem_dir.is_dir():
                continue
            for component_dir in sorted(subsystem_dir.iterdir()):
                if not (component_dir / "symbols.txt").exists():
                    continue
                module_name = component_dir.name
                methods = recover_methods(component_dir, module_name)
                destination = args.output / version_dir.name / subsystem_dir.name / f"{module_name}.py"
                destination.parent.mkdir(parents=True, exist_ok=True)
                destination.write_text(
                    render_module(
                        version_dir.name, subsystem_dir.name, module_name,
                        component_dir, methods,
                    ),
                    encoding="utf-8",
                )
                count += 1
    print(f"Generated {count} estimated source outlines in {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
