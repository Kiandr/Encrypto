del C:\DD\pr\base\Source\Views\mylib.lib
del C:\DD\pr\base\Source\Views\mylib.obj



rem This should be added to views 
rem C:\DD\pr\base\Source\Views\mylib.h
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\mylib.h C:\DD\pr\base\Source\Views /s /y







XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.dll C:\DD\pr\base\UP32\RUNTIME\ENG /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.dll C:\DD\pr\base\Source\Views /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.dll C:\DD\pr\base\cryptopp-lib\libs /s /y



XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.obj C:\DD\pr\base\UP32\RUNTIME\ENG /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.obj C:\DD\pr\base\Source\Views /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\Debug\mylib.obj C:\DD\pr\base\cryptopp-lib\libs /s /y



XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\mylib.h C:\DD\pr\base\Source\Views /s /y
XCOPY C:\GitHub\Encrypto\MD\VS_BuildDll\mylib\mylib.h C:\DD\pr\base\cryptopp-lib\includes /s /y






C:\GitHub\CrackingCodingInterview\BuildDD\Maked.bat
