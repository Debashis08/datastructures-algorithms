#include <gtest/gtest.h>
#include <0003_Graph/0013_AllPairsShortestPathsFloydWarshall.h>
#include"../0000_CommonUtilities/UnitTestHelper.h"
using namespace std;

namespace AllPairsShortestPathsFloydWarshall
{
	UnitTestHelper unitTestHelper;

	TEST(FloydWarshall, SimpleGraph)
	{
		// Arrange
		Graph graph;
		int noOfVertices = 5;
		string expectedResult = "[1 5 4 3 2][1 5 4 3][1 5 4][1 5][2 4 1][2 4 3][2 4][2 4 1 5][3 2 4 1][3 2][3 2 4][3 2 4 1 5][4 1][4 3 2][4 3][4 1 5][5 4 1][5 4 3 2][5 4 3][5 4]";

		// Act
		graph.CreateGraph(noOfVertices);

		graph.PushDirectedEdge(1, 2, 3);
		graph.PushDirectedEdge(1, 3, 8);
		graph.PushDirectedEdge(1, 5, -4);
		graph.PushDirectedEdge(2, 4, 1);
		graph.PushDirectedEdge(2, 5, 7);
		graph.PushDirectedEdge(3, 2, 4);
		graph.PushDirectedEdge(4, 3, -5);
		graph.PushDirectedEdge(4, 1, 2);
		graph.PushDirectedEdge(5, 4, 6);

		graph.FindAllPairsShortestPathsFloydWarshallSolution();
		string actualResult = unitTestHelper.SerializeVectorToString(graph.GetFloydWarshallShortestPath());

		// Assert
		ASSERT_EQ(actualResult, expectedResult);
	}
}