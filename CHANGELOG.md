# 📜 Changelog & User Feedback Fixes

All notable changes, enhancements, and bug fixes for **Dynamic Island for Windows** are documented in this file.

---

## [Unreleased / Latest Updates]

### ✨ Fixes & Enhancements

#### 🚀 Performance & Stability (Bug Fixes #40)
* **Notification System Rewrite:** Completely rewrote the internal notification tracking logic! Previously, the island tracked the "last seen ID", which caused it to randomly drop and miss new notifications if Windows happened to sort them unexpectedly (e.g. newest-first). It now uses an ultra-reliable memory set (`std::set`) to instantly detect and display any genuinely new notification, ignoring Windows' internal sort order. It also now cleanly skips blasting you with old notifications when starting up!
* **Notification Thread Loop:** Fixed a severe bug where the notification listener would enter an infinite, 0-millisecond tight loop on unsupported versions of Windows, causing high CPU usage and log spam. Additionally, a strict 30-second initialization delay has been added when injecting into `explorer.exe` on boot. This ensures the Windows Notification Service is fully loaded *before* the island connects to it, preventing the connection from becoming permanently corrupted until a manual restart!
* **Media Artwork Caching:** Fixed a major CPU sink where the background media thread was blindly downloading and re-decoding album artwork raw bytes unconditionally every 1.5 seconds. The thread now implements strict caching and validation logic, reusing the parsed image data unless the song title or artist actually changes. This drastically reduces background CPU usage and correctly allows the island to auto-hide as expected while playing music.

#### 🎵 VLC & Browser Media Focus Fixes (User Feedback / Bug Fixes #51 & #53)
* **Media Auto-Expand Toggle:** Added a new `Auto-expand on track change` toggle under the Mod Settings. Turning this off prevents the island from constantly popping open when you are rapidly scrolling through short videos (like Instagram Reels or YouTube Shorts), completely eliminating the frustration of constant popups while still keeping the background media state accurate!
* **Browser Window Focus:** Fixed an annoying bug where clicking the media pill to focus a playing browser (like Vivaldi, Chrome, or Edge) would launch a brand new empty window if you had switched tabs. The island will now smartly search for the existing window belonging to the browser process and bring it to the foreground instead of launching a new instance!
* **Missing Media Data:** Some versions of VLC fail to correctly pass the current media title to the Windows Media Transport Controls. The island will now automatically detect this missing data and fallback to safely extracting the playing video/song title directly from VLC's window title, ensuring media controls remain useful!

#### 📐 Shape Style Settings Consolidation (User Feedback / Refactor)
* **Combined Shape Settings:** The `Native Windows 11 style` and `macOS Notch style` settings have been combined into a single, clean `Island Shape Style` dropdown menu. This prevents mutually exclusive toggles from being active at the same time and makes customizing the island's shape much more intuitive.


#### ⛅ Weather Module Toggle (User Feedback / Feature Request)
* **Disable/Hide Weather Widget:** Added a `Weather module` master toggle under the Mod Settings. When disabled, the inactive Dynamic Island pill will perfectly shrink and center only the digital clock for a minimal setup. It also hides the weather widget completely from the expanded view (leaving only the calendar) and pauses all background network fetches to `wttr.in`, improving performance.

#### 👆 Touch Swipe Gestures (User Feedback / Feature Request #54)
* **Touch-Friendly Navigation:** For users on Surface Pro or other Windows tablets without a mouse wheel, the dynamic island is now fully touch-friendly! You can now physically swipe left or right on the island to effortlessly cycle between background apps (like swiping between Weather, the Clock, and active Media controls) just like on a smartphone.


#### ⌨️ Caps Lock Toggle & Wind Direction Arrows (User Feedback / Feature Request ramensoftware#4352)
* **Caps Lock Indicator Toggle:** Added a `Caps Lock module` toggle under the mod's Modules settings, allowing users to disable the Caps Lock / Num Lock island indicator completely if they find it distracting.
* **Wind Direction Arrows:** The weather dashboard now translates wind direction abbreviations (e.g., N, WSW, NE) into clear Unicode arrows (e.g., ↓, ↗, ↙) reflecting the actual meteorological wind flow direction for a cleaner visual layout.


