#pragma once

#include <vector>
#include <string>
using namespace std;

/*
pattern 1
linear recurrence

description
let 1 maps to 'A', 2 maps to 'B', ..., 26 to 'Z'.given a digit sequence, count the number of possible decodings of the given digit sequence.

consider the input string "123".there are three valid ways to decode it :
"ABC" : the grouping is(1, 2, 3) -> 'A', 'B', 'C'
"AW" : the grouping is(1, 23) -> 'A', 'W'
"LC" : the grouping is(12, 3) -> 'L', 'C'
note : groupings that contain invalid codes(e.g., "0" by itself or numbers greater than "26") are not allowed.
for instance, the string "230" is invalid because "0" cannot stand alone, and "30" is greater than "26", so it cannot represent any letter.the task is to find the total number of valid ways to decode a given string.
*/

namespace decode_ways
{
	class DynamicProgramming
	{
	private:
		int _countWaysRecursiveHelper(string& digits, size_t index);
	public:
		int recursiveCountWays(string digits);
		int dpCountways(string digits);
	};
}