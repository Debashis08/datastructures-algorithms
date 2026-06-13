#include <gtest/gtest.h>
#include "0014_subset_sum_problem.h"

namespace subset_sum_problem
{
	TEST(subsetSumProblemTest, recursiveSubsetSumTest)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 3, 34, 4, 12, 5, 2 };
		int sum = 9;
		bool expectedResult = true;

		// act
		bool actualResult = dp.recursiveSubsetSum(nums, sum);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(subsetSumProblemTest, dpSubsetSumTest)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 3, 34, 4, 12, 5, 2 };
		int sum = 9;
		bool expectedResult = true;

		// act
		bool actualResult = dp.dpIsSubsetSum(nums, sum);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}