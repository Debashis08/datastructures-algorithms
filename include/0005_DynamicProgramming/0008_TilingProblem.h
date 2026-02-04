#pragma once

#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
Given a "2 x n" board and tiles of size "2 x 1", the task is to count the number of ways to tile the given board using the 2 x 1 tiles. 
A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
*/

namespace TilingProblem
{
	class DynamicProgramming
	{
	private:
		int NumberOfWaysRecursiveHelper(int n);
	public:
		int RecursiveNumberOfWays(int n);
		int DpNumberOfWays(int n);
	};
}