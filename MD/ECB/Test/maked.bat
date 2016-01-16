cls


rem cl /LD /DBUILDING_MYLIB mylib.cpp 
rem cl /LD mylib.cpp /link /DEF:mylib.def

cl.exe  main.c /link mylib.lib 

 rem cl /LD main.c /link ECB.lib



