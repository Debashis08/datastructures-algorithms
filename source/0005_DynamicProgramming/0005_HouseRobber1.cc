#include "../../include/0005_DynamicProgramming/0005_HouseRobber1.h"

namespace HouseRobber1
{
	int DynamicProgramming::MaxLootRecursive(int house, vector<int>& houseValues)
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

	int DynamicProgramming::RecursiveMaximumLoot(vector<int>& houseValues)
	{
		int totalNumberOfHouses = houseValues.size();
		return this->MaxLootRecursive(totalNumberOfHouses, houseValues);
	}

	int DynamicProgramming::DpMaximumLoot(vector<int>& houseValues)
	{
		int totalNumberOfHouses = houseValues.size();
		vector<int> dp(totalNumberOfHouses + 1, 0);

		dp[0] = 0;
		dp[1] = houseValues[0];

		for (int i = 2; i <= totalNumberOfHouses; i++)
		{
			dp[i] = max(dp[i - 2] + houseValues[i - 1], dp[i - 1]);
		}

		return dp[totalNumberOfHouses];
	}
}