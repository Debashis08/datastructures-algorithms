#include <gtest/gtest.h>
#include <0005_DynamicProgramming/0017_TargetSum.h>

namespace TargetSum
{
	TEST(TargetSum, RecursiveSolutionTest_ValidInput_ReturnsCorrectResult)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int expectedResult = 5;

		// Act
		int actualResult = dp.RecursiveFindTotalWays(nums, target);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(TargetSum, DpSolutionTest_ValidInput_ReturnsCorrectResult)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int expectedResult = 5;

		// Act
		int actualResult = dp.DpFindTotalWays(nums, target);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(TargetSum, DpSolutionTest_TargetGreaterThanTotalSum_ReturnsZero)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = -1000;
		int expectedResult = 0;

		// Act
		int actualResult = dp.DpFindTotalWays(nums, target);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}