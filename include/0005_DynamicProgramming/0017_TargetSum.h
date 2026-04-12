#pragma once

#include<vector>
#include<numeric>
using namespace std;

/*
Pattern 2
Subset / 0-1 Knapsack

Description
Given an array arr[] of length N and an integer target.
You want to build an expression out of arr[] by adding one of the symbols '+' and '-' before each integer in arr[] and then concatenate all the integers. 
Return the number of different expressions that can be built, which evaluates to target.

Example:

Input : N = 5, arr[] = {1, 1, 1, 1, 1}, target = 3
Output: 5
Explanation:
There are 5 ways to assign symbols to
make the sum of array be target 3.

-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Input: N = 1, arr[] = {1}, target = 1
Output: 1
*/

namespace TargetSum
{
	class DynamicProgramming
	{
	private:
		int RecursiveFindTotalWaysHelper(vector<int>& nums, int currentSum, int targetSum, int index);
		int DpFindTotalWays();
	public:
		int RecursiveFindTotalWays(vector<int> nums, int target);
		int DpFindTotalWays(vector<int> nums, int target);
	};
}