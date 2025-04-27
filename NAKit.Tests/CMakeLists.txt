project(NAKit.Tests LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/6910c9d9165801d8827d628cb72eb7ea9dd538c5.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

set(TEST_SOURCES
   src/TestMain.cpp
   
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(NAKit.Tests ${TEST_SOURCES})

target_link_libraries(NAKit.Tests
    GTest::gtest_main
    NAKit.Core
)

target_include_directories(NAKit.Tests PRIVATE
    ${CMAKE_SOURCE_DIR}/NAKit.Core/include
)

# Copy the compiled dynamic library to test executable directory
add_custom_command(TARGET NAKit.Tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:NAKit.Core> ${CMAKE_BINARY_DIR}/NAKit.Tests/
)

gtest_discover_tests(NAKit.Tests)