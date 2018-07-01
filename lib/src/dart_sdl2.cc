#include <cstdlib>
#include <iostream>
#include <string.h>
#include <dart_api.h>
#include "dart_sdl2.h"

// Forward declaration of ResolveName function.
Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool *auto_setup_scope);

// The name of the initialization function is the extension name followed
// by _Init.
DART_EXPORT Dart_Handle dart_sdl2_Init(Dart_Handle parent_library)
{
  if (Dart_IsError(parent_library))
    return parent_library;

  Dart_Handle result_code =
      Dart_SetNativeResolver(parent_library, ResolveName, NULL);
  if (Dart_IsError(result_code))
    return result_code;

  return Dart_Null();
}

Dart_Handle HandleError(Dart_Handle handle)
{
  if (Dart_IsError(handle))
    Dart_PropagateError(handle);
  return handle;
}

Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool *auto_setup_scope)
{
  // If we fail, we return NULL, and Dart throws an exception.
  if (!Dart_IsString(name))
    return NULL;
  Dart_NativeFunction result = NULL;
  const char *cname;
  HandleError(Dart_StringToCString(name, &cname));

  if (strcmp("DartSdl2_createWindow", cname) == 0)
    result = DartSdl2_createWindow;
  else if (strcmp("DartSdl2_delay", cname) == 0)
    result = DartSdl2_delay;
  else if (strcmp("DartSdl2_init", cname) == 0)
    result = DartSdl2_init;
  else if (strcmp("DartSdl2_pixelFormatMapRgb", cname) == 0)
    result = DartSdl2_pixelFormatMapRgb;
  else if (strcmp("DartSdl2_surfaceFillRect", cname) == 0)
    result = DartSdl2_surfaceFillRect;
  else if (strcmp("DartSdl2_surfaceFormat", cname) == 0)
    result = DartSdl2_surfaceFormat;
  else if (strcmp("DartSdl2_surfaceUpdate", cname) == 0)
    result = DartSdl2_surfaceUpdate;
  else if (strcmp("DartSdl2_windowGetSurface", cname) == 0)
    result = DartSdl2_windowGetSurface;
  else if (strcmp("DartSdl2_quit", cname) == 0)
    result = DartSdl2_quit;
  return result;
}