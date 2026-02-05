#include <gtest/gtest.h>
#include <0003_Graph/0012_DifferenceConstraintsShortestPaths.h>
#include"../0000_CommonUtilities/UnitTestHelper.h"
using namespace std;

namespace DifferenceConstraintsShortestPaths
{
	UnitTestHelper unitTestHelper;

	TEST(DifferenceConstraints, SimpleGraph)
	{
		Graph graph;

		vector<vector<int>> vectorA = 
		{
			{1, -1, 0, 0, 0},
			{1, 0, 0, 0, -1},
			{0, 1, 0, 0, -1},
			{-1, 0, 1, 0, 0},
			{-1, 0, 0, 1, 0},
			{0, 0, -1, 1, 0},
			{0, 0, -1, 0, 1},
			{0, 0, 0, -1, 1},
		};
		vector<string> vectorX = { "v1", "v2", "v3", "v4", "v5" };
		vector<int> vectorB = {0, -1, 1, 5, 4, -1, -3, -3};
		vector<pair<string, int>> expectedSolution =
		{
			{"v2", -3},
			{"v5", -4},
			{"v1", -5},
			{"v4", -1},
			{"v3", 0},
		};
		graph.PushAllDirectedEdges(vectorA, vectorX, vectorB);

		ASSERT_TRUE(graph.FindDifferenceConstraintsSolutionBellmanFord());
		ASSERT_EQ(unitTestHelper.SortVectorOfPairAndSerialize(graph.GetDifferenceConstrtaintsSolution()), unitTestHelper.SortVectorOfPairAndSerialize(expectedSolution));
	}
}