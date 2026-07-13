#requires -Version 5.1

<#
.SYNOPSIS
Backs up one or more QIDI Plus4 printers over SSH/SCP before migration.

.EXAMPLE
.\tools\Backup-QidiPlus4.ps1 `
    -Printer 'box=192.168.1.50','no-box=192.168.1.51'

.EXAMPLE
.\tools\Backup-QidiPlus4.ps1 -Printer 'plus4.local' -IncludeLogs -Expand

.NOTES
Each -Printer value may be either HOST or NAME=HOST. The default SSH user is
"mks". Password authentication is supported, although SSH keys are preferable.
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory, Position = 0)]
    [ValidateNotNullOrEmpty()]
    [string[]] $Printer,

    [ValidateNotNullOrEmpty()]
    [string] $User = 'mks',

    [ValidateRange(1, 65535)]
    [int] $Port = 22,

    [ValidateNotNullOrEmpty()]
    [string] $OutputDirectory = (Join-Path $PSScriptRoot '..\data\printer-backups'),

    [switch] $IncludeGcodes,
    [switch] $IncludeLogs,
    [switch] $IncludeEnvironments,
    [switch] $Expand
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

function Get-RequiredCommand {
    param([Parameter(Mandatory)][string] $Name)

    $command = Get-Command $Name -ErrorAction SilentlyContinue
    if (-not $command) {
        throw "Required command '$Name' was not found. Install the Windows OpenSSH Client feature and try again."
    }
    $command.Source
}

function Invoke-NativeCommand {
    param(
        [Parameter(Mandatory)][string] $FilePath,
        [Parameter(Mandatory)][string[]] $ArgumentList,
        [Parameter(Mandatory)][string] $Description,
        [switch] $DiscardOutput
    )

    Write-Host "  $Description"
    if ($DiscardOutput) {
        & $FilePath @ArgumentList | Out-Null
    }
    else {
        & $FilePath @ArgumentList
    }
    if ($LASTEXITCODE -ne 0) {
        throw "$Description failed with exit code $LASTEXITCODE."
    }
}

function Invoke-NativeCommandToFile {
    param(
        [Parameter(Mandatory)][string] $FilePath,
        [Parameter(Mandatory)][string[]] $ArgumentList,
        [Parameter(Mandatory)][string] $OutputPath,
        [Parameter(Mandatory)][string] $Description
    )

    Write-Host "  $Description"
    Remove-Item -LiteralPath $OutputPath -Force -ErrorAction SilentlyContinue
    $process = Start-Process -FilePath $FilePath `
        -ArgumentList $ArgumentList `
        -RedirectStandardOutput $OutputPath `
        -NoNewWindow -Wait -PassThru
    if ($process.ExitCode -ne 0) {
        throw "$Description failed with exit code $($process.ExitCode). Partial output is at '$OutputPath'."
    }
}

function ConvertTo-SafeName {
    param([Parameter(Mandatory)][string] $Value)

    $safe = $Value -replace '[^A-Za-z0-9._-]', '-'
    $safe = $safe.Trim('-')
    if (-not $safe) { return 'qidi-plus4' }
    $safe
}

$ssh = Get-RequiredCommand -Name 'ssh'
$scp = Get-RequiredCommand -Name 'scp'
$tar = Get-Command 'tar' -ErrorAction SilentlyContinue

$outputRoot = [IO.Path]::GetFullPath($OutputDirectory)
[IO.Directory]::CreateDirectory($outputRoot) | Out-Null

# This helper runs on the printer. Only its small inventory is staged in /tmp;
# the compressed tar stream is written to stdout and captured directly on the
# Windows machine. Paths in the tarball are relative to /.
$remoteHelper = @'
#!/bin/sh
set -eu

manifest="$1"
include_gcodes="$2"
include_logs="$3"
include_envs="$4"

umask 077
: > "$manifest"

section() {
    printf '\n===== %s =====\n' "$1" >> "$manifest"
}

run_info() {
    title="$1"
    shift
    section "$title"
    "$@" >> "$manifest" 2>&1 || true
}

run_info "backup time" date -u
run_info "hostname" hostname
run_info "kernel" uname -a
run_info "os release" cat /etc/os-release
run_info "disk usage" df -h
run_info "memory" free -h
run_info "network addresses" ip addr
run_info "USB devices" sh -c 'command -v lsusb >/dev/null 2>&1 && lsusb || true'
run_info "serial devices" sh -c 'ls -la /dev/serial/by-id /dev/serial/by-path 2>/dev/null || true'
run_info "QIDI config.mksini locations" sh -c 'find /home/mks -maxdepth 5 -name config.mksini -type f -print 2>/dev/null || true'
run_info "Klipper service" sh -c 'systemctl cat klipper 2>/dev/null || service klipper status 2>/dev/null || true'
run_info "Moonraker service" sh -c 'systemctl cat moonraker 2>/dev/null || service moonraker status 2>/dev/null || true'
run_info "enabled services" sh -c 'systemctl list-unit-files --state=enabled 2>/dev/null || true'
run_info "installed packages" sh -c 'dpkg-query -W -f="${binary:Package}\t${Version}\n" 2>/dev/null || true'

