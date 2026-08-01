// ==WindhawkMod==
// @id              dynamic-island-for-windows-fork
// @name            Dynamic Island for Windows - Fork
// @description     A living, breathing pill overlay inspired by iPhone's Dynamic Island. Reacts to media, downloads, clipboard, battery, and more.
// @version         1.2.0
// @author          Himanshu
// @github          https://github.com/devcode90
// @include         windhawk.exe
// @compilerOptions -lole32 -loleaut32 -lshcore -ld2d1 -ldwrite -ldwmapi -lgdi32 -luser32 -lshell32 -lruntimeobject -lwindowscodecs -lavrt -lsetupapi -lwinhttp -lpdh -lwinmm
// @license         MIT
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Dynamic Island for Windows

A fluid, living overlay inspired by Apple's Dynamic Island, bringing a beautiful, highly-responsive UI to your Windows desktop. Built natively with hardware-accelerated Direct2D rendering for a buttery-smooth 60 FPS experience.

![Dynamic Island Preview](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/Full-preview.png)

---

## 🚀 Modules & Dashboards

The Dynamic Island intelligently expands to display context-aware dashboards. You can easily navigate between different views using your mouse scroll wheel.

| Module | Description | Preview |
| :--- | :--- | :--- |
| **Media Player** | Shows live album art, track details, audio waveforms, and full playback controls. | ![Media](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/media.png) |
| **Calendar** | A sleek, perfectly aligned monthly calendar that highlights the current date. | ![Calendar](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/calender.png) |
| **Weather** | Real-time weather stats powered by wttr.in, including wind speed, humidity, and "feels like" temperature. | ![Weather](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/weather.png) |
| **Game Overlay** | Real-time FPS, CPU, GPU, and RAM utilization overlays tailored for gamers. | ![Gamebar](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/gamebar.png) |
| **Idle View** | A minimal dashboard with your battery status, digital clock, and sleek pagination dots. | ![Idle](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/idle.png) |
| **Camera Privacy** | Shows a green dot when an app is actively using your webcam. | ![Camera](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/camera-detected.png) |
| **Mic Privacy** | Shows an orange dot when an app is actively using your microphone. | ![Mic](https://raw.githubusercontent.com/devcode90/Dynamic-Island-for-Windows/main/previews/mic-detected.png) |

---

## ✨ Core Features

- **Hardware Privacy Indicators:** A pulsing orange dot appears when your microphone is active, and a green dot when your camera is in use. Rate-limited polling ensures absolutely no CPU drain.
- **High-Res Clipboard & Notifications:** Instantly see what you copied or your latest Windows notifications, featuring crisp, high-fidelity 64px app icons extracted directly from system executables.
- **360Hz+ Dynamic Fluid Animations:** Ultra-smooth resizing and splitting with native support for high refresh rate monitors (up to 360Hz/500Hz+) and zero idle CPU drain.
- **Customizable Aesthetics:** Switch between sleek OLED Black, Dark Gray, Midnight Blue, and Deep Purple themes from the right-click menu, or use the settings to dial in your exact hex colors.

---

## ⚙️ Usage & Settings

- **Hover & Scroll:** Hover over the island to seamlessly expand it. Use your mouse scroll wheel to swipe between the Media, Calendar, and Weather tabs.
- **Right-Click Menu:** Right-click the island to access Theme presets, Transparency settings, and to pin the island open.
- **Windhawk Settings:** Visit the Mod Settings tab to change the island's Position, Size Scale, Refresh Rate (Target FPS), Animation Style (Smooth/Default/Bouncy/Snappy), Animation Speed, and toggle specific modules. You can also perfectly align the island using the `Offset X` and `Offset Y` settings, and select exactly which monitor the island should appear on (including a "Follow Mouse" mode!).
- **Notifications:** To use the notification module, you need to add `explorer.exe` to the process inclusion list in the Advanced tab of the mod settings and restart the mod.

---

## 📝 Feedback & Credits

### Feedback / Support / Bug Reports
- Please use [Windhawk Mods Issues](https://github.com/ramensoftware/windhawk-mods/issues) or [dynamic-island-for-windows issues](https://github.com/devcode90/dynamic-island-for-windows/issues) to report bugs, request features, or share feedback.  
- Clear descriptions, screenshots, or steps to reproduce help improve fixes and updates.  
- Suggestions for UI/UX or new integrations are always welcome.

### Credits
- **[ciizerr @GitHub](https://github.com/ciizerr)**: Improved the UI by refining layout alignment, fixing dashboard scaling, and enhancing calendar and weather module integration.
- **[ChrisSch-dev @GitHub](https://github.com/ChrisSch-dev)**: Added album title support, word wrapping for weather descriptions, sleep resume fixes, and various performance/movement stability improvements.

*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- Appearance:
  - Position: top-center
    $name: Position
    $description: Where the island should appear on your screen.
    $options:
      - top-center: Top Center
      - top-left: Top Left
      - top-right: Top Right
      - bottom-center: Bottom Center
  - TargetMonitor: primary
    $name: Target Monitor
    $description: Select the screen to display the island. If a display isn't found, it safely falls back to the Primary Monitor.(Extra Displays are given even if they don't exist because windhawk settings are static)
    $options:
      - 'primary': Primary Monitor
      - '1': Display 1
      - '2': Display 2
      - '3': Display 3
      - '4': Display 4
      - '5': Display 5
      - 'follow': Follow Mouse (Active Monitor)
  - OffsetX: 0
    $name: Offset X
    $description: Adjust the horizontal position (in pixels). Positive values move it right, negative values move it left.
  - OffsetY: 0
    $name: Offset Y
    $description: Adjust the vertical position (in pixels). Positive values move it down, negative values move it up.
  - BorderMergedMode: false
    $name: Border-Merged Mode
    $description: Attach the island flush to the top edge of the monitor without a floating gap.
  - SizeScale: '1.0'
    $name: Size scale
    $description: Makes the entire island and its contents larger or smaller.
    $options:
      - '0.8': 0.8x
      - '1.0': 1.0x
      - '1.2': 1.2x
      - '1.5': 1.5x
      - '1.8': 1.8x
      - '2.0': 2.0x
      - '2.5': 2.5x
  - AutoHideIdleSeconds: '0'
    $name: Auto-hide island (all states)
    $description: Hide the island (including idle, media, and other states) after this many seconds of inactivity. 0 to disable.
    $options:
      - '-1': Hide instantly
      - '0': Never hide (default)
      - '5': Hide after 5 seconds
      - '10': Hide after 10 seconds
      - '30': Hide after 30 seconds
      - '60': Hide after 60 seconds
  - AutoHideFullscreen: true
    $name: Hide on full screen
    $description: Automatically hide the island when playing a video or app in full screen mode.
  - UnhideOnHover: true
    $name: Unhide on hover
    $description: Allow the hidden island to reappear when you hover your mouse over it.
  - AutoDpiScale: true
    $name: Auto DPI scaling
    $description: Automatically scales the island to match your monitor's DPI. Recommended for 4K screens.
  - ShapeStyle: default
    $name: Island Shape Style
    $description: Change the overall shape of the island (Pill, Windows 11, or macOS Notch).
    $options:
      - default: Default (Apple Pill)
      - w11: Windows 11 (Rounded Box)
      - notch: macOS Notch (Top Edge Flush)
  - AlwaysOnTop: true
    $name: Always on top
    $description: Keeps the island above all other windows. Turn this off if it blocks other apps.
  - ExpandOnHover: true
    $name: Expand on hover
    $description: Expand the island automatically when hovered. If disabled, click to expand.
  - TargetFPS: auto
    $name: Refresh rate / FPS
    $description: Set the animation frame rate. Choose Auto to dynamically match your active monitor's refresh rate (up to 360Hz/500Hz), or select a fixed FPS.
    $options:
      - auto: Auto (Match Monitor Refresh Rate)
      - '60': 60 FPS (Eco / Standard)
      - '90': 90 FPS
      - '120': 120 FPS
      - '144': 144 FPS
      - '165': 165 FPS
      - '240': 240 FPS
      - '360': 360 FPS (Ultra Smooth)
      - '500': 500 FPS (Maximum / Uncapped)
  - AnimationStyle: default
    $name: Animation bounciness / style
    $description: Control the spring physics and feel of the animation.
    $options:
      - smooth: Smooth (No bounciness / Critically damped)
      - default: Default (Balanced Apple-like spring)
      - bouncy: Bouncy (Dynamic elastic spring)
      - snappy: Snappy (High stiffness, quick settle)
  - AnimationSpeed: normal
    $name: Animation speed
    $description: How fast the island expands and collapses.
    $options:
      - very-slow: Very Slow (0.5x)
      - slow: Slow (0.75x)
      - normal: Normal (1.0x)
      - fast: Fast (1.35x)
      - very-fast: Very Fast (1.65x)
      - ultra-fast: Ultra Fast (2.0x)
  $name: Appearance & Behavior
- Themes:
  - AccentColorMode: auto
    $name: Accent color mode
    $description: How the glowing accent color is chosen. Auto extracts it from album art.
    $options:
      - auto: Auto, from album art
      - system: System
      - custom: Custom hex
  - CustomAccentHex: "#4cc9f0"
    $name: Custom accent hex
    $description: The hex color to use when the accent mode is set to Custom.
  - PillBgColor: "#0D0D0F"
    $name: Pill background color
    $description: Hex color for the background. Presets are available in the right-click menu.
  - TextPrimaryColor: "#F7F7F7"
    $name: Primary text color
    $description: Hex color for titles and main text.
  - TextSecondaryColor: "#888888"
    $name: Secondary text color
    $description: Hex color for artist names and muted labels.
  - ContourBorderEnabled: true
    $name: Show contour border
    $description: Enable gray contour stroke line around the island.
  - ContourBorderHex: "#333338"
    $name: Contour border hex color
    $description: Hex color for the island contour stroke.
  - TintIntensity: 72
    $name: Background tint intensity
    $description: 0 to 100. Controls how dark the background tint behind the island is.
  - PillOpacity: 96
    $name: Pill transparency
    $description: 35 to 100. Lower values make the island more see-through.
  $name: Colors & Theming
- Indicators:
  - PrivacyDotsEnabled: true
    $name: Show privacy indicators
    $description: Display orange (mic) and green (camera) dots when hardware is in use.
  - PrivacyDotPulsing: true
    $name: Pulse privacy dots
    $description: Enable smooth pulsing animation on active privacy dots.
  - MicDotHex: "#FF9500"
    $name: Microphone dot color
    $description: Hex color for microphone privacy indicator.
  - CamDotHex: "#34C759"
    $name: Camera dot color
    $description: Hex color for camera privacy indicator.
  $name: Privacy Indicators
- Modules:
  - Media: true
    $name: Media module
    $description: Shows album art, song info, and playback controls when music is playing.
  - MediaAutoExpand: true
    $name: Auto-expand on track change
    $description: Turn off to stop the island from popping open every time a new song or video starts playing (useful if you rapidly scroll through shorts/reels).
  - Clipboard: true
    $name: Clipboard module
    $description: Shows a quick preview of the text or images you just copied.
  - ClipboardIconBgStyle: default
    $name: Clipboard icon background
    $description: Change the background behind the copy/clipboard icon. Select Transparent to remove the fixed gray box.
    $options:
      - default: Default (Subtle Gray)
      - transparent: Transparent (No Background / Remove Gray Box)
      - accent: Accent Color
      - custom: Custom Hex Color
  - ClipboardIconBgHex: "#2E2E38"
    $name: Clipboard icon custom background hex
    $description: The hex color to use when Clipboard icon background is set to Custom Hex Color.
  - Battery: true
    $name: Battery module
    $description: Shows an alert when your laptop battery is running low.
  - Progress: true
    $name: Progress module
    $description: Shows a progress ring around the island for downloads or file copies.
  - HardwareMonitorModule: true
    $name: Include Hardware Monitor in scroll loop
    $description: Add CPU, GPU, RAM, FPS and Network stats card to mouse-wheel scroll loop.
  - GameOverlay: false
    $name: Enable game overlay mode
    $description: Replaces the clock with live stats like FPS, CPU, and RAM usage.
  - ShowMetricText: false
    $name: Show labels in metric chips
    $description: Adds text labels (like "CPU") inside the game overlay bars.
  - Weather: true
    $name: Weather module
    $description: Shows the weather on the right side of the pill. Turn off to only show the clock.
  - WeatherCity: ""
    $name: Weather City (Optional)
    $description: Enter your city (e.g. London). Leave blank to use auto IP geolocation.
  - WeatherFahrenheit: false
    $name: Use Fahrenheit
    $description: Display weather temperature and wind speed in imperial units.
  - PrivacyDots: true
    $name: Show privacy indicators (Mic & Camera)
    $description: Master toggle to display the iOS-style orange/green privacy dots when microphone or camera is in use.
  - PrivacyDotsMic: true
    $name: Show microphone indicator (Orange dot)
    $description: Show the orange dot when microphone is in use. Turn off if background apps (like Discord/OBS) keep it permanently active.
  - PrivacyDotsCam: true
    $name: Show camera indicator (Green dot)
    $description: Show the green dot when webcam is in use.
  - PrivacyDotsPulse: true
    $name: Privacy dots pulsing animation
    $description: Animate the privacy dots with a soft breathing pulse. Turn off for static dots.
  - PrivacyDotsMicHex: "#FF9500"
    $name: Microphone dot custom hex color
    $description: Custom hex color for microphone indicator (default #FF9500).
  - PrivacyDotsCamHex: "#10B981"
    $name: Camera dot custom hex color
    $description: Custom hex color for camera indicator (default #10B981).
  - CapsLock: true
    $name: Caps Lock module
    $description: Shows an indicator when Caps Lock or Num Lock state changes.
  $name: Modules & Features
*/
// ==/WindhawkModSettings==

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <unknwn.h>
#include <dwmapi.h>
#include <shellapi.h>
#include <setupapi.h>
#include <dbt.h>
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>
#include <shcore.h>
#include <windowsx.h>
#include <audioclient.h>
#include <audiopolicy.h>
#include <endpointvolume.h>
#include <mmdeviceapi.h>
#include <mmreg.h>
#include <mmsystem.h>
#include <objbase.h>
#include <wrl/client.h>
#include <uiautomation.h>
#include <winhttp.h>
#include <pdh.h>
#include <pdhmsg.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cwchar>
#include <cstring>
#include <mutex>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>
#if __has_include(<winrt/Windows.UI.Notifications.Management.h>) && \
    __has_include(<winrt/Windows.UI.Notifications.h>)
#define DYNAMIC_ISLAND_HAS_USER_NOTIFICATION_LISTENER 1
#include <winrt/Windows.ApplicationModel.h>
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.UI.Notifications.Management.h>
#else
#define DYNAMIC_ISLAND_HAS_USER_NOTIFICATION_LISTENER 0
#endif

using Microsoft::WRL::ComPtr;
using namespace std::chrono_literals;

namespace {

constexpr wchar_t kWindowClass[] = L"Windhawk.DynamicIslandForWindows";
constexpr UINT WM_APP_LAYOUT_CHANGED = WM_APP + 0x442;
constexpr UINT WM_APP_NEW_EVENT = WM_APP + 0x443;
constexpr float kRenderPadX = 28.0f;
constexpr float kRenderPadY = 22.0f;

enum class IslandKind {
    Idle,
    Media,
    Progress,
    Clipboard,
    Notification,
    Volume,
    BatteryLow,
    CapsLock,
    Device,
    Split,
};

enum class Position {
    TopCenter,
    TopLeft,
    TopRight,
    BottomCenter,
};

enum class AccentMode {
    Auto,
    System,
    Custom,
};

enum class AnimationStyle {
    Smooth,
    Default,
    Bouncy,
    Snappy,
};

enum class ClipboardIconBgStyle {
    Default,
    Transparent,
    Accent,
    Custom,
};

struct Settings {
    Position position = Position::TopCenter;
    int targetMonitor = 0;
    int offsetX = 0;
    int offsetY = 0;
    float sizeScale = 1.0f;
    AccentMode accentMode = AccentMode::Auto;
    D2D1_COLOR_F customAccent = D2D1::ColorF(0x4cc9f0);
    int targetFps = 0; // 0 = Auto
    AnimationStyle animationStyle = AnimationStyle::Default;
    float animationSpeed = 1.0f;
    bool media = true;
    bool mediaAutoExpand = true;
    bool clipboard = true;
    ClipboardIconBgStyle clipboardIconBgStyle = ClipboardIconBgStyle::Default;
    D2D1_COLOR_F clipboardIconBgHex = D2D1::ColorF(0.18f, 0.18f, 0.22f, 1.0f); // #2E2E38
    bool battery = true;
    bool progress = true;
    bool privacyDots = true;
    bool privacyDotsMic = true;
    bool privacyDotsCam = true;
    bool privacyDotsPulse = true;
    bool capsLock = true;
    D2D1_COLOR_F privacyDotsMicHex = D2D1::ColorF(1.0f, 0.584f, 0.0f, 1.0f); // #FF9500
    D2D1_COLOR_F privacyDotsCamHex = D2D1::ColorF(0.133f, 0.776f, 0.239f, 1.0f); // #10B981
    float tintOpacity = 0.72f;
    float pillOpacity = 0.96f;
    bool gameOverlay = false;
    bool showMetricText = true;
    bool weather = true;
    std::wstring weatherCity;
    bool weatherFahrenheit = false;
    int autoHideIdleSeconds = 0;
    bool autoHideFullscreen = true;
    bool borderMergedMode = false;
    bool unhideOnHover = true;
    bool alwaysOnTop = true;
    bool expandOnHover = true;
    bool autoDpiScale = true;
    bool w11Style = false;
    bool notchStyle = false;
    // Color customization
    D2D1_COLOR_F pillBgColor = D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f); // #0D0D0F
    D2D1_COLOR_F textPrimaryColor = D2D1::ColorF(0.969f, 0.969f, 0.969f, 1.0f); // #F7F7F7
    D2D1_COLOR_F textSecondaryColor = D2D1::ColorF(0.533f, 0.533f, 0.533f, 1.0f); // #888888
    bool contourBorderEnabled = true;
    D2D1_COLOR_F contourBorderColor = D2D1::ColorF(0.200f, 0.200f, 0.220f, 1.0f); // #333338
    bool privacyDotsEnabled = true;
    bool privacyDotPulsing = true;
    D2D1_COLOR_F micDotColor = D2D1::ColorF(1.0f, 0.584f, 0.0f, 1.0f); // #FF9500
    D2D1_COLOR_F camDotColor = D2D1::ColorF(0.204f, 0.780f, 0.349f, 1.0f); // #34C759
    bool hardwareMonitorModule = true;
};

struct BitmapPixels {
    std::vector<uint8_t> bgra;
    UINT width = 0;
    UINT height = 0;
    uint64_t generation = 0;
    D2D1_COLOR_F sampledAccent = D2D1::ColorF(0x4cc9f0);
};

struct MediaSnapshot {
    bool available = false;
    bool playing = false;
    std::wstring title;
    std::wstring artist;
    std::wstring albumTitle;
    std::wstring sourceAppUserModelId;
    std::wstring sourceName;
    std::wstring sourceBadge;
    BitmapPixels art;
    BitmapPixels sourceIcon;
    uint64_t artGeneration = 0;
    uint64_t sourceIconGeneration = 0;
    double artChangedAt = 0.0;
    int64_t positionTicks = 0;
    int64_t endTicks = 0;
    int64_t lastUpdatedTicks = 0;
};

struct ClipboardSnapshot {
    bool active = false;
    bool image = false;
    std::wstring text;
    std::wstring appName;
    BitmapPixels appIcon;
    double expiresAt = 0.0;
};

struct BatterySnapshot {
    bool active = false;
    bool low = false;
    bool charging = false;
    int percent = 100;
    DWORD secondsRemaining = BATTERY_LIFE_UNKNOWN;
    double expiresAt = 0.0;
};

struct ProgressSnapshot {
    bool active = false;
    int percent = 0;
};

struct NotificationSnapshot {
    bool active = false;
    std::wstring app;
    std::wstring title;
    std::wstring body;
    BitmapPixels icon;
    double expiresAt = 0.0;
};

struct VolumeSnapshot {
    bool active = false;
    int percent = 0;
    bool muted = false;
    std::wstring deviceName;
    double expiresAt = 0.0;
};

struct CapsLockSnapshot {
    bool active = false;
    bool capsOn = false;
    bool numOn = false;
    bool isNumEvent = false;
    double expiresAt = 0.0;
};

enum class DeviceEventType {
    Connected,
    Disconnected,
};

struct DeviceSnapshot {
    bool active = false;
    DeviceEventType eventType = DeviceEventType::Connected;
    std::wstring deviceName;  // e.g. "USB Drive" or "Bluetooth Device"
    bool isBluetoothLike = false;
    double expiresAt = 0.0;
};

struct SystemSnapshot {
    int volumePercent = 0;
    bool volumeMuted = false;
    int cpuPercent = 0;
    int memoryPercent = 0;
    float memoryUsedGB = 0.0f;
    float memoryTotalGB = 0.0f;
    int diskFreePercent = 0;
    int renderFps = 0;
    int gpuPercent = -1;
    float netUpMbps = 0.0f;
    float netDownMbps = 0.0f;
    bool charging = false;
    bool micActive = false;      // orange dot: microphone in use
    bool cameraActive = false;   // green dot: camera in use
    std::wstring foregroundTitle;
};

struct Activity {
    IslandKind kind = IslandKind::Idle;
    float width = 120.0f;
    float height = 36.0f;
};

struct WeatherSnapshot {
    bool hasData = false;
    float temperature = 0.0f;
    int weatherCode = 0;
    std::wstring city;
    std::wstring weatherDesc;
    std::wstring windSpeed;
    std::wstring windDir;
    std::wstring humidity;
    std::wstring feelsLike;
    double lastUpdated = 0.0;
};

struct SharedState {
    MediaSnapshot media;
    ClipboardSnapshot clipboard;
    NotificationSnapshot notification;
    VolumeSnapshot volume;
    CapsLockSnapshot capsLock;
    DeviceSnapshot device;
    BatterySnapshot battery;
    ProgressSnapshot progress;
    SystemSnapshot system;
    WeatherSnapshot weather;
    std::array<float, 48> waveform{};
    size_t waveformWrite = 0;
    bool muted = false;
};

struct SpringValue {
    float value = 0.0f;
    float velocity = 0.0f;
    float target = 0.0f;

    void Reset(float v) {
        value = target = v;
        velocity = 0.0f;
    }

    void Step(float totalDt, float stiffness, float damping) {
        const float kFixedDt = 0.0005f;
        while (totalDt > 0.0f) {
            float dt = std::min(totalDt, kFixedDt);
            const float displacement = value - target;
            const float acceleration = -stiffness * displacement - damping * velocity;
            velocity += acceleration * dt;
            value += velocity * dt;
            totalDt -= dt;
        }

        if (std::fabs(value - target) < 0.01f && std::fabs(velocity) < 0.01f) {
            value = target;
            velocity = 0.0f;
        }
    }
};

Settings g_settings;
std::mutex g_stateMutex;
SharedState g_state;
std::atomic<uint64_t> g_artGenerationCounter = 0;

HWND g_hwnd = nullptr;
HANDLE g_stopEvent = nullptr;
HANDLE g_settingsChangedEvent = nullptr;
HANDLE g_renderThread = nullptr;
HANDLE g_mediaThread = nullptr;
HANDLE g_audioThread = nullptr;
HANDLE g_weatherThread = nullptr;
HANDLE g_notificationThread = nullptr;
std::atomic<bool> g_running = false;
std::atomic<int> g_idleTab = 0;
std::atomic<bool> g_layoutDirty = true;
std::atomic<bool> g_clickExpanded = false;
std::atomic<int> g_pressedMediaButton = -1;
FILETIME g_prevIdleTime = {};
FILETIME g_prevKernelTime = {};
FILETIME g_prevUserTime = {};
UINT g_shellHookMessage = 0;
UINT g_taskbarCreatedMessage = 0;
bool g_volumeInitialized = false;
std::atomic<double> g_lastNudgeTime = 0.0;

constexpr GUID kSubTypeIeeeFloat = {
    0x00000003,
    0x0000,
    0x0010,
    {0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71},
};



double NowSeconds() {
    using clock = std::chrono::steady_clock;
    static const auto start = clock::now();
    return std::chrono::duration<double>(clock::now() - start).count();
}

float Clamp(float v, float lo, float hi) {
    return std::max(lo, std::min(hi, v));
}

int ClampInt(int v, int lo, int hi) {
    return std::max(lo, std::min(hi, v));
}

bool EqualsNoCase(std::wstring_view a, std::wstring_view b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (towlower(a[i]) != towlower(b[i])) {
            return false;
        }
    }

    return true;
}

std::wstring GetStringSettingCopy(PCWSTR name) {
    PCWSTR value = Wh_GetStringSetting(name);
    std::wstring result = value ? value : L"";
    Wh_FreeStringSetting(value);
    return result;
}

D2D1_COLOR_F ColorFromHex(std::wstring text, D2D1_COLOR_F fallback) {
    if (!text.empty() && text[0] == L'#') {
        text.erase(text.begin());
    }

    if (text.size() != 6) {
        return fallback;
    }

    wchar_t* end = nullptr;
    const unsigned long rgb = wcstoul(text.c_str(), &end, 16);
    if (!end || *end != L'\0') {
        return fallback;
    }

    return D2D1::ColorF(
        ((rgb >> 16) & 0xff) / 255.0f,
        ((rgb >> 8) & 0xff) / 255.0f,
        (rgb & 0xff) / 255.0f,
        1.0f);
}

// Returns true if the currently active foreground window is in full screen mode
bool IsForegroundFullscreen(HWND targetHwnd) {
    HWND fg = GetForegroundWindow();
    if (!fg || fg == targetHwnd || fg == GetDesktopWindow() || fg == GetShellWindow()) {
        return false;
    }

    if (!IsWindowVisible(fg)) return false;

    wchar_t className[256] = {};
    GetClassNameW(fg, className, 256);
    if (wcscmp(className, L"WorkerW") == 0 || wcscmp(className, L"Progman") == 0 ||
        wcscmp(className, L"Shell_TrayWnd") == 0) {
        return false;
    }

    RECT clientRect = {};
    if (!GetClientRect(fg, &clientRect)) return false;
    POINT pt = {0, 0};
    ClientToScreen(fg, &pt);
    clientRect.left += pt.x;
    clientRect.right += pt.x;
    clientRect.top += pt.y;
    clientRect.bottom += pt.y;

    HMONITOR hMon = MonitorFromWindow(fg, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi = { sizeof(MONITORINFO) };
    if (GetMonitorInfoW(hMon, &mi)) {
        if (clientRect.left <= mi.rcMonitor.left &&
            clientRect.top <= mi.rcMonitor.top &&
            clientRect.right >= mi.rcMonitor.right &&
            clientRect.bottom >= mi.rcMonitor.bottom) {
            return true;
        }
    }

    return false;
}

// Returns the DPI scale factor for the primary monitor (1.0 = 96 DPI = 100%)
float GetPrimaryMonitorDpiScale() {
    POINT pt = {0, 0};
    HMONITOR monitor = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    UINT dpiX = 96, dpiY = 96;
    using GetDpiForMonitor_t = HRESULT(WINAPI*)(HMONITOR, int, UINT*, UINT*);
    static auto pGetDpiForMonitor = reinterpret_cast<GetDpiForMonitor_t>(
        GetProcAddress(GetModuleHandleW(L"shcore.dll"), "GetDpiForMonitor"));
    if (pGetDpiForMonitor) {
        pGetDpiForMonitor(monitor, 0 /* MDT_EFFECTIVE_DPI */, &dpiX, &dpiY);
    }
    return static_cast<float>(dpiX) / 96.0f;
}

int GetMonitorRefreshRate(HWND hwnd) {
    HMONITOR monitor = nullptr;
    if (hwnd) {
        monitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    } else {
        POINT pt = {0, 0};
        monitor = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    }
    MONITORINFOEXW mi = {};
    mi.cbSize = sizeof(mi);
    if (GetMonitorInfoW(monitor, &mi)) {
        DEVMODEW dm = {};
        dm.dmSize = sizeof(dm);
        if (EnumDisplaySettingsW(mi.szDevice, ENUM_CURRENT_SETTINGS, &dm)) {
            if (dm.dmDisplayFrequency > 1) {
                return static_cast<int>(dm.dmDisplayFrequency);
            }
        }
    }
    HDC hdc = GetDC(nullptr);
    int rate = GetDeviceCaps(hdc, VREFRESH);
    ReleaseDC(nullptr, hdc);
    return (rate > 1) ? rate : 60;
}

D2D1_COLOR_F GetSystemAccentColor() {
    DWORD color = 0;
    BOOL opaque = FALSE;
    using DwmGetColorizationColor_t = HRESULT(WINAPI*)(DWORD*, BOOL*);
    auto proc = reinterpret_cast<DwmGetColorizationColor_t>(
        GetProcAddress(GetModuleHandleW(L"dwmapi.dll"), "DwmGetColorizationColor"));

    if (proc && SUCCEEDED(proc(&color, &opaque))) {
        return D2D1::ColorF(
            ((color >> 16) & 0xff) / 255.0f,
            ((color >> 8) & 0xff) / 255.0f,
            (color & 0xff) / 255.0f,
            1.0f);
    }

    return D2D1::ColorF(0x4cc9f0);
}

void LoadSettings() {
    Settings next;

    const std::wstring position = GetStringSettingCopy(L"Appearance.Position");
    if (EqualsNoCase(position, L"top-left")) {
        next.position = Position::TopLeft;
    } else if (EqualsNoCase(position, L"top-right")) {
        next.position = Position::TopRight;
    } else if (EqualsNoCase(position, L"bottom-center")) {
        next.position = Position::BottomCenter;
    }

    const std::wstring scale = GetStringSettingCopy(L"Appearance.SizeScale");
    if (!scale.empty()) {
        wchar_t* end;
        float parsedScale = wcstof(scale.c_str(), &end);
        if (end != scale.c_str() && parsedScale > 0.1f && parsedScale < 10.0f) {
            next.sizeScale = parsedScale;
        }
    }

    // Auto DPI scaling: multiply sizeScale by monitor DPI factor.
    // On a 4K 200% display this doubles the island to the right physical size.
    if (Wh_GetIntSetting(L"Appearance.AutoDpiScale") != 0) {
        next.sizeScale *= GetPrimaryMonitorDpiScale();
    }

    const std::wstring accentMode = GetStringSettingCopy(L"Themes.AccentColorMode");
    if (EqualsNoCase(accentMode, L"system")) {
        next.accentMode = AccentMode::System;
    } else if (EqualsNoCase(accentMode, L"custom")) {
        next.accentMode = AccentMode::Custom;
    }

    next.customAccent = ColorFromHex(GetStringSettingCopy(L"Themes.CustomAccentHex"), next.customAccent);

    const std::wstring fpsStr = GetStringSettingCopy(L"Appearance.TargetFPS");
    if (EqualsNoCase(fpsStr, L"auto") || fpsStr.empty()) {
        next.targetFps = 0;
    } else {
        next.targetFps = _wtoi(fpsStr.c_str());
        if (next.targetFps < 0) next.targetFps = 0;
    }

    const std::wstring styleStr = GetStringSettingCopy(L"Appearance.AnimationStyle");
    if (EqualsNoCase(styleStr, L"smooth")) {
        next.animationStyle = AnimationStyle::Smooth;
    } else if (EqualsNoCase(styleStr, L"bouncy")) {
        next.animationStyle = AnimationStyle::Bouncy;
    } else if (EqualsNoCase(styleStr, L"snappy")) {
        next.animationStyle = AnimationStyle::Snappy;
    } else {
        next.animationStyle = AnimationStyle::Default;
    }

    const std::wstring speed = GetStringSettingCopy(L"Appearance.AnimationSpeed");
    if (EqualsNoCase(speed, L"very-slow")) {
        next.animationSpeed = 0.5f;
    } else if (EqualsNoCase(speed, L"slow")) {
        next.animationSpeed = 0.75f;
    } else if (EqualsNoCase(speed, L"fast")) {
        next.animationSpeed = 1.35f;
    } else if (EqualsNoCase(speed, L"very-fast")) {
        next.animationSpeed = 1.65f;
    } else if (EqualsNoCase(speed, L"ultra-fast")) {
        next.animationSpeed = 2.0f;
    } else {
        next.animationSpeed = 1.0f;
    }

    next.media = Wh_GetIntSetting(L"Modules.Media") != 0;
    next.mediaAutoExpand = Wh_GetIntSetting(L"Modules.MediaAutoExpand") != 0;
    next.clipboard = Wh_GetIntSetting(L"Modules.Clipboard") != 0;

    const std::wstring clipBgStr = GetStringSettingCopy(L"Modules.ClipboardIconBgStyle");
    if (EqualsNoCase(clipBgStr, L"transparent")) {
        next.clipboardIconBgStyle = ClipboardIconBgStyle::Transparent;
    } else if (EqualsNoCase(clipBgStr, L"accent")) {
        next.clipboardIconBgStyle = ClipboardIconBgStyle::Accent;
    } else if (EqualsNoCase(clipBgStr, L"custom")) {
        next.clipboardIconBgStyle = ClipboardIconBgStyle::Custom;
    } else {
        next.clipboardIconBgStyle = ClipboardIconBgStyle::Default;
    }
    next.clipboardIconBgHex = ColorFromHex(GetStringSettingCopy(L"Modules.ClipboardIconBgHex"), next.clipboardIconBgHex);

    next.battery = Wh_GetIntSetting(L"Modules.Battery") != 0;
    next.progress = Wh_GetIntSetting(L"Modules.Progress") != 0;
    next.privacyDots = Wh_GetIntSetting(L"Modules.PrivacyDots") != 0;
    next.privacyDotsMic = Wh_GetIntSetting(L"Modules.PrivacyDotsMic") != 0;
    next.privacyDotsCam = Wh_GetIntSetting(L"Modules.PrivacyDotsCam") != 0;
    next.privacyDotsPulse = Wh_GetIntSetting(L"Modules.PrivacyDotsPulse") != 0;
    next.privacyDotsMicHex = ColorFromHex(GetStringSettingCopy(L"Modules.PrivacyDotsMicHex"), D2D1::ColorF(1.0f, 0.584f, 0.0f, 1.0f));
    next.privacyDotsCamHex = ColorFromHex(GetStringSettingCopy(L"Modules.PrivacyDotsCamHex"), D2D1::ColorF(0.133f, 0.776f, 0.239f, 1.0f));
    next.capsLock = Wh_GetIntSetting(L"Modules.CapsLock") != 0;
    next.tintOpacity = Clamp(Wh_GetIntSetting(L"Themes.TintIntensity") / 100.0f, 0.0f, 1.0f);
    const int settingOpacity = Wh_GetIntSetting(L"Themes.PillOpacity");
    const int localOpacity = Wh_GetIntValue(L"PillOpacityOverride", -1);
    next.pillOpacity = Clamp((localOpacity >= 0 ? localOpacity : settingOpacity) / 100.0f,
                             0.35f, 1.0f);
    next.gameOverlay = Wh_GetIntSetting(L"Modules.GameOverlay") != 0;
    next.showMetricText = Wh_GetIntSetting(L"Modules.ShowMetricText") != 0;
    next.weather = Wh_GetIntSetting(L"Modules.Weather") != 0;
    next.weatherCity = GetStringSettingCopy(L"Modules.WeatherCity");
    next.weatherFahrenheit = Wh_GetIntSetting(L"Modules.WeatherFahrenheit") != 0;
    const std::wstring hideSec = GetStringSettingCopy(L"Appearance.AutoHideIdleSeconds");
    next.autoHideIdleSeconds = hideSec.empty() ? 0 : _wtoi(hideSec.c_str());
    next.unhideOnHover = Wh_GetIntSetting(L"Appearance.UnhideOnHover") != 0;
    next.alwaysOnTop = Wh_GetIntSetting(L"Appearance.AlwaysOnTop") != 0;
    const int localExpandOnHover = Wh_GetIntValue(L"ExpandOnHoverOverride", -1);
    next.expandOnHover = localExpandOnHover >= 0 ? (localExpandOnHover != 0) : (Wh_GetIntSetting(L"Appearance.ExpandOnHover") != 0);
    next.autoDpiScale = Wh_GetIntSetting(L"Appearance.AutoDpiScale") != 0;
    next.offsetX = Wh_GetIntSetting(L"Appearance.OffsetX");
    next.offsetY = Wh_GetIntSetting(L"Appearance.OffsetY");

    std::wstring mon = GetStringSettingCopy(L"Appearance.TargetMonitor");
    if (mon == L"primary") next.targetMonitor = 0;
    else if (mon == L"follow") next.targetMonitor = -1;
    else next.targetMonitor = _wtoi(mon.c_str());

    std::wstring shapeStr = GetStringSettingCopy(L"Appearance.ShapeStyle");
    bool baseW11 = EqualsNoCase(shapeStr, L"w11");
    bool baseNotch = EqualsNoCase(shapeStr, L"notch");

    const int localW11Style = Wh_GetIntValue(L"W11StyleOverride", -1);
    next.w11Style = localW11Style >= 0 ? (localW11Style != 0) : baseW11;

    const int localNotchStyle = Wh_GetIntValue(L"NotchStyleOverride", -1);
    next.notchStyle = localNotchStyle >= 0 ? (localNotchStyle != 0) : baseNotch;

    // Color settings — check local theme override first, then settings YAML.
    struct ThemeColors { const wchar_t* bg; const wchar_t* fg; const wchar_t* sec; };
    static constexpr ThemeColors kThemes[] = {
        {L"#0D0D0F", L"#F7F7F7", L"#888888"},  // 0: OLED Black
        {L"#1C1C1E", L"#FFFFFF", L"#999999"},  // 1: Dark Gray
        {L"#050D1A", L"#E8F0FF", L"#7090BB"},  // 2: Midnight Blue
        {L"#0E0014", L"#F0E8FF", L"#9060BB"},  // 3: Deep Purple
        {L"#1F1F1F", L"#FFFFFF", L"#A0A0A0"},  // 4: Fluent Design
    };
    const int theme = Wh_GetIntValue(L"ColorTheme", -1);
    if (theme >= 0 && theme < static_cast<int>(ARRAYSIZE(kThemes))) {
        next.pillBgColor = ColorFromHex(kThemes[theme].bg,
                                        D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f));
        next.textPrimaryColor = ColorFromHex(kThemes[theme].fg,
                                             D2D1::ColorF(0.969f, 0.969f, 0.969f, 1.0f));
        next.textSecondaryColor = ColorFromHex(kThemes[theme].sec,
                                               D2D1::ColorF(0.533f, 0.533f, 0.533f, 1.0f));
    } else {
        next.pillBgColor = ColorFromHex(GetStringSettingCopy(L"Themes.PillBgColor"),
                                        D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f));
        next.textPrimaryColor = ColorFromHex(GetStringSettingCopy(L"Themes.TextPrimaryColor"),
                                             D2D1::ColorF(0.969f, 0.969f, 0.969f, 1.0f));
        next.textSecondaryColor = ColorFromHex(GetStringSettingCopy(L"Themes.TextSecondaryColor"),
                                               D2D1::ColorF(0.533f, 0.533f, 0.533f, 1.0f));
    }

    next.borderMergedMode = Wh_GetIntSetting(L"Appearance.BorderMergedMode") != 0;
    next.autoHideFullscreen = Wh_GetIntSetting(L"Appearance.AutoHideFullscreen") != 0;
    next.hardwareMonitorModule = Wh_GetIntSetting(L"Modules.HardwareMonitorModule") != 0;
    next.contourBorderEnabled = Wh_GetIntSetting(L"Themes.ContourBorderEnabled") != 0;
    next.contourBorderColor = ColorFromHex(GetStringSettingCopy(L"Themes.ContourBorderHex"), D2D1::ColorF(0.200f, 0.200f, 0.220f, 1.0f));
    next.privacyDotsEnabled = Wh_GetIntSetting(L"Indicators.PrivacyDotsEnabled") != 0;
    next.privacyDotPulsing = Wh_GetIntSetting(L"Indicators.PrivacyDotPulsing") != 0;
    next.micDotColor = ColorFromHex(GetStringSettingCopy(L"Indicators.MicDotHex"), D2D1::ColorF(1.0f, 0.584f, 0.0f, 1.0f));
    next.camDotColor = ColorFromHex(GetStringSettingCopy(L"Indicators.CamDotHex"), D2D1::ColorF(0.204f, 0.780f, 0.349f, 1.0f));

    Wh_SetIntValue(L"PinnedExpanded", 0);

    bool cityChanged = next.weatherCity != g_settings.weatherCity;
    g_settings = next;
    g_layoutDirty = true;
    if (cityChanged && g_settingsChangedEvent) {
        SetEvent(g_settingsChangedEvent);
    }
}

void EnableBlurBehind(HWND hwnd) {
    DWM_BLURBEHIND blur = {};
    blur.dwFlags = DWM_BB_ENABLE;
    blur.fEnable = FALSE;
    DwmEnableBlurBehindWindow(hwnd, &blur);
}



struct MonitorEnumData {
    std::vector<HMONITOR> monitors;
};

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC, LPRECT, LPARAM dwData) {
    auto* data = reinterpret_cast<MonitorEnumData*>(dwData);
    data->monitors.push_back(hMonitor);
    return TRUE;
}

RECT GetAnchorWorkRect() {
    HMONITOR selectedMonitor = nullptr;

    if (g_settings.targetMonitor == -1) {
        POINT pt = {0, 0};
        GetCursorPos(&pt);
        selectedMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
    } else if (g_settings.targetMonitor > 0) {
        MonitorEnumData data;
        EnumDisplayMonitors(nullptr, nullptr, MonitorEnumProc, reinterpret_cast<LPARAM>(&data));
        
        int index = g_settings.targetMonitor - 1;
        if (index >= 0 && index < static_cast<int>(data.monitors.size())) {
            selectedMonitor = data.monitors[index];
        }
    }

    if (!selectedMonitor) {
        POINT pt = {0, 0};
        selectedMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTOPRIMARY);
    }

    MONITORINFO mi = {sizeof(mi)};
    GetMonitorInfoW(selectedMonitor, &mi);
    return mi.rcWork;
}

void PositionOverlayWindow(HWND hwnd, int width, int height) {
    RECT work = GetAnchorWorkRect();
    int x = work.left + (work.right - work.left - width) / 2;
    int y = g_settings.notchStyle ? work.top : (work.top + 8);

    switch (g_settings.position) {
        case Position::TopLeft:
            x = work.left + 16;
            y = g_settings.notchStyle ? work.top : (work.top + 8);
            break;
        case Position::TopRight:
            x = work.right - width - 16;
            y = g_settings.notchStyle ? work.top : (work.top + 8);
            break;
        case Position::BottomCenter:
            x = work.left + (work.right - work.left - width) / 2;
            y = work.bottom - height - 40;
            break;
        case Position::TopCenter:
        default:
            break;
    }

    HWND zOrder = g_settings.alwaysOnTop ? HWND_TOPMOST : HWND_NOTOPMOST;
    
    // Manage owner window to firmly anchor to desktop when alwaysOnTop is false
    if (g_settings.alwaysOnTop) {
        SetWindowLongPtr(hwnd, GWLP_HWNDPARENT, 0);
    } else {
        HWND hProgman = FindWindowW(L"Progman", nullptr);
        if (hProgman) {
            SetWindowLongPtr(hwnd, GWLP_HWNDPARENT, reinterpret_cast<LONG_PTR>(hProgman));
        }
    }

    x += g_settings.offsetX;
    y += g_settings.offsetY;
    SetWindowPos(hwnd, zOrder, x, y, width, height,
                 SWP_NOACTIVATE | SWP_NOOWNERZORDER | SWP_SHOWWINDOW);
}

bool DecodeImageBytesToPixels(const std::vector<uint8_t>& bytes, BitmapPixels* outPixels) {
    if (!outPixels || bytes.empty()) {
        return false;
    }

    ComPtr<IWICImagingFactory> factory;
    HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
                                  IID_PPV_ARGS(&factory));
    if (FAILED(hr)) {
        return false;
    }

    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, bytes.size());
    if (!mem) {
        return false;
    }

    void* locked = GlobalLock(mem);
    memcpy(locked, bytes.data(), bytes.size());
    GlobalUnlock(mem);

    ComPtr<IStream> stream;
    hr = CreateStreamOnHGlobal(mem, TRUE, &stream);
    if (FAILED(hr)) {
        GlobalFree(mem);
        return false;
    }

    ComPtr<IWICBitmapDecoder> decoder;
    hr = factory->CreateDecoderFromStream(stream.Get(), nullptr, WICDecodeMetadataCacheOnLoad,
                                          &decoder);
    if (FAILED(hr)) {
        return false;
    }

    ComPtr<IWICBitmapFrameDecode> frame;
    hr = decoder->GetFrame(0, &frame);
    if (FAILED(hr)) {
        return false;
    }

    ComPtr<IWICFormatConverter> converter;
    hr = factory->CreateFormatConverter(&converter);
    if (FAILED(hr)) {
        return false;
    }

    hr = converter->Initialize(frame.Get(), GUID_WICPixelFormat32bppPBGRA,
                               WICBitmapDitherTypeNone, nullptr, 0.0,
                               WICBitmapPaletteTypeCustom);
    if (FAILED(hr)) {
        return false;
    }

    UINT width = 0;
    UINT height = 0;
    converter->GetSize(&width, &height);
    if (!width || !height || width > 2048 || height > 2048) {
        return false;
    }

    BitmapPixels pixels;
    pixels.width = width;
    pixels.height = height;
    pixels.bgra.resize(static_cast<size_t>(width) * height * 4);

    hr = converter->CopyPixels(nullptr, width * 4,
                               static_cast<UINT>(pixels.bgra.size()),
                               pixels.bgra.data());
    if (FAILED(hr)) {
        return false;
    }

    struct Bucket {
        uint32_t count = 0;
        uint32_t r = 0;
        uint32_t g = 0;
        uint32_t b = 0;
    };

    std::array<Bucket, 16 * 16 * 16> buckets{};
    for (size_t i = 0; i + 3 < pixels.bgra.size(); i += 4) {
        const uint8_t alpha = pixels.bgra[i + 3];
        const uint8_t blue = pixels.bgra[i + 0];
        const uint8_t green = pixels.bgra[i + 1];
        const uint8_t red = pixels.bgra[i + 2];
        if (alpha < 32) {
            continue;
        }

        const int maxc = std::max({red, green, blue});
        const int minc = std::min({red, green, blue});
        const int luminance = (54 * red + 183 * green + 19 * blue) / 256;
        const int saturation = maxc - minc;
        if (luminance < 28 || luminance > 232 || saturation < 24) {
            continue;
        }

        const size_t bucketIndex = ((red >> 4) << 8) | ((green >> 4) << 4) | (blue >> 4);
        Bucket& bucket = buckets[bucketIndex];
        const uint32_t weight = 1 + static_cast<uint32_t>(saturation / 48);
        bucket.count += weight;
        bucket.r += red * weight;
        bucket.g += green * weight;
        bucket.b += blue * weight;
    }

    const Bucket* best = nullptr;
    for (const Bucket& bucket : buckets) {
        if (!best || bucket.count > best->count) {
            best = &bucket;
        }
    }

    if (best && best->count > 0) {
        pixels.sampledAccent = D2D1::ColorF(
            Clamp((best->r / static_cast<float>(best->count)) / 255.0f, 0.14f, 1.0f),
            Clamp((best->g / static_cast<float>(best->count)) / 255.0f, 0.14f, 1.0f),
            Clamp((best->b / static_cast<float>(best->count)) / 255.0f, 0.14f, 1.0f),
            1.0f);
    }

    pixels.generation = ++g_artGenerationCounter;
    *outPixels = std::move(pixels);
    return true;
}

