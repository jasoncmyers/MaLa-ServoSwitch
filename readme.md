# ServoStik MaLa Plugin

This is a plugin for the MaLa MAME (Multiple Arcade Machine Emulator) frontend.  It allows the MaLa menu system to interact with Ultimarc ServoStik joysticks and automates the switching between 4- and 8-way joystick positions.

The program should be compiled to a DLL, which is then renamed to a .mplugin file and placed in the MaLa plugins directory.  In its current form, the plugin defaults to 8-way joystick control for menus, and it does not attempt to change configurations when loading an 8-way game.  When loading a game that uses a 4-way joystick control, however, it will trigger the ServoStik to switch the restrictor plate to 4-way mode as the game is launched, and trigger a return to 8-way mode on exit.

Compiling the plugin requires the PacDrive.h header file and PacDrive32.dll or PacDrive64.dll from the Ultimarc PacDrive SDK, which can be found [here](https://www.ultimarc.com/programming.html).