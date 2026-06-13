#include<gtest/gtest.h>
#include "0016_partition_equal_subset_sum.h"

namespace partition_equal_subset_sum
{
	TEST(partitionEqualSubsetSum, recursivePartitionEqualSubsetSum)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 5, 11, 5 };
		bool expectedResult = true;

		// act
		bool actualResult = dp.recursivePartitionEqualSubsets(nums);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}

	TEST(partitionEqualSubsetSum, dpPartitionEqualSubsetSum)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> nums = { 1, 5, 11, 5 };
		bool expectedResult = true;

		// act
		bool actualResult = dp.dpPartitionEqualSubsets(nums);

		// assert
		ASSERT_EQ(expectedResult, actualResult);
	}
}