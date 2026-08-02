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

# Emit machine-readable migration facts as a single JSON object on stdout.
#
# This collects observations only. It deliberately makes no judgement about
# which migration stage a printer has reached: that reconciliation happens in
# probes.py, where it can be unit-tested against recorded fixtures without
# hardware. Every collector is individually guarded so that one unreadable
# path cannot deny the caller the remaining facts; failures are reported in
# the "errors" array instead.
probe() {
    local data_dir="${1:-}" printer_user="${2:-}" connect_sudo=no
    # Whether the *connecting* account can sudo, sampled before any user switch.
    sudo -n true >/dev/null 2>&1 && connect_sudo=yes

    # Everything the probes read — the Klipper checkouts, printer.cfg, the
    # bootstrap receipt — lives under the home of the account that owns Klipper,
    # and is not readable by a separate management account. Collect as that
    # account so every path resolves exactly as it would on a single-account
    # host. -H sets HOME so Path.home() follows.
    local runner=(python3 -)
    if [[ -n "$printer_user" && "$printer_user" != "$(id -un)" ]]; then
        id "$printer_user" >/dev/null 2>&1 ||
            die "printer user does not exist: $printer_user"
        runner=(sudo -n -u "$printer_user" -H python3 -)
    fi

    "${runner[@]}" "$data_dir" "$connect_sudo" <<'PY'
import hashlib
import json
import pathlib
import re
import subprocess
import sys
import urllib.request
from datetime import datetime, timezone

home = pathlib.Path.home()
# Resolved after any switch to the Klipper account, so the default follows that
# account's home rather than the one used to connect.
data_dir = pathlib.Path(sys.argv[1]) if sys.argv[1] else home / "printer_data"
connect_sudo = sys.argv[2] == "yes" if len(sys.argv) > 2 else False
errors: list[str] = []


def guard(name, collect, default=None):
    try:
        return collect()
    except Exception as exc:  # a probe must never abort the whole collection
        errors.append(f"{name}: {type(exc).__name__}: {exc}")
        return default


def command(argv, timeout=15):
    result = subprocess.run(argv, capture_output=True, text=True, timeout=timeout)
    return result.stdout.strip()


def read_os_release():
    wanted = ("ID", "PRETTY_NAME", "VERSION_ID", "VERSION_CODENAME")
    values = {}
    for line in pathlib.Path("/etc/os-release").read_text(encoding="utf-8").splitlines():
        key, _, value = line.partition("=")
        if key in wanted:
            values[key] = value.strip().strip('"')
    return values


def unit_states(units, verb):
    # Queried one unit at a time on purpose. Asking about several units at once
    # makes systemctl's output positional, and a unit it has never heard of can
    # contribute no line at all, silently shifting every later state onto the
    # wrong unit. An absent unit is reported as "not-found", which is a decidable
    # answer; if systemctl cannot be run the caller's guard drops the whole key,
    # which the probes read as "could not tell" instead.
    states = {}
    for unit in units:
        result = subprocess.run(
            ["systemctl", verb, unit], capture_output=True, text=True, timeout=15
        )
        text = result.stdout.strip()
        states[unit] = text.splitlines()[0] if text else "not-found"
    return states


def serial_devices():
    devices = {}
    for name in ("/dev/ttyS0", "/dev/ttyS2"):
        path = pathlib.Path(name)
        entry = {"present": path.exists(), "users": []}
        if entry["present"]:
            users = subprocess.run(
                ["fuser", name], capture_output=True, text=True, timeout=15
            ).stdout.split()
            entry["users"] = [int(pid) for pid in users if pid.isdigit()]
        devices[name] = entry
    return devices


def checkouts():
    found = {}
    for name in ("klipper", "moonraker", "katapult"):
        directory = home / name
        entry = {"present": (directory / ".git").is_dir(), "head": None}
        if entry["present"]:
            entry["head"] = command(
                ["git", "-C", str(directory), "rev-parse", "HEAD"]
            ) or None
        found[name] = entry
    return found


def printer_config():
    directory = data_dir / "config"
    path = directory / "printer.cfg"
    if not path.is_file():
        return {"present": False, "path": str(path)}
    raw = path.read_bytes()
    text = raw.decode("utf-8", errors="replace")

    # MCU sections are counted across the whole config directory, not just
    # printer.cfg. The reviewed profile declares them in hardware.cfg and pulls
    # it in with [include], so reading printer.cfg alone finds none at all.
    sections, serials = set(), set()
    for candidate in sorted(directory.glob("*.cfg")):
        try:
            body = candidate.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        sections.update(name.strip()
                        for name in re.findall(r"^\[(mcu[^\]]*)\]", body, re.MULTILINE))
        serials.update(re.findall(r"^\s*serial:\s*(\S+)", body, re.MULTILINE))

    return {
        "present": True,
        "path": str(path),
        # Size and digest stay specific to printer.cfg: the smoke-test config is
        # a single self-contained file and is recognised by its exact digest.
        "size": len(raw),
        "sha256": hashlib.sha256(raw).hexdigest(),
        "includes": re.findall(r"^\[include\s+([^\]]+)\]", text, re.MULTILINE),
        "mcu_sections": sorted(sections),
        "serials": sorted(serials),
    }


def moonraker_state():
    state = {"reachable": False, "klippy_state": None,
             "klippy_message": None, "mcu_objects": []}
    base = "http://127.0.0.1:7125"
    with urllib.request.urlopen(f"{base}/printer/info", timeout=10) as response:
        payload = json.loads(response.read().decode("utf-8"))
    state["reachable"] = True
    result = payload.get("result", {})
    state["klippy_state"] = result.get("state")
    state["klippy_message"] = result.get("state_message")
    try:
        with urllib.request.urlopen(f"{base}/printer/objects/list", timeout=10) as response:
            listing = json.loads(response.read().decode("utf-8"))
        state["mcu_objects"] = sorted(
            name for name in listing.get("result", {}).get("objects", [])
            if name == "mcu" or name.startswith("mcu ")
        )
    except Exception as exc:
        # Klippy in shutdown answers /printer/info but refuses object queries.
        errors.append(f"moonraker.objects: {type(exc).__name__}: {exc}")
    return state


def bootstrap_receipt():
    # bootstrap-mainline.sh writes this file only after every stage of the host
    # install succeeded, so it is the authoritative completion marker.
    path = data_dir / "mainline-bootstrap.txt"
    if not path.is_file():
        return {"present": False, "path": str(path)}
    values = {"present": True, "path": str(path)}
    for line in path.read_text(encoding="utf-8").splitlines():
        key, separator, value = line.partition("=")
        if separator:
            values[key.strip()] = value.strip()
    return values


def stock_markers():
    markers = {"hid_flash": [], "full_flash_images": []}
    for candidate in (pathlib.Path("/root/hid-flash"), home / "hid-flash"):
        if candidate.is_file():
            markers["hid_flash"].append(str(candidate))
    for image in sorted(home.glob("*full-flash*.bin")):
        markers["full_flash_images"].append(str(image))
    return markers


services = (
    "klipper", "moonraker", "makerbase-client",
    "qidi-plus4-host-tuning", "crowsnest", "qidi-screen-bridge",
)

facts = {
    "schema": 1,
    "collected_at_utc": datetime.now(timezone.utc).isoformat(),
    "data_dir": str(data_dir),
    "home": str(home),
    "hostname": guard("hostname", lambda: command(["hostname"])),
    "device_tree_model": guard(
        "device_tree_model",
        lambda: pathlib.Path("/proc/device-tree/model")
        .read_text(encoding="utf-8", errors="replace").strip("\x00\n "),
    ),
    "kernel": guard("kernel", lambda: command(["uname", "-srmo"])),
    "os_release": guard("os_release", read_os_release, {}),
    "python3": guard("python3", lambda: command(["python3", "--version"])),
    # Reported for the connecting account, since that is the one the migration
    # stages run their privileged work through.
    "passwordless_sudo": connect_sudo,
    "collected_as": guard("collected_as", lambda: command(["id", "-un"])),
    "services": guard("services", lambda: unit_states(services, "is-active"), {}),
    "services_enabled": guard(
        "services_enabled", lambda: unit_states(services, "is-enabled"), {}
    ),
    # Keyed by tty name rather than by unit name: probes address facts with
    # dotted paths, so a key may not itself contain a dot.
    "serial_getty": guard(
        "serial_getty",
        lambda: {
            tty: state for tty, state in zip(
                ("ttyS0", "ttyS2"),
                unit_states(
                    ["serial-getty@ttyS0.service", "serial-getty@ttyS2.service"],
                    "is-enabled",
                ).values(),
            )
        },
        {},
    ),
    "serial_devices": guard("serial_devices", serial_devices, {}),
    "udev_rule": guard(
        "udev_rule",
        lambda: pathlib.Path("/etc/udev/rules.d/99-qidi-uarts.rules").is_file(),
    ),
    "klippy_env": guard(
        "klippy_env", lambda: (home / "klippy-env" / "bin" / "python").is_file()
    ),
    "bootstrap_receipt": guard(
        "bootstrap_receipt", bootstrap_receipt, {"present": False}
    ),
    "checkouts": guard("checkouts", checkouts, {}),
    "printer_cfg": guard("printer_cfg", printer_config, {}),
    "moonraker": guard("moonraker", moonraker_state, {"reachable": False}),
    "stock_markers": guard("stock_markers", stock_markers, {}),
}
facts["errors"] = errors
print(json.dumps(facts, indent=2, sort_keys=True))
PY
}

