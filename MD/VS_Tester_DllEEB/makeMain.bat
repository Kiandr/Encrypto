cls
devenv "C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.sln" /rebuild Debug /project "C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.vcproj" /projectconfig Debug

REM put the mylib.dll and mylib.h to the source control 
REM Copy COPY myli.dll to RUNTEIME AND VIEW

XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.dll C:\DD\pr\base\UP32\RUNTIME /s /y

XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.lib C:\Pluswdev\lib /s /y

REM COPY HEADER TO UPINCLUDE
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.h C:\DD\pr\base\UP32\INCLUDE /s /y REM GOT ERROR



 del main.exe
 del mylib.*
 

XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.dll C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.obj C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.lib C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y

XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.h         C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y

cd  C:\GitHub\Encrypto\MD\VS_Tester_DllEEB
cl.exe  main.cpp /link mylib.lib 
echo "== Compiling main.exe===== "
main.exe
type myLog.txt



 



