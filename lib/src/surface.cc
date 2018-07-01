#include "dart_sdl2.h"

void DartSdl2_surfaceFillRect(Dart_NativeArguments arguments)
{
    // int pointer, Rectangle<int> rect, int color
    Dart_Handle pointerHandle = Dart_GetNativeArgument(arguments, 0);
    Dart_Handle rectangleHandle = Dart_GetNativeArgument(arguments, 1);
    Dart_Handle colorHandle = Dart_GetNativeArgument(arguments, 2);
    SDL_Rect *rect = nullptr;
    uint64_t pointer, color;
    HandleError(Dart_IntegerToUint64(pointerHandle, &pointer));
    HandleError(Dart_IntegerToUint64(colorHandle, &color));
    // TODO: Read in rectangle

    auto *surface = (SDL_Surface *)pointer;
    if (SDL_FillRect(surface, rect, color) != 0)
    {
        Dart_SetReturnValue(arguments, Dart_NewStringFromCString(SDL_GetError()));
    }
}

void DartSdl2_surfaceFormat(Dart_NativeArguments arguments)
{
    Dart_Handle pointerHandle = Dart_GetNativeArgument(arguments, 0);
    uint64_t pointer;
    HandleError(Dart_IntegerToUint64(pointerHandle, &pointer));

    auto *surface = (SDL_Surface *)pointer;
    Dart_SetReturnValue(arguments, Dart_NewIntegerFromUint64((uint64_t)surface->format));
}

void DartSdl2_surfaceUpdate(Dart_NativeArguments arguments)
{
    Dart_Handle windowHandle = Dart_GetNativeArgument(arguments, 0);
    uint64_t window;
    HandleError(Dart_IntegerToUint64(windowHandle, &window));

    if (SDL_UpdateWindowSurface((SDL_Window *)window) != 0)
    {
        Dart_SetReturnValue(arguments, Dart_NewStringFromCString(SDL_GetError()));
    }
}