#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0001_RodCutting.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace RodCutting
{
	UnitTestHelper unitTestHelper;

	TEST(DpRodCutting, RecursiveTest)
	{
		// Arrange
		int length = 8;
		vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
		DynamicProgramming dp(length, price);
		int expectedResult = 22;

		// Act
		int actualResult = dp.RecursiveRodCutting(length);

		// Assert
		EXPECT_EQ(actualResult, expectedResult);
	}

	TEST(DpRodCutting, DpTest)
	{
		// Arrange
		int length = 8;
		vector<int> price = { 1, 5, 8, 9, 10, 17, 17, 20 };
		DynamicProgramming dp(length, price);
		int expectedResult = 22;

		// Act
		pair<int, vector<int>> actualResult = dp.DpGetMaximumProfitWithCuts();

		// Assert
		EXPECT_EQ(actualResult.first, expectedResult);
	}
}