# Reusing the QIDI Plus4 stock touchscreen

> **Status:** research scaffold. Nothing here should replace `xindi` on a
> working printer yet. The code under [`../screen-bridge/`](../screen-bridge/)
> cannot currently control the screen or printer.

## Goal

Retain the stock 800x480 front panel as an optional secondary local interface
after migrating the host to mainline Klipper and Moonraker. A separate
KlipperScreen, Mainsail, or Fluidd instance remains the complete UI and recovery
path. The stock screen bridge must never become necessary for heaters to shut
down, a print to stop, or the printer to boot.

This is an independent implementation project, not an attempt to display
KlipperScreen on the stock hardware and not a dependency on FreeDi releases.

## Confirmed architecture

The following facts are supported by the two printer backups and live read-only
checks of `qidi1` (1.8.2 with Box) and `qidi2` (1.7.3):

- `makerbase-client.service` starts `/root/xindi/build/xindi localhost`.
- The front panel communicates through `/dev/ttyS1`.
- Neither printer exposes the front panel as `/dev/fb*`.
- Touchscreen updates copy a resource to `/root/800_480.tft` and invoke
  `/root/uart`.
- The update helper uses the `whmi-wri` download command associated with
  TJC/Nextion-style displays.
- Retained `xindi` symbols include `parse_cmd_msg_from_tjc_screen`,
  `tjc_event_clicked_handler`, `tjc_event_keyboard`,
  `json_update_moonraker`, and `json_get_moonraker_process_stats`.
- The 1.8.2 binary and touchscreen resources differ from 1.7.3. Versioned
  profiles are therefore required.
- The 1.8.2 UI adds substantial `multi_color_controller` and QIDI Box state.

Additional read-only inspection of the connected `qidi1` screen on 2026-07-13
confirmed:

- `xindi` exclusively held `/dev/ttyS1` on file descriptor 12;
- the active UART configuration was 115200 baud, raw 8N1, with hardware and
  software flow control disabled;
- the UART is the RK3328 `ff120000.serial` 16550A controller;
- `/root/xindi/version` reported UI `V182` and SoC release `V1.8.2`;
- `/root/800_480.tft.bak` was 20,540,552 bytes with SHA-256
  `a64a9c470b6bf8784272c0aba885ad567f1c5596aeb54ad9e8e0161a99b19397`;
- printable `xindi` command templates include `sendme`, `page`, `click`, `ref`,
  and `vis`, consistent with the TJC/Nextion command family.

The connected 1.7.3 screen was subsequently confirmed to use the same 115200
baud raw 8N1 settings. It reports UI `V173`; its 20,480,808-byte screen resource
has SHA-256
`3374f5eb770696f6c3458d0dc53de4e3ca419ec10114744d2dcbdf708793dc25`.
These observations are recorded in both profiles. File descriptor numbers are
process-instance details and must not be hard-coded.

The inferred integration boundary is:

```text
stock TJC HMI <-- UART --> screen bridge <-- WebSocket/HTTP --> Moonraker
                                                                |
                                                             Klipper
```

The panel renders its own compiled pages. The host updates fields and changes
pages with serial commands; button and keyboard events travel back over UART.

## Confirmed versus provisional protocol details

`0xff 0xff 0xff` command termination and common response packets such as touch
event `0x65`, page `0x66`, string `0x70`, and number `0x71` are implemented as
provisional TJC/Nextion-family framing. They are useful for decoding captures,
but each behaviour must be confirmed against the Plus4 panel before it becomes
a control-path contract.

Still unknown:

- every page and component identifier;
- names of screen properties written by `xindi`;
- QIDI-specific event payloads and keyboard encoding;
- startup handshake, reconnect, sleep, wake, and error recovery;
- text encoding used by every field;
- 1.8.2 QIDI Box page mappings;
- which actions are handled locally versus translated into G-code/API calls.

The JSON profiles intentionally preserve these as explicit unknowns. Do not
fill them from memory or generic Nextion documentation alone.

## Safe capture plan

### 1. Record the process and serial configuration

Before attaching to anything, record the executable, file descriptors, and
termios configuration on both stock releases. Avoid printing environment
variables or configuration files that may contain credentials.

```console
pid=$(pidof xindi)
sudo readlink -f /proc/$pid/fd/*
sudo stty -F /dev/ttyS1 -a
```

