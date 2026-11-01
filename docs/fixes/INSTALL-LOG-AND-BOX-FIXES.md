# Install the Plus4 log-space and QIDI Box status fixes

These are the fixes used on QIDI1 with **stock QIDI firmware 1.8.2**:

- Keep system logs from filling the small `/var/log` area, including old logs
  copied back into it at startup.
- Fix the QIDI Box error: `'ToolChange' object has no attribute 'is_tool_change'`.

Allow about 10 minutes. Finish any print first, including paused prints. You
need a computer on the same network, the printer's IP address (shown in its
network settings), and its SSH password. Apply either fix independently.

## 1. Connect to the printer

Open **Terminal** (macOS/Linux) or **PowerShell** (Windows). Replace
`PRINTER_IP` below with your printer's address, for example `192.168.1.50`:

```sh
ssh mks@PRINTER_IP
```

On your first connection, check that the address is your printer's and accept
the connection prompt. Enter the printer's SSH password; nothing appears as
you type. All remaining command blocks go into this SSH window, **not the
Fluidd console**. Copy a whole block, including any `EOF` lines, and press
Enter. If a command reports an error, stop before the next step.

Create a backup, keeping this SSH window open for the rest of the guide:

```sh
backup="$HOME/qidi-fixes-backup-$(date +%Y%m%d-%H%M%S)"
mkdir -p "$backup"
cp -a ~/printer_data/config/printer.cfg "$backup/"
echo "Backup: $backup"
```

If you use Klippee or another config sync tool, make the configuration edit
in section 3 through that tool so a later sync retains it.

## 2. Keep the system logs within their available space

This section is for the stock Armbian layout. Check it first:

```sh
df -h /var/log /var/log.hdd
sudo du -sh /var/log/journal /var/log.hdd/journal
```

Expect roughly **49–50 MB** for `/var/log`, with `/var/log.hdd` on the much
larger disk. If those paths are missing or your layout differs, skip this
section. This fix targets the system journal; it does not limit `klippy.log`.

Save recent diagnostics and the existing settings. The cleanup below removes
older journal history; download any other logs you want to keep first.

```sh
sudo journalctl -b --since "1 hour ago" --no-pager > "$backup/recent-journal.txt"
sudo mkdir -p "$backup/log-settings"
for f in /etc/systemd/journald.conf.d/zz-qidi-log-limits.conf /etc/systemd/system/qidi-journal-archive-cleanup.service /etc/systemd/system/qidi-journal-archive-cleanup.timer; do
    if [ -f "$f" ]; then sudo cp -a "$f" "$backup/log-settings/"; fi
done
```

Paste this block to install the size limits and automatic cleanup:

```sh
sudo mkdir -p /etc/systemd/journald.conf.d
sudo tee /etc/systemd/journald.conf.d/zz-qidi-log-limits.conf > /dev/null <<'EOF'
[Journal]
SystemMaxUse=16M
SystemKeepFree=16M
SystemMaxFileSize=2M
SystemMaxFiles=8
RuntimeMaxUse=8M
RuntimeKeepFree=16M
RuntimeMaxFileSize=2M
MaxRetentionSec=7day
RateLimitIntervalSec=30s
RateLimitBurst=1000
EOF
sudo tee /etc/systemd/system/qidi-journal-archive-cleanup.service > /dev/null <<'EOF'
[Unit]
Description=Bound Armbian disk journal backups before the next boot
After=armbian-ramlog.service
ConditionPathIsDirectory=/var/log.hdd/journal

[Service]
Type=oneshot
Nice=19
IOSchedulingClass=idle
ExecStart=/usr/bin/journalctl --quiet --directory=/var/log.hdd/journal --vacuum-size=12M --vacuum-files=8 --vacuum-time=7day
EOF
sudo tee /etc/systemd/system/qidi-journal-archive-cleanup.timer > /dev/null <<'EOF'
[Unit]
Description=Regular cleanup of Armbian journal backups

[Timer]
OnBootSec=2min
OnUnitActiveSec=15min
AccuracySec=1min

[Install]
WantedBy=timers.target
EOF
```

Activate it and clear excess archived journals now:

```sh
sudo systemctl daemon-reload
sudo systemctl restart systemd-journald
sudo journalctl --rotate --vacuum-size=16M --vacuum-files=8 --vacuum-time=7day
sudo systemctl start qidi-journal-archive-cleanup.service
sudo systemctl enable --now qidi-journal-archive-cleanup.timer
systemctl is-active systemd-journald qidi-journal-archive-cleanup.timer
df -h /var/log
```

The status check should print **`active` twice**, and `/var/log` should have
free space. Cleanup runs about every 15 minutes. Journal sizes can be slightly
above the targets because [cleanup only removes archived journal files](https://www.freedesktop.org/software/systemd/man/254/journalctl.html).
If `/var/log` stays full, stop here and get help rather than deleting its contents.

## 3. Fix the QIDI Box `is_tool_change` error

Skip this section if you do not use a QIDI Box. Keep the Box connected and
powered on. Download the small compatibility file, check its Python syntax,
and install it:

```sh
if [ -f ~/klipper/klippy/extras/box_status_compat.py ]; then
    cp -a ~/klipper/klippy/extras/box_status_compat.py "$backup/"
fi
curl -fL --connect-timeout 15 --max-time 60 https://raw.githubusercontent.com/timo-quinn/qidi-plus4-firmware/main/qidibox-modules/box_status_compat.py -o "$backup/box_status_compat.new.py" &&
~/klippy-env/bin/python -m py_compile "$backup/box_status_compat.new.py" &&
install -m 644 "$backup/box_status_compat.new.py" ~/klipper/klippy/extras/box_status_compat.py
```

In **Fluidd → Configuration**, download a backup of `printer.cfg`, then edit
it. Find `[include box.cfg]` and add the following on its own line below it.
Add it only once; if `[box_status_compat]` already exists in an included file,
leave that section in place instead.

```ini
[box_status_compat]
```

Save the file. Back in SSH, restart the Klipper service:

```sh
sudo systemctl restart klipper
```

Wait about a minute, then refresh Fluidd. It should say **Ready**. A Fluidd
`RESTART` or `FIRMWARE_RESTART` alone does not reliably reload a Python file.
Do not put the new section in `box.cfg`: QIDI regenerates that file.

To check the fix, open this address in your computer's browser, replacing
`PRINTER_IP` as before:

```text
http://PRINTER_IP:7125/printer/objects/query?box_status_compat&multi_color_controller
```

Look for **`"state": "corrected"`** (or `"already-provided"`) and
**`"error": null`** under `operation`. If it says `inactive-no-box`, Klipper
has not loaded the Box configuration; check the Box connection and wait for
detection to finish. This overlay keeps QIDI's existing Box modules and commands.

## If you need to undo a fix

- **Box:** remove only the `[box_status_compat]` section you added, save, and
  run `sudo systemctl restart klipper`. Restore the previous Python file from
  your backup if there was one; otherwise the unused file can remain.
- **Logs:** run `sudo systemctl disable --now qidi-journal-archive-cleanup.timer`.
  Remove the three files created in section 2, or restore their previous
  versions from your backup's `log-settings` folder if they existed. Then run
  `sudo systemctl daemon-reload` and `sudo systemctl restart systemd-journald`.
  Re-enable the timer if it was already installed before this guide. Removed
  journal history cannot be recovered except from your saved logs.

Keep your backup folder. After a QIDI firmware update, check both fixes again.
For technical background, see [Box status compatibility](QIDI-BOX-STATUS-COMPAT.md).
