
REM Copy COPY myli.dll to RUNTEIME AND VIEW
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.dll C:\DD\pr\base\UP32\RUNTIME /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.dll C:\DD\pr\base\Source\Views /s /y





REM COPY HEADER TO UPINCLUDE
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\mylib.h C:\DD\pr\base\UP32\INCLUDE /s /y


REM Build the view
push  C:\DD\pr\base\Source\Views\maked -a prddfun


REM Copy PRDDFUN FROM VIEW TO RUNTIME FOLDER
XCOPY  C:\DD\pr\base\UP32\RUNTIME\UPDDFUN.* "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A" /s /y
XCOPY  C:\DD\pr\base\UP32\RUNTIME\ROTO.DAT "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A" /s /y


REM GET BACK TO THE ORIGINAL LOCATION
cd C:\GitHub\Encrypto\MD\VS_Tester_DllEEB\