#include <gtest/gtest.h>
#include "0013_all_pairs_shortest_paths_floyd_warshall.h"
#include "../0000_common_utilities/unit_test_helper.h"
using namespace std;

namespace all_pairs_shortest_paths_floyd_warshall
{
	UnitTestHelper unitTestHelper;

	TEST(floydWarshall, simpleGraph)
	{
		// arrange
		Graph graph;
		int noOfVertices = 5;
		string expectedResult = "[1 5 4 3 2][1 5 4 3][1 5 4][1 5][2 4 1][2 4 3][2 4][2 4 1 5][3 2 4 1][3 2][3 2 4][3 2 4 1 5][4 1][4 3 2][4 3][4 1 5][5 4 1][5 4 3 2][5 4 3][5 4]";

		// act
		graph.createGraph(noOfVertices);

		graph.pushDirectedEdge(1, 2, 3);
		graph.pushDirectedEdge(1, 3, 8);
		graph.pushDirectedEdge(1, 5, -4);
		graph.pushDirectedEdge(2, 4, 1);
		graph.pushDirectedEdge(2, 5, 7);
		graph.pushDirectedEdge(3, 2, 4);
		graph.pushDirectedEdge(4, 3, -5);
		graph.pushDirectedEdge(4, 1, 2);
		graph.pushDirectedEdge(5, 4, 6);

		graph.findAllPairsShortestPathsFloydWarshallSolution();
		string actualResult = unitTestHelper.serializeVectorToString(graph.getFloydWarshallShortestPath());

		// assert
		ASSERT_EQ(actualResult, expectedResult);
	}
}