bool IconToPixels(HICON icon, UINT size, BitmapPixels* outPixels) {
    if (!icon || !outPixels || !size) {
        return false;
    }

    HDC screen = GetDC(nullptr);
    HDC dc = CreateCompatibleDC(screen);
    ReleaseDC(nullptr, screen);
    if (!dc) {
        return false;
    }

    BITMAPINFO bi = {};
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = static_cast<LONG>(size);
    bi.bmiHeader.biHeight = -static_cast<LONG>(size);
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    void* bits = nullptr;
    HBITMAP bitmap = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    if (!bitmap) {
        DeleteDC(dc);
        return false;
    }

    // Fill with transparent black (alpha=0) so icon edges don't bleed dark fringe.
    HGDIOBJ old = SelectObject(dc, bitmap);
    RECT fill = {0, 0, static_cast<LONG>(size), static_cast<LONG>(size)};
    // Use NULL_BRUSH (transparent) then manually zero-fill the BGRA buffer after copy.
    FillRect(dc, &fill, reinterpret_cast<HBRUSH>(GetStockObject(NULL_BRUSH)));
    // Zero out the bits so background is fully transparent before drawing icon.
    ZeroMemory(bits, static_cast<size_t>(size) * size * 4);
    DrawIconEx(dc, 0, 0, icon, size, size, 0, nullptr, DI_NORMAL);

    BitmapPixels pixels;
    pixels.width = size;
    pixels.height = size;
    pixels.bgra.resize(static_cast<size_t>(size) * size * 4);
    memcpy(pixels.bgra.data(), bits, pixels.bgra.size());

    // Older icons can have no alpha in the color bitmap. Treat black pixels as
    // transparent only when the icon did not write any alpha at all.
    bool hasAlpha = false;
    for (size_t i = 3; i < pixels.bgra.size(); i += 4) {
        if (pixels.bgra[i] != 0) {
            hasAlpha = true;
            break;
        }
    }
    if (!hasAlpha) {
        // No alpha channel: treat near-black as transparent, rest as opaque.
        for (size_t i = 0; i + 3 < pixels.bgra.size(); i += 4) {
            const bool black = pixels.bgra[i] < 4 && pixels.bgra[i + 1] < 4 && pixels.bgra[i + 2] < 4;
            pixels.bgra[i + 3] = black ? 0 : 255;
        }
    } else {
        // Convert to premultiplied alpha so D2D renders edges cleanly without dark fringing.
        for (size_t i = 0; i + 3 < pixels.bgra.size(); i += 4) {
            const uint8_t a = pixels.bgra[i + 3];
            if (a < 255 && a > 0) {
                pixels.bgra[i + 0] = static_cast<uint8_t>(pixels.bgra[i + 0] * a / 255);
                pixels.bgra[i + 1] = static_cast<uint8_t>(pixels.bgra[i + 1] * a / 255);
                pixels.bgra[i + 2] = static_cast<uint8_t>(pixels.bgra[i + 2] * a / 255);
            }
        }
    }

    pixels.generation = ++g_artGenerationCounter;
    *outPixels = std::move(pixels);

    SelectObject(dc, old);
    DeleteObject(bitmap);
    DeleteDC(dc);
    return true;
}

bool ProcessImageNameForPid(DWORD pid, std::wstring* imageName) {
    if (!pid || !imageName) {
        return false;
    }

    HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
    if (!process) {
        return false;
    }

    wchar_t path[MAX_PATH] = {};
    DWORD size = ARRAYSIZE(path);
    const bool ok = QueryFullProcessImageNameW(process, 0, path, &size) != FALSE;
    CloseHandle(process);
    if (ok) {
        *imageName = path;
    }
    return ok;
}

HICON CopyWindowIcon(HWND hwnd, WPARAM iconType) {
    DWORD_PTR result = 0;
    SendMessageTimeoutW(hwnd, WM_GETICON, iconType, 0,
                        SMTO_ABORTIFHUNG | SMTO_BLOCK, 80, &result);
    return result ? CopyIcon(reinterpret_cast<HICON>(result)) : nullptr;
}

HICON getProcessIcon(DWORD pid) {
    std::wstring path;
    if (ProcessImageNameForPid(pid, &path) && !path.empty()) {
        HICON hIcon = nullptr;
        UINT iconId = 0;
        // Try to fetch a high-res 64x64 icon first to avoid pixelated icons
        using PrivateExtractIconsW_t = UINT(WINAPI*)(LPCWSTR, int, int, int, HICON*, UINT*, UINT, UINT);
        static auto pPrivateExtractIconsW = reinterpret_cast<PrivateExtractIconsW_t>(
            GetProcAddress(GetModuleHandleW(L"user32.dll"), "PrivateExtractIconsW"));
        if (pPrivateExtractIconsW && pPrivateExtractIconsW(path.c_str(), 0, 64, 64, &hIcon, &iconId, 1, 0) == 1 && hIcon) {
            return hIcon;
        }

        SHFILEINFOW sfi = {};
        if (SHGetFileInfoW(path.c_str(), 0, &sfi, sizeof(sfi),
                           SHGFI_ICON | SHGFI_LARGEICON)) {
            return sfi.hIcon;
        }

        HICON large = nullptr;
        HICON small = nullptr;
        if (ExtractIconExW(path.c_str(), 0, &large, &small, 1) > 0) {
            if (small) {
                DestroyIcon(small);
            }
            if (large) {
                return large;
            }
        }
    }

    return CopyIcon(LoadIconW(nullptr, IDI_APPLICATION));
}

HICON getWindowIcon(HWND hwnd) {
    if (!hwnd) {
        return CopyIcon(LoadIconW(nullptr, IDI_APPLICATION));
    }

    if (HICON icon = CopyWindowIcon(hwnd, ICON_BIG)) {
        return icon;
    }
    if (HICON icon = CopyWindowIcon(hwnd, ICON_SMALL)) {
        return icon;
    }

    if (auto icon = reinterpret_cast<HICON>(GetClassLongPtrW(hwnd, GCLP_HICON))) {
        return CopyIcon(icon);
    }
    if (auto icon = reinterpret_cast<HICON>(GetClassLongPtrW(hwnd, GCLP_HICONSM))) {
        return CopyIcon(icon);
    }

    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    return getProcessIcon(pid);
}

std::wstring ToLowerCopy(std::wstring value) {
    std::transform(value.begin(), value.end(), value.begin(),
                   [](wchar_t ch) { return static_cast<wchar_t>(towlower(ch)); });
    return value;
}

std::wstring BaseNameFromPath(std::wstring path) {
    const size_t slash = path.find_last_of(L"\\/");
    if (slash != std::wstring::npos) {
        path.erase(0, slash + 1);
    }
    return path;
}

std::wstring StripExtension(std::wstring value) {
    const size_t dot = value.find_last_of(L'.');
    if (dot != std::wstring::npos) {
        value.resize(dot);
    }
    return value;
}

bool ProcessImageNameForWindow(HWND hwnd, std::wstring* imageName) {
    if (!imageName) {
        return false;
    }

    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    if (!pid) {
        return false;
    }

    return ProcessImageNameForPid(pid, imageName);
}

std::wstring FriendlyMediaSourceName(std::wstring_view source) {
    const std::wstring lower = ToLowerCopy(std::wstring(source));
    if (lower.find(L"youtube") != std::wstring::npos) return L"YouTube";
    if (lower.find(L"spotify") != std::wstring::npos) return L"Spotify";
    if (lower.find(L"chrome") != std::wstring::npos) return L"Chrome";
    if (lower.find(L"msedge") != std::wstring::npos || lower.find(L"edge") != std::wstring::npos) return L"Edge";
    if (lower.find(L"firefox") != std::wstring::npos) return L"Firefox";
    if (lower.find(L"vlc") != std::wstring::npos) return L"VLC";
    if (lower.find(L"wmplayer") != std::wstring::npos) return L"Windows Media";
    if (lower.find(L"zune") != std::wstring::npos || lower.find(L"media") != std::wstring::npos) return L"Media Player";

    std::wstring text(source);
    const size_t bang = text.find(L'!');
    if (bang != std::wstring::npos && bang + 1 < text.size()) {
        text.erase(0, bang + 1);
    }
    const size_t dot = text.find(L'.');
    if (dot != std::wstring::npos) {
        text.resize(dot);
    }
    return text.empty() ? L"Media" : text;
}

std::wstring MediaSourceBadge(std::wstring_view sourceName) {
    const std::wstring lower = ToLowerCopy(std::wstring(sourceName));
    if (lower.find(L"youtube") != std::wstring::npos) return L"YT";
    if (lower.find(L"spotify") != std::wstring::npos) return L"SP";
    if (lower.find(L"chrome") != std::wstring::npos) return L"CH";
    if (lower.find(L"edge") != std::wstring::npos) return L"ED";
    if (lower.find(L"firefox") != std::wstring::npos) return L"FF";
    if (lower.find(L"vlc") != std::wstring::npos) return L"VLC";
    if (sourceName.empty()) return L"\u25b6";
    std::wstring badge;
    badge.push_back(static_cast<wchar_t>(towupper(sourceName[0])));
    return badge;
}

bool WindowLooksLikeMediaSource(HWND hwnd, const std::wstring& sourceLower) {
    if (!IsWindowVisible(hwnd) || hwnd == g_hwnd) {
        return false;
    }

    std::wstring image;
    if (!ProcessImageNameForWindow(hwnd, &image)) {
        return false;
    }

    const std::wstring base = ToLowerCopy(BaseNameFromPath(image));
    if (base.empty()) {
        return false;
    }

    return sourceLower.find(base) != std::wstring::npos ||
           (base.find(L"chrome") != std::wstring::npos && sourceLower.find(L"chrome") != std::wstring::npos) ||
           (base.find(L"msedge") != std::wstring::npos && sourceLower.find(L"edge") != std::wstring::npos) ||
           (base.find(L"vlc") != std::wstring::npos && sourceLower.find(L"vlc") != std::wstring::npos);
}

bool IsBrowserMediaSource(std::wstring_view source) {
    const std::wstring lower = ToLowerCopy(std::wstring(source));
    return lower.find(L"chrome") != std::wstring::npos ||
           lower.find(L"edge") != std::wstring::npos ||
           lower.find(L"msedge") != std::wstring::npos ||
           lower.find(L"firefox") != std::wstring::npos ||
           lower.find(L"youtube") != std::wstring::npos;
}

std::wstring SiteBadgeFromTitle(std::wstring_view title) {
    const std::wstring lower = ToLowerCopy(std::wstring(title));
    if (lower.find(L"youtube") != std::wstring::npos) return L"YT";
    if (lower.find(L"netflix") != std::wstring::npos) return L"NF";
    if (lower.find(L"prime video") != std::wstring::npos || lower.find(L"amazon") != std::wstring::npos) return L"PV";
    if (lower.find(L"disney") != std::wstring::npos) return L"D+";
    if (lower.find(L"hotstar") != std::wstring::npos) return L"HS";
    if (lower.find(L"spotify") != std::wstring::npos) return L"SP";
    if (lower.find(L"soundcloud") != std::wstring::npos) return L"SC";
    return L"WEB";
}

struct IconCacheEntry {
    DWORD pid = 0;
    std::wstring exePath;
    BitmapPixels pixels;
    uint64_t lastUsed = 0;
};

std::mutex g_iconCacheMutex;
std::unordered_map<DWORD, IconCacheEntry> g_iconCacheByPid;
uint64_t g_iconCacheClock = 0;

BitmapPixels GetCachedProcessIconPixels(DWORD pid, UINT size) {
    std::wstring exePath;
    ProcessImageNameForPid(pid, &exePath);

    {
        std::lock_guard lock(g_iconCacheMutex);
        auto it = g_iconCacheByPid.find(pid);
        if (it != g_iconCacheByPid.end() && it->second.exePath == exePath &&
            it->second.pixels.width == size) {
            it->second.lastUsed = ++g_iconCacheClock;
            return it->second.pixels;
        }
    }

    BitmapPixels pixels;
    HICON icon = getProcessIcon(pid);
    if (icon) {
        IconToPixels(icon, size, &pixels);
        DestroyIcon(icon);
    }

    if (!pixels.bgra.empty()) {
        std::lock_guard lock(g_iconCacheMutex);
        g_iconCacheByPid[pid] = IconCacheEntry{pid, exePath, pixels, ++g_iconCacheClock};
        if (g_iconCacheByPid.size() > 32) {
            auto oldest = g_iconCacheByPid.begin();
            for (auto it = g_iconCacheByPid.begin(); it != g_iconCacheByPid.end(); ++it) {
                if (it->second.lastUsed < oldest->second.lastUsed) {
                    oldest = it;
                }
            }
            g_iconCacheByPid.erase(oldest);
        }
    }

    return pixels;
}

BitmapPixels GetWindowIconPixels(HWND hwnd, UINT size) {
    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    BitmapPixels pixels = GetCachedProcessIconPixels(pid, size);
    if (!pixels.bgra.empty()) {
        return pixels;
    }

    HICON icon = getWindowIcon(hwnd);
    if (icon) {
        IconToPixels(icon, size, &pixels);
        DestroyIcon(icon);
    }
    return pixels;
}

bool IsIgnorableForegroundWindow(HWND hwnd, const std::wstring& title) {
    wchar_t className[128] = {};
    GetClassNameW(hwnd, className, ARRAYSIZE(className));
    const std::wstring cls = ToLowerCopy(className);
    const std::wstring lowerTitle = ToLowerCopy(title);

    std::wstring image;
    ProcessImageNameForWindow(hwnd, &image);
    const std::wstring base = ToLowerCopy(BaseNameFromPath(image));

    return title.empty() ||
           hwnd == g_hwnd ||
           cls == L"shell_traywnd" ||
           cls == L"workerw" ||
           cls == L"progman" ||
           lowerTitle.find(L"windhawk") != std::wstring::npos ||
           base == L"explorer.exe" ||
           base == L"windhawk.exe";
}

BOOL CALLBACK FindMediaSourceWindowProc(HWND hwnd, LPARAM lParam) {
    auto* data = reinterpret_cast<std::pair<const std::wstring*, HWND*>*>(lParam);
    if (WindowLooksLikeMediaSource(hwnd, *data->first)) {
        *data->second = hwnd;
        return FALSE;
    }
    return TRUE;
}

std::wstring FindBrowserMediaSiteBadge(const std::wstring& sourceAppUserModelId) {
    const std::wstring sourceLower = ToLowerCopy(sourceAppUserModelId);
    HWND found = nullptr;
    std::pair<const std::wstring*, HWND*> data{&sourceLower, &found};
    EnumWindows(FindMediaSourceWindowProc, reinterpret_cast<LPARAM>(&data));
    if (found) {
        wchar_t title[192] = {};
        GetWindowTextW(found, title, ARRAYSIZE(title));
        return SiteBadgeFromTitle(title);
    }
    return L"WEB";
}

BitmapPixels FindMediaSourceIcon(const std::wstring& sourceAppUserModelId) {
    BitmapPixels pixels;
    if (IsBrowserMediaSource(sourceAppUserModelId)) {
        // Continue searching for the browser window anyway to retrieve
        // the browser's app icon or the PWA's app icon.
    }

    const std::wstring sourceLower = ToLowerCopy(sourceAppUserModelId);
    HWND found = nullptr;
    std::pair<const std::wstring*, HWND*> data{&sourceLower, &found};
    EnumWindows(FindMediaSourceWindowProc, reinterpret_cast<LPARAM>(&data));
    if (found) {
        pixels = GetWindowIconPixels(found, 32);
    }
    return pixels;
}

struct FindAppIconData {
    const std::wstring* targetName;
    HWND bestHwnd = nullptr;
    std::unordered_map<DWORD, std::wstring> pidToProcessName;
};

BOOL CALLBACK FindAppIconWindowProc(HWND hwnd, LPARAM lParam) {
    auto* d = reinterpret_cast<FindAppIconData*>(lParam);
    if (!IsWindowVisible(hwnd)) {
        return TRUE;
    }

    if (hwnd == g_hwnd) {
        return TRUE;
    }

    // 1. Fast path: Check window title first (lightweight check without opening process handles)
    wchar_t title[128] = {};
    GetWindowTextW(hwnd, title, ARRAYSIZE(title));
    std::wstring titleLower = ToLowerCopy(title);
    if (!titleLower.empty() && titleLower.find(*d->targetName) != std::wstring::npos) {
        d->bestHwnd = hwnd;
        return FALSE; // Found via title, stop enumeration
    }

    // 2. Slow path fallback: Check process executable name
    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);
    if (!pid) {
        return TRUE;
    }

    std::wstring baseNoExe;
    auto it = d->pidToProcessName.find(pid);
    if (it != d->pidToProcessName.end()) {
        baseNoExe = it->second;
    } else {
        std::wstring image;
        if (ProcessImageNameForPid(pid, &image)) {
            std::wstring base = ToLowerCopy(BaseNameFromPath(image));
            baseNoExe = base;
            if (baseNoExe.size() > 4 && baseNoExe.substr(baseNoExe.size() - 4) == L".exe") {
                baseNoExe = baseNoExe.substr(0, baseNoExe.size() - 4);
            }
            d->pidToProcessName[pid] = baseNoExe;
        } else {
            d->pidToProcessName[pid] = L"";
        }
    }

    if (!baseNoExe.empty()) {
        if (baseNoExe.find(*d->targetName) != std::wstring::npos ||
            d->targetName->find(baseNoExe) != std::wstring::npos) {
            d->bestHwnd = hwnd;
            return FALSE; // Found via process name, stop enumeration
        }
    }

    return TRUE;
}

BitmapPixels FindAppIconByName(const std::wstring& appName, UINT size) {
    BitmapPixels pixels;
    if (appName.empty()) {
        return pixels;
    }

    const std::wstring appNameLower = ToLowerCopy(appName);
    FindAppIconData data;
    data.targetName = &appNameLower;

    EnumWindows(FindAppIconWindowProc, reinterpret_cast<LPARAM>(&data));

    if (data.bestHwnd) {
        pixels = GetWindowIconPixels(data.bestHwnd, size);
    }
    return pixels;
}

std::vector<uint8_t> ReadWinRtStreamBytes(
    const winrt::Windows::Storage::Streams::IRandomAccessStreamReference& reference) {
    std::vector<uint8_t> bytes;
    if (!reference) {
        return bytes;
    }

    auto stream = reference.OpenReadAsync().get();
    if (!stream) {
        return bytes;
    }

    const uint64_t size64 = stream.Size();
    if (size64 == 0 || size64 > 8 * 1024 * 1024) {
        return bytes;
    }

    const uint32_t size = static_cast<uint32_t>(size64);
    winrt::Windows::Storage::Streams::DataReader reader(stream.GetInputStreamAt(0));
    reader.LoadAsync(size).get();
    bytes.resize(size);
    reader.ReadBytes(winrt::array_view<uint8_t>(bytes.data(), bytes.data() + bytes.size()));
    return bytes;
}

void TriggerNudge() {
    const double now = NowSeconds();
    const double previous = g_lastNudgeTime.load();
    if (now - previous < 0.45) {
        return;
    }
    g_lastNudgeTime = now;
    HWND hwnd = g_hwnd;
    if (hwnd) {
        PostMessageW(hwnd, WM_APP_NEW_EVENT, 0, 0);
    }
}

DWORD WINAPI MediaThreadProc(void*) {
    winrt::init_apartment(winrt::apartment_type::multi_threaded);

    using Manager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
    using PlaybackStatus = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionPlaybackStatus;

    Manager manager{nullptr};
    bool loggedUnavailable = false;

    while (WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
        MediaSnapshot next;

        try {
            if (!manager) {
                manager = Manager::RequestAsync().get();
            }

            if (manager) {
                auto session = manager.GetCurrentSession();
                if (session) {
                    auto properties = session.TryGetMediaPropertiesAsync().get();
                    auto playback = session.GetPlaybackInfo();
                    auto timeline = session.GetTimelineProperties();

                    next.available = true;
                    next.playing = playback.PlaybackStatus() == PlaybackStatus::Playing;
                    next.title = properties.Title().c_str();
                    next.artist = properties.Artist().c_str();
                    next.albumTitle = properties.AlbumTitle().c_str();
                    
                    if (timeline) {
                        int64_t np = timeline.Position().count();
                        int64_t ne = timeline.EndTime().count();
                        bool npP = (playback.PlaybackStatus() == PlaybackStatus::Playing);
                        
                        std::lock_guard lock(g_stateMutex);
                        if (np != g_state.media.positionTicks ||
                            ne != g_state.media.endTicks ||
                            npP != g_state.media.playing) {
                            next.positionTicks = np;
                            next.endTicks = ne;
                            next.lastUpdatedTicks = GetTickCount64();
                        } else {
                            next.positionTicks = g_state.media.positionTicks;
                            next.endTicks = g_state.media.endTicks;
                            next.lastUpdatedTicks = g_state.media.lastUpdatedTicks;
                        }
                    }

                    next.sourceAppUserModelId = session.SourceAppUserModelId().c_str();
                    next.sourceName = FriendlyMediaSourceName(next.sourceAppUserModelId);
                    
                    // Fallback for VLC which sometimes fails to provide SMTC Title metadata
                    if (next.title.empty() && next.sourceName == L"VLC") {
                        HWND hwnd = nullptr;
                        while ((hwnd = FindWindowExW(nullptr, hwnd, nullptr, nullptr)) != nullptr) {
                            wchar_t windowTitle[512];
                            if (GetWindowTextW(hwnd, windowTitle, ARRAYSIZE(windowTitle))) {
                                std::wstring t(windowTitle);
                                const std::wstring suffix = L" - VLC media player";
                                if (t.size() > suffix.size() && t.substr(t.size() - suffix.size()) == suffix) {
                                    next.title = t.substr(0, t.size() - suffix.size());
                                    break;
                                }
                            }
                        }
                    }
                    
                    std::wstring prevSourceAppUserModelId;
                    bool hasPrevIcon = false;
                    BitmapPixels prevIcon;
                    uint64_t prevIconGeneration = 0;
                    std::wstring prevBadge;
                    
                    std::wstring prevTitle;
                    std::wstring prevArtist;
                    BitmapPixels prevArt;
                    uint64_t prevArtGeneration = 0;
                    double prevArtChangedAt = 0.0;
                    
                    {
                        std::lock_guard lock(g_stateMutex);
                        prevSourceAppUserModelId = g_state.media.sourceAppUserModelId;
                        hasPrevIcon = !g_state.media.sourceIcon.bgra.empty();
                        prevIcon = g_state.media.sourceIcon;
                        prevIconGeneration = g_state.media.sourceIconGeneration;
                        prevBadge = g_state.media.sourceBadge;
                        
                        prevTitle = g_state.media.title;
                        prevArtist = g_state.media.artist;
                        prevArt = g_state.media.art;
                        prevArtGeneration = g_state.media.artGeneration;
                        prevArtChangedAt = g_state.media.artChangedAt;
                    }

                    if (next.sourceAppUserModelId == prevSourceAppUserModelId) {
                        next.sourceBadge = prevBadge;
                        next.sourceIcon = prevIcon;
                        next.sourceIconGeneration = prevIconGeneration;
                        
                        if (!hasPrevIcon) {
                            next.sourceIcon = FindMediaSourceIcon(next.sourceAppUserModelId);
                            next.sourceIconGeneration = next.sourceIcon.generation;
                        }
                    } else {
                        next.sourceBadge = MediaSourceBadge(next.sourceName);
                        if (IsBrowserMediaSource(next.sourceAppUserModelId)) {
                            next.sourceBadge = FindBrowserMediaSiteBadge(next.sourceAppUserModelId);
                        }
                        next.sourceIcon = FindMediaSourceIcon(next.sourceAppUserModelId);
                        next.sourceIconGeneration = next.sourceIcon.generation;
                    }

                    if (next.title == prevTitle && next.artist == prevArtist && !prevArt.bgra.empty()) {
                        next.art = prevArt;
                        next.artGeneration = prevArtGeneration;
                        next.artChangedAt = prevArtChangedAt;
                    } else if (auto thumbnail = properties.Thumbnail()) {
                        std::vector<uint8_t> bytes = ReadWinRtStreamBytes(thumbnail);
                        if (!bytes.empty()) {
                            BitmapPixels decoded;
                            if (DecodeImageBytesToPixels(bytes, &decoded)) {
                                next.art = std::move(decoded);
                                next.artGeneration = next.art.generation;
                                next.artChangedAt = NowSeconds();
                            }
                        }
                    }
                }
            }
        } catch (...) {
            if (!loggedUnavailable) {
                Wh_Log(L"WinRT media session unavailable; media module will fall back to idle.");
                loggedUnavailable = true;
            }
        }

        {
            std::lock_guard lock(g_stateMutex);
            const bool wasDifferent =
                next.playing != g_state.media.playing ||
                next.title != g_state.media.title ||
                next.artist != g_state.media.artist;

            if (!g_state.media.art.bgra.empty() &&
                next.title == g_state.media.title && next.artist == g_state.media.artist &&
                next.positionTicks >= g_state.media.positionTicks) {
                next.art = g_state.media.art;
                next.artGeneration = g_state.media.artGeneration;
                next.artChangedAt = g_state.media.artChangedAt;
            }
            if (next.sourceIcon.bgra.empty() &&
                next.sourceAppUserModelId == g_state.media.sourceAppUserModelId) {
                next.sourceIcon = g_state.media.sourceIcon;
                next.sourceIconGeneration = g_state.media.sourceIconGeneration;
            }

            g_state.media = std::move(next);
            if (wasDifferent && g_state.media.available && g_settings.mediaAutoExpand) {
                TriggerNudge();
            }
        }

        WaitForSingleObject(g_stopEvent, 1500);
    }

    winrt::uninit_apartment();
    return 0;
}

