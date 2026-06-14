#pragma once
#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
you are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
determine the maximum amount the thief can steal.

note: since the houses are in a circle, the first and last houses are also considered adjacent.

*/

namespace dsa::house_robber2
{
	class DynamicProgramming
	{
	private:
		int _maxLootRecursive(size_t house, vector<int>& houseValues);
		int _maxLootDp(size_t firstHouse, size_t lastHouse, vector<int>& houseValues);
	public:
		int recursiveMaximumLoot(vector<int>& houseValues);
		int dpMaximumLoot(vector<int>& houseValues);
	};
}