#pragma once

#include<vector>
#include<numeric>
using namespace std;

/*
pattern 2
subset / 0-1 knapsack

description
given an array arr[] of length N and an integer target.
you want to build an expression out of arr[] by adding one of the symbols '+' and '-' before each integer in arr[] and then concatenate all the integers. 
return the number of different expressions that can be built, which evaluates to target.

example:

input : N = 5, arr[] = {1, 1, 1, 1, 1}, target = 3
output: 5
explanation:
there are 5 ways to assign symbols to
make the sum of array be target 3.

-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

input: N = 1, arr[] = {1}, target = 1
output: 1
*/

namespace dsa::target_sum
{
	class DynamicProgramming
	{
	private:
		int _recursiveFindTotalWaysHelper(vector<int>& nums, int currentSum, int targetSum, int index);
	public:
		int recursiveFindTotalWays(vector<int> nums, int target);
		int dpFindTotalWays(vector<int> nums, int target);
	};
}