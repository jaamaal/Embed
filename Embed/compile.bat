@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcembed.cpp /link /OUT:embed.exe /SUBSYSTEM:WINDOWS
