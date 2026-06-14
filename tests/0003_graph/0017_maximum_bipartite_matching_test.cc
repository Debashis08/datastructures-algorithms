#include <gtest/gtest.h>
#include "0017_maximum_bipartite_matching.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::maximum_bipartite_matching
{
	TEST(maximumBipartiteMatching, simpleGraph)
	{
		// arrange
		Graph graph;
		UnitTestHelper unitTestHelper;
		int noOfVertices = 9;
		int expectedMaximumMatching = 3;
		string expectedMatchings = "[0 1][2 6][3 5]";

		// act
		graph.createGraph(noOfVertices);

		graph.pushDirectedEdge(0, 1);
		graph.pushDirectedEdge(2, 1);
		graph.pushDirectedEdge(2, 6);
		graph.pushDirectedEdge(3, 5);
		graph.pushDirectedEdge(3, 6);
		graph.pushDirectedEdge(3, 7);
		graph.pushDirectedEdge(4, 6);
		graph.pushDirectedEdge(8, 6);

		int actualMaximumMatching = graph.findMaximumBipartiteMatching();
		vector<vector<int>> actualMatchings = graph.getMatchings();

		// assert
		ASSERT_EQ(expectedMaximumMatching, actualMaximumMatching);
		ASSERT_EQ(expectedMatchings, unitTestHelper.serializeVectorToString(actualMatchings));
	}
}