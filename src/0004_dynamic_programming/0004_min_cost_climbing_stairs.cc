#include "0004_min_cost_climbing_stairs.h"
#include <algorithm>

namespace dsa::min_cost_climbing_stairs
{
	int DynamicProgramming::minCostClimbingStairs(vector<int>& cost)
	{
		size_t steps = cost.size();
		vector<int> dp(steps + 1, 0);

		if (steps == 1)
		{
			return cost[0];
		}

		dp[0] = cost[0];
		dp[1] = cost[1];

		for (int i = 2; i < steps; i++)
		{
			dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
		}

		return min(dp[steps - 1], dp[steps - 2]);
	}
}