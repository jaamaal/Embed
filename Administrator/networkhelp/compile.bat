@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL networkhelp.cpp /MT /link /DLL /OUT:networkhelp.dll
