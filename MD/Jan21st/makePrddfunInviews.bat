rem Build the prddfun dll according to make file 


pushd C:\DD\pr\base\Source\Views
echo "Making prddfun from views" 

call make.bat -a prddfun

rem call  notepad++ "$(PROJPATH\Source\Views\error.txt"
rem call notepad++ "$(PROJPATH\Source\Views\crypto\logVcProj.txt
rem call notepad++ "$(PROJPATH\Source\Views\crypto\logSln.txt

cd C:\GitHub\Encrypto\MD\Jan21st