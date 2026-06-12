#pragma once
#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
Print the n'th Fibonacci number.

*/

namespace FibonacciNumber
{
	class DynamicProgramming
	{
	private:
	public:
		int RecursiveNthFibonacci(int n);
		int DpNthFibonacci(int n);
	};
}