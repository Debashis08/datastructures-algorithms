#include <gtest/gtest.h>
#include "0001_fibonacci_number.h"
using namespace std;

namespace fibonacci_number
{
	TEST(fibonacciNumber, recursiveTest)
	{
		// arrange
		DynamicProgramming dp;
		int n = 5;
		int expectedFib = 5;
		
		// act
		int actualFib = dp.recursiveNthFibonacci(n);

		// assert
		ASSERT_EQ(expectedFib, actualFib);
	}

	TEST(fibonacciNumber, dpTest)
	{
		// arrange
		DynamicProgramming dp;
		int n = 5;
		int expectedFib = 5;

		// act
		int actualFib = dp.dpNthFibonacci(n);

		// assert
		ASSERT_EQ(expectedFib, actualFib);
	}
}