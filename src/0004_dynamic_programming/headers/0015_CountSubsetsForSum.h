#pragma once

#include <vector>
using namespace std;

/*
Pattern 2
Subset / 0-1 Knapsack

Description
Given an array arr[] of length n and an integer target, the task is to find the number of subsets with a sum equal to target.

Examples:

Input: arr[] = [1, 2, 3, 3], target = 6
Output: 3
Explanation: All the possible subsets are [1, 2, 3], [1, 2, 3] and [3, 3]

Input: arr[] = [1, 1, 1, 1], target = 1
Output: 4
Explanation: All the possible subsets are [1], [1], [1] and [1]
*/

namespace CountSubsetsForSum
{
	class DynamicProgramming
	{
	private:
		int RecursiveCountSubsetsHelper(vector<int>& nums, int targetSum, int currentSum, int index);
	public:
		int RecursiveCountSubsets(vector<int> nums, int sum);
		int DpCountSubsets(vector<int> nums, int sum);
	};
}