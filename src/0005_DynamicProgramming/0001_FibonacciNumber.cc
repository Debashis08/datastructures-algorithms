#include <0005_DynamicProgramming/0001_FibonacciNumber.h>

namespace FibonacciNumber
{
	int DynamicProgramming::RecursiveNthFibonacci(int n)
	{
		if (n <= 1)
		{
			return n;
		}

		return this->RecursiveNthFibonacci(n - 1) + this->RecursiveNthFibonacci(n - 2);
	}

	int DynamicProgramming::DpNthFibonacci(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
}