#### ⏭️ Media Progress Bar Seeking & Consistent Album Art App Launching (User Feedback / Feature Request ramensoftware#4738)
* **Problem / Request:** Users suggested allowing clicks on the media progress bar to seek playback position (`TryChangePlaybackPositionAsync`), and noted that clicking anywhere on the media module (e.g. title text or background) opened the underlying media application, which was inconsistent and prone to accidental app launches.
* **Fix & Features Added:**
  * **Interactive Scrubber Seeking:** Clicking anywhere along the horizontal media progress bar in expanded media mode now instantly computes the track fraction and sends `session.TryChangePlaybackPositionAsync(targetTicks)` to the active WinRT media session. The local position state updates immediately (`positionTicks = targetTicks`) so the progress bar scrubber visually jumps right to the clicked location without delay.
  * **Restricted App Launching (`clickedAlbumArt`):** Clicking on the song title, artist, waveform, or background no longer triggers `OpenRelevantApp()`. The source application is now strictly opened ONLY when the user clicks directly on the square Album Art image (`clickedAlbumArt`) in either expanded or collapsed media mode.
  * **Unified Button Hit-Testing:** Standardized playback button hit-testing (`cmd 0, 1, 2`) across both `WM_LBUTTONDOWN` and `WM_LBUTTONUP` (`cy = 56.0f`), ensuring smooth and responsive interaction whether using floating Apple pill style or top-attached macOS Notch style.

#### 🎵 Community Fork Integration: Album Title Support, Weather Word Wrapping & Stability Enhancements (ChrisSch-dev Fork Analysis & Integration)
* **Overview:** Analyzed and integrated key features and stability fixes from `ChrisSch-dev`'s community fork (`dynamic-island-for-windows.wh-fork.cpp`), adding full credit to the mod readme (`// ==WindhawkModReadme==`).
* **Features & Improvements Added:**
  * **Album Title Display (`albumTitle`):** Extracted `properties.AlbumTitle()` from WinRT media sessions and integrated `albumTitle` into `MediaSnapshot`. When playing media with album information, the album title is now displayed cleanly with subtle opacity below the artist name in expanded media mode.
  * **Intelligent Weather Description Word Wrapping:** Upgraded `DrawWeatherDashboard()` description rendering from plain single-line `DrawTextW` to `IDWriteTextFormat` with word wrapping (`DWRITE_WORD_WRAPPING_WRAP`) and dynamic font sizing (`9.8f` to `13.5f` based on description character length), preventing long weather summaries from overflowing or clipping outside the expanded weather panel.
  * **Sleep & Power Resume Auto-Recovery (`WM_POWERBROADCAST`):** Added `WM_POWERBROADCAST` handling for `PBT_APMRESUMESUSPEND`, `PBT_APMRESUMEAUTOMATIC`, and `PBT_APMRESUMECRITICAL`. When the PC wakes from sleep or hibernation, the mod automatically signals settings refresh events, resets weather timestamps (`lastUpdated = 0.0`) to trigger immediate weather updates, and nudges the overlay to restore UI responsiveness instantly.
  * **Robust Keyboard Hook & CapsLock Synchronization (`WM_APP_CAPSLOCK`):** Fixed race conditions during startup where `KeyboardThreadProc` hooked keys before `g_hwnd` was fully initialized (`while (!g_hwnd) Sleep(10);`). Upgraded `LowLevelKeyboardProc` to capture exact synchronous key states (`GetKeyState`) and transmit them inside `WM_APP_CAPSLOCK` (`lParam`), guaranteeing accurate Caps Lock / Num Lock notification badges.
  * **GameOverlay Expansion & Movement Stability:** Added checks for `gameMetricsPresent` (`g_settings.gameOverlay` or `GameOverlayPinned`) inside `ChooseIslandActivity` (`WM_LBUTTONUP`), `UpdateLayout`, and `Renderer::Draw` (`hoverScale`) to prevent unwanted hover scaling, click expansions, or spring bounces when the thin game overlay pill is active. Also removed redundant `TriggerNudge()` calls from `CaptureClipboard` to eliminate unintended jitter or spring oscillations during background clipboard updates.


