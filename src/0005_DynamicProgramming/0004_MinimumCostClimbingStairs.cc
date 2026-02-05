#include <0005_DynamicProgramming/0004_MinimumCostClimbingStairs.h>
#include <algorithm>

namespace MinimumCostClimbingStairs
{
	int DynamicProgramming::MinCostRecursive(size_t step, vector<int>& cost)
	{
		if (step == 0 || step == 1)
		{
			return cost[step];
		}

		return cost[step] + min(this->MinCostRecursive(step - 1, cost), this->MinCostRecursive(step - 2, cost));
	}

	int DynamicProgramming::RecursiveMinimumCostClimbingStairs(vector<int>& cost)
	{
		size_t totalSteps = cost.size();

		if (totalSteps == 1)
		{
			return cost[0];
		}

		return min(this->MinCostRecursive(totalSteps - 1, cost), this->MinCostRecursive(totalSteps - 2, cost));
	}

	int DynamicProgramming::DpMinimumCostClimbingStairs(vector<int>& cost)
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