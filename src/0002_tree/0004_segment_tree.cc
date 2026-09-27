#include "./headers/0004_segment_tree.h"

namespace dsa::segment_tree
{
	Node* SegmentTree::_buildSegmentTree(vector<int>& data, int start, int end)
	{
		Node* node = new Node(start, end);

		if (start == end)
		{
			node->sum = data[start];
			return node;
		}

		int mid = start + (end - start) / 2;
		node->leftChild = _buildSegmentTree(data, start, mid);
		node->rightChild = _buildSegmentTree(data, mid + 1, end);
		node->sum = node->leftChild->sum + node->rightChild->sum;
		return node;
	}

	int SegmentTree::_queryHelper(const Node* node, int left, int right) const
	{
		if (!node || node->startIndex > right || node->endIndex < left)
		{
			// Out of bounds.
			return 0;
		}

		// Total Overlap scenario.
		if (node->startIndex >= left && node->endIndex <= right)
		{
			return node->sum;
		}

		// When the range is not total overlap, propagate the query to both childs, and return the sum of those.
		return this->_queryHelper(node->leftChild, left, right) + this->_queryHelper(node->rightChild, left, right);
	}

	void SegmentTree::_updateHelper(Node* node, int targetIndex, int newValue)
	{
		if (node->startIndex == node->endIndex)
		{
			node->sum = newValue;
			return;
		}

		int mid = node->startIndex + (node->endIndex - node->startIndex) / 2;
		if (targetIndex <= mid)
		{
			this->_updateHelper(node->leftChild, targetIndex, newValue);
		}
		else
		{
			this->_updateHelper(node->rightChild, targetIndex, newValue);
		}

		node->sum = node->leftChild->sum + node->rightChild->sum;
	}

	SegmentTree::SegmentTree(vector<int>& data) : sizeOfData(data.size())
	{
		this->_root = _buildSegmentTree(data, 0, sizeOfData - 1);
	}

	int SegmentTree::query(int left, int right) const
	{
		if (this->_root == nullptr)
		{
			return 0;
		}

		return this->_queryHelper(this->_root, left, right);
	}

	void SegmentTree::update(int targetIndex, int newValue)
	{
		if (this->_root)
		{
			this->_updateHelper(this->_root, targetIndex, newValue);
		}
	}
}