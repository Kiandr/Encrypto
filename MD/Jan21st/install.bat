rem Build 563 with MSV2005
rem SETPATH
set VS90COMNTOOLS = "C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\Tools\"

call C:\GitHub\Encrypto\MD\Jan21st\setup.bat
call C:\DD\pr\base\cryptopp-lib-fetch.bat
rem call C:\GitHub\Encrypto\MD\Jan21st\Buildprddfun-cryptodllSln.bat
call C:\GitHub\Encrypto\MD\Jan21st\ReplaceCryptoLib.bat
call C:\GitHub\Encrypto\MD\Jan21st\CopySlnToViews.bat
call C:\GitHub\Encrypto\MD\Jan21st\Buildprddfun-cryptodllSln.bat 
call C:\GitHub\Encrypto\MD\Jan21st\replaceprddfun1-cppprddfun-mak.bat
call C:\GitHub\Encrypto\MD\Jan21st\CopyPrddfunmaktoViewsLocation.bat
call C:\GitHub\Encrypto\MD\Jan21st\makePrddfunInviews.bat
rem call C:\GitHub\Encrypto\MD\Jan21st\CopySlnToViews.bat
rem call C:\GitHub\Encrypto\MD\Jan21st\slnMake.bat
rem call C:\GitHub\Encrypto\MD\Jan21st\CopyddfunDllfromTunTimeToUP71A.bat

cd C:\GitHub\Encrypto\MD\Jan21st\


