#include "0007_tiling_1x2.h"

namespace dsa::tiling_1x2
{
	int DynamicProgramming::findNumberOfWays(int n)
	{
		if (n < 0)
		{
			return 0;
		}

		if (n == 0 || n == 1)
		{
			return 1;
		}

		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 1];
		}

		return dp[n];
	}
}