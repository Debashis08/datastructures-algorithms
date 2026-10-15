#pragma once

using namespace std;

namespace dsa::red_black_tree
{
	enum Color { WHITE, RED, BLACK };

	class Node
	{
	public:
		int data;
		bool color;
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
		void _leftRotate(Node* node);
		void _rightRotate(Node* node);
		void _insertFixUp(Node* node);
		void _insert(Node* node);
	public:
		RedBlackTree();
		void insertNode(int data);
	};
}