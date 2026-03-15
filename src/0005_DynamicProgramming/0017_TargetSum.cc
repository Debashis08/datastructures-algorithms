#include <0005_DynamicProgramming/0017_TargetSum.h>

namespace TargetSum
{
	int DynamicProgramming::recursiveFindTotalWaysHelper(vector<int>& nums, int currentSum, int targetSum, int index)
	{
		// Base case
		if (currentSum == targetSum && index == nums.size())
		{
			return 1;
		}

		if (index >= nums.size())
		{
			return 0;
		}

		// Return total count of two possible ways while considering the current element
		// 1. Add the current element to currentSum
		// 2. Subtract the current element from currentSum
		return (
			this->recursiveFindTotalWaysHelper(nums, currentSum + nums[index], targetSum, index + 1)
			+
			this->recursiveFindTotalWaysHelper(nums, currentSum - nums[index], targetSum, index + 1));
	}


	int DynamicProgramming::recursiveFindTotalWays(vector<int> nums, int target)
	{
		return this->recursiveFindTotalWaysHelper(nums, 0, target, 0);
	}

	int DynamicProgramming::dpFindTotalWays(vector<int> nums, int target)
	{
		int totalSum = accumulate(nums.begin(), nums.end(), 0);

		if (abs(target) > totalSum)
		{
			return 0;
		}

		int totalSumWithTarget = totalSum + target;
		if (totalSumWithTarget % 2 != 0)
		{
			return 0;
		}

		int targetSubsetSum = totalSumWithTarget / 2;
		int noOfElements = nums.size();
		vector<vector<int>> dp(noOfElements + 1, vector<int>(targetSubsetSum + 1, 0));

		dp[0][0] = 1;

		for (int i = 1; i <= noOfElements; i++)
		{
			for (int j = 0; j <= targetSubsetSum; j++)
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

		return dp[noOfElements][targetSubsetSum];
	}
}