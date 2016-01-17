devenv "C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.sln" /rebuild Debug /project "C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.vcproj" /projectconfig Debug

 del main.exe
 del mylib.*
 

XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.dll C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.obj C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\Debug\mylib.lib C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.h         C:\GitHub\Encrypto\MD\VS_Tester_DllEEB /s /y

cd  C:\GitHub\Encrypto\MD\VS_Tester_DllEEB
cl.exe  main.c /link mylib.lib 
echo "== Compiling main.exe===== "
main.exe
type myLog.txt



 



