# island-hook.ps1
# Claude Code hook for "Dynamic Island for Windows (+ Todoist, Mail, Claude)".
#
# Claude Code runs this on a few hook events and passes the event as JSON on
# stdin. The script keeps a tiny status file up to date, which the island polls
# once a second:
#
#   %USERPROFILE%\.claude\island-status.json
#   { "state": "running|waiting|done|error|idle", "title": "...", "detail": "...",
#     "project": "...", "done": 2, "total": 5, "started": <unix>, "updated": <unix>,
#     "session": "..." }
#
# It never blocks Claude: any failure is swallowed and the script exits 0.

$ErrorActionPreference = 'Stop'

try {
    [Console]::InputEncoding = [Text.Encoding]::UTF8
    $raw = [Console]::In.ReadToEnd()
    if ([string]::IsNullOrWhiteSpace($raw)) { exit 0 }
    $evt = $raw | ConvertFrom-Json

    $dir = Join-Path $env:USERPROFILE '.claude'
    $path = Join-Path $dir 'island-status.json'
    if (-not (Test-Path $dir)) { New-Item -ItemType Directory -Path $dir | Out-Null }

    $now = [DateTimeOffset]::UtcNow.ToUnixTimeSeconds()

    # Current state, or a fresh one.
    $s = $null
    if (Test-Path $path) {
        try { $s = Get-Content -Raw -Encoding UTF8 $path | ConvertFrom-Json } catch { $s = $null }
    }
    if ($null -eq $s) {
        $s = [pscustomobject]@{ state = 'idle'; title = ''; detail = ''; project = ''
                                done = 0; total = 0; started = 0; updated = 0; session = '' }
    }

    function Short([string]$text, [int]$max) {
        if ([string]::IsNullOrEmpty($text)) { return '' }
        $t = ($text -replace '\s+', ' ').Trim()
        if ($t.Length -gt $max) { $t = $t.Substring(0, $max) + [char]0x2026 }
        return $t
    }

    function Leaf([string]$p) {
        if ([string]::IsNullOrEmpty($p)) { return '' }
        return Split-Path -Leaf $p
    }

    # Human-readable line for what a tool just did.
    function Describe($name, $in) {
        switch -Regex ($name) {
            '^Bash$'                { if ($in.description) { return Short $in.description 90 } else { return 'Commande : ' + (Short $in.command 80) } }
            '^(Edit|MultiEdit)$'    { return 'Modifie ' + (Leaf $in.file_path) }
            '^Write$'               { return 'Écrit ' + (Leaf $in.file_path) }
            '^Read$'                { return 'Lit ' + (Leaf $in.file_path) }
            '^(Grep|Glob)$'         { return 'Recherche ' + (Short $in.pattern 70) }
            '^WebSearch$'           { return 'Recherche web : ' + (Short $in.query 70) }
            '^WebFetch$'            { return 'Lit ' + (Short $in.url 70) }
            '^(Task|Agent)$'        { return 'Sous-agent : ' + (Short $in.description 70) }
            '^(TodoWrite|TaskCreate|TaskUpdate)$' { return '' }
            '^mcp__'                { return 'Outil ' + (($name -split '__')[1]) }
            default                 { return [string]$name }
        }
    }

    $event = [string]$evt.hook_event_name
    $session = [string]$evt.session_id

    switch ($event) {
        'UserPromptSubmit' {
            # A new request: reset progress unless we're mid-task in the same session.
            if ($s.state -ne 'running' -or $s.session -ne $session) {
                $s.done = 0; $s.total = 0
            }
            $s.state = 'running'
            $s.title = Short ([string]$evt.prompt) 110
            $s.detail = ''
            $s.started = $now
            $s.session = $session
            if ($evt.cwd) { $s.project = Leaf ([string]$evt.cwd) }
        }
        'PostToolUse' {
            $name = [string]$evt.tool_name
            $in = $evt.tool_input
            if ($s.state -ne 'running') { $s.state = 'running' }   # e.g. a permission was just granted

            if ($name -eq 'TodoWrite' -and $in.todos) {
                # Full list every time: recompute.
                $todos = @($in.todos)
                $s.total = $todos.Count
                $s.done = @($todos | Where-Object { $_.status -eq 'completed' }).Count
                $current = $todos | Where-Object { $_.status -eq 'in_progress' } | Select-Object -First 1
                if ($current) {
                    $label = if ($current.activeForm) { $current.activeForm } else { $current.content }
                    $s.detail = Short ([string]$label) 100
                }
            } elseif ($name -eq 'TaskCreate') {
                $s.total = [int]$s.total + 1
            } elseif ($name -eq 'TaskUpdate') {
                if ($in.status -eq 'completed') { $s.done = [Math]::Min([int]$s.done + 1, [int]$s.total) }
                elseif ($in.status -eq 'in_progress' -and $in.activeForm) { $s.detail = Short ([string]$in.activeForm) 100 }
            } else {
                $d = Describe $name $in
                if ($d) { $s.detail = $d }
            }
        }
        'Notification' {
            # Only a permission / input prompt during work counts as "waiting";
            # the idle reminder after a finished task must not undo "done".
            if ($s.state -eq 'running') {
                $s.state = 'waiting'
                $s.detail = Short ([string]$evt.message) 100
            }
        }
        'Stop' {
            $s.state = 'done'
            $msg = [string]$evt.last_assistant_message
            $s.detail = if ($msg) { Short (($msg -split "`n")[0]) 100 } else { '' }
        }
        'SessionEnd' {
            if ($s.session -eq $session) { $s.state = 'idle' }
        }
        default { exit 0 }
    }

    $s.updated = $now

    # Write to a temp file and swap it in, so the island never reads half a file.
    $json = $s | ConvertTo-Json -Compress
    $tmp = "$path.tmp"
    [IO.File]::WriteAllText($tmp, $json, (New-Object Text.UTF8Encoding($false)))
    Move-Item -Force -LiteralPath $tmp -Destination $path
} catch {
    # Never get in Claude's way.
}
exit 0
