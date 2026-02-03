#include "../../include/0005_DynamicProgramming/0006_HouseRobber2.h"

namespace HouseRobber2
{
	int DynamicProgramming::MaxLootRecursive(size_t house, vector<int>& houseValues)
	{
		if (house <= 0)
		{
			return 0;
		}

		if (house == 1)
		{
			return houseValues[0];
		}

		int pickCurrentHouse = houseValues[house - 1] + this->MaxLootRecursive(house - 2, houseValues);
		int dropCurrentHouse = this->MaxLootRecursive(house - 1, houseValues);

		return max(pickCurrentHouse, dropCurrentHouse);
	}

	int DynamicProgramming::MaxLootDp(size_t firstHouse, size_t lastHouse, vector<int>& houseValues)
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

	int DynamicProgramming::RecursiveMaximumLoot(vector<int>& houseValues)
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

		// Case 1: Exclude last house.
		vector<int> pickFirstHouse(houseValues.begin(), houseValues.end() - 1);

		// Case 2: Exlcude first house.
		vector<int> pickLastHouse(houseValues.begin() + 1, houseValues.end());

		return max(this->MaxLootRecursive(totalNumberOfHouses, pickFirstHouse), this->MaxLootRecursive(totalNumberOfHouses, pickLastHouse));
	}

	int DynamicProgramming::DpMaximumLoot(vector<int>& houseValues)
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

		// Case 1: Exclude last house.
		int pickFirstHouse = this->MaxLootDp(0, totalNumberOfHouses - 2, houseValues);

		// Case 2: Exlcude first house.
		int pickLastHouse = this->MaxLootDp(1, totalNumberOfHouses - 1, houseValues);

		return max(pickFirstHouse, pickLastHouse);
	}
}