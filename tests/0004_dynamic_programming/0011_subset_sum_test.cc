#include <gtest/gtest.h>
#include <vector>
#include "0011_subset_sum.h"

namespace dsa::subset_sum
{
    TEST(SubsetSumTest, 0001_SubsetExistsInMiddle)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 3, 34, 4, 12, 5, 2 };
        int targetSum = 9;
        bool expectedResult = true; // {4, 5} sums to 9

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0002_SubsetDoesNotExist)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 3, 34, 4, 12, 5, 2 };
        int targetSum = 30;
        bool expectedResult = false;

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0003_ZeroTargetSumWithNonEmptyArray)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 1, 2, 3 };
        int targetSum = 0;
        bool expectedResult = true; // Empty subset {} has sum 0

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0004_EmptyArrayZeroTargetSum)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = {};
        int targetSum = 0;
        bool expectedResult = true; // Empty subset {} has sum 0

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0005_EmptyArrayPositiveTargetSum)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = {};
        int targetSum = 5;
        bool expectedResult = false;

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0006_SingleElementMatchesTarget)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 7 };
        int targetSum = 7;
        bool expectedResult = true;

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0007_SingleElementLargerThanTarget)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 10 };
        int targetSum = 5;
        bool expectedResult = false;

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0008_AllElementsRequired)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 2, 4, 6, 8 };
        int targetSum = 20;
        bool expectedResult = true; // 2 + 4 + 6 + 8 = 20

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0009_DuplicateElementsInArray)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 2, 2, 2, 2 };
        int targetSum = 6;
        bool expectedResult = true; // Any three 2s sum to 6

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }

    TEST(SubsetSumTest, 0010_TargetSmallerThanAllElements)
    {
        // Arrange
        DynamicProgramming dp;
        vector<int> nums = { 5, 8, 12 };
        int targetSum = 3;
        bool expectedResult = false;

        // Act
        bool actualResult = dp.canPartitionSum(nums, targetSum);

        // Assert
        ASSERT_EQ(expectedResult, actualResult);
    }
}