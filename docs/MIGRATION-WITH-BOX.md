# Migration runbook: Box-equipped Plus4 (1.8.2) → mainline + KlipperFleet

A plan for migrating a QIDI Plus4 that is currently on stock **1.8.2 with the
QIDI Box** (and, in this example, a Beacon Rev H) to mainline Klipper/Moonraker
on Armbian, set up so that [KlipperFleet](https://github.com/JohnBaumb/KlipperFleet)
manages ongoing MCU firmware, while **attempting to retain Box functionality**.

This runbook builds on [MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md) — read that
first. This document only adds the Box-printer choices, the KlipperFleet
enablement, and the experimental Box retention. Where a step is proven versus
experimental is stated explicitly; a Box printer in daily use is more
consequential than a spare, so treat the experimental parts as attempts to
validate, not settled procedure.

## What migrates, what stays

| Component | Plan | Status |
|---|---|---|
| Host OS | Swap eMMC to Armbian; mainline Klipper/Moonraker/Mainsail | Proven |
| Toolhead MCU (STM32F103, `/dev/ttyS2`) | Mainline Klipper via one-time SWD Katapult | Proven |
| Mainboard MCU (STM32F401, `/dev/ttyS0`) | Mainline Klipper — see the two options below | Proven (microSD) / Experimental (Katapult) |
| QIDI Box MCU (STM32F401, USB) | **Leave on stock firmware**; connect from mainline host | Stock kept; host retention experimental |
| Beacon (USB), if fitted | Keep Beacon firmware; `beacon_klipper` host module | Proven |

The Box MCU is never reflashed — its stock `KLP_MCU_MKS_*` application provides
the RFID/FM17550 behaviour that mainline cannot replace. It stays a stock
Klipper-protocol MCU that the mainline host connects to.

## Identities to capture at run time

Record these from the live printer before starting (`ls /dev/serial/by-id/`)
and use the by-id paths, never `ttyACM*`. Values differ per printer:

- **Box MCU:** USB `1d50:614e` → `/dev/serial/by-id/usb-Klipper_stm32f401xc_*-if00`
- **Beacon (if fitted):** USB `04d8:e72b` → `/dev/serial/by-id/usb-Beacon_Beacon_RevH_*-if00`
- **Mainboard:** `/dev/ttyS0` @ 500000 · **Toolhead:** `/dev/ttyS2` @ 500000

Before touching any MCU, confirm you hold complete pre-flash dumps of this
printer's mainboard, toolhead, and Box, so every MCU is recoverable.

## Pre-flight

Follow [MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md) §1 (back up + audit) and set
up key auth so the many SSH steps do not prompt. Choose a unique, filesystem-safe
`$BackupName` for this printer:

```powershell
python .\tools\migration\qidi_plus4.py setup-ssh --printer $Printer --generate
python .\tools\migration\qidi_plus4.py backup --printer $Printer --name $BackupName
python .\tools\migration\qidi_plus4.py audit  --printer $Printer
```

## 1. Build firmware

Standard three images build as in the base guide:

```powershell
python .\tools\migration\qidi_plus4.py build `
  --klipper-dir ~/klipper-mainline --katapult-dir ~/katapult
```

**KlipperFleet needs Katapult on each MCU it manages.** The repo already ships a
toolhead Katapult config (`firmware-configs/katapult/plus4-toolhead.config`).
There is **no mainboard Katapult config yet** — see the mainboard options below.

## 2. Prepare Armbian eMMC

As in the base guide §2 — download/verify the official Qidi X-6 image and write
it to the spare eMMC. Keep the original eMMC untouched as the rollback.

## 3. Flash the MCUs

### Toolhead — Katapult, then Klipper (proven)

One-time SWD/ST-Link Katapult install, then Klipper over `/dev/ttyS2`, exactly as
[MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md) §6–§7. Either wiring option (board
in place, or removed and powered from the ST-Link 3.3 V on J1 pin 2) applies.
After this, the toolhead has a resident Katapult bootloader and KlipperFleet can
reflash it over UART with no further SWD.

### Mainboard — choose one

**Option A — QIDI microSD bootloader + mainline Klipper (proven, recommended).**
Stage and flash the mainline mainboard image through QIDI's resident microSD
bootloader (base guide §4):

```powershell
python .\tools\migration\qidi_plus4.py stage-mainboard-sdcard `
  --image .\artifacts\mainline-firmware\plus4-mainboard-klipper.bin --output E:\
```

With this option the mainboard is **not** a KlipperFleet target — future
mainboard updates continue via microSD. KlipperFleet then manages the toolhead
only. This is the low-risk path and is recommended for a first attempt.

**Option B — Katapult on the mainboard (experimental, for full KlipperFleet).**
KlipperFleet lists the Plus4 mainboard as a Katapult target, but **this repo has
not validated installing Katapult on the mainboard**, and there is a real
obstacle: QIDI's microSD bootloader lives at `0x08000000` and writes only the
application region (`0x08008000`), so it cannot flash a Katapult bootloader over
itself. Installing Katapult on the F401 mainboard therefore likely requires
system **USB DFU** (BOOT0 + the F401's USB, which is not the host UART link) or
another out-of-band programmer, and needs a mainboard Katapult Kconfig
(STM32F401, 32 KiB bootloader offset, UART `ttyS0` @ 500000, `restart_method:
command`) that does not yet exist in `firmware-configs/`. Treat Option B as
research to validate, not a supported step. Do not attempt it on the first pass.

### Box MCU — do nothing

Leave the Box on its stock firmware. It is not flashed, not given Katapult, and
not a KlipperFleet target.

## 4. Swap eMMC and bootstrap the host

Base guide §5: swap in the Armbian eMMC and bootstrap the upstream stack:

```powershell
python .\tools\migration\qidi_plus4.py bootstrap-host `
  --printer $Printer --confirm BOOTSTRAP-HOST
```

## 5. Install KlipperFleet (day-2 MCU management)

KlipperFleet assumes Klipper at `~/klipper`, Katapult at `~/katapult`, and
Katapult bootloaders already on the MCUs — which the steps above provide for the
toolhead (and, with Option B, the mainboard). Install per its README, add its
`[update_manager klipperfleet]` block to `moonraker.conf`, and register:

- **Toolhead** as a Katapult (UART) device — manageable.
- **Mainboard** as a Katapult device only if Option B succeeded; otherwise leave
  it out (updated via microSD).
- **Box MCU and Beacon** are not flashing targets — leave them out of
  KlipperFleet's flash scope.

**Host caveat:** KlipperFleet states non-Raspberry-Pi hosts are unsupported (on
the roadmap). The migrated host is Armbian on RK3328, so KlipperFleet may need
adaptation to run there. Validate that it installs and detects the toolhead
before relying on it; if it does not yet support the host, fall back to
`katapult/scripts/flashtool.py` over UART for toolhead updates. Getting the
QIDI/RK3328 host supported upstream is a worthwhile contribution.

## 6. Base configuration and single-material commissioning

Commission single-material **before** touching the Box. Render the reviewed
X-7 V1.0 / Beacon profile with this printer's Beacon by-id path and run the smoke
test:

```powershell
python .\tools\migration\qidi_plus4.py render-config `
  --beacon-serial '/dev/serial/by-id/usb-Beacon_Beacon_RevH_<yours>-if00' `
  --output .\artifacts\generated-configs\my-plus4
python .\tools\migration\qidi_plus4.py smoke-test --printer $Printer
```

Confirm both `[mcu]` (toolhead) and `[mcu U_1]` (mainboard) reach `Ready`, then
commission motion, temps, and Beacon per the profile. Prove single-material
printing works before proceeding.

## 7. Experimental: retain the Box on mainline

> This is the frontier. The Box host modules were written against QIDI's Klipper
> fork and are **not validated on upstream Klipper**. Expect to iterate, and keep
> a clean fallback (remove the Box includes → single-material still works).

The Box MCU stays stock; the host side is reconstructed from open source:

1. **Connect the Box MCU.** Add a second MCU to the config using the by-id path:

   ```ini
   [mcu box1]
   serial: /dev/serial/by-id/usb-Klipper_stm32f401xc_<your-box>-if00
   ```

2. **Add the Box host modules (pure Python).** Copy QIDI's own 1.7.0 GPLv3 Box
   source — [`../analysis/github-releases/qidi-klipper-1.7.0-box-source/`](../analysis/github-releases/qidi-klipper-1.7.0-box-source/)
   (`aht20_f.py`, `box_detect.py`, `box_extras.py`, `box_rfid.py`,
   `box_stepper.py`) — into `~/klipper/klippy/extras/`, and
   `~/klippy-env/bin/pip install pyudev`. These are plain `.py`, so mainline
   loads them natively (no `.so`, no Python-version lock). The prebuilt binaries
   in [`../qidibox-modules/`](../qidibox-modules/) are an alternative only if you
   deliberately want compiled modules matching your Python/arch.

3. **Add the Box macros and config.** Include
   [`../qidibox-modules/box_macros.cfg`](../qidibox-modules/box_macros.cfg) (it
   restores the three commands the source predates), and bring the Box config
   sections (`box.cfg`, `box1.cfg`–`box4.cfg`, `user_multi_color.qdini`,
   `drying.conf`) from this printer's own backup, adjusting pin/MCU names to the
   `[mcu box1]` namespace.

4. **Expect breakage and triage it.** The modules may reference QIDI fork-only
   host behaviour (its modified `save_variables.py`, the `mcu.py` `send_wait_ack`
   path, the global G-code break flag, `.so` loader assumptions). If Klipper
   refuses to start, read `klippy.log`, remove the failing include, and either
   port the missing dependency or fall back to single-material. Validate one
   module at a time (`box_detect` → `box_rfid` → `box_stepper` → `box_extras`).

Record what works; that feedback is exactly what a reviewed mainline Box backend
needs. See [AMS-COMPATIBILITY.md](AMS-COMPATIBILITY.md) and
[BOX-CARTOGRAPHER-PYTHON-CONFLICT.md](BOX-CARTOGRAPHER-PYTHON-CONFLICT.md).

## 8. Recovery and rollback

- **Host:** the original eMMC is untouched — swap it back for a full revert.
- **Box:** never modified — it returns to full function on the stock host, or
  keeps working as a stock MCU if the experimental host modules are removed.
- **MCUs:** mainboard and toolhead pre-flash dumps are retained for reflash.
- The toolhead is the only irreversible-ish change (SWD erase of the stock app);
  its dump is retained, and the stock toolhead has no bootloader regardless.

## Status summary

| Part | Confidence |
|---|---|
| Host migration, toolhead Katapult+Klipper, Beacon, single-material | Proven on reference hardware |
| KlipperFleet managing the toolhead | Plausible; validate host support on RK3328 |
| Katapult on the mainboard (Option B) | Unvalidated; research before attempting |
| Box functionality on mainline | Experimental; success not guaranteed |
