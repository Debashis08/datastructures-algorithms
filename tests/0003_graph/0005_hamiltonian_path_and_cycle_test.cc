#include <gtest/gtest.h>
#include "0005_hamiltonian_path_and_cycle.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace dsa::hamiltonian_path_and_cycle
{
	UnitTestHelper unitTestHelper;

	TEST(hamiltonianCycleAndPathTest, showResult)
	{
		Graph graph;

		graph.pushUndirectedEdge(0, 1);
		graph.pushUndirectedEdge(0, 3);
		graph.pushUndirectedEdge(1, 2);
		graph.pushUndirectedEdge(1, 3);
		graph.pushUndirectedEdge(1, 4);
		graph.pushUndirectedEdge(2, 4);
		graph.pushUndirectedEdge(3, 4);

		graph.findHamiltonianCycleAndPath();

		bool isHamiltonianCyclePresent = graph.isHamiltonianCyclePresent();
		bool isHamiltonianPathPresent = graph.isHamiltonianPathPresent();

		vector<int> hamiltonianPathActualResult = graph.getHamiltonianPath();
		vector<int> hamiltonianPathExpectedResult = { 4, 3, 0, 1, 2 };
		
		ASSERT_TRUE(isHamiltonianCyclePresent);
		ASSERT_TRUE(isHamiltonianPathPresent);
		ASSERT_TRUE(unitTestHelper.normalizeCyclesAndCompare(hamiltonianPathActualResult, hamiltonianPathExpectedResult));
	}
}