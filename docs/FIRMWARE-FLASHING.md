# QIDI Plus4 firmware update and MCU flashing paths

This report describes how the QIDI 1.7.3 and 1.8.2 software installs host,
touchscreen, mainboard and QIDI Box firmware. It is based on the regenerated
printer backups, readable scripts, the source shipped with QIDI's modified
STM32 flasher, and named-function decompilation of the unstripped `xindi`
binary.

Do not run the commands in this report directly. The update code assumes QIDI
bootloaders, UART routing and firmware layouts; an incorrect image can leave a
board requiring physical recovery.

## Summary

| Target | Input | Coordinator | Transport/install method |
| --- | --- | --- | --- |
| Linux/SoC application | `QD_Plus4_SOC*` or `QD_Plus4_PATCH*` | `xindi` | Renamed to `mks.deb`, installed as root with `dpkg -i --force-overwrite` |
| Touchscreen | `QD_Plus4_UI*` or `mksscreen.recovery` | `xindi` | Copied to `/root/800_480.tft`, transferred by `/root/uart` over `/dev/ttyS1` |
| Mainboard MCU (`mcu U_1`) | `USB/QD_MCU/MCU` | `xindi` | QIDI HID/UART flasher over `ttyS0` |
| QIDI Box MCU | `/home/mks/mcu_box_to_v1_*.bin` | compiled `box_detect` plus shell script | Klipper reset command, USB bootloader enumeration, framed HID/UART flasher |
| Toolhead MCU (`mcu`) | live flash dump | — | Stock image starts at flash base; no bootloader/updater targeting `/dev/ttyS2` |

The stock names are counterintuitive. Pin ownership shows that `[mcu]` on
`/dev/ttyS2` is the toolhead: it owns the extruder, hotend, toolhead sensors
and ADXL345. `[mcu U_1]` on `/dev/ttyS0` is the mainboard: it owns XY/Z,
bed, chamber and case I/O. Therefore `QD_MCU/MCU` is a **mainboard update**.

## Update coordinator and privilege level

The touchscreen application runs through `makerbase-client.service`. The unit
does not set `User=`, so systemd runs it as root. Its startup script launches:

```text
/root/xindi/build/xindi localhost
```

The 1.8.2 binary is an unstripped ARM64 C++ executable. Relevant retained
functions include `detect_update`, `start_update`, `install_update`,
`update_system`, `check_offline_update`, `u_disk_update`,
`close_mcu_port`, `reset_firmware` and `firmware_reset`.

The equivalent update functions in the 1.7.3 and 1.8.2 binaries have identical
machine-code sizes. The main visible path change is the removable-media mount
from the older `sda1` form to 1.8.2's `USB` path.

## Offline USB update discovery

`detect_update()` scans the mounted USB G-code directory and sets flags based
on filename prefixes and fixed paths. Recognized inputs include:

```text
USB/QD_Update/QD_Plus4_SOC*
USB/QD_Update/QD_Plus4_PATCH*
USB/QD_Update/QD_Plus4_UI*
USB/QD_MCU/MCU
USB/QD_Update/mks.deb
USB/QD_Update/gcode_macro.cfg
USB/QD_Update/printer.cfg
USB/QD_Update/MKS_THR.cfg
USB/QD_Update/config.mksini
USB/QD_Update/QD_Gcode/
USB/QD_factory_mode.txt
USB/QD_Update/QD_factory_mode.txt
```

Files ending in `.bak` are ignored. Outside factory mode, successfully
consumed firmware/configuration files are generally renamed with `.bak` so
they are not applied again.

`u_disk_update()` is an older/simpler path that searches automounted
`sd[a-h][0-3]` directories for `QD_Update/QD_Plus4_SOC`, executes `dpkg -i`
on the file, and removes it.

## SoC/application update

For filenames beginning `QD_Plus4_SOC` or `QD_Plus4_PATCH`, `start_update()`:

1. moves the selected file to `mks.deb` in the USB update directory;
2. runs `dpkg -i --force-overwrite` as root;
3. moves the package back to its original name, normally adding `.bak`;
4. calls `sync`.

Thus `QD_Plus4_SOC` is a Debian package with a product-specific filename, not
a raw eMMC image. The `mks.deb` factory path is also installed directly with
`dpkg`.

Configuration and bundled G-code updates are simple root-level file copies.
Moonraker is stopped while bundled G-code is replaced, ownership and modes are
changed, and Moonraker is restarted.

