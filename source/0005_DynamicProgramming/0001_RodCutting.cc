#include "../../include/0005_DynamicProgramming/0001_RodCutting.h"
#include<iostream>
#include<vector>
using namespace std;

namespace RodCutting
{
	DynamicProgramming::DynamicProgramming(int length, vector<int> price)
	{
		this->_length = length;
		this->_price = price;
	}

	int DynamicProgramming::RecursiveRodCutting(int length)
	{
		// Base case
		if (length == 0)
		{
			return 0;
		}
		
		int result = 0;

		for (int cut = 1; cut <= length; cut++)
		{
			result = max(result, this->_price[cut - 1] + this->RecursiveRodCutting(length - cut));
		}

		return result;
	}

	int DynamicProgramming::DynamicProgrammingRodCutting()
	{
		vector<int> dp(this->_price.size() + 1, 0);

		// Find maximum value for all rod of length i.
		for (int i = 1; i <= this->_length; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i] = max(dp[i], this->_price[j - 1] + dp[i-j]);
			}
		}

		return dp[this->_length];
	}
}