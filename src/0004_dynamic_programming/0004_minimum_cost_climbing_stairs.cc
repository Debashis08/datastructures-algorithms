#include "0004_minimum_cost_climbing_stairs.h"
#include <algorithm>

namespace dsa::minimum_cost_climbing_stairs
{
	int DynamicProgramming::_minCostRecursive(size_t step, vector<int>& cost)
	{
		if (step == 0 || step == 1)
		{
			return cost[step];
		}

		return cost[step] + min(this->_minCostRecursive(step - 1, cost), this->_minCostRecursive(step - 2, cost));
	}

	int DynamicProgramming::recursiveMinimumCostClimbingStairs(vector<int>& cost)
	{
		size_t totalSteps = cost.size();

		if (totalSteps == 1)
		{
			return cost[0];
		}

		return min(this->_minCostRecursive(totalSteps - 1, cost), this->_minCostRecursive(totalSteps - 2, cost));
	}

	int DynamicProgramming::dpMinimumCostClimbingStairs(vector<int>& cost)
	{
		size_t totalSteps = cost.size();
		vector<int> dp(totalSteps, 0);

		if (totalSteps == 1)
		{
			return cost[0];
		}

		dp[0] = cost[0];
		dp[1] = cost[1];

		for (size_t i = 2; i < totalSteps; i++)
		{
			dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
		}

		return min(dp[totalSteps - 1], dp[totalSteps - 2]);
	}
}