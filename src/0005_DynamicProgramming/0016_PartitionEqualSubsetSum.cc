#include <0005_DynamicProgramming/0016_PartitionEqualSubsetSum.h>

namespace PartitionEqualSubsetSum
{
	bool DynamicProgramming::RecursivePartitionEqualSubsetsHelper(vector<int>& nums, int targetSum, int numberOfElements)
	{
		if (targetSum == 0)
		{
			return true;
		}

		if (numberOfElements == 0)
		{
			return false;
		}

		if (nums[numberOfElements - 1] > targetSum)
		{
			return this->RecursivePartitionEqualSubsetsHelper(nums, targetSum, numberOfElements - 1);
		}

		return (this->RecursivePartitionEqualSubsetsHelper(nums, targetSum - nums[numberOfElements - 1], numberOfElements - 1) || this->RecursivePartitionEqualSubsetsHelper(nums, targetSum, numberOfElements - 1));
	}

	bool DynamicProgramming::RecursivePartitionEqualSubsets(vector<int> nums)
	{
		int targetSum = accumulate(nums.begin(), nums.end(), 0);

		// Check if targetSum is odd, then equal partition is not possible at all
		if (targetSum % 2 != 0)
		{
			return false;
		}

		int numberOfElements = nums.size();
		return this->RecursivePartitionEqualSubsetsHelper(nums, targetSum / 2, numberOfElements);
	}

	bool DynamicProgramming::DpPartitionEqualSubsets(vector<int> nums)
	{
		int targetSum = accumulate(nums.begin(), nums.end(), 0);

		// Check if targetSum is odd, then equal partition is not possible at all
		if (targetSum % 2 != 0)
		{
			return false;
		}

		int numberOfElements = nums.size();
		targetSum /= 2;
		vector<vector<bool>> dp(numberOfElements + 1, vector<bool>(targetSum + 1, false));

		for (int i = 0; i <= numberOfElements; i++)
		{
			dp[i][0] = true;
		}

		for (int i = 1; i <= numberOfElements; i++)
		{
			for (int j = 1; j <= targetSum; j++)
			{
				if (nums[i - 1] > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
				}
			}
		}

		return dp[numberOfElements][targetSum];
	}
}