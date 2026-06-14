#include <gtest/gtest.h>
#include "0012_count_ways_to_reach_nth_stair_exclude_order.h"

namespace dsa::count_ways_to_reach_nth_stair_exclude_order
{
	TEST(countWaysToReachNthStairExcludeOrderTest, recursiveCountWaysToReachNthStairExcludeOrder1)
	{
		// arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 3;

		// act
		int actualNumberOfWays = dp.recursiveCountWays(n);

		// assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}

	TEST(countWaysToReachNthStairExcludeOrderTest, dpCountWaysToReachNthStairExcludeOrder1)
	{
		// arrange
		DynamicProgramming dp;
		int n = 4;
		int expectedNumberOfWays = 3;

		// act
		int actualNumberOfWays = dp.dpCountWays(n);

		// assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}
}