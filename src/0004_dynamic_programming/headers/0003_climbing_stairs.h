#pragma once
#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
there are n stairs, and a person standing at the bottom wants to climb stairs to reach the top.
the person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways that a person can reach at the top.

*/

namespace dsa::climbing_stairs
{
	class DynamicProgramming
	{
	private:
	public:
		int recursiveCountWays(int n);
		int dpCountWays(int n);
	};
}