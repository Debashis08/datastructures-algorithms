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
	0002_tree_tests
	
	# List down all the test files
	0001_binary_search_tree_test.cc
	0002_avl_tree_test.cc
)

target_link_libraries(
  0002_tree_tests
  GTest::gtest_main
  0002_tree
)

include(GoogleTest)
gtest_discover_tests(0002_tree_tests DISCOVERY_TIMEOUT 30)