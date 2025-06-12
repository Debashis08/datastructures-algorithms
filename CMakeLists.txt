cmake_minimum_required(VERSION 3.8)
project("datastructures-algorithms")

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# While developing, set this below flag to 'OFF', to save compilation time, uncheck this change before pushing the code
option(ENABLE_CLANG_TIDY "Enable Clang-Tidy analysis" OFF)


# Compiler warnings (conditionally set based on compiler)
if(MSVC)
    # Remove default /W3 and set /W4 explicitly
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    endif()
    add_compile_options(/W4 /WX)  # Highest warning level + treat warnings as errors

    # Debug information format for MSVC (without Edit and Continue)
    if(NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        add_compile_options($<$<CONFIG:Debug,RelWithDebInfo>:/Zi>)
    endif()
else()
    # GCC/Clang flags
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
    
    # Additional Clang-specific flags
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        add_compile_options(-Wno-unused-command-line-argument -Wno-c++98-compat-pedantic)
    endif()
endif()

# Clang-Tidy Setup (only if found)
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(ENABLE_CLANG_TIDY AND CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    message(STATUS "clang-tidy enabled: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY
        "${CLANG_TIDY_EXE}"
        "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
        "--extra-arg-before=-Wno-unknown-warning-option"
        "--extra-arg-before=-Wno-c++98-compat-pedantic"
        "--quiet"
    )
endif()

# Include headers
include_directories(${CMAKE_SOURCE_DIR}/Headers)

# Add subdirectories
add_subdirectory(Headers)
add_subdirectory(SourceCodes)

# GoogleTest Fetching
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Enable unit testing
enable_testing()

# Add test directory
add_subdirectory(Tests)