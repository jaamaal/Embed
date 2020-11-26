@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL windowsspool.cpp /MT /link /DLL /OUT:windowsspool.drv
