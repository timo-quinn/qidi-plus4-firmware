# QIDI Plus4 mainline Klipper migration

This guide combines current community work with measurements from the two
printers used for this repository. It minimizes disassembly, avoids appliance
firmware dependencies, and keeps a straightforward stock recovery path.

> **Status:** audit, build, download, and validation paths are non-destructive.
> The SSH mainboard flash remains experimental until it has been completed and
> recovered on one of these printers. Flash commands require exact confirmation
> phrases and validate their inputs before touching an MCU.

## Recommended route

1. Back up the printer and retain complete MCU dumps.
2. Download the official Armbian Qidi X-6 image and prepare a spare eMMC.
3. Build matching mainline Klipper and Katapult images from source.
4. While the stock host is healthy, flash the mainboard application over SSH
   through QIDI's existing bootloader and verified flasher.
5. Power off and swap in the prepared eMMC.
6. Bootstrap official Klipper, Moonraker, and Katapult over SSH.
7. Attach four temporary ST-Link wires to the toolhead, install Katapult once,
   disconnect it, and flash toolhead Klipper over SSH.
8. Install a reviewed mainline configuration and perform cold commissioning.

This removes the mainboard microSD step and avoids soldering or removing the
toolhead board. It is not physically hands-off: the stock toolhead has no
bootloader, and safely changing the host OS still means swapping the eMMC.

## Live verification

Read-only SSH checks were run on 2026-07-13.

| Property | `qidi1` | `qidi2` |
|---|---|---|
| QIDI release | 1.8.2, QIDI Box | 1.7.3 |
| Host | Debian 10, kernel 5.16.20-rockchip64 | same |
| Python | 3.7.3 | 3.7.3 |
| Mainboard UART | `/dev/ttyS0`, 500000 baud | same |
| Toolhead UART | `/dev/ttyS2`, 500000 baud | same |
| MCU restart | Klipper `command` | same |
| Serial gettys | disabled | disabled |
| Passwordless sudo | available | available |
| `/root/hid-flash` SHA-256 | `22a3b082...3a2519` | identical |
| Mainboard and toolhead flash | identical across releases | identical |

The installed Klipper and Moonraker Git commits are also identical. QIDI's
release differences primarily live in untracked/compiled components and update
payloads. Debian 10 and Python 3.7 are not a sensible foundation for a current
Moonraker installation, so this guide does not attempt an in-place OS upgrade.

The official Armbian Qidi X-6 image has not yet been boot-tested on `qidi1` or
`qidi2`. Its upstream board definition explicitly lists the Plus4, but the
new-host UART and network checks remain a mandatory gate before MCU work.

## Compatibility boundaries

### QIDI Box

Leave the QIDI Box MCU on stock firmware. Its host integration depends on
QIDI's compiled Klipper extensions, which cannot be copied into mainline.
`qidi1` will therefore lose Box functionality until the open backend described
in [HAPPY-HARE-INTEGRATION.md](HAPPY-HARE-INTEGRATION.md) is ready. Do not flash
a generic Klipper image to the Box; its stock application includes RFID and
protocol behavior that mainline does not provide.

### MCU names change

Stock calls the toolhead `[mcu]` and mainboard `[mcu U_1]`. Mainline should use:

```ini
[mcu]
serial: /dev/ttyS0
baud: 500000
restart_method: command

[mcu Toolhead]
serial: /dev/ttyS2
baud: 500000
restart_method: command
```

Do not copy stock pin references unchanged without accounting for that rename.

### Touchscreen

The stock touchscreen does not speak directly to mainline Klipper. This
dependency-minimal path is initially headless: use Moonraker with a web UI or a
network-connected KlipperScreen. FreeDi display support remains an optional
later choice, not a migration prerequisite, and this workflow does not alter
display firmware. An independent, non-critical-path replacement for QIDI's
`xindi` daemon is scaffolded in [SCREEN-BRIDGE.md](SCREEN-BRIDGE.md).

## Equipment

- Spare compatible eMMC module and an eMMC USB reader.
- ST-Link V2 or compatible programmer.
- Four female jumper leads for GND, SWDIO, SWCLK, and RESET.
- Ethernet for the replacement host's first boot.
- Linux or WSL for reproducible MCU builds.

Keeping the original eMMC untouched is the simplest host rollback.

## 1. Back up and audit

Use the cross-platform Python backup and audit commands:

