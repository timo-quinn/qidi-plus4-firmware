# QIDI1 upstream migration review — 2026-10-04

Research scope: primary-source changes relevant to migrating a QIDI Plus4 from
stock firmware to mainline Klipper. This supplements the local QIDI2 audit; it
does not authorize or perform a printer update. The intended first milestone is
single-material printing; QIDI Box commissioning follows later.

Repository baseline: `180ff85` (2026-08-08). The migration guide's hardware and
initial flash observations date from 2026-07-13/14, while its pinned community
sources are older. Dates below are upstream UTC commit/merge/release dates.
Repository histories, PR status, source files, and Armbian download metadata were
checked on 2026-10-04. See [MAINLINE-MIGRATION.md](../migration/MAINLINE-MIGRATION.md) and
[FIRMWARE-FLASHING.md](../firmware/FIRMWARE-FLASHING.md) for local evidence.

## Findings that affect QIDI1 preparation

| Finding | Status and date | Practical consequence |
|---|---|---|
| Armbian Qidi X-6 is now a standard-support board | Merged 2026-08-13 | Keep the official Armbian route; replace the obsolete `.csc` source link with `.conf`. |
| The current minimal-image alias resolves to an older kernel than QIDI2 currently runs | Checked 2026-10-04 | Record the exact image and kernel; do not equate a working download alias with the QIDI2 installation. |
| An upstream serial DMA reopen crash was fixed | Armbian backport 2026-08-14; Linux 6.18 stable fix 2026-08-19 | Check that the selected kernel contains the fix; verify serial close/reopen behavior before flashing. |
| Armbian Imager can preconfigure the first user and network | Existing capability; useful fixes released 2026-08-25 | Preconfigure the spare eMMC to shorten first login; still audit UARTs and sudo. |
| Klipper now reports the MCU's compiled configuration | Merged 2026-09-08/09 | Newly built firmware can provide an additional post-flash check of MCU, offset, UART, and baud selections. |
| Happy Hare v4 includes a QIDI Box profile | Merged 2026-08-30, with September fixes | Useful for the later Box phase; it is a fresh configuration exercise, not a drop-in v3 update or proof of stock feature parity. |

The sources and limits for each finding follow.

## Official Armbian route

