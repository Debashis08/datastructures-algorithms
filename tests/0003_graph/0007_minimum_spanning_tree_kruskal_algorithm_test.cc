#include <gtest/gtest.h>
#include "0007_minimum_spanning_tree_kruskal_algorithm.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::minimum_spanning_tree_kruskal_algorithm
{
	UnitTestHelper unitTestHelper;

	TEST(minimumSpanningTreeKruskal, getMinimumSpanningTreeKruskal)
	{
		Graph graph;

		graph.pushUndirectedEdge(1, 2, 4);
		graph.pushUndirectedEdge(1, 8, 8);
		graph.pushUndirectedEdge(2, 8, 11);
		graph.pushUndirectedEdge(2, 3, 8);
		graph.pushUndirectedEdge(3, 4, 7);
		graph.pushUndirectedEdge(3, 9, 2);
		graph.pushUndirectedEdge(3, 6, 4);
		graph.pushUndirectedEdge(4, 5, 9);
		graph.pushUndirectedEdge(4, 6, 14);
		graph.pushUndirectedEdge(5, 6, 10);
		graph.pushUndirectedEdge(6, 7, 2);
		graph.pushUndirectedEdge(7, 8, 1);
		graph.pushUndirectedEdge(7, 9, 6);
		graph.pushUndirectedEdge(8, 9, 7);

		graph.findMinimumSpanningTreeKruskalAlgorithm();

		vector<pair<pair<int,int>, int>> actualMST = graph.getMinimumSpanningTree();
		vector<pair<pair<int, int>, int>> expectedMST =
		{
			{{7, 8}, 1},
			{{3, 9}, 2},
			{{6, 7}, 2},
			{{2, 1}, 4},
			{{3, 6}, 4},
			{{3, 4}, 7},
			{{8, 1}, 8},
			{{4, 5}, 9}
		};

		ASSERT_EQ(unitTestHelper.sortVectorOfPair(actualMST), unitTestHelper.sortVectorOfPair(expectedMST));
	}
}