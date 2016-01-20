rem Set Up CVN branch to get crypto++ from DVN artifact, Then, set Up enviroment variable and build the solution at 
rem C:\GitHub\CrackingCodingInterview\BuildDD\setup.bat
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