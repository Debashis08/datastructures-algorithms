#include<gtest/gtest.h>
#include "../include/0003_Graph/0017_MaximumBipartiteMatching.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace MaximumBipartiteMatching
{
	TEST(MaximumBipartiteMatching, SimpleGraph)
	{
		// Arrange
		Graph graph;
		UnitTestHelper unitTestHelper;
		int noOfVertices = 9;
		int expectedMaximumMatching = 3;
		string expectedMatchings = "[0 1][2 6][3 5]";

		// Act
		graph.CreateGraph(noOfVertices);

		graph.PushDirectedEdge(0, 1);
		graph.PushDirectedEdge(2, 1);
		graph.PushDirectedEdge(2, 6);
		graph.PushDirectedEdge(3, 5);
		graph.PushDirectedEdge(3, 6);
		graph.PushDirectedEdge(3, 7);
		graph.PushDirectedEdge(4, 6);
		graph.PushDirectedEdge(8, 6);

		int actualMaximumMatching = graph.FindMaximumBipartiteMatching();
		vector<vector<int>> actualMatchings = graph.GetMatchings();

		// Assert
		ASSERT_EQ(expectedMaximumMatching, actualMaximumMatching);
		ASSERT_EQ(expectedMatchings, unitTestHelper.SerializeVectorToString(actualMatchings));
	}
}