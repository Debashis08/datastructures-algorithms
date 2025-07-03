#pragma once
#include<vector>
using namespace std;

namespace RodCutting
{
	class DynamicProgramming
	{
	private:
		int _length;
		vector<int> _price;
	public:
		DynamicProgramming(int length, vector<int> price);
		int RecursiveCutRod();
	};
}