# Create a dedicated management account with key-only login and passwordless
# sudo, leaving the printer's own Klipper account untouched.
#
# Run through an account that already has passwordless sudo. No password is
# ever set on the new account, so it cannot be used for password login at all.
setup_management_user() {
    local new_user="$1" pubkey="$2" confirmation="${3:-}"
    [[ "$confirmation" == 'CREATE-MANAGEMENT-USER' ]] ||
        die 'Explicit CREATE-MANAGEMENT-USER confirmation missing.'
    [[ "$new_user" =~ ^[a-z_][a-z0-9_-]*$ ]] || die "Invalid account name: $new_user"
    [[ "$pubkey" == ssh-* || "$pubkey" == ecdsa-* ]] ||
        die 'Expected an OpenSSH public key.'
    need_sudo

    if id "$new_user" >/dev/null 2>&1; then
        printf 'account=%s existing\n' "$new_user"
    else
        sudo -n useradd --create-home --shell /bin/bash "$new_user" ||
            die "Failed to create $new_user"
        printf 'account=%s created\n' "$new_user"
    fi
    # Never set a password; lock the field so only the key can be used.
    sudo -n passwd -l "$new_user" >/dev/null 2>&1 || true

    local group
    for group in sudo dialout; do
        getent group "$group" >/dev/null || continue
        sudo -n usermod -aG "$group" "$new_user" || die "Failed to add $new_user to $group"
    done

    local home ssh_dir keys
    home=$(getent passwd "$new_user" | cut -d: -f6)
    [[ -n "$home" ]] || die "Could not resolve the home directory for $new_user"
    ssh_dir="$home/.ssh"
    keys="$ssh_dir/authorized_keys"
    sudo -n install -d -m 700 -o "$new_user" -g "$new_user" "$ssh_dir"
    sudo -n touch "$keys"
    sudo -n chown "$new_user:$new_user" "$keys"
    sudo -n chmod 600 "$keys"
    if sudo -n grep -qxF "$pubkey" "$keys" 2>/dev/null; then
        printf 'key=already-present\n'
    else
        printf '%s\n' "$pubkey" | sudo -n tee -a "$keys" >/dev/null
        printf 'key=installed\n'
    fi

    # Validate the fragment before installing it. A malformed file under
    # sudoers.d breaks sudo for every account on the machine, including the one
    # this command is running through.
    local fragment="/etc/sudoers.d/60-$new_user" staged
    staged=$(mktemp)
    printf '%s ALL=(ALL) NOPASSWD:ALL\n' "$new_user" >"$staged"
    if ! sudo -n visudo -cf "$staged" >/dev/null 2>&1; then
        rm -f "$staged"
        die 'Generated sudoers fragment failed validation; nothing was installed.'
    fi
    sudo -n install -m 0440 -o root -g root "$staged" "$fragment"
    rm -f "$staged"

    printf 'sudoers=%s\n' "$fragment"
    printf 'groups=%s\n' "$(id -nG "$new_user")"
    printf 'result=ready\n'
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
    probe) probe "${2:-}" "${3:-}" ;;
    setup-management-user) setup_management_user "$2" "$3" "${4:-}" ;;
    validate) validate_image "$2" "$3" ;;
    flash-mainboard) flash_mainboard "$2" "$3" "${4:-}" ;;
    flash-toolhead-katapult) flash_toolhead_katapult "$2" "$3" "${4:-}" "${5:-/home/mks/qidi-mainline-migration/backups}" ;;
    flash-toolhead) flash_toolhead_app "$2" "$3" "${4:-}" "${5:-/home/mks/katapult}" ;;
    *) die 'Usage: qidi-plus4-remote.sh {audit|probe|setup-management-user|validate|flash-mainboard|flash-toolhead-katapult|flash-toolhead} ...' ;;
esac
