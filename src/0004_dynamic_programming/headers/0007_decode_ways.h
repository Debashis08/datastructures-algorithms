#pragma once

#include <vector>
#include <string>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
Let 1 maps to 'A', 2 maps to 'B', ..., 26 to 'Z'.Given a digit sequence, count the number of possible decodings of the given digit sequence.

Consider the input string "123".There are three valid ways to decode it :
"ABC" : The grouping is(1, 2, 3) -> 'A', 'B', 'C'
"AW" : The grouping is(1, 23) -> 'A', 'W'
"LC" : The grouping is(12, 3) -> 'L', 'C'
Note : Groupings that contain invalid codes(e.g., "0" by itself or numbers greater than "26") are not allowed.
For instance, the string "230" is invalid because "0" cannot stand alone, and "30" is greater than "26", so it cannot represent any letter.The task is to find the total number of valid ways to decode a given string.
*/

namespace DecodeWays
{
	class DynamicProgramming
	{
	private:
		int CountWaysRecursiveHelper(string& digits, size_t index);
	public:
		int RecursiveCountWays(string digits);
		int DpCountways(string digits);
	};
}