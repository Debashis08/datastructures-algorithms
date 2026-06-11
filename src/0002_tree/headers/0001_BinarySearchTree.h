#pragma once

#include <vector>
#include <string>
using namespace std;

namespace BinarySearchTree
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
		void InsertBinarySearchTreeNode(Node* node);
		Node* FindBinarySearchTreeNode(int value);
		Node* FindBinarySearchTreeMinimumValueNode(Node* node);
		Node* FindBinarySearchTreeMaximumValueNode(Node* node);
		Node* FindSuccessorBinarySearchTreeNode(Node* node);
		Node* FindPredecessorBinarySearchTreeNode(Node* node);
		void TransplantBinarySearchTreeNode(Node* nodeU, Node* nodeV);
		void DeleteBinarySearchTreeNode(Node* node);
		void RecursiveInorderTraversal(Node* node, vector<int>& result);
		void RecursivePreorderTraversal(Node* node, vector<int>& result);
		void RecursivePostorderTraversal(Node* node, vector<int>& result);
		void MorrisInorderTraversal(Node* node, vector<int>& result);
		void MorrisPreorderTraversal(Node* node, vector<int>& result);
		void MorrisPostorderTraversal(Node* node, vector<int>& result);
	public:
		BinarySearchTree();
		void InsertNode(int value);
		void DeleteNode(int value);
		vector<int> GetRecursiveInorderTravesalResult();
		vector<int> GetRecursivePreorderTravesalResult();
		vector<int> GetRecursivePostorderTravesalResult();
		vector<int> GetMorrisInorderTraversalResult();
		vector<int> GetMorrisPreorderTraversalResult();
		vector<int> GetMorrisPostorderTraversalResult();
	};
}