section "source repositories"
find /home/mks -maxdepth 3 -type d -name .git 2>/dev/null | sort | while IFS= read -r gitdir; do
    repo=${gitdir%/.git}
    printf '\n--- %s ---\n' "$repo" >> "$manifest"
    git -C "$repo" remote -v >> "$manifest" 2>&1 || true
    git -C "$repo" describe --always --tags --dirty >> "$manifest" 2>&1 || true
    git -C "$repo" status --short >> "$manifest" 2>&1 || true
    git -C "$repo" diff --stat >> "$manifest" 2>&1 || true
done

section "Python environments"
for pip in /home/mks/*-env/bin/pip /home/mks/*_env/bin/pip; do
    [ -x "$pip" ] || continue
    printf '\n--- %s ---\n' "$pip" >> "$manifest"
    "$pip" freeze >> "$manifest" 2>&1 || true
done

if command -v sudo >/dev/null 2>&1 && sudo -n true 2>/dev/null; then
    tar_command="sudo -n tar"
    has_passwordless_sudo="1"
    printf '\nPasswordless sudo: yes\n' >> "$manifest"
else
    tar_command="tar"
    has_passwordless_sudo="0"
    printf '\nPasswordless sudo: no; unreadable root-owned paths may be absent.\n' >> "$manifest"
fi

# Archive the full QIDI user installation, plus system/service/boot state and
# known QIDI application locations. Missing paths are intentionally ignored.
paths="home/mks etc/systemd/system lib/systemd/system etc/init.d etc/default etc/network etc/NetworkManager boot root/xindi usr/data usr/share/klipper"
existing=""
section "archived roots"
for path in $paths; do
    if { [ "$has_passwordless_sudo" = "1" ] && sudo -n test -e "/$path"; } || [ -e "/$path" ]; then
        existing="$existing $path"
        printf '%s\n' "/$path" >> "$manifest"
    fi
done

if [ -z "$existing" ]; then
    echo "No expected backup paths were found." >&2
    exit 3
fi

exclude_args="--exclude=home/mks/.cache --exclude=home/mks/printer_data/comms"
[ "$include_gcodes" = "1" ] || exclude_args="$exclude_args --exclude=home/mks/printer_data/gcodes"
[ "$include_logs" = "1" ] || exclude_args="$exclude_args --exclude=home/mks/printer_data/logs --exclude=home/mks/printer_data/timelapse"
if [ "$include_envs" != "1" ]; then
    exclude_args="$exclude_args --exclude=home/mks/klippy-env --exclude=home/mks/moonraker-env --exclude=home/mks/crowsnest-env --exclude=home/mks/*-env --exclude=home/mks/*_env"
fi

chmod 600 "$manifest"

# stdout must contain only the gzip stream. Informational output belongs in
# the manifest or on stderr so the local archive cannot be corrupted.
# shellcheck disable=SC2086
$tar_command -C / -czf - --ignore-failed-read --warning=no-file-changed $exclude_args $existing
'@

$tempHelper = Join-Path ([IO.Path]::GetTempPath()) ("qidi-backup-{0}.sh" -f [guid]::NewGuid().ToString('N'))
[IO.File]::WriteAllText($tempHelper, ($remoteHelper -replace "`r`n", "`n"), [Text.UTF8Encoding]::new($false))

$sshOptions = @(
    '-p', $Port.ToString(),
    '-o', 'ServerAliveInterval=15',
    '-o', 'ServerAliveCountMax=4',
    '-o', 'StrictHostKeyChecking=accept-new'
)
$scpOptions = @(
    '-P', $Port.ToString(),
    '-o', 'ServerAliveInterval=15',
    '-o', 'ServerAliveCountMax=4',
    '-o', 'StrictHostKeyChecking=accept-new'
)

$completed = @()
try {
    foreach ($printerSpec in $Printer) {
        $name = $printerSpec
        $hostName = $printerSpec
        $separator = $printerSpec.IndexOf('=')
        if ($separator -ge 0) {
            $name = $printerSpec.Substring(0, $separator)
            $hostName = $printerSpec.Substring($separator + 1)
        }
        if ([string]::IsNullOrWhiteSpace($hostName)) {
            throw "Invalid printer specification '$printerSpec'. Use HOST or NAME=HOST."
        }

        $safeName = ConvertTo-SafeName -Value $name
        $timestamp = Get-Date -Format 'yyyyMMdd-HHmmss'
        $baseName = "qidi-plus4-$safeName-$timestamp"
        $remoteScript = "/tmp/$baseName-backup.sh"
        $remoteManifest = "/tmp/$baseName-manifest.txt"
        $destination = Join-Path $outputRoot $safeName
        [IO.Directory]::CreateDirectory($destination) | Out-Null

        $localArchive = Join-Path $destination "$baseName.tar.gz"
        $localChecksum = "$localArchive.sha256"
        $partialArchive = "$localArchive.partial"
        $localManifest = Join-Path $destination "$baseName-manifest.txt"
        $remote = "$User@$hostName"

        Write-Host "`nBacking up '$name' from $remote ..." -ForegroundColor Cyan
        # Remove partial archives left by versions of this script that staged
        # the tarball in /tmp. The name is sanitized before use here.
        $oldRemoteFiles = "/tmp/qidi-plus4-$safeName-*.tar.gz /tmp/qidi-plus4-$safeName-*.tar.gz.sha256 /tmp/qidi-plus4-$safeName-*-manifest.txt /tmp/qidi-plus4-$safeName-*-backup.sh"
        $oldRemoteCleanup = "if sudo -n true 2>/dev/null; then sudo -n rm -f $oldRemoteFiles; else rm -f $oldRemoteFiles; fi"
        Invoke-NativeCommand -FilePath $ssh -ArgumentList ($sshOptions + @($remote, $oldRemoteCleanup)) -Description 'Remove partial backups left in remote /tmp'
        Invoke-NativeCommand -FilePath $scp -ArgumentList ($scpOptions + @($tempHelper, "${remote}:$remoteScript")) -Description 'Upload temporary backup helper'

        $remoteArgs = @(
            'sh',
            $remoteScript,
            $remoteManifest,
            $(if ($IncludeGcodes) { '1' } else { '0' }),
            $(if ($IncludeLogs) { '1' } else { '0' }),
            $(if ($IncludeEnvironments) { '1' } else { '0' })
        )
        Invoke-NativeCommandToFile -FilePath $ssh `
            -ArgumentList ($sshOptions + @($remote) + $remoteArgs) `
            -OutputPath $partialArchive `
            -Description 'Stream compressed archive directly to this computer'
        Move-Item -LiteralPath $partialArchive -Destination $localArchive -Force

        Invoke-NativeCommand -FilePath $scp -ArgumentList ($scpOptions + @("${remote}:$remoteManifest", $localManifest)) -Description 'Download readable inventory'

        $actualHash = (Get-FileHash -LiteralPath $localArchive -Algorithm SHA256).Hash.ToUpperInvariant()
        $checksumLine = "$actualHash  $([IO.Path]::GetFileName($localArchive))`n"
        [IO.File]::WriteAllText($localChecksum, $checksumLine, [Text.UTF8Encoding]::new($false))
        Write-Host "  SHA-256 recorded: $actualHash" -ForegroundColor Green

        if ($tar) {
            Invoke-NativeCommand -FilePath $tar.Source -ArgumentList @('-tzf', $localArchive) -Description 'Test archive readability' -DiscardOutput
        }

        if ($Expand) {
            $expandTo = Join-Path $destination $baseName
            [IO.Directory]::CreateDirectory($expandTo) | Out-Null
            if (-not $tar) {
                throw "The -Expand option requires a local 'tar' command. The verified archive is still available at '$localArchive'."
            }
            Invoke-NativeCommand -FilePath $tar.Source -ArgumentList @('-xzf', $localArchive, '-C', $expandTo) -Description 'Expand verified archive'
        }

        $cleanup = "rm -f $remoteScript $remoteManifest"
        Invoke-NativeCommand -FilePath $ssh -ArgumentList ($sshOptions + @($remote, $cleanup)) -Description 'Remove temporary remote files'

        $completed += [pscustomobject]@{
            Printer = $name
            Host = $hostName
            Archive = $localArchive
            Manifest = $localManifest
            SHA256 = $actualHash
        }
    }
}
finally {
    Remove-Item -LiteralPath $tempHelper -Force -ErrorAction SilentlyContinue
}

Write-Host "`nBackup complete." -ForegroundColor Green
$completed | Format-Table Printer, Host, Archive -AutoSize

Write-Warning 'These archives may contain Wi-Fi credentials, API keys, database contents, and SSH material. Store them securely and do not commit them to Git.'
Write-Warning 'This is a filesystem backup, not an eMMC image or MCU flash readback. Installed MCU firmware normally cannot be recovered over SCP; compiled Klipper artifacts under /home/mks/klipper/out are included when present.'