#### 🔔 Notification Listener & Shell Hook Resiliency Across PC Reboots (User Feedback / Bug Report #40)
* **Problem / Request:** Users reported that notifications (like WhatsApp) stopped working after restarting their PC unless they disabled and re-enabled the mod or removed/re-added `explorer.exe` to the process inclusion list on every reboot.
* **Fix & Features Added:**
  * **WinRT UWP Notification Listener Retry Loop:** When the mod initializes early during system boot (`windhawk.exe` service start), the UWP/WinRT notification platform (`wpnservice` / `UserNotificationListener`) is often not ready yet or access has not yet settled for the interactive user session. Previously, if `RequestAccessAsync()` returned denied or threw an exception right on startup, the notification listener thread permanently exited (`return 0;`). Implemented a resilient outer connection loop that retries connection (`WaitForSingleObject(g_stopEvent, 3000)`) instead of terminating, ensuring the WinRT listener connects automatically as soon as the user logs in and the notification subsystem comes online.
  * **Shell Hook Recovery on Explorer Start (`TaskbarCreated`):** Classic Shell Hook notifications (`CaptureShellNotification`) become disconnected whenever `explorer.exe` starts up after `windhawk.exe` during boot or when Windows Explorer restarts. Added listening and registration for the `TaskbarCreated` system message (`RegisterWindowMessageW(L"TaskbarCreated")`), so the overlay window automatically re-registers its shell hook (`RegisterShellHookWindow`) whenever the taskbar/shell initializes.
  * **UIPI Message Filtering (`ChangeWindowMessageFilterEx`):** Added explicit `ChangeWindowMessageFilterEx` (`MSGFLT_ALLOW`) rules for `SHELLHOOK`, `TaskbarCreated`, `WM_COPYDATA`, and `WM_COPYGLOBALDATA` when running under elevated or admin integrity levels, bypassing Windows User Interface Privilege Isolation (UIPI) so notifications broadcast from `explorer.exe` and `sihost.exe` reliably reach the overlay across all boot scenarios.

#### 🟠 / 🟢 Privacy Indicator Customization & Toggles (User Feedback / Feature Request #34, #36)
* **Problem / Request:** Users requested toggles to turn off the microphone and camera privacy dots (noting that background apps like Discord or OBS keep the mic dot permanently active), as well as controls to disable the pulsing animation and customize the dot colors.
* **Fix & Features Added:**
  * **Master & Individual Toggles:** Added `Show privacy indicators (Mic & Camera)` master toggle, along with independent `Show microphone indicator (Orange dot)` and `Show camera indicator (Green dot)` toggles under the **Modules & Features** settings block. Users can now turn off just the microphone dot while keeping the webcam alert active.
  * **Pulsing Animation Toggle:** Added `Privacy dots pulsing animation` (`PrivacyDotsPulse`). When disabled, privacy dots render as clean, static indicators without the breathing pulse.
  * **Custom Hex Colors:** Added `Microphone dot custom hex color` (`PrivacyDotsMicHex`) and `Camera dot custom hex color` (`PrivacyDotsCamHex`) so users can customize privacy dot colors beyond the default iOS Orange and Green.
  * **Optimized Background Queries:** When privacy indicators are disabled via settings, background registry polling (`IsMicrophoneActive` / `IsCameraActive`) is bypassed entirely, reducing background CPU and registry overhead.

#### ⏱️ Auto-Hide Island Across All States (User Feedback / Feature Request #43, #39, #32)
* **Problem / Request:** Users reported that the auto-hide setting (`AutoHideIdleSeconds`) only hid the island when it was completely idle, meaning background activities like playing media (Spotify, YouTube) or ongoing progress indicators would stay visible on screen continuously without ever auto-hiding after inactivity.
* **Fix & Features Added:**
  * **Universal Auto-Hide Support:** Updated `AutoHideIdleSeconds` to apply across all ongoing states (`Idle`, `Media`, and `Progress`).
  * **Intelligent Transient & Interaction Protection:** When a new event occurs (such as a song track change, clipboard copy, notification, volume adjustment, mouse hover, or pinned state), the island unhides immediately to show the update and stays awake.
  * **Smooth Auto-Hiding:** Once `AutoHideIdleSeconds` of inactivity elapse without further interaction or track changes, any active state smoothly collapses and hides until the next interaction or notification.
  * **Updated Settings Metadata:** Renamed option in Windhawk settings UI to `Auto-hide island (all states)` (`AutoHideIdleSeconds`) with clarified description explaining universal state support.

