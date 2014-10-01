# tls_research #


Research on crossplatform thread local storage solutions

## Windows ##

- **implicit_dll**
	allocates tread storage, manages thread data 
- **explicit_dll**
	links against implicit_dll, uses it to store and retrieve thread specific data
- **bin.exe**
	links against implicit_dll, loads explicit_dll per LoadLibrary

Additionally, explicit_dll uses a DLL wide variable declared with __declspec(thread). That variable is defined in one file and used as extern in another one.

## Linux ##

TODO
