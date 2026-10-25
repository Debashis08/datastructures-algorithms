#include <gtest/gtest.h>
#include "0002_tribonacci.h"

namespace dsa::tribonacci
{
	TEST(TribonacciNumbersTest, 0001_SmallIntegerValue)
	{
		DynamicProgramming dp;
		int n = 5;

		int result = dp.tribonacci(n);

		EXPECT_EQ(result, 4);
	}

	TEST(TribonacciNumbersTest, 0002_LargeIntegerValue)
	{
		DynamicProgramming dp;
		int n = 53;

		int result = dp.tribonacci(n);

		EXPECT_EQ(result, 833817292);
	}
}