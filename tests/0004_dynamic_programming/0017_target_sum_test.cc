#include <gtest/gtest.h>
#include "0017_target_sum.h"

namespace target_sum
{
	TEST(targetSum, recursiveSolutionTest_ValidInput_ReturnsCorrectResult)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int expectedResult = 5;

		// act
		int actualResult = dp.recursiveFindTotalWays(nums, target);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(targetSum, dpSolutionTest_ValidInput_ReturnsCorrectResult)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = 3;
		int expectedResult = 5;

		// act
		int actualResult = dp.dpFindTotalWays(nums, target);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(targetSum, dpSolutionTest_TargetGreaterThanTotalSum_ReturnsZero)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 1, 1, 1, 1 };
		int target = -1000;
		int expectedResult = 0;

		// act
		int actualResult = dp.dpFindTotalWays(nums, target);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}