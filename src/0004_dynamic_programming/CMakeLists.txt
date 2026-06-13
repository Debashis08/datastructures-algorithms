# Specify the source files
set(0005DYNAMICPROGRAMMING_SOURCES
    0001_fibonacci_number.cc
    0002_tribonacci_number.cc
    0003_climbing_stairs.cc
    0004_minimum_cost_climbing_stairs.cc
    0005_house_robber1.cc
    0006_house_robber2.cc
    0007_decode_ways.cc
    0008_tiling_problem.cc
    0009_friends_pairing_problem.cc
    0010_ways_to_cover_distance.cc
    0011_count_ways_to_reach_nth_stair_include_order.cc
    0012_count_ways_to_reach_nth_stair_exclude_order.cc
    0013_knapsack_problem.cc
    0014_subset_sum_problem.cc
    0015_count_subsets_for_sum.cc
    0016_partition_equal_subset_sum.cc
    0017_target_sum.cc

)

# Create a library target
add_library(0005DYNAMICPROGRAMMING ${0005DYNAMICPROGRAMMING_SOURCES})

target_include_directories(0005DYNAMICPROGRAMMING PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)