#include <gtest/gtest.h>
#include <0003_Graph/0016_MaximumFlowEdmondsKarp.h>
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace MaximumFlowEdmondsKarp
{
	UnitTestHelper unitTestHelper;

	TEST(MaximumFlowEdmondsKarp, GraphWithNoParallelEdges)
	{
		// Arrange
		Graph graph;
		int noOfVertices = 6;
		int expectedMaximumFlow = 23;


		// Act
		graph.CreateGraph(noOfVertices);

		graph.PushDirectedEdge(0, 1, 16);
		graph.PushDirectedEdge(0, 2, 13);
		graph.PushDirectedEdge(1, 3, 12);
		graph.PushDirectedEdge(2, 1, 4);
		graph.PushDirectedEdge(2, 4, 14);
		graph.PushDirectedEdge(3, 2, 9);
		graph.PushDirectedEdge(3, 5, 20);
		graph.PushDirectedEdge(4, 3, 7);
		graph.PushDirectedEdge(4, 5, 4);

		int actualMaximumFlow = graph.FindMaximumFlowEdmondsKarp();

		// Assert
		ASSERT_EQ(expectedMaximumFlow, actualMaximumFlow);
	}

	TEST(MaximumFlowEdmondsKarp, GraphWithParallelEdges)
	{
		// Arrange
		Graph graph;
		int noOfVertices = 6;
		int expectedMaximumFlow = 24;


		// Act
		graph.CreateGraph(noOfVertices);

		graph.PushDirectedEdge(0, 1, 16);
		graph.PushDirectedEdge(0, 2, 13);
		graph.PushDirectedEdge(1, 3, 12);
		graph.PushDirectedEdge(1, 2, 6);
		graph.PushDirectedEdge(2, 1, 10);
		graph.PushDirectedEdge(2, 4, 14);
		graph.PushDirectedEdge(2, 3, 2);
		graph.PushDirectedEdge(3, 2, 11);
		graph.PushDirectedEdge(3, 5, 20);
		graph.PushDirectedEdge(4, 3, 7);
		graph.PushDirectedEdge(4, 5, 4);

		int actualMaximumFlow = graph.FindMaximumFlowEdmondsKarp();

		// Assert
		ASSERT_EQ(expectedMaximumFlow, actualMaximumFlow);
	}
}