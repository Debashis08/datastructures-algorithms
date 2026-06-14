#include <gtest/gtest.h>
#include "0002_depth_first_search.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace depth_first_search
{
    UnitTestHelper unitTestHelper;

    TEST(depthFirstSearch, showDFSResultTest01)
    {
        Graph graph;

        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(1, 4);
        graph.pushDirectedEdge(2, 5);
        graph.pushDirectedEdge(3, 5);
        graph.pushDirectedEdge(3, 6);
        graph.pushDirectedEdge(4, 2);
        graph.pushDirectedEdge(5, 4);
        graph.pushDirectedEdge(6, 6);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,8) 2(2,7) 3(9,12) 4(4,5) 5(3,6) 6(10,11)";
        EXPECT_EQ(actualResult, expectedResult);
    }


    TEST(depthFirstSearch, showDFSResultTestSingleVertex)
    {
        Graph graph;

        graph.pushDirectedEdge(1, 1);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,2)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestDisconnectedGraph)
    {
        Graph graph;

        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(3, 4);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,4) 2(2,3) 3(5,8) 4(6,7)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestCyclicGraph)
    {
        Graph graph;

        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(3, 1);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,6) 2(2,5) 3(3,4)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestLargeGraph)
    {
        Graph graph;

        // adding 15 nodes with several edges
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(1, 3);
        graph.pushDirectedEdge(2, 4);
        graph.pushDirectedEdge(4, 5);
        graph.pushDirectedEdge(5, 6);
        graph.pushDirectedEdge(6, 7);
        graph.pushDirectedEdge(7, 8);
        graph.pushDirectedEdge(8, 9);
        graph.pushDirectedEdge(9, 10);
        graph.pushDirectedEdge(10, 11);
        graph.pushDirectedEdge(11, 12);
        graph.pushDirectedEdge(12, 13);
        graph.pushDirectedEdge(13, 14);
        graph.pushDirectedEdge(14, 15);
        graph.pushDirectedEdge(15, 16);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,32) 2(2,29) 3(30,31) 4(3,28) 5(4,27) 6(5,26) 7(6,25) 8(7,24) 9(8,23) 10(9,22) 11(10,21) 12(11,20) 13(12,19) 14(13,18) 15(14,17) 16(15,16)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestNoEdges)
    {
        Graph graph;

        // adding isolated nodes
        graph.pushDirectedEdge(1, 1);
        graph.pushDirectedEdge(2, 2);
        graph.pushDirectedEdge(3, 3);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,2) 2(3,4) 3(5,6)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTest_CyclicGraphWithBackEdges)
    {
        Graph graph;

        // creating a cycle with back edges
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(3, 1); // cycle back to 'a'
        graph.pushDirectedEdge(2, 4); // back edge

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,8) 2(2,7) 3(3,4) 4(5,6)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestDenseGraph)
    {
        Graph graph;

        // complete graph of 4 nodes
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(1, 3);
        graph.pushDirectedEdge(1, 4);
        graph.pushDirectedEdge(2, 1);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(2, 4);
        graph.pushDirectedEdge(3, 1);
        graph.pushDirectedEdge(3, 2);
        graph.pushDirectedEdge(3, 4);
        graph.pushDirectedEdge(4, 1);
        graph.pushDirectedEdge(4, 2);
        graph.pushDirectedEdge(4, 3);

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,8) 2(2,7) 3(3,6) 4(4,5)";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestSelfLoopsAndParallelEdges)
    {
        Graph graph;

        // adding self-loops and parallel edges
        graph.pushDirectedEdge(1, 1);
        graph.pushDirectedEdge(1, 2);
        graph.pushDirectedEdge(2, 2);
        graph.pushDirectedEdge(2, 3);
        graph.pushDirectedEdge(2, 3); // parallel edge
        graph.pushDirectedEdge(3, 3); // self-loop

        graph.dfs();

        string actualResult = unitTestHelper.serializeVectorToString(graph.showDFSResult());
        string expectedResult = "1(1,6) 2(2,5) 3(3,4)";
        EXPECT_EQ(actualResult, expectedResult);
    }

}