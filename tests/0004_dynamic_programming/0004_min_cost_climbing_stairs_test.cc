#include<gtest/gtest.h>
#include "0004_min_cost_climbing_stairs.h"

namespace dsa::min_cost_climbing_stairs
{
	TEST(MinCostClimbingStairsTest, 0001_StandardInput)
	{
		DynamicProgramming dp;
		vector<int> cost = { 16, 19, 10, 12, 18 };
		int expectedCost = 31;

		int actualCost = dp.minCostClimbingStairs(cost);

		EXPECT_EQ(expectedCost, actualCost);
	}

	TEST(MinCostClimbingStairsTest, 0002_AlternatingLowAndHighCosts)
	{
		DynamicProgramming dp;
		vector<int> cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
		int expectedCost = 6;

		int actualCost = dp.minCostClimbingStairs(cost);

		EXPECT_EQ(expectedCost, actualCost);
	}
}