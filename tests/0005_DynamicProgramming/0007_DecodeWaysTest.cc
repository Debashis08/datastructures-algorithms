#include <gtest/gtest.h>
#include <0005_DynamicProgramming/0007_DecodeWays.h>

namespace DecodeWays
{
	TEST(DecodeWays, RecursionTest01)
	{
		// Arrange
		DynamicProgramming dp;
		string digits = "121";
		int expectedWaysCount = 3;

		// Act
		int actualWaysCount = dp.RecursiveCountWays(digits);

		// Assert
		ASSERT_EQ(expectedWaysCount, actualWaysCount);
	}

	TEST(DecodeWays, DpTest01)
	{
		// Arrange
		DynamicProgramming dp;
		string digits = "121";
		int expectedWaysCount = 3;

		// Act
		int actualWaysCount = dp.DpCountways(digits);

		// Assert
		ASSERT_EQ(expectedWaysCount, actualWaysCount);
	}

	TEST(DecodeWays, DpTestInvalidInput)
	{
		// Arrange
		DynamicProgramming dp;
		string digits = "230";
		int expectedWaysCount = 0;

		// Act
		int actualWaysCount = dp.DpCountways(digits);

		// Assert
		ASSERT_EQ(expectedWaysCount, actualWaysCount);
	}
}