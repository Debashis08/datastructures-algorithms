#pragma once

#include<vector>
#include<numeric>
using namespace std;

/*
pattern 2
subset / 0-1 knapsack

description
given an array arr[], check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
note: each element is present in either the first subset or the second subset, but not in both.

examples:

input: arr[] = [1, 5, 11, 5]
output: true
explanation: the array can be partitioned as [1, 5, 5] and [11] and the sum of both the subsets are equal.

input: arr[] = [1, 5, 3]
output: false
explanation: the array cannot be partitioned into equal sum sets.
*/

namespace partition_equal_subset_sum
{
	class DynamicProgramming
	{
	private:
		bool _recursivePartitionEqualSubsetsHelper(vector<int>& nums, int targetSum, int numberOfElements);
	public:
		bool recursivePartitionEqualSubsets(vector<int> nums);
		bool dpPartitionEqualSubsets(vector<int> nums);
	};
}