; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{3DABBE48-E9A7-4DF7-B02B-74C03483B1DA}
AppName=Calculus Graph
AppVerName=Calculus Graph v1.0.0.0
AppPublisher=Nick Lauber
AppPublisherURL=link9313@gmail.com
AppSupportURL=link9313@gmail.com
AppUpdatesURL=link9313@gmail.com
DefaultDirName={pf}\Calculus Graph
DefaultGroupName=Calculus Graph
AllowNoIcons=yes
LicenseFile=C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\GPLV2.TXT
InfoAfterFile=C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\Readme.txt
OutputDir=C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\
OutputBaseFilename=AP_Calc_setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\Calculus Graph.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\libgsl_d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\libgslcblas.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\glut32.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\glu32.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\opengl32.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\msvcp100.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\msvcp100d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\msvcr100.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\msvcr100_clr0400.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\msvcr100d.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\GPLV2.TXT"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\Final\Readme.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Documents and Settings\Owner\My Documents\Visual Studio 2010\Projects\Calculus Graph\*"; DestDir: "{app}\src"; Flags: ignoreversion recursesubdirs createallsubdirs
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\Calculus Graph"; Filename: "{app}\Calculus Graph.exe"
Name: "{group}\Readme"; Filename: "{app}\README.TXT"
Name: "{group}\License"; Filename: "{app}\GPLV2.TXT"
Name: "{group}\{cm:UninstallProgram,Calculus Graph}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\Calculus Graph"; Filename: "{app}\Calculus Graph.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\src\Final\vcredist_x86.exe"; Description: "{cm:LaunchProgram,Installer for Microsoft Visual C++ 2010 x86 Redistributable}"; Flags: nowait postinstall skipifsilent
Filename: "{app}\Calculus Graph.exe"; Description: "{cm:LaunchProgram,Calculus Graph}"; Flags: nowait postinstall skipifsilent


















