#include<gtest/gtest.h>
#include "0010_knapsack_01.h"

namespace dsa::knapsack_01
{
    TEST(Knapsack01Test, 0001_StandardKnapsack)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 2, 3, 4, 5 };
        vector<int> profit = { 3, 4, 5, 6 };
        int capacity = 5;
        int expectedMaxValue = 7; // Items with weight 2 and 3 -> profit 3 + 4 = 7

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0002_EmptyItemsList)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = {};
        vector<int> profit = {};
        int capacity = 10;
        int expectedMaxValue = 0;

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0003_ZeroCapacity)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 1, 2, 3 };
        vector<int> profit = { 10, 15, 40 };
        int capacity = 0;
        int expectedMaxValue = 0;

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0004_AllItemsFit)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 1, 2, 3 };
        vector<int> profit = { 10, 20, 30 };
        int capacity = 10;
        int expectedMaxValue = 60; // Take all items: 10 + 20 + 30 = 60

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0005_NoItemsFit)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 10, 20, 30 };
        vector<int> profit = { 60, 100, 120 };
        int capacity = 5;
        int expectedMaxValue = 0;

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0006_SingleItemFits)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 4 };
        vector<int> profit = { 50 };
        int capacity = 5;
        int expectedMaxValue = 50;

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0007_SingleItemDoesNotFit)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 6 };
        vector<int> profit = { 50 };
        int capacity = 5;
        int expectedMaxValue = 0;

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }

    TEST(Knapsack01Test, 0008_OptimalChoiceSubset)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> weights = { 10, 20, 30 };
        vector<int> profit = { 60, 100, 120 };
        int capacity = 50;
        int expectedMaxValue = 220; // Take items with weights 20 and 30 -> 100 + 120 = 220

        // Act
        int actualMaxValue = dp.knapsack(capacity, weights, profit);

        // Assert
        ASSERT_EQ(expectedMaxValue, actualMaxValue);
    }
}