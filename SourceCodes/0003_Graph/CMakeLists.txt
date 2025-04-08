# Specify the source files
set(0003GRAPH_SOURCES
    0001_BreadthFirstSearch.cc
    0002_DepthFirstSearch.cc
    0003_TopologicalSort.cc
    0004_StronglyConnectedComponents.cc
    0005_HamiltonianPathAndCycle.cc
    0006_EulerianPathAndCircuit.cc
    0007_MinimumSpanningTreeKruskalAlgorithm.cc
    0008_MinimumSpanningTreePrimAlgorithm.cc
    0009_SingleSourceShortestPathBellmanFord.cc
    0010_DirectedAcyclicGraphShortestPath.cc
    0011_SingleSourceShortestPathDijkstra.cc
    0012_DifferenceConstraintsShortestPaths.cc
    0013_AllPairsShortestPathsFloydWarshall.cc
    0014_AllPairsShortestPathsJohnson.cc
    0015_MaximumFlowFordFulkerson.cc
    0016_MaximumFlowEdmondsKarp.cc
    0017_MaximumBipartiteMatching.cc
    0018_MaximumFlowGoldbergGenericPushRelabel.cc

)

# Create a library target
add_library(0003GRAPH ${0003GRAPH_SOURCES})