#if DYNAMIC_ISLAND_HAS_USER_NOTIFICATION_LISTENER
DWORD WINAPI NotificationThreadProc(void*) {
    winrt::init_apartment(winrt::apartment_type::multi_threaded);

    using winrt::Windows::UI::Notifications::KnownNotificationBindings;
    using winrt::Windows::UI::Notifications::NotificationKinds;
    using winrt::Windows::UI::Notifications::Management::UserNotificationListener;
    using winrt::Windows::UI::Notifications::Management::UserNotificationListenerAccessStatus;

    std::set<uint32_t> seenIds;
    bool firstPoll = true;
    bool accessLogged = false;

    // The Windows Notification Service (WNS) and UWP subsystem take time to initialize on boot.
    // If explorer.exe is injected too early, instantiating UserNotificationListener::Current()
    // can permanently bind to an uninitialized COM proxy, permanently breaking notifications for the process.
    // To prevent this, we enforce a strict 30-second delay from process creation before touching the API.
    FILETIME creationTime, exitTime, kernelTime, userTime;
    if (GetProcessTimes(GetCurrentProcess(), &creationTime, &exitTime, &kernelTime, &userTime)) {
        ULARGE_INTEGER ct;
        ct.LowPart = creationTime.dwLowDateTime;
        ct.HighPart = creationTime.dwHighDateTime;
        
        FILETIME systemTime;
        GetSystemTimeAsFileTime(&systemTime);
        ULARGE_INTEGER st;
        st.LowPart = systemTime.dwLowDateTime;
        st.HighPart = systemTime.dwHighDateTime;
        
        uint64_t msSinceProcessStart = (st.QuadPart - ct.QuadPart) / 10000;
        if (msSinceProcessStart < 30000) {
            DWORD waitTime = 30000 - (DWORD)msSinceProcessStart;
            Wh_Log(L"Process started recently. Delaying UserNotificationListener init by %d ms to let UWP subsystem load...", waitTime);
            WaitForSingleObject(g_stopEvent, waitTime);
        }
    }

    while (WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
        try {
            auto listener = UserNotificationListener::Current();
            auto access = listener.RequestAccessAsync().get();
            if (access != UserNotificationListenerAccessStatus::Allowed) {
                if (!accessLogged) {
                    Wh_Log(L"Notification listener permission not granted or UWP subsystem not ready on boot (status: %d); retrying connection loop...", (int)access);
                    accessLogged = true;
                }
                WaitForSingleObject(g_stopEvent, 3000);
                continue;
            }

            if (accessLogged) {
                Wh_Log(L"WinRT UserNotificationListener successfully connected.");
                accessLogged = false;
            }

            while (WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
                try {
                    auto notifications = listener.GetNotificationsAsync(NotificationKinds::Toast).get();
                    std::set<uint32_t> currentIds;
                    
                    for (uint32_t i = 0; i < notifications.Size(); ++i) {
                        currentIds.insert(notifications.GetAt(i).Id());
                    }
                    
                    if (firstPoll) {
                        seenIds = std::move(currentIds);
                        firstPoll = false;
                        WaitForSingleObject(g_stopEvent, 1000);
                        continue;
                    }

                    for (uint32_t i = 0; i < notifications.Size(); ++i) {
                        try {
                            auto userNotification = notifications.GetAt(i);
                            const uint32_t id = userNotification.Id();
                            
                            if (seenIds.count(id)) {
                                continue;
                            }
                            
                            // Immediately mark as seen so we don't process it again
                            seenIds.insert(id);

                            NotificationSnapshot snapshot;
                            snapshot.active = true;
                            snapshot.expiresAt = NowSeconds() + 4.0;
                            auto appInfo = userNotification.AppInfo();
                            auto displayInfo = appInfo.DisplayInfo();
                            snapshot.app = displayInfo.DisplayName().c_str();
                            try {
                                auto logo = displayInfo.GetLogo({32.0f, 32.0f});
                                std::vector<uint8_t> logoBytes = ReadWinRtStreamBytes(logo);
                                if (!logoBytes.empty()) {
                                    DecodeImageBytesToPixels(logoBytes, &snapshot.icon);
                                }
                            } catch (...) {
                            }

                            if (snapshot.icon.bgra.empty() && !snapshot.app.empty()) {
                                snapshot.icon = FindAppIconByName(snapshot.app, 64);
                            }

                            auto notification = userNotification.Notification();
                            auto binding = notification.Visual().GetBinding(KnownNotificationBindings::ToastGeneric());
                            if (binding) {
                                auto textElements = binding.GetTextElements();
                                if (textElements.Size() > 0) {
                                    snapshot.title = textElements.GetAt(0).Text().c_str();
                                }
                                if (textElements.Size() > 1) {
                                    snapshot.body = textElements.GetAt(1).Text().c_str();
                                }
                            }

                            if (snapshot.title.empty()) {
                                snapshot.title = snapshot.app.empty() ? L"New notification" : snapshot.app;
                            }
                            if (!snapshot.body.empty()) {
                                snapshot.title += L" - " + snapshot.body;
                            }
                            if (snapshot.title.size() > 120) {
                                snapshot.title.resize(120);
                                snapshot.title += L"...";
                            }

                            {
                                std::lock_guard lock(g_stateMutex);
                                g_state.notification = std::move(snapshot);
                            }
                            TriggerNudge();
                        } catch (const winrt::hresult_error& nex) {
                            if (nex.to_abi() == 0x80004001 || nex.to_abi() == 0x80040154) { // E_NOTIMPL or REGDB_E_CLASSNOTREG
                                // UWP subsystem not ready, skip without spamming logs
                            } else {
                                Wh_Log(L"Failed to parse a notification (0x%08X); skipping.", nex.to_abi());
                            }
                        } catch (...) {
                            Wh_Log(L"Failed to parse a notification; skipping.");
                        }
                    }
                    
                    seenIds = std::move(currentIds);
                } catch (const winrt::hresult_error& ex) {
                    const HRESULT hr = ex.to_abi();
                    if (hr == 0x80004001 || hr == 0x80040154) { // E_NOTIMPL or REGDB_E_CLASSNOTREG
                        if (!accessLogged) {
                            Wh_Log(L"Notification listener UWP subsystem not fully ready (0x%08X). Retrying in background...", hr);
                            accessLogged = true;
                        }
                    } else {
                        Wh_Log(L"NotificationThreadProc inner loop WinRT error: %s (0x%08X); reconnecting...", ex.message().c_str(), hr);
                    }
                    WaitForSingleObject(g_stopEvent, 3000);
                    break;
                } catch (...) {
                    Wh_Log(L"NotificationThreadProc inner loop unknown exception; reconnecting...");
                    WaitForSingleObject(g_stopEvent, 3000);
                    break;
                }

                WaitForSingleObject(g_stopEvent, 1000);
            }
        } catch (const winrt::hresult_error& ex) {
            if (!accessLogged) {
                Wh_Log(L"NotificationThreadProc connection error: %s (0x%08X). Retrying in 3s...", ex.message().c_str(), ex.to_abi());
                accessLogged = true;
            }
            WaitForSingleObject(g_stopEvent, 3000);
        } catch (...) {
            if (!accessLogged) {
                Wh_Log(L"NotificationThreadProc unknown connection exception. Retrying in 3s...");
                accessLogged = true;
            }
            WaitForSingleObject(g_stopEvent, 3000);
        }
    }

    winrt::uninit_apartment();
    return 0;
}
#endif

float SampleAudioAmplitude(BYTE* data, UINT32 frames, WAVEFORMATEX* format) {
    if (!data || !frames || !format || !format->nChannels) {
        return 0.0f;
    }

    double sum = 0.0;
    size_t samples = static_cast<size_t>(frames) * format->nChannels;

    if (format->wFormatTag == WAVE_FORMAT_IEEE_FLOAT ||
        (format->wFormatTag == WAVE_FORMAT_EXTENSIBLE &&
         format->cbSize >= sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX) &&
         IsEqualGUID(reinterpret_cast<WAVEFORMATEXTENSIBLE*>(format)->SubFormat,
                     kSubTypeIeeeFloat))) {
        auto* f = reinterpret_cast<float*>(data);
        for (size_t i = 0; i < samples; ++i) {
            sum += f[i] * f[i];
        }
    } else if (format->wBitsPerSample == 16) {
        auto* s = reinterpret_cast<int16_t*>(data);
        for (size_t i = 0; i < samples; ++i) {
            const double v = s[i] / 32768.0;
            sum += v * v;
        }
    }

    const double rms = samples ? std::sqrt(sum / samples) : 0.0;
    return Clamp(static_cast<float>(rms * 4.0), 0.0f, 1.0f);
}

void PushWaveformSample(float amplitude) {
    std::lock_guard lock(g_stateMutex);
    
    float lastVal = 0.0f;
    if (g_state.waveformWrite > 0) {
        lastVal = g_state.waveform[(g_state.waveformWrite - 1) % g_state.waveform.size()];
    }

    // Apply an attack/release envelope (Exponential Moving Average)
    // Quick snappy attack (0.7) for beats, buttery smooth release (0.85) for decay.
    float smoothed;
    if (amplitude > lastVal) {
        smoothed = lastVal * 0.3f + amplitude * 0.7f;
    } else {
        smoothed = lastVal * 0.85f + amplitude * 0.15f;
    }

    g_state.waveform[g_state.waveformWrite % g_state.waveform.size()] = smoothed;
    ++g_state.waveformWrite;
}

void PushAudioChunks(BYTE* data, UINT32 frames, WAVEFORMATEX* format) {
    if (!data || !frames || !format || !format->nChannels) {
        PushWaveformSample(0.0f);
        return;
    }

    constexpr UINT32 chunkFrames = 64;
    const UINT32 channels = format->nChannels;
    const bool isFloat =
        format->wFormatTag == WAVE_FORMAT_IEEE_FLOAT ||
        (format->wFormatTag == WAVE_FORMAT_EXTENSIBLE &&
         format->cbSize >= sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX) &&
         IsEqualGUID(reinterpret_cast<WAVEFORMATEXTENSIBLE*>(format)->SubFormat,
                     kSubTypeIeeeFloat));
    const bool is16 = format->wBitsPerSample == 16;

    if (!isFloat && !is16) {
        PushWaveformSample(SampleAudioAmplitude(data, frames, format));
        return;
    }

    for (UINT32 frame = 0; frame < frames; frame += chunkFrames) {
        const UINT32 chunk = std::min(chunkFrames, frames - frame);
        double sum = 0.0;
        const size_t samples = static_cast<size_t>(chunk) * channels;
        const size_t start = static_cast<size_t>(frame) * channels;

        if (isFloat) {
            auto* f = reinterpret_cast<float*>(data);
            for (size_t i = 0; i < samples; ++i) {
                const double v = f[start + i];
                sum += v * v;
            }
        } else {
            auto* s = reinterpret_cast<int16_t*>(data);
            for (size_t i = 0; i < samples; ++i) {
                const double v = s[start + i] / 32768.0;
                sum += v * v;
            }
        }

        PushWaveformSample(Clamp(static_cast<float>(std::sqrt(sum / samples) * 4.0), 0.0f, 1.0f));
    }
}

// --- Weather Fetching Helpers ---
std::string HttpGet(const wchar_t* host, const wchar_t* path, bool https = true) {
    std::string response;
    HINTERNET hSession = WinHttpOpen(L"DynamicIsland/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) {
        Wh_Log(L"Weather HttpGet: WinHttpOpen failed with error %lu", GetLastError());
        return response;
    }

    HINTERNET hConnect = WinHttpConnect(hSession, host, https ? INTERNET_DEFAULT_HTTPS_PORT : INTERNET_DEFAULT_HTTP_PORT, 0);
    if (hConnect) {
        HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", path, nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, https ? WINHTTP_FLAG_SECURE : 0);
        if (hRequest) {
            if (WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0) &&
                WinHttpReceiveResponse(hRequest, nullptr)) {
                DWORD size = 0;
                DWORD downloaded = 0;
                do {
                    if (WinHttpQueryDataAvailable(hRequest, &size) && size > 0) {
                        std::vector<char> buffer(size + 1);
                        if (WinHttpReadData(hRequest, buffer.data(), size, &downloaded)) {
                            buffer[downloaded] = '\0';
                            response.append(buffer.data());
                        } else {
                            Wh_Log(L"Weather HttpGet: WinHttpReadData failed with error %lu", GetLastError());
                        }
                    }
                } while (size > 0);
            } else {
                Wh_Log(L"Weather HttpGet: WinHttpSendRequest/ReceiveResponse failed with error %lu", GetLastError());
            }
            WinHttpCloseHandle(hRequest);
        } else {
            Wh_Log(L"Weather HttpGet: WinHttpOpenRequest failed with error %lu", GetLastError());
        }
        WinHttpCloseHandle(hConnect);
    } else {
        Wh_Log(L"Weather HttpGet: WinHttpConnect failed with error %lu", GetLastError());
    }
    WinHttpCloseHandle(hSession);
    return response;
}

DWORD WINAPI WeatherThreadProc(void*) {
    // Initial delay to avoid slowing down startup
    WaitForSingleObject(g_stopEvent, 3000);

    while (WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
        std::wstring cityOverride;
        bool isFahrenheit = false;
        bool weatherEnabled = true;
        {
            std::lock_guard lock(g_stateMutex);
            weatherEnabled = g_settings.weather;
            cityOverride = g_settings.weatherCity;
            isFahrenheit = g_settings.weatherFahrenheit;
        }

        if (!weatherEnabled) {
            WaitForSingleObject(g_stopEvent, 2000);
            continue;
        }

        std::wstring url = L"/?format=j1";
        if (!cityOverride.empty()) {
            std::wstring urlName = cityOverride;
            size_t pos = 0;
            while ((pos = urlName.find(L" ", pos)) != std::wstring::npos) {
                urlName.replace(pos, 1, L"%20");
                pos += 3;
            }
            url = L"/" + urlName + L"?format=j1";
        }

        Wh_Log(L"Weather: Requesting weather from wttr.in/host: wttr.in, path: %s", url.c_str());
        std::string wRes = HttpGet(L"wttr.in", url.c_str(), true);
        if (wRes.empty()) {
            Wh_Log(L"Weather: HTTPS request failed, retrying over plain HTTP...");
            wRes = HttpGet(L"wttr.in", url.c_str(), false);
        }
        
        if (!wRes.empty()) {
            Wh_Log(L"Weather: Received response from wttr.in (size: %zu bytes)", wRes.size());
            float temp = 0.0f;
            int code = 0;
            std::wstring desc = L"";
            std::wstring windSpeed = L"";
            std::wstring windDir = L"";
            std::wstring humidity = L"";
            std::wstring feelsLike = L"";
            std::wstring cityLabel = L"Local Weather";
            
            const char* areaStr = strstr(wRes.c_str(), "\"areaName\":");
            if (areaStr) {
                const char* valStr = strstr(areaStr, "\"value\":");
                if (valStr) {
                    valStr += 8;
                    while (*valStr == ' ' || *valStr == '\"') valStr++;
                    const char* end = strchr(valStr, '\"');
                    if (end) {
                        std::string cityA(valStr, end - valStr);
                        int wchars_num = MultiByteToWideChar(CP_UTF8, 0, cityA.c_str(), -1, NULL, 0);
                        if (wchars_num > 0) {
                            std::vector<wchar_t> wstr(wchars_num);
                            MultiByteToWideChar(CP_UTF8, 0, cityA.c_str(), -1, &wstr[0], wchars_num);
                            cityLabel = wstr.data();
                        }
                    }
                }
            }
            
            const char* currentStr = strstr(wRes.c_str(), "\"current_condition\":");
            if (currentStr) {
                auto ParseStringField = [&](const char* key, std::wstring& out) {
                    const char* kStr = strstr(currentStr, key);
                    if (kStr) {
                        kStr += strlen(key);
                        while (*kStr == ' ' || *kStr == '\"' || *kStr == ':') kStr++;
                        const char* end = strchr(kStr, '\"');
                        if (end) {
                            std::string valA(kStr, end - kStr);
                            int wchars_num = MultiByteToWideChar(CP_UTF8, 0, valA.c_str(), -1, NULL, 0);
                            if (wchars_num > 0) {
                                std::vector<wchar_t> wstr(wchars_num);
                                MultiByteToWideChar(CP_UTF8, 0, valA.c_str(), -1, &wstr[0], wchars_num);
                                out = wstr.data();
                            }
                        }
                    }
                };

                const char* tempStr = strstr(currentStr, isFahrenheit ? "\"temp_F\":" : "\"temp_C\":");
                if (tempStr) {
                    tempStr += 9;
                    while (*tempStr == ' ' || *tempStr == '\"') tempStr++;
                    sscanf(tempStr, "%f", &temp);
                }
                const char* codeStr = strstr(currentStr, "\"weatherCode\":");
                if (codeStr) {
                    codeStr += 14;
                    while (*codeStr == ' ' || *codeStr == '\"') codeStr++;
                    sscanf(codeStr, "%d", &code);
                }
                
                const char* descStr = strstr(currentStr, "\"weatherDesc\":");
                if (descStr) {
                    const char* valStr = strstr(descStr, "\"value\":");
                    if (valStr) {
                        valStr += 8;
                        while (*valStr == ' ' || *valStr == '\"') valStr++;
                        const char* end = strchr(valStr, '\"');
                        if (end) {
                            std::string valA(valStr, end - valStr);
                            int wchars_num = MultiByteToWideChar(CP_UTF8, 0, valA.c_str(), -1, NULL, 0);
                            if (wchars_num > 0) {
                                std::vector<wchar_t> wstr(wchars_num);
                                MultiByteToWideChar(CP_UTF8, 0, valA.c_str(), -1, &wstr[0], wchars_num);
                                desc = wstr.data();
                                while(!desc.empty() && desc.back() == L' ') desc.pop_back();
                            }
                        }
                    }
                }
                
                ParseStringField(isFahrenheit ? "\"windspeedMiles\"" : "\"windspeedKmph\"", windSpeed);
                ParseStringField("\"winddir16Point\"", windDir);
                ParseStringField("\"humidity\"", humidity);
                ParseStringField(isFahrenheit ? "\"FeelsLikeF\"" : "\"FeelsLikeC\"", feelsLike);

                std::wstring finalCity = cityOverride.empty() ? cityLabel : cityOverride;
                Wh_Log(L"Weather parsed success: city=%s, temp=%.1f, feelsLike=%s, humidity=%s%%, desc=%s",
                       finalCity.c_str(), temp, feelsLike.c_str(), humidity.c_str(), desc.c_str());
            } else {
                Wh_Log(L"Weather: Failed to find \"current_condition\" in response.");
            }
            
            {
                std::lock_guard lock(g_stateMutex);
                g_state.weather.hasData = true;
                g_state.weather.temperature = temp;
                g_state.weather.weatherCode = code;
                if (!cityOverride.empty()) g_state.weather.city = cityOverride;
                else g_state.weather.city = cityLabel;
                g_state.weather.weatherDesc = desc;
                g_state.weather.windSpeed = windSpeed;
                g_state.weather.windDir = windDir;
                g_state.weather.humidity = humidity;
                g_state.weather.feelsLike = feelsLike;
                g_state.weather.lastUpdated = NowSeconds();
            }
        } else {
            Wh_Log(L"Weather: HttpGet returned empty response.");
        }

        HANDLE events[] = {g_stopEvent, g_settingsChangedEvent};
        DWORD waitResult = WaitForMultipleObjects(2, events, FALSE, 15 * 60 * 1000);
        if (waitResult == WAIT_OBJECT_0) {
            break;
        }
    }
    return 0;
}

DWORD WINAPI AudioThreadProc(void*) {
    HRESULT hrCo = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    while (WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
        ComPtr<IMMDeviceEnumerator> enumerator;
        ComPtr<IMMDevice> device;
        ComPtr<IAudioClient> client;
        ComPtr<IAudioCaptureClient> capture;
        WAVEFORMATEX* mixFormat = nullptr;

        HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr,
                                      CLSCTX_ALL, IID_PPV_ARGS(&enumerator));
        if (SUCCEEDED(hr)) {
            hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
        }
        if (SUCCEEDED(hr)) {
            hr = device->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr,
                                  reinterpret_cast<void**>(client.GetAddressOf()));
        }
        if (SUCCEEDED(hr)) {
            hr = client->GetMixFormat(&mixFormat);
        }
        if (SUCCEEDED(hr)) {
            REFERENCE_TIME bufferDuration = 10000000 / 5;
            hr = client->Initialize(AUDCLNT_SHAREMODE_SHARED,
                                    AUDCLNT_STREAMFLAGS_LOOPBACK,
                                    bufferDuration, 0, mixFormat, nullptr);
        }
        if (SUCCEEDED(hr)) {
            hr = client->GetService(IID_PPV_ARGS(&capture));
        }
        if (SUCCEEDED(hr)) {
            hr = client->Start();
        }

        if (FAILED(hr)) {
            if (mixFormat) {
                CoTaskMemFree(mixFormat);
            }
            WaitForSingleObject(g_stopEvent, 2500);
            continue;
        }

        while (WaitForSingleObject(g_stopEvent, 16) == WAIT_TIMEOUT) {
            UINT32 packetFrames = 0;
            if (FAILED(capture->GetNextPacketSize(&packetFrames))) {
                break;
            }

            float amplitude = 0.0f;
            int packets = 0;
            while (packetFrames > 0) {
                BYTE* data = nullptr;
                UINT32 frames = 0;
                DWORD flags = 0;
                if (FAILED(capture->GetBuffer(&data, &frames, &flags, nullptr, nullptr))) {
                    break;
                }

                if (!(flags & AUDCLNT_BUFFERFLAGS_SILENT)) {
                    amplitude = std::max(amplitude, SampleAudioAmplitude(data, frames, mixFormat));
                    PushAudioChunks(data, frames, mixFormat);
                } else {
                    PushWaveformSample(0.0f);
                }
                capture->ReleaseBuffer(frames);
                ++packets;

                if (FAILED(capture->GetNextPacketSize(&packetFrames))) {
                    packetFrames = 0;
                }
            }

            if (packets > 0) {
                if (amplitude <= 0.001f) {
                    PushWaveformSample(0.0f);
                }
            } else {
                PushWaveformSample(0.0f);
            }
        }

        client->Stop();
        if (mixFormat) {
            CoTaskMemFree(mixFormat);
        }
    }

    if (SUCCEEDED(hrCo)) {
        CoUninitialize();
    }

    return 0;
}

void UpdateBatterySnapshot() {
    SYSTEM_POWER_STATUS status = {};
    if (!GetSystemPowerStatus(&status)) {
        return;
    }

    bool newCharging = (status.ACLineStatus == 1);
    int newPercent = status.BatteryLifePercent == 255 ? 100 : status.BatteryLifePercent;

    bool triggerAlert = false;

    {
        std::lock_guard lock(g_stateMutex);
        static bool s_batteryInit = false;
        if (!s_batteryInit) {
            g_state.battery.charging = newCharging;
            g_state.battery.percent = newPercent;
            s_batteryInit = true;
        }

        if (g_state.battery.charging != newCharging) {
            triggerAlert = true;
        }

        if (!newCharging && newPercent < g_state.battery.percent && (newPercent == 20 || newPercent == 10)) {
            triggerAlert = true;
        }

        g_state.battery.charging = newCharging;
        g_state.battery.percent = newPercent;
        g_state.battery.secondsRemaining = status.BatteryLifeTime;
        g_state.battery.low = (!newCharging && newPercent <= 20);

        if (triggerAlert) {
            g_state.battery.active = true;
            g_state.battery.expiresAt = NowSeconds() + 4.0;
        }
    }

    if (triggerAlert) {
        TriggerNudge();
    }
}

ULONGLONG FileTimeToUInt64(FILETIME ft) {
    ULARGE_INTEGER value = {};
    value.LowPart = ft.dwLowDateTime;
    value.HighPart = ft.dwHighDateTime;
    return value.QuadPart;
}

static PDH_HQUERY g_gpuQuery = NULL;
static PDH_HCOUNTER g_gpuCounter = NULL;

static void InitGpuQuery() {
    if (g_gpuQuery == NULL) {
        if (PdhOpenQueryW(NULL, 0, &g_gpuQuery) == ERROR_SUCCESS) {
            PdhAddEnglishCounterW(g_gpuQuery, L"\\GPU Engine(*)\\Utilization Percentage", 0, &g_gpuCounter);
            PdhCollectQueryData(g_gpuQuery);
        }
    }
}

static int GetGpuUsage() {
    InitGpuQuery();
    if (!g_gpuQuery || !g_gpuCounter) return 0;
    
    PdhCollectQueryData(g_gpuQuery);
    
    DWORD bufferSize = 0;
    DWORD itemCount = 0;
    PdhGetFormattedCounterArrayW(g_gpuCounter, PDH_FMT_DOUBLE, &bufferSize, &itemCount, NULL);
    
    if (bufferSize > 0) {
        std::vector<BYTE> buffer(bufferSize);
        PDH_FMT_COUNTERVALUE_ITEM_W* items = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(buffer.data());
        
        if (PdhGetFormattedCounterArrayW(g_gpuCounter, PDH_FMT_DOUBLE, &bufferSize, &itemCount, items) == ERROR_SUCCESS) {
            double total = 0;
            for (DWORD i = 0; i < itemCount; i++) {
                if (items[i].szName && wcsstr(items[i].szName, L"engtype_3D")) {
                    total += items[i].FmtValue.doubleValue;
                }
            }
            return ClampInt(static_cast<int>(total), 0, 100);
        }
    }
    return 0;
}

static PDH_HQUERY g_netQuery = NULL;
static PDH_HCOUNTER g_netUpCounter = NULL;
static PDH_HCOUNTER g_netDownCounter = NULL;

static void InitNetQuery() {
    if (g_netQuery == NULL) {
        if (PdhOpenQueryW(NULL, 0, &g_netQuery) == ERROR_SUCCESS) {
            PdhAddEnglishCounterW(g_netQuery, L"\\Network Interface(*)\\Bytes Sent/sec", 0, &g_netUpCounter);
            PdhAddEnglishCounterW(g_netQuery, L"\\Network Interface(*)\\Bytes Received/sec", 0, &g_netDownCounter);
            PdhCollectQueryData(g_netQuery);
        }
    }
}

static void GetNetworkUsage(float& outUpMbps, float& outDownMbps) {
    outUpMbps = 0.0f;
    outDownMbps = 0.0f;
    InitNetQuery();
    if (!g_netQuery || !g_netUpCounter || !g_netDownCounter) return;

    PdhCollectQueryData(g_netQuery);

    auto getSum = [](PDH_HCOUNTER counter) -> double {
        DWORD bufferSize = 0;
        DWORD itemCount = 0;
        PdhGetFormattedCounterArrayW(counter, PDH_FMT_DOUBLE, &bufferSize, &itemCount, NULL);
        if (bufferSize > 0) {
            std::vector<BYTE> buffer(bufferSize);
            PDH_FMT_COUNTERVALUE_ITEM_W* items = reinterpret_cast<PDH_FMT_COUNTERVALUE_ITEM_W*>(buffer.data());
            if (PdhGetFormattedCounterArrayW(counter, PDH_FMT_DOUBLE, &bufferSize, &itemCount, items) == ERROR_SUCCESS) {
                double total = 0;
                for (DWORD i = 0; i < itemCount; i++) {
                    if (items[i].szName) {
                        if (wcsstr(items[i].szName, L"Loopback") == nullptr) {
                            total += items[i].FmtValue.doubleValue;
                        }
                    }
                }
                return total;
            }
        }
        return 0.0;
    };

    // Bytes to Mbps
    outUpMbps = static_cast<float>(getSum(g_netUpCounter) * 8.0 / 1000000.0);
    outDownMbps = static_cast<float>(getSum(g_netDownCounter) * 8.0 / 1000000.0);
}

void UpdateSystemSnapshot() {
    SystemSnapshot next;
    {
        std::lock_guard lock(g_stateMutex);
        next = g_state.system;
        next.charging = g_state.system.charging;
    }

    next.gpuPercent = GetGpuUsage();
    GetNetworkUsage(next.netUpMbps, next.netDownMbps);

    MEMORYSTATUSEX memory = {};
    memory.dwLength = sizeof(memory);
    if (GlobalMemoryStatusEx(&memory)) {
        next.memoryPercent = static_cast<int>(memory.dwMemoryLoad);
        next.memoryTotalGB = static_cast<float>(memory.ullTotalPhys) / (1024.0f * 1024.0f * 1024.0f);
        next.memoryUsedGB = next.memoryTotalGB - static_cast<float>(memory.ullAvailPhys) / (1024.0f * 1024.0f * 1024.0f);
    }

    ULARGE_INTEGER freeBytesAvailable = {};
    ULARGE_INTEGER totalBytes = {};
    ULARGE_INTEGER totalFreeBytes = {};
    if (GetDiskFreeSpaceExW(L"C:\\", &freeBytesAvailable, &totalBytes, &totalFreeBytes) &&
        totalBytes.QuadPart > 0) {
        next.diskFreePercent = ClampInt(
            static_cast<int>(totalFreeBytes.QuadPart * 100 / totalBytes.QuadPart), 0, 100);
    }

    HWND foreground = GetForegroundWindow();
    if (foreground && foreground != g_hwnd) {
        wchar_t title[96] = {};
        GetWindowTextW(foreground, title, ARRAYSIZE(title));
        if (!IsIgnorableForegroundWindow(foreground, title)) {
            next.foregroundTitle = title;
            if (next.foregroundTitle.size() > 42) {
                next.foregroundTitle.resize(42);
                next.foregroundTitle += L"...";
            }

        } else {
            next.foregroundTitle.clear();
        }
    }

    FILETIME idle = {};
    FILETIME kernel = {};
    FILETIME user = {};
    if (GetSystemTimes(&idle, &kernel, &user)) {
        const ULONGLONG idleNow = FileTimeToUInt64(idle);
        const ULONGLONG kernelNow = FileTimeToUInt64(kernel);
        const ULONGLONG userNow = FileTimeToUInt64(user);
        const ULONGLONG idlePrev = FileTimeToUInt64(g_prevIdleTime);
        const ULONGLONG kernelPrev = FileTimeToUInt64(g_prevKernelTime);
        const ULONGLONG userPrev = FileTimeToUInt64(g_prevUserTime);

        const ULONGLONG total = (kernelNow - kernelPrev) + (userNow - userPrev);
        const ULONGLONG idleDelta = idleNow - idlePrev;
        if (total > 0 && kernelPrev != 0) {
            next.cpuPercent = ClampInt(static_cast<int>((total - idleDelta) * 100 / total), 0, 100);
        }

        g_prevIdleTime = idle;
        g_prevKernelTime = kernel;
        g_prevUserTime = user;
    }

    static ComPtr<IAudioEndpointVolume> s_volume;
    if (!s_volume) {
        ComPtr<IMMDeviceEnumerator> enumerator;
        ComPtr<IMMDevice> device;
        HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, IID_PPV_ARGS(&enumerator));
        if (SUCCEEDED(hr)) {
            hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
        }
        if (SUCCEEDED(hr)) {
            hr = device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr, reinterpret_cast<void**>(s_volume.GetAddressOf()));
        }
    }

    if (s_volume) {
        float level = 0.0f;
        BOOL muted = FALSE;
        if (SUCCEEDED(s_volume->GetMasterVolumeLevelScalar(&level)) && SUCCEEDED(s_volume->GetMute(&muted))) {
            next.volumePercent = ClampInt(static_cast<int>(level * 100.0f + 0.5f), 0, 100);
            next.volumeMuted = muted != FALSE;
        } else {
            s_volume.Reset(); // Retry next time
        }
    }

    std::lock_guard lock(g_stateMutex);
    const bool volumeChanged =
        g_volumeInitialized &&
        (std::abs(next.volumePercent - g_state.system.volumePercent) >= 2 ||
         next.volumeMuted != g_state.system.volumeMuted);
    g_state.system = next;
    g_state.muted = next.volumeMuted;
    if (volumeChanged) {
        g_state.volume.active = true;
        g_state.volume.percent = next.volumePercent;
        g_state.volume.muted = next.volumeMuted;
        g_state.volume.deviceName = L"System audio";
        g_state.volume.expiresAt = NowSeconds() + 1.8;
        TriggerNudge();
    }
    g_volumeInitialized = true;
}

// ---- Privacy indicator helpers ----
bool IsDeviceActiveViaRegistry(const wchar_t* capability) {
    bool isActive = false;
    std::wstring basePath = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\CapabilityAccessManager\\ConsentStore\\";
    basePath += capability;

    auto CheckSubkeys = [](HKEY hKeyParent) -> bool {
        DWORD index = 0;
        wchar_t subKeyName[256];
        DWORD nameLen = ARRAYSIZE(subKeyName);
        while (RegEnumKeyExW(hKeyParent, index, subKeyName, &nameLen, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
            HKEY hSub;
            if (RegOpenKeyExW(hKeyParent, subKeyName, 0, KEY_READ, &hSub) == ERROR_SUCCESS) {
                if (_wcsicmp(subKeyName, L"NonPackaged") == 0) {
                    DWORD npIndex = 0;
                    wchar_t npSubKeyName[256];
                    DWORD npNameLen = ARRAYSIZE(npSubKeyName);
                    while (RegEnumKeyExW(hSub, npIndex, npSubKeyName, &npNameLen, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
                        HKEY hNpSub;
                        if (RegOpenKeyExW(hSub, npSubKeyName, 0, KEY_READ, &hNpSub) == ERROR_SUCCESS) {
                            uint64_t stopTime = 1;
                            DWORD dataSize = sizeof(stopTime);
                            if (RegQueryValueExW(hNpSub, L"LastUsedTimeStop", nullptr, nullptr, reinterpret_cast<LPBYTE>(&stopTime), &dataSize) == ERROR_SUCCESS) {
                                if (stopTime == 0) {
                                    RegCloseKey(hNpSub);
                                    RegCloseKey(hSub);
                                    return true;
                                }
                            }
                            RegCloseKey(hNpSub);
                        }
                        npIndex++;
                        npNameLen = ARRAYSIZE(npSubKeyName);
                    }
                } else {
                    uint64_t stopTime = 1;
                    DWORD dataSize = sizeof(stopTime);
                    if (RegQueryValueExW(hSub, L"LastUsedTimeStop", nullptr, nullptr, reinterpret_cast<LPBYTE>(&stopTime), &dataSize) == ERROR_SUCCESS) {
                        if (stopTime == 0) {
                            RegCloseKey(hSub);
                            return true;
                        }
                    }
                }
                RegCloseKey(hSub);
            }
            index++;
            nameLen = ARRAYSIZE(subKeyName);
        }
        return false;
    };

    HKEY hKey;
    if (RegOpenKeyExW(HKEY_CURRENT_USER, basePath.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        isActive = CheckSubkeys(hKey);
        RegCloseKey(hKey);
    }
    
    if (!isActive) {
        if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, basePath.c_str(), 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
            isActive = CheckSubkeys(hKey);
            RegCloseKey(hKey);
        }
    }
    
    return isActive;
}

bool IsMicrophoneActive() {
    return IsDeviceActiveViaRegistry(L"microphone");
}

bool IsCameraActive() {
    return IsDeviceActiveViaRegistry(L"webcam");
}

void UpdateProgressSnapshot() {
    const int progress = Wh_GetIntValue(L"ProgressPercent", -1);
    std::lock_guard lock(g_stateMutex);
    g_state.progress.active = progress >= 0 && progress <= 100;
    g_state.progress.percent = ClampInt(progress, 0, 100);
}

void UpdatePrivacyIndicators() {
    const bool mic = (g_settings.privacyDots && g_settings.privacyDotsMic) ? IsMicrophoneActive() : false;
    const bool cam = (g_settings.privacyDots && g_settings.privacyDotsCam) ? IsCameraActive() : false;
    std::lock_guard lock(g_stateMutex);
    g_state.system.micActive = mic;
    g_state.system.cameraActive = cam;
}

std::wstring ReadClipboardText(HWND hwnd) {
    std::wstring text;
    if (!OpenClipboard(hwnd)) {
        return text;
    }

    HANDLE data = GetClipboardData(CF_UNICODETEXT);
    if (data) {
        auto* locked = static_cast<const wchar_t*>(GlobalLock(data));
        if (locked) {
            text = locked;
            GlobalUnlock(data);
        }
    }

    CloseClipboard();
    return text;
}

bool ClipboardHasBitmap(HWND hwnd) {
    bool result = false;
    if (OpenClipboard(hwnd)) {
        result = IsClipboardFormatAvailable(CF_BITMAP) ||
                 IsClipboardFormatAvailable(CF_DIB) ||
                 IsClipboardFormatAvailable(CF_DIBV5);
        CloseClipboard();
    }
    return result;
}

bool IsLikelyToastWindow(HWND hwnd, const wchar_t* className, const wchar_t* title) {
    if (hwnd == g_hwnd || !hwnd) {
        return false;
    }

    if (GetWindow(hwnd, GW_OWNER)) {
        return false;
    }

    const std::wstring cls = ToLowerCopy(className ? className : L"");
    const std::wstring text = ToLowerCopy(title ? title : L"");

    // Classic Windows 10 toasts have clear class names
    if (cls.find(L"notification") != std::wstring::npos ||
        cls.find(L"toast") != std::wstring::npos ||
        cls.find(L"windows.ui.notifications") != std::wstring::npos) {
        return true;
    }

    // Windows 11 toasts use generic XAML or CoreWindow classes, usually hosted by
    // explorer.exe, sihost.exe, or ShellExperienceHost.exe.
    // Importantly, their title is often empty at the exact moment of creation!
    if (cls.find(L"xaml_windowedpopupclass") != std::wstring::npos ||
        cls.find(L"windows.ui.core.corewindow") != std::wstring::npos) {
        
        std::wstring image;
        if (ProcessImageNameForWindow(hwnd, &image)) {
            const std::wstring base = ToLowerCopy(BaseNameFromPath(image));
            if (base == L"explorer.exe" || base == L"sihost.exe" || base == L"shellexperiencehost.exe") {
                // Ensure it's not the start menu, search, or action center main panel
                if (text != L"start" && text != L"action center" && text != L"search" && text != L"task view") {
                    return true;
                }
            }
        }
    }

    return false;
}

void CaptureShellNotification(HWND hwnd) {
    // Grace period: ignore notifications that fire in the first 3 seconds after
    // the mod starts. sihost.exe gets injected while system windows are still
    // settling, which causes false positives (e.g. Snipping Tool windows).
    if (NowSeconds() < 3.0) {
        return;
    }

    wchar_t className[128] = {};
    wchar_t title[192] = {};
    GetClassNameW(hwnd, className, ARRAYSIZE(className));
    GetWindowTextW(hwnd, title, ARRAYSIZE(title));

    if (!IsLikelyToastWindow(hwnd, className, title)) {
        return;
    }

    NotificationSnapshot notification;
    notification.active = true;
    notification.app = L"Notification";
    notification.title = title;
    notification.expiresAt = NowSeconds() + 4.0;
    // Fetch a 64px icon to ensure crisp rendering inside the pill
    notification.icon = GetWindowIconPixels(hwnd, 64);

    if (notification.title.size() > 96) {
        notification.body = notification.title.substr(64);
        notification.title.resize(64);
        notification.title += L"...";
    }

    {
        std::lock_guard lock(g_stateMutex);
        g_state.notification = std::move(notification);
    }
    TriggerNudge();

    // Spawn a background thread to extract the full rich text body of the toast using UI Automation.
    // Modern Windows Toasts often only provide the App Name via GetWindowTextW, leaving the body hidden in the XAML tree.
    std::thread([hwnd]() {
        Sleep(400); // Give the heavy UWP XAML tree enough time to fully construct the text nodes
        HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
        if (SUCCEEDED(hr)) {
            IUIAutomation* uia = nullptr;
            hr = CoCreateInstance(__uuidof(CUIAutomation), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IUIAutomation), (void**)&uia);
            if (SUCCEEDED(hr) && uia) {
                IUIAutomation2* uia2 = nullptr;
                if (SUCCEEDED(uia->QueryInterface(__uuidof(IUIAutomation2), (void**)&uia2)) && uia2) {
                    uia2->put_TransactionTimeout(500);
                    uia2->put_ConnectionTimeout(500);
                    uia2->Release();
                }
                IUIAutomationElement* windowEl = nullptr;
                if (SUCCEEDED(uia->ElementFromHandle(hwnd, &windowEl)) && windowEl) {
                    IUIAutomationCondition* cond = nullptr;
                    uia->CreateTrueCondition(&cond);
                    IUIAutomationElementArray* elements = nullptr;
                    if (SUCCEEDED(windowEl->FindAll(TreeScope_Descendants, cond, &elements)) && elements) {
                        int count = 0;
                        elements->get_Length(&count);
                        std::wstring appName;
                        std::wstring fullText;
                        for (int i = 0; i < count; ++i) {
                            IUIAutomationElement* el = nullptr;
                            if (SUCCEEDED(elements->GetElement(i, &el)) && el) {
                                BSTR name = nullptr;
                                el->get_CurrentName(&name);
                                if (name && wcslen(name) > 0) {
                                    std::wstring chunk = name;
                                    // Skip generic screen-reader labels often found in toasts
                                    if (chunk != L"Notification" && chunk != L"New notification") {
                                        if (appName.empty()) {
                                            appName = chunk;
                                        } else {
                                            if (!fullText.empty()) fullText += L"  -  ";
                                            fullText += chunk;
                                        }
                                    }
                                }
                                if (name) SysFreeString(name);
                                el->Release();
                            }
                        }
                        elements->Release();
                        
                        if (fullText.empty() && !appName.empty()) {
                            fullText = appName;
                            appName = L"Notification";
                        }
                        
                        if (!fullText.empty()) {
                            std::lock_guard lock(g_stateMutex);
                            if (g_state.notification.active) {
                                if (!appName.empty()) {
                                    g_state.notification.app = appName;
                                    if (appName != L"Notification") {
                                        BitmapPixels resolvedIcon = FindAppIconByName(appName, 64);
                                        if (!resolvedIcon.bgra.empty()) {
                                            g_state.notification.icon = std::move(resolvedIcon);
                                        }
                                    }
                                }
                                g_state.notification.title = fullText;
                            }
                        }
                    }
                    if (cond) cond->Release();
                    windowEl->Release();
                }
                uia->Release();
            }
            CoUninitialize();
        }
    }).detach();
}

void CaptureClipboard(HWND hwnd) {
    ClipboardSnapshot clip;
    clip.expiresAt = NowSeconds() + 2.5;
    HWND owner = GetClipboardOwner();
    if (!owner) {
        owner = GetForegroundWindow();
    }
    wchar_t ownerTitle[80] = {};
    if (owner) {
        GetWindowTextW(owner, ownerTitle, ARRAYSIZE(ownerTitle));
    }
    if (owner && !IsIgnorableForegroundWindow(owner, ownerTitle)) {
        DWORD pid = 0;
        GetWindowThreadProcessId(owner, &pid);
        // Fetch at 64px for crisp rendering — 18px/32px is often too small for icon APIs and returns empty.
        clip.appIcon = GetWindowIconPixels(owner, 64);

        clip.appName = ownerTitle;
        if (clip.appName.empty()) {
            std::wstring path;
            if (ProcessImageNameForPid(pid, &path)) {
                clip.appName = StripExtension(BaseNameFromPath(path));
            }
        }
        if (clip.appName.size() > 24) {
            clip.appName.resize(24);
            clip.appName += L"...";
        }
    }

    std::wstring text = ReadClipboardText(hwnd);
    if (!text.empty()) {
        constexpr size_t maxChars = 96;
        std::replace(text.begin(), text.end(), L'\r', L' ');
        std::replace(text.begin(), text.end(), L'\n', L' ');
        if (text.size() > maxChars) {
            text.resize(maxChars);
            text += L"...";
        }
        clip.text = text;
        clip.image = false;
        clip.active = true;
    } else if (ClipboardHasBitmap(hwnd)) {
        clip.text = L"Image copied";
        clip.image = true;
        clip.active = true;
    }

    if (clip.active) {
        {
            std::lock_guard lock(g_stateMutex);
            g_state.clipboard = std::move(clip);
        }
    }
}

void SetClickThrough(HWND hwnd, bool clickThrough) {
    LONG_PTR exStyle = GetWindowLongPtrW(hwnd, GWL_EXSTYLE);
    const bool has = (exStyle & WS_EX_TRANSPARENT) != 0;
    if (clickThrough == has) {
        return;
    }

    if (clickThrough) {
        exStyle |= WS_EX_TRANSPARENT;
    } else {
        exStyle &= ~WS_EX_TRANSPARENT;
    }

    SetWindowLongPtrW(hwnd, GWL_EXSTYLE, exStyle);
}

void OpenRelevantApp();


void ToggleEndpointMute();

void HandleStatusClickAtPoint(HWND hwnd, LPARAM lParam) {
    // Disabled click handlers for status chips as requested by the user
    return;
}

void ToggleEndpointMute() {
    ComPtr<IMMDeviceEnumerator> enumerator;
    ComPtr<IMMDevice> device;
    ComPtr<IAudioEndpointVolume> volume;

    HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr,
                                  CLSCTX_ALL, IID_PPV_ARGS(&enumerator));
    if (SUCCEEDED(hr)) {
        hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
    }
    if (SUCCEEDED(hr)) {
        hr = device->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr,
                              reinterpret_cast<void**>(volume.GetAddressOf()));
    }
    if (SUCCEEDED(hr)) {
        BOOL muted = FALSE;
        volume->GetMute(&muted);
        volume->SetMute(!muted, nullptr);
        std::lock_guard lock(g_stateMutex);
        g_state.muted = !muted;
    }
}

