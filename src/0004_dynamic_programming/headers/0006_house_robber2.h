#pragma once
#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.

Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

*/

namespace HouseRobber2
{
	class DynamicProgramming
	{
	private:
		int MaxLootRecursive(size_t house, vector<int>& houseValues);
		int MaxLootDp(size_t firstHouse, size_t lastHouse, vector<int>& houseValues);
	public:
		int RecursiveMaximumLoot(vector<int>& houseValues);
		int DpMaximumLoot(vector<int>& houseValues);
	};
}