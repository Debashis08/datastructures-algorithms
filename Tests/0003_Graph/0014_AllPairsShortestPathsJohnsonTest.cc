#include<gtest/gtest.h>
#include"../Headers/0003_Graph/0014_AllPairsShortestPathsJohnson.h"
#include"../0000_CommonUtilities/UnitTestHelper.h"
using namespace std;

namespace AllPairsShortestPathsJohnson
{
	UnitTestHelper unitTestHelper;

	TEST(JohnsonAlgorithm, SimpleGraph)
	{
		// Arrange
		Graph graph;
		vector<vector<int>> expectedDistanceMatrix =
		{
			{0, 1, -3, 2, -4},
			{3, 0, -4, 1, -1},
			{7, 4, 0, 5, 3},
			{2, -1, -5, 0, -2},
			{8, 5, 1, 6, 0},
		};
		string expectedPredecessorMatrixesult = "[1 5 4 3 2][1 5 4 3][1 5 4][1 5][2 4 1][2 4 3][2 4][2 4 1 5][3 2 4 1][3 2][3 2 4][3 2 4 1 5][4 1][4 3 2][4 3][4 1 5][5 4 1][5 4 3 2][5 4 3][5 4]";

		// Act
		graph.PushDirectedEdge(1, 2, 3);
		graph.PushDirectedEdge(1, 3, 8);
		graph.PushDirectedEdge(1, 5, -4);
		graph.PushDirectedEdge(2, 4, 1);
		graph.PushDirectedEdge(2, 5, 7);
		graph.PushDirectedEdge(3, 2, 4);
		graph.PushDirectedEdge(4, 3, -5);
		graph.PushDirectedEdge(4, 1, 2);
		graph.PushDirectedEdge(5, 4, 6);

		bool result = graph.FindAllPairsShortestPathsJohnsonAlgorithm();
		vector<vector<int>> actualDistanceMatrix = graph.GetAllPairsShortestPathsDistanceMatrix();
		string actualPredecessorMatrix = unitTestHelper.SerializeVectorToString(graph.GetAllPairsShortestPathsPathMatrix());

		// Assert
		ASSERT_TRUE(result);
		ASSERT_EQ(expectedDistanceMatrix, actualDistanceMatrix);
		ASSERT_EQ(expectedPredecessorMatrixesult, actualPredecessorMatrix);
	}
}