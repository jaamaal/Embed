# Windows-Persistence
![](https://img.shields.io/badge/Windows-Compatible-green.svg)

Real threat actors use different Tactics, Techniques and Procedures (TTPs). One of the strategy is Persistence - an approach to endure a penetrated machine restart and protect admittance to a target environment. There is a ton of spotlight on what strategies use to exploit a specific vulnerability or how their C2 channels & infrastructure resemble.

Adapt practically persistence steadiness strategies working at Windows 10 utilized by sponsored nation-state threat actors, as Turla, ProjectSauron, APT29, EquationGroup, including Stuxnet / Flame.
## System Requirements
*	x86-32/x64 Windows 7/8/8.1/10, x86-32/x64 Widnows Server 2012/2016/2019.
*	Administrator account with UAC set on default settings needed.
## Usage
Run executable from command line: embed [Param] or embed-sr [Param]. See "Run examples" underneath for more info.

Run examples:

*	embed.exe "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
*	echo embed-sr.exe %HOMEPATH%"\Documents\Windowspowershell\profile.ps1
*	schtasks /create /sc onlogon /tn AdobeFlashSync /tr "embed.exe"

