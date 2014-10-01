#include <windows.h> 
#include <stdio.h> 
 
#include "defs.h"
#include "explicit_dll.h"

void ErrorExit(char *); 

#ifdef _WIN32
_TLS DWORD thread_specific_var = 0;
#else
_TLS int thread_specific_var = 0;
#endif

EXPLICIT_API void explicit_dll_do_my_stuff(VOID) 
{   
   int i;

   thread_specific_var = GetCurrentThreadId();

   if(!StoreData(thread_specific_var))
      ErrorExit("explicit_dll StoreData error");

   for(i=0; i<THREADCOUNT; i++)
   {
      DWORD dwOut;
      if(!GetData(&dwOut))
         ErrorExit("explicit_dll GetData error");
      if( dwOut != thread_specific_var)
         printf("explicit_dll thread %d: data is incorrect (%d)\n", GetCurrentThreadId(), dwOut);
      else printf("explicit_dll thread %d: data is correct\n", GetCurrentThreadId());
      Sleep(0);
   }
   return 0; 
} 
 
void ErrorExit (char *msg) 
{ 
   fprintf(stderr, "explicit_dll %s\n", msg); 
   ExitProcess(0); 
}