struct WindowSearch {
    std::wstring targetTitle;
    std::wstring targetApp;
    HWND foundHwnd = nullptr;
    HWND fallbackHwnd = nullptr;
};

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    if (!IsWindowVisible(hwnd)) {
        return TRUE;
    }

    auto* search = reinterpret_cast<WindowSearch*>(lParam);

    wchar_t title[512];
    if (GetWindowTextW(hwnd, title, ARRAYSIZE(title)) > 0) {
        std::wstring wTitle(title);
        // Case-insensitive check if window title contains currently playing media title
        auto it = std::search(
            wTitle.begin(), wTitle.end(),
            search->targetTitle.begin(), search->targetTitle.end(),
            [](wchar_t ch1, wchar_t ch2) { return towlower(ch1) == towlower(ch2); }
        );

        if (it != wTitle.end()) {
            search->foundHwnd = hwnd;
            return FALSE; // found exact title, stop enumerating
        }
    }

    // Fallback: check if the window belongs to the target app (by process executable name)
    if (!search->fallbackHwnd && !search->targetApp.empty()) {
        DWORD pid = 0;
        GetWindowThreadProcessId(hwnd, &pid);
        if (pid != 0) {
            std::wstring exePath;
            if (ProcessImageNameForPid(pid, &exePath)) {
                std::wstring targetLower = ToLowerCopy(search->targetApp);
                std::wstring exeLower = ToLowerCopy(exePath);
                
                // Remove quotes from target AppUserModelId if any
                if (targetLower.size() >= 2 && targetLower.front() == L'"' && targetLower.back() == L'"') {
                    targetLower = targetLower.substr(1, targetLower.size() - 2);
                }

                if (exeLower == targetLower) {
                    search->fallbackHwnd = hwnd;
                } else {
                    std::wstring exeName = exeLower;
                    size_t slashPos = exeName.find_last_of(L"\\/");
                    if (slashPos != std::wstring::npos) {
                        exeName = exeName.substr(slashPos + 1);
                    }
                    if (exeName == targetLower || exeName == targetLower + L".exe") {
                        search->fallbackHwnd = hwnd;
                    }
                }
            }
        }
    }

    return TRUE;
}

void OpenRelevantApp() {
    std::wstring title;
    std::wstring app;
    {
        std::lock_guard lock(g_stateMutex);
        title = g_state.media.title;
        app = g_state.media.sourceAppUserModelId;
    }

    // Try to find and focus window containing track title (ideal for browser playing YouTube/Spotify)
    if (!title.empty() || !app.empty()) {
        WindowSearch search;
        search.targetTitle = title;
        search.targetApp = app;
        EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&search));

        HWND hwndToFocus = search.foundHwnd ? search.foundHwnd : search.fallbackHwnd;

        if (hwndToFocus) {
            if (IsIconic(hwndToFocus)) {
                ShowWindow(hwndToFocus, SW_RESTORE);
            }
            SetForegroundWindow(hwndToFocus);
            return;
        }
    }

    // Fallback: Launch or focus via AppUserModelId or Path
    if (!app.empty()) {
        std::wstring executePath = app;
        
        // Remove surrounding quotes if any
        if (executePath.size() >= 2 && executePath.front() == L'"' && executePath.back() == L'"') {
            executePath = executePath.substr(1, executePath.size() - 2);
        }

        bool isFilePath = (executePath.find(L":\\") != std::wstring::npos || 
                           (executePath.size() >= 4 && executePath.substr(executePath.size() - 4) == L".exe"));

        if (isFilePath) {
            if (GetFileAttributesW(executePath.c_str()) == INVALID_FILE_ATTRIBUTES) {
                // Path doesn't exist. Try 64-bit Program Files if it was in x86
                size_t x86Pos = executePath.find(L" (x86)");
                if (x86Pos != std::wstring::npos) {
                    std::wstring altPath = executePath;
                    altPath.erase(x86Pos, 6);
                    if (GetFileAttributesW(altPath.c_str()) != INVALID_FILE_ATTRIBUTES) {
                        executePath = altPath;
                    }
                }
                
                // If it STILL doesn't exist after trying alternatives, just gracefully abort!
                // Trying to guess 'brave.exe' triggers broken Windows Registry App Paths.
                if (GetFileAttributesW(executePath.c_str()) == INVALID_FILE_ATTRIBUTES) {
                    return;
                }
            }
            
            SHELLEXECUTEINFOW sei = { sizeof(sei) };
            sei.fMask = SEE_MASK_FLAG_NO_UI;
            sei.lpFile = executePath.c_str();
            sei.nShow = SW_SHOWNORMAL;
            ShellExecuteExW(&sei);
        } else {
            // It's a UWP/Desktop AppUserModelId, launch via AppsFolder
            std::wstring shellPath = L"shell:AppsFolder\\" + executePath;
            SHELLEXECUTEINFOW sei = { sizeof(sei) };
            sei.fMask = SEE_MASK_FLAG_NO_UI;
            sei.lpFile = shellPath.c_str();
            sei.nShow = SW_SHOWNORMAL;
            ShellExecuteExW(&sei);
        }
        return;
    }

    ShellExecuteW(nullptr, L"open", L"ms-settings:", nullptr, nullptr, SW_SHOWNORMAL);
}

void DismissTransientState() {
    std::lock_guard lock(g_stateMutex);
    g_state.clipboard.active = false;
    g_state.notification.active = false;
    g_state.volume.active = false;
    g_state.progress.active = false;
    g_state.capsLock.active = false;
    g_state.device.active = false;
    g_state.battery.active = false;
    Wh_SetIntValue(L"ProgressPercent", -1);
}

void ShowContextMenu(HWND hwnd, POINT screenPoint) {
    HMENU menu = CreatePopupMenu();
    AppendMenuW(menu, MF_STRING, 1, L"Dismiss");
    AppendMenuW(menu, MF_STRING, 2, L"Pin expanded");
    AppendMenuW(menu, MF_STRING, 3, Wh_GetIntValue(L"GameOverlayPinned", 0) ? L"Hide game overlay" : L"Show game overlay");
    std::wstring shapeStr = GetStringSettingCopy(L"Appearance.ShapeStyle");
    const int activeW11 = Wh_GetIntValue(L"W11StyleOverride", -1) >= 0
                          ? Wh_GetIntValue(L"W11StyleOverride", 0)
                          : EqualsNoCase(shapeStr, L"w11");
    AppendMenuW(menu, MF_STRING, 10, activeW11 ? L"Use iPhone Pill Style" : L"Use Windows 11 Flyout Style");
    const int activeNotch = Wh_GetIntValue(L"NotchStyleOverride", -1) >= 0
                          ? Wh_GetIntValue(L"NotchStyleOverride", 0)
                          : EqualsNoCase(shapeStr, L"notch");
    AppendMenuW(menu, MF_STRING, 12, activeNotch ? L"Disable macOS Notch Style" : L"Use macOS Notch Style");
    const int activeExpandOnHover = Wh_GetIntValue(L"ExpandOnHoverOverride", -1) >= 0
                          ? Wh_GetIntValue(L"ExpandOnHoverOverride", 0)
                          : Wh_GetIntSetting(L"Appearance.ExpandOnHover");
    AppendMenuW(menu, MF_STRING, 11, activeExpandOnHover ? L"Expand on Click" : L"Expand on Hover");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 4, L"Transparency 100%");
    AppendMenuW(menu, MF_STRING, 5, L"Transparency 85%");
    AppendMenuW(menu, MF_STRING, 6, L"Transparency 70%");
    AppendMenuW(menu, MF_STRING, 7, L"Transparency 55%");
    AppendMenuW(menu, MF_STRING, 8, L"Reset transparency");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    // Color theme presets
    AppendMenuW(menu, MF_STRING, 20, L"Theme: OLED Black (default)");
    AppendMenuW(menu, MF_STRING, 21, L"Theme: Dark Gray");
    AppendMenuW(menu, MF_STRING, 22, L"Theme: Midnight Blue");
    AppendMenuW(menu, MF_STRING, 23, L"Theme: Deep Purple");
    AppendMenuW(menu, MF_STRING, 24, L"Theme: Fluent Design");
    AppendMenuW(menu, MF_SEPARATOR, 0, nullptr);
    AppendMenuW(menu, MF_STRING, 9, L"Open Windhawk settings");

    SetForegroundWindow(hwnd);
    const UINT cmd = TrackPopupMenu(menu, TPM_RETURNCMD | TPM_RIGHTBUTTON,
                                   screenPoint.x, screenPoint.y, 0, hwnd, nullptr);
    DestroyMenu(menu);

    switch (cmd) {
        case 1:
            DismissTransientState();
            g_clickExpanded = false;
            g_layoutDirty = true;
            TriggerNudge();
            break;
        case 2:
            Wh_SetIntValue(L"PinnedExpanded", Wh_GetIntValue(L"PinnedExpanded", 0) ? 0 : 1);
            break;
        case 3:
            Wh_SetIntValue(L"GameOverlayPinned", Wh_GetIntValue(L"GameOverlayPinned", 0) ? 0 : 1);
            break;
        case 4:
            Wh_SetIntValue(L"PillOpacityOverride", 100);
            LoadSettings();
            break;
        case 5:
            Wh_SetIntValue(L"PillOpacityOverride", 85);
            LoadSettings();
            break;
        case 6:
            Wh_SetIntValue(L"PillOpacityOverride", 70);
            LoadSettings();
            break;
        case 7:
            Wh_SetIntValue(L"PillOpacityOverride", 55);
            LoadSettings();
            break;
        case 8:
            Wh_SetIntValue(L"PillOpacityOverride", -1);
            LoadSettings();
            break;
        case 9: {
            wchar_t currentProcessPath[MAX_PATH] = {};
            GetModuleFileNameW(nullptr, currentProcessPath, ARRAYSIZE(currentProcessPath));

            HINSTANCE result = ShellExecuteW(nullptr, L"open",
                                             currentProcessPath,
                                             nullptr,
                                             nullptr, SW_SHOWNORMAL);
            if (reinterpret_cast<INT_PTR>(result) <= 32) {
                Wh_Log(L"Failed to open Windhawk settings.");
            }
            break;
        }
        case 10: {
            std::wstring shapeStr = GetStringSettingCopy(L"Appearance.ShapeStyle");
            const int activeW11Val = Wh_GetIntValue(L"W11StyleOverride", -1) >= 0
                                  ? Wh_GetIntValue(L"W11StyleOverride", 0)
                                  : EqualsNoCase(shapeStr, L"w11");
            Wh_SetIntValue(L"W11StyleOverride", activeW11Val ? 0 : 1);
            if (!activeW11Val) Wh_SetIntValue(L"NotchStyleOverride", 0);
            LoadSettings();
            g_layoutDirty = true;
            break;
        }
        case 12: {
            std::wstring shapeStr = GetStringSettingCopy(L"Appearance.ShapeStyle");
            const int activeNotchVal = Wh_GetIntValue(L"NotchStyleOverride", -1) >= 0
                                    ? Wh_GetIntValue(L"NotchStyleOverride", 0)
                                    : EqualsNoCase(shapeStr, L"notch");
            Wh_SetIntValue(L"NotchStyleOverride", activeNotchVal ? 0 : 1);
            if (!activeNotchVal) Wh_SetIntValue(L"W11StyleOverride", 0);
            LoadSettings();
            g_layoutDirty = true;
            TriggerNudge();
            break;
        }
        case 11: {
            const int activeExpandOnHover = Wh_GetIntValue(L"ExpandOnHoverOverride", -1) >= 0
                                  ? Wh_GetIntValue(L"ExpandOnHoverOverride", 0)
                                  : Wh_GetIntSetting(L"Appearance.ExpandOnHover");
            Wh_SetIntValue(L"ExpandOnHoverOverride", activeExpandOnHover ? 0 : 1);
            LoadSettings();
            g_layoutDirty = true;
            break;
        }
        // Color theme presets — stored as integer index in local mod storage.
        case 20:  // OLED Black
            Wh_SetIntValue(L"ColorTheme", 0);
            LoadSettings();
            break;
        case 21:  // Dark Gray
            Wh_SetIntValue(L"ColorTheme", 1);
            LoadSettings();
            break;
        case 22:  // Midnight Blue
            Wh_SetIntValue(L"ColorTheme", 2);
            LoadSettings();
            break;
        case 23:  // Deep Purple
            Wh_SetIntValue(L"ColorTheme", 3);
            LoadSettings();
            break;
        case 24:  // Fluent Design
            Wh_SetIntValue(L"ColorTheme", 4);
            LoadSettings();
            break;
    }
}

class Renderer {
   public:
    bool Initialize(HWND hwnd) {
        hwnd_ = hwnd;

        HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
                                       __uuidof(ID2D1Factory),
                                       reinterpret_cast<void**>(d2dFactory_.GetAddressOf()));
        if (FAILED(hr)) {
            return false;
        }

        hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
                                 reinterpret_cast<IUnknown**>(dwriteFactory_.GetAddressOf()));
        if (FAILED(hr)) {
            return false;
        }

        D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
            D2D1_RENDER_TARGET_TYPE_DEFAULT,
            D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
            0.0f, 0.0f,
            D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE);

        hr = d2dFactory_->CreateDCRenderTarget(&props, &target_);
        if (FAILED(hr)) {
            return false;
        }

        // Apple SF Pro-like: use Segoe UI Variable Display for clean modern look.
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_SEMI_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         13.5f, L"", &textFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Small", nullptr,
                                         DWRITE_FONT_WEIGHT_NORMAL,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         11.0f, L"", &smallTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         18.0f, L"", &clockFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe Fluent Icons", nullptr,
                                         DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         16.0f, L"", &iconFormat_);

        if (textFormat_) {
            textFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        }
        if (smallTextFormat_) {
            smallTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        }
        if (clockFormat_) {
            clockFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            clockFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            clockFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
        if (iconFormat_) {
            iconFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        }

        return CreateBackingBitmap(520, 140);
    }

    bool Render(const SharedState& state, const Settings& settings, const Activity& primary,
                const std::optional<Activity>& secondary, float width, float height,
                float nudge, bool hover, bool pinned, double now) {
        EnsureTextFormats(settings.sizeScale);
        const int pixelWidth = std::max(1, static_cast<int>(std::ceil(width + kRenderPadX * 2.0f)));
        const int pixelHeight = std::max(1, static_cast<int>(std::ceil(height + kRenderPadY * 2.0f)));

        if (pixelWidth != bitmapWidth_ || pixelHeight != bitmapHeight_) {
            if (!CreateBackingBitmap(pixelWidth, pixelHeight)) {
                return false;
            }
            PositionOverlayWindow(hwnd_, pixelWidth, pixelHeight);
        } else if (g_layoutDirty.exchange(false)) {
            PositionOverlayWindow(hwnd_, pixelWidth, pixelHeight);
        }

        RECT rc = {0, 0, bitmapWidth_, bitmapHeight_};
        HRESULT hr = target_->BindDC(memDc_, &rc);
        if (FAILED(hr)) {
            return false;
        }

        target_->BeginDraw();
        target_->Clear(D2D1::ColorF(0, 0.0f));

        EnsureBrushes(settings, state);
        settingsOpacity_ = settings.pillOpacity;

        const bool gameMetricsPresent = primary.kind == IslandKind::Idle &&
            (settings.gameOverlay || Wh_GetIntValue(L"GameOverlayPinned", 0) != 0);
        const float hoverScale = ((hover && !gameMetricsPresent) || pinned) ? 1.025f : 1.0f;
        const float scale = hoverScale;

        const float top = settings.notchStyle ? std::max(0.0f, nudge) : (kRenderPadY + nudge);
        const float left = kRenderPadX;
        
        if (width >= 2.0f && height >= 2.0f) {
            if (secondary) {
                const float gap = 12.0f * settings.sizeScale;
                const float maxH = std::max(primary.height, secondary->height);
                const float pTop = top + (maxH - primary.height) * 0.5f;
                const float sTop = top + (maxH - secondary->height) * 0.5f;

                DrawPill(state, settings, primary,
                         D2D1::RectF(left, pTop, left + primary.width, pTop + primary.height),
                         scale, now);
                DrawPill(state, settings, *secondary,
                         D2D1::RectF(left + primary.width + gap, sTop,
                                      left + primary.width + gap + secondary->width,
                                      sTop + secondary->height),
                         scale, now);
            } else {
                DrawPill(state, settings, primary,
                         D2D1::RectF(left, top, left + width, top + height), scale, now);
            }
        }

        hr = target_->EndDraw();
        if (FAILED(hr)) {
            return false;
        }

        POINT src = {0, 0};
        SIZE size = {bitmapWidth_, bitmapHeight_};
        POINT dst = {};
        RECT winRect = {};
        GetWindowRect(hwnd_, &winRect);
        dst.x = winRect.left;
        dst.y = winRect.top;

        BLENDFUNCTION blend = {};
        blend.BlendOp = AC_SRC_OVER;
        blend.SourceConstantAlpha = static_cast<BYTE>(Clamp(settings.pillOpacity, 0.35f, 1.0f) * 255.0f);
        blend.AlphaFormat = AC_SRC_ALPHA;

        return UpdateLayeredWindow(hwnd_, nullptr, &dst, &size, memDc_, &src, 0, &blend,
                                   ULW_ALPHA) != FALSE;
    }

    void Shutdown() {
        artBitmap_.Reset();
        notificationIconBitmap_.Reset();
        mediaSourceIconBitmap_.Reset();
        clipboardIconBitmap_.Reset();
        accentBrush_.Reset();
        redBrush_.Reset();
        textBrush_.Reset();
        mutedBrush_.Reset();
        tintBrush_.Reset();
        shadowBrush_.Reset();
        target_.Reset();
        textFormat_.Reset();
        smallTextFormat_.Reset();
        boldTextFormat_.Reset();
        hugeTextFormat_.Reset();
        clockFormat_.Reset();
        iconFormat_.Reset();
        dwriteFactory_.Reset();
        d2dFactory_.Reset();

        if (oldBitmap_) {
            SelectObject(memDc_, oldBitmap_);
            oldBitmap_ = nullptr;
        }
        if (dib_) {
            DeleteObject(dib_);
            dib_ = nullptr;
        }
        if (memDc_) {
            DeleteDC(memDc_);
            memDc_ = nullptr;
        }
    }

   private:
    bool CreateBackingBitmap(int width, int height) {
        if (oldBitmap_) {
            SelectObject(memDc_, oldBitmap_);
            oldBitmap_ = nullptr;
        }
        if (dib_) {
            DeleteObject(dib_);
            dib_ = nullptr;
        }
        if (!memDc_) {
            HDC screen = GetDC(nullptr);
            memDc_ = CreateCompatibleDC(screen);
            ReleaseDC(nullptr, screen);
            if (!memDc_) {
                return false;
            }
        }

        BITMAPINFO bi = {};
        bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        bi.bmiHeader.biWidth = width;
        bi.bmiHeader.biHeight = -height;
        bi.bmiHeader.biPlanes = 1;
        bi.bmiHeader.biBitCount = 32;
        bi.bmiHeader.biCompression = BI_RGB;

        void* bits = nullptr;
        dib_ = CreateDIBSection(memDc_, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
        if (!dib_) {
            return false;
        }

        oldBitmap_ = static_cast<HBITMAP>(SelectObject(memDc_, dib_));
        bitmapWidth_ = width;
        bitmapHeight_ = height;
        return true;
    }

    float lastFontScale_ = 0.0f;
    void EnsureTextFormats(float scale) {
        if (std::abs(scale - lastFontScale_) < 0.001f) {
            return;
        }

        textFormat_ = nullptr;
        smallTextFormat_ = nullptr;
        clockFormat_ = nullptr;
        iconFormat_ = nullptr;

        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_SEMI_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         13.5f, L"", &textFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Small", nullptr,
                                         DWRITE_FONT_WEIGHT_NORMAL,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         11.0f, L"", &smallTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         18.0f, L"", &clockFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         12.0f, L"", &boldTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                         DWRITE_FONT_WEIGHT_BOLD,
                                         DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         42.0f, L"", &hugeTextFormat_);
        dwriteFactory_->CreateTextFormat(L"Segoe Fluent Icons", nullptr,
                                         DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL,
                                         DWRITE_FONT_STRETCH_NORMAL,
                                         16.0f, L"", &iconFormat_);

        if (textFormat_) {
            textFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        }
        if (smallTextFormat_) {
            smallTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        }
        if (boldTextFormat_) {
            boldTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            boldTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
        }
        if (hugeTextFormat_) {
            hugeTextFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            hugeTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
        }
        if (clockFormat_) {
            clockFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
            clockFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            clockFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
        }
        if (iconFormat_) {
            iconFormat_->SetWordWrapping(DWRITE_WORD_WRAPPING_NO_WRAP);
        }

        lastFontScale_ = scale;
    }

    void EnsureBrushes(const Settings& settings, const SharedState& state) {
        D2D1_COLOR_F accent = settings.customAccent;
        if (settings.accentMode == AccentMode::System) {
            accent = GetSystemAccentColor();
        } else if (settings.accentMode == AccentMode::Auto && !state.media.art.bgra.empty()) {
            accent = state.media.art.sampledAccent;
        }

        if (!accentBrush_) target_->CreateSolidColorBrush(accent, &accentBrush_);
        else accentBrush_->SetColor(accent);

        if (!redBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.27f, 0.27f, 1.0f), &redBrush_);

        // Use user-configured text colors.
        D2D1_COLOR_F primary = settings.textPrimaryColor;
        primary.a = 0.96f;
        if (!textBrush_) target_->CreateSolidColorBrush(primary, &textBrush_);
        else textBrush_->SetColor(primary);

        D2D1_COLOR_F secondary = settings.textSecondaryColor;
        secondary.a = 0.72f;
        if (!mutedBrush_) target_->CreateSolidColorBrush(secondary, &mutedBrush_);
        else mutedBrush_->SetColor(secondary);

        // Cache pill bg color with opacity applied.
        pillBgColor_ = settings.pillBgColor;
        pillBgColor_.a = 1.0f;
        
        D2D1_COLOR_F tintColor = D2D1::ColorF(0.010f, 0.010f, 0.012f, settings.tintOpacity);
        if (!tintBrush_) target_->CreateSolidColorBrush(tintColor, &tintBrush_);
        else tintBrush_->SetColor(tintColor);

        if (!shadowBrush_) target_->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0.70f), &shadowBrush_);
    }

    void DrawPill(const SharedState& state, const Settings& settings, const Activity& activity,
                  D2D1_RECT_F rect, float scale, double now) {
        const float cx = (rect.left + rect.right) * 0.5f;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float w = (rect.right - rect.left) * scale;
        const float h = (rect.bottom - rect.top) * scale;
        rect = D2D1::RectF(cx - w * 0.5f, cy - h * 0.5f, cx + w * 0.5f, cy + h * 0.5f);

        float radius = settings.w11Style ? 8.0f * settings.sizeScale : (rect.bottom - rect.top) * 0.5f;
        if (settings.notchStyle) {
            radius = 16.0f * settings.sizeScale;
        } else if (!settings.w11Style) {
            radius = std::min(radius, 44.0f * settings.sizeScale);
        }
        DrawSoftShadow(rect, radius);

        DrawPillSurface(rect, radius, activity.kind, settings.w11Style, settings.notchStyle);

        if (activity.kind == IslandKind::Progress) {
            DrawProgressRing(rect, state.progress.percent);
        }

        if (activity.kind == IslandKind::BatteryLow) {
            const float pulse = 0.5f + 0.5f * std::sin(static_cast<float>(now * 2.0 * 3.14159265 * 2.1));
            redBrush_->SetOpacity(0.45f + 0.45f * pulse);
            DrawIslandShape(rect, radius, settings.w11Style, settings.notchStyle, redBrush_.Get(), 2.0f);
            redBrush_->SetOpacity(1.0f);
        } else {
            accentBrush_->SetOpacity(activity.kind == IslandKind::Idle ? 0.18f : 0.34f);
            DrawIslandShape(rect, radius, settings.w11Style, settings.notchStyle, accentBrush_.Get(), 1.0f);
            accentBrush_->SetOpacity(1.0f);
        }

        if (!settings.w11Style && !settings.notchStyle) {
            ComPtr<ID2D1SolidColorBrush> highlight;
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.10f * settingsOpacity_), &highlight);
            target_->DrawRoundedRectangle(
                D2D1::RoundedRect(D2D1::RectF(rect.left + 1, rect.top + 1, rect.right - 1,
                                              rect.bottom - 1),
                                  radius - 1, radius - 1),
                highlight.Get(), 1.0f);
        }

        D2D1_MATRIX_3X2_F oldTransform;
        target_->GetTransform(&oldTransform);
        D2D1_POINT_2F pillCenter = D2D1::Point2F((rect.left + rect.right) * 0.5f, (rect.top + rect.bottom) * 0.5f);
        target_->SetTransform(D2D1::Matrix3x2F::Scale(settings.sizeScale, settings.sizeScale, pillCenter) * oldTransform);

        float invScale = 1.0f / settings.sizeScale;
        float unW = (rect.right - rect.left) * invScale;
        float unH = (rect.bottom - rect.top) * invScale;
        D2D1_RECT_F unscaledRect = D2D1::RectF(pillCenter.x - unW * 0.5f, pillCenter.y - unH * 0.5f, pillCenter.x + unW * 0.5f, pillCenter.y + unH * 0.5f);

        switch (activity.kind) {
            case IslandKind::Media:
                DrawMedia(state, unscaledRect, now);
                break;
            case IslandKind::Clipboard:
                DrawClipboard(state, unscaledRect);
                break;
            case IslandKind::Notification:
                DrawNotification(state, unscaledRect);
                break;
            case IslandKind::Volume:
                DrawVolume(state, unscaledRect);
                break;
            case IslandKind::CapsLock:
                DrawCapsLock(state, unscaledRect);
                break;
            case IslandKind::Device:
                DrawDevice(state, unscaledRect);
                break;
            case IslandKind::BatteryLow:
                DrawBattery(state, unscaledRect);
                break;
            case IslandKind::Progress:
                DrawProgress(state, unscaledRect);
                break;
            case IslandKind::Idle:
            default:
                DrawIdleDashboard(state, unscaledRect, settings, now);
                break;
        }

        // ── Apple-style privacy indicator dots ───────────────────────────────
        // Green dot = camera in use, Orange dot = mic in use.
        // Drawn in top-right corner of pill, outside content area.
        DrawPrivacyDots(state, settings, unscaledRect, now);

        target_->SetTransform(oldTransform);
    }

    void DrawSoftShadow(D2D1_RECT_F rect, float radius) {
        UNREFERENCED_PARAMETER(rect);
        UNREFERENCED_PARAMETER(radius);
    }

    // Apple Dynamic Island privacy dots.
    // Placed inside the pill near the top-right edge — pulsing glow like iPhone.
    void DrawPrivacyDots(const SharedState& state, const Settings& settings, D2D1_RECT_F rect, double now) {
        const bool mic = state.system.micActive && settings.privacyDots && settings.privacyDotsMic;
        const bool cam = state.system.cameraActive && settings.privacyDots && settings.privacyDotsCam;
        if (!mic && !cam) return;

        // Soft breathing pulse (0.75 Hz like iPhone) or static 1.0f.
        const float pulse = settings.privacyDotsPulse
            ? (0.72f + 0.28f * std::sin(static_cast<float>(now * 2.0 * 3.14159265 * 0.75)))
            : 1.0f;

        const float dotR   = 4.5f;   // dot radius
        const float gap    = 5.5f;   // gap between dots
        const float margin = 10.0f;  // from right edge
        const float dotY   = rect.top + (rect.bottom - rect.top) * 0.5f;

        float x = rect.right - margin - dotR;

        // Green = camera (rightmost when both active).
        if (cam) {
            ComPtr<ID2D1SolidColorBrush> camBrush;
            D2D1_COLOR_F camColor = settings.privacyDotsCamHex;
            camColor.a = pulse * settingsOpacity_;
            target_->CreateSolidColorBrush(camColor, &camBrush);
            if (camBrush) {
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, dotY), dotR, dotR),
                                     camBrush.Get());
                // Glow halo.
                ComPtr<ID2D1SolidColorBrush> glow;
                D2D1_COLOR_F glowColor = camColor;
                glowColor.a = 0.18f * pulse * settingsOpacity_;
                target_->CreateSolidColorBrush(glowColor, &glow);
                if (glow) {
                    target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, dotY),
                                                        dotR * 2.2f, dotR * 2.2f), glow.Get());
                }
            }
            x -= (dotR * 2.0f + gap);
        }

        // Orange = microphone.
        if (mic) {
            ComPtr<ID2D1SolidColorBrush> micBrush;
            D2D1_COLOR_F micColor = settings.privacyDotsMicHex;
            micColor.a = pulse * settingsOpacity_;
            target_->CreateSolidColorBrush(micColor, &micBrush);
            if (micBrush) {
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, dotY), dotR, dotR),
                                     micBrush.Get());
                ComPtr<ID2D1SolidColorBrush> glow;
                D2D1_COLOR_F glowColor = micColor;
                glowColor.a = 0.18f * pulse * settingsOpacity_;
                target_->CreateSolidColorBrush(glowColor, &glow);
                if (glow) {
                    target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, dotY),
                                                        dotR * 2.2f, dotR * 2.2f), glow.Get());
                }
            }
        }
    }

    ComPtr<ID2D1PathGeometry> CreateNotchGeometry(D2D1_RECT_F rect, float radius) {
        ComPtr<ID2D1PathGeometry> geom;
        if (FAILED(d2dFactory_->CreatePathGeometry(&geom))) return nullptr;
        
        ComPtr<ID2D1GeometrySink> sink;
        if (FAILED(geom->Open(&sink))) return nullptr;
        
        float r = std::min({radius, (rect.right - rect.left) * 0.5f, (rect.bottom - rect.top) * 0.5f});
        if (r < 0.0f) r = 0.0f;

        sink->BeginFigure(D2D1::Point2F(rect.left, rect.top), D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine(D2D1::Point2F(rect.right, rect.top));
        sink->AddLine(D2D1::Point2F(rect.right, rect.bottom - r));
        if (r > 0.0f) {
            sink->AddArc(D2D1::ArcSegment(
                D2D1::Point2F(rect.right - r, rect.bottom),
                D2D1::SizeF(r, r), 0.0f,
                D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
            sink->AddLine(D2D1::Point2F(rect.left + r, rect.bottom));
            sink->AddArc(D2D1::ArcSegment(
                D2D1::Point2F(rect.left, rect.bottom - r),
                D2D1::SizeF(r, r), 0.0f,
                D2D1_SWEEP_DIRECTION_CLOCKWISE, D2D1_ARC_SIZE_SMALL));
        } else {
            sink->AddLine(D2D1::Point2F(rect.left, rect.bottom));
        }
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        sink->Close();
        
        return geom;
    }

    ComPtr<ID2D1Geometry> CreateIslandMaskGeometry(D2D1_RECT_F rect, float radius, bool notchStyle) {
        if (notchStyle) {
            ComPtr<ID2D1PathGeometry> geom = CreateNotchGeometry(rect, radius);
            if (geom) {
                ComPtr<ID2D1Geometry> baseGeom;
                geom.As(&baseGeom);
                return baseGeom;
            }
        }
        ComPtr<ID2D1RoundedRectangleGeometry> rr;
        d2dFactory_->CreateRoundedRectangleGeometry(D2D1::RoundedRect(rect, radius, radius), &rr);
        ComPtr<ID2D1Geometry> baseGeom;
        if (rr) rr.As(&baseGeom);
        return baseGeom;
    }

    void FillIslandShape(D2D1_RECT_F rect, float radius, bool w11Style, bool notchStyle, ID2D1Brush* brush) {
        if (!brush) return;
        if (notchStyle) {
            auto geom = CreateNotchGeometry(rect, radius);
            if (geom) {
                target_->FillGeometry(geom.Get(), brush);
                return;
            }
        }
        target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), brush);
    }

    void DrawIslandShape(D2D1_RECT_F rect, float radius, bool w11Style, bool notchStyle, ID2D1Brush* brush, float strokeWidth) {
        if (!brush) return;
        if (notchStyle) {
            auto geom = CreateNotchGeometry(rect, radius);
            if (geom) {
                target_->DrawGeometry(geom.Get(), brush, strokeWidth);
                return;
            }
        }
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), brush, strokeWidth);
    }

    void DrawPillSurface(D2D1_RECT_F rect, float radius, IslandKind kind, bool w11Style, bool notchStyle) {
        UNREFERENCED_PARAMETER(kind);

        if (tintBrush_) {
            FillIslandShape(rect, radius, w11Style, notchStyle, tintBrush_.Get());
        }

        // User-defined pill background color.
        ComPtr<ID2D1SolidColorBrush> blackBrush;
        D2D1_COLOR_F bg = pillBgColor_;
        bg.a = settingsOpacity_;
        target_->CreateSolidColorBrush(bg, &blackBrush);
        if (blackBrush) {
            FillIslandShape(rect, radius, w11Style, notchStyle, blackBrush.Get());
        }

        if (w11Style) {
            // In Windows 11 style, we draw a double-layer modern border.
            // Windows 11 uses a very subtle 1px border. In dark mode, it's white with 15% opacity.
            ComPtr<ID2D1SolidColorBrush> border;
            target_->CreateSolidColorBrush(
                D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.15f * settingsOpacity_), &border);
            if (border) {
                D2D1_RECT_F borderRect = D2D1::RectF(rect.left + 0.5f, rect.top + 0.5f,
                                                     rect.right - 0.5f, rect.bottom - 0.5f);
                DrawIslandShape(borderRect, radius, w11Style, notchStyle, border.Get(), 1.0f);
            }
        } else if (notchStyle) {
            // macOS Notch style border: draw subtle rim without top gloss
            ComPtr<ID2D1SolidColorBrush> border;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.08f * settingsOpacity_),
                                           &border);
            if (border) {
                D2D1_RECT_F borderRect = D2D1::RectF(rect.left + 0.5f, rect.top + 0.5f,
                                                     rect.right - 0.5f, rect.bottom - 0.5f);
                DrawIslandShape(borderRect, radius, w11Style, notchStyle, border.Get(), 0.8f);
            }
        } else {
            // Thin top-edge gloss: simulates iPhone notch glass shine.
            ComPtr<ID2D1SolidColorBrush> gloss;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.055f * settingsOpacity_),
                                           &gloss);
            if (gloss) {
                D2D1_RECT_F glossLine = D2D1::RectF(rect.left + radius, rect.top + 0.5f,
                                                    rect.right - radius, rect.top + 1.2f);
                target_->FillRectangle(glossLine, gloss.Get());
            }

            // Outer border: extremely subtle white rim like iPhone Dynamic Island edge.
            ComPtr<ID2D1SolidColorBrush> border;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.08f * settingsOpacity_),
                                           &border);
            if (border) {
                DrawIslandShape(D2D1::RectF(rect.left + 0.5f, rect.top + 0.5f,
                                            rect.right - 0.5f, rect.bottom - 0.5f),
                                radius, w11Style, notchStyle, border.Get(), 0.8f);
            }
        }
    }

    void DrawAccentGlow(D2D1_RECT_F rect, const Activity& activity, double now) {
        float opacity = activity.kind == IslandKind::Media ? 0.23f : 0.12f;
        if (activity.kind == IslandKind::BatteryLow) {
            redBrush_->SetOpacity(0.18f);
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(rect.right - 38, rect.top + 20), 56, 36),
                                 redBrush_.Get());
            redBrush_->SetOpacity(1.0f);
            return;
        }

        opacity += 0.05f * (0.5f + 0.5f * std::sin(static_cast<float>(now * 1.7)));
        accentBrush_->SetOpacity(opacity);
        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(rect.left + 48, rect.top + 10), 70, 42),
                             accentBrush_.Get());
        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(rect.right - 58, rect.bottom - 8), 76, 42),
                             accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
    }

    static void GetWeatherIconAndText(int code, std::wstring& icon, std::wstring& text) {
        switch (code) {
            case 113: icon = L"☀️"; break;
            case 116: icon = L"⛅"; break;
            case 119: case 122: icon = L"☁️"; break;
            case 143: case 248: case 260: icon = L"🌫️"; break;
            case 200: case 386: case 389: case 392: case 395: icon = L"⛈️"; break;
            case 176: case 263: case 266: case 281: case 284: case 293: case 296: case 299: case 302: case 305: case 308: case 311: case 314: case 353: case 356: case 359: icon = L"🌧️"; break;
            case 179: case 182: case 185: case 227: case 230: case 317: case 320: case 323: case 326: case 329: case 332: case 335: case 338: case 350: case 362: case 365: case 368: case 371: icon = L"❄️"; break;
            default: icon = L"🌡️"; break;
        }
    }

    static int GetDaysInMonth(int year, int month) {
        if (month == 2) {
            bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            return leap ? 29 : 28;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
        return 31;
    }

    static int GetDayOfWeek(int year, int month, int day) {
        if (month < 3) { month += 12; year -= 1; }
        int k = year % 100;
        int j = year / 100;
        int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
        return (h + 6) % 7;
    }



    void DrawCalendarDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings, double now, float scale, SYSTEMTIME& local) {
        ComPtr<ID2D1SolidColorBrush> calBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.05f * settingsOpacity_), &calBg);
        D2D1_RECT_F leftBlock = D2D1::RectF(rect.left + 22.0f * scale, rect.top + 18.0f * scale,
                                            rect.left + 118.0f * scale, rect.bottom - 22.0f * scale);
        target_->FillRoundedRectangle(D2D1::RoundedRect(leftBlock, 12.0f * scale, 12.0f * scale), calBg.Get());
        
        ComPtr<ID2D1SolidColorBrush> calHeader;
        target_->CreateSolidColorBrush(D2D1::ColorF(0.85f, 0.25f, 0.20f, 0.9f * settingsOpacity_), &calHeader);
        
        wchar_t monthName[32] = {};
        GetDateFormatEx(LOCALE_NAME_USER_DEFAULT, 0, &local, L"MMMM", monthName, ARRAYSIZE(monthName), nullptr);
        for (int i = 0; monthName[i]; ++i) monthName[i] = towupper(monthName[i]);
        
        target_->DrawTextW(monthName, static_cast<UINT32>(wcslen(monthName)), boldTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.top + 8.0f * scale, leftBlock.right, leftBlock.top + 26.0f * scale),
                           calHeader.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        wchar_t yearStr[16] = {};
        swprintf_s(yearStr, L"%d", local.wYear);
        mutedBrush_->SetOpacity(0.45f);
        target_->DrawTextW(yearStr, static_cast<UINT32>(wcslen(yearStr)), boldTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.top + 24.0f * scale, leftBlock.right, leftBlock.top + 40.0f * scale),
                           mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        wchar_t dayStr[16] = {};
        swprintf_s(dayStr, L"%d", local.wDay);
        textBrush_->SetOpacity(0.96f);
        target_->DrawTextW(dayStr, static_cast<UINT32>(wcslen(dayStr)), hugeTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.top + 34.0f * scale, leftBlock.right, leftBlock.top + 84.0f * scale),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        wchar_t weekdayName[32] = {};
        GetDateFormatEx(LOCALE_NAME_USER_DEFAULT, 0, &local, L"dddd", weekdayName, ARRAYSIZE(weekdayName), nullptr);
        mutedBrush_->SetOpacity(0.75f);
        target_->DrawTextW(weekdayName, static_cast<UINT32>(wcslen(weekdayName)), boldTextFormat_.Get(),
                           D2D1::RectF(leftBlock.left, leftBlock.bottom - 24.0f * scale, leftBlock.right, leftBlock.bottom - 4.0f * scale),
                           mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        // Right Grid (7 Columns)
        const float gridStart = rect.left + 138.0f * scale;
        const float gridTop = rect.top + 20.0f * scale;
        const float colW = 31.0f * scale;
        const float rowH = 20.0f * scale;
        const wchar_t* days[] = {L"S", L"M", L"T", L"W", L"T", L"F", L"S"};
        
        for (int i = 0; i < 7; ++i) {
            D2D1_RECT_F cell = D2D1::RectF(gridStart + i * colW, gridTop, gridStart + (i+1)*colW, gridTop + rowH);
            ComPtr<ID2D1SolidColorBrush> brush = (i == 0 || i == 6) ? calHeader : mutedBrush_;
            target_->DrawTextW(days[i], 1, boldTextFormat_.Get(), cell, brush.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        int startDay = GetDayOfWeek(local.wYear, local.wMonth, 1);
        int totalDays = GetDaysInMonth(local.wYear, local.wMonth);
        
        int row = 1;
        int col = startDay;
        textBrush_->SetOpacity(0.85f);
        for (int d = 1; d <= totalDays; ++d) {
            D2D1_RECT_F cell = D2D1::RectF(gridStart + col * colW, gridTop + row * rowH + 2.0f * scale, 
                                           gridStart + (col+1)*colW, gridTop + (row+1)*rowH + 2.0f * scale);
            
            if (d == local.wDay) {
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(cell.left + colW*0.5f, cell.top + rowH*0.5f), 11.0f*scale, 11.0f*scale), calHeader.Get());
                target_->DrawTextW(std::to_wstring(d).c_str(), static_cast<UINT32>(std::to_wstring(d).length()), boldTextFormat_.Get(), cell, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
            } else {
                ComPtr<ID2D1SolidColorBrush> dBrush = (col == 0 || col == 6) ? calHeader : textBrush_;
                if (col == 0 || col == 6) dBrush->SetOpacity(0.6f);
                target_->DrawTextW(std::to_wstring(d).c_str(), static_cast<UINT32>(std::to_wstring(d).length()), boldTextFormat_.Get(), cell, dBrush.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
            }
            
            col++;
            if (col > 6) { col = 0; row++; }
        }
    }

    std::wstring WindDirToArrow(const std::wstring& dir) {
        if (dir == L"N") return L"\x2193";
        if (dir == L"NNE" || dir == L"NE" || dir == L"ENE") return L"\x2199";
        if (dir == L"E") return L"\x2190";
        if (dir == L"ESE" || dir == L"SE" || dir == L"SSE") return L"\x2196";
        if (dir == L"S") return L"\x2191";
        if (dir == L"SSW" || dir == L"SW" || dir == L"WSW") return L"\x2197";
        if (dir == L"W") return L"\x2192";
        if (dir == L"WNW" || dir == L"NW" || dir == L"NNW") return L"\x2198";
        return dir;
    }

    void DrawWeatherDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings, double now, float scale, bool hasWeather, const std::wstring& wIcon, const std::wstring& wText) {
        wchar_t wTemp[32] = {};
        if (hasWeather) swprintf_s(wTemp, L"%.0f\x00B0", state.weather.temperature);
        else wcscpy_s(wTemp, L"--\x00B0");

        std::wstring city = hasWeather ? state.weather.city : L"Locating...";
        std::wstring desc = wText;

        textBrush_->SetOpacity(0.96f);
        // City Name
        target_->DrawTextW(city.c_str(), static_cast<UINT32>(city.length()), boldTextFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 35.0f * scale, rect.left + 185.0f * scale, rect.bottom),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        // Weather Icon
        target_->DrawTextW(wIcon.c_str(), static_cast<UINT32>(wIcon.length()), hugeTextFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 60.0f * scale, rect.left + 95.0f * scale, rect.bottom),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT);
                           
        // Temperature
        target_->DrawTextW(wTemp, static_cast<UINT32>(wcslen(wTemp)), hugeTextFormat_.Get(),
                           D2D1::RectF(rect.left + 95.0f * scale, rect.top + 60.0f * scale, rect.left + 185.0f * scale, rect.bottom),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        // Description
        const size_t descLength = desc.length();
        float descFontSize = 13.5f;
        if (descLength > 58) descFontSize = 9.8f;
        else if (descLength > 44) descFontSize = 10.5f;
        else if (descLength > 32) descFontSize = 11.5f;
        else if (descLength > 22) descFontSize = 12.5f;
        descFontSize *= scale;

        ComPtr<IDWriteTextFormat> weatherDescFormat;
        if (dwriteFactory_) {
            dwriteFactory_->CreateTextFormat(L"Segoe UI Variable Display", nullptr,
                                             DWRITE_FONT_WEIGHT_SEMI_BOLD,
                                             DWRITE_FONT_STYLE_NORMAL,
                                             DWRITE_FONT_STRETCH_NORMAL,
                                             descFontSize, L"", &weatherDescFormat);
        }
        if (weatherDescFormat) {
            weatherDescFormat->SetWordWrapping(DWRITE_WORD_WRAPPING_WRAP);
            weatherDescFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            weatherDescFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
        }

        target_->DrawTextW(desc.c_str(), static_cast<UINT32>(desc.length()),
                           weatherDescFormat ? weatherDescFormat.Get() : textFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 120.0f * scale,
                                       rect.left + 185.0f * scale, rect.bottom - 12.0f * scale),
                           mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);


        ComPtr<ID2D1SolidColorBrush> divider;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f * settingsOpacity_), &divider);
        target_->FillRoundedRectangle(
            D2D1::RoundedRect(D2D1::RectF(rect.left + 190.0f * scale, rect.top + 30.0f * scale,
                                           rect.left + 191.5f * scale, rect.bottom - 34.0f * scale),
                              0.5f * scale, 0.5f * scale), divider.Get());

        std::wstring line3 = hasWeather ? L"Wind: " + state.weather.windSpeed + (settings.weatherFahrenheit ? L" mph " : L" km/h ") + WindDirToArrow(state.weather.windDir) : L"Updated recently";
        std::wstring line4 = hasWeather ? L"Feels Like: " + state.weather.feelsLike + L"\x00B0" : L"";
        std::wstring line5 = hasWeather ? L"Humidity: " + state.weather.humidity + L"%" : L"";

        mutedBrush_->SetOpacity(0.70f);
        
        D2D1_RECT_F rightLine3 = D2D1::RectF(rect.left + 215.0f * scale, rect.top + 55.0f * scale, rect.right, rect.bottom);
        target_->DrawTextW(line3.c_str(), static_cast<UINT32>(line3.length()), textFormat_.Get(),
                           rightLine3, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                           
        D2D1_RECT_F rightLine4 = D2D1::RectF(rect.left + 215.0f * scale, rect.top + 85.0f * scale, rect.right, rect.bottom);
        target_->DrawTextW(line4.c_str(), static_cast<UINT32>(line4.length()), textFormat_.Get(),
                           rightLine4, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                           
        D2D1_RECT_F rightLine5 = D2D1::RectF(rect.left + 215.0f * scale, rect.top + 115.0f * scale, rect.right, rect.bottom);
        target_->DrawTextW(line5.c_str(), static_cast<UINT32>(line5.length()), textFormat_.Get(),
                           rightLine5, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
    }

    void DrawHardwareMonitorDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings, float scale) {
        textBrush_->SetOpacity(0.96f);
        target_->DrawTextW(L"Hardware Monitor", 16, boldTextFormat_.Get(),
                           D2D1::RectF(rect.left + 35.0f * scale, rect.top + 20.0f * scale, rect.right - 25.0f * scale, rect.top + 45.0f * scale),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        // Separator Line
        ComPtr<ID2D1SolidColorBrush> sepBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.15f * settingsOpacity_), &sepBrush);
        float midX = (rect.left + rect.right) * 0.5f;
        target_->DrawLine(D2D1::Point2F(midX, rect.top + 50.0f * scale),
                          D2D1::Point2F(midX, rect.bottom - 20.0f * scale),
                          sepBrush.Get(), 1.0f * scale);

        // Hardware Data Column (Left)
        float leftX = rect.left + 30.0f * scale;
        float rightX = midX + 24.0f * scale;
        float startY = rect.top + 50.0f * scale;
        float rowSpacing = 38.0f * scale;

        // Colors
        ComPtr<ID2D1SolidColorBrush> cpuBrush, ramBrush, gpuBrush, upBrush, downBrush, ssdBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.90f, 0.50f, 1.0f), &cpuBrush); // Green
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &ramBrush); // Red
        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f), &gpuBrush);  // Cyan
        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.90f, 0.50f, 1.0f), &upBrush);   // Green
        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f), &downBrush);  // Cyan
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.60f, 0.0f, 1.0f), &ssdBrush);   // Orange

        auto drawRow = [&](float x, float y, int iconKind, ID2D1SolidColorBrush* iconColor, const wchar_t* label, const wchar_t* value) {
            // Draw Icon
            iconColor->SetOpacity(settingsOpacity_);
            DrawGameIcon(D2D1::Point2F(x + 10.0f * scale, y + 10.0f * scale), 8.0f * scale, iconKind, iconColor, scale);
            iconColor->SetOpacity(1.0f);
            
            // Draw Label
            mutedBrush_->SetOpacity(0.60f * settingsOpacity_);
            target_->DrawTextW(label, static_cast<UINT32>(wcslen(label)), smallTextFormat_.Get(),
                               D2D1::RectF(x + 28.0f * scale, y + 2.0f * scale, x + 100.0f * scale, y + 20.0f * scale),
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

            // Draw Value
            textBrush_->SetOpacity(0.96f * settingsOpacity_);
            target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(),
                               D2D1::RectF(x + 28.0f * scale, y + 16.0f * scale, x + 200.0f * scale, y + 40.0f * scale),
                               textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        };

        wchar_t buf1[32], buf2[32], buf3[32], buf4[32], buf5[32], buf6[32];
        
        swprintf_s(buf1, L"%d%%", state.system.cpuPercent);
        swprintf_s(buf2, L"%.1f / %.1f GB", state.system.memoryUsedGB, state.system.memoryTotalGB);
        if (state.system.gpuPercent >= 0) {
            swprintf_s(buf3, L"%d%%", state.system.gpuPercent);
        } else {
            wcscpy_s(buf3, L"--");
        }

        swprintf_s(buf4, L"%.1f Mbps", state.system.netUpMbps);
        swprintf_s(buf5, L"%.1f Mbps", state.system.netDownMbps);
        swprintf_s(buf6, L"%d%%", 100 - state.system.diskFreePercent);

        drawRow(leftX, startY, 1, cpuBrush.Get(), L"CPU", buf1);
        drawRow(leftX, startY + rowSpacing, 2, ramBrush.Get(), L"RAM", buf2);
        drawRow(leftX, startY + rowSpacing * 2.0f, 3, gpuBrush.Get(), L"GPU", buf3);

        drawRow(rightX, startY, 0, upBrush.Get(), L"NET UP", buf4);
        drawRow(rightX, startY + rowSpacing, 0, downBrush.Get(), L"NET DOWN", buf5);
        drawRow(rightX, startY + rowSpacing * 2.0f, 4, ssdBrush.Get(), L"SSD", buf6);
    }

    void DrawIdleDashboard(const SharedState& state, D2D1_RECT_F rect, const Settings& settings,
                           double now) {
        if (settings.gameOverlay || Wh_GetIntValue(L"GameOverlayPinned", 0) != 0) {
            DrawGameOverlay(state, rect, 1.0f);
            return;
        }
        target_->PushAxisAlignedClip(rect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
        
        if (!clockFormat_) return;

        SYSTEMTIME local = {};
        GetLocalTime(&local);
        wchar_t timeBuf[32] = {};
        GetTimeFormatEx(LOCALE_NAME_USER_DEFAULT, TIME_NOSECONDS, &local, nullptr, timeBuf, ARRAYSIZE(timeBuf));

        const float scale = 1.0f;
        const float width = rect.right - rect.left;
        
        bool hasWeather = state.weather.hasData && (now - state.weather.lastUpdated < 3600.0);
        std::wstring wIcon = L"🌡️";
        std::wstring wText = L"Loading...";
        if (hasWeather) {
            wText = state.weather.weatherDesc;
            GetWeatherIconAndText(state.weather.weatherCode, wIcon, wText);
        }

        if (width / scale < 220.0f) {
            // Collapsed Mode
            if (!settings.weather) {
                D2D1_RECT_F timeRect = D2D1::RectF(rect.left, rect.top + 7.0f * scale,
                                                   rect.right, rect.bottom - 7.0f * scale);
                textBrush_->SetOpacity(0.96f);
                smallTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
                target_->DrawTextW(timeBuf, static_cast<UINT32>(wcslen(timeBuf)), smallTextFormat_.Get(),
                                   timeRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                smallTextFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
            } else {
                D2D1_RECT_F timeRect = D2D1::RectF(rect.left + 20.0f * scale, rect.top + 7.0f * scale,
                                                   rect.left + 80.0f * scale, rect.bottom - 7.0f * scale);
                textBrush_->SetOpacity(0.96f);
                target_->DrawTextW(timeBuf, static_cast<UINT32>(wcslen(timeBuf)), smallTextFormat_.Get(),
                                   timeRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
                
                ComPtr<ID2D1SolidColorBrush> divider;
                target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f * settingsOpacity_), &divider);
                target_->FillRoundedRectangle(
                    D2D1::RoundedRect(D2D1::RectF(rect.left + 82.0f * scale, rect.top + 10.0f * scale,
                                                   rect.left + 83.5f * scale, rect.bottom - 10.0f * scale),
                                      0.5f * scale, 0.5f * scale), divider.Get());

                wchar_t weatherLabel[32] = {};
                if (hasWeather) swprintf_s(weatherLabel, L"%s %.0f\x00B0", wIcon.c_str(), state.weather.temperature);
                else wcscpy_s(weatherLabel, ARRAYSIZE(weatherLabel), L"🌡️ --\x00B0");

                D2D1_RECT_F wRect = D2D1::RectF(rect.left + 94.0f * scale, rect.top + 7.0f * scale,
                                                rect.right, rect.bottom - 7.0f * scale);
                target_->DrawTextW(weatherLabel, static_cast<UINT32>(wcslen(weatherLabel)), smallTextFormat_.Get(),
                                   wRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT);
            }
            textBrush_->SetOpacity(1.0f);
            target_->PopAxisAlignedClip();
            g_idleTab = 0;
            return;
        }

        // Expanded Mode
        std::vector<int> activeTabs;
        activeTabs.push_back(0); // Calendar
        if (settings.weather) activeTabs.push_back(1);
        if (settings.hardwareMonitorModule) activeTabs.push_back(2);

        int maxTabs = activeTabs.size();
        int tabIdx = g_idleTab % maxTabs;
        if (tabIdx < 0) tabIdx += maxTabs;
        int activeTabId = activeTabs[tabIdx];

        if (activeTabId == 0) DrawCalendarDashboard(state, rect, settings, now, scale, local);
        else if (activeTabId == 1) DrawWeatherDashboard(state, rect, settings, now, scale, hasWeather, wIcon, wText);
        else if (activeTabId == 2) DrawHardwareMonitorDashboard(state, rect, settings, scale);

        // Pagination dots (Vertical on the right edge)
        if (maxTabs > 1) {
            float shiftX = 0.0f;
            if (state.system.micActive && state.system.cameraActive) {
                shiftX = 30.0f * scale;
            } else if (state.system.micActive || state.system.cameraActive) {
                shiftX = 16.0f * scale;
            }
            const float dotX = rect.right - 10.0f * scale - shiftX;
            const float dotY = (rect.top + rect.bottom) * 0.5f;
            const float spacing = 8.0f * scale;
            const float r = 2.5f * scale;
            
            ComPtr<ID2D1SolidColorBrush> activeDot, inactiveDot;
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.85f * settingsOpacity_), &activeDot);
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.25f * settingsOpacity_), &inactiveDot);

            float startY = dotY - (spacing * (maxTabs - 1)) * 0.5f;
            for (int i = 0; i < maxTabs; ++i) {
                target_->FillEllipse(
                    D2D1::Ellipse(D2D1::Point2F(dotX, startY + spacing * i), r, r),
                    (i == tabIdx) ? activeDot.Get() : inactiveDot.Get()
                );
            }
        }

        target_->PopAxisAlignedClip();
    }

    void DrawGameOverlay(const SharedState& state, D2D1_RECT_F rect, float unused_scale) {
        const float scale = 1.0f;
        ComPtr<ID2D1SolidColorBrush> panelBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.080f * settingsOpacity_), &panelBrush);

        D2D1_RECT_F fpsPanel = D2D1::RectF(rect.left + 10.0f * scale, rect.top + 10.0f * scale,
                                          rect.left + 84.0f * scale, rect.bottom - 10.0f * scale);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fpsPanel, 15.0f * scale, 15.0f * scale), panelBrush.Get());

        ComPtr<ID2D1SolidColorBrush> fpsIconBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 1.0f, 0.65f, 1.0f), &fpsIconBrush);
        D2D1_POINT_2F fpsCenter = D2D1::Point2F(fpsPanel.left + 18.0f * scale, fpsPanel.top + 17.0f * scale);
        DrawGameIcon(fpsCenter, 7.0f * scale, 0, fpsIconBrush.Get(), scale);

        if (g_settings.showMetricText) {
            mutedBrush_->SetOpacity(0.44f);
            target_->DrawTextW(L"FPS", 3, smallTextFormat_.Get(),
                               D2D1::RectF(fpsPanel.left + 31.0f * scale, fpsPanel.top + 6.0f * scale,
                                           fpsPanel.right - 10.0f * scale, fpsPanel.top + 24.0f * scale),
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        wchar_t fpsValue[16] = {};
        swprintf_s(fpsValue, L"%d", state.system.renderFps);
        textBrush_->SetOpacity(0.96f);
        D2D1_RECT_F fpsValueRect = g_settings.showMetricText 
            ? D2D1::RectF(fpsPanel.left + 16.0f * scale, fpsPanel.top + 23.0f * scale, fpsPanel.right - 10.0f * scale, fpsPanel.bottom - 4.0f * scale)
            : D2D1::RectF(fpsPanel.left + 31.0f * scale, fpsPanel.top + 10.0f * scale, fpsPanel.right - 10.0f * scale, fpsPanel.bottom - 4.0f * scale);
        target_->DrawTextW(fpsValue, static_cast<UINT32>(wcslen(fpsValue)), textFormat_.Get(),
                           fpsValueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        const float cardTop = rect.top + 10.0f * scale;
        const float cardW = 62.0f * scale;
        const float gap = 6.0f * scale;
        const float start = fpsPanel.right + 8.0f * scale;
        DrawGameMetricCard(D2D1::RectF(start, cardTop, start + cardW, rect.bottom - 10.0f * scale),
                           L"CPU", state.system.cpuPercent, 1, scale);
        DrawGameMetricCard(D2D1::RectF(start + cardW + gap, cardTop,
                                       start + cardW * 2.0f + gap, rect.bottom - 10.0f * scale),
                           L"RAM", state.system.memoryPercent, 2, scale);
        DrawGameMetricCard(D2D1::RectF(start + cardW * 2.0f + gap * 2.0f, cardTop,
                                       start + cardW * 3.0f + gap * 2.0f, rect.bottom - 10.0f * scale),
                           L"GPU", state.system.gpuPercent, 3, scale);
        DrawGameMetricCard(D2D1::RectF(start + cardW * 3.0f + gap * 3.0f, cardTop,
                                       start + cardW * 4.0f + gap * 3.0f, rect.bottom - 10.0f * scale),
                           L"DSK", 100 - state.system.diskFreePercent, 4, scale);

        textBrush_->SetOpacity(0.90f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawGameMetricCard(D2D1_RECT_F rect, const wchar_t* label, int percent, int iconKind, float unused_scale) {
        const float scale = 1.0f;
        D2D1_COLOR_F metricColor = D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f);
        switch (iconKind) {
            case 1:
                metricColor = D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f);
                break;
            case 2:
                metricColor = D2D1::ColorF(0.83f, 0.0f, 1.0f, 1.0f);
                break;
            case 3:
                metricColor = D2D1::ColorF(0.0f, 1.0f, 0.60f, 1.0f);
                break;
            case 4:
                metricColor = D2D1::ColorF(1.0f, 0.48f, 0.0f, 1.0f);
                break;
            default:
                metricColor = D2D1::ColorF(0.0f, 1.0f, 0.65f, 1.0f);
                break;
        }

        ComPtr<ID2D1SolidColorBrush> metricBrush;
        target_->CreateSolidColorBrush(metricColor, &metricBrush);

        ComPtr<ID2D1SolidColorBrush> cardBrush;
        ComPtr<ID2D1SolidColorBrush> borderBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.080f * settingsOpacity_), &cardBrush);
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.060f * settingsOpacity_), &borderBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(rect, 16.0f * scale, 16.0f * scale), cardBrush.Get());
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 16.0f * scale, 16.0f * scale), borderBrush.Get(), 1.0f * scale);

        metricBrush->SetOpacity(0.24f * settingsOpacity_);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 16.0f * scale, 16.0f * scale), metricBrush.Get(), 1.2f * scale);
        metricBrush->SetOpacity(1.0f);

        DrawGameIcon(D2D1::Point2F(rect.left + 18.0f * scale, rect.top + 18.0f * scale), 8.0f * scale, iconKind, metricBrush.Get(), scale);

        if (g_settings.showMetricText) {
            mutedBrush_->SetOpacity(0.56f);
            target_->DrawTextW(label, static_cast<UINT32>(wcslen(label)), smallTextFormat_.Get(),
                               D2D1::RectF(rect.left + 31.0f * scale, rect.top + 6.0f * scale,
                                           rect.right - 5.0f * scale, rect.top + 24.0f * scale),
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        wchar_t value[16] = {};
        if (percent < 0) {
            wcscpy_s(value, ARRAYSIZE(value), L"--");
        } else {
            swprintf_s(value, L"%d%%", percent);
        }
        textBrush_->SetOpacity(0.90f);
        D2D1_RECT_F valueRect = g_settings.showMetricText 
            ? D2D1::RectF(rect.left + 10.0f * scale, rect.top + 22.0f * scale, rect.right - 8.0f * scale, rect.bottom - 8.0f * scale)
            : D2D1::RectF(rect.left + 31.0f * scale, rect.top + 10.0f * scale, rect.right - 5.0f * scale, rect.bottom - 8.0f * scale);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(),
                           valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        const float pct = percent < 0 ? 0.0f : Clamp(percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F track = D2D1::RectF(rect.left + 10.0f * scale, rect.bottom - 6.0f * scale,
                                       rect.right - 10.0f * scale, rect.bottom - 3.0f * scale);
        borderBrush->SetOpacity(0.12f * settingsOpacity_);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 1.5f * scale, 1.5f * scale), borderBrush.Get());
        D2D1_RECT_F fillRect = D2D1::RectF(track.left, track.top,
                                          track.left + (track.right - track.left) * pct,
                                          track.bottom);
        metricBrush->SetOpacity(0.85f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fillRect, 1.5f * scale, 1.5f * scale), metricBrush.Get());
        metricBrush->SetOpacity(1.0f);
    }

    void DrawGameIcon(D2D1_POINT_2F center, float radius, int kind, ID2D1SolidColorBrush* customBrush = nullptr, float unused_scale = 1.0f) {
        const float scale = 1.0f;
        ID2D1SolidColorBrush* brush = customBrush ? customBrush : accentBrush_.Get();
        brush->SetOpacity(0.88f);
        switch (kind) {
            case 1: {
                const float size = radius * 0.82f;
                D2D1_RECT_F outerRect = D2D1::RectF(center.x - size, center.y - size, center.x + size, center.y + size);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(outerRect, 2.0f * scale, 2.0f * scale), brush, 1.4f * scale);
                const float dieSize = size * 0.45f;
                D2D1_RECT_F dieRect = D2D1::RectF(center.x - dieSize, center.y - dieSize, center.x + dieSize, center.y + dieSize);
                target_->FillRoundedRectangle(D2D1::RoundedRect(dieRect, 1.0f * scale, 1.0f * scale), brush);
                const float pinLength = 2.0f * scale;
                const float pinSpacing = size * 0.45f;
                for (float offset = -pinSpacing; offset <= pinSpacing + 0.1f * scale; offset += pinSpacing) {
                    target_->DrawLine(D2D1::Point2F(center.x + offset, center.y - size),
                                      D2D1::Point2F(center.x + offset, center.y - size - pinLength),
                                      brush, 1.0f * scale);
                    target_->DrawLine(D2D1::Point2F(center.x + offset, center.y + size),
                                      D2D1::Point2F(center.x + offset, center.y + size + pinLength),
                                      brush, 1.0f * scale);
                    target_->DrawLine(D2D1::Point2F(center.x - size, center.y + offset),
                                      D2D1::Point2F(center.x - size - pinLength, center.y + offset),
                                      brush, 1.0f * scale);
                    target_->DrawLine(D2D1::Point2F(center.x + size, center.y + offset),
                                      D2D1::Point2F(center.x + size + pinLength, center.y + offset),
                                      brush, 1.0f * scale);
                }
                break;
            }
            case 2: {
                const float w = radius * 1.15f;
                const float h = radius * 0.45f;
                D2D1_RECT_F pcb = D2D1::RectF(center.x - w, center.y - h, center.x + w, center.y + h);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(pcb, 1.0f * scale, 1.0f * scale), brush, 1.3f * scale);
                const float chipW = (w * 2.0f - 6.0f * scale) / 3.0f;
                const float chipH = h * 0.65f;
                for (int i = 0; i < 3; ++i) {
                    float cx = center.x - w + 2.0f * scale + i * (chipW + 1.0f * scale);
                    D2D1_RECT_F chip = D2D1::RectF(cx, center.y - chipH, cx + chipW, center.y + chipH);
                    target_->FillRectangle(chip, brush);
                }
                const float pinY = center.y + h;
                for (float px = center.x - w + 2.0f * scale; px <= center.x + w - 2.0f * scale; px += 2.2f * scale) {
                    target_->DrawLine(D2D1::Point2F(px, pinY),
                                      D2D1::Point2F(px, pinY + 1.2f * scale),
                                      brush, 0.9f * scale);
                }
                break;
            }
            case 3: {
                const float w = radius * 1.1f;
                const float h = radius * 0.7f;
                D2D1_RECT_F shroud = D2D1::RectF(center.x - w, center.y - h, center.x + w, center.y + h);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(shroud, 1.5f * scale, 1.5f * scale), brush, 1.3f * scale);
                target_->DrawLine(D2D1::Point2F(center.x - w - 1.5f * scale, center.y - h - 1.0f * scale),
                                  D2D1::Point2F(center.x - w - 1.5f * scale, center.y + h + 1.0f * scale),
                                  brush, 1.4f * scale);
                const float fanR = h * 0.75f;
                target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, center.y), fanR, fanR), brush, 1.2f * scale);
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, center.y), 1.5f * scale, 1.5f * scale), brush);
                for (int i = 0; i < 4; ++i) {
                    float angle = i * 3.14159f / 4.0f;
                    float dx = std::cos(angle) * fanR;
                    float dy = std::sin(angle) * fanR;
                    target_->DrawLine(D2D1::Point2F(center.x - dx, center.y - dy),
                                      D2D1::Point2F(center.x + dx, center.y + dy),
                                      brush, 0.8f * scale);
                }
                target_->DrawLine(D2D1::Point2F(center.x - w + 3.0f * scale, center.y + h + 1.2f * scale),
                                  D2D1::Point2F(center.x + w - 2.0f * scale, center.y + h + 1.2f * scale),
                                  brush, 1.0f * scale);
                break;
            }
            case 4: {
                const float w = radius * 0.85f;
                const float h = radius * 1.05f;
                D2D1_RECT_F enc = D2D1::RectF(center.x - w, center.y - h, center.x + w, center.y + h);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(enc, 2.0f * scale, 2.0f * scale), brush, 1.3f * scale);
                const float platR = w * 0.82f;
                const float platY = center.y + h - platR - 2.0f * scale;
                target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, platY), platR, platR), brush, 1.2f * scale);
                target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, platY), 2.0f * scale, 2.0f * scale), brush, 1.0f * scale);
                const float pivotX = center.x - w + 3.0f * scale;
                const float pivotY = center.y - h + 3.5f * scale;
                target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(pivotX, pivotY), 1.5f * scale, 1.5f * scale), brush);
                target_->DrawLine(D2D1::Point2F(pivotX, pivotY),
                                  D2D1::Point2F(center.x + 1.0f * scale, platY - 1.0f * scale),
                                  brush, 1.1f * scale);
                break;
            }
            case 0:
            default: {
                const float dialR = radius * 1.05f;
                target_->DrawEllipse(D2D1::Ellipse(center, dialR, dialR), brush, 1.3f * scale);
                for (int i = 0; i < 5; ++i) {
                    float angle = -3.14159f * 0.8f + i * 3.14159f * 0.4f;
                    float dx1 = std::cos(angle) * dialR;
                    float dy1 = std::sin(angle) * dialR;
                    float dx2 = std::cos(angle) * (dialR - 2.0f * scale);
                    float dy2 = std::sin(angle) * (dialR - 2.0f * scale);
                    target_->DrawLine(D2D1::Point2F(center.x + dx1, center.y + dy1),
                                      D2D1::Point2F(center.x + dx2, center.y + dy2),
                                      brush, 0.9f * scale);
                }
                target_->FillEllipse(D2D1::Ellipse(center, 1.6f * scale, 1.6f * scale), brush);
                const float needleAngle = -3.14159f * 0.25f;
                const float needleLen = dialR * 0.85f;
                target_->DrawLine(center,
                                  D2D1::Point2F(center.x + std::cos(needleAngle) * needleLen,
                                                center.y + std::sin(needleAngle) * needleLen),
                                  brush, 1.4f * scale);
                break;
            }
        }
        brush->SetOpacity(1.0f);
    }

    void DrawPageDots(D2D1_RECT_F rect, int active, int count, float unused_scale) {
        const float scale = 1.0f;
        const float gap = 6.0f * scale;
        const float total = count * 3.0f * scale + (count - 1) * gap;
        const float start = (rect.left + rect.right - total) * 0.5f;
        const float y = rect.bottom - 7.0f * scale;
        for (int i = 0; i < count; ++i) {
            mutedBrush_->SetOpacity(i == active ? 0.45f : 0.16f);
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(start + i * (3.0f * scale + gap), y),
                                               (i == active ? 2.0f : 1.5f) * scale,
                                               (i == active ? 2.0f : 1.5f) * scale),
                                 mutedBrush_.Get());
        }
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawMetricChip(const SharedState& state, D2D1_RECT_F rect, const wchar_t* label, int percent, int iconKind) {
        const float scale = 1.0f;
        D2D1_COLOR_F metricColor = D2D1::ColorF(0.0f, 0.82f, 1.0f, 1.0f);
        switch (iconKind) {
            case 1: {
                if (state.battery.low) {
                    metricColor = D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f);
                } else if (state.system.charging) {
                    metricColor = D2D1::ColorF(1.0f, 0.80f, 0.0f, 1.0f);
                } else {
                    metricColor = D2D1::ColorF(0.0f, 0.90f, 0.50f, 1.0f);
                }
                break;
            }
            case 2:
                metricColor = D2D1::ColorF(0.0f, 0.65f, 1.0f, 1.0f);
                break;
            case 3:
            default:
                metricColor = D2D1::ColorF(0.83f, 0.0f, 1.0f, 1.0f);
                break;
        }

        ComPtr<ID2D1SolidColorBrush> metricBrush;
        target_->CreateSolidColorBrush(metricColor, &metricBrush);

        ComPtr<ID2D1SolidColorBrush> chipBg;
        ComPtr<ID2D1SolidColorBrush> chipBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.070f * settingsOpacity_), &chipBg);
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.060f * settingsOpacity_), &chipBorder);
        target_->FillRoundedRectangle(D2D1::RoundedRect(rect, 11.0f * scale, 11.0f * scale), chipBg.Get());
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 11.0f * scale, 11.0f * scale), chipBorder.Get(), 1.0f * scale);

        metricBrush->SetOpacity(0.24f * settingsOpacity_);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(rect, 11.0f * scale, 11.0f * scale), metricBrush.Get(), 1.2f * scale);
        metricBrush->SetOpacity(1.0f);

        D2D1_POINT_2F iconCenter = D2D1::Point2F(rect.left + 14.5f * scale, rect.top + 13.0f * scale);
        const float radius = 5.5f * scale;
        
        switch (iconKind) {
            case 1: {
                const float w = 6.2f * scale;
                const float h = 3.4f * scale;
                D2D1_RECT_F batBody = D2D1::RectF(iconCenter.x - w, iconCenter.y - h, iconCenter.x + w - 1.2f * scale, iconCenter.y + h);
                metricBrush->SetOpacity(0.85f);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(batBody, 0.8f * scale, 0.8f * scale), metricBrush.Get(), 1.1f * scale);
                
                D2D1_RECT_F batTip = D2D1::RectF(iconCenter.x + w - 1.2f * scale, iconCenter.y - h * 0.45f, iconCenter.x + w, iconCenter.y + h * 0.45f);
                target_->FillRoundedRectangle(D2D1::RoundedRect(batTip, 0.4f * scale, 0.4f * scale), metricBrush.Get());
                
                const float fillPercent = percent < 0 ? 0.0f : Clamp(percent / 100.0f, 0.0f, 1.0f);
                const float fillW = (batBody.right - batBody.left - 2.0f * scale) * fillPercent;
                if (fillW > 0.5f * scale) {
                    D2D1_RECT_F batFill = D2D1::RectF(batBody.left + 1.0f * scale, batBody.top + 1.0f * scale, batBody.left + 1.0f * scale + fillW, batBody.bottom - 1.0f * scale);
                    target_->FillRoundedRectangle(D2D1::RoundedRect(batFill, 0.4f * scale, 0.4f * scale), metricBrush.Get());
                }
                
                if (state.system.charging) {
                    ComPtr<ID2D1SolidColorBrush> boltBrush;
                    target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.85f, 0.0f, 1.0f), &boltBrush);
                    D2D1_POINT_2F p1 = D2D1::Point2F(iconCenter.x - 0.8f * scale, iconCenter.y - 3.2f * scale);
                    D2D1_POINT_2F p2 = D2D1::Point2F(iconCenter.x - 1.6f * scale, iconCenter.y + 0.3f * scale);
                    D2D1_POINT_2F p3 = D2D1::Point2F(iconCenter.x - 0.4f * scale, iconCenter.y + 0.3f * scale);
                    D2D1_POINT_2F p4 = D2D1::Point2F(iconCenter.x - 1.2f * scale, iconCenter.y + 3.6f * scale);
                    D2D1_POINT_2F p5 = D2D1::Point2F(iconCenter.x + 0.6f * scale, iconCenter.y - 0.1f * scale);
                    D2D1_POINT_2F p6 = D2D1::Point2F(iconCenter.x - 0.4f * scale, iconCenter.y - 0.1f * scale);
                    ComPtr<ID2D1PathGeometry> boltGeom;
                    d2dFactory_->CreatePathGeometry(&boltGeom);
                    ComPtr<ID2D1GeometrySink> sink;
                    if (SUCCEEDED(boltGeom->Open(&sink))) {
                        sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
                        sink->AddLine(p2);
                        sink->AddLine(p3);
                        sink->AddLine(p4);
                        sink->AddLine(p5);
                        sink->AddLine(p6);
                        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
                        sink->Close();
                        target_->FillGeometry(boltGeom.Get(), boltBrush.Get());
                        ComPtr<ID2D1SolidColorBrush> outline;
                        target_->CreateSolidColorBrush(D2D1::ColorF(0.0f, 0.0f, 0.0f, 0.8f), &outline);
                        target_->DrawGeometry(boltGeom.Get(), outline.Get(), 0.5f * scale);
                    }
                }
                break;
            }
            case 2: {
                D2D1_RECT_F spkBox = D2D1::RectF(iconCenter.x - radius * 0.95f, iconCenter.y - radius * 0.45f, iconCenter.x - radius * 0.35f, iconCenter.y + radius * 0.45f);
                target_->FillRoundedRectangle(D2D1::RoundedRect(spkBox, 0.5f * scale, 0.5f * scale), metricBrush.Get());
                
                ComPtr<ID2D1PathGeometry> coneGeom;
                d2dFactory_->CreatePathGeometry(&coneGeom);
                ComPtr<ID2D1GeometrySink> coneSink;
                if (SUCCEEDED(coneGeom->Open(&coneSink))) {
                    coneSink->BeginFigure(D2D1::Point2F(iconCenter.x - radius * 0.35f, iconCenter.y - radius * 0.45f), D2D1_FIGURE_BEGIN_FILLED);
                    coneSink->AddLine(D2D1::Point2F(iconCenter.x + radius * 0.15f, iconCenter.y - radius * 0.85f));
                    coneSink->AddLine(D2D1::Point2F(iconCenter.x + radius * 0.15f, iconCenter.y + radius * 0.85f));
                    coneSink->AddLine(D2D1::Point2F(iconCenter.x - radius * 0.35f, iconCenter.y + radius * 0.45f));
                    coneSink->EndFigure(D2D1_FIGURE_END_CLOSED);
                    coneSink->Close();
                    target_->FillGeometry(coneGeom.Get(), metricBrush.Get());
                }
                
                if (state.system.volumeMuted) {
                    const float off = radius * 0.35f;
                    const float xCenter = iconCenter.x + radius * 0.60f;
                    target_->DrawLine(D2D1::Point2F(xCenter - off, iconCenter.y - off),
                                      D2D1::Point2F(xCenter + off, iconCenter.y + off),
                                      metricBrush.Get(), 1.2f * scale);
                    target_->DrawLine(D2D1::Point2F(xCenter - off, iconCenter.y + off),
                                      D2D1::Point2F(xCenter + off, iconCenter.y - off),
                                      metricBrush.Get(), 1.2f * scale);
                } else {
                    const float xCenter = iconCenter.x + radius * 0.15f;
                    if (percent > 0) {
                        ComPtr<ID2D1PathGeometry> wave1;
                        d2dFactory_->CreatePathGeometry(&wave1);
                        ComPtr<ID2D1GeometrySink> sink1;
                        if (SUCCEEDED(wave1->Open(&sink1))) {
                            sink1->BeginFigure(D2D1::Point2F(xCenter + radius * 0.28f, iconCenter.y - radius * 0.38f), D2D1_FIGURE_BEGIN_HOLLOW);
                            sink1->AddBezier(D2D1::BezierSegment(
                                D2D1::Point2F(xCenter + radius * 0.5f, iconCenter.y - radius * 0.18f),
                                D2D1::Point2F(xCenter + radius * 0.5f, iconCenter.y + radius * 0.18f),
                                D2D1::Point2F(xCenter + radius * 0.28f, iconCenter.y + radius * 0.38f)
                            ));
                            sink1->EndFigure(D2D1_FIGURE_END_OPEN);
                            sink1->Close();
                            target_->DrawGeometry(wave1.Get(), metricBrush.Get(), 1.2f * scale);
                        }
                    }
                    if (percent > 50) {
                        ComPtr<ID2D1PathGeometry> wave2;
                        d2dFactory_->CreatePathGeometry(&wave2);
                        ComPtr<ID2D1GeometrySink> sink2;
                        if (SUCCEEDED(wave2->Open(&sink2))) {
                            sink2->BeginFigure(D2D1::Point2F(xCenter + radius * 0.55f, iconCenter.y - radius * 0.72f), D2D1_FIGURE_BEGIN_HOLLOW);
                            sink2->AddBezier(D2D1::BezierSegment(
                                D2D1::Point2F(xCenter + radius * 0.88f, iconCenter.y - radius * 0.35f),
                                D2D1::Point2F(xCenter + radius * 0.88f, iconCenter.y + radius * 0.35f),
                                D2D1::Point2F(xCenter + radius * 0.55f, iconCenter.y + radius * 0.72f)
                            ));
                            sink2->EndFigure(D2D1_FIGURE_END_OPEN);
                            sink2->Close();
                            target_->DrawGeometry(wave2.Get(), metricBrush.Get(), 1.2f * scale);
                        }
                    }
                }
                break;
            }
            case 3:
            default: {
                const float size = radius * 0.78f;
                D2D1_RECT_F outerRect = D2D1::RectF(iconCenter.x - size, iconCenter.y - size, iconCenter.x + size, iconCenter.y + size);
                target_->DrawRoundedRectangle(D2D1::RoundedRect(outerRect, 1.5f * scale, 1.5f * scale), metricBrush.Get(), 1.1f * scale);
                
                const float dieSize = size * 0.42f;
                D2D1_RECT_F dieRect = D2D1::RectF(iconCenter.x - dieSize, iconCenter.y - dieSize, iconCenter.x + dieSize, iconCenter.y + dieSize);
                target_->FillRoundedRectangle(D2D1::RoundedRect(dieRect, 0.5f * scale, 0.5f * scale), metricBrush.Get());
                
                const float pinLength = 1.6f * scale;
                const float pinSpacing = size * 0.5f;
                for (float offset = -pinSpacing; offset <= pinSpacing + 0.1f; offset += pinSpacing * 2.0f) {
                    target_->DrawLine(D2D1::Point2F(iconCenter.x + offset, iconCenter.y - size),
                                      D2D1::Point2F(iconCenter.x + offset, iconCenter.y - size - pinLength),
                                      metricBrush.Get(), 0.9f * scale);
                    target_->DrawLine(D2D1::Point2F(iconCenter.x + offset, iconCenter.y + size),
                                      D2D1::Point2F(iconCenter.x + offset, iconCenter.y + size + pinLength),
                                      metricBrush.Get(), 0.9f * scale);
                    target_->DrawLine(D2D1::Point2F(iconCenter.x - size, iconCenter.y + offset),
                                      D2D1::Point2F(iconCenter.x - size - pinLength, iconCenter.y + offset),
                                      metricBrush.Get(), 0.9f * scale);
                    target_->DrawLine(D2D1::Point2F(iconCenter.x + size, iconCenter.y + offset),
                                      D2D1::Point2F(iconCenter.x + size + pinLength, iconCenter.y + offset),
                                      metricBrush.Get(), 0.9f * scale);
                }
                break;
            }
        }

        if (g_settings.showMetricText) {
            D2D1_RECT_F labelRect = D2D1::RectF(rect.left + 23.0f * scale, rect.top + 3.0f * scale, rect.right - 2.0f * scale, rect.top + 20.0f * scale);
            mutedBrush_->SetOpacity(0.48f);
            target_->DrawTextW(label, static_cast<UINT32>(wcslen(label)), smallTextFormat_.Get(), labelRect,
                               mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);
        }

        wchar_t value[16] = {};
        if (percent < 0) {
            wcscpy_s(value, ARRAYSIZE(value), L"--");
        } else {
            swprintf_s(value, L"%d%%", percent);
        }
        textBrush_->SetOpacity(0.90f);
        D2D1_RECT_F valueRect = g_settings.showMetricText
            ? D2D1::RectF(rect.left + 7.5f * scale, rect.top + 14.5f * scale, rect.right - 2.0f * scale, rect.bottom - 8.0f * scale)
            : D2D1::RectF(rect.left + 23.0f * scale, rect.top + 8.0f * scale, rect.right - 2.0f * scale, rect.bottom - 8.0f * scale);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(),
                           valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_NONE);

        const float clamped = percent < 0 ? 0.0f : Clamp(percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F meterTrack = D2D1::RectF(rect.left + 8.0f * scale, rect.bottom - 6.0f * scale, rect.right - 8.0f * scale, rect.bottom - 4.0f * scale);
        chipBorder->SetOpacity(0.12f * settingsOpacity_);
        target_->FillRoundedRectangle(D2D1::RoundedRect(meterTrack, 1.0f * scale, 1.0f * scale), chipBorder.Get());
        
        D2D1_RECT_F meterFill = D2D1::RectF(meterTrack.left, meterTrack.top,
                                           meterTrack.left + (meterTrack.right - meterTrack.left) * clamped,
                                           meterTrack.bottom);
        metricBrush->SetOpacity(0.85f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(meterFill, 1.0f * scale, 1.0f * scale), metricBrush.Get());
        
        textBrush_->SetOpacity(0.90f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawMiniUsageBars(D2D1_RECT_F rect, int memory, int cpu) {
        const int bars = 18;
        const float gap = 3.0f;
        const float barWidth = ((rect.right - rect.left) - gap * (bars - 1)) / bars;
        for (int i = 0; i < bars; ++i) {
            const float mix = i / static_cast<float>(bars - 1);
            const float value = (memory * (1.0f - mix) + cpu * mix) / 100.0f;
            const float x = rect.left + i * (barWidth + gap);
            const float h = 2.0f + value * (rect.bottom - rect.top);
            accentBrush_->SetOpacity(0.18f + 0.38f * value);
            target_->FillRoundedRectangle(
                D2D1::RoundedRect(D2D1::RectF(x, rect.bottom - h, x + barWidth, rect.bottom),
                                  barWidth * 0.5f, barWidth * 0.5f),
                accentBrush_.Get());
        }
        accentBrush_->SetOpacity(1.0f);
    }

    void DrawMedia(const SharedState& state, D2D1_RECT_F rect, double now) {
        const float height = rect.bottom - rect.top;

        float radius = g_settings.w11Style ? 8.0f * g_settings.sizeScale : height * 0.5f;
        if (g_settings.notchStyle) {
            radius = 16.0f * g_settings.sizeScale;
        } else if (!g_settings.w11Style) {
            radius = std::min(radius, 44.0f * g_settings.sizeScale);
        }
        ComPtr<ID2D1Geometry> mask = CreateIslandMaskGeometry(rect, radius, g_settings.notchStyle);
        ComPtr<ID2D1Layer> layer;
        target_->CreateLayer(&layer);

        float expandedAlpha = std::clamp((height - 60.0f) / 60.0f, 0.0f, 1.0f);
        float collapsedAlpha = std::clamp((80.0f - height) / 30.0f, 0.0f, 1.0f);

        // Expanded UI
        if (expandedAlpha > 0.01f && mask && layer) {
            target_->PushLayer(D2D1::LayerParameters(rect, mask.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, D2D1::IdentityMatrix(), expandedAlpha, nullptr, D2D1_LAYER_OPTIONS_NONE), layer.Get());
            
            int tab = g_idleTab % 3;
            if (tab < 0) tab += 3;

            if (tab == 0) {
                // Expanded Apple DI media: large square art on left, text center.
                const float artSize = 64.0f;
                D2D1_RECT_F artRect = D2D1::RectF(rect.left + 24.0f, rect.top + 20.0f,
                                                  rect.left + 24.0f + artSize, rect.top + 20.0f + artSize);
                DrawAlbumArt(state.media, artRect, now, 16.0f, true);

                float shiftX = 0.0f;
                if (state.system.micActive && state.system.cameraActive) {
                    shiftX = 30.0f;
                } else if (state.system.micActive || state.system.cameraActive) {
                    shiftX = 16.0f;
                }

                const float waveW = 32.0f;
                const float waveH = 20.0f;
                D2D1_RECT_F waveRect = D2D1::RectF(rect.right - 24.0f - shiftX - waveW,
                                                   rect.top + 20.0f + (artSize - waveH) * 0.5f,
                                                   rect.right - 24.0f - shiftX,
                                                   rect.top + 20.0f + (artSize + waveH) * 0.5f);

                const float textLeft = artRect.right + 18.0f;
                const float textRight = waveRect.left - 16.0f;
                
                // Title — bold, prominent.
                D2D1_RECT_F titleRect = D2D1::RectF(textLeft, rect.top + 34.0f, textRight, rect.top + 54.0f);
                DrawMarqueeText(state.media.title.empty() ? L"Unknown" : state.media.title,
                                titleRect, textFormat_.Get(), textBrush_.Get(), now, 42.0f);

                // Artist — muted below title.
                D2D1_RECT_F artistRect = D2D1::RectF(textLeft, rect.top + 54.0f, textRight, rect.top + 74.0f);
                mutedBrush_->SetOpacity(0.55f);
                DrawMarqueeText(state.media.artist.empty() ? L"" : state.media.artist,
                                artistRect, smallTextFormat_.Get(), mutedBrush_.Get(), now, 30.0f);
                mutedBrush_->SetOpacity(0.50f);

                if (!state.media.albumTitle.empty()) {
                    D2D1_RECT_F albumRect = D2D1::RectF(textLeft, rect.top + 68.0f, textRight, rect.top + 84.0f);
                    mutedBrush_->SetOpacity(0.40f);
                    DrawMarqueeText(state.media.albumTitle, albumRect, smallTextFormat_.Get(),
                                    mutedBrush_.Get(), now, 28.0f);
                    mutedBrush_->SetOpacity(0.50f);
                }

                if (state.media.playing) {
                    DrawWaveform(state, waveRect);
                } else {
                    mutedBrush_->SetOpacity(0.5f);
                    for (int i = 0; i < 4; ++i) {
                        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(waveRect.left + i * 4.0f + 2.0f, (waveRect.top + waveRect.bottom) * 0.5f), 1.2f, 1.2f), mutedBrush_.Get());
                    }
                }

                // Timeline (Scrubber)
                const float scrubberY = rect.top + 114.0f;
                double currentPosition = state.media.positionTicks / 10000000.0;
                double duration = state.media.endTicks / 10000000.0;
                if (state.media.playing && state.media.lastUpdatedTicks > 0) {
                    currentPosition += (GetTickCount64() - state.media.lastUpdatedTicks) / 1000.0;
                }
                currentPosition = std::max(0.0, std::min(currentPosition, duration));

                auto FormatTime = [](double seconds) -> std::wstring {
                    if (seconds <= 0.0 || _isnan(seconds)) return L"0:00";
                    int m = static_cast<int>(seconds) / 60;
                    int s = static_cast<int>(seconds) % 60;
                    wchar_t buf[16];
                    swprintf_s(buf, L"%d:%02d", m, s);
                    return buf;
                };

                std::wstring elapsedStr = FormatTime(currentPosition);
                std::wstring remainStr = L"-" + FormatTime(duration - currentPosition);

                const float scrubLeft = rect.left + 24.0f;
                const float scrubRight = rect.right - 24.0f;
                
                mutedBrush_->SetOpacity(0.8f);
                D2D1_RECT_F elRect = D2D1::RectF(scrubLeft, scrubberY - 8.0f, scrubLeft + 40.0f, scrubberY + 8.0f);
                target_->DrawTextW(elapsedStr.c_str(), static_cast<UINT32>(elapsedStr.size()), smallTextFormat_.Get(), elRect, mutedBrush_.Get());
                
                D2D1_RECT_F remRect = D2D1::RectF(scrubRight - 36.0f, scrubberY - 8.0f, scrubRight, scrubberY + 8.0f);
                target_->DrawTextW(remainStr.c_str(), static_cast<UINT32>(remainStr.size()), smallTextFormat_.Get(), remRect, mutedBrush_.Get());

                const float barLeft = scrubLeft + 36.0f;
                const float barRight = scrubRight - 38.0f;
                const float progress = duration > 0.0 ? static_cast<float>(currentPosition / duration) : 0.0f;

                ComPtr<ID2D1SolidColorBrush> scrubBg;
                target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.15f), &scrubBg);
                target_->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(barLeft, scrubberY - 2.5f, barRight, scrubberY + 2.5f), 2.5f, 2.5f), scrubBg.Get());

                ComPtr<ID2D1SolidColorBrush> scrubFg;
                target_->CreateSolidColorBrush(state.media.art.bgra.empty() ? D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.9f) : state.media.art.sampledAccent, &scrubFg);
                const float scrubW = (barRight - barLeft) * progress;
                target_->FillRoundedRectangle(D2D1::RoundedRect(D2D1::RectF(barLeft, scrubberY - 2.5f, barLeft + scrubW, scrubberY + 2.5f), 2.5f, 2.5f), scrubFg.Get());

                // Controls
                const float cy = rect.top + 148.0f;
                const float cx = (rect.left + rect.right) * 0.5f;
                DrawMediaControls(state.media.playing, 
                                  D2D1::Point2F(cx - 64.0f, cy),
                                  D2D1::Point2F(cx, cy),
                                  D2D1::Point2F(cx + 64.0f, cy));
            } else if (tab == 1) {
                SYSTEMTIME local = {}; GetLocalTime(&local);
                DrawCalendarDashboard(state, rect, g_settings, now, 1.0f, local);
            } else if (tab == 2) {
                bool hasWeather = state.weather.hasData && (now - state.weather.lastUpdated < 3600.0);
                std::wstring wIcon = L"🌡️"; std::wstring wText = L"Loading...";
                if (hasWeather) {
                    wText = state.weather.weatherDesc;
                    GetWeatherIconAndText(state.weather.weatherCode, wIcon, wText);
                }
                DrawWeatherDashboard(state, rect, g_settings, now, 1.0f, hasWeather, wIcon, wText);
            }

            // Pagination dots (Vertical on the right edge)
            const float scale = 1.0f;
            float shiftX = 0.0f;
            if (state.system.micActive && state.system.cameraActive) {
                shiftX = 30.0f * scale;
            } else if (state.system.micActive || state.system.cameraActive) {
                shiftX = 16.0f * scale;
            }
            const float dotX = rect.right - 10.0f * scale - shiftX;
            const float dotY = (rect.top + rect.bottom) * 0.5f;
            const float spacing = 8.0f * scale;
            const float r = 2.5f * scale;
            
            ComPtr<ID2D1SolidColorBrush> activeDot, inactiveDot;
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.85f * settingsOpacity_), &activeDot);
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.25f * settingsOpacity_), &inactiveDot);

            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY - spacing), r, r), tab == 0 ? activeDot.Get() : inactiveDot.Get());
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY), r, r), tab == 1 ? activeDot.Get() : inactiveDot.Get());
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY + spacing), r, r), tab == 2 ? activeDot.Get() : inactiveDot.Get());

            target_->PopLayer();
        }

        // Collapsed UI
        if (collapsedAlpha > 0.01f && mask && layer) {
            g_idleTab = 0;
            target_->PushLayer(D2D1::LayerParameters(rect, mask.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, D2D1::IdentityMatrix(), collapsedAlpha, nullptr, D2D1_LAYER_OPTIONS_NONE), layer.Get());
            
            const float cy = (rect.top + rect.bottom) * 0.5f;
            const float artPadding = 6.0f;
            const float artSize = height - artPadding * 2.0f;
            
            D2D1_RECT_F artRect = D2D1::RectF(rect.left + 8.0f, cy - artSize * 0.5f,
                                              rect.left + 8.0f + artSize, cy + artSize * 0.5f);
            DrawAlbumArt(state.media, artRect, now, artSize * 0.5f, false);

            float shiftX = 0.0f;
            if (state.system.micActive && state.system.cameraActive) {
                shiftX = 30.0f;
            } else if (state.system.micActive || state.system.cameraActive) {
                shiftX = 16.0f;
            }

            D2D1_RECT_F waveRect = D2D1::RectF(rect.right - 42.0f - shiftX, cy - 10.0f,
                                               rect.right - 14.0f - shiftX, cy + 10.0f);
            if (state.media.playing) {
                DrawWaveform(state, waveRect);
            } else {
                mutedBrush_->SetOpacity(0.5f);
                for (int i = 0; i < 4; ++i) {
                    target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(waveRect.left + i * 6.0f + 3.0f, cy), 1.5f, 1.5f), mutedBrush_.Get());
                }
            }

            target_->PopLayer();
        }
    }

    void DrawMediaControls(bool playing, D2D1_POINT_2F prev, D2D1_POINT_2F play, D2D1_POINT_2F next) {
        DrawMediaButton(prev, 16.0f, 0, false);
        DrawMediaButton(play, 22.0f, playing ? 1 : 2, true);
        DrawMediaButton(next, 16.0f, 3, false);
    }

    void DrawMediaButton(D2D1_POINT_2F center, float radius, int kind, bool primary) {
        int buttonCmd = (kind == 0) ? 0 : ((kind == 1 || kind == 2) ? 1 : 2);
        bool isPressed = (g_pressedMediaButton.load() == buttonCmd);

        if (isPressed) {
            radius *= 0.88f; // Shrink by 12% on click
        }

        ComPtr<ID2D1SolidColorBrush> bg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, primary ? (isPressed ? 0.16f : 0.080f) : (isPressed ? 0.10f : 0.040f)), &bg);
        target_->FillEllipse(D2D1::Ellipse(center, radius, radius), bg.Get());
        accentBrush_->SetOpacity(primary ? (isPressed ? 1.0f : 0.88f) : (isPressed ? 0.80f : 0.62f));

        if (kind == 1) {  // pause
            const float h = radius * 0.72f;
            target_->FillRoundedRectangle(D2D1::RoundedRect(
                                             D2D1::RectF(center.x - 4.0f, center.y - h * 0.5f,
                                                         center.x - 1.5f, center.y + h * 0.5f),
                                             1.0f, 1.0f),
                                         accentBrush_.Get());
            target_->FillRoundedRectangle(D2D1::RoundedRect(
                                             D2D1::RectF(center.x + 1.5f, center.y - h * 0.5f,
                                                         center.x + 4.0f, center.y + h * 0.5f),
                                             1.0f, 1.0f),
                                         accentBrush_.Get());
        } else {
            const float dir = kind == 0 ? -1.0f : 1.0f;
            const float tri = radius * (primary ? 0.70f : 0.62f);
            
            // The combined bounding box of the triangle and the line is not centered.
            // We apply a slight horizontal shift to perfectly center the next/prev icons inside the circle.
            const float cx = (kind == 0 || kind == 3) ? center.x - dir * radius * 0.16f : center.x;

            D2D1_POINT_2F p1 = D2D1::Point2F(cx - dir * tri * 0.35f, center.y - tri * 0.58f);
            D2D1_POINT_2F p2 = D2D1::Point2F(cx - dir * tri * 0.35f, center.y + tri * 0.58f);
            D2D1_POINT_2F p3 = D2D1::Point2F(cx + dir * tri * 0.55f, center.y);
            ComPtr<ID2D1PathGeometry> geom;
            d2dFactory_->CreatePathGeometry(&geom);
            ComPtr<ID2D1GeometrySink> sink;
            geom->Open(&sink);
            sink->BeginFigure(p1, D2D1_FIGURE_BEGIN_FILLED);
            sink->AddLine(p2);
            sink->AddLine(p3);
            sink->EndFigure(D2D1_FIGURE_END_CLOSED);
            sink->Close();
            target_->FillGeometry(geom.Get(), accentBrush_.Get());

            if (kind == 0 || kind == 3) {
                const float x = cx + dir * radius * 0.55f;
                target_->DrawLine(D2D1::Point2F(x, center.y - radius * 0.45f),
                                  D2D1::Point2F(x, center.y + radius * 0.45f),
                                  accentBrush_.Get(), 1.5f);
            }
        }

        accentBrush_->SetOpacity(1.0f);
    }

    void DrawAlbumArt(const MediaSnapshot& media, D2D1_RECT_F rect, double now, float radius = 9.0f, bool drawBadge = true) {
        ComPtr<ID2D1RoundedRectangleGeometry> mask;
        HRESULT hrMask = d2dFactory_->CreateRoundedRectangleGeometry(
            D2D1::RoundedRect(rect, radius, radius), &mask);
        ComPtr<ID2D1Layer> layer;
        HRESULT hrLayer = target_->CreateLayer(nullptr, &layer);
        const bool roundedClip = SUCCEEDED(hrMask) && SUCCEEDED(hrLayer) && mask && layer;
        if (roundedClip) {
            target_->PushLayer(D2D1::LayerParameters(rect, mask.Get()), layer.Get());
        } else {
            target_->PushAxisAlignedClip(rect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
        }

        if (!media.art.bgra.empty()) {
            if (artGeneration_ != media.art.generation || !artBitmap_) {
                D2D1_BITMAP_PROPERTIES props = D2D1::BitmapProperties(
                    D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED));
                target_->CreateBitmap(D2D1::SizeU(media.art.width, media.art.height),
                                      media.art.bgra.data(), media.art.width * 4,
                                      &props, &artBitmap_);
                artGeneration_ = media.art.generation;
            }

            D2D1_RECT_F dst = D2D1::RectF(rect.left, rect.top, rect.right, rect.bottom);
            target_->DrawBitmap(artBitmap_.Get(), dst, 1.0f,
                                D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
        } else {
            accentBrush_->SetOpacity(0.24f);
            target_->FillRoundedRectangle(D2D1::RoundedRect(rect, radius, radius), accentBrush_.Get());
            accentBrush_->SetOpacity(1.0f);
            if (!media.sourceIcon.bgra.empty()) {
                D2D1_RECT_F iconRect = D2D1::RectF(rect.left + 11, rect.top + 11,
                                                  rect.right - 11, rect.bottom - 11);
                DrawBitmapPixels(media.sourceIcon, iconRect, mediaSourceIconBitmap_,
                                 mediaSourceIconGeneration_, 0.95f);
            } else {
                target_->DrawTextW(media.sourceBadge.empty() ? L"\u25b6" : media.sourceBadge.c_str(),
                                   static_cast<UINT32>(media.sourceBadge.empty() ? 1 : media.sourceBadge.size()),
                                   textFormat_.Get(), rect, textBrush_.Get());
            }
        }

        if (drawBadge && !media.sourceIcon.bgra.empty()) {
            D2D1_RECT_F badge = D2D1::RectF(rect.right - 24, rect.bottom - 22,
                                           rect.right - 3, rect.bottom - 3);
            DrawCircularBitmapPixels(media.sourceIcon,
                                     D2D1::Point2F((badge.left + badge.right) * 0.5f,
                                                   (badge.top + badge.bottom) * 0.5f),
                                     9.5f, mediaSourceIconBitmap_,
                                     mediaSourceIconGeneration_, 0.98f);
        }

        if (roundedClip) {
            target_->PopLayer();
        } else {
            target_->PopAxisAlignedClip();
        }
    }

    void DrawBitmapPixels(const BitmapPixels& pixels, D2D1_RECT_F rect,
                          ComPtr<ID2D1Bitmap>& cache, uint64_t& cachedGeneration,
                          float opacity = 1.0f) {
        if (pixels.bgra.empty()) {
            return;
        }

        if (cachedGeneration != pixels.generation || !cache) {
            D2D1_BITMAP_PROPERTIES props = D2D1::BitmapProperties(
                D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED));
            target_->CreateBitmap(D2D1::SizeU(pixels.width, pixels.height),
                                  pixels.bgra.data(), pixels.width * 4,
                                  &props, &cache);
            cachedGeneration = pixels.generation;
        }

        if (cache) {
            target_->DrawBitmap(cache.Get(), rect, opacity, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
        }
    }

    // Draws a bitmap filling a rounded-rect badge with a small inset for polish.
    void DrawRoundedBitmapPixels(const BitmapPixels& pixels, D2D1_RECT_F badge,
                                 float cornerRadius,
                                 ComPtr<ID2D1Bitmap>& cache, uint64_t& cachedGeneration,
                                 float opacity = 1.0f) {
        if (pixels.bgra.empty()) return;

        // 2px inset so the icon has clean edges inside the badge.
        const float pad = 2.0f;
        D2D1_RECT_F iconRect = D2D1::RectF(badge.left + pad, badge.top + pad,
                                           badge.right - pad, badge.bottom - pad);
        const float innerR = std::max(0.0f, cornerRadius - pad);

        ComPtr<ID2D1RoundedRectangleGeometry> mask;
        d2dFactory_->CreateRoundedRectangleGeometry(
            D2D1::RoundedRect(iconRect, innerR, innerR), &mask);
        ComPtr<ID2D1Layer> layer;
        target_->CreateLayer(nullptr, &layer);

        if (mask && layer) {
            target_->PushLayer(
                D2D1::LayerParameters(iconRect, mask.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE),
                layer.Get());
            DrawBitmapPixels(pixels, iconRect, cache, cachedGeneration, opacity);
            target_->PopLayer();
        } else {
            DrawBitmapPixels(pixels, iconRect, cache, cachedGeneration, opacity);
        }
    }

    void DrawCircularBitmapPixels(const BitmapPixels& pixels, D2D1_POINT_2F center, float radius,
                                  ComPtr<ID2D1Bitmap>& cache, uint64_t& cachedGeneration,
                                  float opacity = 1.0f) {
        if (pixels.bgra.empty()) {
            return;
        }

        D2D1_RECT_F rect = D2D1::RectF(center.x - radius, center.y - radius,
                                      center.x + radius, center.y + radius);
        ComPtr<ID2D1EllipseGeometry> ellipse;
        d2dFactory_->CreateEllipseGeometry(D2D1::Ellipse(center, radius, radius), &ellipse);
        ComPtr<ID2D1Layer> layer;
        target_->CreateLayer(nullptr, &layer);

        if (ellipse && layer) {
            target_->PushLayer(D2D1::LayerParameters(
                                  rect, ellipse.Get(), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE),
                              layer.Get());
            DrawBitmapPixels(pixels, rect, cache, cachedGeneration, opacity);
            target_->PopLayer();
        } else {
            DrawBitmapPixels(pixels, rect, cache, cachedGeneration, opacity);
        }

        ComPtr<ID2D1SolidColorBrush> border;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &border);
        if (border) {
            target_->DrawEllipse(D2D1::Ellipse(center, radius, radius), border.Get(), 1.0f);
        }
    }

    void DrawMarqueeText(const std::wstring& text, D2D1_RECT_F rect, IDWriteTextFormat* format,
                         ID2D1Brush* brush, double now, float speed) {
        if (!format || !brush || text.empty()) {
            return;
        }

        ComPtr<IDWriteTextLayout> layout;
        dwriteFactory_->CreateTextLayout(text.c_str(), static_cast<UINT32>(text.size()),
                                         format, 2000.0f, rect.bottom - rect.top, &layout);
        DWRITE_TEXT_METRICS metrics = {};
        if (layout) {
            layout->GetMetrics(&metrics);
        }

        const float available = rect.right - rect.left;
        
        // We only want to clip horizontally so we don't bleed out of the pill.
        // We expand the vertical bounds so descenders/ascenders aren't cut off.
        D2D1_RECT_F clipRect = rect;
        clipRect.top -= 10.0f;
        clipRect.bottom += 10.0f;
        target_->PushAxisAlignedClip(clipRect, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);

        if (metrics.widthIncludingTrailingWhitespace <= available) {
            target_->DrawTextLayout(D2D1::Point2F(rect.left, rect.top), layout.Get(), brush,
                                    D2D1_DRAW_TEXT_OPTIONS_NONE);
        } else {
            const float cycle = metrics.widthIncludingTrailingWhitespace + 38.0f;
            const float offset = std::fmod(static_cast<float>(now) * speed, cycle);
            target_->DrawTextLayout(D2D1::Point2F(rect.left - offset, rect.top), layout.Get(),
                                    brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
            target_->DrawTextLayout(D2D1::Point2F(rect.left - offset + cycle, rect.top),
                                    layout.Get(), brush, D2D1_DRAW_TEXT_OPTIONS_NONE);
        }
        target_->PopAxisAlignedClip();
    }

    void DrawWaveform(const SharedState& state, D2D1_RECT_F rect) {
        const float gap = 2.5f;
        const float minBarWidth = 2.0f;
        const float availableW = rect.right - rect.left;
        size_t count = std::max<size_t>(1, static_cast<size_t>((availableW + gap) / (minBarWidth + gap)));
        count = std::min<size_t>(count, 32);

        const float barWidth = (availableW - gap * (count - 1)) / count;
        const float centerY = (rect.top + rect.bottom) * 0.5f;
        const float maxH = (rect.bottom - rect.top) * 0.86f;

        // Use a step size of 4 samples (approx 40ms) so bars aren't identical
        const size_t step = 4;

        for (size_t i = 0; i < count; ++i) {
            const size_t offset = (count - i) * step;
            const size_t source = (state.waveformWrite + state.waveform.size() - offset) %
                                  state.waveform.size();
            const float amp = Clamp(state.waveform[source], 0.03f, 1.0f);
            const float h = std::max(3.0f, amp * maxH);
            const float x = rect.left + i * (barWidth + gap);
            D2D1_RECT_F bar = D2D1::RectF(x, centerY - h * 0.5f, x + barWidth, centerY + h * 0.5f);
            accentBrush_->SetOpacity(0.45f + 0.5f * amp);
            target_->FillRoundedRectangle(D2D1::RoundedRect(bar, barWidth * 0.5f, barWidth * 0.5f),
                                         accentBrush_.Get());
        }
        accentBrush_->SetOpacity(1.0f);
    }

    void DrawClipboard(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 40.0f || rect.right - rect.left < 100.0f) return;
        const double now = NowSeconds();
        const float ttl = 2.5f;
        const float remaining = Clamp(static_cast<float>(state.clipboard.expiresAt - now), 0.0f, ttl);
        const float progress = remaining / ttl;

        D2D1_RECT_F badge = D2D1::RectF(rect.left + 12, rect.top + 10,
                                       rect.left + 50, rect.bottom - 10);
        bool fillBadge = true;
        D2D1_COLOR_F bgColor = D2D1::ColorF(1, 1, 1, 0.070f);
        if (g_settings.clipboardIconBgStyle == ClipboardIconBgStyle::Transparent) {
            fillBadge = false;
        } else if (g_settings.clipboardIconBgStyle == ClipboardIconBgStyle::Accent) {
            bgColor = g_settings.customAccent;
            bgColor.a = 0.25f;
        } else if (g_settings.clipboardIconBgStyle == ClipboardIconBgStyle::Custom) {
            bgColor = g_settings.clipboardIconBgHex;
        }

        if (fillBadge) {
            ComPtr<ID2D1SolidColorBrush> badgeBg;
            target_->CreateSolidColorBrush(bgColor, &badgeBg);
            target_->FillRoundedRectangle(D2D1::RoundedRect(badge, 13, 13), badgeBg.Get());
        }
        target_->DrawRoundedRectangle(D2D1::RoundedRect(badge, 13, 13), accentBrush_.Get(), 1.0f);

        if (!state.clipboard.appIcon.bgra.empty()) {
            DrawRoundedBitmapPixels(state.clipboard.appIcon,
                                    badge, 10.0f,
                                    clipboardIconBitmap_,
                                    clipboardIconGeneration_, 0.96f);
        } else {
            // Fallback icon when no app icon is available.
            // Use Segoe Fluent Icons for a native Windows 11 look.
            const wchar_t* glyph = state.clipboard.image ? L"\uE114" : L"\uE8C8";
            if (fillBadge && g_settings.clipboardIconBgStyle == ClipboardIconBgStyle::Default) {
                ComPtr<ID2D1SolidColorBrush> iconBg;
                const D2D1_COLOR_F iconColor = state.clipboard.image
                    ? D2D1::ColorF(0.3f, 0.3f, 0.35f, 0.90f)
                    : D2D1::ColorF(1, 1, 1, 0.055f * settingsOpacity_);
                target_->CreateSolidColorBrush(iconColor, &iconBg);
                target_->FillRoundedRectangle(D2D1::RoundedRect(badge, 13, 13), iconBg.Get());
            }
            textBrush_->SetOpacity(0.95f);
            
            // Draw glyph perfectly centered in the badge rectangle.
            if (iconFormat_) {
                iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
                iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
                target_->DrawTextW(glyph,
                                   static_cast<UINT32>(wcslen(glyph)), iconFormat_.Get(), badge,
                                   textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
                iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
                iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
            }
            
            textBrush_->SetOpacity(0.90f);
        }

        D2D1_RECT_F titleRect = D2D1::RectF(badge.right + 11, rect.top + 9,
                                           rect.right - 18, rect.top + 25);
        mutedBrush_->SetOpacity(0.48f);
        const std::wstring clipTitle =
            state.clipboard.appName.empty()
                ? (state.clipboard.image ? std::wstring(L"Image copied") : std::wstring(L"Clipboard"))
                : state.clipboard.appName + L"  \u00b7  Clipboard";
        target_->DrawTextW(clipTitle.c_str(), static_cast<UINT32>(clipTitle.size()),
                           smallTextFormat_.Get(), titleRect, mutedBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);

        D2D1_RECT_F textRect = D2D1::RectF(badge.right + 11, rect.top + 25,
                                           rect.right - 18, rect.bottom - 12);
        DrawMarqueeText(state.clipboard.text.empty() ? L"Copied" : state.clipboard.text,
                        textRect, textFormat_.Get(), textBrush_.Get(), now, 34.0f);

        D2D1_RECT_F track = D2D1::RectF(badge.right + 11, rect.bottom - 8,
                                       rect.right - 20, rect.bottom - 6);
        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &trackBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 1, 1), trackBrush.Get());
        D2D1_RECT_F fill = D2D1::RectF(track.left, track.top,
                                      track.left + (track.right - track.left) * progress,
                                      track.bottom);
        accentBrush_->SetOpacity(0.55f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fill, 1, 1), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawNotification(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 48.0f || rect.right - rect.left < 120.0f) return;
        const double now = NowSeconds();
        const float ttl = 4.0f;
        const float remaining = Clamp(static_cast<float>(state.notification.expiresAt - now), 0.0f, ttl);
        const float progress = remaining / ttl;

        const float cy = (rect.top + rect.bottom) * 0.5f;
        // Apple DI: app icon is a large iOS-style rounded square.
        const float iconSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - iconSz * 0.5f,
                                        rect.left + 14 + iconSz, cy + iconSz * 0.5f);
        const float br = iconSz * 0.35f;  // Softer iOS superellipse-like squircle.

        // Icon background plate.
        ComPtr<ID2D1SolidColorBrush> plateBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &plateBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), plateBrush.Get());

        if (!state.notification.icon.bgra.empty()) {
            DrawRoundedBitmapPixels(state.notification.icon, badge, br,
                                    notificationIconBitmap_, notificationIconGeneration_, 1.0f);

            // Draw a red dot (badge) at the top-right of the app icon
            ComPtr<ID2D1SolidColorBrush> badgeColor;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &badgeColor);
            
            const float dotR = iconSz * 0.13f;
            const float dotX = badge.right - dotR * 0.5f;
            const float dotY = badge.top + dotR * 0.5f;
            
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY), dotR, dotR), badgeColor.Get());

            ComPtr<ID2D1SolidColorBrush> badgeBorder;
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.95f), &badgeBorder);
            target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(dotX, dotY), dotR, dotR), badgeBorder.Get(), 0.9f);
        } else {
            DrawNotificationFallbackIcon(
                D2D1::Point2F((badge.left + badge.right) * 0.5f, cy), iconSz * 0.38f);
        }

        const float tx = badge.right + 14;
        // App name — small dim label.
        D2D1_RECT_F appRect = D2D1::RectF(tx, cy - 22, rect.right - 14, cy - 6);
        mutedBrush_->SetOpacity(0.50f);
        target_->DrawTextW(state.notification.app.c_str(),
                           static_cast<UINT32>(state.notification.app.size()),
                           smallTextFormat_.Get(), appRect, mutedBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);

        // Title — bold white.
        D2D1_RECT_F titleRect = D2D1::RectF(tx, cy - 4, rect.right - 14, cy + 17);
        textBrush_->SetOpacity(0.95f);
        DrawMarqueeText(state.notification.title.empty() ? L"Notification" : state.notification.title,
                        titleRect, textFormat_.Get(), textBrush_.Get(), now, 28.0f);
        textBrush_->SetOpacity(0.90f);

        // Thicker, softer progress bar at bottom.
        D2D1_RECT_F track = D2D1::RectF(tx, rect.bottom - 7, rect.right - 14, rect.bottom - 3);
        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &trackBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 2, 2), trackBrush.Get());
        D2D1_RECT_F fill = D2D1::RectF(track.left, track.top,
                                       track.left + (track.right - track.left) * progress, track.bottom);
        accentBrush_->SetOpacity(0.75f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fill, 2, 2), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
        mutedBrush_->SetOpacity(0.50f);
    }

    void DrawVolume(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 140.0f) return;
        const bool muted = state.volume.muted || state.volume.percent == 0;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f,
                                        rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f; // Softer squircle corners

        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        const wchar_t* glyph = muted ? L"\uE74F" : L"\uE993"; // Mute and Volume2 from Segoe Fluent Icons
        textBrush_->SetOpacity(0.95f);
        
        if (iconFormat_) {
            iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
            iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
            
            target_->DrawTextW(glyph, static_cast<UINT32>(wcslen(glyph)), iconFormat_.Get(), badge,
                               textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
                               
            iconFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
            iconFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
        }

        const float tx = badge.right + 14;
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 22, rect.right - 58, cy - 6);
        mutedBrush_->SetOpacity(0.50f);
        const std::wstring deviceLabel =
            state.volume.deviceName.empty() ? std::wstring(L"Volume") : state.volume.deviceName;
        target_->DrawTextW(deviceLabel.c_str(), static_cast<UINT32>(deviceLabel.size()),
                           smallTextFormat_.Get(), labelRect, mutedBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);

        wchar_t value[16] = {};
        if (muted) {
            wcscpy_s(value, ARRAYSIZE(value), L"Muted");
        } else {
            swprintf_s(value, L"%d%%", state.volume.percent);
        }
        D2D1_RECT_F valueRect = D2D1::RectF(rect.right - 58, cy - 22, rect.right - 14, cy - 6);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), smallTextFormat_.Get(),
                           valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
        textBrush_->SetOpacity(0.90f);

        D2D1_RECT_F track = D2D1::RectF(tx, cy + 2, rect.right - 14, cy + 6);
        ComPtr<ID2D1SolidColorBrush> trackBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &trackBrush);
        target_->FillRoundedRectangle(D2D1::RoundedRect(track, 2, 2), trackBrush.Get());
        const float pct = Clamp(state.volume.percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F fill = D2D1::RectF(track.left, track.top,
                                       track.left + (track.right - track.left) * pct,
                                       track.bottom);
        accentBrush_->SetOpacity(muted ? 0.24f : 0.85f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(fill, 2, 2), accentBrush_.Get());
        accentBrush_->SetOpacity(1.0f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawCapsLock(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 110.0f) return;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f,
                                        rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        // Badge Background (translucent physical keycap base)
        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.08f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        // Keycap Border for 3D visual depth
        ComPtr<ID2D1SolidColorBrush> badgeBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.16f), &badgeBorder);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBorder.Get(), 1.0f);

        const wchar_t* glyph = nullptr;
        std::wstring label;
        bool isOn = false;

        if (state.capsLock.isNumEvent) {
            glyph = L"1";
            label = L"Num Lock";
            isOn = state.capsLock.numOn;
        } else {
            glyph = L"A";
            label = L"Caps Lock";
            isOn = state.capsLock.capsOn;
        }

        // Draw central bold keycap glyph, vertically and horizontally centered
        textBrush_->SetOpacity(0.95f);
        target_->DrawTextW(glyph, static_cast<UINT32>(wcslen(glyph)), clockFormat_.Get(), badge,
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);

        // Draw physical glowing status LED inside the keycap
        ComPtr<ID2D1SolidColorBrush> ledBrush;
        D2D1_COLOR_F ledColor = isOn
            ? D2D1::ColorF(0.19f, 0.83f, 0.38f, 1.0f)   // Green glowing LED for ON
            : D2D1::ColorF(1.0f,  1.0f,  1.0f,  0.22f);  // Dim white for OFF
        target_->CreateSolidColorBrush(ledColor, &ledBrush);

        D2D1_POINT_2F ledCenter = D2D1::Point2F(badge.right - 5.0f, badge.bottom - 5.0f);
        target_->FillEllipse(D2D1::Ellipse(ledCenter, 3.0f, 3.0f), ledBrush.Get());

        // Draw label text
        const float tx = badge.right + 14;
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 10, rect.right - 40, cy + 10);
        target_->DrawTextW(label.c_str(), static_cast<UINT32>(label.size()),
                           smallTextFormat_.Get(), labelRect, textBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);

        // Draw status string (ON/OFF)
        std::wstring status = isOn ? L"ON" : L"OFF";
        D2D1_RECT_F statusRect = D2D1::RectF(rect.right - 40, cy - 10, rect.right - 14, cy + 10);
        mutedBrush_->SetOpacity(0.80f);
        target_->DrawTextW(status.c_str(), static_cast<UINT32>(status.size()), smallTextFormat_.Get(),
                           statusRect, mutedBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
    }

    void DrawDevice(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 100.0f) return;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const bool connected = (state.device.eventType == DeviceEventType::Connected);

        // Badge circle with colored dot
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f,
                                        rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.10f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        // Small colored status dot inside badge
        ComPtr<ID2D1SolidColorBrush> dotBrush;
        D2D1_COLOR_F dotColor = connected
            ? D2D1::ColorF(0.19f, 0.83f, 0.38f, 1.0f)   // green
            : D2D1::ColorF(1.0f,  0.27f, 0.22f, 1.0f);  // red
        target_->CreateSolidColorBrush(dotColor, &dotBrush);

        // Draw USB plug icon using simple rects
        const float px = (badge.left + badge.right) * 0.5f;
        const float py = (badge.top + badge.bottom) * 0.5f;
        const float ps = badgeSz * 0.28f;

        ComPtr<ID2D1SolidColorBrush> iconBrush;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.90f), &iconBrush);

        // Plug body
        D2D1_RECT_F plug = D2D1::RectF(px - ps * 0.4f, py - ps * 0.8f, px + ps * 0.4f, py + ps * 0.6f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(plug, 1.5f, 1.5f), iconBrush.Get());
        // Plug prong left
        D2D1_RECT_F pl = D2D1::RectF(px - ps * 0.35f, py - ps * 1.2f, px - ps * 0.12f, py - ps * 0.8f);
        target_->FillRectangle(pl, iconBrush.Get());
        // Plug prong right
        D2D1_RECT_F pr = D2D1::RectF(px + ps * 0.12f, py - ps * 1.2f, px + ps * 0.35f, py - ps * 0.8f);
        target_->FillRectangle(pr, iconBrush.Get());
        // Plug cord
        D2D1_RECT_F cord = D2D1::RectF(px - ps * 0.1f, py + ps * 0.6f, px + ps * 0.1f, py + ps * 1.0f);
        target_->FillRoundedRectangle(D2D1::RoundedRect(cord, 1.0f, 1.0f), iconBrush.Get());

        // Status dot (bottom-right of badge)
        D2D1_POINT_2F dotCenter = D2D1::Point2F(badge.right - 4.5f, badge.bottom - 4.5f);
        target_->FillEllipse(D2D1::Ellipse(dotCenter, 4.5f, 4.5f), dotBrush.Get());

        // Text block
        const float tx = badge.right + 14;
        mutedBrush_->SetOpacity(0.50f);
        std::wstring label = connected ? L"Device Connected" : L"Device Removed";
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 22, rect.right - 14, cy - 5);
        target_->DrawTextW(label.c_str(), static_cast<UINT32>(label.size()),
                           smallTextFormat_.Get(), labelRect, mutedBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);

        textBrush_->SetOpacity(0.95f);
        const std::wstring& name = state.device.deviceName.empty()
            ? (state.device.isBluetoothLike ? std::wstring(L"Bluetooth") : std::wstring(L"USB Device"))
            : state.device.deviceName;
        D2D1_RECT_F nameRect = D2D1::RectF(tx, cy - 3, rect.right - 14, cy + 17);
        target_->DrawTextW(name.c_str(), static_cast<UINT32>(name.size()),
                           textFormat_.Get(), nameRect, textBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);
        textBrush_->SetOpacity(0.90f);
        mutedBrush_->SetOpacity(0.58f);
    }

    void DrawNotificationFallbackIcon(D2D1_POINT_2F center, float radius) {
        ComPtr<ID2D1SolidColorBrush> bg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.055f * settingsOpacity_), &bg);
        target_->FillEllipse(D2D1::Ellipse(center, radius, radius), bg.Get());

        accentBrush_->SetOpacity(0.92f);
        
        ComPtr<ID2D1PathGeometry> bellGeom;
        d2dFactory_->CreatePathGeometry(&bellGeom);
        ComPtr<ID2D1GeometrySink> sink;
        if (SUCCEEDED(bellGeom->Open(&sink))) {
            const float r = radius;
            sink->BeginFigure(D2D1::Point2F(center.x - r * 0.15f, center.y - r * 0.7f), D2D1_FIGURE_BEGIN_FILLED);
            sink->AddBezier(D2D1::BezierSegment(
                D2D1::Point2F(center.x - r * 0.4f, center.y - r * 0.7f),
                D2D1::Point2F(center.x - r * 0.5f, center.y - r * 0.2f),
                D2D1::Point2F(center.x - r * 0.55f, center.y + r * 0.2f)
            ));
            sink->AddBezier(D2D1::BezierSegment(
                D2D1::Point2F(center.x - r * 0.6f, center.y + r * 0.45f),
                D2D1::Point2F(center.x - r * 0.85f, center.y + r * 0.55f),
                D2D1::Point2F(center.x - r * 0.85f, center.y + r * 0.6f)
            ));
            sink->AddLine(D2D1::Point2F(center.x + r * 0.85f, center.y + r * 0.6f));
            sink->AddBezier(D2D1::BezierSegment(
                D2D1::Point2F(center.x + r * 0.85f, center.y + r * 0.55f),
                D2D1::Point2F(center.x + r * 0.6f, center.y + r * 0.45f),
                D2D1::Point2F(center.x + r * 0.55f, center.y + r * 0.2f)
            ));
            sink->AddBezier(D2D1::BezierSegment(
                D2D1::Point2F(center.x + r * 0.5f, center.y - r * 0.2f),
                D2D1::Point2F(center.x + r * 0.4f, center.y - r * 0.7f),
                D2D1::Point2F(center.x + r * 0.15f, center.y - r * 0.7f)
            ));
            sink->EndFigure(D2D1_FIGURE_END_CLOSED);
            sink->Close();

            target_->FillGeometry(bellGeom.Get(), accentBrush_.Get());
            target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, center.y + r * 0.7f), r * 0.22f, r * 0.22f), accentBrush_.Get());
            target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, center.y - r * 0.75f), r * 0.18f, r * 0.18f), accentBrush_.Get(), 1.4f);
        }

        ComPtr<ID2D1SolidColorBrush> badgeColor;
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &badgeColor);
        const float badgeR = radius * 0.28f;
        const float badgeX = center.x + radius * 0.65f;
        const float badgeY = center.y - radius * 0.5f;
        target_->FillEllipse(D2D1::Ellipse(D2D1::Point2F(badgeX, badgeY), badgeR, badgeR), badgeColor.Get());

        ComPtr<ID2D1SolidColorBrush> badgeBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 1.0f, 1.0f, 0.95f), &badgeBorder);
        target_->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(badgeX, badgeY), badgeR, badgeR), badgeBorder.Get(), 0.9f);

        accentBrush_->SetOpacity(1.0f);
    }

    void DrawBattery(const SharedState& state, D2D1_RECT_F rect) {
        if (rect.bottom - rect.top < 24.0f || rect.right - rect.left < 140.0f) return;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float badgeSz = (rect.bottom - rect.top) - 16.0f;
        D2D1_RECT_F badge = D2D1::RectF(rect.left + 14, cy - badgeSz * 0.5f,
                                        rect.left + 14 + badgeSz, cy + badgeSz * 0.5f);
        const float br = badgeSz * 0.35f;

        ComPtr<ID2D1SolidColorBrush> badgeBg;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.12f), &badgeBg);
        target_->FillRoundedRectangle(D2D1::RoundedRect(badge, br, br), badgeBg.Get());

        // Draw battery vector icon
        const float bx = badge.left + badgeSz * 0.25f;
        const float by = cy - badgeSz * 0.22f;
        const float bw = badgeSz * 0.45f;
        const float bh = badgeSz * 0.44f;
        D2D1_RECT_F batRect = D2D1::RectF(bx, by, bx + bw, by + bh);
        
        ComPtr<ID2D1SolidColorBrush> batBorder;
        target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.85f), &batBorder);
        target_->DrawRoundedRectangle(D2D1::RoundedRect(batRect, 2, 2), batBorder.Get(), 1.5f);
        
        // Battery Terminal (Nub)
        D2D1_RECT_F nubRect = D2D1::RectF(batRect.right, cy - 3, batRect.right + 2.5f, cy + 3);
        target_->FillRectangle(nubRect, batBorder.Get());

        // Battery Fill
        const float pct = Clamp(state.battery.percent / 100.0f, 0.0f, 1.0f);
        D2D1_RECT_F fillRect = D2D1::RectF(batRect.left + 2, batRect.top + 2,
                                           batRect.left + 2 + (bw - 4) * pct, batRect.bottom - 2);
        
        ComPtr<ID2D1SolidColorBrush> batFill;
        if (state.battery.low) {
            target_->CreateSolidColorBrush(D2D1::ColorF(1.0f, 0.23f, 0.18f, 1.0f), &batFill); // Red
        } else if (state.battery.charging) {
            target_->CreateSolidColorBrush(D2D1::ColorF(0.19f, 0.83f, 0.38f, 1.0f), &batFill); // Green
        } else {
            target_->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 0.95f), &batFill); // White
        }
        target_->FillRoundedRectangle(D2D1::RoundedRect(fillRect, 1, 1), batFill.Get());

        // Text Labels
        const float tx = badge.right + 14;
        D2D1_RECT_F labelRect = D2D1::RectF(tx, cy - 22, rect.right - 14, cy - 6);
        mutedBrush_->SetOpacity(0.50f);
        std::wstring label = state.battery.charging ? L"Power Connected" : L"Battery Alert";
        target_->DrawTextW(label.c_str(), static_cast<UINT32>(label.size()),
                           smallTextFormat_.Get(), labelRect, mutedBrush_.Get(),
                           D2D1_DRAW_TEXT_OPTIONS_CLIP);

        wchar_t value[128] = {};
        if (state.battery.secondsRemaining != BATTERY_LIFE_UNKNOWN && !state.battery.charging) {
            const DWORD minutes = state.battery.secondsRemaining / 60;
            swprintf_s(value, ARRAYSIZE(value), L"%d%% \u2022 %luh %02lum left", 
                       state.battery.percent, minutes / 60, minutes % 60);
        } else {
            swprintf_s(value, ARRAYSIZE(value), L"%d%%", state.battery.percent);
        }

        D2D1_RECT_F valueRect = D2D1::RectF(tx, cy - 4, rect.right - 14, cy + 17);
        textBrush_->SetOpacity(0.95f);
        target_->DrawTextW(value, static_cast<UINT32>(wcslen(value)), textFormat_.Get(),
                           valueRect, textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
        textBrush_->SetOpacity(0.90f);
    }

    void DrawProgress(const SharedState& state, D2D1_RECT_F rect) {
        wchar_t buffer[64] = {};
        swprintf_s(buffer, L"Progress %d%%", state.progress.percent);
        target_->DrawTextW(buffer, static_cast<UINT32>(wcslen(buffer)), textFormat_.Get(),
                           D2D1::RectF(rect.left + 18, rect.top + 14, rect.right - 18,
                                       rect.bottom - 10),
                           textBrush_.Get(), D2D1_DRAW_TEXT_OPTIONS_CLIP);
    }

    void DrawProgressRing(D2D1_RECT_F rect, int percent) {
        ComPtr<ID2D1PathGeometry> geometry;
        d2dFactory_->CreatePathGeometry(&geometry);
        ComPtr<ID2D1GeometrySink> sink;
        geometry->Open(&sink);

        const float cx = (rect.left + rect.right) * 0.5f;
        const float cy = (rect.top + rect.bottom) * 0.5f;
        const float rx = (rect.right - rect.left) * 0.5f + 6.0f;
        const float ry = (rect.bottom - rect.top) * 0.5f + 6.0f;
        const float start = -3.14159265f * 0.5f;
        const float sweep = 2.0f * 3.14159265f * Clamp(percent / 100.0f, 0.0f, 1.0f);
        const int segments = std::max(2, static_cast<int>(48 * percent / 100.0f));

        auto pointAt = [&](float a) {
            return D2D1::Point2F(cx + std::cos(a) * rx, cy + std::sin(a) * ry);
        };

        sink->BeginFigure(pointAt(start), D2D1_FIGURE_BEGIN_HOLLOW);
        for (int i = 1; i <= segments; ++i) {
            const float a = start + sweep * i / segments;
            sink->AddLine(pointAt(a));
        }
        sink->EndFigure(D2D1_FIGURE_END_OPEN);
        sink->Close();

        accentBrush_->SetOpacity(0.92f);
        target_->DrawGeometry(geometry.Get(), accentBrush_.Get(), 3.0f);
        accentBrush_->SetOpacity(1.0f);
    }

    HWND hwnd_ = nullptr;
    HDC memDc_ = nullptr;
    HBITMAP dib_ = nullptr;
    HBITMAP oldBitmap_ = nullptr;
    int bitmapWidth_ = 0;
    int bitmapHeight_ = 0;

    ComPtr<ID2D1Factory> d2dFactory_;
    ComPtr<ID2D1DCRenderTarget> target_;
    ComPtr<IDWriteFactory> dwriteFactory_;
    ComPtr<IDWriteTextFormat> textFormat_;
    ComPtr<IDWriteTextFormat> smallTextFormat_;
    ComPtr<IDWriteTextFormat> boldTextFormat_;
    ComPtr<IDWriteTextFormat> hugeTextFormat_;
    ComPtr<IDWriteTextFormat> clockFormat_;
    ComPtr<IDWriteTextFormat> iconFormat_;
    ComPtr<ID2D1SolidColorBrush> accentBrush_;
    ComPtr<ID2D1SolidColorBrush> redBrush_;
    ComPtr<ID2D1SolidColorBrush> textBrush_;
    ComPtr<ID2D1SolidColorBrush> mutedBrush_;
    ComPtr<ID2D1SolidColorBrush> tintBrush_;
    ComPtr<ID2D1SolidColorBrush> shadowBrush_;
    ComPtr<ID2D1Bitmap> artBitmap_;
    ComPtr<ID2D1Bitmap> notificationIconBitmap_;
    ComPtr<ID2D1Bitmap> mediaSourceIconBitmap_;
    ComPtr<ID2D1Bitmap> clipboardIconBitmap_;
    uint64_t artGeneration_ = 0;
    uint64_t notificationIconGeneration_ = 0;
    uint64_t mediaSourceIconGeneration_ = 0;
    uint64_t clipboardIconGeneration_ = 0;
    float settingsOpacity_ = 0.96f;
    D2D1_COLOR_F pillBgColor_ = D2D1::ColorF(0.051f, 0.051f, 0.059f, 1.0f);
};

