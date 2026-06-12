#pragma once
#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
Print the n'th Tribonacci number.

*/

namespace TribonacciNumber
{
	class DynamicProgramming
	{
	private:
	public:
		int RecursiveNthTribonacci(int n);
		int DpNthTribonacci(int n);
	};
}