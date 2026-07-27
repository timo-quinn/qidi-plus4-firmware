# QIDI Plus4 toolhead MCU firmware analysis

A recurring question is whether QIDI's toolhead behaviour — load-cell / strain
gauge homing, and occasional `Timer too close` (TTC) errors — comes from
proprietary logic hidden in the compiled toolhead firmware. This note records
what the toolhead flash dump actually contains and where the relevant logic
lives.

## Summary

- The toolhead MCU firmware is **stock Klipper**, not a proprietary blob.
- Its command interface is **100% standard Klipper** — there is no custom
  load-cell, strain-gauge, or force command.
- The load cell is presented to the host as a **plain digital endstop**, so the
  strain-gauge conditioning happens in hardware, not firmware.
- The homing / probing / timing behaviour that TTC relates to is therefore
  **host-side** (QIDI's `mcu.py` and `probe.py` patches), not in the toolhead
  firmware.

## What was examined

Full toolhead flash read-backs from two releases:

| Release | Size | SHA-256 |
|---|---:|---|
| 1.7.3 | 65,536 | `e18170b75aff6ab36bcfb906218a5832f85e8a1a76435801306d107e4a806a28` |
| 1.8.2 | 65,536 | `e18170b75aff6ab36bcfb906218a5832f85e8a1a76435801306d107e4a806a28` |

The two dumps are **byte-identical**, so the toolhead firmware did not change
between these releases. The dumps live under ignored backup storage and are not
redistributed; only the extracted evidence below is published.

## Firmware identity

The build vector table is a Cortex-M image (initial SP `0x20005000`, reset
`0x08003afd`), loaded at `0x08000000`. Klipper firmware embeds a zlib-compressed
"identify" dictionary that fully describes the build; extracted from the dump it
reports:

| Field | Value |
|---|---|
| Version | `v0.12.0-65-g96ab9069-dirty-20240301_100458-mkspi` |
| MCU | `stm32f103xe` |
| Clock | 72 MHz |
| Toolchain | `gcc 7.3.1` (ARM embedded 7, 2018-q2) |
| Commands / responses | 80 / 30 |

This is the same upstream Klipper commit (`96ab9069`) recorded elsewhere in the
lineage. The full extracted dictionary is committed at
[`../analysis/firmware/toolhead-mcu-dictionary.json`](../analysis/firmware/toolhead-mcu-dictionary.json).

Reproduce the extraction from a dump with:

```python
import zlib, json
d = open("toolhead-full-flash.bin", "rb").read()
i = d.index(b"x\x9c")            # first zlib stream; the dictionary follows
print(json.loads(zlib.decompressobj().decompress(d[i:i+8000]))["version"])
```

## The command set is entirely stock

All 80 commands and 30 responses are standard Klipper. The homing- and
sensing-relevant ones are the ordinary primitives:

- `config_endstop`, `endstop_home`, `endstop_query_state`, `endstop_state`
- `config_analog_in`, `query_analog_in`, `analog_in_state`
- `config_trsync`, `trsync_start`, `trsync_set_timeout`, `trsync_trigger`,
  `trsync_state`, `stepper_stop_on_trigger`
- `config_adxl345` (input-shaping accelerometer), `config_thermocouple`

There is **no** `load_cell`, `strain`, `weigh`, `gram`, or `force` command, and
no other QIDI-specific verb. Nothing in the toolhead firmware's interface is
proprietary.

## Where the load cell and timing logic actually live

- **Load cell:** the host-side probe wrapper (`qdprobe.py`,
  `MakerbaseProbeEndstopWrapper`) configures the probe as a digital `endstop`
  pin. Combined with the absence of any load-cell command in the firmware, this
  means the strain-gauge signal is conditioned to a digital trigger **in
  hardware** (amplifier + comparator) and read by the stock `endstop_home`
  path. The MCU does nothing load-cell-specific.
- **Timing / TTC:** because the firmware is stock, the homing and probing timing
  is governed by the host. QIDI's deviations from upstream Klipper are host-side
  code patches, not `printer.cfg` settings — principally in `klippy/mcu.py`
  (`TRSYNC_TIMEOUT` raised from 25 ms to 100 ms, staggered trsync reports,
  synchronous `send_wait_ack`) and `klippy/extras/probe.py` (sampling and retry
  changes). See [FIRMWARE-CHANGES.md](FIRMWARE-CHANGES.md).

General `Timer too close` errors during printing (as opposed to during homing)
are usually host-scheduling issues — SBC load, USB/serial latency, host pauses —
which these patches do not directly address.

## Caveat: the build is `-dirty`

The version string ends in `-dirty`, meaning QIDI built from a modified Klipper
tree. The **command interface** is stock, but that does not prove the C
**implementation** is byte-for-byte upstream; small patches to files such as
`endstop.c` or the scheduler would not appear in the command dictionary. To rule
those out, the productive approach is a differential: build a pristine Klipper
`96ab9069` for the STM32F103xE with the same toolchain and diff its compiled
output (or decompilation) against this dump. Decompiling the dump on its own is
low value because it is otherwise stock Klipper, whose source is public at that
commit. This differential has not been performed.
