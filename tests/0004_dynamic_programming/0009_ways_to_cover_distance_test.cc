#include <gtest/gtest.h>
#include "0009_ways_to_cover_distance.h"

namespace dsa::ways_to_cover_distance
{
    TEST(WaysToCoverDistanceTest, 0001_ZeroDistance)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 0;
        int expectedWays = 1;

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0002_NegativeDistance)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = -3;
        int expectedWays = 0;

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0003_DistanceOne)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 1;
        int expectedWays = 1; // {1}

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0004_DistanceTwo)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 2;
        int expectedWays = 2; // {1,1}, {2}

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0005_DistanceThree)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 3;
        int expectedWays = 4; // {1,1,1}, {1,2}, {2,1}, {3}

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0006_DistanceFour)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 4;
        int expectedWays = 7; // Tribonacci sequence values for n=4

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0007_DistanceFive)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 5;
        int expectedWays = 13;

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0008_MediumDistance)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 8;
        int expectedWays = 81;

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(WaysToCoverDistanceTest, 0009_LargerDistance)
    {
        // Arrange
        DynamicProgramming dp;
        int distance = 10;
        int expectedWays = 274;

        // Act
        int actualWays = dp.findWaysToCover(distance);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }
}