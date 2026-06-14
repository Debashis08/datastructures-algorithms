#include "0015_count_subsets_for_sum.h"

namespace count_subsets_for_sum
{
	// dynamic programming private member methods
	int DynamicProgramming::_recursiveCountSubsetsHelper(vector<int>& nums, int targetSum, int currentSum, int index)
	{
		int noOfElements = nums.size();
		if (index == noOfElements)
		{
			return (targetSum == currentSum);
		}

		int exclude = this->_recursiveCountSubsetsHelper(nums, targetSum, currentSum, index + 1);
		int include = 0;

		if ((nums[index] + currentSum) <= targetSum)
		{
			include = this->_recursiveCountSubsetsHelper(nums, targetSum, currentSum + nums[index], index + 1);
		}

		return (exclude + include);
	}

	// dynamic programming public member methods
	int DynamicProgramming::recursiveCountSubsets(vector<int> nums, int sum)
	{
		return this->_recursiveCountSubsetsHelper(nums, sum, 0, 0);
	}

	int DynamicProgramming::dpCountSubsets(vector<int> nums, int sum)
	{
		int noOfElements = nums.size();
		vector<vector<int>> dp(noOfElements + 1, vector<int>(sum + 1, 0));

		dp[0][0] = 1;

		for (int i = 1; i <= noOfElements; i++)
		{
			for (int j = 0; j <= sum; j++)
			{
				// considering excluding the current element
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