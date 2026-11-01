#include<gtest/gtest.h>
#include"0003_climbing_stairs.h"

namespace dsa::climbing_stairs
{
	TEST(ClimbingStairsTest, 0001_SmallIntegerValue)
	{
		DynamicProgramming dp;
		int n = 5;

		int result = dp.countWays(n);

		EXPECT_EQ(result, 8);
	}

	TEST(ClimbingStairsTest, 0002_LargeIntegerValue)
	{
		DynamicProgramming dp;
		int n = 53;

		int result = dp.countWays(n);

		EXPECT_EQ(result, 368225352);
	}
}