#### 🍏 Native macOS Notch Style Mode (User Feedback / Feature Request)
* **Problem / Request:** Users requested an option similar to the native Windows 11 style, but designed to resemble a MacBook notch where the island sticks flush to the top edge of the upper screen.
* **Fix & Features Added:**
  * **New Mod Setting (`MacOsNotchStyle`):** Added `macOS Notch style` toggle under the Appearance settings block.
  * **Top-Attached Screen Ceilings:** When enabled, the window position automatically anchors flush against the monitor top edge (`y = 0`) instead of floating 8 pixels below it, ensuring a true top-attached notch appearance.
  * **Custom Direct2D Notch Path Geometry:** Implemented `CreateNotchGeometry()` and `CreateIslandMaskGeometry()`, generating an authentic MacBook notch shape with flat top corners and smoothly curved bottom corners (`16.0f` scaled radius).
  * **Right-Click Context Menu Toggle:** Added a convenient right-click menu item ("Use macOS Notch Style" / "Disable macOS Notch Style") to switch seamlessly between Apple floating pill, Windows 11 flyout box, and macOS Notch styles.
  * **Precision Media Click Detection:** Updated window coordinate calculations in `WndProc` so interacting with media buttons and dashboards works with exact precision whether floating or attached in notch style.

#### ❌ Right-Click Menu Dismiss Button Functionality & Media Visibility Fix (Feedback / Issue #32)
* **Problem:** Clicking "Dismiss" from the right-click context menu would cause the Dynamic Island to disappear permanently, even if media (e.g. Spotify, YouTube) was currently playing in the background. The island would remain hidden until a new event (such as a media title change or clipboard copy) occurred.
* **Fix & Features Added:**
  * **Comprehensive Transient State Clearing:** Updated `DismissTransientState()` to reliably clear all transient popups (Clipboard, Notifications, Volume, Progress, Caps Lock, Device, and Battery low alerts) while keeping active media state intact.
  * **Immediate Layout Refresh & Nudge:** Added immediate `g_layoutDirty = true`, `g_clickExpanded = false`, and `TriggerNudge()` calls when the Dismiss menu command is executed.
  * **Instant Media Restoration:** When dismissing an overlaying notification or clipboard popup while media is playing, the island now smoothly and immediately animates back to the active Media pill or dashboard without ever hiding or freezing.

#### 📋 Customizable Clipboard Icon Background Style (Feedback / Issue #30)
* **Problem:** When copying text or images, the clipboard preview displayed a hardcoded gray background behind the icon that could not be modified or removed via settings.
* **Fix & Features Added:**
  * Added **`ClipboardIconBgStyle`** under the **Modules** settings block with 4 customizable modes:
    * `default`: Standard subtle gray background badge.
    * `transparent`: Eliminates the background box entirely for a clean, outline-only floating icon look.
    * `accent`: Uses the island's glowing accent color with soft opacity.
    * `custom`: Uses a custom hex color.
  * Added **`ClipboardIconBgHex`** setting to define the exact hex color when using Custom mode (default `#2E2E38`).
  * Updated `DrawClipboard` rendering logic so both the outer badge box and inner fallback icon plate respect the selected background style.

#### 🚀 High Refresh Rate (360Hz+) Support & Precise Animation Controls (Feedback / Issue #26)
* **Problem:** Animations felt stuttery or buggy on high refresh rate monitors (144Hz, 240Hz, 360Hz+), and users lacked precise control over animation physics.
* **Fix & Features Added:**
  * **Zero-Spin Frame Pacing:** Replaced hardcoded 16ms sleep (~60 FPS) with a CPU-efficient hybrid timing system using 1ms OS timer resolution (`timeBeginPeriod`) and thread yielding. Achieves buttery-smooth presentation on 360Hz/500Hz panels while maintaining **0.00% CPU usage at idle**.
  * **Automatic Monitor Hz Detection:** Implemented `GetMonitorRefreshRate(HWND hwnd)` to detect and match native display frequency automatically when set to `Auto`.
  * **2000Hz Deterministic Physics Sub-Stepping:** Upgraded `SpringValue::Step` to use a fixed timestep (`0.0005s`), ensuring identical spring behavior and stability regardless of framerate.
  * **New Mod Settings (`TargetFPS`, `AnimationStyle`, `AnimationSpeed`):** Added options for target FPS up to 500 FPS, spring styles (`smooth`, `default`, `bouncy`, `snappy`), and 6 granular animation speed levels (0.5x to 2.0x).
