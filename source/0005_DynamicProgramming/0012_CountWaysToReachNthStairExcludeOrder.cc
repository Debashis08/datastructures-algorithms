#include "../../include/0005_DynamicProgramming/0012_CountWaysToReachNthStairExcludeOrder.h"

namespace CountWaysToReachNthStairExcludeOrder
{
	// notes:
	/*
	To avoid counting ways which only differ in order, we can assume that a person initially takes only steps of size 1 followed by steps of size 2.
	In other words, once a person takes a step of size 2, he will continue taking steps of size 2 till he reaches the nth stair.
		A person can reach nth stair from either(n - 1)th stair or from(n - 2)th stair.So, there are two cases :
	The person has reached nth step from(n - 1)th step, this means that the last step was of size 1 and all the previous steps should also be of size 1. So, there is only 1 way.
		The person has reached nth step from(n - 2)th step, this means that the last step was of size 2 and the previous steps can either be of size 1 or size 2.
		Therefore the Recurrence relation will be :

	nthStair(n) = 1 (last step was of size 1) + nthStair(n - 2) (last step was of size 2)
	so f(n) = 1 + f(n - 2)
	*/

	// Dynamic Programming Private Member Methods.
	int DynamicProgramming::RecursiveCountWaysToReachNthStairExcludeOrderHelper(int n)
	{
		if (n < 0)
		{
			return 0;
		}
		if (n == 0)
		{
			return 1;
		}

		return 1 + this->RecursiveCountWaysToReachNthStairExcludeOrderHelper(n - 2);
	}

	// Dynamic Programming Public Member Methods.
	int DynamicProgramming::RecursiveCountWaysToReachNthStairExcludeOrder(int n)
	{
		return this->RecursiveCountWaysToReachNthStairExcludeOrderHelper(n);
	}

	int DynamicProgramming::DpCountWaysToReachNthStairExcludeOrder(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		if (n >= 1)
		{
			dp[1] = 1;
		}
		for (int i = 2; i <= n; i++)
		{
			dp[i] = 1 + dp[i - 2];
		}
		return dp[n];
	}
}