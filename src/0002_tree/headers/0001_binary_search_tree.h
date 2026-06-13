#pragma once

#include <vector>
#include <string>
using namespace std;

namespace binary_search_tree
{
	class Node
	{
	public:
		int data;
		Node* parent;
		Node* left;
		Node* right;

		Node(int data, Node* parent, Node* left, Node* right);
	};

	class BinarySearchTree
	{
	private:
		Node* _root;
		void _insertBSTreeNode(Node* node);
		Node* _findBSTreeNode(int value);
		Node* _findBSTreeMinNode(Node* node);
		Node* _findBSTreeMaxNode(Node* node);
		Node* _findSuccessor(Node* node);
		Node* _findPredecessor(Node* node);
		void _transplant(Node* nodeU, Node* nodeV);
		void _deleteBSTreeNode(Node* node);
		void _recursiveInorder(Node* node, vector<int>& result);
		void _recursivePreorder(Node* node, vector<int>& result);
		void _recursivePostorder(Node* node, vector<int>& result);
		void _morrisInorder(Node* node, vector<int>& result);
		void _morrisPreorder(Node* node, vector<int>& result);
		void _morrisPostorder(Node* node, vector<int>& result);
	public:
		BinarySearchTree();
		void insertNode(int value);
		void deleteNode(int value);
		vector<int> recursiveInorderTraversal();
		vector<int> recursivePreorderTravesal();
		vector<int> recursivePostorderTravesal();
		vector<int> morrisInorderTraversal();
		vector<int> morrisPreorderTraversal();
		vector<int> morrisPostorderTraversal();
	};
}