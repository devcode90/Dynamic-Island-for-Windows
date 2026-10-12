# Claude tab — Claude Code hook

The island's **Claude** tab reads a small status file that a Claude Code hook keeps up to date:

```
%USERPROFILE%\.claude\island-status.json
```

## Install

From this folder, in PowerShell:

```powershell
powershell -ExecutionPolicy Bypass -File .\install-island-hook.ps1
```

The installer copies `island-hook.ps1` to `%USERPROFILE%\.claude\` and registers it in `%USERPROFILE%\.claude\settings.json` for `UserPromptSubmit`, `PostToolUse`, `Notification`, `Stop` and `SessionEnd`. It backs up `settings.json` first (`settings.json.bak-island`) and is safe to run again. Restart Claude Code, then turn on **Claude tab** in the mod settings.

## What the tab shows

- State: running, waiting for you (permission or input prompt), done, or idle.
- The request you sent and what Claude is doing right now (editing a file, running a command…).
- Progress from Claude's task list (`TodoWrite`, or `TaskCreate` / `TaskUpdate`), e.g. `3/5 tasks`.
- A pill pops when a task finishes or Claude is waiting for you.

## Notes

- Only Claude Code sessions are tracked, not the Claude desktop or web apps.
- The hook starts PowerShell on every tool call, which adds roughly 0.2–0.4 s per action.
- With several sessions open at once, the most recent event wins.
- To remove it, delete the `island-hook.ps1` entries from `settings.json` (or restore the backup).

### Status file format

```json
{ "state": "running", "title": "…", "detail": "…", "project": "…",
  "done": 2, "total": 5, "started": 1760290000, "updated": 1760290120, "session": "…" }
```

`state` is one of `running`, `waiting`, `done`, `error`, `idle`. Anything that writes this file can drive the tab.
