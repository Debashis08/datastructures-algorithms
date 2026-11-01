#include "0008_friends_pairing.h"

namespace dsa::friends_pairing
{
	int DynamicProgramming::findPairings(int n)
	{
		vector<int> dp(n + 1, 0);

		for (int i = 0; i <= n; i++)
		{
			if (i <= 2)
			{
				dp[i] = i;
			}
			else
			{
				dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
			}
		}

		return dp[n];
	}
}