Armbian merged [Qidi X-6 standard support, PR #10412](https://github.com/armbian/build/pull/10412)
on 2026-08-13 at commit
[`48cb69f26b1a29f015f327191eebcdd6144d0038`](https://github.com/armbian/build/commit/48cb69f26b1a29f015f327191eebcdd6144d0038).
It changes the board file from `.csc` to `.conf`; it is not a new flashing
transport. The [current board definition](https://github.com/armbian/build/blob/b44a5a2cfc5114477e20fc8f6aaa38058860ab9f/config/boards/qidi-x6.conf)
explicitly includes X-7/Plus4, offers `current,edge`, tests `current`, and uses
U-Boot 2026.07. The [U-Boot update, PR #10228](https://github.com/armbian/build/pull/10228)
merged on 2026-07-19, so it predates the August repository baseline.

The migration tool's existing
[Trixie current minimal alias](https://dl.armbian.com/qidi-x6/Trixie_current_minimal)
was reachable. Its [checksum sidecar](https://dl.armbian.com/qidi-x6/Trixie_current_minimal.sha)
identified:

```text
Armbian_26.8.1_Qidi-x6_trixie_current_6.18.44_minimal.img.xz
SHA-256: c6e9bbcabab9122e0db17d48aa495d16b2ca474f53a7402233ecbb68ffb9a39e
```

HTTP HEAD reported 423,518,364 bytes and Last-Modified
`2026-08-14 09:01:11 UTC`. These are server metadata observations, not a local
download, hash verification, or boot test of that image. The alias can change.
The board webpage could not be retrieved by the web reader; the source
definition and download endpoint were independently checked.

The companion local audit found QIDI2 running kernel
`6.18.54-current-rockchip64` on Debian 13 / Armbian `26.11.0-trunk.68`.
That is newer than this alias and identifies a trunk installation. Choose and
record QIDI1's image deliberately, then boot and audit it before committing to
MCU changes. Copying QIDI2's whole eMMC would also copy its machine identity,
keys and printer configuration; a fresh official image with a setup preset is
the cleaner inferred approach.

### Serial reopen fix

[Armbian PR #10420](https://github.com/armbian/build/pull/10420), merged
2026-08-14 at
[`b8f771a3ce74887e68dfe4176365a73719aae66a`](https://github.com/armbian/build/commit/b8f771a3ce74887e68dfe4176365a73719aae66a),
backports a fix for stale RX DMA state causing a kernel crash when a serial
port is closed and reopened. Linux's 6.18 stable branch received the fix on
2026-08-19 at
[`ae05d9e50b6b9f246c110b3bdc03676145c2d0d4`](https://github.com/gregkh/linux/commit/ae05d9e50b6b9f246c110b3bdc03676145c2d0d4).
Armbian then [removed its redundant 6.18 backport](https://github.com/armbian/build/pull/10482)
on 2026-08-20 because the stable kernel contained it.

The fix is absent from the [vanilla 6.18.44 file history](https://github.com/gregkh/linux/commits/v6.18.44/drivers/tty/serial/8250/8250_dma.c)
and present in [6.18.54](https://github.com/gregkh/linux/commits/v6.18.54/drivers/tty/serial/8250/8250_dma.c).
The prebuilt image's reported timestamp precedes the Armbian backport merge;
do not assume that image includes the patch without inspecting its build or
installed kernel. The [RK3328 base device tree](https://github.com/gregkh/linux/blob/v6.18.54/arch/arm64/boot/dts/rockchip/rk3328.dtsi)
defines UART RX/TX DMA, and [Armbian's QIDI tree](https://github.com/armbian/build/blob/b44a5a2cfc5114477e20fc8f6aaa38058860ab9f/patch/kernel/archive/rockchip64-6.18/dt/rk3328-qidi-x6.dts)
enables UART0 and UART2. This makes the fix relevant to investigate on Plus4;
the upstream live reproducer was a different Rockchip board. It does not prove
that every Plus4 timing error is resolved or that host affinity tuning can be
removed.

### Shorter host first boot

[Armbian Imager v2.0.2](https://github.com/armbian/imager/releases/tag/v2.0.2)
already documented first-boot profiles for the user, SSH key, Wi-Fi and locale.
[v2.0.4](https://github.com/armbian/imager/releases/tag/v2.0.4), released
2026-08-25 at
[`5ad7dbb419094fb54407d791f53c7ea89090383e`](https://github.com/armbian/imager/tree/5ad7dbb419094fb54407d791f53c7ea89090383e),
fixes shorter presets leaving stale trailing content and shows the selected
kernel branch/version before flashing. Its [preset renderer](https://github.com/armbian/imager/blob/5ad7dbb419094fb54407d791f53c7ea89090383e/src/config/autoconfig.ts)
uses Armbian's `/root/.not_logged_in_yet` format.

Recommendation: use a QIDI1-specific first-boot profile when preparing the
spare eMMC, then verify the actual login and UART setup. Treat this as an
available upstream simplification requiring a QIDI1 boot check; it has not
been exercised on QIDI1 during this review. It does not replace the host-stack
bootstrap or the performance/IRQ audit.

## MCU flashing and recovery

The two Plus4 reference repositories remain at precisely the guide's existing
pinned commits: [phrac `00fc3e54`](https://github.com/phrac/plus4_kalico/tree/00fc3e54bdf2ac5db72b34dc63c63063be804fdb)
and [cgarwood82 `e3551541`](https://github.com/cgarwood82/plus4MainlineKlipperConfig/tree/e3551541f66860658de280b99f8c915a2bff5d34),
both dated 2025-12-13. Neither provides a newly discovered stock-Plus4
hands-off flash path.

Katapult's only main-branch additions since the pinned
[`ec59b9bb`](https://github.com/Arksine/katapult/tree/ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e)
are [RP2350 support](https://github.com/Arksine/katapult/commit/ada29fdafb9a4f1e665fa021478307cb3c05c564)
and [Pico SDK header updates](https://github.com/Arksine/katapult/commit/3b973a485388b4ef0f9efef46f78152e302aea8e),
dated 2026-10-01. They do not simplify the Plus4's STM32F401/F103 route.

The [Katapult deployer documentation](https://github.com/Arksine/katapult/blob/3b973a485388b4ef0f9efef46f78152e302aea8e/README.md#katapult-deployer)
states that the deployer **overwrites the existing bootloader**. Installing it
through QIDI's microSD updater does not preserve QIDI's bootloader merely
because the deployer application begins at the stock application offset.
Its configuration also determines Katapult's resulting application offset.
The [STM32 configuration](https://github.com/Arksine/katapult/blob/ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e/src/stm32/Kconfig)
distinguishes `STM32_FLASH_START_8000` (deployer linked at `0x08008000`)
from `STM32_APP_START_8000` (installed Katapult launches Klipper at
`0x08008000`). The alternative `STM32_APP_START_4000` requires a Klipper
image linked at `0x08004000`. The [deployer source](https://github.com/Arksine/katapult/blob/ec59b9bb9ad6c2ec8d4dc6831fbc77f0b308e29e/src/deployer.c)
writes the bootloader payload at `CONFIG_FLASH_START` (`0x08000000` on
STM32), independently of the deployer's own link address. Thus the stock
microSD path can install Katapult by first loading that application; SWD is
a fallback if deployment fails, not an inherent requirement for successful
mainboard deployment. The programmer-free route still replaces the stock
bootloader and its recovery behavior.
Retaining the directly flashed 32 KiB-offset Klipper mainboard application is
the simpler locally validated initial route. Mainboard Katapult remains an
older optional tradeoff for later UART updates, requiring a separate
reviewed build, backup, and recovery plan.

Katapult's same README still recommends a full chip erase for initial
installation and a two-call bootloader request/upload for UART devices. That
matches the local toolhead erase requirement. Nothing found removes the
one-time physical programming operation for the locally captured stock
toolhead, which contains no resident bootloader. This conclusion is limited
to the documented hardware/dumps; audit QIDI1 rather than assume it matches.

### Improved post-flash evidence

Klipper merged [embedded build configuration](https://github.com/Klipper3d/klipper/commit/8aa2ed3087c2d6f4da9d29bad5e772afa0cdd912)
and [`mcu_kconfig` status](https://github.com/Klipper3d/klipper/commit/8c29c0a8e205d897f765ce867b983e009cbe32a1)
on 2026-09-08, followed by [config logging](https://github.com/Klipper3d/klipper/commit/3a1f884dc83c44714bfc93238525cb57f4474588)
on 2026-09-09. Newly built MCU firmware and a compatible host can report its
actual minimal build configuration. Add that evidence to cold commissioning;
older MCU firmware reports `None`, so a host-only update cannot recover this
information from existing stock images. Keep image vector/hash checks before
flashing.

Klipper's [CS1237 load-cell support](https://github.com/Klipper3d/klipper/commit/8cdfdd98c03c88b1fcc682b1976c6ff0b87aea70)
(2026-09-19) and [read correction](https://github.com/Klipper3d/klipper/commit/eefd197ac58770a3427f7ce3c279b3ceef669116)
(2026-09-30) concern ADC-based probes, including QIDI Q2 work. They are not
evidence that the Plus4's documented digital-endstop strain-gauge hardware can
use that path unchanged. See [TOOLHEAD-MCU-FIRMWARE.md](../firmware/TOOLHEAD-MCU-FIRMWARE.md).

## QIDI Box after single-material commissioning

Happy Hare [v4.0.0 landed on 2026-08-30](https://github.com/moggieuk/Happy-Hare/commit/fe4ce39faad3bc06f0582942b2874c49fc599e7e).
Its [README](https://github.com/moggieuk/Happy-Hare/blob/0b56a4ed9bd689695aa6c925eeefaa99871a35a0/README.md)
lists QIDI Box and explains that v3/v4 configuration formats are incompatible.
The native [Box board profile](https://github.com/moggieuk/Happy-Hare/blob/0b56a4ed9bd689695aa6c925eeefaa99871a35a0/installer/boards/custom/Kconfig.qidi_box)
recognizes both stock `QIDI_BOX_V2` and mainline serial IDs and defines ordinary
step/dir/enable pins and sensors. This establishes installer support for a
stock-MCU path, not a tested end-to-end Plus4 installation or an equivalence to
QIDI's proprietary host modules.
Both QIDI profile files are present at the initial v4 commit, so their
introduction date is confirmed as 2026-08-30. The local QIDI1 Box advertises
`QIDI_BOX_V1_1.1.1`, whereas this upstream board profile names v2 and matches
`QIDI_BOX_V2`. Its applicability to our retained Box firmware and hardware
is therefore unverified; an installer serial-ID match is not enough to
establish compatibility.

The [MMU profile](https://github.com/moggieuk/Happy-Hare/blob/0b56a4ed9bd689695aa6c925eeefaa99871a35a0/installer/mmu_types/Kconfig.qidi_box)
defaults to a QIDI Q2 toolhead. Its `THR:PA1` sensor name and cutter coordinates
must not be copied into a Plus4 configuration. September changes fixed
[software I2C selection](https://github.com/moggieuk/Happy-Hare/commit/264b64236b2e99a29a2fae81a60b00ed78d67a33),
[dryer heater naming](https://github.com/moggieuk/Happy-Hare/commit/b088dc5d3c0453dfa12a73fd90cc3963be01e246),
and [preload homing/parking](https://github.com/moggieuk/Happy-Hare/commit/b45a4d8c799003d4cb4400904bf7fe9e0aad1aa6).
The heater-naming change explicitly says the user must still create the
`heater_generic` section. Validate actual sensors, thermal controls, gate
motion and cutter geometry independently.

Happy Hare's [NFC/RFID documentation](https://moggieuk.github.io/Happy-Hare-Doc/Feature-NFC/)
lists RC522, PN5180, PN532 and PN7160 readers. The checked source tree has no
`fm17550` driver or command integration. Factory QIDI RFID support is therefore
not established by the new Box profile; retain stock Box firmware and separate
RFID/dryer commissioning from initial filament movement. Use a pinned v3
branch for the existing local v3 backend until a deliberate v4 evaluation is
completed. Do not run the old installer instructions against today's default
branch and assume compatible output.

## Proposals and alternatives that should not change the default

FreeDi remains at the already reviewed
[`facb6707`](https://github.com/Phil1988/FreeDi/tree/facb6707e22d1194ed3a4f6c84ea549732a99da3)
(2026-06-14). Its [PR #562](https://github.com/Phil1988/FreeDi/pull/562), opened
2026-09-12 and still unmerged, documents a 500000-baud Klipper / 250000-baud
Katapult mismatch in FreeDi's shipped Plus4 toolhead files. It proposes a
separate request baud. Our matched 500000-baud builds avoid that particular
problem; do not substitute FreeDi binaries based solely on matching MCU names.

Other current FreeDi proposals address
[safe installer reruns](https://github.com/Phil1988/FreeDi/pull/576),
[available Python binary versions](https://github.com/Phil1988/FreeDi/pull/575),
and [machine identity cleanup in prebuilt images](https://github.com/Phil1988/FreeDi/pull/578).
They are **unmerged as checked**. The last proposal reports shared SSH keys in
an older FreeDi image and supplies an unmerged build fix; this review did not
independently inspect that image. These are reasons to retain the fresh
official-image route, not evidence of a newly repaired FreeDi release.

[KlipperFleet](https://github.com/JohnBaumb/KlipperFleet) offers a web flashing
interface and lists Plus4 boards, but its README labels it alpha and says
non-Raspberry-Pi hosts and Fluidd are unsupported. Its Plus4 table also describes
a USB mainboard path, unlike our stock UART wiring. It adds no verified
stock-Plus4 bootloader entry method and is not a replacement for the current
initial migration workflow.

Recommended preparation changes are therefore modest: select and pin the host
image/kernel; consider first-boot preconfiguration; retain mainboard microSD and
one-time toolhead SWD; build and record matching firmware once; verify the
new MCU configuration metadata after flashing; defer Box/v4/screen integration
until single-material commissioning succeeds.
