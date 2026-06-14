#include "0010_ways_to_cover_distance.h"

namespace ways_to_cover_distance
{
	// dynamic programming private member methods.
	int DynamicProgramming::_waysToCoverDistanceRecursiveHelper(int dist)
	{
		if (dist < 0)
		{
			return 0;
		}

		if (dist == 0)
		{
			return 1;
		}
		
		int result = 0;
		result += this->_waysToCoverDistanceRecursiveHelper(dist - 1);
		result += this->_waysToCoverDistanceRecursiveHelper(dist - 2);
		result += this->_waysToCoverDistanceRecursiveHelper(dist - 3);
		
		return result;
	}

	// dynamic programming public member methods.
	int DynamicProgramming::recursiveWaysToCoverDistance(int dist)
	{
		return this->_waysToCoverDistanceRecursiveHelper(dist);
	}

	int DynamicProgramming::dpWaysToCoverDistance(int dist)
	{
		vector<int> dp(dist + 1, 0);
		dp[0] = 1;
		if (dist >= 1)
		{
			dp[1] = 1;
		}
		if (dist >= 2)
		{
			dp[2] = 2;
		}

		for(int i = 3; i <= dist; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		return dp[dist];
	}
}