#include <gtest/gtest.h>
#include "0008_tiling_problem.h"

namespace tiling_problem
{
	TEST(tilingProblem, recursionTest01)
	{
		// arrange
		DynamicProgramming dp;
		int nummberOfRows = 4;
		int expectedNumberOfWays = 5;

		// act
		int actualNumberOfWays = dp.recursiveNumberOfWays(nummberOfRows);

		// assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}

	TEST(tilingProblem, dpTest01)
	{
		// arrange
		DynamicProgramming dp;
		int nummberOfRows = 4;
		int expectedNumberOfWays = 5;

		// act
		int actualNumberOfWays = dp.dpNumberOfWays(nummberOfRows);

		// assert
		ASSERT_EQ(expectedNumberOfWays, actualNumberOfWays);
	}
}