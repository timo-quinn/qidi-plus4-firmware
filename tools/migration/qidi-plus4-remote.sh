#!/usr/bin/env bash
set -euo pipefail

# Directory this script was staged into, used to find the shared MCU layout
# table (mcu-layouts.json) that the orchestrator copies in alongside it.
script_dir="$(cd "$(dirname "$0")" 2>/dev/null && pwd || true)"
export QIDI_LAYOUTS_FILE="${script_dir:+$script_dir/mcu-layouts.json}"

die() { printf 'ERROR: %s\n' "$*" >&2; exit 1; }
need() { command -v "$1" >/dev/null || die "Missing command: $1"; }
need_sudo() { sudo -n true >/dev/null 2>&1 || die 'Passwordless sudo is required.'; }

sha256_file() { sha256sum "$1" | awk '{print $1}'; }
assert_hash() {
    local path="$1" expected="${2,,}" actual
    actual="$(sha256_file "$path")"
    [[ "$actual" == "$expected" ]] || die "SHA-256 mismatch for $path: $actual"
}

validate_image() {
    local kind="$1" image="$2"
    [[ -f "$image" ]] || die "Image not found: $image"
    python3 - "$kind" "$image" <<'PY'
import json, os, pathlib, struct, sys

kind, filename = sys.argv[1:]
data = pathlib.Path(filename).read_bytes()
# Canonical layouts come from mcu-layouts.json (staged beside this script and
# shared with qidi_plus4.py). The inline table is a standalone fallback and must
# be kept identical to that file.
layouts_file = os.environ.get("QIDI_LAYOUTS_FILE", "")
if layouts_file and pathlib.Path(layouts_file).exists():
    layouts = {name: tuple(int(value, 16) for value in bounds)
               for name, bounds in json.loads(pathlib.Path(layouts_file).read_text()).items()}
else:
    layouts = {
        "mainboard": (0x08008000, 0x08040000, 0x20000000, 0x20020000),
        "toolhead-app": (0x08002000, 0x08010000, 0x20000000, 0x20010000),
        "toolhead-katapult": (0x08000000, 0x08002000, 0x20000000, 0x20010000),
    }
if kind not in layouts:
    raise SystemExit("Unknown image kind: " + kind)
base, limit, ram_start, ram_limit = layouts[kind]
if len(data) < 32 or len(data) > limit - base:
    raise SystemExit("Invalid image size: %d bytes" % len(data))
stack, reset = struct.unpack_from("<II", data)
reset_address = reset & ~1
if not ram_start <= stack < ram_limit:
    raise SystemExit("Stack vector outside expected SRAM: 0x%08x" % stack)
if not base <= reset_address < limit or not reset & 1:
    raise SystemExit("Reset vector outside expected Thumb image: 0x%08x" % reset)
print("validated kind=%s size=%d stack=0x%08x reset=0x%08x" %
      (kind, len(data), stack, reset))
PY
}

request_serial_bootloader() {
    local device="$1" baud="$2"
    sudo -n python3 - "$device" "$baud" <<'PY'
import os
import sys
import termios
import time
import tty

device, baud_text = sys.argv[1:]
baud = int(baud_text)
speed = getattr(termios, "B%d" % baud, None)
if speed is None:
    raise SystemExit("Unsupported serial bootloader-request baud: %d" % baud)

request = b" \x1c Request Serial Bootloader!! ~"
if len(request) != 32:
    raise SystemExit("Internal serial bootloader request has an invalid length")

def write_all(fd, data):
    view = memoryview(data)
    while view:
        written = os.write(fd, view)
        if written <= 0:
            raise SystemExit("Failed to write the serial bootloader request")
        view = view[written:]

fd = os.open(device, os.O_RDWR | os.O_NOCTTY)
try:
    tty.setraw(fd, termios.TCSANOW)
    attrs = termios.tcgetattr(fd)
    attrs[4] = speed
    attrs[5] = speed
    termios.tcsetattr(fd, termios.TCSANOW, attrs)
    termios.tcflush(fd, termios.TCIOFLUSH)
    # End and discard any partial Klipper protocol frame left when the host
    # process closed. The bootloader request must begin at an empty frame and
    # be exactly 32 bytes long to pass the MCU's special request check.
    write_all(fd, b"\x7e")
    termios.tcdrain(fd)
    time.sleep(0.1)
    write_all(fd, request)
    termios.tcdrain(fd)
    time.sleep(0.1)
finally:
    os.close(fd)

print("Sent the 32-byte Klipper serial bootloader request at %d baud" % baud)
PY
}

audit() {
    printf 'hostname=%s\n' "$(hostname)"
    printf 'model='; tr -d '\000' </proc/device-tree/model 2>/dev/null || true; printf '\n'
    grep -E '^(PRETTY_NAME|VERSION_ID|VERSION_CODENAME)=' /etc/os-release || true
    uname -srmo
    python3 --version 2>&1 || true
    df -h / /home /tmp 2>/dev/null || true
    for device in /dev/ttyS0 /dev/ttyS2; do
        ls -l "$device" 2>&1 || true
        printf '%s_users=' "$device"; fuser "$device" 2>/dev/null || true; printf '\n'
    done
    systemctl is-enabled serial-getty@ttyS0.service serial-getty@ttyS2.service 2>/dev/null || true
    systemctl is-active klipper moonraker makerbase-client 2>/dev/null || true
    if sudo -n true >/dev/null 2>&1; then
        printf 'passwordless_sudo=yes\n'
        for flasher in /root/hid-flash /home/mks/hid-flash; do
            if sudo -n test -f "$flasher"; then
                sudo -n sha256sum "$flasher" || true
            fi
        done
    else
        printf 'passwordless_sudo=no\n'
    fi
    find /home/mks -maxdepth 1 -type f -name '*full-flash*.bin' -exec sha256sum {} \; 2>/dev/null || true
    grep -nE '^\[mcu|^[[:space:]]*(serial|baud|restart_method):' \
        /home/mks/printer_data/config/printer.cfg 2>/dev/null | head -30 || true
}

