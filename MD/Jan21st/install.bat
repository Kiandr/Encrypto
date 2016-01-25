rem Build 563 with MSV2005
rem SETPATH
set VS90COMNTOOLS = "C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\Tools\"

call C:\GitHub\Encrypto\MD\Jan21st\setup.bat
rem Get crypto++ lib from jenkins and setup the eviromental variables. 
call C:\DD\pr\base\cryptopp-lib-fetch.bat
rem replace the crypo++ lib with the one I built on this machine.  
rem call C:\GitHub\Encrypto\MD\Jan21st\ReplaceCryptoLib.bat
rem copy github contrlled code into the views folder
call C:\GitHub\Encrypto\MD\Jan21st\CopySlnToViews.bat
rem copy the prddfun.mak from github to vews folder
call C:\GitHub\Encrypto\MD\Jan21st\replaceprddfun1-cppprddfun-mak.bat

call C:\GitHub\Encrypto\MD\Jan21st\makePrddfunInviews.bat

call C:\GitHub\Encrypto\MD\Jan21st\CopyddfunDllfromTunTimeToUP71A.bat

cd C:\GitHub\Encrypto\MD\Jan21st\


