[CmdletBinding()]
param(
    [string]$BackupRoot = (Join-Path $PSScriptRoot '..\data\printer-backups\work'),
    [string]$OutputRoot = (Join-Path $PSScriptRoot '..\analysis\components'),
    [ValidateSet('All', 'ChangedOnly')]
    [string]$Scope = 'All',
    [string]$GhidraImage = 'blacktop/ghidra@sha256:2561c4ef8a3eb4c851bf8ce7eec4737c93f067fe607d773af021b60a62bf6a68',
    [switch]$SkipDecompilation,
    [switch]$Force
)

$ErrorActionPreference = 'Stop'

function Get-RelativeUnixPath {
    param([Parameter(Mandatory)][string]$Base, [Parameter(Mandatory)][string]$Path)
    $basePath = [System.IO.Path]::GetFullPath($Base).TrimEnd('\', '/') + [System.IO.Path]::DirectorySeparatorChar
    $targetPath = [System.IO.Path]::GetFullPath($Path)
    $baseUri = [Uri]$basePath
    $targetUri = [Uri]$targetPath
    [Uri]::UnescapeDataString($baseUri.MakeRelativeUri($targetUri).ToString())
}

function Invoke-DockerTool {
    param(
        [Parameter(Mandatory)][string]$Workspace,
        [Parameter(Mandatory)][string[]]$Arguments
    )
    & docker run --rm --entrypoint sh -v "${Workspace}:/workspace" $GhidraImage -lc ($Arguments -join ' ')
    if ($LASTEXITCODE -ne 0) {
        throw "Docker analysis command failed with exit code $LASTEXITCODE"
    }
}

if (-not (Get-Command docker -ErrorAction SilentlyContinue)) {
    throw 'Docker is required. Install/start Docker Desktop first.'
}

$workspace = (Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$backupRootPath = (Resolve-Path $BackupRoot).Path
$outputRootPath = [System.IO.Path]::GetFullPath($OutputRoot)
New-Item -ItemType Directory -Force -Path $outputRootPath | Out-Null

$firmware = [ordered]@{
    '1.7.3' = Join-Path $backupRootPath '1.7.3\home\mks'
    '1.8.2' = Join-Path $backupRootPath '1.8.2\home\mks'
}

$records = @()
foreach ($version in $firmware.Keys) {
    $root = $firmware[$version]
    if (-not (Test-Path -LiteralPath $root)) {
        throw "Missing extracted backup root for $version`: $root"
    }

    $components = Get-ChildItem -LiteralPath $root -Recurse -File -Filter '*.so' |
        Where-Object {
            $_.FullName -match '[\\/]klipper[\\/]klippy[\\/]extras[\\/]' -or
            $_.FullName -match '[\\/]moonraker[\\/]moonraker[\\/]components[\\/]'
        }

    foreach ($component in $components) {
        $relative = Get-RelativeUnixPath -Base $root -Path $component.FullName
        $hash = (Get-FileHash -LiteralPath $component.FullName -Algorithm SHA256).Hash
        $records += [pscustomobject]@{
            Firmware = $version
            Component = [System.IO.Path]::GetFileNameWithoutExtension($component.Name)
            Subsystem = if ($relative.StartsWith('moonraker/')) { 'Moonraker' } else { 'Klipper' }
            RelativePath = $relative
            Bytes = $component.Length
            SHA256 = $hash
            SourcePath = $component.FullName
        }
    }
}

$groups = $records | Group-Object Component
foreach ($group in $groups) {
    $hashCount = @($group.Group.SHA256 | Select-Object -Unique).Count
    $presentVersions = @($group.Group.Firmware | Select-Object -Unique).Count
    foreach ($record in $group.Group) {
        $record | Add-Member -NotePropertyName ChangedBetweenReleases -NotePropertyValue ($hashCount -gt 1 -or $presentVersions -eq 1)
    }
}

if ($Scope -eq 'ChangedOnly') {
    $records = @($records | Where-Object ChangedBetweenReleases)
}

$manifestRecords = $records | Select-Object Firmware, Component, Subsystem, RelativePath, Bytes, SHA256, ChangedBetweenReleases
$manifestRecords | Sort-Object Firmware, Subsystem, Component |
    Export-Csv -LiteralPath (Join-Path $outputRootPath 'manifest.csv') -NoTypeInformation
$manifestRecords | Sort-Object Firmware, Subsystem, Component |
    ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $outputRootPath 'manifest.json') -Encoding utf8

foreach ($record in ($records | Sort-Object Firmware, Subsystem, Component)) {
    $componentDir = Join-Path $outputRootPath "$($record.Firmware)\$($record.Subsystem.ToLowerInvariant())\$($record.Component)"
    New-Item -ItemType Directory -Force -Path $componentDir | Out-Null

    $sourceContainer = '/workspace/' + (Get-RelativeUnixPath -Base $workspace -Path $record.SourcePath)
    $outputContainer = '/workspace/' + (Get-RelativeUnixPath -Base $workspace -Path $componentDir)

    Write-Host "[$($record.Firmware)] $($record.Subsystem)/$($record.Component)"
    $quotedSource = "'$sourceContainer'"
    $quotedOutput = "'$outputContainer'"
    Invoke-DockerTool -Workspace $workspace -Arguments @(
        "readelf -hW $quotedSource > $quotedOutput/elf-header.txt",
        "&& readelf -SW $quotedSource > $quotedOutput/sections.txt",
        "&& readelf -dW $quotedSource > $quotedOutput/dynamic.txt",
        "&& readelf -nW $quotedSource > $quotedOutput/notes.txt",
        "&& nm -an --demangle $quotedSource > $quotedOutput/symbols.txt",
        "&& strings -a -t x $quotedSource > $quotedOutput/strings.txt"
    )

    if (-not $SkipDecompilation) {
        $decompiledPath = Join-Path $componentDir 'decompiled.c'
        if ($Force -or -not (Test-Path -LiteralPath $decompiledPath)) {
            $projectName = ('qidi_' + $record.Firmware.Replace('.', '_') + '_' + $record.Component) -replace '[^A-Za-z0-9_]', '_'
            $scriptContainer = '/workspace/tools/ghidra'
            & docker run --rm --entrypoint /ghidra/support/analyzeHeadless `
                -v "${workspace}:/workspace" $GhidraImage `
                /tmp $projectName `
                -import $sourceContainer `
                -scriptPath $scriptContainer `
                -postScript ExportCythonDecompilation.java "$outputContainer/decompiled.c" "$outputContainer/disassembly.txt" `
                -deleteProject
            if ($LASTEXITCODE -ne 0) {
                throw "Ghidra decompilation failed for $($record.SourcePath) with exit code $LASTEXITCODE"
            }
        }
    }
}

Write-Host "Reference exported to $outputRootPath"
