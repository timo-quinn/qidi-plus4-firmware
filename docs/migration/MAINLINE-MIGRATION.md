# QIDI Plus4 mainline Klipper migration

This guide combines current community work with measurements from representative
QIDI Plus4 systems. It minimizes disassembly, avoids appliance firmware
dependencies, and keeps a straightforward stock recovery path.

> **Status:** audit, build, download, and validation paths are non-destructive.
> Repeated live tests disproved the proposed direct SSH mainboard flash: QIDI's
> UART loader did not acknowledge and its flasher returned a false-success exit
> status. The command is disabled. Mainboard migration uses the established
> microSD bootloader route; destructive toolhead commands still require exact
> confirmation phrases and validate their inputs before touching an MCU.

The [2026-10-04 QIDI1 review](../history/QIDI1-MIGRATION-REVIEW-2026-10-04.md) records
current upstream changes and local preparation gaps. In particular, do not use
Printerlab's automatic resume as proof that a stock configuration is already a
commissioned mainline configuration. Use explicit stages until that probe is
corrected.

## Recommended route

1. Back up the printer and retain complete MCU dumps.
2. Download the official Armbian Qidi X-6 image and prepare a spare eMMC.
3. Build matching mainline Klipper and Katapult images from source.
4. Copy the built mainboard image to a FAT32 microSD card as `qd_mcu.bin`,
   flash it through the mainboard's resident bootloader, and verify that the
   file is renamed to `qd_mcu.CUR`.
5. Power off, remove the microSD card, and swap in the prepared eMMC.
6. Bootstrap official Klipper, Moonraker, and Katapult over SSH.
7. Attach temporary ST-Link wires to the toolhead board — in place, or removed
   and powered from the ST-Link's 3.3 V pin — install Katapult once,
   disconnect it, and flash toolhead Klipper over SSH.
8. Install a reviewed mainline configuration and perform cold commissioning.
9. After single-material printing is proven, install and commission Happy Hare
   using [HAPPY-HARE-INSTALLATION.md](HAPPY-HARE-INSTALLATION.md).

This avoids soldering; the toolhead board can be flashed in place or removed
for easier wiring access. It is not physically hands-off: the mainboard needs
a microSD card, the stock toolhead has no bootloader, and safely changing the
host OS still means swapping the eMMC.

## Validated reference baseline

Read-only SSH checks were run on 2026-07-13.

The extended hardware, USB, boot, screen, and runtime comparison is recorded in
[LIVE-HARDWARE-INVENTORY.md](../firmware/LIVE-HARDWARE-INVENTORY.md).

| Property | Verified reference finding |
|---|---|
| QIDI releases sampled | 1.7.3 without QIDI Box; 1.8.2 with QIDI Box |
| Controller PCB | X-7 V1.0 on both systems |
| Host | Debian 10, kernel 5.16.20-rockchip64 |
| Python | 3.7.3 |
| Mainboard UART | `/dev/ttyS0`, 500000 baud |
| Toolhead UART | `/dev/ttyS2`, 500000 baud |
| MCU restart | Klipper `command` |
| Serial gettys | disabled |
| Passwordless sudo | available |
| `/root/hid-flash` SHA-256 | `22a3b082...3a2519`, identical on both systems |
| Mainboard and toolhead flash | identical across sampled releases |
| Mainboard microSD migration | Mainline image accepted and renamed to `qd_mcu.CUR` on the 1.7.3 X-7 reference printer |
| Toolhead migration | Katapult installed after a full SWD erase; mainline Klipper written and verified over `/dev/ttyS2` on the same reference printer |

The installed Klipper and Moonraker Git commits are also identical. QIDI's
release differences primarily live in untracked/compiled components and update
payloads. Debian 10 and Python 3.7 are not a sensible foundation for a current
Moonraker installation, so this guide does not attempt an in-place OS upgrade.

Armbian is now boot-tested on the migrated reference printer. A read-only check
on 2026-10-04 found Debian 13, Armbian 26.11.0-trunk.68, kernel
6.18.54-current-rockchip64, both UART MCUs connected, and Klipper ready. This
is a working nightly installation, not a qualification of every downloadable
image. Check the replacement host's UARTs and network before toolhead work, and
audit every target printer against the retained hardware baseline.

## Compatibility boundaries

### QIDI Box

