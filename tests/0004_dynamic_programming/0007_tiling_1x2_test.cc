#include <gtest/gtest.h>
#include "0007_tiling_1x2.h"

namespace dsa::tiling_1x2
{
    TEST(Tiling1x2Test, 0001_ZeroBoard)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 0;
        int expectedWays = 1;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0002_SingleLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 1;
        int expectedWays = 1;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0003_TwoLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 2;
        int expectedWays = 2;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0004_ThreeLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 3;
        int expectedWays = 3;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0005_FourLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 4;
        int expectedWays = 5;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0006_FiveLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 5;
        int expectedWays = 8;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0007_MediumLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 6;
        int expectedWays = 13;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0008_LargerLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 10;
        int expectedWays = 89;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(Tiling1x2Test, 0009_MaxStandardLength)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 15;
        int expectedWays = 987;

        // Act
        int actualWays = dp.findNumberOfWays(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }
}