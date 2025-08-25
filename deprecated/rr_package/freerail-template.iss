; -- freerail.iss --

[Setup]
AppName=FreeRail
AppVerName=FreeRail -rev<BZR>
DefaultDirName={pf}\FreeRail
DefaultGroupName=FreeRail
UninstallDisplayIcon={app}\rocview.exe
Compression=lzma
SolidCompression=yes
DirExistsWarning=auto
OutputDir=..\..\package
AppCopyright=tbd
AppPublisher=tbd
AppPublisherURL=https://www.github.com/michaeloed/FreeRail
OutputBaseFilename=freerail-<BZR>-win32

[Tasks]
;Name: service; Description: "Register FreeRail as Service"; GroupDescription: "Service"; Flags: unchecked
Name: demoplan; Description: "Demo plan"
Name: images; Description: "Loco images"
Name: themes; Description: "SVG Themes"
Name: americanthemes; Description: "SVG American Themes"; Flags: unchecked
;Name: symbols; Description: "WebClient Symbols"

[Run]
;Filename: "{sys}\sc.exe"; Parameters: "create freerail binPath= ""{app}\freerail.exe -service -w {app}"" start= auto";Tasks: service
;Filename: "{sys}\sc.exe"; Parameters: "description freerail ""Model Railway Control Software""";Tasks: service

[UninstallRun]
;Filename: "{sys}\sc.exe"; Parameters: "stop freerail "
;Filename: "{sys}\sc.exe"; Parameters: "delete freerail "

[Code]
procedure StopService();
var
  ResultCode: Integer;
begin
  Exec(ExpandConstant('{sys}\sc.exe'), 'stop freerail', '', SW_SHOW, ewWaitUntilTerminated, ResultCode);
  Exec(ExpandConstant('{sys}\sc.exe'), 'delete freerail', '', SW_SHOW, ewWaitUntilTerminated, ResultCode);
end;

[Files]
;Source: "..\..\winbin\freerail.exe"; DestDir: "{app}"; BeforeInstall: StopService; Tasks: service
;Source: "..\..\winbin\freerail.exe"; DestDir: "{app}"; Tasks: not service
Source: "..\..\winbin\freerail.exe"; DestDir: "{app}"
Source: "stopservice.cmd"; DestDir: "{app}"
Source: "mkservice.cmd"; DestDir: "{app}"
Source: "..\..\winbin\rocview.exe"; DestDir: "{app}"
Source: "..\..\winbin\*.dll"; DestDir: "{app}"
Source: "plan.xml"; DestDir: "{userdocs}\FreeRail"; Tasks: demoplan; Flags: onlyifdoesntexist uninsneveruninstall
Source: "freerail.mib"; DestDir: "{userdocs}\FreeRail";
Source: "freeraild.ico"; DestDir: "{app}"
Source: "images\*.*"; DestDir: "{userdocs}\FreeRail\images"; Tasks: images; Flags: onlyifdoesntexist uninsneveruninstall
Source: "..\..\stylesheets\*.*"; DestDir: "{userdocs}\FreeRail\stylesheets";
Source: "..\..\decspecs\*.*"; DestDir: "{userdocs}\FreeRail\decspecs"; Flags: recursesubdirs
Source: "..\..\rocview\svg\themes\*.*"; DestDir: "{app}\svg\themes"; Tasks: themes; Flags: recursesubdirs
Source: "..\..\rocview\svg\americanthemes\*.*"; DestDir: "{app}\svg\themes"; Tasks: americanthemes; Flags: recursesubdirs
;Source: "..\..\rocrail\symbols\*.*"; DestDir: "{app}\symbols"; Tasks: symbols; Flags: onlyifdoesntexist
Source: "..\..\rocrail\impl\web\html\*.*"; DestDir: "{app}\web"; Flags: recursesubdirs
Source: "..\..\COPYING"; DestDir: "{app}"

[Icons]
Name: "{group}\Rocview"; Parameters: "-sp ""{app}"" -themespath ""{app}"""; WorkingDir: "{userdocs}\FreeRail"; Filename: "{app}\rocview.exe"
Name: "{group}\FreeRail Server"; IconFilename: "{app}\freeraild.ico"; Parameters: "-console -l ""{app}"" -img ""{userdocs}\FreeRail\images"""; WorkingDir: "{userdocs}\FreeRail"; Filename: "{app}\freerail.exe"