Leave the QIDI Box MCU on stock firmware. Its host integration depends on
QIDI's compiled Klipper extensions, which cannot be copied into mainline.
A printer currently using a QIDI Box will therefore lose Box functionality
until the open backend described in
[HAPPY-HARE-INTEGRATION.md](../integrations/HAPPY-HARE-INTEGRATION.md) is ready. Do not flash a
generic Klipper image to the Box; its stock application includes RFID and
protocol behavior that mainline does not provide.

### MCU names

The reviewed full profile retains QIDI's conventional names: toolhead `[mcu]`
on `/dev/ttyS2` and mainboard `[mcu U_1]` on `/dev/ttyS0`. The inert smoke test
uses different names to isolate the connectivity check:

```ini
[mcu]
serial: /dev/ttyS0
baud: 500000
restart_method: command

[mcu toolhead]
serial: /dev/ttyS2
baud: 500000
restart_method: command
```

Use the full profile's names consistently with its pin references. The smoke
test has no pin definitions and must not be extended into the full profile by
copying hardware sections without reviewing their MCU prefixes.

### Touchscreen

The stock touchscreen does not speak directly to mainline Klipper. This
dependency-minimal path is initially headless: use Moonraker with a web UI or a
network-connected KlipperScreen. FreeDi display support remains an optional
later choice, not a migration prerequisite, and this workflow does not alter
display firmware. An independent, non-critical-path replacement for QIDI's
`xindi` daemon is scaffolded in [SCREEN-BRIDGE.md](../integrations/SCREEN-BRIDGE.md).

## Equipment

- Spare compatible eMMC module and an eMMC USB reader.
- ST-Link V2 or compatible programmer.
- Four female jumper leads for GND, SWDIO, SWCLK, and RESET, plus a fifth
  3.3 V lead if the toolhead board will be removed and powered by the ST-Link.
- Ethernet for the replacement host's first boot.
- Linux or WSL for reproducible MCU builds.

Keeping the original eMMC untouched is the simplest host rollback.

## Command variables

The PowerShell examples below use variables so the same instructions work with
any printer. Set `$Printer` to a resolvable hostname or IP address and choose a
unique, filesystem-safe label for `$BackupName`:

```powershell
$Printer = 'plus4.local'
$BackupName = 'my-plus4'
```

The migration tool defaults to the `mks` SSH user. Add `--user <username>` to
commands if your printer uses a different account. If the hostname or address
changes after replacing the host OS, update `$Printer` before continuing.

### Avoid repeated password prompts

Each phase opens several SSH and SCP connections, so password authentication
prompts for the printer password many times over a full migration. Install an
SSH key once to make every later command password-free:

```powershell
python .\tools\migration\qidi_plus4.py setup-ssh --printer $Printer --generate
```

This prompts for the printer password a single time, installs your public key
(creating an `ed25519` key first if you have none), and verifies key-based
login. If it reports a non-default key path, pass that path as `--identity` to
the other commands; a standard `~/.ssh/id_ed25519` is picked up automatically.
On Linux and macOS the tool additionally reuses one SSH connection per phase, so
even without a key you are prompted at most once per command. Re-run `setup-ssh`
after the host OS is replaced, because the new Armbian install has its own host
key and account.

When Printerlab orchestrates this first login, configure the printer entry with
a dedicated `identityFile` and a temporary `sshPasswordEnv` name, then run
`plab mainline setup-ssh <printer> --generate`. Printerlab supplies the password
only through its private randomized askpass gate; this utility accepts the
environment variable name, never the password as an argument. Remove
`sshPasswordEnv` and clear the environment variable immediately after the key
is installed.

## 1. Back up and audit

Use the cross-platform Python backup and audit commands:

```powershell
python .\tools\migration\qidi_plus4.py backup --printer $Printer --name $BackupName
python .\tools\migration\qidi_plus4.py audit --printer $Printer
```

Compare flasher hashes, UARTs, baud rates, and sudo results with the table above.
Stop if they differ. A filesystem backup does not replace the retained MCU dumps
under `data/printer-backups/<backup-name>/mcu-dumps/`. Repeat the backup and audit
with distinct variable values for each additional printer.

## 2. Prepare official Armbian

The Qidi X-6 controller became an official Armbian community board in March
2026. Its upstream definition explicitly lists the Plus4, so the host no longer
depends on FreeDi or an old Armbian fork.

The board was promoted to standard support on 2026-08-13; its definition is
now `config/boards/qidi-x6.conf`. Record the resolved image filename and kernel
version as well as its checksum. The download alias may resolve to an older
kernel than the working reference printer; see the dated review before choosing
an image.

