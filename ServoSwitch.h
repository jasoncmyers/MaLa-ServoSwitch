#ifndef __MALA_SERVOSWITCH__
#define __MALA_SERVOSWITCH__

struct EventGame
{
	const char* Description;
	const char* Rom;
	const char* CloneOf;
	const char* Manufacturer;
	const char* Genre;
	int Year;
	int InputButtons;
	int InputCoins;
	const char* InputPlayers;
	const char* InputControl;
	const char* VideoScreen;
	const char* VideoOrientation;
	int VideoWidth;
	int VideoHeight;
	const char* DriverStatus;
	const char* Controls;
	const char* JoyUp;
	const char* JoyDown;
	const char* JoyLeft;
	const char* JoyRight;
	const char* Button1;
	const char* Button2;
	const char* Button3;
	const char* Button4;
	const char* Button5;
	const char* Button6;
	const char* Button7;
	const char* Button8;
	const char* Details;
	const char* RomPath;
	const char* Extension;
	int Played;
};

struct EventEmulator
{
	const char* Name;
	const char* Filename;
	const char* RomPath;
	const char* Extensions;
	const char* Commandline;
	const char* SnapPath;
	const char* MarqueePath;
	const char* CPanelPath;
	const char* VideoPath;
	const char* EncoderConfigFile;
	int EncoderGameBased;
	const char* EncoderConfigFilesPath;
	const char* EncoderConfigFileExtension;
};

struct EventGamelist
{
	const char* Name;
	int GameCount;
	int FilterCount;
};

struct EventTree
{
	const char* Name;
	int NodeCount;
	int Menu;
};

#endif