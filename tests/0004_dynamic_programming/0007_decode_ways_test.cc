#include <gtest/gtest.h>
#include "0007_decode_ways.h"

namespace dsa::decode_ways
{
	TEST(decodeWays, recursionTest01)
	{
		// arrange
		DynamicProgramming dp;
		string digits = "121";
		int expectedWaysCount = 3;

		// act
		int actualWaysCount = dp.recursiveCountWays(digits);

		// assert
		ASSERT_EQ(expectedWaysCount, actualWaysCount);
	}

	TEST(decodeWays, dpTest01)
	{
		// arrange
		DynamicProgramming dp;
		string digits = "121";
		int expectedWaysCount = 3;

		// act
		int actualWaysCount = dp.dpCountways(digits);

		// assert
		ASSERT_EQ(expectedWaysCount, actualWaysCount);
	}

	TEST(decodeWays, dpTestInvalidInput)
	{
		// arrange
		DynamicProgramming dp;
		string digits = "230";
		int expectedWaysCount = 0;

		// act
		int actualWaysCount = dp.dpCountways(digits);

		// assert
		ASSERT_EQ(expectedWaysCount, actualWaysCount);
	}
}