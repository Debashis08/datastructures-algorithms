#include <0005_DynamicProgramming/0007_DecodeWays.h>

namespace DecodeWays
{
	int DynamicProgramming::CountWaysRecursiveHelper(string& digits, size_t index)
	{
		size_t digitsLength = digits.size();

		// Base case: If the end of the string is reached, return 1 as it signifies a valid decoding.
		if (index >= digitsLength)
		{
			return 1;
		}

		int ways = 0;

		// Single digit decoding: check if current digit is not '0'.
		if (digits[index] != '0')
		{
			ways = this->CountWaysRecursiveHelper(digits, index + 1);
		}

		// Two digit decoding: check if next two digits are valid.
		if ((index + 1 < digitsLength) && ((digits[index] == '1' && digits[index + 1] <= '9') || (digits[index] == '2' && digits[index + 1] <= '6')))
		{
			ways += this->CountWaysRecursiveHelper(digits, index + 2);
		}
		return ways;
	}

	int DynamicProgramming::RecursiveCountWays(string digits)
	{
		return this->CountWaysRecursiveHelper(digits, 0);
	}

	int DynamicProgramming::DpCountways(string digits)
	{
		size_t digitsLength = digits.size();

		vector<int> dp(digitsLength + 1, 0);

		dp[digitsLength] = 1;

		for (int index = digitsLength - 1; index >= 0; index--)
		{
			// Single digit decoding: check if current digit is not '0'.
			if (digits[index] != '0')
			{
				dp[index] = dp[index + 1];
			}

			// Two digit decoding: check if next two digits are valid.
			if ((index + 1 < digitsLength) && ((digits[index] == '1' && digits[index + 1] <= '9') || (digits[index] == '2' && digits[index + 1] <= '6')))
			{
				dp[index] += dp[index + 2];
			}
		}

		return dp[0];
	}
}