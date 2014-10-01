
#include "defs.h"

#ifdef _WIN32
_TLS extern DWORD thread_specific_var;
#else
_TLS extern int thread_specific_var;
#endif

IMPLICIT_API extern BOOL WINAPI StoreData(DWORD dw);
IMPLICIT_API extern BOOL WINAPI GetData(DWORD *pdw);
 
