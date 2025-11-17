#include "../../include/0005_DynamicProgramming/0011_CountWaysToReachNthStairIncludeOrder.h"

namespace CountWaysToReachNthStairIncludeOrder
{
	// Dynamic Programming Private Member Methods.
	int DynamicProgramming::RecursiveCountWaysToReachNthStairIncludeOrderHelper(int n)
	{
		if (n < 0)
		{
			return 0;
		}
		if (n == 0 || n == 1)
		{
			return 1;
		}

		int result = 0;
		result += this->RecursiveCountWaysToReachNthStairIncludeOrderHelper(n - 1);
		result += this->RecursiveCountWaysToReachNthStairIncludeOrderHelper(n - 2);

		return result;
	}

	// Dynamic Programming Public Member Methods.
	int DynamicProgramming::RecursiveCountWaysToReachNthStairIncludeOrder(int n)
	{
		return this->RecursiveCountWaysToReachNthStairIncludeOrderHelper(n);
	}

	int DynamicProgramming::DpCountWaysToReachNthStairIncludeOrder(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		if (n >= 1)
		{
			dp[1] = 1;
		}
		for(int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
}