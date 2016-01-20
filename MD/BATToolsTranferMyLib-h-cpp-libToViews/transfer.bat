


rem Set Up CVN branch to get crypto++ from DVN artifact, Then, set Up enviroment variable and build the solution, Uncomment lines 2 and 3 for build request. 
rem C:\GitHub\CrackingCodingInterview\BuildDD\setup.bat
rem type C:\DD\pr\base\build_UP.err

rem CopyTheRight LIb from XCOPY "C:\Users\SageKian\Downloads\cryptopp563 (1)\Win32\Output\Debug\*.*" C:\DD\pr\base\cryptopp-lib\libs /s /y
XCOPY "C:\Users\SageKian\Downloads\cryptopp563 (1)\Win32\Output\Debug\*.*" C:\DD\pr\base\cryptopp-lib\libs /s /y
XCOPY "C:\Users\SageKian\Downloads\cryptopp563 (1)\*.h" C:\DD\pr\base\cryptopp-lib\includes /s /y




echo "------------------------------------------------------------------------------"
rem Transfer mylib.h, mylib.cpp mylib.sln to C:\pr\base\source\views\
rem C:\GitHub\Encrypto\MD\DllEEB\mylib root of Build Project: 
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.h		C:\DD\pr\base\Source\Views /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.cpp		C:\DD\pr\base\Source\Views /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.sln		C:\DD\pr\base\Source\Views /s /y
XCOPY C:\GitHub\Encrypto\MD\DllEEB\mylib\mylib.vcproj	C:\DD\pr\base\Source\Views /s /y
echo "------------------------------------------------------------------------------"-
rem AddDependency to prddfun.mak, Do that by copying the GitControlled Replica of prddfun.mak from GitRepository back to Views directory: 
type C:\GitHub\Encrypto\MD\BATToolsTranferMyLib-h-cpp-libToViews\prddfun.mak
XCOPY C:\GitHub\Encrypto\MD\BATToolsTranferMyLib-h-cpp-libToViews\prddfun.mak 	C:\DD\pr\base\Source\Views /s /y
echo "------------------------------------------------------------------------------"	
rem Build myLIb.DllEEB\mylib.dll and put into a tester at C:\GitHub\Encrypto\MD\Jan20BuildDllWrapperFourFiles\CryptoPPTestMain

