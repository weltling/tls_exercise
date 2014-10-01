
del *.exp *.lib *.obj *.exe *.dll

cl /LD /D IMPLICIT_EXPORTS implicit_dll.c 
cl /LD /D EXPLICIT_EXPORTS explicit_dll.c explicit_dll_other_file.c /link implicit_dll.lib
rem cl bin.c
cl bin.c /link implicit_dll.lib
