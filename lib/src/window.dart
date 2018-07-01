part of sdl2;

const int windowPosUndefinedMask = 0x1FFF0000;

int windowPosUndefinedDisplay(int x) => windowPosUndefinedMask | x;

final int windowPosUndefined = windowPosUndefinedDisplay(0);

bool windowPosIsUndefined(int x) =>
    (((x) & 0xFFFF0000) == windowPosUndefinedMask);

///  Used to indicate that the window position should be centered.
const int windowPosCenteredMask = 0x2FFF0000;

int windowPosCenteredDisplay(int x) => (windowPosCenteredMask | (x));

final int windowPosCentered = windowPosCenteredDisplay(0);

bool windowPosIsCentered(int x) =>
    (((x) & 0xFFFF0000) == windowPosCenteredMask);

class Window {
  final int _pointer;

  Window._(this._pointer);

  factory Window(String title, int x, int y, int w, int h, int flags) {
    var result = _createWindow(title, x, y, w, h, flags);
    if (result[0] != null) throw new SdlException(result[0] as String);
    return new Window._(result[1] as int);
  }

  static List _createWindow(String title, int x, int y, int w, int h, int flags)
      native "DartSdl2_createWindow";

  static List _windowGetSurface(int pointer) native "DartSdl2_windowGetSurface";

  Surface get surface {
    var result = _windowGetSurface(_pointer);
    if (result[0] != null) throw new SdlException(result[0] as String);
    return new Surface._(_pointer, result[1] as int);
  }
}

/// The flags on a window
abstract class WindowFlags {
  static const int

      /// fullscreen window
      windowFullscreen = 0x00000001,

      /// window usable with OpenGL context
      windowOpenGL = 0x00000002,

      /// window is visible
      windowShown = 0x00000004,

      /// window is not visible
      windowHidden = 0x00000008,

      /// no window decoration
      windowBorderless = 0x00000010,

      /// window can be resized
      windowResizable = 0x00000020,

      /// window is minimized
      windowMinimized = 0x00000040,

      /// window is maximized
      windowMaximized = 0x00000080,

      /// window has grabbed input focus
      windowInputGrabbed = 0x00000100,

      /// window has input focus
      windowInputFocus = 0x00000200,

      /// window has mouse focus
      windowMouseFocus = 0x00000400,
      windowFullscreenDesktop = (windowFullscreen | 0x00001000),

      /// window not created by SDL
      windowForeign = 0x00000800,

      /// window should be created in high-DPI mode if supported.
      /// On macOS NSHighResolutionCapable must be set true in the
      // application's Info.plist for this to have any effect.
      windowAllowHighDpi = 0x00002000,

      /// window has mouse captured (unrelated to INPUT_GRABBED)
      windowMouseCapture = 0x00004000,

      /// window should always be above others
      windowAlwaysOnTop = 0x00008000,

      /// window should not be added to the taskbar
      windowSkipTaskbar = 0x00010000,

      /// window should be treated as a utility window
      windowUtility = 0x00020000,

      /// window should be treated as a tooltip
      windowTooltip = 0x00040000,

      /// window should be treated as a popup menu
      windowPopupMenu = 0x00080000,

      /// window usable for Vulkan surface
      windowVulkan = 0x10000000;
}
