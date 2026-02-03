#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0004_MinimumCostClimbingStairs.h"

namespace MinimumCostClimbingStairs
{
	TEST(MinimumCostClimbingStairs, RecursionTest)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> cost = { 16, 19, 10, 12, 18 };
		int expectedCost = 31;

		// Act
		int actualCost = dp.RecursiveMinimumCostClimbingStairs(cost);

		// Assert
		ASSERT_EQ(expectedCost, actualCost);
	}

	TEST(MinimumCostClimbingStairs, DpTest)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> cost = { 16, 19, 10, 12, 18 };
		int expectedCost = 31;

		// Act
		int actualCost = dp.DpMinimumCostClimbingStairs(cost);

		// Assert
		ASSERT_EQ(expectedCost, actualCost);
	}
}