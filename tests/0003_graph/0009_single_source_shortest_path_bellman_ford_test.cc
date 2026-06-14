#include <gtest/gtest.h>
#include "0009_single_source_shortest_path_bellman_ford.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::single_source_shortest_path_bellman_ford
{
    UnitTestHelper unitTestHelper;

    // Test for simple Graph
    TEST(bellmanFordTest, simpleTest)
    {
        Graph graph;

        graph.pushDirectedEdge(0, 1, 6);
        graph.pushDirectedEdge(0, 3, 7);
        graph.pushDirectedEdge(1, 2, 5);
        graph.pushDirectedEdge(1, 3, 8);
        graph.pushDirectedEdge(1, 4, -4);
        graph.pushDirectedEdge(2, 1, -2);
        graph.pushDirectedEdge(3, 2, -3);
        graph.pushDirectedEdge(3, 4, 9);
        graph.pushDirectedEdge(3, 4, 9);
        graph.pushDirectedEdge(4, 2, 7);
        graph.pushDirectedEdge(4, 0, 2);

        string expectedResult = "0 3 2 1 4";
        ASSERT_TRUE(graph.findSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getShortestPathBellmanFord(4)), expectedResult);
    }

    // Test for single Node Graph
    TEST(bellmanFordTest, singleNodeTest)
    {
        Graph graph;
        graph.pushDirectedEdge(0, 0, 0);  // self-loop

        string expectedResult = "0";
        ASSERT_TRUE(graph.findSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getShortestPathBellmanFord(0)), expectedResult);
    }

    // Test for negative weight cycle
    TEST(bellmanFordTest, negativeWeightCycleTest)
    {
        Graph graph;
        graph.pushDirectedEdge(0, 1, 1);
        graph.pushDirectedEdge(1, 2, -1);
        graph.pushDirectedEdge(2, 0, -1);  // negative weight cycle

        ASSERT_FALSE(graph.findSingleSourceShortestPathBellmanFord(0));
    }

    // Test for multiple shortest paths
    TEST(bellmanFordTest, multipleShortestPathsTest)
    {
        Graph graph;
        graph.pushDirectedEdge(0, 1, 5);
        graph.pushDirectedEdge(0, 2, 5);
        graph.pushDirectedEdge(1, 3, 1);
        graph.pushDirectedEdge(2, 3, 1);

        string expectedResult = "0 1 3";
        ASSERT_TRUE(graph.findSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getShortestPathBellmanFord(3)), expectedResult);
    }

    // Test for all negative weights
    TEST(bellmanFordTest, allNegativeWeightsTest)
    {
        Graph graph;
        graph.pushDirectedEdge(0, 1, -5);
        graph.pushDirectedEdge(1, 2, -3);
        graph.pushDirectedEdge(2, 3, -2);
        graph.pushDirectedEdge(3, 4, -1);

        string expectedResult = "0 1 2 3 4";
        ASSERT_TRUE(graph.findSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getShortestPathBellmanFord(4)), expectedResult);
    }

    // Test for large Graph
    TEST(bellmanFordTest, largeGraphTest)
    {
        Graph graph;
        for (int i = 0; i < 100; ++i) {
            graph.pushDirectedEdge(i, i + 1, 1);
        }

        string expectedResult = "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20";
        ASSERT_TRUE(graph.findSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getShortestPathBellmanFord(20)), expectedResult);
    }

    // Test for self-loop Edge
    TEST(bellmanFordTest, selfLoopTest)
    {
        Graph graph;
        graph.pushDirectedEdge(0, 0, 10);  // self-loop with weight 10

        string expectedResult = "0";
        ASSERT_TRUE(graph.findSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.serializeVectorToString(graph.getShortestPathBellmanFord(0)), expectedResult);
    }
}
