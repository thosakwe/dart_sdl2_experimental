part of sdl2;

void delay(int ms) native "DartSdl2_delay";

String _init(int flags) native "DartSdl2_init";

void init(int flags) {
  var result = _init(flags);
  if (result != null) throw new SdlException(result);
}

void quit() native "DartSdl2_quit";

const int initTimer = 0x00000001;

const int initAudio = 0x00000010;

/// Implies [initEvents].
const int initVideo = 0x00000020;

/// Implies [initEvents].
const int initJoystick = 0x00000200;

const int initHaptic = 0x00001000;

/// Implies [initJoystick].
const int initGameController = 0x00002000;

const int initEvents = 0x00004000;

/// compatibility; this flag is ignored.
const int initNoParachute = 0x00100000;

const int initEverything = initTimer |
    initAudio |
    initVideo |
    initEvents |
    initJoystick |
    initHaptic |
    initGameController;
