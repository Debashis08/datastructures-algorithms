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
  0001_FibonacciNumberTest.cc
  0002_TribonacciNumberTest.cc
  0003_ClimbingStairsTest.cc
  0004_MinimumCostClimbingStairsTest.cc
  0005_HouseRobber1Test.cc
  0006_HouseRobber2Test.cc
  0007_DecodeWaysTest.cc
  0008_TilingProblemTest.cc
  0009_FriendsPairingProblemTest.cc
  0010_WaysToCoverDistanceTest.cc
  0011_CountWaysToReachNthStairIncludeOrderTest.cc
  0012_CountWaysToReachNthStairExcludeOrderTest.cc
  0013_KnapsackProblemTest.cc
  0014_SubsetSumProblemTest.cc

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