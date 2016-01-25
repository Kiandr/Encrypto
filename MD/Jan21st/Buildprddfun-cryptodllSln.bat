rem oBuildprddfun-cryptodllSln


echo "============= Compiling *.sln C:\GitHub\Encrypto\MD\DllEEB\prddfun-cryptoDll\prddfun-cryptoDll.sln ==================== "
devenv C:\DD\pr\base\Source\Views\crypto\prddfun-cryptoDll.sln /Deploy "Release|Win32" /out "C:\DD\pr\base\Source\Views\crypto\logSln.txt" /project C:\DD\pr\base\Source\Views\crypto\prddfun-cryptoDll.vcproj /projectconfig Release /Log "C:\DD\pr\base\Source\Views\crypto\logVcProj.txt"

xcopy  C:\DD\pr\base\Source\Views\crypto\prddfun-cryptoDll.obj    C:\DD\pr\base\cryptopp-lib\libs /S /Y
 rem notepad++ C:\DD\pr\base\Source\Views\crypto\logSln.txt
rem  notepad++ C:\DD\pr\base\Source\Views\crypto\logVcProj.txt
