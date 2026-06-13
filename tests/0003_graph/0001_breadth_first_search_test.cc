#include <gtest/gtest.h>
#include <string>
#include "../../src/0003_graph/headers/0001_breadth_first_search.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace breadth_first_search
{
    UnitTestHelper unitTestHelper;


	TEST(bFSTesting, showBFSResultTest01) 
    {
		Graph graph;

        graph.pushUndirectedEdge(1, 2);
        graph.pushUndirectedEdge(1, 3);
        graph.pushUndirectedEdge(2, 4);
        graph.pushUndirectedEdge(3, 5);
        graph.pushUndirectedEdge(3, 6);
        graph.pushUndirectedEdge(5, 6);
        graph.pushUndirectedEdge(5, 7);
        graph.pushUndirectedEdge(6, 7);
        graph.pushUndirectedEdge(6, 8);
        graph.pushUndirectedEdge(7, 8);

        graph.BFS(1);
        
        string actualResult = unitTestHelper.serializeVectorToString(graph.showBFSResult());
        string expectedResult = "1(0) 2(1) 3(1) 4(2) 5(2) 6(2) 7(3) 8(3)";
        EXPECT_EQ(actualResult, expectedResult);
	}

    TEST(bFSTesting, showBFSResultTest02) 
    {
        Graph graph;

        graph.pushUndirectedEdge(1, 2);

        graph.BFS(1);

        string actualResult = unitTestHelper.serializeVectorToString(graph.showBFSResult());
        string expectedResult = "1(0) 2(1)";
        EXPECT_EQ(actualResult, expectedResult);
    }
}