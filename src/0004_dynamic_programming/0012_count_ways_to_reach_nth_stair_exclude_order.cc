#include "0012_count_ways_to_reach_nth_stair_exclude_order.h"

namespace dsa::count_ways_to_reach_nth_stair_exclude_order
{
	// notes:
	/*
	To avoid counting ways which only differ in order, we can assume that a person initially takes only steps of size 1 followed by steps of size 2.
	In other words, once a person takes a step of size 2, he will continue taking steps of size 2 till he reaches the nth stair.
		A person can reach nth stair from either(n - 1)th stair or from(n - 2)th stair.so, there are two cases :
	the person has reached nth step from(n - 1)th step, this means that the last step was of size 1 and all the previous steps should also be of size 1. so, there is only 1 way.
		the person has reached nth step from(n - 2)th step, this means that the last step was of size 2 and the previous steps can either be of size 1 or size 2.
		therefore the recurrence relation will be :

	nthStair(n) = 1 (last step was of size 1) + nthStair(n - 2) (last step was of size 2)
	so f(n) = 1 + f(n - 2)
	*/

	// dynamic programming private member methods.
	int DynamicProgramming::_recursiveCountWaysHelper(int n)
	{
		if (n < 0)
		{
			return 0;
		}
		if (n == 0)
		{
			return 1;
		}

		return 1 + this->_recursiveCountWaysHelper(n - 2);
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
		for (int i = 2; i <= n; i++)
		{
			dp[i] = 1 + dp[i - 2];
		}
		return dp[n];
	}
}