#include <gtest/gtest.h>
#include "0011_count_ways_to_reach_nth_stair_include_order.h"

namespace dsa::count_ways_to_reach_nth_stair_include_order
{
	TEST(countWaysToReachNthStairIncludeOrderTest, recursiveCountWaysToReachNthStairIncludeOrder1)
	{
		// arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 5;

		// act
		int actualNumberOfWays = dp.recursiveCountWays(n);

		// assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}

	TEST(countWaysToReachNthStairIncludeOrderTest, dpCountWaysToReachNthStairIncludeOrder1)
	{
		// arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 5;

		// act
		int actualNumberOfWays = dp.dpCountWays(n);

		// assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}
}