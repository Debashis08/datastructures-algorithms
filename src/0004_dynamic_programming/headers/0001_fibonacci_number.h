#pragma once
#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
print the n'th fibonacci number.

*/

namespace dsa::fibonacci_number
{
	class DynamicProgramming
	{
	private:
	public:
		int recursiveNthFibonacci(int n);
		int dpNthFibonacci(int n);
	};
}