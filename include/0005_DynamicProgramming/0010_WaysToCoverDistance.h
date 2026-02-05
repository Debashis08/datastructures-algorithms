#pragma once

#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
Given a distance 'dist', count total number of ways to cover the distance with 1, 2 and 3 steps.

Examples:

Input: n = 3
Output: 4
Explanation: Below are the four ways
=> 1 step + 1 step + 1 step
=> 1 step + 2 step
=> 2 step + 1 step
=> 3 step



Input: n = 4
Output: 7
Explanation: Below are the four ways
=> 1 step + 1 step + 1 step + 1 step
=> 1 step + 2 step + 1 step
=>  2 step + 1 step + 1 step
=>  1 step + 1 step + 2 step
=>  2 step + 2 step
=>  3 step + 1 step
=>  1 step + 3 step
*/

namespace WaysToCoverDistance
{
	class DynamicProgramming
	{
	private:
		int WaysToCoverDistanceRecursiveHelper(int dist);
	public:
		int RecursiveWaysToCoverDistance(int dist);
		int DpWaysToCoverDistance(int dist);
	};
}