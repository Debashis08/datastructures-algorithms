# CMakeLists.txt : CMake project for DataStructures_Algorithms, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.8)

project ("datastructures-algorithms")

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Only enable MSVC-specific debug information format when using MSVC
if(MSVC AND NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  endif()
endif()

# Clang-Tidy Setup
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
  set(CMAKE_CXX_CLANG_TIDY 
    "${CLANG_TIDY_EXE}"
    "-extra-arg=-Wno-unknown-warning-option"  # Ignore unknown warning options
    "-warnings-as-errors=readability-identifier-naming*"  # Make naming violations errors
    "--quiet"  # Reduce output noise
  )
endif()

# Debug information format for MSVC (without Edit and Continue)
if(MSVC AND NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options($<$<CONFIG:Debug,RelWithDebInfo>:/Zi>)
endif()

# If using Clang, suppress the warning
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unused-command-line-argument)
endif()

# Enhanced Clang-Tidy Setup
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
  set(CMAKE_CXX_CLANG_TIDY 
    "${CLANG_TIDY_EXE}"
    "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
    "--extra-arg-before=-Wno-unknown-warning-option"
    "--quiet"
  )
  # Enable all warnings and treat them as errors
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-c++98-compat-pedantic)  # Disable for Clang
endif()


if(CLANG_TIDY_EXE)
  set(CMAKE_CXX_CLANG_TIDY 
    "${CLANG_TIDY_EXE}"
    "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
    "--extra-arg-before=-Wno-c++98-compat-pedantic"  # Also disable in clang-tidy
    "--extra-arg=-Wno-newline-eof"  # Force-disable for all files
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
set_target_properties(gtest gmock gtest_main gmock_main PROPERTIES CXX_CLANG_TIDY "")