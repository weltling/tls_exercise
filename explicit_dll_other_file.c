#include <windows.h> 
#include <stdio.h> 
 
#include "defs.h"
#include "explicit_dll.h"

void ErrorExitOther (char *); 

IMPLICIT_API extern BOOL WINAPI StoreData(DWORD dw);
IMPLICIT_API extern BOOL WINAPI GetData(DWORD *pdw);
 
EXPLICIT_API void explicit_dll_other_file_ts_var(VOID) 
{   
   int i;

   for(i=0; i<THREADCOUNT; i++)
   {
      DWORD dwOut;
      if(!GetData(&dwOut))
         ErrorExitOther("explicit_dll_other_file GetData error");
      if( dwOut != thread_specific_var)
         printf("explicit_dll_other_file thread %d: data is incorrect (%d)\n", GetCurrentThreadId(), dwOut);
      else printf("explicit_dll_other_file thread %d: data is correct\n", thread_specific_var);
      Sleep(0);
   }

   return 0; 
} 
 
void ErrorExitOther (char *msg) 
{ 
   fprintf(stderr, "explicit_dll_other_file %s\n", msg); 
   ExitProcess(0); 
}

