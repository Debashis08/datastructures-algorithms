#include "0007_decode_ways.h"

namespace decode_ways
{
	int DynamicProgramming::countWaysRecursiveHelper(string& digits, size_t index)
	{
		size_t digitsLength = digits.size();

		// Base case: if the end of the string is reached, return 1 as it signifies a valid decoding.
		if (index >= digitsLength)
		{
			return 1;
		}

		int ways = 0;

		// single digit decoding: check if current digit is not '0'.
		if (digits[index] != '0')
		{
			ways = this->countWaysRecursiveHelper(digits, index + 1);
		}

		// two digit decoding: check if next two digits are valid.
		if ((index + 1 < digitsLength) && ((digits[index] == '1' && digits[index + 1] <= '9') || (digits[index] == '2' && digits[index + 1] <= '6')))
		{
			ways += this->countWaysRecursiveHelper(digits, index + 2);
		}
		return ways;
	}

	int DynamicProgramming::recursiveCountWays(string digits)
	{
		return this->countWaysRecursiveHelper(digits, 0);
	}

	int DynamicProgramming::dpCountways(string digits)
	{
		size_t digitsLength = digits.size();

		vector<int> dp(digitsLength + 1, 0);

		dp[digitsLength] = 1;

		for (int index = digitsLength - 1; index >= 0; index--)
		{
			// single digit decoding: check if current digit is not '0'.
			if (digits[index] != '0')
			{
				dp[index] = dp[index + 1];
			}

			// two digit decoding: check if next two digits are valid.
			if ((index + 1 < digitsLength) && ((digits[index] == '1' && digits[index + 1] <= '9') || (digits[index] == '2' && digits[index + 1] <= '6')))
			{
				dp[index] += dp[index + 2];
			}
		}

		return dp[0];
	}
}