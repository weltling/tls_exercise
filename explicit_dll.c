#include <windows.h> 
#include <stdio.h> 
 
#define THREADCOUNT 4 

VOID ErrorExit(LPSTR); 

__declspec(dllimport) extern BOOL WINAPI StoreData(DWORD dw);
__declspec(dllimport) extern BOOL WINAPI GetData(DWORD *pdw);
 
__declspec(dllexport) void dyndll_do_my_stuff(VOID) 
{   
   int i;

   if(!StoreData(GetCurrentThreadId()))
      ErrorExit("dyndll StoreData error");

   //for(i=0; i<THREADCOUNT; i++)
   for(i=0; i<1; i++)
   {
      DWORD dwOut;
      if(!GetData(&dwOut))
         ErrorExit("dyndll GetData error");
      if( dwOut != GetCurrentThreadId())
         printf("dyndll thread %d: data is incorrect (%d)\n", GetCurrentThreadId(), dwOut);
      else printf("dyndll thread %d: data is correct\n", GetCurrentThreadId());
      Sleep(0);
   }
   return 0; 
} 
 
VOID ErrorExit (LPSTR lpszMessage) 
{ 
   fprintf(stderr, "dyndll %s\n", lpszMessage); 
   ExitProcess(0); 
}

