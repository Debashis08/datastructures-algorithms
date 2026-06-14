#include "0009_friends_pairing_problem.h"

namespace dsa::friends_pairing_problem
{
	// dynamic programming private member methods.
	int DynamicProgramming::_countFriendsPairingsRecursiveHelper(int n)
	{
		if (n <= 1)
		{
			return 1;
		}
		int result = 0;
		result += this->_countFriendsPairingsRecursiveHelper(n - 1);
		result += (n - 1) * this->_countFriendsPairingsRecursiveHelper(n - 2);

		return result;
	}

	// dynamic programming public member methods.
	int DynamicProgramming::recursiveCountFriendsPairings(int n)
	{
		return this->_countFriendsPairingsRecursiveHelper(n);
	}

	int DynamicProgramming::dpCountFriendsPairings(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
		}

		return dp[n];
	}
}