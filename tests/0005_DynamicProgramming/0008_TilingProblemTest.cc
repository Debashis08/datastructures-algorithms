#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0008_TilingProblem.h"

namespace TilingProblem
{
	TEST(TilingProblem, RecursionTest01)
	{
		// Arrange
		DynamicProgramming dp;
		int nummberOfRows = 4;
		int expectedNumberOfWays = 5;

		// Act
		int actualNumberOfWays = dp.RecursiveNumberOfWays(nummberOfRows);

		// Assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}

	TEST(TilingProblem, DpTest01)
	{
		// Arrange
		DynamicProgramming dp;
		int nummberOfRows = 4;
		int expectedNumberOfWays = 5;

		// Act
		int actualNumberOfWays = dp.DpNumberOfWays(nummberOfRows);

		// Assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}
}