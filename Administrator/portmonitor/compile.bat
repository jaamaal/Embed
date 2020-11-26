@ECHO OFF

cl.exe /W0 portmonitor.cpp portmonitor.def /MT /link /DLL /OUT:portmonitor.dll