On `qidi1`, `stty` confirmed the active 115200 baud raw 8N1 configuration while
`xindi` owned the UART. Repeat this check on each screen release; capturing the
relevant `termios` system call during service startup remains stronger evidence.

### 2. Capture an interaction matrix

For each release, start from a known page and perform one action at a time:

- idle boot and screen wake;
- open and close every page;
- tap and hold each control;
- edit numeric and text fields;
- home and jog one axis at a time with motion made physically safe;
- preheat and cooldown without filament;
- begin, pause, resume, and cancel a short test print;
- induce only safe, reversible warning states;
- on 1.8.2, visit every Box page and change one slot/state at a time.

Record the screen, UART direction, timestamp, Moonraker request/event, and
result. Never infer command semantics from a single occurrence.

### 3. Obtain bidirectional UART evidence

The scaffold's `capture` command is read-only but cannot see bytes written by a
different process. Suitable research methods, in order of preference, are:

1. trace `xindi` read/write system calls on a stock printer and correlate file
   descriptors to `/dev/ttyS1`;
2. use a logic analyser or a second UART receiver on the host-to-screen and
   screen-to-host lines, with common ground and verified voltage levels;
3. stop `xindi` and use the scaffold against a disconnected/spare test setup.

Do not connect two active transmitters to one UART line. Do not attach 5 V test
equipment until the electrical levels have been measured.

Raw traces should remain under ignored `data/` storage. Commit only minimized,
annotated fixtures with private data removed.

## Implementation stages

### Stage A: passive decoder

- Confirm framing, baud, startup, and event decoding.
- Build anonymized fixtures for both screen releases.
- Populate page/component profiles only from repeatable evidence.
- Do not transmit to the panel or connect to Moonraker.

### Stage B: read-only status display

- Add a Moonraker WebSocket client using ordinary mainline APIs.
- Subscribe to a small set of stable objects.
- Update temperatures, printer state, coordinates, and print progress.
- Ignore all touch actions except navigation implemented inside the panel.
- Require an explicit command-line flag before opening the UART for writes.

### Stage C: allow-listed controls

- Map individual, reviewed touch events to named actions.
- Prefer Moonraker APIs and dedicated macros over arbitrary G-code text.
- Reject parameters outside configured limits.
- Debounce duplicate touch events and make operations idempotent where possible.
- Begin with pause/resume/cancel and temperature presets; add motion last.

### Stage D: material-system adapter

Define an internal material model independent of QIDI, Happy Hare, or AFC.
Adapters can translate `mmu`, AFC, or another backend into this model, while a
screen profile maps it to the stock UI. This avoids embedding one project's
object schema throughout the serial implementation.

The 1.8.2 Box screen expects QIDI's nested `multi_color_controller` state. That
schema is documented in [AMS-COMPATIBILITY.md](AMS-COMPATIBILITY.md), but
translation should be implemented only after ordinary printer controls are
stable.

## Safety model

- Read-only is the default at every layer.
- Screen writes and printer actions require separate explicit enablement.
- No generic "execute this string" mapping in a profile.
- Actions use a fixed registry with validated typed parameters.
- Heating limits come from bridge configuration and must not exceed Klipper's.
- Motion commands require homing state and conservative bounds.
- Loss of the bridge or panel leaves Klipper and Moonraker unaffected.
- The service runs unprivileged with only UART group access.
- Installation must preserve an SSH/web UI recovery path.
- Every profile records its exact touchscreen resource hash once known.

## Clean-room and redistribution boundary

The implementation should be based on observed external behaviour, published
source, retained public symbols, and documented mainline APIs. Keep recovered
pseudocode and proprietary binaries in the analysis/reference area; do not copy
QIDI implementation text into the new Python package.

Do not redistribute `/root/800_480.tft`, backups, credentials, databases, or
QIDI binaries unless their licence clearly permits it. A future installer can
extract and hash the resource already owned by the printer operator.

## Definition of the first usable milestone

The first milestone is intentionally modest: on both 1.7.3 and 1.8.2 panels,
the bridge starts after Moonraker, identifies the configured profile, displays
accurate idle/printing temperatures and progress, logs unknown events, performs
no printer action, and can be disabled without changing Klipper configuration.
