# QIDI Box MCU watchdog reset (2026-08-06)

## Result

The 6 August 2026 failure was a reset of the QIDI Box MCU, not a second host
USB-hub failure and not the Box output `Timer too close` bug. The retained
journal shows the Box application disconnecting, the resident MKS bootloader
appearing for about two seconds, and the same MCU returning to its Klipper
application. A read-only reset-reason query subsequently reported
`IndependentWatchdog`.

Static analysis also proves a defect in the QIDI-specific PB0 interrupt path:
the configured debounce interval is stored but never enforced. The motion
sensor can therefore interrupt on every encoder or noise edge. Because the
application feeds its independent watchdog only from the main task runner, a
sustained PB0 interrupt storm can keep that runner from executing for the
roughly half-second watchdog interval and reset the MCU.

The debounce defect is confirmed. It is the leading software explanation for
this incident because the reset occurred as newly inserted filament began
moving through the Box sensors. The retained logs do not include an MCU
interrupt trace or electrical capture, so they cannot prove whether the exact
trigger was legitimate encoder transitions, contact bounce, coupled motor
noise, or another electrical event.

## Exact firmware identity

The affected unit ran QIDI's retained Box 1.1.1 application:

| Item | Identity |
| --- | --- |
| Klipper identify string | `KLP_MCU_MKS_V1_1.1.1` |
| Target | `stm32f401xc`, 84 MHz |
| Application USB identity | `1d50:614e`, `QIDI_BOX_V1_1.1.1` |
| Application base | `0x08008000` (after the 32 KiB resident bootloader) |
| Packaged application | `mcu_box_to_v1_1.1.1.bin`, 36,280 bytes |
| Application SHA-256 | `EB5C326E95B739B4C16BE957CEA18682F1B4EEE972CA47061077D28CF86EF362` |
| Full 256 KiB flash SHA-256 | `855633D1E3378E47F4006D27D25B6F7CC3ECCC557B567AF28319B721E1663926` |

The packaged application is an exact byte-for-byte match for the application
region of the retained full-flash dump. This report therefore describes the
exact deployed application, not a nearby source revision or a reconstructed
mainline build.

## Incident evidence

The kernel journal recorded this single reset sequence in UTC:

| Time | Observation |
| --- | --- |
| `09:14:26` | Box application USB device disconnected |
| `09:14:27` | `0483:5740`, product `COLOR BOOT`, manufacturer `MKS`, enumerated |
| `09:14:29` | Bootloader disconnected |
| `09:14:29` | `1d50:614e`, product `QIDI_BOX_V1_1.1.1`, enumerated |

The intermediate `COLOR BOOT` identity is the resident bootloader. Its
appearance distinguishes a Box MCU restart from loss and recovery of only the
host-side USB connection. Klippy recorded no invalid bytes, then a jump in Box
retransmits, EOF and loss of `mcu_box1`; the other MCUs remained responsive.
The printer was idle (`gcodein=0`), and the failed MCU returned no Klipper
shutdown record.

## Watchdog and reset-reason implementation

The retained application contains the following relevant paths:

| Address | Finding |
| --- | --- |
| `0x08009062`-`0x0800907b` | Starts IWDG with prescaler `0` and reload `0x0fff` |
| `0x0800895c`-`0x08008963` | The application's only IWDG feed site, in the main task runner |
| `0x0800ce8c` | Reads and decodes `RCC_CSR` at `0x40023874` |
| `0x0800e4f0` | PB0 IRQ configuration stores `84 * debounce_us` |
| `0x0800cbf4`, `0x0800b9d8` | EXTI0 wrapper and callback do not apply that debounce value |

With the STM32 low-speed oscillator tolerance, the IWDG settings give an
approximately 410-512 ms timeout. A normal Klipper shutdown still returns to
the task runner and feeds this watchdog, so an ordinary host-side error does
not explain the observed reboot. The MCU must stop servicing the main task
runner long enough for IWDG to expire, or suffer a different reset whose flags
are misreported by the decoder described below.

The QIDI `reset_reason_get` decoder checks sticky `RCC_CSR` flags in this
priority order: low-power, window watchdog, independent watchdog, software,
power-on, reset pin, then unknown. It has two important limitations:

- it omits the brownout-reset flag (`BORRSTF`, bit 25); and
- it never sets `RMVF` to clear the accumulated reset flags after reading them.

Consequently, `IndependentWatchdog` is strong corroborating evidence but not a
one-shot crash record. An older IWDG flag can survive later resets and outrank
other flags, while a brownout can be reported as `Unknown` or masked by a
higher-priority sticky flag. Capture the value on the first reconnect, label
it as potentially stale, and do not use this decoder alone to rule out power
or reset-pin faults.

## PB0 failure mechanism

The stock Box profile assigns the filament motion sensor to pull-up input PB0
and enables QIDI's proprietary EXTI path with a nominal 50 us debounce:

```ini
[filament_motion_sensor box_motion_sensor]
switch_pin: ^mcu_box1:PB0
use_irq: True
debounce_us: 50
```

