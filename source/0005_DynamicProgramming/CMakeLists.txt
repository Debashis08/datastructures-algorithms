# Specify the source files
set(0005DYNAMICPROGRAMMING_SOURCES
    0001_FibonacciNumber.cc
    0002_TribonacciNumber.cc
    0003_ClimbingStairs.cc
    0004_MinimumCostClimbingStairs.cc
    0005_HouseRobber1.cc
    0006_HouseRobber2.cc

)

# Create a library target
add_library(0005DYNAMICPROGRAMMING ${0005DYNAMICPROGRAMMING_SOURCES})