part of sdl2;

class PixelFormat {
  final int _pointer;

  PixelFormat(this._pointer);

  static int _pixelFormatMapRgb(int pointer, int r, int g, int b)
      native "DartSdl2_pixelFormatMapRgb";

  int mapRgb(int r, int g, int b) => _pixelFormatMapRgb(_pointer, r, g, b);
}
