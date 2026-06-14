#pragma once

#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
given a "2 x n" board and tiles of size "2 x 1", the task is to count the number of ways to tile the given board using the 2 x 1 tiles. 
A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
*/

namespace tiling_problem
{
	class DynamicProgramming
	{
	private:
		int _numberOfWaysRecursiveHelper(int n);
	public:
		int recursiveNumberOfWays(int n);
		int dpNumberOfWays(int n);
	};
}