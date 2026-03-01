#include<gtest/gtest.h>
#include<0005_DynamicProgramming/0015_CountSubsetsForSum.h>

namespace CountSubsetsForSum
{
	TEST(CountSubsetsForSum, RecursiveCountSubsetSum)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 2, 3, 3 };
		int sum = 6;
		int expectedCount = 3;

		// Act
		int actualCount = dp.recursiveCountSubsets(nums, sum);

		// Assert
		ASSERT_EQ(expectedCount, actualCount);
	}

	TEST(CountSubsetsForSum, DpCountSubsetSum)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 2, 3, 3 };
		int sum = 6;
		int expectedCount = 3;

		// Act
		int actualCount = dp.dpCountSubsets(nums, sum);

		// Assert
		ASSERT_EQ(expectedCount, actualCount);
	}
}