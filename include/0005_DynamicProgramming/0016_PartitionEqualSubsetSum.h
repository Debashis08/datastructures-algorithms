#pragma once

#include<vector>
#include<numeric>
using namespace std;

/*
Pattern 2
Subset / 0-1 Knapsack

Description
Given an array arr[], check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
Note: Each element is present in either the first subset or the second subset, but not in both.

Examples:

Input: arr[] = [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11] and the sum of both the subsets are equal.

Input: arr[] = [1, 5, 3]
Output: false
Explanation: The array cannot be partitioned into equal sum sets.
*/

namespace PartitionEqualSubsetSum
{
	class DynamicProgramming
	{
	private:
		bool RecursivePartitionEqualSubsetsHelper(vector<int>& nums, int targetSum, int numberOfElements);
	public:
		bool RecursivePartitionEqualSubsets(vector<int> nums);
		bool DpPartitionEqualSubsets(vector<int> nums);
	};
}