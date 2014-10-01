#include <windows.h> 
#include <stdio.h> 
 
#include "defs.h"

#define THREADCOUNT 4 

VOID ErrorExit(LPSTR); 

IMPLICIT_API extern BOOL WINAPI StoreData(DWORD dw);
IMPLICIT_API extern BOOL WINAPI GetData(DWORD *pdw);
 
EXPLICIT_API void explicit_dll_do_my_stuff(VOID) 
{   
   int i;

   if(!StoreData(GetCurrentThreadId()))
      ErrorExit("explicit_dll StoreData error");

   //for(i=0; i<THREADCOUNT; i++)
   for(i=0; i<1; i++)
   {
      DWORD dwOut;
      if(!GetData(&dwOut))
         ErrorExit("explicit_dll GetData error");
      if( dwOut != GetCurrentThreadId())
         printf("explicit_dll thread %d: data is incorrect (%d)\n", GetCurrentThreadId(), dwOut);
      else printf("explicit_dll thread %d: data is correct\n", GetCurrentThreadId());
      Sleep(0);
   }
   return 0; 
} 
 
VOID ErrorExit (LPSTR lpszMessage) 
{ 
   fprintf(stderr, "explicit_dll %s\n", lpszMessage); 
   ExitProcess(0); 
}

