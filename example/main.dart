import 'dart:isolate';
import 'package:sdl2/sdl2.dart' as sdl2;

main() {
  var recv = new ReceivePort();
  Isolate.spawn(uiMain, null, onExit: recv.sendPort);
  return recv.first;
}

void uiMain(_) {
  sdl2.init(sdl2.initVideo);

  var wnd = new sdl2.Window(
    'Hello!',
    sdl2.windowPosUndefined,
    sdl2.windowPosUndefined,
    800,
    600,
    sdl2.WindowFlags.windowShown,
  );

  wnd.surface
    ..fill(wnd.surface.format.mapRgb(0xFF, 0xFF, 0xFF))
    ..update();

  sdl2.delay(10000);
  sdl2.quit();
}
