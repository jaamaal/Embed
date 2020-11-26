@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL timeprovision.cpp timeprovision.def /MT /link /DLL /OUT:timeprovision.dll
