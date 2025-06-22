#include<gtest/gtest.h>
#include "../include/0003_Graph/0011_SingleSourceShortestPathDijkstra.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace SingleSourceShortestPathDijkstra
{
	UnitTestHelper unitTestHelper;

	// Test for Simple Graph
	TEST(DijkstraTest, SimpleGraph)
	{
		Graph graph;

		graph.PushDirectedEdge(0, 1, 10);
		graph.PushDirectedEdge(0, 3, 5);
		graph.PushDirectedEdge(1, 2, 1);
		graph.PushDirectedEdge(1, 3, 2);
		graph.PushDirectedEdge(2, 4, 4);
		graph.PushDirectedEdge(3, 1, 3);
		graph.PushDirectedEdge(3, 2, 9);
		graph.PushDirectedEdge(3, 4, 2);
		graph.PushDirectedEdge(4, 2, 6);
		graph.PushDirectedEdge(4, 0, 7);

		graph.FindShortestPathDijkstra(0);

		string expectedPath = "0 3 1 2";

		ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetDijkstraShortestPath(2)), expectedPath);
	}
}