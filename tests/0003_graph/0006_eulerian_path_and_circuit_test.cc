#include <gtest/gtest.h>
#include "0006_eulerian_path_and_circuit.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace eulerian_path_and_circuit
{
	UnitTestHelper unitTestHelper;

	TEST(eulerianPathAndCycle, test1)
	{
		Graph graph;

		graph.pushUndirectedEdge(1, 0);
		graph.pushUndirectedEdge(0, 2);
		graph.pushUndirectedEdge(2, 1);
		graph.pushUndirectedEdge(0, 3);
		graph.pushUndirectedEdge(3, 4);
		graph.pushUndirectedEdge(4, 0);

		graph.findEulerianPathAndCircuit();

		bool isEulerianPathPresent = graph.isEulerianPathPresent();
		bool isEulerianCircuitPresent = graph.isEulerianCircuitPresent();

		vector<int> actualEulerianPath = graph.undirectedGraphGetEulerianPath();
		vector<int> expectedEulerianPath = { 0, 1, 2, 0, 3, 4, 0};

		ASSERT_TRUE(isEulerianPathPresent);
		ASSERT_TRUE(isEulerianCircuitPresent);
		EXPECT_EQ(expectedEulerianPath, actualEulerianPath);
	}
}