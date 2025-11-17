#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0012_CountWaysToReachNthStairExcludeOrder.h"

namespace CountWaysToReachNthStairExcludeOrder
{
	TEST(CountWaysToReachNthStairExcludeOrderTest, RecursiveCountWaysToReachNthStairExcludeOrder1)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 3;

		// Act
		int actualNumberOfWays = dp.RecursiveCountWaysToReachNthStairExcludeOrder(n);

		// Assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}

	TEST(CountWaysToReachNthStairExcludeOrderTest, DpCountWaysToReachNthStairExcludeOrder1)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 3;

		// Act
		int actualNumberOfWays = dp.DpCountWaysToReachNthStairExcludeOrder(n);

		// Assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}
}