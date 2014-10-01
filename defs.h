
#ifdef _WIN32

# define _TLS __declspec(thread)

# ifdef IMPLICIT_EXPORTS
#  define IMPLICIT_API __declspec(dllexport)
# else
#  define IMPLICIT_API __declspec(dllimport)
# endif

# ifdef EXPLICIT_EXPORTS
#  define EXPLICIT_API __declspec(dllexport)
# else
#  define EXPLICIT_API __declspec(dllimport)
# endif

#else

# define _TLS __thread

#  if defined(__GNUC__) && __GNUC__ >= 4
#   define IMPLICIT_API __attribute__ ((visibility("default")))
#   define EXPLICIT_API __attribute__ ((visibility("default")))
#  else
#   define IMPLICIT_API
#   define EXPLICIT_API
#  endif

#endif


#define THREADCOUNT 4 

