#############################################################################
#
#  Makefile for PRDDFUN, application PR
#
#  'Copyright (c) 1992-2016 Sage Software, Inc.  All rights reserved.'
#
#############################################################################


XOPTS = $(COPTS) -EHsc

PRDDFUN: $(RUNPATH)\$(APP)DDFUN.DLL iPRDDFUN

iPRDDFUN: $(INCPATH)\prddfun.i $(INCPATH)\prddfun.h $(GENPATH)\prddfun.dep

$(RUNPATH)\$(APP)DDFUN.DLL: \
   $(OBJPATH)\$(APP)ddfun.obj \
   $(OBJPATH)\$(APP)ddfun1.obj \
   $(OBJPATH)\$(APP)ddfungenxml.obj \
   $(OBJPATH)\$(APP)ddfun-cryptoDll.lib \


PRDDFUN-OBJ : \
 $(OBJPATH)\$(APP)ddfun.OBJ \
 $(OBJPATH)\$(APP)ddfun1.OBJ \
 $(OBJPATH)\$(APP)ddfungenxml.OBJ \

 echo $(PROJPATH)
  
    
$(OBJPATH)\$(APP)ddfun.OBJ: $(OBJPATH)\PRDDFUN.OBJ
   copy $? $@

$(OBJPATH)\$(APP)ddfun1.OBJ: $(OBJPATH)\PRDDFUN1.OBJ
   copy $? $@

$(OBJPATH)\$(APP)ddfungenxml.OBJ: $(OBJPATH)\PRDDFUNgenxml.OBJ
   copy $? $@

$(OBJPATH)\prddfun.obj: prddfun.cpp iPR iPRDDFUN prddfun1.h prddfun2.h

$(OBJPATH)\prddfun1.obj: prddfun1.cpp iPR iPRDDFUN prddfun1.h prddfun2.h

$(OBJPATH)\prddfungenxml.obj: prddfun1.cpp iPR iPRDDFUN prddfun1.h prddfun2.h

$(OBJPATH)\$(APP)ddfun-cryptoDll.lib:  prddfun-cryptoDll.cpp  prddfun-cryptoDll.h
    devenv "$(PROJPATH)\Source\Views\prddfun-cryptoDll.sln" /Deploy "Release|Win32" /out  "$(PROJPATH)\Source\Views\logSln.txt" /project  "prddfun-cryptoDll" /projectconfig Release /Log "$(PROJPATH)\Source\Views\logVcProj.txt"
	copy Release\$(APP)ddfun-cryptoDll.lib $(OBJPATH)
	copy Release\$(APP)ddfun-cryptoDll.dll $(RUNPATH)

# If there is a prddfun2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\prddfun.dep: prddfun.tbl
!IF "PRDDFUN"!="prddfun"
   gentable -zPRDDFUN -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
