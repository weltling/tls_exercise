
del *.exp *.lib *.obj *.exe *.dll

cl /LD implicit_dll.c 
cl /LD explicit_dll.c /link implicit_dll.lib
rem cl bin.c
cl bin.c /link implicit_dll.lib