Activity ActivityForKind(IslandKind kind, const Settings& settings, const SharedState& state) {
    Activity activity;
    activity.kind = kind;

    switch (kind) {
        case IslandKind::Media:
            activity.width = 150.0f;
            activity.height = 44.0f;
            break;
        case IslandKind::Progress:
            activity.width = 230.0f;
            activity.height = 48.0f;
            break;
        case IslandKind::Clipboard:
            activity.width = 340.0f;
            activity.height = 56.0f;
            break;
        case IslandKind::Notification:
            activity.width = 360.0f;
            activity.height = 58.0f;
            break;
        case IslandKind::Volume:
            activity.width = 300.0f;
            activity.height = 54.0f;
            break;
        case IslandKind::BatteryLow:
            activity.width = 290.0f;
            activity.height = 52.0f;
            break;
        case IslandKind::CapsLock:
            activity.width = 180.0f;
            activity.height = 42.0f;
            break;
        case IslandKind::Device:
            activity.width = 240.0f;
            activity.height = 50.0f;
            break;
        case IslandKind::Idle:
        default:
            if (settings.autoHideIdleSeconds == -1 && !state.system.micActive && !state.system.cameraActive) {
                activity.width = 0.0f;
                activity.height = 0.0f;
            } else {
                activity.width = settings.weather ? 170.0f : 96.0f;
                activity.height = 36.0f;
            }
            break;
    }

    activity.width *= settings.sizeScale;
    activity.height *= settings.sizeScale;
    return activity;
}