Download the current official Debian 13 minimal image and verify Armbian's
published SHA-256:

```powershell
python .\tools\migration\qidi_plus4.py armbian-image --list-only
python .\tools\migration\qidi_plus4.py armbian-image
```

The downloader resolves the alias before transfer, preserves the exact image
filename, and rejects kernels older than the reviewed default `6.18.54`.
Use `--url <exact-HTTPS-image>` for a selected build. Its checksum and kernel
record establish download integrity; boot, device-tree and UART checks on the
replacement eMMC remain required.

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

Under Debian, Ubuntu, or WSL, install the native build tools and ARM embedded
toolchain first:

```bash
sudo apt-get update
sudo apt-get install -y \
  git build-essential cpp \
  gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi
```

Confirm that the cross-compiler is available:

```bash
arm-none-eabi-gcc --version
```

Then clone the upstream sources and build the three MCU images:

```bash
git clone https://github.com/Klipper3d/klipper.git ~/klipper-mainline
git clone https://github.com/Arksine/katapult.git ~/katapult
git -C ~/klipper-mainline checkout --detach 214fdb2877ff4640e9316a663c1b8b2e232c86fd
git -C ~/katapult checkout --detach ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e

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
  --printer $Printer --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin
python .\tools\migration\qidi_plus4.py validate-toolhead-katapult `
  --printer $Printer --image .\artifacts\mainline-firmware\plus4-toolhead-katapult.bin
python .\tools\migration\qidi_plus4.py validate-toolhead `
  --printer $Printer --image .\artifacts\mainline-firmware\plus4-toolhead-klipper.bin
```

## 4. Flash the mainboard with microSD

Use a microSD card with a single FAT32 partition no larger than 32 GiB. Remove
other partitions and hidden volumes, then stage the mainboard image onto the
card root. The `stage-mainboard-sdcard` action re-validates the image's vectors,
copies it to the exact filename `qd_mcu.bin`, and records its SHA-256 so the
wrong image or filename cannot be flashed by accident:

```powershell
python .\tools\migration\qidi_plus4.py stage-mainboard-sdcard `
  --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin `
  --output E:\
```

Replace `E:\` with the verified microSD volume root. Safely eject it, shut the printer
down, wait for power to discharge, insert the card into the mainboard, and turn
the printer on. Leave it powered for at least 60 seconds. Turn it off, remove
the card, and inspect it on the computer. Continue only if the bootloader
renamed the file to `qd_mcu.CUR`.

The recovered 1.7.3 mainboard image contains the literal paths
`1:/qd_mcu.bin` and `1:/qd_mcu.CUR`. The built mainline image is linked at
`0x08008000`, matching the stock application vector and preserving QIDI's
resident 32 KiB bootloader. This direct application route is simpler than
installing a mainboard Katapult deployer, at the cost of requiring the microSD
card again for future mainboard firmware updates.

This exact route was completed on the 1.7.3 X-7 reference printer on
2026-07-13. The bootloader renamed the built mainline application from
`qd_mcu.bin` to `qd_mcu.CUR`, providing the required on-card success marker.

### Why the direct SSH route is disabled

Three live attempts on the recovered 1.7.3 reference printer reached
`/root/hid-flash` but received no bootloader `OK` response. Tests covered an
ordinary firmware restart, Klipper's exact 32-byte serial bootloader request,
and an aligned request after clearing partial protocol data. Every attempt
failed before `> Flashing firmware...`; the stock application remained healthy.

The QIDI flasher also returned process status zero after printing a protocol
timeout. The migration command now refuses to run so that this false success
cannot encourage a power-off or host swap. The retained implementation remains
analysis evidence, not an available migration action.

## 5. Replace and bootstrap the host

Open the rear cover once, replace the stock eMMC with the prepared spare, refit
its two screws, and boot with Ethernet connected. Complete Armbian's initial
root-password and regular-user setup. Use `mks` as the regular user if you want
the documented defaults unchanged, then configure passwordless sudo.

Bootstrap the upstream host stack without KIAUH or FreeDi:

```powershell
python .\tools\migration\qidi_plus4.py bootstrap-host `
  --printer $Printer --confirm BOOTSTRAP-HOST
```

The checked-in bootstrap installs Debian packages, clones official Klipper,
Moonraker, and Katapult, creates Python environments and systemd services, and
sets UART permissions. It also installs persistent RK3328 latency tuning:

