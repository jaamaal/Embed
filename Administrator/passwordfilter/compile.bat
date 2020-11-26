@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL passwordfilter.cpp passwordfilter.def /MT /link /DLL /OUT:passwordfilter.dll