## Online update

The online flow selects one of these regional bases:

```text
https://download_aliyun.qidi3dprinter.com/QD_Plus4
https://download_aws.qidi3dprinter.com/QD_Plus4
```

`update_system()` appends `/QD_Plus4_SOC` and `/QD_Plus4_UI` literally, so the
complete payload URLs are:

```text
https://download_aliyun.qidi3dprinter.com/QD_Plus4/QD_Plus4_SOC
https://download_aliyun.qidi3dprinter.com/QD_Plus4/QD_Plus4_UI
https://download_aws.qidi3dprinter.com/QD_Plus4/QD_Plus4_SOC
https://download_aws.qidi3dprinter.com/QD_Plus4/QD_Plus4_UI
```

The files are downloaded into `/tmp` using the same final component as the
local filename. Live checks on 2026-07-13 returned HTTP 200 for all four
endpoints. The two UI payloads were byte-identical, but the SOC packages were
not exact regional mirrors. Both were Debian package `qidi-x-plus4` version
`1.0.1`, and unpacking showed only `/root/xindi/build/xindi` differed. The AWS
binary matched the captured 1.8.2 `xindi` SHA-256; the Aliyun binary was a
different build even though its packaged `/root/xindi/version` still reported
SOC `V1.8.2`.

| Endpoint | Bytes | SHA-256 |
| --- | ---: | --- |
| Aliyun SOC | 17,119,600 | `1269743A5DBDA1E156FAF70CB6241E2D944CC0FDC00D1A27AB91C93E1B5DB677` |
| AWS SOC | 17,116,444 | `A7C24153945AE7625D162AFBB8B8BDD932245C49A1A9986D077CAB408314C461` |
| Aliyun UI | 20,540,552 | `A64A9C470B6BF8784272C0ABA885AD567F1C5596AEB54AD9E8E0161A99B19397` |
| AWS UI | 20,540,552 | `A64A9C470B6BF8784272C0ABA885AD567F1C5596AEB54AD9E8E0161A99B19397` |

`install_update()` installs the SoC file with `dpkg -i --force-overwrite` and
copies the UI file to `/root/800_480.tft`, deleting each temporary file after
a successful operation.

The binary also invokes `/root/auto_update/version_check.py` and
`download_update.py`, with `update_info.ini` and `update_progress.ini`. Those
root files were outside the backup script's captured paths, so their manifest,
version and download-validation logic could not be reviewed.

## Mainboard MCU flashing

When `USB/QD_MCU/MCU` is detected, `start_update()` performs this sequence:

1. copy the image to `/root/klipper.bin`;
2. send the G-code `CLOSE_MCU_PORT` through the Makerbase/Moonraker connection;
3. stop Klipper;
4. run `/root/hid-flash /root/klipper.bin ttyS0`;
5. start Klipper;
6. outside factory mode, rename the USB image to `MCU.bak`.

`CLOSE_MCU_PORT` is present in `xindi`, but no handler for that exact command
was found in the captured readable Klipper source or printer configuration.
Decompiling `close_mcu_port()` confirms that it only submits the literal G-code
`CLOSE_MCU_PORT\n` through the normal Makerbase/Moonraker path; it does not
toggle a GPIO or manipulate the UART locally. It may be a legacy/private
integration point. Stopping Klipper still releases the UART before the flasher
opens it.

The release payload contains both the flasher binary and its modified source
under `STM32_HID_Bootloader/cli`. It identifies itself as HID-Flash 2.2.1 but
uses a serial port instead of USB HID:

1. open `ttyS0`;
2. send a 64-byte reset-pages frame beginning `BLTTTTTT`;
3. wait for `OK` twice;
4. send the firmware in 1,024-byte pages, padding the last page with `0xff`;
5. wait after each page for an acknowledgement whose byte 7 is `0x02`;
6. send a 1,024-byte reboot frame beginning `BTLDCMD 01`;
7. close the UART.

The flasher performs no visible model, version, signature or firmware-content
validation. It checks that the file opens and relies on bootloader responses.
It opens the target at 115200 baud and assumes the QIDI bootloader is already
answering. Although its serial library contains DTR/RTS helpers, the bootloader
toggle sequence is compiled out. The exact event that leaves the mainboard in
its updater after Klipper is stopped remains to be verified on hardware.