std::vector<IslandKind> ChooseActivities(const SharedState& state, const Settings& settings, double now) {
    std::vector<IslandKind> activities;

    if (state.clipboard.active && now < state.clipboard.expiresAt) {
        activities.push_back(IslandKind::Clipboard);
    }
    if (state.capsLock.active && now < state.capsLock.expiresAt) {
        activities.push_back(IslandKind::CapsLock);
    }
    if (state.device.active && now < state.device.expiresAt) {
        activities.push_back(IslandKind::Device);
    }
    if (state.volume.active && now < state.volume.expiresAt) {
        activities.push_back(IslandKind::Volume);
    }
    if (state.notification.active && now < state.notification.expiresAt) {
        activities.push_back(IslandKind::Notification);
    }
    if (settings.battery && state.battery.active && now < state.battery.expiresAt) {
        activities.push_back(IslandKind::BatteryLow);
    }
    if (settings.progress && state.progress.active) {
        activities.push_back(IslandKind::Progress);
    }
    if (settings.media && state.media.available && g_idleTab == 0) {
        activities.push_back(IslandKind::Media);
    }

    if (activities.empty()) {
        activities.push_back(IslandKind::Idle);
    }

    return activities;
}

constexpr UINT WM_APP_CAPSLOCK = WM_APP + 0x444;
HHOOK g_keyboardHook = nullptr;
HANDLE g_keyboardThread = nullptr;
DWORD g_keyboardThreadId = 0;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
            auto* kbd = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
            if (kbd->vkCode == VK_CAPITAL || kbd->vkCode == VK_NUMLOCK) {
                bool capsOn = (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
                bool numOn = (GetKeyState(VK_NUMLOCK) & 0x0001) != 0;
                {
                    std::lock_guard lock(g_stateMutex);
                    g_state.capsLock.active = true;
                    g_state.capsLock.capsOn = capsOn;
                    g_state.capsLock.numOn = numOn;
                    g_state.capsLock.isNumEvent = (kbd->vkCode == VK_NUMLOCK);
                    g_state.capsLock.expiresAt = NowSeconds() + 2.5;
                }
                HWND hwnd = g_hwnd;
                if (hwnd) {
                    LPARAM state = (capsOn ? 1 : 0) | (numOn ? 2 : 0);
                    PostMessageW(hwnd, WM_APP_CAPSLOCK, kbd->vkCode, state);
                }
            }
        }
    }
    return CallNextHookEx(g_keyboardHook, nCode, wParam, lParam);
}

DWORD WINAPI KeyboardThreadProc(void*) {
    while (!g_hwnd) {
        Sleep(10);
    }
    g_keyboardHook = SetWindowsHookExW(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);
    MSG msg;
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    if (g_keyboardHook) {
        UnhookWindowsHookEx(g_keyboardHook);
        g_keyboardHook = nullptr;
    }
    return 0;
}

