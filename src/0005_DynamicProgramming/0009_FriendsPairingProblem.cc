#include <0005_DynamicProgramming/0009_FriendsPairingProblem.h>

namespace FriendsPairingProblem
{
	// Dynamic Programming Private Member Methods.
	int DynamicProgramming::CountFriendsPairingsRecursiveHelper(int n)
	{
		if (n <= 1)
		{
			return 1;
		}
		int result = 0;
		result += this->CountFriendsPairingsRecursiveHelper(n - 1);
		result += (n - 1) * this->CountFriendsPairingsRecursiveHelper(n - 2);

		return result;
	}

	// Dynamic Programming Public Member Methods.
	int DynamicProgramming::RecursiveCountFriendsPairings(int n)
	{
		return this->CountFriendsPairingsRecursiveHelper(n);
	}

	int DynamicProgramming::DpCountFriendsPairings(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
		}

		return dp[n];
	}
}