A read-only 256 KiB dump from the stock 1.7.3 mainboard confirms its complete
layout. A bootloader vector table begins at `0x08000000` with reset handler
`0x08004b95`; a second valid vector table begins exactly 32 KiB later at file
offset `0x8000`, with application reset handler `0x0800bf99`. The Klipper
dictionary at offset `0xd780` reports
`v0.12.0-65-g96ab9069-dirty-20240301_100654-mkspi`, STM32F401XC, USART1
PA10/PA9 and 500000 baud. The complete dump has SHA-256
`4C4116B81218914C3A1E5E66C5C5A777FCAC306AB709CF9DD10A318C8978B26E`.
This independently verifies the 32 KiB application offset used by the
community mainline build and shows that the QIDI UART and microSD updaters
ultimately populate the same application region.

The 1.8.2 mainboard dump is byte-for-byte identical to the 1.7.3 dump,
including both bootloader and Klipper application. QIDI did not change the
mainboard MCU firmware between these two installed printer versions.

No command or embedded path targets `/dev/ttyS2`, so the captured QIDI UI does
not expose the same direct update mechanism for the toolhead MCU. An
uncaptured Debian-package maintainer script could theoretically add another
path, so this is a conclusion about the captured files rather than proof that
QIDI has never shipped a toolhead updater.

A subsequent read-only dump from the stock 1.7.3 toolhead resolves the more
important bootloader question. Klipper's bundled `dump_mcu.py` read 64 KiB
from the STM32F103XE starting at `0x08000000`. The first words are a valid
application vector table: initial stack `0x20005000` and reset handler
`0x08003afd`. Code occupies the nominal first 8 KiB and continues through the
rest of the image; there is no separate stock bootloader region. The embedded
Klipper dictionary is at file offset `0x5324`, reports
`v0.12.0-65-g96ab9069-dirty-20240301_100458-mkspi`, and confirms USART1 on
PB7/PB6 at 500000 baud. The complete 64 KiB dump has SHA-256
`E18170B75AFF6AB36BCFB906218A5832F85E8A1A76435801306D107E4A806A28`.
The 1.8.2 toolhead dump has the same hash, so its complete MCU firmware is
also byte-for-byte identical to 1.7.3.

This means QIDI's `hid-flash` cannot simply be pointed at `/dev/ttyS2`: there
is no resident bootloader to receive its 115200-baud protocol. Installing
Katapult for the first time necessarily requires SWD or another physical
STM32 programming mechanism. The 8 KiB offset used by community toolhead
builds applies only *after* Katapult has been installed.

## QIDI Box MCU flashing

The published `box_detect.py` source is an exact API-lineage match for the
compiled module. It monitors USB serial IDs for `QIDI_BOX_V1` and
`QIDI_BOX_V2`, extracts the connected Box version, compares it with the
bundled `mcu_box_to_v1_*.bin`, and starts:

```text
/home/mks/mcu_update_BOX_to_v1.sh <image> <klipper-serial-device>
```

The shell script then:

1. extracts the running Box MCU's Klipper command dictionary with
   `serial_com_dict`;
2. decompresses it and obtains the runtime reset-command message ID;
3. sends that reset command with `serial_com`, retrying up to five times;
4. waits for a USB bootloader matching `usb-*MKS_COLOR*_BOOT*`;
5. runs `/home/mks/hid-flash <image> <bootloader-device>`;
6. returns distinct errors for missing firmware, reset failure, missing
   bootloader and flasher failure.

The Box uses a different, newer flasher binary: HID-Flash 2.5.1 (UART). Its
recovered framing is:

```text
A5 | type:1 | payload_length_be:2 | payload | CRC16_be:2
```

Its sequence is `basic`, `start` (including firmware size), repeated `file`
frames, and `end` or `abort`. File frames contain a big-endian packet number,
a big-endian actual-data length and up to 1,024 data bytes. It validates CRC16
on responses, retries data-error/time-out frames, and requires acknowledgements
before advancing.

The bundled Box image is 36,280 bytes and has SHA-256
`EB5C326E95B739B4C16BE957CEA18682F1B4EEE972CA47061077D28CF86EF362`.
The image and updater are identical in the two captured releases.

