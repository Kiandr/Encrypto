cls


rem cl /LD /DBUILDING_MYLIB mylib.cpp 
 rem cl /LD mylib.cpp /link /DEF:mylib.def
cl.exe /D_USRDLL /D_WINDLL main.c mylib.lib /link /DLL /OUT:main.dll




