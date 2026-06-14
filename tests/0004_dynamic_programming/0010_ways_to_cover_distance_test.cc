#include <gtest/gtest.h>
#include "0010_ways_to_cover_distance.h"

namespace dsa::ways_to_cover_distance
{
	TEST(waysToCoverDistanceTest, recursiveWaysToCoverDistance1)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 3;
		int expectedNumberOfWaysToCoverDistance = 4;

		// act
		int actualNumberOfWaysToCoverDistance = dp.recursiveWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, recursiveWaysToCoverDistance2)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 4;
		int expectedNumberOfWaysToCoverDistance = 7;

		// act
		int actualNumberOfWaysToCoverDistance = dp.recursiveWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, recursiveWaysToCoverDistanc3)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 5;
		int expectedNumberOfWaysToCoverDistance = 13;

		// act
		int actualNumberOfWaysToCoverDistance = dp.recursiveWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, recursiveWaysToCoverDistanc4)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 6;
		int expectedNumberOfWaysToCoverDistance = 24;

		// act
		int actualNumberOfWaysToCoverDistance = dp.recursiveWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, dpWaysToCoverDistance1)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 3;
		int expectedNumberOfWaysToCoverDistance = 4;

		// act
		int actualNumberOfWaysToCoverDistance = dp.dpWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, dpWaysToCoverDistance2)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 4;
		int expectedNumberOfWaysToCoverDistance = 7;

		// act
		int actualNumberOfWaysToCoverDistance = dp.dpWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, dpWaysToCoverDistance3)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 5;
		int expectedNumberOfWaysToCoverDistance = 13;

		// act
		int actualNumberOfWaysToCoverDistance = dp.dpWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(waysToCoverDistanceTest, dpWaysToCoverDistance4)
	{
		// arrange
		DynamicProgramming dp;
		int distance = 6;
		int expectedNumberOfWaysToCoverDistance = 24;

		// act
		int actualNumberOfWaysToCoverDistance = dp.dpWaysToCoverDistance(distance);

		// assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}
}