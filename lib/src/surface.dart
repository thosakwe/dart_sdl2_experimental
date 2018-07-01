part of sdl2;

class Surface {
  final int _window, _pointer;

  Surface._(this._window, this._pointer);

  static String _surfaceFillRect(int pointer, Rectangle<int> rect, int color)
      native "DartSdl2_surfaceFillRect";

  static int _surfaceFormat(int pointer) native "DartSdl2_surfaceFormat";

  static String _surfaceUpdate(int windowPointer)
      native "DartSdl2_surfaceUpdate";

  PixelFormat get format => new PixelFormat(_surfaceFormat(_pointer));

  void fill(int color) {
    var result = _surfaceFillRect(_pointer, null, color);
    if (result != null) throw new SdlException(result);
  }

  void update() {
    var result = _surfaceUpdate(_window);
    if (result != null) throw new SdlException(result);
  }
}
