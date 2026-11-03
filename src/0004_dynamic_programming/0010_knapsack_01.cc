#include "0010_knapsack_01.h"

namespace dsa::knapsack_01
{
	int DynamicProgramming::knapsack(int capacity, vector<int>& weight, vector<int>& profit)
	{
		int n = weight.size();

		vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= capacity; j++)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else
				{
					// Either pick or drop the current item.
					int pick = 0;
					if (weight[i - 1] <= j)
					{
						pick = profit[i - 1] + dp[i - 1][j - weight[i - 1]];
					}
					
					int drop = dp[i - 1][j];

					dp[i][j] = max(pick, drop);
				}
			}
		}

		return dp[n][capacity];
	}
}