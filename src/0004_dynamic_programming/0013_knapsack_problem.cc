#include "0013_knapsack_problem.h"

namespace dsa::knapsack_problem
{
	// dynamic programming private member methods.
	int DynamicProgramming::_recursiveKnapsackHelper(int capacity, vector<int>& weight, vector<int>& profit, int numberOfItems)
	{
		if (capacity <= 0 || numberOfItems == 0)
		{
			return 0;
		}

		int pickCurrentItem = 0;

		// pick the current item only if does not exceed the capacity.
		if (weight[numberOfItems - 1] <= capacity)
		{
			pickCurrentItem = profit[numberOfItems - 1] + this->_recursiveKnapsackHelper(capacity - weight[numberOfItems - 1], weight, profit, numberOfItems - 1);
		}

		int dropCurrentItem = this->_recursiveKnapsackHelper(capacity, weight, profit, numberOfItems - 1);

		return max(pickCurrentItem, dropCurrentItem);
	}

	// dynamic programming public member methods.
	int DynamicProgramming::recursiveKnapsack(int capacity, vector<int> weight, vector<int> profit)
	{
		size_t totalNumberOfItems = weight.size();
		return this->_recursiveKnapsackHelper(capacity, weight, profit, totalNumberOfItems);
	}

	int DynamicProgramming::dpKnapsack(int capacity, vector<int> weight, vector<int> profit)
	{
		int numberOfItems = weight.size();
		vector<vector<int>> dp(numberOfItems + 1, vector<int>(capacity + 1, 0));

		for (int i = 0; i <= numberOfItems; i++)
		{
			for (int j = 0; j <= capacity; j++)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else
				{
					int pickCurrentItem = 0;
					if (weight[i - 1] <= j)
					{
						pickCurrentItem = profit[i - 1] + dp[i - 1][j - weight[i - 1]];
					}
					int dropCurrentItem = dp[i - 1][j];

					dp[i][j] = max(pickCurrentItem, dropCurrentItem);
				}
			}
		}

		return dp[numberOfItems][capacity];
	}

	int DynamicProgramming::dpKnapsackSpaceOptimized(int capacity, vector<int> weight, vector<int> profit)
	{
		int numberOfItems = weight.size();
		vector<int> dp(capacity + 1, 0);

		for (int i = 1; i <= numberOfItems; i++)
		{
			for (int j = capacity; j >= weight[i - 1]; j--)
			{
				dp[j] = max(dp[j], profit[i - 1] + dp[j - weight[i - 1]]);
			}
		}

		return dp[capacity];
	}
}