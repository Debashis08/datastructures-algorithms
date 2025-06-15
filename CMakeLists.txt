# CMakeList.txt : CMake for datastructures-algorithms
cmake_minimum_required (VERSION 3.10)
project ("datastructures-algorithms")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# .clang-tidy settp
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY
        "${CLANG_TIDY_EXE}"
        "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
        "--extra-arg-before=-Wno-unknown-warning-option"
        "--extra-arg-before=-Wno-c++98-compat-pedantic"
        "--quiet"
    )
endif()

include_directories(${CMAKE_SOURCE_DIR}/Headers)

add_subdirectory(Headers)
add_subdirectory(SourceCodes)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_subdirectory(Tests)