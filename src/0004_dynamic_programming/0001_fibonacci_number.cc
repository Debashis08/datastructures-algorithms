#include "0001_fibonacci_number.h"

namespace fibonacci_number
{
	int DynamicProgramming::recursiveNthFibonacci(int n)
	{
		if (n <= 1)
		{
			return n;
		}

		return this->recursiveNthFibonacci(n - 1) + this->recursiveNthFibonacci(n - 2);
	}

	int DynamicProgramming::dpNthFibonacci(int n)
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
