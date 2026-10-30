# Integration research

[All documentation](../README.md) · [Repository home](../../README.md)

These references explain compatibility and protocol findings. Each document
states the limits of the available evidence and implementation.

| Guide | Use it for |
| --- | --- |
| [AMS compatibility](AMS-COMPATIBILITY.md) | QIDI Box and third-party AMS interoperability |
| [Box and Cartographer Python conflict](BOX-CARTOGRAPHER-PYTHON-CONFLICT.md) | Compiled-Python compatibility and rebuilding Box modules |
| [Box configuration regeneration](QIDI-BOX-CONFIG-REGENERATION.md) | How stock `box_detect` recreates `box.cfg` and affects synchronization |
| [Happy Hare integration](HAPPY-HARE-INTEGRATION.md) | Box hardware interfaces and possible integration approaches |
| [Stock touchscreen bridge](SCREEN-BRIDGE.md) | Protocol evidence, capture plan, and replacement design |

## Implementations and related guides

- [Box modules and overlays](../../qidibox-modules/README.md).
- [Stock-screen bridge scaffold](../../screen-bridge/README.md), which does not yet control a printer.
- [Optional integration templates](../../mainline-addons/README.md).
- [Post-migration Happy Hare installation](../migration/HAPPY-HARE-INSTALLATION.md).
- [Stock-firmware fixes and compatibility overlays](../fixes/README.md).
