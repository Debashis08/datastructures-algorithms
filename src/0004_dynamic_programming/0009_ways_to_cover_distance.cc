#include "0009_ways_to_cover_distance.h"

namespace dsa::ways_to_cover_distance
{
	int DynamicProgramming::findWaysToCover(int distance)
	{
		if (distance < 0)
		{
			return 0;
		}

		vector<int>dp(distance + 1, 0);
		
		dp[0] = 1;
		for (int i = 1; i <= distance; i++)
		{
			if (i <= 2)
			{
				dp[i] = i;
			}
			else
			{
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			}
		}

		return dp[distance];
	}
}