A read-only 256 KiB live dump establishes the Box layout. Its bootloader
vector begins at `0x08000000` with reset handler `0x080049dd`; the Box
application vector begins 32 KiB later at `0x08008000`, with reset handler
`0x0800cd2d`. The 36,280-byte bundled update image is an exact byte-for-byte
match for the live flash starting at offset `0x8000`. The full dump has
SHA-256 `855633D1E3378E47F4006D27D25B6F7CC3ECCC557B567AF28319B721E1663926`.
This confirms that QIDI's Box updater preserves a 32 KiB resident bootloader
and replaces only the application image.

The Box image is not a generic mainline Klipper MCU build. Its embedded
identify dictionary reports an STM32F401XC at 84 MHz using USB on PA11/PA12,
and exposes QIDI-specific commands including `config_fm17550`,
`query_fm17550`, the `fm17550_*_cb` RFID operations, `config_irq_button`,
`irq_button_ack`, and `reset_reason_get`. Mainline's normal MCU command set
does not provide those RFID operations. A vanilla mainline image would
therefore remove functionality required by QIDI's current Box host modules.

## Mainline Klipper migration implications

The QIDI transport is technically capable of writing an unsigned application
image, but that does not make every mainline image safe to send through it.
The image must target the exact MCU, clock, UART pins, baud rate and bootloader
application offset expected by the board. An incorrect offset can overwrite a
bootloader or leave the MCU unable to start.

The community-tested Plus4 mainline configurations use:

| Board | MCU | Mainline application offset | Connection |
| --- | --- | --- | --- |
| Mainboard | STM32F401XC, 8 MHz crystal | 32 KiB (`0x08008000`) | USART1 PA10/PA9, 500000 baud, `/dev/ttyS0` |
| Toolhead after Katapult installation | STM32F103XE, 8 MHz crystal | 8 KiB (`0x08002000`) | USART1 PB7/PB6, 500000 baud, `/dev/ttyS2` |
| QIDI Box | STM32F401XC, 8 MHz crystal | 32 KiB (`0x08008000`) | USB PA11/PA12 |

A conservative conversion path is:

1. Retain the original QIDI eMMC and all captured binaries as recovery media.
2. On the mainboard, use its existing microSD bootloader to install a Katapult
   deployer as `qd_mcu.bin`; a successful update renames it to `qd_mcu.CUR`.
   Then flash the 32 KiB-offset mainline application through Katapult over
   `/dev/ttyS0`. This replaces the opaque QIDI update transport with a
   documented, repeatable bootloader path.
3. On the toolhead, perform a one-time SWD/ST-Link installation of Katapult.
   No verified stock-QIDI updater for `/dev/ttyS2` was found. Once Katapult is
   installed, subsequent 8 KiB-offset Klipper images can be sent over
   `/dev/ttyS2` without using SWD again.
4. Initially leave the QIDI Box MCU on its stock firmware. Port or adapt the
   host-side Box/Happy Hare integration to its self-described Klipper protocol.
   Only replace its MCU image after the RFID and interrupt-button MCU support
   has been ported to mainline or replaced with proven standard mechanisms.
   Its 32 KiB bootloader layout and exact stock recovery application are now
   captured.
5. Do not treat Beacon as a Klipper MCU. Keep its own firmware/update utility
   and use the mainline `beacon_klipper` host module.
6. Replace the QIDI screen integration with FreeDi, or use KlipperScreen on a
   separate compatible display. The stock panel is a serial HMI rather than a
   KlipperScreen-compatible Linux display, and `xindi` depends on QIDI-specific
   host APIs and configuration. The independent bridge research is documented
   in [SCREEN-BRIDGE.md](SCREEN-BRIDGE.md).

It may be possible to send a correctly linked mainboard image through
`/root/hid-flash ... ttyS0`, because the recovered flasher does not validate
the payload. Katapult is preferable for the migration because its layout and
recovery workflow are documented. Running the same QIDI flasher against
`ttyS2` will not work merely because both boards use UART: the stock toolhead
image begins at `0x08000000` and has no resident bootloader.

### Potentially simpler conversion workflow

The existing Plus4 mainline guides install the Katapult deployer on the
mainboard using a FAT32 microSD card named `qd_mcu.bin`, then use Katapult to
install Klipper. QIDI's stock UI already sends an arbitrary application image
to the same mainboard application area using `USB/QD_MCU/MCU`. The live dump
confirms that both update paths target the application vector at `0x08008000`.
This creates a layout-validated simplification candidate: while still running
the stock QIDI host, supply the correctly built Katapult `deployer.bin` as
`QD_MCU/MCU` and
let the normal QIDI updater install it. If validated on a recoverable printer,
that would remove the microSD formatting, rear-panel access and reset-button
steps while retaining Katapult for all subsequent updates.

