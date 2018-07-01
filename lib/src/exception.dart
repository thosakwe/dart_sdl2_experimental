part of sdl2;

class SdlException implements Exception {
  final String message;

  SdlException(this.message);

  @override
  String toString() => message;
}
