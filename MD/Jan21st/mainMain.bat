rem SET Visual Studio 2008

SET VS90COMNTOOLS=C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\Tools
pushd C:\ 


rem Build 563 with MSV2005
 rem C:\Users\SageKian\Downloads\cryptopp563MSV2005\cryptest.sln
 XCOPY C:\Users\SageKian\Downloads\cryptopp563MSV2005\Win32\output\release\  C:\DD\pr\base\cryptopp-lib\libs
 XCOPY C:\Users\SageKian\Downloads\cryptopp563MSV2005\*.h  C:\DD\pr\base\cryptopp-lib\includes 
 