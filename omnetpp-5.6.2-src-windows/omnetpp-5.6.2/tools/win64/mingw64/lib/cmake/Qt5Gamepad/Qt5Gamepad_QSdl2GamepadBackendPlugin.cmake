
add_library(Qt5::QSdl2GamepadBackendPlugin MODULE IMPORTED)

_populate_Gamepad_plugin_properties(QSdl2GamepadBackendPlugin RELEASE "gamepads/sdl2gamepad.dll")
_populate_Gamepad_plugin_properties(QSdl2GamepadBackendPlugin DEBUG "gamepads/sdl2gamepadd.dll")

list(APPEND Qt5Gamepad_PLUGINS Qt5::QSdl2GamepadBackendPlugin)
