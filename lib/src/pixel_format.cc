#include "dart_sdl2.h"

void DartSdl2_pixelFormatMapRgb(Dart_NativeArguments arguments)
{
    Dart_Handle pointerHandle = Dart_GetNativeArgument(arguments, 0);
    Dart_Handle rHandle = Dart_GetNativeArgument(arguments, 1);
    Dart_Handle gHandle = Dart_GetNativeArgument(arguments, 2);
    Dart_Handle bHandle = Dart_GetNativeArgument(arguments, 3);
    uint64_t pointer, r, g, b;

    HandleError(Dart_IntegerToUint64(pointerHandle, &pointer));
    HandleError(Dart_IntegerToUint64(rHandle, &r));
    HandleError(Dart_IntegerToUint64(gHandle, &g));
    HandleError(Dart_IntegerToUint64(bHandle, &b));

    auto *pixelFormat = (SDL_PixelFormat *)pointer;
    Dart_SetReturnValue(arguments, Dart_NewIntegerFromUint64((uint64_t)SDL_MapRGB(pixelFormat, (Uint8)r, (Uint8)g, (Uint8)b)));
}