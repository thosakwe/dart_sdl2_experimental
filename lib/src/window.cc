#include "dart_sdl2.h"

void DartSdl2_createWindow(Dart_NativeArguments arguments)
{
    Dart_Handle titleHandle = Dart_GetNativeArgument(arguments, 0);
    Dart_Handle xHandle = Dart_GetNativeArgument(arguments, 1);
    Dart_Handle yHandle = Dart_GetNativeArgument(arguments, 2);
    Dart_Handle wHandle = Dart_GetNativeArgument(arguments, 3);
    Dart_Handle hHandle = Dart_GetNativeArgument(arguments, 4);
    Dart_Handle flagsHandle = Dart_GetNativeArgument(arguments, 5);
    const char *title;
    int64_t x, y, w, h;
    uint64_t flags;

    HandleError(Dart_StringToCString(titleHandle, &title));
    HandleError(Dart_IntegerToInt64(xHandle, &x));
    HandleError(Dart_IntegerToInt64(yHandle, &y));
    HandleError(Dart_IntegerToInt64(wHandle, &w));
    HandleError(Dart_IntegerToInt64(hHandle, &h));
    HandleError(Dart_IntegerToUint64(flagsHandle, &flags));

    SDL_Window *window = SDL_CreateWindow(title, (int)x, (int)y, (int)w, (int)h, (Uint32)flags);
    Dart_Handle result = Dart_NewList(2);

    if (window == nullptr)
    {
        Dart_ListSetAt(result, 0, Dart_NewStringFromCString(SDL_GetError()));
    }
    else
    {
        Dart_ListSetAt(result, 1, Dart_NewIntegerFromUint64((uint64_t)window));
    }

    Dart_SetReturnValue(arguments, result);
}

void DartSdl2_windowGetSurface(Dart_NativeArguments arguments)
{
    Dart_Handle pointerHandle = Dart_GetNativeArgument(arguments, 0);
    uint64_t pointer;

    HandleError(Dart_IntegerToUint64(pointerHandle, &pointer));

    SDL_Surface *surface = SDL_GetWindowSurface((SDL_Window *)pointer);
    Dart_Handle result = Dart_NewList(2);

    if (surface == nullptr)
    {
        Dart_ListSetAt(result, 0, Dart_NewStringFromCString(SDL_GetError()));
    }
    else
    {
        Dart_ListSetAt(result, 1, Dart_NewIntegerFromUint64((uint64_t)surface));
    }

    Dart_SetReturnValue(arguments, result);
}