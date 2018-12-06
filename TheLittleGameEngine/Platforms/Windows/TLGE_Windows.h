#ifndef __TLGE__WINDOWS_H__
#define __TLGE__WINDOWS_H__

#include <windows.h>
#include <windowsx.h>
#include "../Libraries/SDL2/include/SDL.h"
#include "../Libraries/SDL2_mixer/include/SDL_mixer.h"
#include "WindowManager_Windows.h"
#include "SoundManagerWin32.h"

//Only the basics
#define WIN32_LEAN_AND_MEAN

//Windows "entry point"
int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousInstanceHandle, LPSTR comandLine, int showCommand);

//Input handling function
LRESULT CALLBACK WndProc(HWND windowHandle, UINT message, WPARAM unsignedIntParam, LPARAM longParam);

void WIN32_BindFunctions();

#endif