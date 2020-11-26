@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL tester.cpp /MT /link /DLL /OUT:tester.dll
