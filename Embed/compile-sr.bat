@ECHO OFF

cl.exe /nologo /Ox /MT /W0 /GS- /DNDEBUG /Tcembed-srv.cpp /link /OUT:embed-srv.exe /MACHINE:x64
