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
  0003GraphTests
  0001_BreadthFirstSearchTest.cc
  0002_DepthFirstSearchTest.cc
  0003_TopologicalSortTest.cc
  0004_StronglyConnectedComponentsTest.cc
  0005_HamiltonianPathAndCycleTest.cc
  0006_EulerianPathAndCircuitTest.cc
  0007_MinimumSpanningTreeKruskalAlgorithmTest.cc
  0008_MinimumSpanningTreePrimAlgorithmTest.cc
  0009_SingleSourceShortestPathBellmanFordTest.cc
  0010_DirectedAcyclicGraphShortestPathTest.cc
  0011_SingleSourceShortestPathDijkstraTest.cc
  0012_DifferenceConstraintsShortestPathsTest.cc
  0013_AllPairsShortestPathsFloydWarshallTest.cc
  0014_AllPairsShortestPathsJohnsonTest.cc
  0015_MaximumFlowFordFulkersonTest.cc
  0016_MaximumFlowEdmondsKarpTest.cc
  0017_MaximumBipartiteMatchingTest.cc
  0018_MaximumFlowGoldbergGenericPushRelabelTest.cc
  0019_MaximumFlowRelabelToFrontTest.cc
)

target_link_libraries(
  0003GraphTests
  GTest::gtest_main
  0003GRAPH
)

# Add .clang-tidy configuration to this library.
if(CLANG_TIDY_EXE)
  set_target_properties(0003GRAPH PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")
endif()

include(GoogleTest)
gtest_discover_tests(0003GraphTests DISCOVERY_TIMEOUT 30)