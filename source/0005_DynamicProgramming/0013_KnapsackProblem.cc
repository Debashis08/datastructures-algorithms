#include "../../include/0005_DynamicProgramming/0013_KnapsackProblem.h"

namespace KnapsackProblem
{
	// Dynamic Programming Private Member Methods.
	int DynamicProgramming::KnapsackRecursiveHelper(int capacity, vector<int>& weight, vector<int>& profit, int numberOfItems)
	{
		if (capacity <= 0 || numberOfItems == 0)
		{
			return 0;
		}
		
		int pickCurrentItem = 0;
		
		// Pick the current item only if does not exceed the capacity.
		if (weight[numberOfItems - 1] <= capacity)
		{
			pickCurrentItem = profit[numberOfItems - 1] + this->KnapsackRecursiveHelper(capacity - weight[numberOfItems - 1], weight, profit, numberOfItems - 1);
		}

		int dropCurrentItem = this->KnapsackRecursiveHelper(capacity, weight, profit, numberOfItems - 1);

		return max(pickCurrentItem, dropCurrentItem);
	}

	// Dynamic Programming Public Member Methods.
	int DynamicProgramming::RecursiveKnapsack(int capacity, vector<int> weight, vector<int> profit)
	{
		size_t totalNumberOfItems = weight.size();
		return this->KnapsackRecursiveHelper(capacity, weight, profit, totalNumberOfItems);
	}
}