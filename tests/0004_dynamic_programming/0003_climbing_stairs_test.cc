#include <gtest/gtest.h>
#include "0003_climbing_stairs.h"

namespace dsa::climbing_stairs
{
	TEST(climbingStairs, recursiveTest)
	{
		// arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedCount = 5;

		// act
		int actualCount = dp.recursiveCountWays(n);

		// assert
		ASSERT_EQ(expectedCount, actualCount);
	}

	TEST(climbingStairs, dpTest)
	{
		// arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedCount = 5;

		// act
		int actualCount = dp.dpCountWays(n);

		// assert
		ASSERT_EQ(expectedCount, actualCount);
	}
}