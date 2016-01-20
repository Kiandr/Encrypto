rem Delete the dlls from the follwoing directories. 
del C:\DD\pr\base\UP32\RUNTIME\mylib.*
del "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A\mylib.*"
del C:\Pluswdev\lib\mylib.*
del C:\DD\pr\base\UP32\INCLUDE\mylib.*


devenv "C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\mylib.sln" /rebuild Debug /project "C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\mylib.vcproj" /projectconfig Debug

REM cls /Od /I "C:\DD\pr\base\cryptopp-lib\libs\cryptlib.lib" /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /Gm /EHsc /RTC1 /MDd /Fo"Debug\\" /Fd"Debug\vc90.pdb" /W3 /nologo /c /ZI /TP /errorReport:prompt

REM put the mylib.dll and mylib.h to the source control 
REM Copy COPY myli.dll to RUNTEIME AND VIEW

REM XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.dll C:\DD\pr\base\UP32\RUNTIME /s /y

REM XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.dll "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A" /s /y

XCOPY C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\Debug\mylib.lib C:\Pluswdev\lib /s /y

REM COPY HEADER TO UPINCLUDE
XCOPY C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\mylib.h C:\DD\pr\base\UP32\INCLUDE /s /y 





 del main.exe
 del mylib.*
 

REM XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.dll C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y
XCOPY C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\Debug\mylib.obj C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPTestMain /s /y
XCOPY C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\Debug\mylib.lib C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPTestMain /s /y

XCOPY C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPMyLib\mylib\mylib.h        C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPTestMain /s /y

cd  C:\GitHub\Encrypto\MD\Jan19TestBuildLibStatically\CryptoPPTestMain
cl.exe  main.cpp /link mylib.lib 
echo "== Compiling main.exe January 19th Test Mylib Statically being linked===== "
main.exe
type myLog.txt



 



