#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0011_CountWaysToReachNthStairIncludeOrder.h"

namespace CountWaysToReachNthStairIncludeOrder
{
	TEST(CountWaysToReachNthStairIncludeOrderTest, RecursiveCountWaysToReachNthStairIncludeOrder1)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 5;

		// Act
		int actualNumberOfWays = dp.RecursiveCountWaysToReachNthStairIncludeOrder(n);

		// Assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}

	TEST(CountWaysToReachNthStairIncludeOrderTest, DpCountWaysToReachNthStairIncludeOrder1)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 5;

		// Act
		int actualNumberOfWays = dp.DpCountWaysToReachNthStairIncludeOrder(n);

		// Assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}
}