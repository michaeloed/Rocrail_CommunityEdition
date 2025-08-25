; -- freerail.iss --

[Setup]
AppName=FreeRail
AppVerName=FreeRail -rev<BZR>
DefaultDirName=C:\FreeRail
DefaultGroupName=FreeRail
UninstallDisplayIcon=C:\FreeRail\rocview.exe
Compression=lzma
SolidCompression=yes
DirExistsWarning=auto
OutputDir=..\..\package
AppCopyright=tbd
AppPublisher=tbd
AppPublisherURL=https://www.github.com/michaeloed/FreeRail
OutputBaseFilename=freerail-root-<BZR>-win32
DisableDirPage=yes

[Tasks]
Name: demoplan; Description: "Demo plan"
Name: images; Description: "Loco images"
Name: themes; Description: "SVG Themes"
Name: americanthemes; Description: "SVG American Themes"; Flags: unchecked

[Files]
Source: "..\..\winbin\freerail.exe"; DestDir: "C:\FreeRail"
Source: "stopservice.cmd"; DestDir: "C:\FreeRail"
Source: "mkservice.cmd"; DestDir: "C:\FreeRail"
Source: "..\..\winbin\rocview.exe"; DestDir: "C:\FreeRail"
Source: "..\..\winbin\*.dll"; DestDir: "C:\FreeRail"
Source: "plan.xml"; DestDir: "C:\FreeRail\Demo"; Tasks: demoplan; Flags: onlyifdoesntexist uninsneveruninstall
Source: "rocview.ini"; DestDir: "C:\FreeRail"; Flags: onlyifdoesntexist uninsneveruninstall
Source: "freerail.mib"; DestDir: "C:\FreeRail";
Source: "freeraild.ico"; DestDir: "C:\FreeRail"
Source: "images\*.*"; DestDir: "C:\FreeRail\images"; Tasks: images; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\stylesheets\*.*"; DestDir: "C:\FreeRail\stylesheets";
Source: "..\..\decspecs\*.*"; DestDir: "C:\FreeRail\decspecs"; Flags: recursesubdirs
Source: "..\..\rocview\svg\themes\*.*"; DestDir: "C:\FreeRail\svg\themes"; Tasks: themes; Flags: recursesubdirs
Source: "..\..\rocview\svg\americanthemes\*.*"; DestDir: "C:\FreeRail\svg\themes"; Tasks: americanthemes; Flags: recursesubdirs
Source: "..\..\freerail\impl\web\html\*.*"; DestDir: "C:\FreeRail\web"; Flags: recursesubdirs
Source: "..\..\COPYING"; DestDir: "C:\FreeRail"

[Icons]
Name: "{group}\Rocview"; Parameters: "-sp ""C:\FreeRail"" -themespath ""C:\FreeRail"""; WorkingDir: "C:\FreeRail"; Filename: "C:\FreeRail\rocview.exe"
Name: "{group}\FreeRail Server"; IconFilename: "C:\FreeRail\freeraild.ico"; Parameters: "-console -l ""C:\FreeRail"" -img ""C:\FreeRail\images"""; WorkingDir: "C:\FreeRail"; Filename: "C:\FreeRail\freerail.exe"

