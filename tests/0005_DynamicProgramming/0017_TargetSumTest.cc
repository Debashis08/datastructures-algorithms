#include <gtest/gtest.h>
#include <0005_DynamicProgramming/0017_TargetSum.h>

namespace TargetSum
{
	TEST(TargetSum, TC0001)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int expectedResult = 5;

		// Act
		int actualResult = dp.recursiveFindTotalWays(nums, target);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(TargetSum, TC0002)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int expectedResult = 5;

		// Act
		int actualResult = dp.dpFindTotalWays(nums, target);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(TargetSum, TC0003)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = -1000;
		int expectedResult = 0;

		// Act
		int actualResult = dp.dpFindTotalWays(nums, target);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}