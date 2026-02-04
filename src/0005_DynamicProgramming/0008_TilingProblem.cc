#include <0005_DynamicProgramming/0008_TilingProblem.h>

namespace TilingProblem
{
	int DynamicProgramming::NumberOfWaysRecursiveHelper(int n)
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
		result += this->NumberOfWaysRecursiveHelper(n - 1);
		result += this->NumberOfWaysRecursiveHelper(n - 2);

		return result;
	}

	int DynamicProgramming::RecursiveNumberOfWays(int n)
	{
		return this->NumberOfWaysRecursiveHelper(n);
	}

	int DynamicProgramming::DpNumberOfWays(int n)
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