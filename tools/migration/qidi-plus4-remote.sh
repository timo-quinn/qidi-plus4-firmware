#!/usr/bin/env bash
set -euo pipefail

known_mainboard_flasher='22a3b082954567f9ab3168333afbeb14fb8503c11ecedad6263d2db70a3a2519'

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
import pathlib, struct, sys

kind, filename = sys.argv[1:]
data = pathlib.Path(filename).read_bytes()
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
    local image="$1" expected_sha="$2" confirmation="$3" flasher='/root/hid-flash'
    [[ "$confirmation" == 'FLASH-MAINBOARD' ]] || die 'Explicit FLASH-MAINBOARD confirmation missing.'
    need_sudo
    validate_image mainboard "$image"
    assert_hash "$image" "$expected_sha"
    sudo -n test -x "$flasher" || die "$flasher is unavailable; run this phase on the stock host."
    [[ "$(sudo -n sha256sum "$flasher" | awk '{print $1}')" == "$known_mainboard_flasher" ]] || \
        die 'The installed QIDI mainboard flasher does not match either verified printer.'
    [[ -c /dev/ttyS0 ]] || die '/dev/ttyS0 is missing.'
    systemctl is-active --quiet klipper || die 'The stock Klipper service is not active.'
    [[ -p /home/mks/printer_data/comms/klippy.serial ]] || \
        die 'Klipper command FIFO is missing; the stock Klipper service must be healthy.'

    printf 'Requesting the verified stock mainboard bootloader...\n'
    printf 'FIRMWARE_RESTART\n' | timeout 5 sudo -n tee /home/mks/printer_data/comms/klippy.serial >/dev/null
    sleep 3
    sudo -n systemctl stop klipper
    if sudo -n "$flasher" "$image" ttyS0; then
        printf 'Mainboard application flash completed. Klipper remains stopped.\n'
        printf 'Power down and continue with the replacement host installation.\n'
    else
        status=$?
        printf 'Mainboard flasher failed; attempting to restart the stock Klipper service.\n' >&2
        sudo -n systemctl start klipper || true
        exit "$status"
    fi
}

flash_toolhead_katapult() {
    local image="$1" expected_sha="$2" confirmation="$3" backup_dir="$4"
    [[ "$confirmation" == 'ERASE-TOOLHEAD' ]] || die 'Explicit ERASE-TOOLHEAD confirmation missing.'
    need_sudo; need st-info; need st-flash
    validate_image toolhead-katapult "$image"
    assert_hash "$image" "$expected_sha"
    probe="$(st-info --probe 2>&1)"
    printf '%s\n' "$probe"
    grep -Eqi 'F1|chipid:[[:space:]]+0x0?414' <<<"$probe" || \
        die 'ST-Link did not report an STM32F1-class target; check wiring and board identity.'
    mkdir -p "$backup_dir"
    backup="$backup_dir/toolhead-pre-katapult-$(date -u +%Y%m%dT%H%M%SZ).bin"
    sudo -n systemctl stop klipper || true
    st-flash read "$backup" 0x08000000 0x10000
    sha256sum "$backup"
    st-flash write "$image" 0x08000000
    verify="$backup_dir/toolhead-katapult-verify.bin"
    st-flash read "$verify" 0x08000000 "$(stat -c %s "$image")"
    cmp -n "$(stat -c %s "$image")" "$image" "$verify" || die 'Katapult read-back differs.'
    rm -f "$verify"
    printf 'Katapult verified. Disconnect ST-Link and restore the toolhead wiring before flashing Klipper.\n'
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
