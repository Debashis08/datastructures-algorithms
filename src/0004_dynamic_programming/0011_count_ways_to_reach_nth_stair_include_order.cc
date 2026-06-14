#include "0011_count_ways_to_reach_nth_stair_include_order.h"

namespace dsa::count_ways_to_reach_nth_stair_include_order
{
	// dynamic programming private member methods.
	int DynamicProgramming::_recursiveCountWaysHelper(int n)
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
		result += this->_recursiveCountWaysHelper(n - 1);
		result += this->_recursiveCountWaysHelper(n - 2);

		return result;
	}

	// dynamic programming public member methods.
	int DynamicProgramming::recursiveCountWays(int n)
	{
		return this->_recursiveCountWaysHelper(n);
	}

	int DynamicProgramming::dpCountWays(int n)
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