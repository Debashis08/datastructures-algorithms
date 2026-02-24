#include <0005_DynamicProgramming/0014_SubsetSumProblem.h>

namespace SubsetSumProblem
{
	// Dynamic Programming Private Member Methods.
	bool DynamicProgramming::SubsetSumRecursiveHelper(vector<int>& nums, int sum, int numberOfElements)
	{
		// Base case.
		// If the sum is 0, we found a subset with a given sum.
		if (sum == 0)
		{
			return true;
		}

		// Base case.
		// If there are no elements left to process and the sum is not 0 yet, we did not find a subset with given sum, so return false.
		if (numberOfElements == 0)
		{
			return false;
		}

		// When the current element is greater than the sum, we skip it, as all elemeents are non-negative.
		if (nums[numberOfElements - 1] > sum)
		{
			return this->SubsetSumRecursiveHelper(nums, sum, numberOfElements - 1);
		}

		// When the current element is equal to or less than the sum, we have two choices.
		// 1. Include the current element in the subset and the sum is reduced by the current element value and also the number of elements is reducded by 1.
		// 2. Exclude the current element from the subset and the sum remains the same but the number of eleements is reduced by 1.
		// If either of these two choices return true, we return true.
		return this->SubsetSumRecursiveHelper(nums, sum - nums[numberOfElements - 1], numberOfElements - 1) || this->SubsetSumRecursiveHelper(nums, sum, numberOfElements - 1);
	}

	// Dynamic Programming Public Member Methods.
	bool DynamicProgramming::RecursiveSubsetSum(vector<int> nums, int sum)
	{
		int numberOfElements = nums.size();
		return this->SubsetSumRecursiveHelper(nums, sum, numberOfElements);
	}

	bool DynamicProgramming::dpIsSubsetSum(vector<int> nums, int sum)
	{
		int numberOfElements = nums.size();
		vector<vector<bool>> dp(numberOfElements + 1, vector<bool>(sum + 1, false));

		// When the sum is 0, the result is true
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