```powershell
python .\tools\migration\qidi_plus4.py backup --printer qidi1 --name qidi1
python .\tools\migration\qidi_plus4.py backup --printer qidi2 --name qidi2
python .\tools\migration\qidi_plus4.py audit --printer qidi1
python .\tools\migration\qidi_plus4.py audit --printer qidi2
```

Compare flasher hashes, UARTs, baud rates, and sudo results with the table above.
Stop if they differ. A filesystem backup does not replace the retained MCU dumps
under `data/printer-backups/*/mcu-dumps/`.

## 2. Prepare official Armbian

The Qidi X-6 controller became an official Armbian community board in March
2026. Its upstream definition explicitly lists the Plus4, so the host no longer
depends on FreeDi or an old Armbian fork.

Download the current official Debian 13 minimal image and verify Armbian's
published SHA-256:

```powershell
python .\tools\migration\qidi_plus4.py armbian-image --list-only
python .\tools\migration\qidi_plus4.py armbian-image
```

Alternatively, reproduce it from the official build framework:

```bash
git clone https://github.com/armbian/build.git
cd build
./compile.sh BOARD=qidi-x6 RELEASE=trixie \
  BUILD_DESKTOP=no BUILD_MINIMAL=yes KERNEL_CONFIGURE=no
```

Write the decompressed image to the spare eMMC with Armbian Imager or another
normal disk imager. Do not overwrite the mounted stock root disk with `dd` over
SSH; two eMMC screws are preferable to a half-written filesystem.

## 3. Build MCU firmware

Under Linux or WSL:

```bash
git clone https://github.com/Klipper3d/klipper.git ~/klipper-mainline
git clone https://github.com/Arksine/katapult.git ~/katapult

python3 tools/migration/qidi_plus4.py build \
  --klipper-dir ~/klipper-mainline \
  --katapult-dir ~/katapult
```

The command builds and locally validates:

- `plus4-mainboard-klipper.bin` at `0x08008000`;
- `plus4-toolhead-katapult.bin` at `0x08000000`;
- `plus4-toolhead-klipper.bin` at `0x08002000`.

Outputs, SHA-256 hashes, and source commits are recorded below
`artifacts/mainline-firmware/`. Existing `.config` files are restored.

Validate the images against a stock printer before any flash:

```powershell
python .\tools\migration\qidi_plus4.py validate-mainboard `
  --printer qidi1 --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin
python .\tools\migration\qidi_plus4.py validate-toolhead-katapult `
  --printer qidi1 --image .\artifacts\mainline-firmware\plus4-toolhead-katapult.bin
python .\tools\migration\qidi_plus4.py validate-toolhead `
  --printer qidi1 --image .\artifacts\mainline-firmware\plus4-toolhead-klipper.bin
```

## 4. Experimental SSH mainboard flash

Run this while the stock host is healthy:

```powershell
python .\tools\migration\qidi_plus4.py flash-mainboard `
  --printer qidi1 `
  --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin `
  --confirm FLASH-MAINBOARD
```

The helper validates the vector layout and SHA-256, refuses an unknown QIDI
flasher, requests `FIRMWARE_RESTART`, stops Klipper, and invokes the verified
flasher on `ttyS0`. It preserves QIDI's resident 32 KiB bootloader and leaves
the old Klipper host stopped after success.

The evidence is strong—the same flasher exists on both printers, and the
recovered QIDI/FreeDi flows use the same restart-plus-flasher sequence—but this
specific migration path remains experimental until recovery-tested here. The
established FAT32 `qd_mcu.bin` route remains the conservative fallback.

After a successful flash, shut down and power off.

## 5. Replace and bootstrap the host

Open the rear cover once, replace the stock eMMC with the prepared spare, refit
its two screws, and boot with Ethernet connected. Complete Armbian's initial
root-password and regular-user setup. Use `mks` as the regular user if you want
the documented defaults unchanged, then configure passwordless sudo.

Bootstrap the upstream host stack without KIAUH or FreeDi:

```powershell
python .\tools\migration\qidi_plus4.py bootstrap-host `
  --printer qidi1 --confirm BOOTSTRAP-HOST
