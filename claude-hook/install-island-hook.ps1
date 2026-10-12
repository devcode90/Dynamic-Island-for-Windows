# install-island-hook.ps1
# One-time setup for the Claude tab of "Dynamic Island for Windows (+ Todoist, Mail, Claude)".
#
#   1. copies island-hook.ps1 to %USERPROFILE%\.claude\
#   2. registers it in %USERPROFILE%\.claude\settings.json for the events it needs
#      (a backup of settings.json is written first; running this twice is safe)
#
# Run from the folder containing both scripts:
#   powershell -ExecutionPolicy Bypass -File .\install-island-hook.ps1

$ErrorActionPreference = 'Stop'

# Windows PowerShell 5.1 otherwise serialises some arrays as {"value":[...],"Count":n}.
try { Remove-TypeData -TypeName System.Array -ErrorAction SilentlyContinue } catch {}

$claudeDir = Join-Path $env:USERPROFILE '.claude'
$hookTarget = Join-Path $claudeDir 'island-hook.ps1'
$settingsPath = Join-Path $claudeDir 'settings.json'
$source = Join-Path $PSScriptRoot 'island-hook.ps1'

if (-not (Test-Path $source)) { throw "island-hook.ps1 introuvable à côté de ce script ($source)." }
if (-not (Test-Path $claudeDir)) { New-Item -ItemType Directory -Path $claudeDir | Out-Null }

Copy-Item -Force $source $hookTarget
Write-Host "Hook copié : $hookTarget"

# Load settings.json (or start empty), backing it up first.
if (Test-Path $settingsPath) {
    $backup = "$settingsPath.bak-island"
    Copy-Item -Force $settingsPath $backup
    Write-Host "Sauvegarde : $backup"
    $settings = Get-Content -Raw -Encoding UTF8 $settingsPath | ConvertFrom-Json
} else {
    $settings = [pscustomobject]@{}
}

if (-not ($settings.PSObject.Properties.Name -contains 'hooks')) {
    $settings | Add-Member -NotePropertyName hooks -NotePropertyValue ([pscustomobject]@{})
}

# Shell form (one command string, no "args"): works whether Claude Code runs
# hooks through Git Bash or PowerShell, and on versions without exec-form hooks.
# Forward slashes keep the path intact under Git Bash.
$hookPathForShell = $hookTarget -replace '\\', '/'
$handler = [pscustomobject]@{
    type    = 'command'
    command = "powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass -File `"$hookPathForShell`""
    timeout = 10
}

foreach ($eventName in @('UserPromptSubmit', 'PostToolUse', 'Notification', 'Stop', 'SessionEnd')) {
    $groups = @()
    if ($settings.hooks.PSObject.Properties.Name -contains $eventName) {
        # Keep everything that isn't ours, so re-running never duplicates.
        foreach ($group in @($settings.hooks.$eventName)) {
            $kept = @($group.hooks | Where-Object { -not ((([string]$_.command) + ' ' + ($_.args -join ' ')) -match 'island-hook\.ps1') })
            if ($kept.Count -gt 0) {
                $group.hooks = $kept
                $groups += $group
            }
        }
        $settings.hooks.PSObject.Properties.Remove($eventName)
    }
    $groups += [pscustomobject]@{ hooks = @($handler) }
    $settings.hooks | Add-Member -NotePropertyName $eventName -NotePropertyValue $groups
}

$json = $settings | ConvertTo-Json -Depth 32
[IO.File]::WriteAllText($settingsPath, $json, (New-Object Text.UTF8Encoding($false)))
Write-Host "settings.json mis à jour : $settingsPath"
Write-Host ""
Write-Host "C'est prêt. Redémarre Claude Code, puis active l'onglet Claude dans les réglages du mod."
