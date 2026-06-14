#pragma once

#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
given a distance 'dist', count total number of ways to cover the distance with 1, 2 and 3 steps.

examples:

input: n = 3
output: 4
explanation: below are the four ways
=> 1 step + 1 step + 1 step
=> 1 step + 2 step
=> 2 step + 1 step
=> 3 step



input: n = 4
output: 7
explanation: below are the four ways
=> 1 step + 1 step + 1 step + 1 step
=> 1 step + 2 step + 1 step
=>  2 step + 1 step + 1 step
=>  1 step + 1 step + 2 step
=>  2 step + 2 step
=>  3 step + 1 step
=>  1 step + 3 step
*/

namespace dsa::ways_to_cover_distance
{
	class DynamicProgramming
	{
	private:
		int _waysToCoverDistanceRecursiveHelper(int dist);
	public:
		int recursiveWaysToCoverDistance(int dist);
		int dpWaysToCoverDistance(int dist);
	};
}