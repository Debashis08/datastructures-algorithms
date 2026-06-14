#include "0006_house_robber2.h"

namespace dsa::house_robber2
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

	int DynamicProgramming::_maxLootDp(size_t firstHouse, size_t lastHouse, vector<int>& houseValues)
	{
		int totalNumberOfHouses = lastHouse - firstHouse + 1;

		if (totalNumberOfHouses == 0)
		{
			return 0;
		}

		if (totalNumberOfHouses == 1)
		{
			return houseValues[firstHouse];
		}

		vector<int> dp(totalNumberOfHouses, 0);

		dp[0] = houseValues[firstHouse];
		dp[1] = max(houseValues[firstHouse], houseValues[firstHouse + 1]);

		for (size_t i = 2; i < totalNumberOfHouses; i++)
		{
			dp[i] = max(houseValues[firstHouse + i] + dp[i - 2], dp[i - 1]);
		}

		return dp[totalNumberOfHouses - 1];
	}

	int DynamicProgramming::recursiveMaximumLoot(vector<int>& houseValues)
	{
		if (houseValues.size() == 0)
		{
			return 0;
		}

		if (houseValues.size() == 1)
		{
			return houseValues[0];
		}

		size_t totalNumberOfHouses = houseValues.size()-1;

		// Case 1: exclude last house.
		vector<int> pickFirstHouse(houseValues.begin(), houseValues.end() - 1);

		// Case 2: exlcude first house.
		vector<int> pickLastHouse(houseValues.begin() + 1, houseValues.end());

		return max(this->_maxLootRecursive(totalNumberOfHouses, pickFirstHouse), this->_maxLootRecursive(totalNumberOfHouses, pickLastHouse));
	}

	int DynamicProgramming::dpMaximumLoot(vector<int>& houseValues)
	{
		size_t totalNumberOfHouses = houseValues.size();

		if (totalNumberOfHouses == 0)
		{
			return 0;
		}

		if (totalNumberOfHouses == 1)
		{
			return houseValues[0];
		}

		// Case 1: exclude last house.
		int pickFirstHouse = this->_maxLootDp(0, totalNumberOfHouses - 2, houseValues);

		// Case 2: exlcude first house.
		int pickLastHouse = this->_maxLootDp(1, totalNumberOfHouses - 1, houseValues);

		return max(pickFirstHouse, pickLastHouse);
	}
}