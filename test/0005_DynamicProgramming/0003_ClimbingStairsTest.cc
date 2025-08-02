#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0003_ClimbingStairs.h"

namespace ClimbingStairs
{
	TEST(ClimbingStairs, RecursiveTest)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedCount = 5;

		// Act
		int actualCount = dp.RecursiveCountWays(n);

		// Assert
		ASSERT_EQ(expectedCount, actualCount);
	}

	TEST(ClimbingStairs, DpTest)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedCount = 5;

		// Act
		int actualCount = dp.DpCountWays(n);

		// Assert
		ASSERT_EQ(expectedCount, actualCount);
	}
}