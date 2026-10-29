#include "0006_house_robber_2.h"

namespace dsa::house_robber_2
{
	int DynamicProgramming::_maxLoot(size_t first, size_t last, vector<int>& houses)
	{
		int n = last - first + 1;

		if (n == 1)
		{
			return houses[first];
		}

		vector<int> dp(n, 0);
		dp[0] = houses[first];
		dp[1] = max(houses[first], houses[first + 1]);

		for (int i = 2; i < n; i++)
		{
			dp[i] = max(dp[i - 1], houses[first + i] + dp[i - 2]);
		}

		return dp[n - 1];
	}

	int DynamicProgramming::findMaxLoot(vector<int>& houses)
	{
		size_t n = houses.size();
		if (n == 0)
		{
			return 0;
		}

		if (n == 1)
		{
			return houses[0];
		}

		// Case 1: exclude last house.
		int pickFirstHouse = this->_maxLoot(0, n - 2, houses);

		// Case 2: exclude first house.
		int pickLastHouse = this->_maxLoot(1, n - 1, houses);

		return max(pickFirstHouse, pickLastHouse);
	}
}