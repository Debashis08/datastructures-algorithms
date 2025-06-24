#include<gtest/gtest.h>
#include "../include/0003_Graph/0010_DirectedAcyclicGraphShortestPath.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace DirectedAcyclicGraphShortestPath
{
	UnitTestHelper unitTestHelper;

	// Test for Simple Graph
	TEST(DAGTest, SimpleGraph)
	{
		Graph graph;

		graph.PushDirectedEdge(0, 1, 5);
		graph.PushDirectedEdge(0, 2, 3);
		graph.PushDirectedEdge(1, 2, 2);
		graph.PushDirectedEdge(1, 3, 6);
		graph.PushDirectedEdge(2, 3, 7);
		graph.PushDirectedEdge(2, 4, 4);
		graph.PushDirectedEdge(2, 5, 2);
		graph.PushDirectedEdge(3, 4, -1);
		graph.PushDirectedEdge(3, 5, 1);
		graph.PushDirectedEdge(4, 5, -2);

		graph.FindDAGShortestPath(1);
		string expectedPath = "1 3 4 5";
		ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetDAGShortestPath(5)), expectedPath);
	}
}