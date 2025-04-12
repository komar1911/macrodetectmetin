# MacroDetectMetin
Macro Detector for Metin2 (Mouse and Keyboard)

<h3><strong>PLEASE READ!!!</strong></h3>

<h2><strong style="color: red;">⚠️ PLEASE DONT BAN PEOPLE AFTER DETECTION! VERIFY MANUAL THAT PLAYER IS CHEATING!!! ⚠️</strong></h2>

<h3>Sometimes it can do false positives from Mouse / Keyboard software (but 90% of them do it from their Kernel Driver)</h3>



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

