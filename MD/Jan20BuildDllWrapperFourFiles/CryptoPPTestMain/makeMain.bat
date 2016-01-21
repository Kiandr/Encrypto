cd C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain\
rem CopyTheRight LIb from XCOPY "C:\Users\SageKian\Downloads\cryptopp563 (1)\Win32\Output\Debug\*.*" C:\DD\pr\base\cryptopp-lib\libs /s /y
XCOPY "C:\Users\SageKian\Downloads\cryptopp563 (1)\Win32\Output\Debug\*.*" C:\DD\pr\base\cryptopp-lib\libs /s /y
XCOPY "C:\Users\SageKian\Downloads\cryptopp563 (1)\*.h" C:\DD\pr\base\cryptopp-lib\includes /s /y


cls

del C:\DD\pr\base\UP32\RUNTIME\prddfun-cryptoDll.*
del "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A\prddfun-cryptoDll.*"
del C:\Pluswdev\lib\prddfun-cryptoDll.*
del C:\DD\pr\base\UP32\INCLUDE\prddfun-cryptoDll.*
del C:\DD\pr\base\Source\Views\mylib.*

del C:\DD\pr\base\UP32\RUNTIME\mylib.*
del C:\DD\pr\base\UP32\OBJ\mylib.*
del "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A\mylib.*"
del C:\Pluswdev\lib\mylib.*
del C:\DD\pr\base\cryptopp-lib\libs\mylib.*
del C:\DD\pr\base\UP32\OBJ\mylib.*
del C:\DD\pr\base\cryptopp-lib\includes\mylib.*
del C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain\mylib.*

echo "============= Compiling *.sln C:\GitHub\Encrypto\MD\DllEEB\prddfun-cryptoDll\prddfun-cryptoDll.sln ==================== "
devenv "C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\prddfun-cryptoDll.sln" /rebuild Debug /project "C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\prddfun-cryptoDll.vcproj" /projectconfig Debug
   
echo "============= Copy prddfun-cryptoDll.dll to  Runtime Directory ==================== "
REM put the prddfun-cryptoDll.dll and prddfun-cryptoDll.h to the source control 
REM Copy COPY myli.dll to RUNTEIME AND VIEW
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.dll  C:\DD\pr\base\UP32\RUNTIME 						/s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.dll  C:\DD\pr\base\UP32\OBJ 									/s /y

XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.dll  "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A" /s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.lib  C:\Pluswdev\lib 									/s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.lib  C:\DD\pr\base\cryptopp-lib\libs 									/s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.lib  C:\DD\pr\base\UP32\OBJ 									/s /y


REM COPY HEADER TO UPINCLUDE
echo "============= Copy prddfun-cryptoDll.h to ????? ==================== "

XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\prddfun-cryptoDll.h  C:\DD\pr\base\cryptopp-lib\includes /s /y 


REM Build Main
 del main.exe
 del prddfun-cryptoDll.*
 echo "============= Copy prddfun-cryptoDll.dll container to Tester Directory @ to  ==================== "
rem XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.obj		 C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain /s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.dll		 C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain /s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\Debug\prddfun-cryptoDll.lib		 C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain /s /y
XCOPY C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMyLib-dll\prddfun-cryptoDll\prddfun-cryptoDll.h         		 C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain /s /y


Rem Run Main 
echo "============= complie link and build  main.exe ==================== "
cd   C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain\
cl.exe  main.cpp /link prddfun-cryptoDll.lib 
echo "============= RUN  main.exe ==================== "
rem main.exe
echo "============= content of myLog.exe ==================== "
type myLog.txt


echo "============= build maked pr ddfun  ==================== "
cd C:\DD\pr\base\Source\Views\
call maked -a prddfun
cd C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain\
echo "============= Copy to Runtime Direcotry  ==================== "
XCOPY  C:\DD\pr\base\UP32\RUNTIME\UPDDFUN.* "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A" /s /y
XCOPY  C:\DD\pr\base\UP32\RUNTIME\ROTO.DAT "C:\Program Files (x86)\Sage\Sage 300 ERP\UP72A" /s /y
notepad++ C:\DD\pr\base\Source\Views\error
cd C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain\
 



