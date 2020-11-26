@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL cert.cpp cert.def /MT /link /DLL /OUT:cert.dll
