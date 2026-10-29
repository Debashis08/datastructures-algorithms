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
	0004_dynamic_programming_tests
	
	# List down all the test files
	0001_fibonacci_test.cc
	0002_tribonacci_test.cc
	0003_climbing_stairs_test.cc
	0004_min_cost_climbing_stairs_test.cc
	0005_house_robber_1_test.cc
	0006_house_robber_2_test.cc

















)

target_link_libraries(
  0004_dynamic_programming_tests
  GTest::gtest_main
  0004_dynamicProgramming
)

include(GoogleTest)
gtest_discover_tests(0004_dynamic_programming_tests DISCOVERY_TIMEOUT 30)