@ECHO OFF

cl.exe /W0 /D_USRDLL /D_WINDLL FoldersShell.cpp FoldersShell.def /MT /link /DLL /OUT:FoldersShell.dll
