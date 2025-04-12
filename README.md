# MacroDetectMetin
Macro Detector for Metin2 (Mouse and Keyboard)




add in UserInterface.cpp

#include "Detect.h"

in Main

	HANDLE hThread = CreateThread(nullptr, 0, hookThread, nullptr, 0, nullptr);
	if (hThread) {
		CloseHandle(hThread);
	}
