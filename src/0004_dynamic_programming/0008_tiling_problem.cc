#include "0008_tiling_problem.h"

namespace tiling_problem
{
	int DynamicProgramming::_numberOfWaysRecursiveHelper(int n)
	{
		if (n < 0)
		{
			return 0;
		}

		if (n == 0)
		{
			return 1;
		}

		int result = 0;
		result += this->_numberOfWaysRecursiveHelper(n - 1);
		result += this->_numberOfWaysRecursiveHelper(n - 2);

		return result;
	}

	int DynamicProgramming::recursiveNumberOfWays(int n)
	{
		return this->_numberOfWaysRecursiveHelper(n);
	}

	int DynamicProgramming::dpNumberOfWays(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
}