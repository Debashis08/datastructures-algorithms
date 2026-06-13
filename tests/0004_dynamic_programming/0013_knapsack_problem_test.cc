#include <gtest/gtest.h>
#include "0013_knapsack_problem.h"

namespace knapsack_problem
{
	TEST(knapsackProblemTest, recursiveKnapsackProblemTest01)
	{
		// arrange
		DynamicProgramming dp;
		int capacity = 4;
		vector<int> weight = { 4,5,1 };
		vector<int> profit = { 1,2,3 };
		int expectedMaximumProfit = 3;

		// act
		int actualMaximumProfit = dp.recursiveKnapsack(capacity, weight, profit);

		// assert
		ASSERT_EQ(expectedMaximumProfit, actualMaximumProfit);
	}

	TEST(knapsackProblemTest, dpKnapsackProblemTest01)
	{
		// arrange
		DynamicProgramming dp;
		int capacity = 4;
		vector<int> weight = { 4,5,1 };
		vector<int> profit = { 1,2,3 };
		int expectedMaximumProfit = 3;

		// act
		int actualMaximumProfit = dp.dpKnapsack(capacity, weight, profit);

		// assert
		ASSERT_EQ(expectedMaximumProfit, actualMaximumProfit);
	}

	TEST(knapsackProblemTest, dpKnapsackProblemTest02)
	{
		// arrange
		DynamicProgramming dp;
		int capacity = 4;
		vector<int> weight = { 4,5,1 };
		vector<int> profit = { 1,2,3 };
		int expectedMaximumProfit = 3;

		// act
		int actualMaximumProfit = dp.dpKnapsackSpaceOptimized(capacity, weight, profit);

		// assert
		ASSERT_EQ(expectedMaximumProfit, actualMaximumProfit);
	}
}