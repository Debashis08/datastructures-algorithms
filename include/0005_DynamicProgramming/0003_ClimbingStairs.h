#pragma once
#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
There are n stairs, and a person standing at the bottom wants to climb stairs to reach the top.
The person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways that a person can reach at the top.

*/

namespace ClimbingStairs
{
	class DynamicProgramming
	{
	private:
	public:
		int RecursiveCountWays(int n);
		int DpCountWays(int n);
	};
}