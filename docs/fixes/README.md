# Fixes and compatibility

[All documentation](../README.md) · [Repository home](../../README.md)

Choose the guide for the observed problem and check its firmware and hardware
scope before using its installation procedure.

| Guide | Problem or task |
| --- | --- |
| [Install the log-space and Box status fixes](INSTALL-LOG-AND-BOX-FIXES.md) | Beginner-friendly installation for the fixes used on QIDI1 with stock 1.8.2 |
| [PLR `Timer too close` repair](PLR-TIMER-TOO-CLOSE.md) | Diagnosed stock power-loss-recovery failure, transactional repair and rollback |
| [Box output clock guard](QIDI-BOX-OUTPUT-CLOCK-GUARD.md) | Stock-1.8.2 output scheduling with the MCU that owns each pin |
| [Box status compatibility](QIDI-BOX-STATUS-COMPAT.md) | Missing tool-change status property in stock 1.8.2 Box modules |
| [Box watchdog resets](QIDI-BOX-WATCHDOG-RESET.md) | PB0 interrupt/debounce forensics, containment, and hardware isolation |
| [Disable QIDILink](DISABLE-QIDI-CLOUD.md) | Disable the legacy cloud client on stock firmware |

Implementations live in [plr-hardening/](../../plr-hardening/README.md) and
[qidibox-modules/](../../qidibox-modules/README.md).
For broader Box compatibility questions, see [integration research](../integrations/README.md).
