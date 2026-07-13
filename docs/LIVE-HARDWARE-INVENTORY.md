# QIDI Plus4 live hardware and runtime inventory

This document records sanitized, read-only observations from the two reference
printers on 2026-07-13. It complements filesystem backups: active device
bindings, serial settings, loaded MCU dictionaries, and Moonraker object lists
cannot be inferred as reliably from files alone.

No services were stopped, UART bytes were consumed, commands were sent to an
MCU, or files were changed on either printer. Unique USB serial numbers,
network identifiers, credentials, cloud data, and databases are deliberately
omitted.

## Reference systems

| Property | `qidi1` | `qidi2` |
| --- | --- | --- |
| QIDI release | 1.8.2 with QIDI Box | 1.7.3 without Box |
| Physical controller PCB | `X-7 V1.0` | `X-7 V1.0` |
| Host model | Makerbase MKS Pi | same |
| Device-tree compatible | `firefly,roc-rk3328-cc`, `rockchip,rk3328` | same |
| OS | Debian 10 Buster | same |
| Kernel | `5.16.20-rockchip64`, ARM64 | same |
| eMMC | 29.1 GiB `/dev/mmcblk1` | same |
| Boot partition | 256 MiB VFAT on `mmcblk1p1` | same |
| Root partition | 28.6 GiB ext4 on `mmcblk1p2` | same |
| Klipper Git | `96ab906946ed558b961a7d8e0e56fb6aebf15316` (dirty) | same |
| Moonraker Git | `346a3d7c9dca6499bdef2957ca39a23c702b0268` (dirty) | same |

`X-7 V1.0` is the physical Makerbase/QIDI controller PCB identity. It is not a
contradiction with Armbian's `qidi-x6` build name: the upstream Armbian board
configuration explicitly treats `qidi-x6` as an umbrella target for QIDI X-6
and X-7 boards used in the Plus4 and related printers. Likewise,
`firefly,roc-rk3328-cc` is the compatibility identity used by the stock Linux
device tree, not the QIDI PCB product name.

Migration records should retain all three identifiers. Do not assume another
physical revision such as X-7 V1.1 has identical power routing, connectors, or
pin assignments until its schematic or a live inventory has been compared.

The installed boot artifacts are byte-identical:

| Artifact | SHA-256 |
| --- | --- |
| `/boot/extlinux/extlinux.conf` | `140f355e122cb0b7bb65b649c082f5ec25eb93164d9c0effb4872ab9d03ba65e` |
| `/boot/uInitrd` | `ea5fddbff9ed827593eba84733fd2569d2e894d3761a03dabd8b5cacf55bf1a6` |
| `/boot/Image` | `c6dcae6707c9b67957a5f97374d09342dce5fa1e6c0b4ae0df19e22ad2f03009` |
| `/boot/dtb/rockchip/rk3328-roc-cc.dtb` | `cde8cb7b706b49489e4e912b073acaf66fcd0984889991b997b795f75672b329` |

The live flattened-device-tree hashes differ. This is not evidence of a static
DTB change: the disk DTB is identical and boot firmware/kernel fixups can insert
machine-specific values into the live tree. A semantic, redacted tree diff is
required before treating a live FDT difference as a firmware difference.

## Active host connections

| Device | Hardware address/driver | Runtime | Owner |
| --- | --- | --- | --- |
| Mainboard | `/dev/ttyS0`, `serial@ff110000`, `dw-apb-uart` | 500000 baud | Klipper |
| Stock screen | `/dev/ttyS1`, `serial@ff120000`, `dw-apb-uart` | 115200 baud, raw 8N1 | `xindi` |
| Toolhead | `/dev/ttyS2`, `serial@ff130000`, `dw-apb-uart` | 500000 baud | Klipper |
| Beacon Rev H | USB CDC ACM, VID:PID `04d8:e72b` | `/dev/ttyACM0` | Klipper |
| QIDI Box (`qidi1`) | USB CDC ACM, VID:PID `1d50:614e` | `/dev/ttyACM1` | Klipper |

Klipper, not a separate QIDI service, owns both USB devices on `qidi1`. The Box
enumerates with model `QIDI_BOX_V1_1.1.1`; stable installation should use its
`/dev/serial/by-id` identity rather than assuming `ttyACM1`.

## Loaded MCU identities

The mainboard, toolhead, and Beacon builds are the same on both releases:

| Klipper name | Target/runtime identity | Important constants |
| --- | --- | --- |
| Stock `mcu` (toolhead) | STM32F103xE, QIDI Klipper build `v0.12.0-65-g96ab9069` | 72 MHz, UART 500000 |
| Stock `U_1` (mainboard) | STM32F401xC, same QIDI Klipper build | 84 MHz, UART 500000 |
| `beacon` | Beacon 2.1.0, revision H | 32 MHz, USB CDC ACM |
| `mcu_box1` (`qidi1`) | `KLP_MCU_MKS_V1_1.1.1`, STM32F401xC | 84 MHz, USB CDC ACM |

The Box runtime dictionary contains 129 commands and declares initial active-low
states for `PA1`, `PA2`, `PB4`, `PB5`, `PA14`, `PA15`, `PC4`, and `PC5`. It also
reserves `PA11` and `PA12` for USB. This strengthens the conclusion that the
Box should remain on its stock application while the host-side integration is
reimplemented.

Full mainboard and toolhead flash dumps already exist for both reference
printers under ignored backup storage. A full QIDI Box dump also exists for
`qidi1`.

