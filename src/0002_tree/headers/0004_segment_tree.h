#pragma once

#include<vector>
using namespace std;

namespace dsa::segment_tree
{
	class Node
	{
	public:
		int startIndex;
		int endIndex;
		int sum;
		Node* left;
		Node* right;

		Node(int start, int end)
		{
			startIndex = start;
			endIndex = end;
			sum = 0;
			left = nullptr;
			right = nullptr;
		}
	};

	class SegmentTree
	{
	private:
		Node* _root;
		int sizeOfTheVector;
		Node* buildSegmentTree(vector<int>& data, int start, int end);
		int queryHelper(const Node* node, int leftQuery, int rightQuery) const;
		
	public:
		SegmentTree(vector<int>& data);
		int query(int leftQuery, int rightQuery) const;
	};
}