```

The checked-in bootstrap installs Debian packages, clones official Klipper,
Moonraker, and Katapult, creates Python environments and systemd services, and
sets UART permissions. It leaves Klipper stopped until `printer.cfg` is reviewed.
For a repeatable install, pass commit IDs with `--klipper-ref`,
`--moonraker-ref`, and `--katapult-ref`; the installed commits are always
recorded in `~/printer_data/mainline-bootstrap.txt`.

Log out and back in, then verify:

```bash
ls -l /dev/ttyS0 /dev/ttyS2
systemctl is-enabled serial-getty@ttyS0.service serial-getty@ttyS2.service
git -C ~/klipper rev-parse HEAD
git -C ~/moonraker rev-parse HEAD
git -C ~/katapult rev-parse HEAD
```

The official Qidi X-6 board definition supplies the device tree. Do not apply
old fork-specific UART overlays unless the new-host audit proves one is missing.

## 6. Install Katapult on the toolhead once

Power off and slide off the toolhead rear cover. With the board installed,
connect these temporary wires:

| Toolhead J1 | ST-Link |
|---|---|
| Pin 1 | SWDIO |
| Pin 3 | SWCLK |
| Pin 5 | RESET |
| Pin 6 | GND |

Leave pins 2 and 4 unconnected while the printer powers the toolhead. Secure the
contacts so they cannot move or short. Boot the printer, wait for the host, then
plug the ST-Link into the top USB port.

```powershell
python .\tools\migration\qidi_plus4.py flash-toolhead-katapult `
  --printer qidi1 `
  --image .\artifacts\mainline-firmware\plus4-toolhead-katapult.bin `
  --confirm ERASE-TOOLHEAD
```

The helper requires an STM32F1 probe, reads the existing 64 KiB flash to a
timestamped backup, writes Katapult, and verifies a read-back. Power off,
disconnect ST-Link and temporary wires, and replace the cover.

## 7. Flash toolhead Klipper

Boot again:

```powershell
python .\tools\migration\qidi_plus4.py flash-toolhead `
  --printer qidi1 `
  --image .\artifacts\mainline-firmware\plus4-toolhead-klipper.bin `
  --confirm FLASH-TOOLHEAD
```

This flashes the `0x08002000` application over `/dev/ttyS2` at 500000 baud.
Future toolhead updates can use the same SSH action without ST-Link.

## 8. Configuration and cold commissioning

Start from a reviewed current mainline Plus4 configuration, not the QIDI fork
configuration verbatim. Merge only understood hardware values from the backups.

Before enabling heaters or normal-speed movement:

1. Confirm both MCUs connect at 500000 baud.
2. Verify every thermistor reports plausible room temperature.
3. Query and manually trigger every endstop.
4. Verify fan outputs individually.
5. Verify heater pins and sensors before PID calibration.
6. Preserve chamber-heater power limits from the exact printer revision.
7. Home one axis at a time at reduced speed, with access to the power switch.
8. Calibrate PID, Z offset, mesh, and input shaping before printing.

Do not enable QIDI Box includes on `qidi1` until a mainline backend exists.

## Rollback

Reinstalling the untouched stock eMMC restores the host. MCU rollback requires:

- mainboard: QIDI's `qd_mcu.bin` through its microSD bootloader;
- toolhead: a stock-compatible **8 KiB-offset** image through Katapult, or the
  saved full image through ST-Link;
- display: no action, because this workflow never flashes it.

Keep per-printer dumps and the new ST-Link read-back. Do not assume a binary
from another hardware batch is interchangeable.

## Sources and freshness

- [Official Armbian Qidi X-6 page](https://www.armbian.com/boards/qidi-x6)
- [Official Armbian Qidi X-6 board definition](https://github.com/armbian/build/blob/main/config/boards/qidi-x6.csc)
- [plus4_kalico at reviewed commit 00fc3e5](https://github.com/phrac/plus4_kalico/tree/00fc3e54bdf2ac5db72b34dc63c63063be804fdb)
- [FreeDi reference at facb670](https://github.com/Phil1988/FreeDi/tree/facb6707e22d1194ed3a4f6c84ea549732a99da3)
- [Plus4 mainline configuration reference at e355154](https://github.com/cgarwood82/plus4MainlineKlipperConfig/tree/e3551541f66860658de280b99f8c915a2bff5d34)
- [Katapult at reviewed commit ec59b9b](https://github.com/Arksine/katapult/tree/ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e)
- [Official Klipper installation documentation](https://www.klipper3d.org/Installation.html)
- [Official Klipper bootloader documentation](https://www.klipper3d.org/Bootloaders.html)

Community guides are reference points, not authority. Re-run `audit` immediately
before each migration and verify all hardware assumptions against that printer.
