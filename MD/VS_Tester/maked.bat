del main.exe
del mylib.*
 

XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.dll C:\GitHub\Encrypto\MD\VS_Tester /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.obj C:\GitHub\Encrypto\MD\VS_Tester /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.lib C:\GitHub\Encrypto\MD\VS_Tester /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\mylib.h C:\GitHub\Encrypto\MD\VS_Tester /s /y

cd  C:\GitHub\Encrypto\MD\VS_Tester
cl.exe  main.c /link mylib.lib 
echo "Main"
main.exe
type example.txt



 



