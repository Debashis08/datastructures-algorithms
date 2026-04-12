#include<gtest/gtest.h>
#include <0005_DynamicProgramming/0016_PartitionEqualSubsetSum.h>

namespace PartitionEqualSubsetSum
{
	TEST(PartitionEqualSubsetSum, RecursivePartitionEqualSubsetSum)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 5, 11, 5 };
		bool expectedResult = true;

		// Act
		bool actualResult = dp.RecursivePartitionEqualSubsets(nums);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(PartitionEqualSubsetSum, DpPartitionEqualSubsetSum)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 5, 11, 5 };
		bool expectedResult = true;

		// Act
		bool actualResult = dp.DpPartitionEqualSubsets(nums);

		// Assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}