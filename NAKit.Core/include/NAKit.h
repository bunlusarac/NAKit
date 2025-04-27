#pragma once

#ifdef _WIN32
    #ifdef NAKIT_EXPORTS
        #define LIB_API __declspec(dllexport)
    #else 
        #define LIB_API __declspec(dllimport)
    #endif
#else
    #define LIB_API
#endif