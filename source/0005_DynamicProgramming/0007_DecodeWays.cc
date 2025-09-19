#include "../../include/0005_DynamicProgramming/0007_DecodeWays.h"

namespace DecodeWays
{
	int DynamicProgramming::CountWaysRecursiveHelper(string& digits, size_t index)
	{
		size_t digitsLength = digits.size();

		if (index >= digitsLength)
		{
			return 1;
		}
	}

	int DynamicProgramming::RecursiveCountWays(string digits)
	{

	}
}