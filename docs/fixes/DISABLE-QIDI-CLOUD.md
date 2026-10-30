# Disabling the legacy QIDILink client on stock firmware

This note records a community-tested procedure for disabling the legacy
`QIDILink-client`/`udp_server` boot path. It is not a complete cloud-disable
procedure for every Plus4 firmware release.

On firmware 1.8.x, QIDI also ships Moonraker `mqtt` and `frp_manager`
components. Those components are separate from the legacy launcher and are not
disabled by the steps below. A printer that has been linked to QIDI Cloud may
therefore retain an outbound MQTT connection or allow the FRP service to be
re-enabled. Mainline Klipper/Moonraker omits these QIDI-specific components; see
[MAINLINE-MIGRATION.md](../migration/MAINLINE-MIGRATION.md).

## Firmware scope

- On older stock releases, `QIDILink-client.service` and
  `/root/QIDILink-client/udp_server` implement the remote-access path targeted
  by this procedure.
- QIDI's 1.7.3 payload already removes the normally named service and comments
  out the legacy launcher while retaining renamed files.
- Firmware 1.8.2 adds compiled Moonraker `mqtt` and `frp_manager` components.
  This repository has not validated a durable, update-safe way to remove those
  components from stock firmware, so this guide does not claim to disable them.

## Disable the legacy launcher

This reversible procedure comes from the qidi-community Plus4 Wiki
([`content/disable QIDILink-client`](https://github.com/qidi-community/Plus4-Wiki/tree/main/content/disable%20QIDILink-client)).

1. SSH in and become root:

   ```bash
   sudo -i
   ```

2. Stop and disable the service if it exists:

   ```bash
   systemctl disable --now QIDILink-client
   ```

3. Move its data directory so the launcher cannot find it:

   ```bash
   mv /root/QIDILink-client /root/QIDILink-client-DoNotTouch
   ```

   QIDI's own update payload uses the same destination name. If the source is
   already absent and the destination exists, do not run the command again.

4. Comment out the launch line if it is still active:

   ```bash
   sed -i 's!^/root/QIDILink-client/udp_server!#/root/QIDILink-client/udp_server!' \
     /root/xindi/build/start.sh
   ```

5. Mask the systemd unit:

   ```bash
   systemctl mask QIDILink-client
   ```

## Verify

After rebooting, verify the legacy path and inspect the newer components
separately:

```bash
systemctl is-enabled QIDILink-client
pgrep -a udp_server
systemctl status QIDILink-client --no-pager
pgrep -af 'frpc|moonraker'
```

The first command should report `masked`, and `pgrep -a udp_server` should
produce no output. The final command is diagnostic only: Moonraker itself is
expected to be present, and a process listing cannot prove that MQTT is
disconnected. Check Moonraker's log for MQTT connection messages and use
network-level egress blocking when a strict no-cloud guarantee is required.

## Reverse and cautions

To reverse the legacy change, unmask and enable the unit, restore the
`start.sh` line, and rename the data directory back. Vendor firmware updates
may overwrite any of these changes, so re-check after updating.

These are owner actions on your own device. QIDI Link is not required for
normal local printing.

## Credit

Legacy procedure from the qidi-community Plus4 Wiki (MIT). Firmware-version
scope and analysis are original to this repository.
