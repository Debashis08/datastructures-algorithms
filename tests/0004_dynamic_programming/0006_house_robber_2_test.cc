#include<gtest/gtest.h>
#include "0006_house_robber_2.h"

namespace dsa::house_robber_2
{
    TEST(HouseRobber2Test, 0001_MixedHouseValues)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 6, 7, 1, 3, 8, 2, 4 };
        int expectedMaximumLoot = 19;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0002_EmptyHouseList)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = {};
        int expectedMaximumLoot = 0;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0003_SingleHouse)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 10 };
        int expectedMaximumLoot = 10;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0004_TwoHouses)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 2, 7 };
        int expectedMaximumLoot = 7;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0005_ChooseNonAdjacentHouses)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 2, 1, 1, 2 };
        int expectedMaximumLoot = 3;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0006_AllHouseValuesIncreasing)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 1, 2, 3, 4, 5 };
        int expectedMaximumLoot = 8;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0007_AllHouseValuesDecreasing)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 9, 7, 5, 3, 1 };
        int expectedMaximumLoot = 14;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0008_AllHouseValuesEqual)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 5, 5, 5, 5, 5 };
        int expectedMaximumLoot = 10;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0009_ChooseNonAdjacentHouses)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 1, 2, 10, 1 };
        int expectedMaximumLoot = 11;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0010_ChooseAlternatingHouses)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 2, 7, 9, 3, 1 };
        int expectedMaximumLoot = 11;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }

    TEST(HouseRobber2Test, 0011_LargeHouseValues)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> houseValues = { 100, 1, 1, 100 };
        int expectedMaximumLoot = 101;

        // Act
        int actualMaximumLoot = dp.findMaxLoot(houseValues);

        // Assert
        ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
    }
}