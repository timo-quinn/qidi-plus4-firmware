# Mainline printer configurations

These are reviewed commissioning and operating profiles for Plus4 hardware
after the MCUs and host have been migrated to upstream Klipper. They are not
factory profiles and they do not contain calibration copied from another
printer.

Current profile:

- [`plus4-x7-v1.0-beacon/`](plus4-x7-v1.0-beacon/) — X-7 V1.0 mainboard,
  upstream Klipper on both UART MCUs, Beacon Rev H, and no QIDI Box.

Render a per-printer copy with `qidi_plus4.py render-config`; do not edit the
tracked serial placeholder or add `SAVE_CONFIG` output to this directory.
Commission the generated hardware profile before using its `operations.cfg`.
