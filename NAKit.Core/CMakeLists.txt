cmake_minimum_required(VERSION 3.8)

project(NAKit.Core VERSION 1.0 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(spdlog)

#file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
#file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS src/*.h)

set(SOURCES 
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

add_library(NAKit.Core SHARED ${SOURCES} ${HEADERS} )
set_target_properties(NAKit.Core PROPERTIES SUFFIX ${LIBRARY_SUFFIX})
set_target_properties(NAKit.Core PROPERTIES CXX_STANDARD 17)

target_compile_definitions(NAKit.Core PRIVATE NAKIT_EXPORTS)
target_include_directories(NAKit.Core PUBLIC include)
target_link_libraries(NAKit.Core PRIVATE spdlog::spdlog)