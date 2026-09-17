#include "./headers/0004_segment_tree.h"

namespace dsa::segment_tree
{
	Node* SegmentTree::buildSegmentTree(vector<int>& data, int start, int end)
	{
		Node* node = new Node(start, end);

		if (start == end)
		{
			node->sum = data[start];
			return node;
		}

		int mid = start + (end - start) / 2;
		node->left = buildSegmentTree(data, start, mid);
		node->right = buildSegmentTree(data, mid + 1, end);
		node->sum = node->left->sum + node->right->sum;
		return node;
	}

	SegmentTree::SegmentTree(vector<int>& data) : sizeOfTheVector(data.size())
	{
		buildSegmentTree(data, 0, sizeOfTheVector - 1);
	}
}