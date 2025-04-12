#pragma once

#include <Windows.h>
#include <iostream>

extern HHOOK g_mouseHook;
extern HHOOK g_keyboardHook;

LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
DWORD WINAPI hookThread(LPVOID lpParam);
