#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0001_RodCutting.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace RodCutting
{
	UnitTestHelper unitTestHelper;

	TEST(DpRodCutting, RecursiveTest)
	{
		// Arrange
		vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
		int length = 8;
		DynamicProgramming dp(price);
		int expectedResult = 22;

		// Act
		int actualResult = dp.RecursiveRodCutting(length);

		// Assert
		ASSERT_EQ(actualResult, expectedResult);
	}

	TEST(DpRodCutting, DpTest)
	{
		// Arrange
		vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
		int length = 8;
		DynamicProgramming dp(price);
		int expectedProfit = 22;
		vector<int> expectedCuts = { 2, 6 };

		// Act
		pair<int, vector<int>> actualResult = dp.DpGetMaximumProfitWithCuts(length);

		// Assert
		ASSERT_EQ(actualResult.first, expectedProfit);
		ASSERT_EQ(actualResult.second, expectedCuts);
	}
}