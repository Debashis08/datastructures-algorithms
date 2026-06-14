#include <gtest/gtest.h>
#include "0014_all_pairs_shortest_paths_johnson.h"
#include"../0000_common_utilities/unit_test_helper.h"
using namespace std;

namespace dsa::all_pairs_shortest_paths_johnson
{
	UnitTestHelper unitTestHelper;

	TEST(johnsonAlgorithm, simpleGraph)
	{
		// arrange
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

		// act
		graph.pushDirectedEdge(1, 2, 3);
		graph.pushDirectedEdge(1, 3, 8);
		graph.pushDirectedEdge(1, 5, -4);
		graph.pushDirectedEdge(2, 4, 1);
		graph.pushDirectedEdge(2, 5, 7);
		graph.pushDirectedEdge(3, 2, 4);
		graph.pushDirectedEdge(4, 3, -5);
		graph.pushDirectedEdge(4, 1, 2);
		graph.pushDirectedEdge(5, 4, 6);

		bool result = graph.findAllPairsShortestPathsJohnsonAlgorithm();
		vector<vector<int>> actualDistanceMatrix = graph.getAllPairsShortestPathsDistanceMatrix();
		string actualPredecessorMatrix = unitTestHelper.serializeVectorToString(graph.getAllPairsShortestPathsPathMatrix());

		// assert
		ASSERT_TRUE(result);
		ASSERT_EQ(expectedDistanceMatrix, actualDistanceMatrix);
		ASSERT_EQ(expectedPredecessorMatrixesult, actualPredecessorMatrix);
	}
}