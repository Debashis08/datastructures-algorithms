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

  0001_breadth_first_search_test.cc
  0002_depth_first_search_test.cc
  0003_topological_sort_test.cc
  0004_strongly_connected_components_test.cc
  0005_hamiltonian_path_and_cycle_test.cc
  0006_eulerian_path_and_circuit_test.cc
  0007_minimum_spanning_tree_kruskal_algorithm_test.cc
  0008_minimum_spanning_tree_prim_algorithm_test.cc
  0009_single_source_shortest_path_bellman_ford_test.cc
  0010_directed_acyclic_graph_shortest_path_test.cc
  0011_single_source_shortest_path_dijkstra_test.cc
  0012_difference_constraints_shortest_paths_test.cc
  0013_all_pairs_shortest_paths_floyd_warshall_test.cc
  0014_all_pairs_shortest_paths_johnson_test.cc
  0015_maximum_flow_ford_fulkerson_test.cc
  0016_maximum_flow_edmonds_karp_test.cc
  0017_maximum_bipartite_matching_test.cc
  0018_maximum_flow_goldberg_generic_push_relabel_test.cc
  0019_maximum_flow_relabel_to_front_test.cc
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