flash_mainboard() {
    # Disabled: repeated live tests on the stock Plus4 showed QIDI's UART loader
    # never acknowledged the serial bootloader request, and the flasher returned
    # a false-success status without transferring a firmware page. The supported
    # mainboard route is the resident microSD bootloader. See
    # docs/MAINLINE-MIGRATION.md and docs/FIRMWARE-FLASHING.md; the historical
    # implementation is preserved in Git history.
    die 'Direct SSH mainboard flashing is disabled: the stock Plus4 UART loader did
not enter the bootloader in live testing and no firmware pages transferred. Stage
plus4-mainboard-klipper.bin as qd_mcu.bin (qidi_plus4.py stage-mainboard-sdcard)
and flash it through the resident microSD bootloader per docs/MAINLINE-MIGRATION.md.'
}

flash_toolhead_katapult() {
    local image="$1" expected_sha="$2" confirmation="$3" backup_dir="$4"
    [[ "$confirmation" == 'ERASE-TOOLHEAD' ]] || die 'Explicit ERASE-TOOLHEAD confirmation missing.'
    need_sudo; need st-info; need st-flash
    validate_image toolhead-katapult "$image"
    assert_hash "$image" "$expected_sha"
    probe="$(st-info --probe 2>&1)"
    printf '%s\n' "$probe"
    # The toolhead is an STM32F103xE (device/chip id 0x414). Match the chip id or
    # an explicit STM32F1 descriptor, not a bare "F1" that can occur elsewhere.
    grep -Eqi 'chipid:[[:space:]]*0x0?414|STM32F1' <<<"$probe" || \
        die 'ST-Link did not report an STM32F1-class target; check wiring and board identity.'
    mkdir -p "$backup_dir"
    backup="$backup_dir/toolhead-pre-katapult-$(date -u +%Y%m%dT%H%M%SZ).bin"
    sudo -n systemctl stop klipper || true
    st-flash read "$backup" 0x08000000 0x10000
    sha256sum "$backup"
    # Stock QIDI Klipper is linked at 0x08000000. Merely overwriting its first
    # pages leaves non-blank data at Katapult's 0x08002000 application vector.
    # Katapult then jumps into stale stock code instead of waiting on UART.
    # Preserve the read-back above, then erase the target before installing it.
    st-flash erase
    st-flash write "$image" 0x08000000
    verify="$backup_dir/toolhead-katapult-verify.bin"
    st-flash read "$verify" 0x08000000 "$(stat -c %s "$image")"
    cmp -n "$(stat -c %s "$image")" "$image" "$verify" || die 'Katapult read-back differs.'
    rm -f "$verify"
    app_vector="$backup_dir/toolhead-app-vector-verify.bin"
    st-flash read "$app_vector" 0x08002000 8
    python3 - "$app_vector" <<'PY'
import pathlib, sys

data = pathlib.Path(sys.argv[1]).read_bytes()
if data != b"\xff" * 8:
    raise SystemExit("Katapult application vector is not blank after erase")
PY
    rm -f "$app_vector"
    printf 'Katapult and blank application vector verified. Disconnect ST-Link and restore the toolhead wiring before flashing Klipper.\n'
}

flash_toolhead_app() {
    local image="$1" expected_sha="$2" confirmation="$3" katapult_dir="$4"
    [[ "$confirmation" == 'FLASH-TOOLHEAD' ]] || die 'Explicit FLASH-TOOLHEAD confirmation missing.'
    need_sudo
    validate_image toolhead-app "$image"
    assert_hash "$image" "$expected_sha"
    [[ -f "$katapult_dir/scripts/flashtool.py" ]] || die "Katapult flashtool missing below $katapult_dir."
    [[ -c /dev/ttyS2 ]] || die '/dev/ttyS2 is missing.'
    sudo -n systemctl stop klipper || true
    if python3 "$katapult_dir/scripts/flashtool.py" -b 500000 -d /dev/ttyS2 -f "$image"; then
        sudo -n systemctl start klipper || true
    else
        status=$?
        printf 'Toolhead flash failed; Klipper remains stopped.\n' >&2
        exit "$status"
    fi
}

case "${1:-}" in
    audit) audit ;;
    validate) validate_image "$2" "$3" ;;
    flash-mainboard) flash_mainboard "$2" "$3" "${4:-}" ;;
    flash-toolhead-katapult) flash_toolhead_katapult "$2" "$3" "${4:-}" "${5:-/home/mks/qidi-mainline-migration/backups}" ;;
    flash-toolhead) flash_toolhead_app "$2" "$3" "${4:-}" "${5:-/home/mks/katapult}" ;;
    *) die 'Usage: qidi-plus4-remote.sh {audit|validate|flash-mainboard|flash-toolhead-katapult|flash-toolhead} ...' ;;
esac