LRESULT CALLBACK OverlayWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static POINT s_touchStart = {0, 0};
    static ULONGLONG s_touchStartTime = 0;
    switch (msg) {
        case WM_CREATE:
            AddClipboardFormatListener(hwnd);
            if (g_shellHookMessage == 0) g_shellHookMessage = RegisterWindowMessageW(L"SHELLHOOK");
            if (g_taskbarCreatedMessage == 0) g_taskbarCreatedMessage = RegisterWindowMessageW(L"TaskbarCreated");
            RegisterShellHookWindow(hwnd);
            return 0;

        case WM_DESTROY:
            RemoveClipboardFormatListener(hwnd);
            DeregisterShellHookWindow(hwnd);
            return 0;

        case WM_APP_CAPSLOCK: {
            if (!g_settings.capsLock) return 0;
            bool isNum = (wParam == VK_NUMLOCK);
            bool capsOn = (lParam & 1) != 0;
            bool numOn = (lParam & 2) != 0;
            {
                std::lock_guard lock(g_stateMutex);
                g_state.capsLock.active = true;
                g_state.capsLock.capsOn = capsOn;
                g_state.capsLock.numOn = numOn;
                g_state.capsLock.isNumEvent = isNum;
                g_state.capsLock.expiresAt = NowSeconds() + 2.5;
            }
            TriggerNudge();
            return 0;
        }

        case WM_DEVICECHANGE: {
            // DBT_DEVICEARRIVAL = 0x8000, DBT_DEVICEREMOVECOMPLETE = 0x8004
            if (wParam == 0x8000 || wParam == 0x8004) {
                bool arrived = (wParam == 0x8000);
                std::wstring devName;
                bool isBt = false;

                if (lParam) {
                    auto* hdr = reinterpret_cast<DEV_BROADCAST_HDR*>(lParam);
                    if (hdr->dbch_devicetype == DBT_DEVTYP_VOLUME) {
                        devName = L"USB Drive";
                    } else if (hdr->dbch_devicetype == DBT_DEVTYP_PORT) {
                        devName = L"COM Device";
                    } else {
                        // Generic/Bluetooth OEM
                        isBt = true;
                        devName = L"Bluetooth Device";
                    }
                }

                {
                    std::lock_guard lock(g_stateMutex);
                    g_state.device.active = true;
                    g_state.device.eventType = arrived ? DeviceEventType::Connected
                                                       : DeviceEventType::Disconnected;
                    g_state.device.deviceName = devName;
                    g_state.device.isBluetoothLike = isBt;
                    g_state.device.expiresAt = NowSeconds() + 3.0;
                }
                TriggerNudge();
            }
            return 0;
        }

        case WM_POWERBROADCAST: {
            if (wParam == PBT_APMRESUMESUSPEND || wParam == PBT_APMRESUMEAUTOMATIC || wParam == PBT_APMRESUMECRITICAL) {
                if (g_settingsChangedEvent) {
                    SetEvent(g_settingsChangedEvent);
                }
                {
                    std::lock_guard lock(g_stateMutex);
                    g_state.weather.lastUpdated = 0.0;
                }
                TriggerNudge();
            }
            return TRUE;
        }

        case WM_CLIPBOARDUPDATE:
            if (g_settings.clipboard) {
                CaptureClipboard(hwnd);
            }
            return 0;



        case WM_APP_LAYOUT_CHANGED:
            g_layoutDirty = true;
            return 0;

        case WM_SETCURSOR:
            if (LOWORD(lParam) == HTCLIENT) {
                POINT pt;
                GetCursorPos(&pt);
                ScreenToClient(hwnd, &pt);

                bool mediaActive = false;
                {
                    std::lock_guard lock(g_stateMutex);
                    mediaActive = g_settings.media && g_state.media.available;
                }

                if (mediaActive) {
                    RECT clientRect;
                    GetClientRect(hwnd, &clientRect);
                    const float height = static_cast<float>(clientRect.bottom - clientRect.top);
                    const float width = static_cast<float>(clientRect.right - clientRect.left);

                    if (height > 60.0f && (g_idleTab % 3) == 0) {
                        float totalScale = (GetDpiForWindow(hwnd) / 96.0f) * g_settings.sizeScale;
                        float cx = width / 2.0f;
                        float cy = height / 2.0f;
                        float unX = (pt.x - cx) / totalScale;
                        float unY = (pt.y - cy) / totalScale;

                        bool hoverClickable = false;

                        // Check album art bounds
                        if (unX >= -168.0f && unX <= -100.0f && unY >= -74.0f && unY <= -6.0f) {
                            hoverClickable = true;
                        }

                        // Check media buttons bounds
                        if (unY > 56.0f - 30.0f && unY < 56.0f + 30.0f) {
                            if (unX > -84.0f && unX < -44.0f) hoverClickable = true; // Prev
                            else if (unX > -24.0f && unX < 24.0f) hoverClickable = true; // Play/Pause
                            else if (unX > 44.0f && unX < 84.0f) hoverClickable = true; // Next
                        }

                        // Check music progress bar bounds
                        if (unY >= 8.0f && unY <= 36.0f && unX >= -136.0f && unX <= 134.0f) {
                            hoverClickable = true;
                        }

                        if (hoverClickable) {
                            SetCursor(LoadCursorW(nullptr, IDC_HAND));
                            return TRUE;
                        }
                    }
                }
            }
            break;

        case WM_LBUTTONDOWN:
            {
                int xPos = GET_X_LPARAM(lParam);
                int yPos = GET_Y_LPARAM(lParam);
                
                s_touchStart.x = xPos;
                s_touchStart.y = yPos;
                s_touchStartTime = GetTickCount64();
                
                bool mediaActive = false;
                {
                    std::lock_guard lock(g_stateMutex);
                    mediaActive = g_settings.media && g_state.media.available;
                }

                RECT clientRect;
                GetClientRect(hwnd, &clientRect);
                const float height = static_cast<float>(clientRect.bottom - clientRect.top);
                const float width = static_cast<float>(clientRect.right - clientRect.left);

                if (mediaActive && height > 60.0f && (g_idleTab % 3) == 0) {
                    float totalScale = (GetDpiForWindow(hwnd) / 96.0f) * g_settings.sizeScale;
                    float cx = width / 2.0f;
                    float cy = height / 2.0f;
                    
                    float unX = (xPos - cx) / totalScale;
                    float unY = (yPos - cy) / totalScale;

                    if (unY > 56.0f - 30.0f && unY < 56.0f + 30.0f) {
                        int cmd = -1;
                        if (unX > -84.0f && unX < -44.0f) cmd = 0; // Prev
                        else if (unX > -24.0f && unX < 24.0f) cmd = 1; // Play/Pause
                        else if (unX > 44.0f && unX < 84.0f) cmd = 2; // Next

                        if (cmd != -1) {
                            g_pressedMediaButton = cmd;
                            SetCapture(hwnd);
                            g_layoutDirty = true;
                            return 0;
                        }
                    }
                }
            }
            break;

        case WM_LBUTTONUP:
            {
                if (g_pressedMediaButton.load() != -1) {
                    g_pressedMediaButton = -1;
                    ReleaseCapture();
                    g_layoutDirty = true;
                }

                int xPos = GET_X_LPARAM(lParam);
                int yPos = GET_Y_LPARAM(lParam);
                
                ULONGLONG now = GetTickCount64();
                if (s_touchStartTime > 0 && (now - s_touchStartTime) < 500) {
                    int dx = xPos - s_touchStart.x;
                    if (abs(dx) > 40) { // Horizontal swipe threshold
                        bool mediaActive = false;
                        bool hwMonActive = false;
                        bool weatherActive = false;
                        {
                            std::lock_guard lock(g_stateMutex);
                            mediaActive = g_settings.media && g_state.media.available;
                            hwMonActive = g_settings.hardwareMonitorModule;
                            weatherActive = g_settings.weather;
                        }
                        int maxTabs = mediaActive ? 3 : (1 + (weatherActive ? 1 : 0) + (hwMonActive ? 1 : 0));
                        if (maxTabs > 1) {
                            if (dx > 0) { // Swipe right -> previous tab
                                g_idleTab = (g_idleTab - 1 + maxTabs) % maxTabs;
                            } else { // Swipe left -> next tab
                                g_idleTab = (g_idleTab + 1) % maxTabs;
                            }
                            g_layoutDirty = true;
                        }
                        s_touchStartTime = 0;
                        return 0; // Consume swipe gesture
                    }
                }
                s_touchStartTime = 0;
                
                bool mediaActive = false;
                std::vector<IslandKind> kinds;
                {
                    std::lock_guard lock(g_stateMutex);
                    mediaActive = g_settings.media && g_state.media.available;
                    kinds = ChooseActivities(g_state, g_settings, NowSeconds());
                }
                const bool gameMetricsPresent =
                    !kinds.empty() && kinds[0] == IslandKind::Idle &&
                    (g_settings.gameOverlay || Wh_GetIntValue(L"GameOverlayPinned", 0) != 0);

                bool expanded = Wh_GetIntValue(L"PinnedExpanded", 0) != 0 || g_clickExpanded.load();
                if (!gameMetricsPresent && !g_settings.expandOnHover && !expanded) {
                    g_clickExpanded = true;
                    g_layoutDirty = true;
                    return 0; // consumed click to expand
                }

                RECT clientRect;
                GetClientRect(hwnd, &clientRect);
                const float height = static_cast<float>(clientRect.bottom - clientRect.top);
                const float width = static_cast<float>(clientRect.right - clientRect.left);

                float totalScale = (GetDpiForWindow(hwnd) / 96.0f) * g_settings.sizeScale;
                float cx = width / 2.0f;
                float cy = height / 2.0f;
                float unX = (xPos - cx) / totalScale;
                float unY = (yPos - cy) / totalScale;

                bool clickedAlbumArt = false;
                if (mediaActive) {
                    if (height > 60.0f && (g_idleTab % 3) == 0) {
                        // Check album art bounds in expanded media view
                        if (unX >= -168.0f && unX <= -100.0f && unY >= -74.0f && unY <= -6.0f) {
                            clickedAlbumArt = true;
                        }

                        if (unY > 56.0f - 30.0f && unY < 56.0f + 30.0f) {
                            // Check button clicks in expanded media view
                            int cmd = -1;
                            if (unX > -84.0f && unX < -44.0f) cmd = 0; // Prev
                            else if (unX > -24.0f && unX < 24.0f) cmd = 1; // Play/Pause
                            else if (unX > 44.0f && unX < 84.0f) cmd = 2; // Next

                            if (cmd != -1) {
                                std::thread([cmd]() {
                                    winrt::init_apartment(winrt::apartment_type::multi_threaded);
                                    try {
                                        using Manager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
                                        auto manager = Manager::RequestAsync().get();
                                        if (manager) {
                                            auto sessions = manager.GetSessions();
                                            std::wstring currentAumid;
                                            {
                                                std::lock_guard lock(g_stateMutex);
                                                currentAumid = g_state.media.sourceAppUserModelId;
                                            }
                                            winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession session = nullptr;
                                            for (auto const& s : sessions) {
                                                if (s.SourceAppUserModelId().c_str() == currentAumid) {
                                                    session = s;
                                                    break;
                                                }
                                            }
                                            if (!session) session = manager.GetCurrentSession();

                                            if (session) {
                                                if (cmd == 0) session.TrySkipPreviousAsync().get();
                                                else if (cmd == 1) session.TryTogglePlayPauseAsync().get();
                                                else if (cmd == 2) session.TrySkipNextAsync().get();
                                            }
                                        }
                                    } catch (...) {}
                                }).detach();
                                return 0;
                            }
                        }

                        if (unY >= 8.0f && unY <= 36.0f && unX >= -136.0f && unX <= 134.0f) {
                            // Clicked on the media progress bar (scrubber) to seek
                            float fraction = (unX - (-130.0f)) / (128.0f - (-130.0f));
                            fraction = std::clamp(fraction, 0.0f, 1.0f);
                            int64_t endTicks = 0;
                            {
                                std::lock_guard lock(g_stateMutex);
                                endTicks = g_state.media.endTicks;
                            }
                            if (endTicks > 0) {
                                int64_t targetTicks = static_cast<int64_t>(fraction * endTicks);
                                std::thread([targetTicks]() {
                                    winrt::init_apartment(winrt::apartment_type::multi_threaded);
                                    try {
                                        using Manager = winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager;
                                        auto manager = Manager::RequestAsync().get();
                                        if (manager) {
                                            auto sessions = manager.GetSessions();
                                            std::wstring currentAumid;
                                            {
                                                std::lock_guard lock(g_stateMutex);
                                                currentAumid = g_state.media.sourceAppUserModelId;
                                            }
                                            winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession session = nullptr;
                                            for (auto const& s : sessions) {
                                                if (s.SourceAppUserModelId().c_str() == currentAumid) {
                                                    session = s;
                                                    break;
                                                }
                                            }
                                            if (!session) session = manager.GetCurrentSession();

                                            if (session) {
                                                session.TryChangePlaybackPositionAsync(targetTicks).get();
                                            }
                                        }
                                    } catch (...) {}
                                }).detach();
                                {
                                    std::lock_guard lock(g_stateMutex);
                                    g_state.media.positionTicks = targetTicks;
                                    g_state.media.lastUpdatedTicks = GetTickCount64();
                                }
                                g_layoutDirty = true;
                            }
                            return 0;
                        }
                    } else if (height <= 60.0f) {
                        float unW = (width - kRenderPadX * 2.0f) / totalScale;
                        float unH = (height - kRenderPadY * 2.0f) / totalScale;
                        float artSize = unH - 12.0f;
                        float artLeft = -unW * 0.5f + 8.0f;
                        if (unX >= artLeft - 4.0f && unX <= artLeft + artSize + 4.0f &&
                            unY >= -artSize * 0.5f - 4.0f && unY <= artSize * 0.5f + 4.0f) {
                            clickedAlbumArt = true;
                        }
                    }

                    if (height > 45.0f && xPos > width - 30.0f) {
                        // Clicked on the right edge scroll area in Media
                        g_idleTab = (g_idleTab + 1) % 3;
                        g_layoutDirty = true;
                    } else if (clickedAlbumArt) {
                        OpenRelevantApp();
                    }
                } else {
                    if (!kinds.empty() && kinds[0] == IslandKind::Idle && height > 45.0f) {
                        int maxTabs = g_settings.weather ? 2 : 1;
                        if (maxTabs > 1) {
                            if (xPos < width / 2.0f) g_idleTab = (g_idleTab - 1 + maxTabs) % maxTabs;
                            else g_idleTab = (g_idleTab + 1) % maxTabs;
                        }
                        g_layoutDirty = true;
                    } else {
                        HandleStatusClickAtPoint(hwnd, lParam);
                    }
                }
            }
            return 0;

        case WM_MBUTTONUP:
            ToggleEndpointMute();
            return 0;

        case WM_LBUTTONDBLCLK:
            Wh_SetIntValue(L"PinnedExpanded", Wh_GetIntValue(L"PinnedExpanded", 0) ? 0 : 1);
            return 0;

        case WM_MOUSEWHEEL: {
            static ULONGLONG lastScrollTime = 0;
            ULONGLONG now = GetTickCount64();
            if (now - lastScrollTime < 150) return 0; // 150ms debounce
            lastScrollTime = now;

            bool mediaActive = false;
            bool hwMonActive = false;
            bool weatherActive = false;
            {
                std::lock_guard lock(g_stateMutex);
                mediaActive = g_settings.media && g_state.media.available;
                hwMonActive = g_settings.hardwareMonitorModule;
                weatherActive = g_settings.weather;
            }
            int maxTabs = mediaActive ? 3 : (1 + (weatherActive ? 1 : 0) + (hwMonActive ? 1 : 0));
            int delta = GET_WHEEL_DELTA_WPARAM(wParam);
            if (delta > 0) {
                if (g_idleTab > 0) g_idleTab--;
            } else if (delta < 0) {
                if (g_idleTab < maxTabs - 1) g_idleTab++;
            }
            
            g_layoutDirty = true;
            return 0;
        }

        case WM_RBUTTONUP: {
            POINT pt = {GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)};
            ClientToScreen(hwnd, &pt);
            ShowContextMenu(hwnd, pt);
            return 0;
        }
    }

    if (msg == g_shellHookMessage && g_shellHookMessage != 0) {
        if (wParam == HSHELL_WINDOWCREATED) {
            CaptureShellNotification(reinterpret_cast<HWND>(lParam));
        }
        return 0;
    }

    if (msg == g_taskbarCreatedMessage && g_taskbarCreatedMessage != 0) {
        Wh_Log(L"TaskbarCreated received; re-registering shell hook window.");
        DeregisterShellHookWindow(hwnd);
        RegisterShellHookWindow(hwnd);
        return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

DWORD WINAPI RenderThreadProc(void*) {
    HRESULT hrCo = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    WNDCLASSEXW wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = OverlayWndProc;
    wc.hInstance = GetModuleHandleW(nullptr);
    wc.lpszClassName = kWindowClass;
    wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    RegisterClassExW(&wc);

    HWND hwnd = CreateWindowExW(
        WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE | WS_EX_TRANSPARENT,
        kWindowClass, L"Dynamic Island for Windows", WS_POPUP, 0, 0, 520, 140,
        nullptr, nullptr, wc.hInstance, nullptr);

    if (!hwnd) {
        Wh_Log(L"Failed to create Dynamic Island overlay window.");
        if (SUCCEEDED(hrCo)) {
            CoUninitialize();
        }
        return 0;
    }

    g_hwnd = hwnd;
    if (g_shellHookMessage == 0) g_shellHookMessage = RegisterWindowMessageW(L"SHELLHOOK");
    if (g_taskbarCreatedMessage == 0) g_taskbarCreatedMessage = RegisterWindowMessageW(L"TaskbarCreated");
    using ChangeWindowMessageFilterEx_t = BOOL(WINAPI*)(HWND, UINT, DWORD, PVOID);
    static auto pChangeWindowMessageFilterEx = reinterpret_cast<ChangeWindowMessageFilterEx_t>(
        GetProcAddress(GetModuleHandleW(L"user32.dll"), "ChangeWindowMessageFilterEx"));
    if (pChangeWindowMessageFilterEx) {
        if (g_shellHookMessage) pChangeWindowMessageFilterEx(hwnd, g_shellHookMessage, 1 /*MSGFLT_ALLOW*/, nullptr);
        if (g_taskbarCreatedMessage) pChangeWindowMessageFilterEx(hwnd, g_taskbarCreatedMessage, 1 /*MSGFLT_ALLOW*/, nullptr);
        pChangeWindowMessageFilterEx(hwnd, WM_COPYDATA, 1 /*MSGFLT_ALLOW*/, nullptr);
        pChangeWindowMessageFilterEx(hwnd, 0x0049 /*WM_COPYGLOBALDATA*/, 1 /*MSGFLT_ALLOW*/, nullptr);
    } else {
        using ChangeWindowMessageFilter_t = BOOL(WINAPI*)(UINT, DWORD);
        static auto pChangeWindowMessageFilter = reinterpret_cast<ChangeWindowMessageFilter_t>(
            GetProcAddress(GetModuleHandleW(L"user32.dll"), "ChangeWindowMessageFilter"));
        if (pChangeWindowMessageFilter) {
            if (g_shellHookMessage) pChangeWindowMessageFilter(g_shellHookMessage, 1 /*MSGFLT_ADD*/);
            if (g_taskbarCreatedMessage) pChangeWindowMessageFilter(g_taskbarCreatedMessage, 1 /*MSGFLT_ADD*/);
            pChangeWindowMessageFilter(WM_COPYDATA, 1 /*MSGFLT_ADD*/);
            pChangeWindowMessageFilter(0x0049 /*WM_COPYGLOBALDATA*/, 1 /*MSGFLT_ADD*/);
        }
    }
    EnableBlurBehind(hwnd);
    ShowWindow(hwnd, SW_SHOWNOACTIVATE);

    Renderer renderer;
    if (!renderer.Initialize(hwnd)) {
        DestroyWindow(hwnd);
        g_hwnd = nullptr;
        if (SUCCEEDED(hrCo)) {
            CoUninitialize();
        }
        return 0;
    }

    using TimeBeginPeriod_t = MMRESULT(WINAPI*)(UINT);
    using TimeEndPeriod_t = MMRESULT(WINAPI*)(UINT);
    static auto pTimeBeginPeriod = reinterpret_cast<TimeBeginPeriod_t>(
        GetProcAddress(LoadLibraryW(L"winmm.dll"), "timeBeginPeriod"));
    static auto pTimeEndPeriod = reinterpret_cast<TimeEndPeriod_t>(
        GetProcAddress(GetModuleHandleW(L"winmm.dll"), "timeEndPeriod"));
    if (pTimeBeginPeriod) {
        pTimeBeginPeriod(1);
    }

    SpringValue widthSpring;
    SpringValue heightSpring;
    SpringValue nudgeSpring;
    widthSpring.Reset((g_settings.autoHideIdleSeconds == -1 ? 0.0f : 120.0f) * g_settings.sizeScale);
    heightSpring.Reset((g_settings.autoHideIdleSeconds == -1 ? 0.0f : 36.0f) * g_settings.sizeScale);
    nudgeSpring.Reset(0.0f);

    IslandKind previousPrimary = IslandKind::Idle;
    auto previousFrame = std::chrono::steady_clock::now();
    auto nextFrameTarget = previousFrame;
    double nextBatteryPoll = 0.0;
    double nextProgressPoll = 0.0;
    double nextSystemPoll = 0.0;
    double nextPrivacyPoll = 0.0;

    static double lastInteractionTime = NowSeconds();
    while (WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
        MSG message = {};
        while (PeekMessageW(&message, nullptr, 0, 0, PM_REMOVE)) {
            if (message.message == WM_APP_NEW_EVENT) {
                nudgeSpring.value = -6.0f;
                nudgeSpring.velocity = 0.0f;
                nudgeSpring.target = 0.0f;
                lastInteractionTime = NowSeconds();
                continue;
            }
            TranslateMessage(&message);
            DispatchMessageW(&message);
        }

        const double now = NowSeconds();
        if (now >= nextBatteryPoll) {
            UpdateBatterySnapshot();
            nextBatteryPoll = now + 15.0;
        }
        if (now >= nextProgressPoll) {
            UpdateProgressSnapshot();
            nextProgressPoll = now + 0.25;
        }
        if (now >= nextSystemPoll) {
            UpdateSystemSnapshot();
            nextSystemPoll = now + 1.0;
        }
        if (now >= nextPrivacyPoll) {
            UpdatePrivacyIndicators();
            nextPrivacyPoll = now + 2.0;  // poll every 2 s
        }

        SharedState snapshot;
        {
            std::lock_guard lock(g_stateMutex);
            snapshot = g_state;
            if (g_state.clipboard.active && now >= g_state.clipboard.expiresAt) {
                g_state.clipboard.active = false;
                snapshot.clipboard.active = false;
            }
            if (g_state.notification.active && now >= g_state.notification.expiresAt) {
                g_state.notification.active = false;
                snapshot.notification.active = false;
            }
            if (g_state.volume.active && now >= g_state.volume.expiresAt) {
                g_state.volume.active = false;
                snapshot.volume.active = false;
            }
            if (g_state.capsLock.active && now >= g_state.capsLock.expiresAt) {
                g_state.capsLock.active = false;
                snapshot.capsLock.active = false;
            }
            if (g_state.battery.active && now >= g_state.battery.expiresAt) {
                g_state.battery.active = false;
                snapshot.battery.active = false;
            }
            if (g_state.device.active && now >= g_state.device.expiresAt) {
                g_state.device.active = false;
                snapshot.device.active = false;
            }
        }

        const std::vector<IslandKind> kinds = ChooseActivities(snapshot, g_settings, now);
        Activity primary = ActivityForKind(kinds[0], g_settings, snapshot);
        std::optional<Activity> secondary;
        if (kinds.size() >= 2) {
            secondary = ActivityForKind(kinds[1], g_settings, snapshot);
        }

        const bool pinned = Wh_GetIntValue(L"PinnedExpanded", 0) != 0;

        if (primary.kind != previousPrimary) {
            if (primary.kind != IslandKind::Idle) {
                nudgeSpring.value = -6.0f;
                nudgeSpring.velocity = 0.0f;
                nudgeSpring.target = 0.0f;
            }
            lastInteractionTime = now;
        }
        previousPrimary = primary.kind;

        RECT windowRect = {};
        GetWindowRect(hwnd, &windowRect);
        POINT cursor = {};
        GetCursorPos(&cursor);
        const bool hover = PtInRect(&windowRect, cursor) != FALSE;
        
        bool needsRender = false;
        
        if (!hover && g_clickExpanded.load()) {
            g_clickExpanded = false;
            needsRender = true;
        }
        bool isTransientAlert = (primary.kind == IslandKind::Clipboard ||
                                 primary.kind == IslandKind::Notification ||
                                 primary.kind == IslandKind::Volume ||
                                 primary.kind == IslandKind::BatteryLow ||
                                 primary.kind == IslandKind::CapsLock ||
                                 primary.kind == IslandKind::Device ||
                                 (primary.kind == IslandKind::Media &&
                                  (now - g_state.media.artChangedAt < 4.0)));

        bool currentlyHidden = false;
        if (g_settings.autoHideIdleSeconds == -1 && !isTransientAlert && !pinned) {
            currentlyHidden = true;
        } else if (g_settings.autoHideIdleSeconds > 0) {
            currentlyHidden = (now - lastInteractionTime > g_settings.autoHideIdleSeconds);
        }

        bool isHoverExpanded = g_settings.expandOnHover ? hover : (hover && g_clickExpanded.load());
        const bool gameMetricsPresent = primary.kind == IslandKind::Idle &&
            (g_settings.gameOverlay || Wh_GetIntValue(L"GameOverlayPinned", 0) != 0);
        if (gameMetricsPresent) {
            isHoverExpanded = false;
        }
        
        if (currentlyHidden && !g_settings.unhideOnHover) {
            isHoverExpanded = false;
        } else if (isHoverExpanded || pinned || isTransientAlert) {
            lastInteractionTime = now;
        }
        
        bool isHidden = false;
        if (g_settings.autoHideIdleSeconds == -1 && !isTransientAlert && !isHoverExpanded && !pinned) {
            isHidden = true;
        } else if (g_settings.autoHideIdleSeconds > 0) {
            isHidden = (now - lastInteractionTime > g_settings.autoHideIdleSeconds);
        }

        bool isFullscreen = g_settings.autoHideFullscreen && IsForegroundFullscreen(hwnd);
        bool privacyActive = (snapshot.system.micActive || snapshot.system.cameraActive) && g_settings.privacyDotsEnabled;
        if (primary.kind == IslandKind::Idle) {
            if (!isFullscreen && (pinned || isHoverExpanded)) {
                primary.width = 380.0f * g_settings.sizeScale;
                primary.height = 184.0f * g_settings.sizeScale;
            }
        }
        if (!isFullscreen && primary.kind == IslandKind::Idle &&
            (g_settings.gameOverlay || Wh_GetIntValue(L"GameOverlayPinned", 0) != 0)) {
            primary.width = 372.0f * g_settings.sizeScale;
            primary.height = 64.0f * g_settings.sizeScale;
        }
        if (primary.kind == IslandKind::Media) {
            bool recentArtChange = g_settings.mediaAutoExpand && (NowSeconds() - g_state.media.artChangedAt) < 4.0;
            if (!isFullscreen && (isHoverExpanded || pinned || recentArtChange)) {
                primary.width = 380.0f * g_settings.sizeScale;
                primary.height = 184.0f * g_settings.sizeScale;
            }
        }

        if (isHidden && !privacyActive && !pinned && !isHoverExpanded && !isTransientAlert) {
            primary.width = 0.0f;
            primary.height = 0.0f;
            secondary.reset();
        }

        float targetWidth = primary.width;
        float targetHeight = primary.height;
        if (secondary) {
            targetWidth = primary.width + secondary->width + 12.0f * g_settings.sizeScale;
            targetHeight = std::max(primary.height, secondary->height);
        }

        widthSpring.target = targetWidth;
        heightSpring.target = targetHeight;

        const auto currentFrame = std::chrono::steady_clock::now();
        float dt = std::chrono::duration<float>(currentFrame - previousFrame).count();
        previousFrame = currentFrame;
        dt = Clamp(dt, 0.001f, 0.050f);

        float styleStiffnessMult = 1.0f;
        float styleDampingMult = 1.0f;
        if (g_settings.animationStyle == AnimationStyle::Smooth) {
            styleStiffnessMult = 1.0f;
            styleDampingMult = 1.35f; // Critically damped, no bounciness
        } else if (g_settings.animationStyle == AnimationStyle::Bouncy) {
            styleStiffnessMult = 1.1f;
            styleDampingMult = 0.70f; // Underdamped, lively elasticity
        } else if (g_settings.animationStyle == AnimationStyle::Snappy) {
            styleStiffnessMult = 1.5f;
            styleDampingMult = 1.25f; // High stiffness and quick settle
        }

        const float speed = g_settings.animationSpeed;
        float widthStiffness = 280.0f * styleStiffnessMult;
        float widthDamping = 24.0f * styleDampingMult;
        if (targetWidth > widthSpring.value) {
            widthStiffness = 380.0f * styleStiffnessMult;
            widthDamping = 26.0f * styleDampingMult;
        } else if (targetWidth < widthSpring.value) {
            widthStiffness = 200.0f * styleStiffnessMult;
            widthDamping = 28.0f * styleDampingMult;
        }

        float heightStiffness = 280.0f * styleStiffnessMult;
        float heightDamping = 24.0f * styleDampingMult;
        if (targetHeight > heightSpring.value) {
            heightStiffness = 380.0f * styleStiffnessMult;
            heightDamping = 26.0f * styleDampingMult;
        } else if (targetHeight < heightSpring.value) {
            heightStiffness = 200.0f * styleStiffnessMult;
            heightDamping = 28.0f * styleDampingMult;
        }

        widthSpring.Step(dt * speed, widthStiffness, widthDamping);
        if (widthSpring.value < 0.0f) {
            widthSpring.value = 0.0f;
            widthSpring.velocity = 0.0f;
        }

        heightSpring.Step(dt * speed, heightStiffness, heightDamping);
        if (heightSpring.value < 0.0f) {
            heightSpring.value = 0.0f;
            heightSpring.velocity = 0.0f;
        }

        nudgeSpring.Step(dt * speed, 280.0f * styleStiffnessMult, 24.0f * styleDampingMult);

        {
            std::lock_guard lock(g_stateMutex);
            g_state.system.renderFps = ClampInt(static_cast<int>(1.0f / std::max(dt, 0.001f) + 0.5f), 0, 1000);
        }

        const bool draggingOrHover = hover || ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0 && PtInRect(&windowRect, cursor));
        SetClickThrough(hwnd, (primary.kind == IslandKind::Idle && !draggingOrHover && !pinned));

        // Check if animating structurally
        if (std::abs(widthSpring.velocity) > 0.01f || std::abs(widthSpring.target - widthSpring.value) > 0.01f ||
            std::abs(heightSpring.velocity) > 0.01f || std::abs(heightSpring.target - heightSpring.value) > 0.01f ||
            std::abs(nudgeSpring.velocity) > 0.01f || std::abs(nudgeSpring.target - nudgeSpring.value) > 0.01f) {
            needsRender = true;
        }

        // Active Monitor Tracking (Follow Mouse)
        if (g_settings.targetMonitor == -1) {
            static HMONITOR s_lastMonitor = nullptr;
            POINT pt;
            GetCursorPos(&pt);
            HMONITOR currentMonitor = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
            if (currentMonitor != s_lastMonitor) {
                s_lastMonitor = currentMonitor;
                g_layoutDirty = true;
            }
        }

        // Check if layout was explicitly invalidated
        if (g_layoutDirty.load()) {
            needsRender = true;
        }

        // Hover or pinned state changes visual elements slightly
        static bool prevHover = false;
        static bool prevPinned = false;
        if (hover != prevHover || pinned != prevPinned) {
            needsRender = true;
            prevHover = hover;
            prevPinned = pinned;
        }

        // Animated activities that require continuous rendering
        if (primary.kind == IslandKind::Media || primary.kind == IslandKind::BatteryLow ||
            primary.kind == IslandKind::Clipboard || primary.kind == IslandKind::Notification) {
            needsRender = true;
        }

        // Privacy dots
        if (snapshot.system.micActive || snapshot.system.cameraActive) {
            needsRender = true;
        }
        
        // Idle dashboard clock changes once a minute
        static SYSTEMTIME prevTime = {};
        if (primary.kind == IslandKind::Idle && !isHidden) {
            SYSTEMTIME local = {};
            GetLocalTime(&local);
            if (local.wMinute != prevTime.wMinute) {
                needsRender = true;
                prevTime = local;
            }
        }

        // Compare data snapshot to detect changes
        static uint64_t prevArtGen = 0;
        static uint64_t prevSrcIconGen = 0;
        static uint64_t prevNotifIconGen = 0;
        static uint64_t prevClipIconGen = 0;
        static int prevCpu = -1;
        static int prevRam = -1;
        static int prevDisk = -1;
        static int prevVol = -1;
        static bool prevMuted = false;
        static int prevBat = -1;
        static bool prevCharging = false;
        static int prevProg = -1;
        static std::wstring prevMediaTitle;
        
        if (snapshot.media.artGeneration != prevArtGen ||
            snapshot.media.sourceIconGeneration != prevSrcIconGen ||
            snapshot.media.title != prevMediaTitle ||
            snapshot.notification.icon.generation != prevNotifIconGen ||
            snapshot.clipboard.appIcon.generation != prevClipIconGen ||
            snapshot.system.cpuPercent != prevCpu ||
            snapshot.system.memoryPercent != prevRam ||
            snapshot.system.diskFreePercent != prevDisk ||
            snapshot.system.volumePercent != prevVol ||
            snapshot.system.volumeMuted != prevMuted ||
            snapshot.battery.percent != prevBat ||
            snapshot.battery.charging != prevCharging ||
            snapshot.progress.percent != prevProg) {
            needsRender = true;
            prevArtGen = snapshot.media.artGeneration;
            prevSrcIconGen = snapshot.media.sourceIconGeneration;
            prevMediaTitle = snapshot.media.title;
            prevNotifIconGen = snapshot.notification.icon.generation;
            prevClipIconGen = snapshot.clipboard.appIcon.generation;
            prevCpu = snapshot.system.cpuPercent;
            prevRam = snapshot.system.memoryPercent;
            prevDisk = snapshot.system.diskFreePercent;
            prevVol = snapshot.system.volumePercent;
            prevMuted = snapshot.system.volumeMuted;
            prevBat = snapshot.battery.percent;
            prevCharging = snapshot.battery.charging;
            prevProg = snapshot.progress.percent;
        }

        if (needsRender) {
            renderer.Render(snapshot, g_settings, primary, secondary,
                            widthSpring.value, heightSpring.value, nudgeSpring.value,
                            hover, pinned, now);
        }

        int targetFps = g_settings.targetFps;
        if (targetFps <= 0) {
            targetFps = GetMonitorRefreshRate(hwnd);
        }
        targetFps = ClampInt(targetFps, 30, 1000);
        const double targetFrameMs = 1000.0 / static_cast<double>(targetFps);

        if (!needsRender) {
            // When nothing is animating or changing on screen, sleep 16ms (~60 Hz) to conserve 100% CPU.
            WaitForSingleObject(g_stopEvent, 16);
            nextFrameTarget = std::chrono::steady_clock::now();
        } else {
            // When animating, achieve ultra-smooth target refresh rate (e.g. 144Hz, 240Hz, 360Hz+).
            nextFrameTarget += std::chrono::duration_cast<std::chrono::steady_clock::duration>(
                std::chrono::duration<double, std::milli>(targetFrameMs));
            
            auto nowTime = std::chrono::steady_clock::now();
            if (nowTime < nextFrameTarget) {
                double remainingMs = std::chrono::duration<double, std::milli>(nextFrameTarget - nowTime).count();
                if (remainingMs >= 1.5) {
                    // Sleep for the bulk of the remaining time using OS event wait (zero CPU usage)
                    WaitForSingleObject(g_stopEvent, static_cast<DWORD>(remainingMs - 0.5));
                }
                // Yield for the final fraction of a millisecond to ensure jitter-free presentation on 360Hz displays without CPU waste
                while (std::chrono::steady_clock::now() < nextFrameTarget && 
                       WaitForSingleObject(g_stopEvent, 0) == WAIT_TIMEOUT) {
                    std::this_thread::yield();
                }
            } else {
                // If we fell behind, reset target to avoid speed-up catch-up loop
                nextFrameTarget = nowTime;
            }
        }
    }

    if (pTimeEndPeriod) {
        pTimeEndPeriod(1);
    }

    renderer.Shutdown();
    DestroyWindow(hwnd);
    g_hwnd = nullptr;
    UnregisterClassW(kWindowClass, wc.hInstance);

    if (SUCCEEDED(hrCo)) {
        CoUninitialize();
    }

    return 0;
}



bool StartThreads() {
    g_stopEvent = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    g_settingsChangedEvent = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    if (!g_stopEvent || !g_settingsChangedEvent) {
        return false;
    }

    g_running = true;
    g_renderThread = CreateThread(nullptr, 0, RenderThreadProc, nullptr, 0, nullptr);
    if (!g_renderThread) {
        return false;
    }

    g_mediaThread = CreateThread(nullptr, 0, MediaThreadProc, nullptr, 0, nullptr);
    g_audioThread = CreateThread(nullptr, 0, AudioThreadProc, nullptr, 0, nullptr);
    g_weatherThread = CreateThread(nullptr, 0, WeatherThreadProc, nullptr, 0, nullptr);
    g_keyboardThread = CreateThread(nullptr, 0, KeyboardThreadProc, nullptr, 0, &g_keyboardThreadId);
#if DYNAMIC_ISLAND_HAS_USER_NOTIFICATION_LISTENER
    g_notificationThread = CreateThread(nullptr, 0, NotificationThreadProc, nullptr, 0, nullptr);
#endif

    return true;
}

void StopThreads() {
    if (g_keyboardThreadId != 0) {
        PostThreadMessageW(g_keyboardThreadId, WM_QUIT, 0, 0);
    }
    if (g_stopEvent) {
        SetEvent(g_stopEvent);
    }

    HANDLE handles[] = {g_renderThread, g_mediaThread, g_audioThread, g_weatherThread, g_notificationThread, g_keyboardThread};
    for (HANDLE handle : handles) {
        if (handle) {
            WaitForSingleObject(handle, 3000);
            CloseHandle(handle);
        }
    }

    g_renderThread = nullptr;
    g_mediaThread = nullptr;
    g_audioThread = nullptr;
    g_weatherThread = nullptr;
    g_notificationThread = nullptr;
    g_keyboardThread = nullptr;
    g_keyboardThreadId = 0;

    if (g_stopEvent) {
        CloseHandle(g_stopEvent);
        g_stopEvent = nullptr;
    }
    if (g_settingsChangedEvent) {
        CloseHandle(g_settingsChangedEvent);
        g_settingsChangedEvent = nullptr;
    }

    g_running = false;
}



}  // namespace

BOOL WhTool_ModInit() {
    LoadSettings();

    if (!StartThreads()) {
        StopThreads();
        return FALSE;
    }

    g_layoutDirty = true;
    Wh_Log(L"Dynamic Island for Windows initialized.");
    return TRUE;
}

void WhTool_ModSettingsChanged() {
    LoadSettings();
}

void WhTool_ModUninit() {
    if (g_hwnd) {
        PostMessageW(g_hwnd, WM_CLOSE, 0, 0);
    }
    StopThreads();
    Wh_Log(L"Dynamic Island for Windows unloaded.");
}

//////////////////////////////////////////////////////////////////////////////////
// Windhawk tool mod implementation for mods which don't need to inject to other
// processes or hook other functions. Context:
// https://github.com/ramensoftware/windhawk/wiki/Mods-as-tools:-Running-mods-in-a-dedicated-process
//
// The mod will load and run in a dedicated windhawk.exe process.
//
// Paste the code below as part of the mod code, and use these callbacks:
// * WhTool_ModInit
// * WhTool_ModSettingsChanged
// * WhTool_ModUninit
//
// Currently, other callbacks are not supported.

bool g_isToolModProcessLauncher;
HANDLE g_toolModProcessMutex;

void WINAPI EntryPoint_Hook() {
    Wh_Log(L">");
    ExitThread(0);
}

BOOL Wh_ModInit() {
    DWORD sessionId;
    if (ProcessIdToSessionId(GetCurrentProcessId(), &sessionId) &&
        sessionId == 0) {
        return FALSE;
    }

    bool isExcluded = false;
    bool isToolModProcess = false;
    bool isCurrentToolModProcess = false;
    int argc;
    LPWSTR* argv = CommandLineToArgvW(GetCommandLine(), &argc);
    if (!argv) {
        Wh_Log(L"CommandLineToArgvW failed");
        return FALSE;
    }

    for (int i = 1; i < argc; i++) {
        if (wcscmp(argv[i], L"-service") == 0 ||
            wcscmp(argv[i], L"-service-start") == 0 ||
            wcscmp(argv[i], L"-service-stop") == 0) {
            isExcluded = true;
            break;
        }
    }

    for (int i = 1; i < argc - 1; i++) {
        if (wcscmp(argv[i], L"-tool-mod") == 0) {
            isToolModProcess = true;
            if (wcscmp(argv[i + 1], WH_MOD_ID) == 0) {
                isCurrentToolModProcess = true;
            }
            break;
        }
    }

    LocalFree(argv);

    if (isExcluded) {
        return FALSE;
    }

    if (isCurrentToolModProcess) {
        g_toolModProcessMutex =
            CreateMutex(nullptr, TRUE, L"windhawk-tool-mod_" WH_MOD_ID);
        if (!g_toolModProcessMutex) {
            Wh_Log(L"CreateMutex failed");
            ExitProcess(1);
        }

        if (GetLastError() == ERROR_ALREADY_EXISTS) {
            Wh_Log(L"Tool mod already running (%s)", WH_MOD_ID);
            ExitProcess(1);
        }

        if (!WhTool_ModInit()) {
            ExitProcess(1);
        }

        IMAGE_DOS_HEADER* dosHeader =
            (IMAGE_DOS_HEADER*)GetModuleHandle(nullptr);
        IMAGE_NT_HEADERS* ntHeaders =
            (IMAGE_NT_HEADERS*)((BYTE*)dosHeader + dosHeader->e_lfanew);

        DWORD entryPointRVA = ntHeaders->OptionalHeader.AddressOfEntryPoint;
        void* entryPoint = (BYTE*)dosHeader + entryPointRVA;

        Wh_SetFunctionHook(entryPoint, (void*)EntryPoint_Hook, nullptr);
        return TRUE;
    }

    if (isToolModProcess) {
        return FALSE;
    }

    g_isToolModProcessLauncher = true;
    return TRUE;
}

void Wh_ModAfterInit() {
    if (!g_isToolModProcessLauncher) {
        return;
    }

    WCHAR currentProcessPath[MAX_PATH];
    switch (GetModuleFileName(nullptr, currentProcessPath,
                              ARRAYSIZE(currentProcessPath))) {
        case 0:
        case ARRAYSIZE(currentProcessPath):
            Wh_Log(L"GetModuleFileName failed");
            return;
    }

    WCHAR
    commandLine[MAX_PATH + 2 +
                (sizeof(L" -tool-mod \"" WH_MOD_ID "\"") / sizeof(WCHAR)) - 1];
    swprintf_s(commandLine, L"\"%s\" -tool-mod \"%s\"", currentProcessPath,
               WH_MOD_ID);

    HMODULE kernelModule = GetModuleHandle(L"kernelbase.dll");
    if (!kernelModule) {
        kernelModule = GetModuleHandle(L"kernel32.dll");
        if (!kernelModule) {
            Wh_Log(L"No kernelbase.dll/kernel32.dll");
            return;
        }
    }

    using CreateProcessInternalW_t = BOOL(WINAPI*)(
        HANDLE hUserToken, LPCWSTR lpApplicationName, LPWSTR lpCommandLine,
        LPSECURITY_ATTRIBUTES lpProcessAttributes,
        LPSECURITY_ATTRIBUTES lpThreadAttributes, WINBOOL bInheritHandles,
        DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory,
        LPSTARTUPINFOW lpStartupInfo,
        LPPROCESS_INFORMATION lpProcessInformation,
        PHANDLE hRestrictedUserToken);
    CreateProcessInternalW_t pCreateProcessInternalW =
        (CreateProcessInternalW_t)GetProcAddress(kernelModule,
                                                 "CreateProcessInternalW");
    if (!pCreateProcessInternalW) {
        Wh_Log(L"No CreateProcessInternalW");
        return;
    }

    STARTUPINFO si{
        .cb = sizeof(STARTUPINFO),
        .dwFlags = STARTF_FORCEOFFFEEDBACK,
    };
    PROCESS_INFORMATION pi;
    if (!pCreateProcessInternalW(nullptr, currentProcessPath, commandLine,
                                 nullptr, nullptr, FALSE, NORMAL_PRIORITY_CLASS,
                                 nullptr, nullptr, &si, &pi, nullptr)) {
        Wh_Log(L"CreateProcess failed");
        return;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void Wh_ModSettingsChanged() {
    if (g_isToolModProcessLauncher) {
        return;
    }

    WhTool_ModSettingsChanged();
}

void Wh_ModUninit() {
    if (g_isToolModProcessLauncher) {
        return;
    }

    WhTool_ModUninit();
    ExitProcess(0);
}