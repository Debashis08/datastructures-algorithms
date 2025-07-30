#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0002_TribonacciNumber.h"
using namespace std;

namespace TribonacciNumber
{
	TEST(TribonacciNumber, RecursiveTest)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 5;
		int expectedFib = 2;

		// Act
		int actualFib = dp.RecursiveNthTribonacci(n);

		// Assert
		ASSERT_EQ(expectedFib, actualFib);
	}

	TEST(TribonacciNumber, DpTest)
	{
		// Arrange
		DynamicProgramming dp;
		int n = 10;
		int expectedFib = 44;

		// Act
		int actualFib = dp.DpNthTribonacci(n);

		// Assert
		ASSERT_EQ(expectedFib, actualFib);
	}
}