#pragma once

#include<vector>
using namespace std;

/*
pattern 2
subset / 0-1 knapsack

description
Given two arrays, val[] and wt[], where val[i] represents the value and wt[i] represents the weight of the ith item, and an integer W representing the knapsack capacity, 
find the maximum total value that can be obtained by selecting items without exceeding the capacity W.
Each item can either be selected completely or not selected at all. Fractional selection of an item is not allowed.

Examples:
Input:  W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: There are two items with weights 4 and 1 that can fit within the knapsack capacity. Selecting the item with weight 4 gives value 1, 
while selecting the item with weight 1 gives value 3. Both items cannot be selected together as their total weight is 5, 
which exceeds the capacity. Hence, the maximum possible value is 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
Output: 0
Explanation: All the item weights are greater than the knapsack capacity.
*/

namespace dsa::knapsack_01
{
	class DynamicProgramming
	{
	private:
	public:
		int knapsack(int capacity, vector<int>& weight, vector<int>& profit);
	};
}