#include <windows.h> 
#include <stdio.h> 
 
#include "defs.h"

#define THREADCOUNT 4 

VOID ErrorExit(LPSTR); 

IMPLICIT_API extern BOOL WINAPI StoreData(DWORD dw);
IMPLICIT_API extern BOOL WINAPI GetData(DWORD *pdw);
 
typedef void (*explicit_dll_do_my_stuff)(void);

void process_dyn_dll(void)
{
	HMODULE hMod = LoadLibrary("explicit_dll");

	explicit_dll_do_my_stuff do_stuff = GetProcAddress(hMod, "explicit_dll_do_my_stuff");

	do_stuff();
}

DWORD WINAPI ThreadFunc(VOID) 
{   
   int i;

   if(!StoreData(GetCurrentThreadId()))
      ErrorExit("StoreData error");

   //for(i=0; i<THREADCOUNT; i++)
   for(i=0; i<1; i++)
   {
      DWORD dwOut;
      if(!GetData(&dwOut))
         ErrorExit("GetData error");
      if( dwOut != GetCurrentThreadId())
         printf("thread %d: data is incorrect (%d)\n", GetCurrentThreadId(), dwOut);
      else printf("thread %d: data is correct\n", GetCurrentThreadId());

      process_dyn_dll();

      Sleep(0);
   }

   return 0; 
} 
 
int main(VOID) 
{ 
   DWORD IDThread; 
   HANDLE hThread[THREADCOUNT]; 
   int i; 
   HMODULE hm;
 
// Create multiple threads. 
 
   for (i = 0; i < THREADCOUNT; i++) 
   { 
      hThread[i] = CreateThread(NULL, // default security attributes 
         0,                           // use default stack size 
         (LPTHREAD_START_ROUTINE) ThreadFunc, // thread function 
         NULL,                    // no thread function argument 
         0,                       // use default creation flags 
         &IDThread);              // returns thread identifier 
 
   // Check the return value for success. 
      if (hThread[i] == NULL) 
         ErrorExit("CreateThread error\n"); 
   } 
 
   WaitForMultipleObjects(THREADCOUNT, hThread, TRUE, INFINITE); 

   FreeLibrary(hm);
 
   return 0; 
} 
 
VOID ErrorExit (LPSTR lpszMessage) 
{ 
   fprintf(stderr, "%s\n", lpszMessage); 
   ExitProcess(0); 
}

