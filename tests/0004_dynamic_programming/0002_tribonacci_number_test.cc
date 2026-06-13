#include <gtest/gtest.h>
#include "0002_tribonacci_number.h"
using namespace std;

namespace tribonacci_number
{
	TEST(tribonacciNumber, recursiveTest)
	{
		// arrange
		DynamicProgramming dp;
		int n = 5;
		int expectedFib = 2;

		// act
		int actualFib = dp.recursiveNthTribonacci(n);

		// assert
		ASSERT_EQ(expectedFib, actualFib);
	}

	TEST(tribonacciNumber, dpTest)
	{
		// arrange
		DynamicProgramming dp;
		int n = 10;
		int expectedFib = 44;

		// act
		int actualFib = dp.dpNthTribonacci(n);

		// assert
		ASSERT_EQ(expectedFib, actualFib);
	}
}