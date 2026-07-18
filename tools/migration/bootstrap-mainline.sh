#!/usr/bin/env bash
set -euo pipefail

if [[ $EUID -eq 0 ]]; then
    echo 'Run this script as the regular printer user, not root.' >&2
    exit 1
fi
sudo -n true >/dev/null 2>&1 || {
    echo 'Passwordless sudo is required for unattended SSH bootstrap.' >&2
    exit 1
}

home="$HOME"
data="$home/printer_data"
klipper="$home/klipper"
moonraker="$home/moonraker"
katapult="$home/katapult"
klipper_ref="${KLIPPER_REF:-master}"
moonraker_ref="${MOONRAKER_REF:-master}"
katapult_ref="${KATAPULT_REF:-master}"

sudo apt-get update
sudo DEBIAN_FRONTEND=noninteractive apt-get install -y \
    git python3 python-is-python3 python3-venv python3-dev python3-pip python3-serial \
    build-essential libffi-dev libncurses-dev libusb-dev libusb-1.0-0-dev \
    pkg-config gcc-arm-none-eabi binutils-arm-none-eabi \
    libnewlib-arm-none-eabi stm32flash stlink-tools curl

clone_or_update() {
    local url="$1" directory="$2" ref="$3"
    if [[ -d "$directory/.git" ]]; then
        [[ -z "$(git -C "$directory" status --porcelain)" ]] || {
            echo "Refusing to update dirty checkout: $directory" >&2; exit 1;
        }
    else
        git clone "$url" "$directory"
    fi
    git -C "$directory" fetch --prune origin "$ref"
    git -C "$directory" checkout --detach FETCH_HEAD
}

clone_or_update https://github.com/Klipper3d/klipper.git "$klipper" "$klipper_ref"
clone_or_update https://github.com/Arksine/moonraker.git "$moonraker" "$moonraker_ref"
clone_or_update https://github.com/Arksine/katapult.git "$katapult" "$katapult_ref"

python3 -m venv "$home/klippy-env"
"$home/klippy-env/bin/pip" install --upgrade pip
"$home/klippy-env/bin/pip" install -r "$klipper/scripts/klippy-requirements.txt"

mkdir -p "$data/config" "$data/logs" "$data/comms" "$data/systemd" "$data/gcodes"
touch "$data/config/printer.cfg"
sudo usermod -a -G dialout "$USER"
printf '%s\n' \
    'KERNEL=="ttyS0",GROUP="dialout",MODE="0660"' \
    'KERNEL=="ttyS2",GROUP="dialout",MODE="0660"' | \
    sudo tee /etc/udev/rules.d/99-qidi-uarts.rules >/dev/null
sudo systemctl mask serial-getty@ttyS0.service serial-getty@ttyS2.service
sudo udevadm control --reload-rules
sudo udevadm trigger

cat >"$data/systemd/klipper.env" <<EOF
KLIPPER_ARGS="$klipper/klippy/klippy.py $data/config/printer.cfg -I $data/comms/klippy.serial -l $data/logs/klippy.log -a $data/comms/klippy.sock"
EOF

sudo tee /etc/systemd/system/klipper.service >/dev/null <<EOF
[Unit]
Description=Klipper 3D Printer Firmware
Documentation=https://www.klipper3d.org/
After=network-online.target
Wants=network-online.target

[Install]
WantedBy=multi-user.target

[Service]
Type=simple
User=$USER
WorkingDirectory=$klipper
EnvironmentFile=$data/systemd/klipper.env
ExecStart=$home/klippy-env/bin/python \$KLIPPER_ARGS
Restart=always
RestartSec=10
EOF

sudo systemctl daemon-reload
sudo systemctl enable klipper.service
sudo systemctl stop klipper.service 2>/dev/null || true

moonraker_config="$data/config/moonraker.conf"
if [[ ! -s "$moonraker_config" ]]; then
    cat >"$moonraker_config" <<EOF
[server]
host: 0.0.0.0
port: 7125
klippy_uds_address: $data/comms/klippy.sock

[authorization]
trusted_clients:
    127.0.0.0/8
    ::1/128
EOF
fi

MOONRAKER_DATA_PATH="$data" MOONRAKER_FORCE_SYSTEM_INSTALL=y \
    "$moonraker/scripts/install-moonraker.sh" -f

{
    printf 'installed_at_utc=%s\n' "$(date -u +%Y-%m-%dT%H:%M:%SZ)"
    printf 'klipper_commit=%s\n' "$(git -C "$klipper" rev-parse HEAD)"
    printf 'moonraker_commit=%s\n' "$(git -C "$moonraker" rev-parse HEAD)"
    printf 'katapult_commit=%s\n' "$(git -C "$katapult" rev-parse HEAD)"
} | tee "$data/mainline-bootstrap.txt"

echo
echo 'Host bootstrap complete. Klipper remains stopped until printer.cfg is installed.'
echo 'Log out and back in before using the UARTs so the dialout group applies.'
