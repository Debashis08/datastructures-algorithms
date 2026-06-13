#include <gtest/gtest.h>
#include "0004_strongly_connected_components.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace strongly_connected_components
{
	UnitTestHelper  unitTestHelper;

    // Test case: testing with a simple graph.
	TEST(stronglyConnectedComponentsTesting, simpleGraphTest)
	{
		Graph graph;

		graph.pushDirectedEdge(1, 2);
		graph.pushDirectedEdge(1, 5);
		graph.pushDirectedEdge(2, 3);
		graph.pushDirectedEdge(2, 4);
		graph.pushDirectedEdge(3, 2);
		graph.pushDirectedEdge(4, 4);
		graph.pushDirectedEdge(5, 1);
		graph.pushDirectedEdge(5, 4);
		graph.pushDirectedEdge(6, 1);
		graph.pushDirectedEdge(6, 3);
		graph.pushDirectedEdge(6, 7);
		graph.pushDirectedEdge(7, 3);
		graph.pushDirectedEdge(7, 8);
		graph.pushDirectedEdge(8, 6);

        auto actualResult = graph.findAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {6, 8, 7},{1, 5},{2, 3},{4} };
        EXPECT_EQ(unitTestHelper.sortVectorOfVectors(actualResult), unitTestHelper.sortVectorOfVectors(expectedResult));
	}

    // Test case: single Node.
    TEST(stronglyConnectedComponentsTesting, singleNodeTest) 
    {
        Graph graph;
        graph.pushSingleNode(1);

        auto actualResult = graph.findAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {1} };
        EXPECT_EQ(unitTestHelper.sortVectorOfVectors(actualResult), unitTestHelper.sortVectorOfVectors(expectedResult));
    }

    // Test case: disconnected Graph.
    TEST(stronglyConnectedComponentsTesting, disconnectedGraphTest)
    {
        Graph graph;
        graph.pushSingleNode(1);
        graph.pushSingleNode(2);
        graph.pushSingleNode(3);

        auto actualResult = graph.findAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {1},{3},{2} };
        EXPECT_EQ(unitTestHelper.sortVectorOfVectors(actualResult), unitTestHelper.sortVectorOfVectors(expectedResult));
    }

    // Test case: chain of nodes.
    TEST(stronglyConnectedComponentsTesting, chainOfNodesTest)
    {
        Graph graph;
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(3, 4);

        auto actualResult = graph.findAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {2},{1},{3},{4} };
        EXPECT_EQ(unitTestHelper.sortVectorOfVectors(actualResult), unitTestHelper.sortVectorOfVectors(expectedResult));
    }

    // Test case: bidirectional Edge.
    TEST(stronglyConnectedComponentsTesting, bidirectionalEdgeTest)
    {
        Graph graph;
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(2, 1);

        auto actualResult = graph.findAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {2, 1} };
        EXPECT_EQ(unitTestHelper.sortVectorOfVectors(actualResult), unitTestHelper.sortVectorOfVectors(expectedResult));
    }

    // Test case: complex Graph.
    TEST(stronglyConnectedComponentsTesting, complexGraphTest)
    {
        Graph graph;

        // Graph structure with multiple sCCs and isolated nodes.
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(3, 1);  // cycle: 1 -> 2 -> 3 -> 1
        graph.pushDirectedEdge(4, 5);
        graph.pushDirectedEdge(5, 6);
        graph.pushDirectedEdge(6, 4);  // cycle: 4 -> 5 -> 6 -> 4
        graph.pushDirectedEdge(7, 8);  // single direction: 7 -> 8
        graph.pushSingleNode(9);       // isolated node.

        auto actualResult = graph.findAllStronglyConnectedComponents();
        vector<vector<int>> expectedResult = { {4, 6, 5},{7}, { 2, 3, 1},{8}, {9} };
        EXPECT_EQ(unitTestHelper.sortVectorOfVectors(actualResult), unitTestHelper.sortVectorOfVectors(expectedResult));
    }
}