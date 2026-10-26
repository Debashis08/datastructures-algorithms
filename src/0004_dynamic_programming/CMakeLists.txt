# Define the source files for the library
set(0004DYNAMICPROGRAMMING_SOURCES

    # List down all the source files.
    0001_fibonacci.cc
    0002_tribonacci.cc
    0003_climbing_stairs.cc
    0004_min_cost_climbing_stairs.cc
    0005_house_robber_1.cc






















)

# Create the library target
add_library(0004_dynamicProgramming ${0004DYNAMICPROGRAMMING_SOURCES})

# Add the header directory to the target's include paths
target_include_directories(0004_dynamicProgramming PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)