#include <gtest/gtest.h>
#include "0016_maximum_flow_edmonds_karp.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace maximum_flow_edmonds_karp
{
	UnitTestHelper unitTestHelper;

	TEST(maximumFlowEdmondsKarp, graphWithNoParallelEdges)
	{
		// arrange
		Graph graph;
		int noOfVertices = 6;
		int expectedMaximumFlow = 23;


		// act
		graph.createGraph(noOfVertices);

		graph.pushDirectedEdge(0, 1, 16);
		graph.pushDirectedEdge(0, 2, 13);
		graph.pushDirectedEdge(1, 3, 12);
		graph.pushDirectedEdge(2, 1, 4);
		graph.pushDirectedEdge(2, 4, 14);
		graph.pushDirectedEdge(3, 2, 9);
		graph.pushDirectedEdge(3, 5, 20);
		graph.pushDirectedEdge(4, 3, 7);
		graph.pushDirectedEdge(4, 5, 4);

		int actualMaximumFlow = graph.findMaximumFlowEdmondsKarp();

		// assert
		ASSERT_EQ(expectedMaximumFlow, actualMaximumFlow);
	}

	TEST(maximumFlowEdmondsKarp, graphWithParallelEdges)
	{
		// arrange
		Graph graph;
		int noOfVertices = 6;
		int expectedMaximumFlow = 24;


		// act
		graph.createGraph(noOfVertices);

		graph.pushDirectedEdge(0, 1, 16);
		graph.pushDirectedEdge(0, 2, 13);
		graph.pushDirectedEdge(1, 3, 12);
		graph.pushDirectedEdge(1, 2, 6);
		graph.pushDirectedEdge(2, 1, 10);
		graph.pushDirectedEdge(2, 4, 14);
		graph.pushDirectedEdge(2, 3, 2);
		graph.pushDirectedEdge(3, 2, 11);
		graph.pushDirectedEdge(3, 5, 20);
		graph.pushDirectedEdge(4, 3, 7);
		graph.pushDirectedEdge(4, 5, 4);

		int actualMaximumFlow = graph.findMaximumFlowEdmondsKarp();

		// assert
		ASSERT_EQ(expectedMaximumFlow, actualMaximumFlow);
	}
}