# MacroDetectMetin
Macro Detector for Metin2 (Mouse and Keyboard)




add in UserInterface.cpp

#include "Detect.h"

in Main

	HANDLE hThread = CreateThread(nullptr, 0, hookThread, nullptr, 0, nullptr);
	if (hThread) {
		CloseHandle(hThread);
	}





Video:


https://github.com/user-attachments/assets/f8d61796-2d99-40b5-990c-44796f60622a



https://github.com/user-attachments/assets/c94486a7-1d98-49a8-b02c-cf365892348f

