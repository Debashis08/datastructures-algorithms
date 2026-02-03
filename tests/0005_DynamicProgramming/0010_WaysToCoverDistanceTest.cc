#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0010_WaysToCoverDistance.h"

namespace WaysToCoverDistance
{
	TEST(WaysToCoverDistanceTest, RecursiveWaysToCoverDistance1)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 3;
		int expectedNumberOfWaysToCoverDistance = 4;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.RecursiveWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, RecursiveWaysToCoverDistance2)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 4;
		int expectedNumberOfWaysToCoverDistance = 7;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.RecursiveWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, RecursiveWaysToCoverDistanc3)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 5;
		int expectedNumberOfWaysToCoverDistance = 13;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.RecursiveWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, RecursiveWaysToCoverDistanc4)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 6;
		int expectedNumberOfWaysToCoverDistance = 24;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.RecursiveWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, DpWaysToCoverDistance1)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 3;
		int expectedNumberOfWaysToCoverDistance = 4;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.DpWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, DpWaysToCoverDistance2)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 4;
		int expectedNumberOfWaysToCoverDistance = 7;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.DpWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, DpWaysToCoverDistance3)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 5;
		int expectedNumberOfWaysToCoverDistance = 13;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.DpWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}

	TEST(WaysToCoverDistanceTest, DpWaysToCoverDistance4)
	{
		// Arrange
		DynamicProgramming dp;
		int distance = 6;
		int expectedNumberOfWaysToCoverDistance = 24;

		// Act
		int actualNumberOfWaysToCoverDistance = dp.DpWaysToCoverDistance(distance);

		// Assert
		ASSERT_EQ(expectedNumberOfWaysToCoverDistance, actualNumberOfWaysToCoverDistance);
	}
}