## Screen comparison

| Property | 1.8.2 (`qidi1`) | 1.7.3 (`qidi2`) |
| --- | --- | --- |
| UI version | `V182` | `V173` |
| `xindi` size | 14,284,000 | 12,465,248 |
| `xindi` SHA-256 | `492d5779...de8efd` | `e65dfa30...214fd` |
| Screen resource size | 20,540,552 | 20,480,808 |
| Screen resource SHA-256 | `a64a9c47...b19397` | `3374f5eb...93dc25` |
| UART settings | 115200, raw 8N1, no flow control | same |

The complete resource hashes and capture unknowns are maintained in the JSON
profiles under [`../screen-bridge/profiles/`](../screen-bridge/profiles/).

## Runtime API differences

The ready-state Moonraker object list contained 218 objects on 1.8.2 with the
Box and 153 on 1.7.3 without it. The additional hardware-facing objects include:

- `mcu mcu_box1` and `multi_color_controller`;
- four `box_stepper` objects;
- `box_extras`, a Box motion sensor, and Box heaters/fans/sensors;
- the Box-specific tool/load/unload macro set documented elsewhere.

Both report the same underlying Klipper and Moonraker Git versions. At runtime,
1.8.2 loads the additional Moonraker `mqtt` and `frp_manager` components, while
the inspected 1.7.3 instance loads `update_manager` instead. These are service
configuration/application-layer differences, not host boot or MCU changes.

Both printers listen on TCP ports 22, 80, 631, 7125, and 10088. This inventory
does not assess exposure beyond the local network; it records the service
surface that a replacement image must either reproduce deliberately or omit.

## High-value evidence still worth preserving

### Host boot chain

The filesystem backups include `/boot`, but not necessarily the eMMC boot
partitions or unpartitioned sectors holding the vendor bootloader. Before the
eMMC migration, make read-only copies of:

- `/dev/mmcblk1boot0` and `/dev/mmcblk1boot1` (4 MiB each);
- the unpartitioned prefix of `/dev/mmcblk1` through the start of partition 1;
- the partition table and eMMC EXT_CSD/boot-enable state.

Store these only under ignored backup storage. They may contain board-specific
values and are recovery evidence, not files for publication without review.

The spare factory eMMC connected through the reference USB reader appears as a
31,037,849,600-byte removable MBR disk. It exposes the 16 MiB bootloader prefix
and user partitions, but not separate eMMC hardware `boot0`/`boot1` devices or
EXT_CSD access. Use
[`image_factory_emmc.py`](../tools/migration/image_factory_emmc.py) from an
elevated terminal to image that user area. Capture `boot0`, `boot1`, and EXT_CSD
later from a booted board or a reader that explicitly exposes eMMC hardware
partitions.

The factory user-area image was acquired and independently re-verified on
2026-07-13:

| Artifact | Size | SHA-256 |
| --- | ---: | --- |
| `factory-emmc-user-area.img` | 31,037,849,600 | `8c52cb163a249cb57768c2fff6bcf951379f4746a1a0411b3c6b0714fdfa2856` |
| `emmc-prefix-16MiB.bin` | 16,777,216 | `e3f9403e86f0bec867635be86df8b50f5cb97a9bf3e66833db57a73be0bd9992` |

The source was marked read-only in Windows throughout acquisition. A separate
post-acquisition SHA-256 pass matched the manifest for both files. The image
contains an MBR with a 256 MiB FAT16-LBA partition at LBA 32,768 and a Linux
partition at LBA 557,056. Raw evidence remains under ignored backup storage.

Both partitions were subsequently mounted from the verified image using
read-only loop devices; the ext4 root was mounted with journal recovery
disabled. The mounts were removed immediately after inspection. The pristine
image identifies itself as factory firmware `V1.1.2` with UI `V112`:

| Factory artifact | Size | SHA-256 |
| --- | ---: | --- |
| `/root/xindi/build/xindi` | 9,380,776 | `b3c9ba5baeced281abb9b4ad6eb24eec6346370d7f5b58fc950da17670f75617` |
| `/root/800_480.tft.bak` | 28,972,292 | `7ab12a2b011498e53e6bcd6456f30674616cc08975cd97d5615140eabb4a733b` |
| `/root/uart` | 35,000 | `c38d9420180e0d5775d6d7b4a1fc84a3f53d3233c91d60aadffbcbcde6721ef6` |
| `/root/hid-flash` | 44,264 | `22a3b082954567f9ab3168333afbeb14fb8503c11ecedad6263d2db70a3a2519` |

The factory image contains the same Debian 10 base, Klipper commit, Moonraker
commit, kernel, initramfs, disk DTB, UART touchscreen updater, and mainboard
flasher hashes as the 1.7.3 and 1.8.2 reference systems. This moves the known
unchanged boot/host baseline back to at least QIDI release 1.1.2. The major
release evolution is therefore in QIDI application/configuration layers rather
than the kernel or boot artifacts.

### Live protocols

- Bidirectional screen UART capture is still required to map page/component IDs.
- USB capture between Klipper and the QIDI Box would document the stock framing
  and reconnect sequence, although the Klipper command dictionary and published
  message formats should be used first.
- A redacted semantic decompilation of the common RK3328 DTB would help verify
  every UART, USB, regulator, GPIO, thermal, and storage node against mainline
  Armbian.

Passive hardware capture is preferable. Attaching a second reader to an active
TTY can consume bytes, and probing I2C/GPIO buses can change device state.
