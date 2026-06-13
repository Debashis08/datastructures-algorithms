#pragma once
#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
print the n'th tribonacci number.

*/

namespace tribonacci_number
{
	class DynamicProgramming
	{
	private:
	public:
		int recursiveNthTribonacci(int n);
		int dpNthTribonacci(int n);
	};
}