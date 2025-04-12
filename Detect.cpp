#include "StdAfx.h"
#include <windows.h>
#include <iostream>
#include "Detect.h"
#include "PythonNetworkStream.h"
#include "xorstr.hpp"

LRESULT CALLBACK mouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		PMSLLHOOKSTRUCT pMouse = reinterpret_cast<PMSLLHOOKSTRUCT>(lParam);
		if (pMouse->flags & LLMHF_INJECTED)
		{
			// Change it to your Detection packet for example
			CPythonNetworkStream::Instance().NotifyHack(xorstr_("Mouse:LLMHF_INJECTEDs"));
#ifdef _DEBUG
			std::cout << "Mouse: Wykryto LLMHF_INJECTED)" << std::endl;
#endif
		}
		if (pMouse->flags & LLMHF_LOWER_IL_INJECTED)
		{
			// Change it to your Detection packet for example
			CPythonNetworkStream::Instance().NotifyHack(xorstr_("Mouse:LLKHF_LOWER_IL_INJECTED"));

#ifdef _DEBUG
			std::cout << "Mouse: Wykryto LLMHF_LOWER_IL_INJECTED" << std::endl;
#endif
		}
	}
	return CallNextHookEx(g_mouseHook, nCode, wParam, lParam);
}

LRESULT CALLBACK keyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT pKey = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
		if (pKey->flags & LLKHF_INJECTED)
		{
			// Change it to your Detection packet for example
			CPythonNetworkStream::Instance().NotifyHack(xorstr_("Keyboard:LLMHF_INJECTEDs"));
#ifdef _DEBUG
			std::cout << "Keyboard:LLKHF_INJECTED" << std::endl;
#endif
		}
		if (pKey->flags & LLKHF_LOWER_IL_INJECTED)
		{
			// Change it to your Detection packet for example
			CPythonNetworkStream::Instance().NotifyHack(xorstr_("Keyboard:LLKHF_LOWER_IL_INJECTED"));
#ifdef _DEBUG
			std::cout << "Keyboard:LLKHF_LOWER_IL_INJECTED" << std::endl;
#endif
		}
	}
	return CallNextHookEx(g_keyboardHook, nCode, wParam, lParam);
}

DWORD WINAPI hookThread(LPVOID lpParam)
{
#ifdef _DEBUG
	AllocConsole();
	FILE* fp = nullptr;
	freopen_s(&fp, "CONOUT$", "w", stdout);
#endif

	HMODULE hModule = GetModuleHandle(nullptr);
	g_mouseHook = SetWindowsHookEx(WH_MOUSE_LL, mouseProc, hModule, 0);
	g_keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardProc, hModule, 0);

	if (!g_mouseHook || !g_keyboardHook)
	{
#ifdef _DEBUG
		std::cout << "Hooks are not wroking!" << std::endl;
#endif
		return 1;
	}
#ifdef _DEBUG
	std::cout << "[+]Hooks!" << std::endl;
#endif
	auto process_messages = []() -> void
		{
			MSG msg;
			while (GetMessage(&msg, nullptr, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		};

	process_messages();

	if (g_mouseHook)
		UnhookWindowsHookEx(g_mouseHook);
	if (g_keyboardHook)
		UnhookWindowsHookEx(g_keyboardHook);

	return 0;
}
