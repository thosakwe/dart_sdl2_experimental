#include "dart_sdl2.h"

void DartSdl2_delay(Dart_NativeArguments arguments)
{
    Dart_Handle msHandle = Dart_GetNativeArgument(arguments, 0);
    uint64_t ms;
    HandleError(Dart_IntegerToUint64(msHandle, &ms));
    SDL_Delay((Uint32)ms);
}

void DartSdl2_init(Dart_NativeArguments arguments)
{
    Dart_Handle flagsHandle = Dart_GetNativeArgument(arguments, 0);
    uint64_t flags;
    HandleError(Dart_IntegerToUint64(flagsHandle, &flags));

    if (SDL_Init((Uint32)flags) != 0)
    {
        Dart_SetReturnValue(arguments, Dart_NewStringFromCString(SDL_GetError()));
    }
}

void DartSdl2_quit(Dart_NativeArguments arguments)
{
    SDL_Quit();
}