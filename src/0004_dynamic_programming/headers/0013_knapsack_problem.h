#pragma once

#include <vector>
using namespace std;

/*
pattern 2
subset / 0-1 knapsack

description
given n items where each item has some weight and profit associated with it and also given a bag with capacity W, [i.e., the bag can hold at most W weight in it]. the task is to put the items into the bag such that the sum of profits associated with them is the maximum possible.

note: the constraint here is we can either put an item completely into the bag or cannot put it at all [it is not possible to put a part of an item into the bag].

input:  W = 4, profit[] = [1, 2, 3], weight[] = [4, 5, 1]
output: 3
explanation: there are two items which have weight less than or equal to 4. if we select the item with weight 4, the possible profit is 1. and if we select the item with weight 1, the possible profit is 3. so the maximum possible profit is 3. note that we cannot put both the items with weight 4 and 1 together as the capacity of the bag is 4.

input: W = 3, profit[] = [1, 2, 3], weight[] = [4, 5, 6]
output: 0
*/

namespace knapsack_problem
{
	class DynamicProgramming
	{
	private:
		int knapsackRecursiveHelper(int capacity, vector<int>& weight, vector<int>& profit, int numberOfItems);
	public:
		int recursiveKnapsack(int capacity, vector<int> weight, vector<int> profit);
		int dpKnapsack(int capacity, vector<int> weight, vector<int> profit);
		int dpKnapsackSpaceOptimized(int capacity, vector<int> weight, vector<int> profit);
	};
}