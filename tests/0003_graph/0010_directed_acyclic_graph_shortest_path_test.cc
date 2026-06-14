#include <gtest/gtest.h>
#include "0010_directed_acyclic_graph_shortest_path.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::directed_acyclic_graph_shortest_path
{
	UnitTestHelper unitTestHelper;

	// Test for simple Graph
	TEST(directedAcyclicGraphShortestPath, shortestPath)
	{
		Graph graph;

		graph.pushDirectedEdge(0, 1, 5);
		graph.pushDirectedEdge(0, 2, 3);
		graph.pushDirectedEdge(1, 2, 2);
		graph.pushDirectedEdge(1, 3, 6);
		graph.pushDirectedEdge(2, 3, 7);
		graph.pushDirectedEdge(2, 4, 4);
		graph.pushDirectedEdge(2, 5, 2);
		graph.pushDirectedEdge(3, 4, -1);
		graph.pushDirectedEdge(3, 5, 1);
		graph.pushDirectedEdge(4, 5, -2);

		graph.findDAGShortestPath(1);
		string expectedPath = "1 3 4 5";
		ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getDAGShortestPath(5)), expectedPath);
	}
}