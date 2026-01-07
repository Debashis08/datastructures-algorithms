#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0013_KnapsackProblem.h"

namespace KnapsackProblem
{
	TEST(KnapsackProblemTest, RecursiveKnapsackProblemTest01)
	{
		// Arrange
		DynamicProgramming dp;
		int capacity = 4;
		vector<int> weight = { 4,5,1 };
		vector<int> profit = { 1,2,3 };
		int expectedMaximumProfit = 3;

		// Act
		int actualMaximumProfit = dp.RecursiveKnapsack(capacity, weight, profit);

		// Assert
		ASSERT_EQ(expectedMaximumProfit, actualMaximumProfit);
	}

	TEST(KnapsackProblemTest, DpKnapsackProblemTest01)
	{
		// Arrange
		DynamicProgramming dp;
		int capacity = 4;
		vector<int> weight = { 4,5,1 };
		vector<int> profit = { 1,2,3 };
		int expectedMaximumProfit = 3;

		// Act
		int actualMaximumProfit = dp.DpKnapsack(capacity, weight, profit);

		// Assert
		ASSERT_EQ(expectedMaximumProfit, actualMaximumProfit);
	}
}