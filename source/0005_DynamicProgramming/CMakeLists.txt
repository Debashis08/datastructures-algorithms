# Specify the source files
set(0005DYNAMICPROGRAMMING_SOURCES
    0001_FibonacciNumber.cc
    0002_TribonacciNumber.cc
    0003_ClimbingStairs.cc
    0004_MinimumCostClimbingStairs.cc

)

# Create a library target
add_library(0005DYNAMICPROGRAMMING ${0005DYNAMICPROGRAMMING_SOURCES})