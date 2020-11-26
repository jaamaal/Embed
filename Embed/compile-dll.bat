@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL embed-dll.cpp /MT /link /DLL /OUT:embed.dll
