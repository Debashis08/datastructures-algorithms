# Specify the source files
set(0003GRAPH_SOURCES
    0001_breadth_first_search.cc
    0002_depth_first_search.cc
    0003_topological_sort.cc
    0004_strongly_connected_components.cc
    0005_hamiltonian_path_and_cycle.cc
    0006_eulerian_path_and_circuit.cc
    0007_minimum_spanning_tree_kruskal_algorithm.cc
    0008_minimum_spanning_tree_prim_algorithm.cc
    0009_single_source_shortest_path_bellman_ford.cc
    0010_directed_acyclic_graph_shortest_path.cc
    0011_single_source_shortest_path_dijkstra.cc
    0012_difference_constraints_shortest_paths.cc
    0013_all_pairs_shortest_paths_floyd_warshall.cc
    0014_all_pairs_shortest_paths_johnson.cc
    0015_maximum_flow_ford_fulkerson.cc
    0016_maximum_flow_edmonds_karp.cc
    0017_maximum_bipartite_matching.cc
    0018_maximum_flow_goldberg_generic_push_relabel.cc
    0019_maximum_flow_relabel_to_front.cc

)

# Create a library target
add_library(0003_Graph ${0003GRAPH_SOURCES})

target_include_directories(0003_Graph PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)