- the CPU frequency governor is set to `performance`;
- Klipper is restricted to CPUs 1 and 2;
- the toolhead `/dev/ttyS2` IRQ is routed to CPU 1;
- the mainboard `/dev/ttyS0` IRQ is routed to CPU 2;
- Moonraker and known UI/camera services are restricted to CPUs 0 and 3; and
- `irqbalance` and Debian's late `ondemand.service` are masked when installed
  so they cannot undo the UART assignments or governor.

The governor is applied before Klipper starts. UART IRQs do not necessarily
exist until Klipper opens both serial devices, so a strict post-start hook waits
for them and applies their affinities on every Klipper restart. The hook also
waits through the 60-second boot-settle interval used by QIDI's original tuning
script, because Armbian's hardware optimizer can continue changing host state
after its systemd unit reports completion. If the hook cannot verify both IRQs,
Klipper does not complete startup.

It leaves Klipper stopped until `printer.cfg` is reviewed.
For a repeatable install, pass commit IDs with `--klipper-ref`,
`--moonraker-ref`, and `--katapult-ref`; the installed commits are always
recorded in `~/printer_data/mainline-bootstrap.txt`.

Use the same Klipper commit recorded in the MCU build's `BUILD-METADATA.txt` for
`--klipper-ref`, and likewise pin Katapult. Build and bootstrap default to the
reviewed full commits recorded in the October 2026 fix report. Moving refs and
abbreviated SHAs are rejected. Pass `--artifacts <build-directory>` to verify
all three hashes and require bootstrap commits to match the MCU build.
Printerlab bootstrap and resume pass this directory automatically.
`--printer-user mks --user plab` now executes bootstrap as `mks` through sudo
and streams its helpers without placing files in the management account's home.

Bootstrap performs `audit-early` while Klipper is stopped. Smoke-test performs
the full runtime tuning audit after both UARTs connect; neither a short log tail
nor an early IRQ assignment substitutes for that check.

Use `--beacon-ref <full-commit>` to install the Beacon host plugin. This option
installs requirements and its Klipper module without invoking upstream
`install.sh`, which also updates probe firmware. Probe firmware remains a
separate hardware operation. Shake&Tune and the web frontend remain optional
host setup steps. Existing companion screens can continue to use Moonraker.

Log out and back in, then verify:

```bash
ls -l /dev/ttyS0 /dev/ttyS2
systemctl is-enabled serial-getty@ttyS0.service serial-getty@ttyS2.service
git -C ~/klipper rev-parse HEAD
git -C ~/moonraker rev-parse HEAD
git -C ~/katapult rev-parse HEAD
```

Audit the effective governor, process affinity, and UART IRQ routing from the
workstation:

```powershell
python .\tools\migration\qidi_plus4.py audit-host-tuning --printer $Printer
```

Printers bootstrapped by an older checkout can be patched without reflashing an
MCU:

```powershell
python .\tools\migration\qidi_plus4.py tune-host `
  --printer $Printer --confirm TUNE-HOST
```

The patch is idempotent and refuses to restart Klipper or Moonraker while a job
is printing or paused. Klipper requires the early governor service and remains
failed if its post-start UART affinity hook cannot verify both IRQs. The patch
deliberately does not relax Klipper's scheduling checks or change the
500000-baud MCU firmware.

The official Qidi X-6 board definition supplies the device tree. Do not apply
old fork-specific UART overlays unless the new-host audit proves one is missing.

## 6. Install Katapult on the toolhead once

Power off and slide off the toolhead rear cover. Both wiring options below
have been used on live migrations. Either way, the printer host runs the flash
helper, so the printer must be booted with the ST-Link in the top USB port
before flashing.

**Option A — board installed** (validated on the reference printer): connect
these temporary wires:

| Toolhead J1 | ST-Link |
|---|---|
| Pin 1 | SWDIO |
| Pin 2 | 3.3 V (Option B only) |
| Pin 3 | SWCLK |
| Pin 5 | RESET |
| Pin 6 | GND |

Leave pins 2 and 4 unconnected while the printer powers the toolhead. Secure the
contacts so they cannot move or short. Boot the printer, wait for the host, then
plug the ST-Link into the top USB port.

**Option B — board removed** (validated on the second migrated printer):
unplug the toolhead harness and remove the board for unobstructed access to
J1. Connect the same SWDIO, SWCLK, RESET, and GND wires, plus a fifth wire
from the ST-Link's 3.3 V pin to J1 pin 2 so the programmer powers the bare
board. Never feed ST-Link power into a board that is still connected to the
printer harness — the board must have exactly one power source. Boot the
printer, wait for the host, then plug the ST-Link into the top USB port.

```powershell
python .\tools\migration\qidi_plus4.py flash-toolhead-katapult `
  --printer $Printer `
  --image .\artifacts\mainline-firmware\plus4-toolhead-katapult.bin `
  --confirm ERASE-TOOLHEAD
```

