#include "0015_CountSubsetsForSum.h"

namespace CountSubsetsForSum
{
	// Dynamic Programming private member methods
	int DynamicProgramming::RecursiveCountSubsetsHelper(vector<int>& nums, int targetSum, int currentSum, int index)
	{
		int noOfElements = nums.size();
		if (index == noOfElements)
		{
			return (targetSum == currentSum);
		}

		int exclude = this->RecursiveCountSubsetsHelper(nums, targetSum, currentSum, index + 1);
		int include = 0;

		if ((nums[index] + currentSum) <= targetSum)
		{
			include = this->RecursiveCountSubsetsHelper(nums, targetSum, currentSum + nums[index], index + 1);
		}

		return (exclude + include);
	}

	// Dynamic Programming public member methods
	int DynamicProgramming::RecursiveCountSubsets(vector<int> nums, int sum)
	{
		return this->RecursiveCountSubsetsHelper(nums, sum, 0, 0);
	}

	int DynamicProgramming::DpCountSubsets(vector<int> nums, int sum)
	{
		int noOfElements = nums.size();
		vector<vector<int>> dp(noOfElements + 1, vector<int>(sum + 1, 0));

		dp[0][0] = 1;

		for (int i = 1; i <= noOfElements; i++)
		{
			for (int j = 0; j <= sum; j++)
			{
				// Considering excluding the current element
				dp[i][j] = dp[i - 1][j];

				// Case to include the current element
				if (nums[i - 1] <= j)
				{
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[noOfElements][sum];
	}
}