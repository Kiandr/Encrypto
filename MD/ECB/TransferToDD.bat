rem Structure of the building process: 
rem Put the mylib.lib & mylib.dll & mylib.pdb inside the libs

XCOPY C:\GitHub\Encrypto\MD\VS\Release\mylib.dll C:\DD\pr\base\cryptopp-lib\libs
XCOPY C:\GitHub\Encrypto\MD\VS\Release\mylib.lib C:\DD\pr\base\cryptopp-lib\libs
