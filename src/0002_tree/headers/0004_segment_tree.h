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
		Node* leftChild;
		Node* rightChild;

		Node(int start, int end)
		{
			startIndex = start;
			endIndex = end;
			sum = 0;
			leftChild = nullptr;
			rightChild = nullptr;
		}
	};

	class SegmentTree
	{
	private:
		Node* _root;
		int _sizeOfData;
		Node* _buildSegmentTree(vector<int>& data, int start, int end);
		int _queryHelper(const Node* node, int left, int right) const;
		void _updateHelper(Node* node, int targetIndex, int newValue);
		
	public:
		SegmentTree(vector<int>& data);
		int query(int left, int right) const;
		void update(int targetIndex, int newValue);
	};
}