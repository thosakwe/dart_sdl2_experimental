#ifndef DART_SDL_H
#define DART_SDL_H
#include <dart_api.h>
#include <SDL.h>

Dart_Handle HandleError(Dart_Handle handle);

void DartSdl2_createWindow(Dart_NativeArguments arguments);
void DartSdl2_delay(Dart_NativeArguments arguments);
void DartSdl2_init(Dart_NativeArguments arguments);
void DartSdl2_pixelFormatMapRgb(Dart_NativeArguments arguments);
void DartSdl2_surfaceFillRect(Dart_NativeArguments arguments);
void DartSdl2_surfaceFormat(Dart_NativeArguments arguments);
void DartSdl2_surfaceUpdate(Dart_NativeArguments arguments);
void DartSdl2_windowGetSurface(Dart_NativeArguments arguments);
void DartSdl2_quit(Dart_NativeArguments arguments);

#endif