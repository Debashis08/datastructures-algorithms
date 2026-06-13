#include <gtest/gtest.h>
#include "0004_minimum_cost_climbing_stairs.h"

namespace minimum_cost_climbing_stairs
{
	TEST(minimumCostClimbingStairs, recursionTest)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> cost = { 16, 19, 10, 12, 18 };
		int expectedCost = 31;

		// act
		int actualCost = dp.recursiveMinimumCostClimbingStairs(cost);

		// assert
		ASSERT_EQ(expectedCost, actualCost);
	}

	TEST(minimumCostClimbingStairs, dpTest)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> cost = { 16, 19, 10, 12, 18 };
		int expectedCost = 31;

		// act
		int actualCost = dp.dpMinimumCostClimbingStairs(cost);

		// assert
		ASSERT_EQ(expectedCost, actualCost);
	}
}