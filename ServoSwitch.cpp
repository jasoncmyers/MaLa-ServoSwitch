// ServoSwitch.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "ServoSwitch.h"
#include <string>
#include <vector>
#include "PacDrive.h"


#ifdef _MANAGED
#pragma managed(push, off)
#endif

#define DLL __declspec(dllexport)

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	return TRUE;
}

static std::vector<std::string> FourWayGames;
static bool isFourWayGame = false;
static bool isFourWayStick = false;

/******************************************************************************
*
******************************************************************************/
void WriteToFile(const char* text)
{
	FILE *f;
	fopen_s(&f, "4way.log", "a");
	fprintf(f, text);
	fclose(f);
}

/******************************************************************************
*
******************************************************************************/
void Switch4Way()
{
	
	if (!isFourWayStick) {
		//WriteToFile("Joystick to 4-way mode\n\n");
		if (PacSetServoStik4Way())
		{
			//WriteToFile("Successfully switched to 4-way mode");
			isFourWayStick = true;
		}
		else
		{
			//WriteToFile("Failed to switch to 4-way mode");
		}
	}
}

/******************************************************************************
*
******************************************************************************/
void Switch8Way()
{
	if (isFourWayStick) {
		//WriteToFile("Joystick to 8-way mode\n\n");
		if (PacSetServoStik8Way())
		{
			//WriteToFile("Successfully switched to 8-way mode");
			isFourWayStick = false;
		}
		else
		{
			//WriteToFile("Failed to switch to 8-way mode");
		}
	}
}

/******************************************************************************
*
******************************************************************************/
void ReadGameFile()
{
	//WriteToFile("Starting game list: \n\n");
	
	std::string line;
	std::ifstream listfile("4waygames.lst");
	if (listfile.is_open()) 
	{
		//WriteToFile("List file opened successfully\n\n");
		while (std::getline(listfile, line))
		{
			FourWayGames.push_back(line);
			//WriteToFile("Reading a game\n");
		}
	}
	else {
		//WriteToFile("Read file failed\n\n");
	}
	
	//char buf[500];
	//sprintf_s(buf, "Game list size:%i\n\n", FourWayGames.size());
	//WriteToFile(buf);
	
	/*for (size_t i = 0; i < (FourWayGames.size()); i++)
	{
		char text[500];
		sprintf_s(text, "Game #:%i\n", i);
		WriteToFile(text);
		char text2[500];
		sprintf_s(text2, "%s\n\n", FourWayGames[i].c_str());
		WriteToFile(text2);
	}
	//WriteToFile("Ending game list/n/n/n");*/
}

/******************************************************************************
*
******************************************************************************/
extern "C" DLL void MaLaStart()
{
	PacInitialize();
	ReadGameFile();
	Switch8Way();

}

/******************************************************************************
*
******************************************************************************/
extern "C" DLL void MaLaQuit()
{
	PacShutdown();
}


/******************************************************************************
*
******************************************************************************/
extern "C" DLL void MaLaGameSelected(EventGame* g)
{
	isFourWayGame = false;
	for (size_t i = 0; i < (FourWayGames.size()); i++)
	{
		if (strcmp(g->Rom, FourWayGames[i].c_str()) == 0) {
			isFourWayGame = true;
			break;
		}
	}

	/*char buf[500];
	sprintf_s(buf, "Game %s is %i for 4way\n", g->Rom, (int)isFourWayGame);
	WriteToFile(buf); */
}

/******************************************************************************
*
******************************************************************************/
extern "C" DLL void MaLaGameStart()
{
	//WriteToFile("Beginning game\n");
	if (isFourWayGame) {
		Switch4Way();
	}
}

/******************************************************************************
*
******************************************************************************/
extern "C" DLL void MaLaGameQuit()
{
	//WriteToFile("Returning from game\n");
	Switch8Way();
}

/******************************************************************************
*
******************************************************************************/
extern "C" DLL const char* PluginName()
{
	return "ServoSwitch v0.9";
}

/******************************************************************************
*
******************************************************************************/
extern "C" DLL const char* PluginCopyright()
{
	return "2014 by J.C. Myers";
}

#ifdef _MANAGED
#pragma managed(pop)
#endif