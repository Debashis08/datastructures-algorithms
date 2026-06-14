#include "0005_house_robber1.h"

namespace house_robber1
{
	int DynamicProgramming::_maxLootRecursive(size_t house, vector<int>& houseValues)
	{
		if (house <= 0)
		{
			return 0;
		}

		if (house == 1)
		{
			return houseValues[0];
		}

		int pickCurrentHouse = houseValues[house - 1] + this->_maxLootRecursive(house - 2, houseValues);
		int dropCurrentHouse = this->_maxLootRecursive(house - 1, houseValues);

		return max(pickCurrentHouse, dropCurrentHouse);
	}

	int DynamicProgramming::recursiveMaximumLoot(vector<int>& houseValues)
	{
		size_t totalNumberOfHouses = houseValues.size();
		return this->_maxLootRecursive(totalNumberOfHouses, houseValues);
	}

	int DynamicProgramming::dpMaximumLoot(vector<int>& houseValues)
	{
		size_t totalNumberOfHouses = houseValues.size();
		vector<int> dp(totalNumberOfHouses + 1, 0);

		dp[0] = 0;
		dp[1] = houseValues[0];

		for (size_t i = 2; i <= totalNumberOfHouses; i++)
		{
			dp[i] = max(dp[i - 2] + houseValues[i - 1], dp[i - 1]);
		}

		return dp[totalNumberOfHouses];
	}
}