#include "0003_red_black_tree.h"

namespace dsa::red_black_tree
{
	Node::Node(int data, Color color, Node* parent, Node* left, Node* right)
	{
		this->data = data;
		this->color = color;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}

	void RedBlackTree::_leftRotate(Node* node)
	{
		Node* rightChild = node->right;
		node->right = rightChild->left;

		if (rightChild->left != this->_nil)
		{
			rightChild->left->parent = node;
		}

		rightChild->parent = node->parent;
		
		if (node->parent == this->_nil)
		{
			this->_root = rightChild;
		}
		else if (node == node->parent->left)
		{
			node->parent->left = rightChild;
		}
		else
		{
			node->parent->right = rightChild;
		}

		rightChild->left = node;
		node->parent = rightChild;
	}

	void RedBlackTree::_rightRotate(Node* node)
	{
		Node* leftChild = node->left;
		node->left = leftChild->right;

		if (leftChild->right != this->_nil)
		{
			leftChild->right->parent = node;
		}

		leftChild->parent = node->parent;
		if (node->parent == this->_nil)
		{
			this->_root = leftChild;
		}
		else if(node==node->parent->left)
		{
			node->parent->left = leftChild;
		}
		else
		{
			node->parent->right = leftChild;
		}

		leftChild->right = node;
		node->parent = leftChild;
	}

	void RedBlackTree::_insertFixUp(Node* node)
	{
		while (node->parent->color == RED)
		{
			if (node->parent == node->parent->parent->left)
			{
				Node* uncle = node->parent->parent->right;
				if (uncle->color == RED)
				{
					node->parent->color = BLACK;
					uncle->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}
				else
				{
					if (node == node->parent->right)
					{
						node = node->parent;
						this->_leftRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					this->_rightRotate(node->parent->parent);
				}
			}
			else
			{
				Node* uncle = node->parent->parent->left;
				if (uncle->color == RED)
				{
					node->parent->color = BLACK;
					uncle->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}
				else
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						this->_rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					this->_leftRotate(node->parent->parent);
				}
			}
		}

		this->_root->color = BLACK;
	}

	void RedBlackTree::_insert(Node* node)
	{
		Node* y = this->_nil;
		Node* x = this->_root;

		while (x != this->_nil)
		{
			y = x;
			if (node->data < x->data)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		node->parent = y;
		if (y == this->_nil)
		{
			this->_root = node;
		}
		else if (node->data < y->data)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}

		node->left = this->_nil;
		node->right = this->_nil;
		node->color = RED;

		this->_insertFixUp(node);
	}

	RedBlackTree::RedBlackTree()
	{
		this->_nil = new Node(-1, BLACK);
		this->_root = this->_nil;
	}

	void RedBlackTree::insertNode(int data)
	{
		Node* node = new Node(data);
		this->_insert(node);
	}
}