#pragma once
#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
Given an array of integers cost[] of length n, where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, we can either climb 1 or 2 steps.
We can either start from the step with index 0, or the step with index 1. The task is to find the minimum cost to reach the top.

*/

namespace MinimumCostClimbingStairs
{
	class DynamicProgramming
	{
	private:
		int MinCostRecursive(size_t step, vector<int>& cost);
	public:
		int RecursiveMinimumCostClimbingStairs(vector<int>& cost);
		int DpMinimumCostClimbingStairs(vector<int>& cost);
	};
}