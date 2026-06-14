#pragma once

#include <vector>
using namespace std;

/*
pattern 2
subset / 0-1 knapsack

description
given an array arr[] of non-negative integers and a value sum, the task is to check if there is a subset of the given array whose sum is equal to the given sum.

examples:

input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
output: true
explanation: there is a subset (4, 5) with sum 9.

input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
output: false
explanation: there is no subset that add up to 30.
*/

namespace dsa::subset_sum_problem
{
	class DynamicProgramming
	{
	private:
		bool _recursiveSubsetSumHelper(vector<int>& nums, int sum, int numberOfElements);
	public:
		bool recursiveSubsetSum(vector<int> nums, int sum);
		bool dpIsSubsetSum(vector<int> nums, int sum);
	};
}