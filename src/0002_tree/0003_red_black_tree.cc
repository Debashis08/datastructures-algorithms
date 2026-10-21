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

	void RedBlackTree::_clearTree(Node* node)
	{
		if (node == this->_nil)
		{
			return;
		}

		this->_clearTree(node->left);
		this->_clearTree(node->right);
		delete node;
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

	Node* RedBlackTree::_findNode(Node* node, int data)
	{
		if (node == this->_nil)
		{
			return this->_nil;
		}
		if (data < node->data)
		{
			return this->_findNode(node->left, data);
		}
		else if (data > node->data)
		{
			return this->_findNode(node->right, data);
		}
		else
		{
			return node;
		}
	}

	Node* RedBlackTree::_findMin(Node* node)
	{
		Node* ptr = this->_nil;
		while (node != this->_nil)
		{
			ptr = node;
			node = node->left;
		}

		return ptr;
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

	void RedBlackTree::_transplant(Node* u, Node* v)
	{
		if (u->parent == this->_nil)
		{
			this->_root = v;
		}
		else if (u == u->parent->left)
		{
			u->parent->left = v;
		}
		else
		{
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void RedBlackTree::_delteFixup(Node* node)
	{
		while (node != this->_root && node->color == BLACK)
		{
			if (node == node->parent->left)
			{
				Node* sibling = node->parent->right;
				if (sibling->color == RED)
				{
					sibling->color = BLACK;
					node->parent->color = RED;
					this->_leftRotate(node->parent);
					sibling = node->parent->right;
				}
				if (sibling->left->color == BLACK && sibling->right->color == BLACK)
				{
					sibling->color = RED;
					node = node->right;
				}
				else
				{
					if (sibling->right->color == BLACK)
					{
						sibling->left->color = BLACK;
						sibling->color = RED;
						this->_rightRotate(sibling);
						sibling = node->parent->right;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->right->color = BLACK;
					this->_leftRotate(node->parent);
					node = this->_root;
				}
			}
			else
			{
				Node* sibling = node->parent->left;
				if (sibling->color == RED)
				{
					sibling->color = BLACK;
					node->parent->color = RED;
					this->_rightRotate(node->parent);
					sibling = node->parent->left;
				}
				if (sibling->left->color == BLACK && sibling->right->color == BLACK)
				{
					sibling->color = RED;
					node = node->parent;
				}
				else
				{
					if (sibling->left->color == BLACK)
					{
						sibling->right->color = BLACK;
						sibling->color = RED;
						this->_leftRotate(sibling);
						sibling = node->parent->left;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->left->color = BLACK;
					this->_rightRotate(node->parent);
					node = this->_root;
				}
			}
		}

		node->color = BLACK;
	}

	void RedBlackTree::_delete(Node* node)
	{
		Node* y = node;
		Node* x;
		Color yOriginalColor = y->color;
		if (node->left == this->_nil)
		{
			x = node->right;
			this->_transplant(node, node->right);
		}
		else if (node->right == this->_nil)
		{
			x = node->left;
			this->_transplant(node, node->left);
		}
		else
		{
			y = this->_findMin(node->right);
			yOriginalColor = y->color;
			x = y->right;
			if (y->parent == node)
			{
				x->parent = node;
			}
			else
			{
				this->_transplant(y, y->right);
				y->right = node->right;
				y->right->parent = y;
			}
			this->_transplant(node, y);
			y->left = node->left;
			y->left->parent = y;
			y->color = node->color;
		}

		if (yOriginalColor == BLACK)
		{
			this->_delteFixup(x);
		}

		delete node;
	}

	void RedBlackTree::_recursiveInorder(Node* node, vector<vector<int>>& result)
	{
		if (node == nullptr)
		{
			return;
		}

		this->_recursiveInorder(node->left, result);
		result.push_back({ node->data, node->color });
		this->_recursiveInorder(node->right, result);
	}

	RedBlackTree::RedBlackTree()
	{
		this->_nil = new Node(-1, BLACK);
		this->_root = this->_nil;
	}

	RedBlackTree::~RedBlackTree()
	{
		this->_clearTree(this->_root);
		delete this->_nil;
	}

	void RedBlackTree::insertNode(int data)
	{
		Node* node = new Node(data);
		this->_insert(node);
	}
	void RedBlackTree::deleteNode(int data)
	{
		Node* node = this->_findNode(this->_root, data);
		if (node != this->_nil)
		{
			this->_delete(node);
		}
	}

	vector<vector<int>> RedBlackTree::recursiveInorderTraversal()
	{
		vector<vector<int>> result;
		this->_recursiveInorder(this->_root, result);
		return result;
	}
}