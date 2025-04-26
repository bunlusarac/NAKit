cmake_minimum_required(VERSION 3.8)

project(NAKit.Core VERSION 1.0 LANGUAGES CXX)

set(SOURCES 
    "src/Square.cpp"
)

set(HEADERS 
    "include/NAKit.h"
)

if (WIN32)
    set(LIBRARY_SUFFIX ".dll")
elseif (APPLE)
    set(LIBRARY_SUFFIX ".dylib")
else()
    set(LIBRARY_SUFFIX ".so")
endif()

add_library(NAKit.Core SHARED ${SOURCES} ${HEADERS})
set_target_properties(NAKit.Core PROPERTIES SUFFIX ${LIBRARY_SUFFIX})
set_target_properties(NAKit.Core PROPERTIES CXX_STANDARD 17)

target_compile_definitions(NAKit.Core PRIVATE NAKIT_EXPORTS)
target_include_directories(NAKit.Core PUBLIC include)
