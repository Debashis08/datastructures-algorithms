#include <gtest/gtest.h>
#include "0002_dfs.h"
#include "../0000_test_utilities/unit_test_helper.h"

namespace dsa::dfs
{
    UnitTestHelper unitTestHelper;

    TEST(depthFirstSearch, 0001_dfsTest_SimpleConnectedGraph)
    {
        Graph graph;
        int n = 7;
        vector<vector<int>> adjMat = {
            {},
            { 2, 4 },
            { 5 },   
            { 5, 6 },
            { 2 },   
            { 4 },   
            { 6 }    
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 10][4 9][11 14][6 7][5 8][12 13]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestSingleVertex)
    {
        Graph graph;
        int n = 2;
        vector<vector<int>> adjMat = {
            {},
            { 1 }
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 4]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestDisconnectedGraph)
    {
        Graph graph;
        int n = 5;
        vector<vector<int>> adjMat = {
            {},
            { 2 },
            {},
            { 4 },
            {}
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 6][4 5][7 10][8 9]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestCyclicGraph)
    {
        Graph graph;
        int n = 4;
        vector<vector<int>> adjMat = {
            {},
            { 2 },
            { 3 },
            { 1 }
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 8][4 7][5 6]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestLargeGraph)
    {
        Graph graph;
        int n = 17;
        vector<vector<int>> adjMat = {
            {},
            { 2, 3 },
            { 4 },   
            {},      
            { 5 },   
            { 6 },   
            { 7 },   
            { 8 },   
            { 9 },   
            { 10 },  
            { 11 },  
            { 12 },  
            { 13 },  
            { 14 },  
            { 15 },  
            { 16 },  
            {}       
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 34][4 31][32 33][5 30][6 29][7 28][8 27][9 26][10 25][11 24][12 23][13 22][14 21][15 20][16 19][17 18]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestNoEdges)
    {
        Graph graph;
        int n = 4;
        vector<vector<int>> adjMat = {
            {},
            { 1 },
            { 2 },
            { 3 }
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 4][5 6][7 8]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTest_CyclicGraphWithBackEdges)
    {
        Graph graph;
        int n = 5;
        vector<vector<int>> adjMat = {
            {},
            { 2 },
            { 3, 4 },
            { 1 },
            {}
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 10][4 9][5 6][7 8]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestDenseGraph)
    {
        Graph graph;
        int n = 5;
        vector<vector<int>> adjMat = {
            {},
            { 2, 3, 4 },
            { 1, 3, 4 },
            { 1, 2, 4 },
            { 1, 2, 3 }
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 10][4 9][5 8][6 7]";
        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(depthFirstSearch, showDFSResultTestSelfLoopsAndParallelEdges)
    {
        Graph graph;
        int n = 4;
        vector<vector<int>> adjMat = {
            {},
            { 1, 2 },
            { 2, 3, 3 },
            { 3 }
        };

        auto results = graph.dfs(adjMat, n);
        string actualResult = unitTestHelper.serializeVectorToString(results);
        string expectedResult = "[1 2][3 8][4 7][5 6]";
        EXPECT_EQ(actualResult, expectedResult);
    }
}