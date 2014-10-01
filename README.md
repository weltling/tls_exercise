tls_research
============

Research on crossplatform thread local storage solutions

On windows, both bin.exe and explicit_dll depend on the implicit_dll. implicit_dll manages the TLS storage. explicit_dll is loaded per LoadLibrary indo the bin.exe.
