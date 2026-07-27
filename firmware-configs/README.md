# Plus4 mainline firmware configurations

These Kconfig fragments are consumed by the `build` command in
[`tools/migration/qidi_plus4.py`](../tools/migration/qidi_plus4.py).
They describe the two stock Plus4 controller boards verified on two reference
printers (firmware 1.8.2 with Box, and 1.7.3 without) on 2026-07-13.

| Image | MCU | Application address | Transport |
|---|---|---:|---|
| Mainboard Klipper | STM32F401XC, 8 MHz crystal | `0x08008000` | USART1, 500000 baud |
| Toolhead Katapult | STM32F103XE, 8 MHz crystal | bootloader at `0x08000000`; app at `0x08002000` | USART1 PB7/PB6, 500000 baud |
| Toolhead Klipper | STM32F103XE, 8 MHz crystal | `0x08002000` | USART1 PB7/PB6, 500000 baud |

The mainboard fragment retains QIDI's resident 32 KiB bootloader. The toolhead
fragment reserves 8 KiB for Katapult. Do not use these files for a different
board revision without verifying the MCU, clock, UART pins, and flash layout.
