#include <gtest/gtest.h>
#include "0011_single_source_shortest_path_dijkstra.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::single_source_shortest_path_dijkstra
{
	UnitTestHelper unitTestHelper;

	// Test for simple Graph
	TEST(dijkstraTest, simpleGraph)
	{
		Graph graph;

		graph.pushDirectedEdge(0, 1, 10);
		graph.pushDirectedEdge(0, 3, 5);
		graph.pushDirectedEdge(1, 2, 1);
		graph.pushDirectedEdge(1, 3, 2);
		graph.pushDirectedEdge(2, 4, 4);
		graph.pushDirectedEdge(3, 1, 3);
		graph.pushDirectedEdge(3, 2, 9);
		graph.pushDirectedEdge(3, 4, 2);
		graph.pushDirectedEdge(4, 2, 6);
		graph.pushDirectedEdge(4, 0, 7);

		graph.findShortestPathDijkstra(0);

		string expectedPath = "0 3 1 2";

		ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getDijkstraShortestPath(2)), expectedPath);
	}
}