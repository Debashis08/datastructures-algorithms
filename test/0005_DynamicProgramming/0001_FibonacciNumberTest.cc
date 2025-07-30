#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0001_FibonacciNumber.h"
using namespace std;

namespace FibonacciNumber
{
	TEST(FibonacciNumber, RecursiveTest)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 5;
		int expectedFib = 5;
		
		// Act
		int actualFib = dp.RecursiveNthFibonacci(n);

		// Assert
		ASSERT_EQ(expectedFib, actualFib);
	}

	TEST(FibonacciNumber, DpTest)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 5;
		int expectedFib = 5;

		// Act
		int actualFib = dp.DpNthFibonacci(n);

		// Assert
		ASSERT_EQ(expectedFib, actualFib);
	}
}