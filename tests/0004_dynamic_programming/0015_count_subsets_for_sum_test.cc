#include <gtest/gtest.h>
#include "0015_count_subsets_for_sum.h"

namespace dsa::count_subsets_for_sum
{
	TEST(countSubsetsForSum, recursiveCountSubsetSum)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 2, 3, 3 };
		int sum = 6;
		int expectedCount = 3;

		// act
		int actualCount = dp.recursiveCountSubsets(nums, sum);

		// assert
		ASSERT_EQ(expectedCount, actualCount);
	}

	TEST(countSubsetsForSum, dpCountSubsetSum)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 2, 3, 3 };
		int sum = 6;
		int expectedCount = 3;

		// act
		int actualCount = dp.dpCountSubsets(nums, sum);

		// assert
		ASSERT_EQ(expectedCount, actualCount);
	}
}