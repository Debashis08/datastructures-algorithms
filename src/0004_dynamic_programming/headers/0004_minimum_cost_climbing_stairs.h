#pragma once
#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
given an array of integers cost[] of length n, where cost[i] is the cost of the ith step on a staircase. once the cost is paid, we can either climb 1 or 2 steps.
we can either start from the step with index 0, or the step with index 1. the task is to find the minimum cost to reach the top.

*/

namespace dsa::minimum_cost_climbing_stairs
{
	class DynamicProgramming
	{
	private:
		int _minCostRecursive(size_t step, vector<int>& cost);
	public:
		int recursiveMinimumCostClimbingStairs(vector<int>& cost);
		int dpMinimumCostClimbingStairs(vector<int>& cost);
	};
}