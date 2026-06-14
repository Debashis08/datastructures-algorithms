#pragma once

#include <vector>
using namespace std;

/*
pattern 2
subset / 0-1 knapsack

description
given an array arr[] of length n and an integer target, the task is to find the number of subsets with a sum equal to target.

examples:

input: arr[] = [1, 2, 3, 3], target = 6
output: 3
explanation: all the possible subsets are [1, 2, 3], [1, 2, 3] and [3, 3]

input: arr[] = [1, 1, 1, 1], target = 1
output: 4
explanation: all the possible subsets are [1], [1], [1] and [1]
*/

namespace dsa::count_subsets_for_sum
{
	class DynamicProgramming
	{
	private:
		int _recursiveCountSubsetsHelper(vector<int>& nums, int targetSum, int currentSum, int index);
	public:
		int recursiveCountSubsets(vector<int> nums, int sum);
		int dpCountSubsets(vector<int> nums, int sum);
	};
}