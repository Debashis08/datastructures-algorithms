#pragma once

#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

namespace dsa::avl_tree
{
	class Node
	{
	public:
		int data;
		int height;
		Node* parent;
		Node* left;
		Node* right;
		
		Node(int data, Node* parent, Node* left, Node* right);
	};

	class AvlTree
	{
	private:
		Node* _root;
		void _rotate(Node* parent, Node* child);
		int _findChildHeightDifference(Node* node);
		Node* _findMaxHeightChild(Node* node);
		void _adjustAvlTreeHeight(Node* node);
		Node* _findNodeByValue(int value);
		Node* _findMinimumValueNode(Node* node);
		void _transplant(Node* u, Node* v);
		void _insert(Node* node);
		void _delete(Node* node);
		void _recursiveInorder(Node* node, vector<vector<int>>& result);
	public:
		AvlTree();
		void insertNode(int value);
		void deleteNode(int value);
		vector<vector<int>> recursiveInorderTraversal();
	};
}