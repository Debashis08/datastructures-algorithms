#include "../../include/0005_DynamicProgramming/0002_TribonacciNumber.h"

namespace TribonacciNumber
{
	int DynamicProgramming::RecursiveNthTribonacci(int n)
	{
		if (n == 0 || n == 1 || n == 2)
		{
			return 0;
		}

		if (n == 3)
		{
			return 1;
		}

		return this->RecursiveNthTribonacci(n - 1) + this->RecursiveNthTribonacci(n - 2) + this->RecursiveNthTribonacci(n - 3);
	}

	int DynamicProgramming::DpNthTribonacci(int n)
	{
		vector<int> dp(n, 0);
		dp[0] = dp[1] = 0;
		dp[2] = 1;

		for (int i = 3; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		
		return dp[n - 1];
	}
}
