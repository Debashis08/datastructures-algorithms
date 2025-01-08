#include<gtest/gtest.h>
#include "../Headers/0003_Graph/0009_SingleSourceShortestPathBellmanFord.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace SingleSourceShortestPathBellmanFord
{
	UnitTestHelper unitTestHelper;

	TEST(BellmanFordTest, SimpleTest)
	{
		Graph graph;

		graph.PushDirectedEdge(0, 1, 6);
		graph.PushDirectedEdge(0, 3, 7);
		graph.PushDirectedEdge(1, 2, 5);
		graph.PushDirectedEdge(1, 3, 8);
		graph.PushDirectedEdge(1, 4, -4);
		graph.PushDirectedEdge(2, 1, -2);
		graph.PushDirectedEdge(3, 2, -3);
		graph.PushDirectedEdge(3, 4, 9);
		graph.PushDirectedEdge(3, 4, 9);
		graph.PushDirectedEdge(4, 2, 7);
		graph.PushDirectedEdge(4, 0, 2);


		string expectedResult = "0 3 2 1 4";
		ASSERT_TRUE(graph.FindSingleSourceShortestPathBellmanFord(0));
		ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetShortestPathBellmanFord(4)), expectedResult);
	}
}