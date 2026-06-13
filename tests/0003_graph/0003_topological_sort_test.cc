#include <gtest/gtest.h>
#include "0003_topological_sort.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace topological_sort
{
	UnitTestHelper unitTestHelper;

	TEST(topoSortTesting, showTopoSortResult)
	{
		Graph graph;

        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(1, 4);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(4, 3);
        graph.pushSingleNode(5);
        graph.pushDirectedEdge(6, 7);
        graph.pushDirectedEdge(6, 8);
        graph.pushDirectedEdge(7, 4);
        graph.pushDirectedEdge(7, 8);
        graph.pushDirectedEdge(9, 8);

        graph.topologicalSort();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showTopologicalSortResult());
        string expectedResult = "9(17,18) 6(11,16) 7(12,15) 8(13,14) 5(9,10) 1(1,8) 4(6,7) 2(2,5) 3(3,4)";

        EXPECT_EQ(actualResult, expectedResult);
	}

    // Test with a larger graph and multiple paths between nodes
    TEST(topoSortTesting, largeGraphMultiplePaths)
    {
        Graph graph;
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(1, 3);
        graph.pushDirectedEdge(2, 4);
        graph.pushDirectedEdge(3, 4);
        graph.pushDirectedEdge(4, 5);
        graph.pushDirectedEdge(5, 6);
        graph.pushDirectedEdge(6, 7);

        graph.topologicalSort();
        string actualResult = unitTestHelper.serializeVectorToString(graph.showTopologicalSortResult());
        string expectedResult = "1(1,14) 3(12,13) 2(2,11) 4(3,10) 5(4,9) 6(5,8) 7(6,7)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test with a graph containing disconnected components
    TEST(topoSortTesting, disconnectedGraph)
    {
        Graph graph;
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(3, 4);
        graph.pushDirectedEdge(5, 6);

        graph.topologicalSort();
        string actualResult = unitTestHelper.serializeVectorToString(graph.showTopologicalSortResult());
        string expectedResult = "5(9,12) 6(10,11) 3(5,8) 4(6,7) 1(1,4) 2(2,3)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test with a graph that has multiple nodes pointing to the same node
    TEST(topoSortTesting, multipleIncomingEdges)
    {
        Graph graph;
        graph.pushDirectedEdge(1, 3);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(3, 4);

        graph.topologicalSort();
        string actualResult = unitTestHelper.serializeVectorToString(graph.showTopologicalSortResult());
        string expectedResult = "2(7,8) 1(1,6) 3(2,5) 4(3,4)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    // Test for a single-node graph to check the base case
    TEST(topoSortTesting, singleNodeGraph)
    {
        Graph graph;
        graph.pushSingleNode(1);

        graph.topologicalSort();
        string actualResult = unitTestHelper.serializeVectorToString(graph.showTopologicalSortResult());
        string expectedResult = "1(1,2)";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(topoSortTesting, showTopoSortResultUsingKahnAlgorithm)
    {
        Graph graph;

        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(1, 4);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(4, 3);
        graph.pushSingleNode(5);
        graph.pushDirectedEdge(6, 7);
        graph.pushDirectedEdge(6, 8);
        graph.pushDirectedEdge(7, 4);
        graph.pushDirectedEdge(7, 8);
        graph.pushDirectedEdge(9, 8);

        graph.kahnTopologicalSort();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showTopologicalSortResult());
        string expectedResult = "1(1,5) 5(2,7) 6(3,8) 9(4,10) 2(6,11) 7(9,12) 4(13,15) 8(14,17) 3(16,18)";

        EXPECT_EQ(actualResult, expectedResult);
    }
}