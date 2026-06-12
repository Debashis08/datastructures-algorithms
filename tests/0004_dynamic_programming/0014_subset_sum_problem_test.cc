#include <gtest/gtest.h>
#include "0014_SubsetSumProblem.h"

namespace SubsetSumProblem
{
	TEST(SubsetSumProblemTest, RecursiveSubsetSumTest)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 3, 34, 4, 12, 5, 2 };
		int sum = 9;
		bool expectedResult = true;

		// Act
		bool actualResult = dp.RecursiveSubsetSum(nums, sum);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(SubsetSumProblemTest, DpSubsetSumTest)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 3, 34, 4, 12, 5, 2 };
		int sum = 9;
		bool expectedResult = true;

		// Act
		bool actualResult = dp.DpIsSubsetSum(nums, sum);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}