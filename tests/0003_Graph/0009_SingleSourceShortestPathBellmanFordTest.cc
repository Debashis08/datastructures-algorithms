#include <gtest/gtest.h>
#include <0003_Graph/0009_SingleSourceShortestPathBellmanFord.h>
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace SingleSourceShortestPathBellmanFord
{
    UnitTestHelper unitTestHelper;

    // Test for Simple Graph
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

    // Test for Single Node Graph
    TEST(BellmanFordTest, SingleNodeTest)
    {
        Graph graph;
        graph.PushDirectedEdge(0, 0, 0);  // Self-loop

        string expectedResult = "0";
        ASSERT_TRUE(graph.FindSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetShortestPathBellmanFord(0)), expectedResult);
    }

    // Test for Negative Weight Cycle
    TEST(BellmanFordTest, NegativeWeightCycleTest)
    {
        Graph graph;
        graph.PushDirectedEdge(0, 1, 1);
        graph.PushDirectedEdge(1, 2, -1);
        graph.PushDirectedEdge(2, 0, -1);  // Negative weight cycle

        ASSERT_FALSE(graph.FindSingleSourceShortestPathBellmanFord(0));
    }

    // Test for Multiple Shortest Paths
    TEST(BellmanFordTest, MultipleShortestPathsTest)
    {
        Graph graph;
        graph.PushDirectedEdge(0, 1, 5);
        graph.PushDirectedEdge(0, 2, 5);
        graph.PushDirectedEdge(1, 3, 1);
        graph.PushDirectedEdge(2, 3, 1);

        string expectedResult = "0 1 3";
        ASSERT_TRUE(graph.FindSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetShortestPathBellmanFord(3)), expectedResult);
    }

    // Test for All Negative Weights
    TEST(BellmanFordTest, AllNegativeWeightsTest)
    {
        Graph graph;
        graph.PushDirectedEdge(0, 1, -5);
        graph.PushDirectedEdge(1, 2, -3);
        graph.PushDirectedEdge(2, 3, -2);
        graph.PushDirectedEdge(3, 4, -1);

        string expectedResult = "0 1 2 3 4";
        ASSERT_TRUE(graph.FindSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetShortestPathBellmanFord(4)), expectedResult);
    }

    // Test for Large Graph
    TEST(BellmanFordTest, LargeGraphTest)
    {
        Graph graph;
        for (int i = 0; i < 100; ++i) {
            graph.PushDirectedEdge(i, i + 1, 1);
        }

        string expectedResult = "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20";
        ASSERT_TRUE(graph.FindSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetShortestPathBellmanFord(20)), expectedResult);
    }

    // Test for Self-Loop Edge
    TEST(BellmanFordTest, SelfLoopTest)
    {
        Graph graph;
        graph.PushDirectedEdge(0, 0, 10);  // Self-loop with weight 10

        string expectedResult = "0";
        ASSERT_TRUE(graph.FindSingleSourceShortestPathBellmanFord(0));
        ASSERT_EQ(unitTestHelper.SerializeVectorToString(graph.GetShortestPathBellmanFord(0)), expectedResult);
    }
}