A still shorter option would send the 32 KiB-offset mainline Klipper image
directly through QIDI's flasher and retain the QIDI bootloader. That should be
treated as a recovery-oriented alternative rather than the preferred public
workflow because the bootloader is opaque and the flasher does not verify the
written image.

The stock toolhead dump rules out an equivalent no-hardware path: its Klipper
application is linked directly at `0x08000000`, not `0x08002000`, and there is
no bootloader beneath it. The one-time SWD/ST-Link Katapult installation
therefore remains necessary. That part of the guide can still be shortened by
using a validated prebuilt Katapult image and a pogo-pin fixture instead of
requiring every user to build Katapult and solder a permanent header, but the
physical programming operation itself cannot safely be removed.

Current community reference implementations:

* [Plus4 mainline/Kalico migration](https://github.com/phrac/plus4_kalico)
* [FreeDi mainline Klipper distribution](https://github.com/Phil1988/FreeDi)
* [Plus4 mainline configuration and flash parameters](https://github.com/cgarwood82/plus4MainlineKlipperConfig)
* [Klipper bootloader entry documentation](https://www.klipper3d.org/Bootloader_Entry.html)
* [Klipper bootloader documentation](https://www.klipper3d.org/Bootloaders.html)

## Touchscreen flashing

The touchscreen firmware is stored as `/root/800_480.tft`. The `uart` helper
is an unstripped ARM64 program that:

* opens `/dev/ttyS1`;
* reads `/root/800_480.tft`;
* uses the `whmi-wri` download command used by TJC/Nextion-style displays;
* negotiates at 230,400 baud and transfers at 921,600 baud;
* sends the firmware data and completion sequence.

Offline update command fragments show the UI file being copied into place,
`/root/uart` being run, and the image renamed to `800_480.tft.bak`. The recovery
path similarly copies `mksscreen.recovery` into `/root/800_480.tft` before the
transfer.

## Trust and validation observations

These are static-review observations, not a claim that a remote exploit is
available:

* the offline updater runs as root and accepts SoC/PATCH packages primarily by
  filename prefix before passing them to `dpkg`;
* the constructed offline shell commands do not visibly quote removable-media
  filenames;
* the mainboard and Box flashers do not perform a cryptographic signature check;
* the online coordinator uses HTTPS, but no checksum/signature verification is
  visible in the analyzed C++ functions;
* the unavailable `/root/auto_update` Python scripts may provide additional
  online validation, so that part remains unresolved;
* there is no visible rollback or dual-bank recovery orchestration at the host
  level.

For a mainline migration, preserve the QIDI mainboard and Box bootloaders and
the original MCU images before flashing. Treat `/root/hid-flash`, `/home/mks/hid-flash`,
`mcu_update_BOX_to_v1.sh`, the Box image, `/root/uart`, and the touchscreen
image as recovery assets even though they are not needed during normal
mainline operation.

## Evidence files

* `xindi-update-decompiled.c` — selected named 1.8.2 update routines;
* `box-hid-flash-decompiled.c` — Box flasher main control flow;
* `box-hid-protocol-decompiled.c` — recovered framing and response parser;
* `../analysis/components/lineage-source/*/klipper/box_detect.py` — published
  source-lineage view of Box discovery/update triggering;
* `../tools/ghidra/ExportNamedDecompilation.java` — the
  reusable named-function Ghidra exporter.

Key 1.8.2 evidence hashes:

| File | SHA-256 |
| --- | --- |
| `xindi` | `492D57792B08FFBA9B9F1567CA21A8999140F4DFAB7D8A04F63EF62938DE8EFD` |
| `/root/hid-flash` 2.2.1 | `22A3B082954567F9AB3168333AFBEB14FB8503C11ECEDAD6263D2DB70A3A2519` |
| `/home/mks/hid-flash` 2.5.1 | `B53ABFDA5F9C295E2CE1CF59B1FD04DF7DEAC043810AA6AC77A3BF4857E55A7E` |
| `/root/uart` | `C38D9420180E0D5775D6D7B4A1FC84A3F53D3233C91D60AADFFBCBCDE6721EF6` |
| `mcu_update_BOX_to_v1.sh` | `4AE5086954628F34582397D30870479E9039BC36AF2C0B3EA5B681F4DBD42380` |