The wrapper requires an STM32F1 probe, reads the existing 64 KiB flash, and
copies it with a verified checksum to workstation `data/printer-backups/`
(or `--backup-output`). It refuses erase if transfer, size or checksum checks
fail. The helper reads the attached board again and requires it to match that
workstation dump before it erases the chip, writes Katapult, verifies its
read-back, and confirms that Katapult's application vector at `0x08002000` is
blank. The erase is necessary because stock QIDI Klipper is linked at
`0x08000000`; leaving its old bytes in the new application slot makes Katapult
jump into stale code instead of waiting on the UART. In the captured stock
toolhead dump, `0x08002000` begins `e3 69 33 b1 00 22 19 68`, which Katapult's
nonblank application test accepts even though it is not an offset-correct
vector table. Power off, disconnect the ST-Link and temporary wires, refit and
reconnect the board if it was removed, and replace the cover. The board must
be back on the printer harness before the next step: toolhead Klipper is
flashed over the printer's UART, not over SWD.

## 7. Flash toolhead Klipper

Boot again:

```powershell
python .\tools\migration\qidi_plus4.py flash-toolhead `
  --printer $Printer `
  --image .\artifacts\mainline-firmware\plus4-toolhead-klipper.bin `
  --confirm FLASH-TOOLHEAD
```

This flashes the `0x08002000` application over `/dev/ttyS2` at 500000 baud.
Future toolhead updates can use the same SSH action without ST-Link.

This route was completed on the 1.7.3 X-7 reference printer on 2026-07-14.
Katapult wrote all 39 application pages and verified the programmed image with
its reported SHA `4161AC2A68441678A4659D5262C5E4ACC9F6CCFB`. A second Plus4
was later migrated using Option B: the toolhead board was removed and powered
from the ST-Link's 3.3 V pin for the Katapult install, then reinstalled for
the UART Klipper flash.

## 8. Configuration and cold commissioning

Start from a reviewed current mainline Plus4 configuration, not the QIDI fork
configuration verbatim. Merge only understood hardware values from the backups.

First install the inert two-MCU smoke-test configuration. It contains no pin,
motor, heater, fan, probe, or endstop definitions, so its only purpose is to
confirm both UART firmware links. The `smoke-test` action backs up any existing
`printer.cfg`, installs the inert configuration, restarts mainline Klipper, and
prints the recent `klippy.log` so you can see both MCUs reach `Ready`:

```powershell
python .\tools\migration\qidi_plus4.py smoke-test --printer $Printer
```

The equivalent manual steps, if you prefer them, are:

```powershell
scp .\tools\migration\smoke-test-printer.cfg `
  "mks@${Printer}:/home/mks/printer_data/config/printer.cfg"
ssh "mks@$Printer" 'sudo systemctl restart klipper'
```

For a fuller picture, check Moonraker's view of Klipper:

```bash
api_key="$(~/moonraker/scripts/fetch-apikey.sh)"
curl -s -H "X-Api-Key: $api_key" \
  http://127.0.0.1:7125/server/info | python3 -m json.tool
grep -E "Loaded MCU|MCU '.*' config|Printer is ready" \
  ~/printer_data/logs/klippy.log | tail -n 20
```

Fresh installs made by the bootstrap trust only the IPv4 and IPv6 loopback
ranges, so the API-key header is normally redundant for commands run on the
host. It is retained in this diagnostic because it also works with an existing
Moonraker configuration that does not trust localhost. LAN clients remain
untrusted until the owner deliberately configures authentication or appropriate
`trusted_clients` ranges.

Continue only when `/server/info` reports `klippy_connected: true` and
`klippy_state: ready`, and the smoke-test log has loaded both `mcu` on
`/dev/ttyS0` and `toolhead` on `/dev/ttyS2`. The reviewed full profile follows
QIDI's conventional names instead: its primary `mcu` is the toolhead on
`/dev/ttyS2`, and `U_1` is the mainboard on `/dev/ttyS0`. The `/printer/info`
endpoint is provided through Klippy and may return 404 before that connection
exists, so it is not used as the initial health check. Moonraker may list
`pause_resume`, `display_status`, and `virtual_sdcard` under
`missing_klippy_requirements` during this test; those sections are deliberately
absent from the inert configuration and will be supplied by the full printer
configuration.

