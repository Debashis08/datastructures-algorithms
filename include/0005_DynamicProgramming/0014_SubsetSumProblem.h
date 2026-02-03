#pragma once

#include <vector>
using namespace std;

/*
Pattern 2
Subset / 0-1 Knapsack

Description
Given an array arr[] of non-negative integers and a value sum, the task is to check if there is a subset of the given array whose sum is equal to the given sum.

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: False
Explanation: There is no subset that add up to 30.
*/

namespace SubsetSumProblem
{
	class DynamicProgramming
	{
	private:
		bool SubsetSumRecursiveHelper(vector<int>& nums, int sum, int numberOfElements);
	public:
		bool RecursiveSubsetSum(vector<int> nums, int sum);
	};
}