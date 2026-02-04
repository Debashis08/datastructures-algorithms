#include <0005_DynamicProgramming/0010_WaysToCoverDistance.h>

namespace WaysToCoverDistance
{
	// Dynamic Programming Private Member Methods.
	int DynamicProgramming::WaysToCoverDistanceRecursiveHelper(int dist)
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
		result += this->WaysToCoverDistanceRecursiveHelper(dist - 1);
		result += this->WaysToCoverDistanceRecursiveHelper(dist - 2);
		result += this->WaysToCoverDistanceRecursiveHelper(dist - 3);
		
		return result;
	}

	// Dynamic Programming Public Member Methods.
	int DynamicProgramming::RecursiveWaysToCoverDistance(int dist)
	{
		return this->WaysToCoverDistanceRecursiveHelper(dist);
	}

	int DynamicProgramming::DpWaysToCoverDistance(int dist)
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