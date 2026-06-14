#include <gtest/gtest.h>
#include "0015_maximum_flow_ford_fulkerson.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::maximum_flow_ford_fulkerson
{
	UnitTestHelper unitTestHelper;

	TEST(maximumFlowFordFulkerson, graphWithNoParallelEdges)
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

		int actualMaximumFlow = graph.findMaximumFlowFordFulkerson();

		// assert
		ASSERT_EQ(expectedMaximumFlow, actualMaximumFlow);
	}

	TEST(maximumFlowFordFulkerson, graphWithParallelEdges)
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

		int actualMaximumFlow = graph.findMaximumFlowFordFulkerson();

		// assert
		ASSERT_EQ(expectedMaximumFlow, actualMaximumFlow);
	}
}