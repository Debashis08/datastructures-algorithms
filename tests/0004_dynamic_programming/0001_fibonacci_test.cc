#include<gtest/gtest.h>
#include"0001_fibonacci.h"

namespace dsa::fibonacci
{
	TEST(FibonacciNumbersTest, 0001_SmallIntegerValue)
	{
		DynamicProgramming dp;
		int n = 5;
		
		int result = dp.fibonacci(n);

		EXPECT_EQ(result, 5);
	}

	TEST(FibonacciNumbersTest, 0002_LargeIntegerValue)
	{
		DynamicProgramming dp;
		int n = 53;

		int result = dp.fibonacci(n);

		EXPECT_EQ(result, 1776683621);
	}
}