At configuration time the firmware converts the requested interval to 84 MHz
ticks and stores it. The EXTI0 handling path does not read that interval, does
not compare a timestamp, and does not mask/re-arm the line for the debounce
period. Every PB0 edge is therefore admitted. During filament insertion the
encoder produces real transitions, while contact bounce or motor-coupled noise
can add many more. Sufficient interrupt occupancy prevents the main task runner
from reaching its sole IWDG feed site for 410-512 ms, after which hardware
resets into `COLOR BOOT` and then starts the application again.

The durable MCU-side repair is to implement real bounded debounce: mask or
latch EXTI0, defer processing, and re-arm it after the configured interval.
That requires a reviewed replacement Box application and is not part of the
immediate containment.

## Immediate containment

Use Klipper's bounded polled button path instead of the defective QIDI IRQ
path:

```ini
[filament_motion_sensor box_motion_sensor]
switch_pin: ^mcu_box1:PB0
use_irq: False
```

Remove `debounce_us`; it belongs only to the QIDI IRQ path and would otherwise
suggest protection that is not active. Keep the sensor and its normal Klipper
motion monitoring enabled.

Also quarantine automatic insertion while validating the change. QIDI's lane
callback invokes `RELOAD_ALL RFID=1`, starts RFID work and may run a lane home
of up to 3000 mm at 80 mm/s while PB0 is active. QIDI registers `RELOAD_ALL`
dynamically from `box_extras`, so a G-code macro with `rename_existing` cannot
wrap it during configuration parsing and will prevent Klipper from starting.
The managed `box_output_clock_guard` post-load overlay instead replaces the
registered callback at `klippy:connect`, rejects only automatic `RFID=1` calls,
and passes explicit/manual calls to the original command. Do not rely on
`enable_box` or `auto_read_rfid=0` alone: neither removes the automatic lane
motion that exposed this failure. Use the established guarded manual load
commands until deliberate testing shows the Box stable.

Apply both containment changes through the canonical managed configuration so
QIDI's `box_detect` regeneration cannot silently restore `use_irq: True`.

### Controlled vendor-path comparison

To test whether the original cable/hub path was the actual reset cause, the
reviewed migration utility also exposes `restore-box-motion-template`. It
backs up only the detected `/home/mks/cfg_with_N` template and restores the
stock pair `use_irq: True` and `debounce_us: 50` without touching active config
or restarting Klipper. The matching active `box.cfg` must still be deployed
through the normal managed-config workflow.

Keep the output-clock and automatic-insertion guards enabled during this
comparison so only the motion IRQ/debounce variable changes. Treat the vendor
path as an experiment: rapid PB0 activity again runs the IRQ implementation
identified in this analysis.

## Safe isolation procedure

1. Do not reproduce this during a print. Confirm the hotend and Box heater are
   off, motion is idle, and filament can be removed without force.
2. Before restarting or power-cycling, retain Klippy and kernel journals and
   issue only the read-only reset-reason query. Record that its result may be
   sticky; do not clear flags until the evidence is saved.
3. Deploy `use_irq: False` and the automatic-insertion quarantine together,
   then restart Klipper once while idle. Verify the Box reconnects and the
   managed configuration still contains both controls.
4. Exercise the normal manual load path at low risk, without a print. Observe
   Box communication, sensor state and the kernel journal. Do not repeatedly
   force a lane against an endstop after an unexpected response.
5. If isolation is still required, test RFID-only work and lane motion
   separately. Re-enable automatic insertion only after each independent path
   is stable, and change one variable per test.
6. On any recurrence, stop testing and capture the first reset reason and USB
   transition before another restart changes the evidence context.

## Distinction from `Timer too close`

The separate QIDI Box output bug calculates an output timestamp from the
primary MCU clock and queues it on `mcu_box1`. Clock-domain mismatch can make
Klipper reject the command with an orderly `Timer too close` shutdown. The
[`box_output_clock_guard`](QIDI-BOX-OUTPUT-CLOCK-GUARD.md) corrects that host
object ownership error.

That bug does not reset the Box MCU, enumerate `COLOR BOOT`, or prevent the
main task runner from feeding IWDG. The clock guard and the PB0/automatic-load
containment address different failures; a printer that has experienced both
needs both remedies.

## Limits and electrical alternatives

The available evidence does not include a logic-analyzer trace of PB0, an MCU
interrupt counter, or oscilloscope captures of the Box supply and NRST. It
therefore cannot exclude a supply dip, reset-pin interference, sensor wiring
fault, or EMI as the initiating event. The incomplete sticky reset decoder is
an additional reason not to treat its string as conclusive.

If the reset recurs with PB0 polled and automatic insertion disabled, power the
printer down before disturbing wiring and investigate hardware rather than
loosening Klipper timing limits:

- inspect and reseat the PB0 sensor harness, grounds and Box USB connection;
- substitute a known-good sensor or cable, one item at a time;
- scope the Box supply and NRST during lane-motor start and filament contact;
- check PB0 for excessive bounce or motor-correlated spikes; and
- evaluate cable routing, shielding, ferrites and supply integrity.

A Schmitt-trigger buffer or correctly engineered hardware filter can reject
electrical noise, but an arbitrary RC network can slow edges, violate input
threshold timing, or hide legitimate motion pulses. Make hardware changes only
with the board voltage, pull-up, sensor output and maximum encoder rate known.
Firmware debounce is the preferred long-term correction because its behavior
can be bounded and tested without altering the sensor electrical interface.
