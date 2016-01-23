rem oBuildprddfun-cryptodllSln

del 
echo "============= Compiling *.sln C:\GitHub\Encrypto\MD\DllEEB\prddfun-cryptoDll\prddfun-cryptoDll.sln ==================== "
 devenv C:\DD\pr\base\Source\Views\crypto\prddfun-cryptoDll.sln /Deploy "Release|Win32" /out "C:\DD\pr\base\Source\Views\crypto\logSln.txt" /project C:\DD\pr\base\Source\Views\crypto\prddfun-cryptoDll.vcproj /projectconfig Release /Log "C:\DD\pr\base\Source\Views\crypto\logVcProj.txt"
 notepad++ C:\DD\pr\base\Source\Views\crypto\logSln.txt
 notepad++ C:\DD\pr\base\Source\Views\crypto\logVcProj.txt
