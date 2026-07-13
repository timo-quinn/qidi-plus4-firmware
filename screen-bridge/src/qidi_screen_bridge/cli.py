from __future__ import annotations

import argparse
import glob
import json
import sys
from pathlib import Path

from .capture import capture_serial
from .profile import load_profile
from .protocol import decode_packet


def _hex_bytes(value: str) -> bytes:
    try:
        return bytes.fromhex(value.replace("0x", ""))
    except ValueError as exc:
        raise argparse.ArgumentTypeError(str(exc)) from exc


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="qidi-screen-bridge",
        description="Research tools for the QIDI Plus4 stock touchscreen",
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    decode = subparsers.add_parser("decode", help="decode one hex-encoded screen packet")
    decode.add_argument("packet", type=_hex_bytes)

    validate = subparsers.add_parser("validate-profile", help="validate screen profiles")
    validate.add_argument("profiles", nargs="+", type=Path)

    capture = subparsers.add_parser("capture", help="capture screen-to-host UART packets")
    capture.add_argument("--device", required=True)
    capture.add_argument("--baud", required=True, type=int)
    capture.add_argument("--output", required=True, type=Path)
    capture.add_argument("--raw-output", type=Path)
    return parser


def _expand_profiles(paths: list[Path]) -> list[Path]:
    """Expand profile wildcards consistently on Unix and Windows shells."""

    expanded: list[Path] = []
    for path in paths:
        value = str(path)
        if any(character in value for character in "*?["):
            matches = [Path(match) for match in glob.glob(value)]
            if not matches:
                raise SystemExit(f"profile pattern matched no files: {value}")
            expanded.extend(matches)
        else:
            expanded.append(path)
    return expanded


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    if args.command == "decode":
        print(json.dumps(decode_packet(args.packet).as_dict(), indent=2, sort_keys=True))
        return 0
    if args.command == "validate-profile":
        for path in _expand_profiles(args.profiles):
            profile = load_profile(path)
            print(
                f"{path}: valid ({profile.profile_id}; "
                f"{len(profile.unknowns)} documented unknowns)"
            )
        return 0
    if args.command == "capture":
        if args.baud <= 0:
            raise SystemExit("--baud must be positive")
        raw = args.raw_output.open("ab") if args.raw_output else None
        try:
            capture_serial(args.device, args.baud, args.output, raw_stream=raw)
        except KeyboardInterrupt:
            return 130
        finally:
            if raw is not None:
                raw.close()
        return 0
    return 2


if __name__ == "__main__":
    sys.exit(main())
