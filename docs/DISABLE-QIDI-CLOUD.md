# Disabling QIDI cloud / QIDILink on stock firmware

This note is for owners who want to keep stock QIDI firmware but stop the
printer from reaching QIDI's cloud and from being reachable through it. It ties
the repository's firmware analysis to a community-tested disable procedure. If
you are migrating to mainline Klipper instead, none of this is needed — the
mainline stack omits the cloud components entirely (see
[MAINLINE-MIGRATION.md](MAINLINE-MIGRATION.md)).

## What the cloud stack is

From the firmware analysis, QIDI's remote-access path on 1.8.x is built from a
few cooperating pieces:

- **`QIDILink-client`** — a compiled binary in `/root`, started at boot from
  `/root/xindi/build/start.sh` (it launches a `udp_server` helper). It is not
  packaged; it runs as root.
- **Moonraker `mqtt` + `frp_manager` components** — an always-on MQTT control
  channel and an FRP (fast reverse proxy) tunnel that together let the cloud
  issue Moonraker API calls, start remote prints, and open an inbound tunnel.
  See [FIRMWARE-CHANGES.md](FIRMWARE-CHANGES.md).

The security concern is that enabling QIDI Link associates the printer with a
publicly reachable cloud endpoint; the community has reported that a linked
printer can be controlled by anyone who knows its URL. Disabling it removes both
the outbound channel and the inbound tunnel.

## Disable procedure (stock firmware)

This is the community-tested procedure from the qidi-community Plus4 Wiki
([`content/disable QIDILink-client`](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/disable%20QIDILink-client)),
recorded here with attribution. It is reversible; note each change so you can
undo it.

1. SSH in and become root:

   ```bash
   sudo -i     # authenticate with the mks account password
   ```

2. Stop and disable the service:

   ```bash
   systemctl stop QIDILink-client
   systemctl disable --now QIDILink-client
   ```

3. Move its data directory so the launcher cannot find it:

   ```bash
   mv /root/QIDILink-client /root/QIDILink-client-DoNotTouch
   ```

   (QIDI's own 1.8.2 update payload already renames it this way, so the name is
   consistent with vendor behaviour.)

4. Comment out the launch line in the boot script:

   ```bash
   sed -i 's!^/root/QIDILink-client/udp_server!#/root/QIDILink-client/udp_server!' \
     /root/xindi/build/start.sh
   ```

5. Mask the systemd unit so it cannot be re-activated:

   ```bash
   mv -v /etc/systemd/system/QIDILink-client.service{,.masked}
   systemctl mask QIDILink-client
   ```

## Verify and reverse

- Verify: `systemctl is-enabled QIDILink-client` should report `masked`, and the
  process should be gone (`pgrep -a udp_server` returns nothing after a reboot).
- Reverse: unmask the unit, restore the `start.sh` line, and rename the data
  directory back.

## Scope and cautions

- This targets the `QIDILink-client`/`udp_server` boot path. QIDI's Moonraker
  `mqtt`/`frp_manager` components are separate; a QIDI Box printer that never
  linked to the cloud generally does not bring up the FRP tunnel, but if you
  have linked before, also confirm no FRP service is enabled.
- Editing `start.sh` and masking a vendor service can be overwritten by a future
  QIDI firmware update; re-check after updating.
- These are owner actions on your own device. Nothing here is required for
  normal local printing; QIDI Link is an opt-in convenience feature.

## Credit

Procedure from the qidi-community Plus4 Wiki (MIT). This document adds the
firmware-analysis context and is original to this repository.
