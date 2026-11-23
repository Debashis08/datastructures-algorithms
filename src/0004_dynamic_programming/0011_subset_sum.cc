#include"0011_subset_sum.h"

namespace dsa::subset_sum
{
	bool DynamicProgramming::canPartitionSum(vector<int>& nums, int sum)
	{
		int n = nums.size();

		vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

		// When the sum is 0, the result is true.
		for (int i = 0; i < n + 1; i++)
		{
			dp[i][0] = true;
		}

		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < sum + 1; j++)
			{
				// The current sum (which is j) is less than current element. Can not include current element in subset.
				if (j < nums[i - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					// Include or exclude the current element.
					dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);
				}
			}
		}


		return dp[n][sum];
	}
}