#include "0005_house_robber_1.h"

namespace dsa::house_robber_1
{
	int DynamicProgramming::findMaxLoot(vector<int>& houses)
	{
		size_t n = houses.size();
		if (n == 0)
		{
			return 0;
		}

		vector<int> dp(n + 1, 0);

		dp[0] = 0;
		dp[1] = houses[0];

		for (int i = 2; i <= n; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + houses[i - 1]);
		}

		return dp[n];
	}
}