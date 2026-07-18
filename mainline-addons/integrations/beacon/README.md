# Beacon integration

Beacon remains an external Klipper module, so it is separate from the
dependency-free add-ons. Follow the current upstream installation first:

```bash
cd ~
git clone https://github.com/beacon3d/beacon_klipper.git
./beacon_klipper/install.sh
```

On a minimal Armbian host, install the compatibility command expected by
Beacon's directly executable updater before restarting Klipper:

```bash
sudo apt-get install -y python-is-python3
```

Without it, Beacon can still connect, but `klippy.log` may show the firmware
check exiting with status 127 because `/usr/bin/env python` is unavailable.

Review `beacon.cfg.example`, replace the serial and geometry placeholders, and
merge it into the machine configuration. Do not use `[safe_z_home]` with
Beacon's current built-in homing workflow. Always disconnect Beacon at USB or
power the printer down before touching the sensor-end cable.

For RevH, the accelerometer is exposed as `beacon`; the example points
`[resonance_tester]` at it. Calibrate the scanner/contact model again after a
host migration or sensor replacement rather than copying saved model data.

`PLUS4_ADAPTIVE_MESH METHOD=rapid_scan` can be used only after normal Beacon
scanning and a full-bed mesh have been validated.

References:

- [Beacon quick start](https://docs.beacon3d.com/quickstart/)
- [Beacon contact homing](https://docs.beacon3d.com/contact/)
