#!/bin/sh
set -eu

manifest="$1"
include_gcodes="$2"
include_logs="$3"
include_envs="$4"
umask 077
: >"$manifest"

section() { printf '\n===== %s =====\n' "$1" >>"$manifest"; }
run_info() { title="$1"; shift; section "$title"; "$@" >>"$manifest" 2>&1 || true; }

run_info "backup time" date -u
run_info "hostname" hostname
run_info "kernel" uname -a
run_info "os release" cat /etc/os-release
run_info "disk usage" df -h
run_info "memory" free -h
run_info "network addresses" ip addr
run_info "USB devices" sh -c 'command -v lsusb >/dev/null 2>&1 && lsusb || true'
run_info "serial devices" sh -c 'ls -la /dev/serial/by-id /dev/serial/by-path 2>/dev/null || true'
run_info "Klipper service" sh -c 'systemctl cat klipper 2>/dev/null || true'
run_info "Moonraker service" sh -c 'systemctl cat moonraker 2>/dev/null || true'
run_info "enabled services" sh -c 'systemctl list-unit-files --state=enabled 2>/dev/null || true'
# dpkg expands these placeholders, not the shell.
# shellcheck disable=SC2016
run_info "installed packages" sh -c 'dpkg-query -W -f="${binary:Package}\t${Version}\n" 2>/dev/null || true'

section "source repositories"
find /home/mks -maxdepth 3 -type d -name .git 2>/dev/null | sort | while IFS= read -r gitdir; do
    repo=${gitdir%/.git}
    printf '\n--- %s ---\n' "$repo" >>"$manifest"
    git -C "$repo" remote -v >>"$manifest" 2>&1 || true
    git -C "$repo" describe --always --tags --dirty >>"$manifest" 2>&1 || true
    git -C "$repo" status --short >>"$manifest" 2>&1 || true
done

if command -v sudo >/dev/null 2>&1 && sudo -n true 2>/dev/null; then
    tar_command="sudo -n tar"
    has_sudo=1
else
    tar_command=tar
    has_sudo=0
fi

paths="home/mks etc/systemd/system lib/systemd/system etc/init.d etc/default etc/network etc/NetworkManager boot root/xindi usr/data usr/share/klipper"
existing=""
section "archived roots"
for path in $paths; do
    if { [ "$has_sudo" = 1 ] && sudo -n test -e "/$path"; } || [ -e "/$path" ]; then
        existing="$existing $path"
        printf '/%s\n' "$path" >>"$manifest"
    fi
done
[ -n "$existing" ] || { echo 'No expected backup paths found.' >&2; exit 3; }

exclude_args="--exclude=home/mks/.cache --exclude=home/mks/printer_data/comms"
[ "$include_gcodes" = 1 ] || exclude_args="$exclude_args --exclude=home/mks/printer_data/gcodes"
[ "$include_logs" = 1 ] || exclude_args="$exclude_args --exclude=home/mks/printer_data/logs --exclude=home/mks/printer_data/timelapse"
if [ "$include_envs" != 1 ]; then
    exclude_args="$exclude_args --exclude=home/mks/klippy-env --exclude=home/mks/moonraker-env --exclude=home/mks/crowsnest-env --exclude=home/mks/*-env --exclude=home/mks/*_env"
fi
chmod 600 "$manifest"
# shellcheck disable=SC2086
$tar_command -C / -czf - --ignore-failed-read --warning=no-file-changed $exclude_args $existing