This smoke-test file is not a printable machine configuration. Render the
reviewed X-7 V1.0 / Beacon profile with the target printer's exact by-id path:

```powershell
python .\tools\migration\qidi_plus4.py render-config `
  --commissioning `
  --profile-dir ..\qidi-plus4-configs\printers\mainline-klipper-beacon `
  --beacon-serial '/dev/serial/by-id/usb-Beacon_Beacon_RevH_CHANGE_ME-if00' `
  --output C:\printerlab-workspaces\my-plus4-mainline
```

`qidi-plus4-configs` is the preferred source for sanitized setup profiles;
per-printer state belongs in Klippee and that printer's workspace.
Omit `--profile-dir` to use this repository's bundled compatibility fallback.
Read the generated files and follow the selected profile's commissioning notes;
the fallback is documented in
[`../../mainline-configs/plus4-x7-v1.0-beacon/README.md`](../../mainline-configs/plus4-x7-v1.0-beacon/README.md).
With `--commissioning`, the generated root includes only hardware and Beacon,
uses conservative uncalibrated settings, and excludes the production layer.
Without that option, the full example retains source-printer tuning and
service-area moves. Review the selected profile and recalibrate the target
printer before enabling the operating layer.

Before enabling heaters or normal-speed movement:

1. Confirm both MCUs connect at 500000 baud.
2. Verify every thermistor reports plausible room temperature.
3. Query and manually trigger every endstop.
4. Verify fan outputs individually.
5. Verify heater pins and sensors before PID calibration.
6. Preserve chamber-heater power limits from the exact printer revision.
7. Home one axis at a time at reduced speed, with access to the power switch.
8. Calibrate PID, Z offset, and mesh before enabling the operating layer.
9. Calibrate input shaping before raising the conservative motion limits.

Do not enable QIDI Box includes until a reviewed mainline backend exists.

Beacon's current `update_firmware.py` is directly executable with an
`/usr/bin/env python` shebang. Minimal Armbian images may initially provide only
`python3`, which causes a non-fatal updater exit status 127 during Klipper
startup even though Beacon connects. The current bootstrap installs
`python-is-python3`; on a host bootstrapped earlier, install it once and restart
Klipper:

```bash
sudo apt-get update
sudo apt-get install -y python-is-python3
sudo systemctl restart klipper
```

Happy Hare is an optional post-migration layer. Do not install it until the
printer passes this commissioning sequence. A supported third-party MMU can
then follow [HAPPY-HARE-INSTALLATION.md](HAPPY-HARE-INSTALLATION.md); the QIDI
Box remains behind the compatibility boundary described above.

The profile's `operations.cfg` supplies the normal single-material print,
pause/resume/cancel, fan and chamber contract. Additional dependency-free
macros and separate Beacon/Happy Hare templates are scaffolded under
[`../../mainline-addons/`](../../mainline-addons/). Enable those one at a time only
after the base printer is commissioned.

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
- [Official Armbian Qidi X-6 board definition](https://github.com/armbian/build/blob/main/config/boards/qidi-x6.conf)
- [plus4_kalico at reviewed commit 00fc3e5](https://github.com/phrac/plus4_kalico/tree/00fc3e54bdf2ac5db72b34dc63c63063be804fdb)
- [FreeDi reference at facb670](https://github.com/Phil1988/FreeDi/tree/facb6707e22d1194ed3a4f6c84ea549732a99da3)
- [Plus4 mainline configuration reference at e355154](https://github.com/cgarwood82/plus4MainlineKlipperConfig/tree/e3551541f66860658de280b99f8c915a2bff5d34)
- [Katapult at reviewed commit ec59b9b](https://github.com/Arksine/katapult/tree/ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e)
- [Beacon Klipper at reviewed commit 7c71e98](https://github.com/beacon3d/beacon_klipper/tree/7c71e984abfa889721b36409989ed34067d40240)
- [Official Beacon quick start](https://docs.beacon3d.com/quickstart/)
- [Official Klipper installation documentation](https://www.klipper3d.org/Installation.html)
- [Official Klipper bootloader documentation](https://www.klipper3d.org/Bootloaders.html)

Community guides are reference points, not authority. Re-run `audit` immediately
before each migration and verify all hardware assumptions against that printer.
