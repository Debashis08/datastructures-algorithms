#include "0014_subset_sum_problem.h"

namespace subset_sum_problem
{
	// dynamic programming private member methods.
	bool DynamicProgramming::subsetSumRecursiveHelper(vector<int>& nums, int sum, int numberOfElements)
	{
		// Base case.
		// if the sum is 0, we found a subset with a given sum.
		if (sum == 0)
		{
			return true;
		}

		// Base case.
		// if there are no elements left to process and the sum is not 0 yet, we did not find a subset with given sum, so return false.
		if (numberOfElements == 0)
		{
			return false;
		}

		// when the current element is greater than the sum, we skip it, as all elemeents are non-negative.
		if (nums[numberOfElements - 1] > sum)
		{
			return this->subsetSumRecursiveHelper(nums, sum, numberOfElements - 1);
		}

		// when the current element is equal to or less than the sum, we have two choices.
		// 1. include the current element in the subset and the sum is reduced by the current element value and also the number of elements is reducded by 1.
		// 2. exclude the current element from the subset and the sum remains the same but the number of eleements is reduced by 1.
		// if either of these two choices return true, we return true.
		return this->subsetSumRecursiveHelper(nums, sum - nums[numberOfElements - 1], numberOfElements - 1) || this->subsetSumRecursiveHelper(nums, sum, numberOfElements - 1);
	}

	// dynamic programming public member methods.
	bool DynamicProgramming::recursiveSubsetSum(vector<int> nums, int sum)
	{
		int numberOfElements = nums.size();
		return this->subsetSumRecursiveHelper(nums, sum, numberOfElements);
	}

	bool DynamicProgramming::dpIsSubsetSum(vector<int> nums, int sum)
	{
		int numberOfElements = nums.size();
		vector<vector<bool>> dp(numberOfElements + 1, vector<bool>(sum + 1, false));

		// when the sum is 0, the result is true
		for (int i = 0; i < numberOfElements; i++)
		{
			dp[i][0] = true;
		}

		for (int i = 1; i < numberOfElements + 1; i++)
		{
			for (int j = 1; j < sum + 1; j++)
			{
				if (j < nums[i - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					// include or exclude the current element
					dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
				}
			}
		}

		return dp[numberOfElements][sum];
	}
}