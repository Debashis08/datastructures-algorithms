#pragma once

#include<vector>
using namespace std;

namespace dsa::red_black_tree
{
	enum Color { WHITE, RED, BLACK };

	class Node
	{
	public:
		int data;
		Color color;
		Node* parent;
		Node* left;
		Node* right;

		Node(int data, Color color = WHITE, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr);
	};

	class RedBlackTree
	{
	private:
		Node* _root;
		Node* _nil;
		void _clearTree(Node* node);
		void _leftRotate(Node* node);
		void _rightRotate(Node* node);
		Node* _findNode(Node* node, int data);
		Node* _findMin(Node* node);
		void _insertFixUp(Node* node);
		void _insert(Node* node);
		void _transplant(Node* u, Node* v);
		void _delteFixup(Node* node);
		void _delete(Node* node);
		void _recursiveInorder(Node* node, vector<vector<int>>& result);
	public:
		RedBlackTree();
		~RedBlackTree();
		void insertNode(int data);
		void deleteNode(int data);
		vector<vector<int>> recursiveInorderTraversal();
	};
}