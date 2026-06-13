cmake_policy(SET CMP0135 NEW)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  0005DynamicProgrammingTests

  0001_fibonacci_number_test.cc
  0002_tribonacci_number_test.cc
  0003_climbing_stairs_test.cc
  0004_minimum_cost_climbing_stairs_test.cc
  0005_house_robber1_test.cc
  0006_house_robber2_test.cc
  0007_decode_ways_test.cc
  0008_tiling_problem_test.cc
  0009_friends_pairing_problem_test.cc
  0010_ways_to_cover_distance_test.cc
  0011_count_ways_to_reach_nth_stair_include_order_test.cc
  0012_count_ways_to_reach_nth_stair_exclude_order_test.cc
  0013_knapsack_problem_test.cc
  0014_subset_sum_problem_test.cc
  0015_count_subsets_for_sum_test.cc
  0016_partition_equal_subset_sum_test.cc
  0017_target_sum_test.cc

)

target_link_libraries(
  0005DynamicProgrammingTests
  GTest::gtest_main
  0005DYNAMICPROGRAMMING
)

# Add .clang-tidy configuration to this library.
if(CLANG_TIDY_EXE)
  set_target_properties(0005DYNAMICPROGRAMMING PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
endif()

include(GoogleTest)
gtest_discover_tests(0005DynamicProgrammingTests DISCOVERY_TIMEOUT 30)