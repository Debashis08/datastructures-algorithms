#include "0002_avl_tree.h"

namespace dsa::avl_tree
{
	Node::Node(int data, Node* parent, Node* left, Node* right)
	{
		this->data = data;
		this->height = 1;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}

	void AvlTree::_rotate(Node* parent, Node* child)
	{
		if (parent == this->_root)
		{
			if (child == parent->left)
			{
				parent->left = child->right;
				if (child->right != nullptr)
				{
					child->right->parent = parent;
				}
				child->right = parent;
				parent->parent = child;

				this->_root = child;
				this->_root->parent = nullptr;
			}
			else
			{
				parent->right = child->left;
				if (child->left != nullptr)
				{
					child->left->parent = parent;
				}
				child->left = parent;
				parent->parent = child;

				this->_root = child;
				this->_root->parent = nullptr;
			}
		}

	}

	int AvlTree::_findChildHeightDifference(Node* node)
	{
		Node* leftChild = node->left;
		Node* rightChild = node->right;
		int heightDiff = 0;

		if (leftChild == nullptr && rightChild == nullptr)
		{
			heightDiff = 0;
		}
		else if (leftChild != nullptr && rightChild == nullptr)
		{
			heightDiff = leftChild->height;
		}
		else if (leftChild == nullptr && rightChild != nullptr)
		{
			heightDiff = rightChild->height;
		}
		else
		{
			heightDiff = abs(leftChild->height - rightChild->height);
		}

		return heightDiff;
	}

	Node* AvlTree::_findMaxHeightChild(Node* node)
	{
		Node* leftChild = node->left;
		Node* rightChild = node->right;

		if (leftChild == nullptr && rightChild == nullptr)
		{
			return nullptr;
		}
		else if (leftChild != nullptr && rightChild == nullptr)
		{
			return leftChild;
		}
		else if (leftChild == nullptr && rightChild != nullptr)
		{
			return rightChild;
		}
		else
		{
			return (leftChild->height > rightChild->height) ? leftChild : rightChild;
		}
	}

	void AvlTree::_adjustAvlTreeHeight(Node* node)
	{
		while (node != nullptr)
		{
			int h = this->_findMaxHeightChild(node)->height;
			if (h == node->height)
			{
				node->height = node->height + 1;
			}

			int heightDiff = this->_findChildHeightDifference(node);
			if (heightDiff > 1)
			{
				Node* grandParent = node;
				Node* parent = this->_findMaxHeightChild(node);
				Node* child = this->_findMaxHeightChild(parent);
				if ((parent == grandParent->left && child == parent->left) || (parent == grandParent->right && child == parent->right))
				{
					this->_rotate(grandParent, parent);
				}
				else
				{
					this->_rotate(parent, child);
					this->_rotate(grandParent, child);
				}
			}
			else
			{
				node = node->parent;
			}
		}
	}

	Node* AvlTree::_findNodeByValue(int value)
	{
		Node* node = this->_root;
		while (node != nullptr)
		{
			if (value < node->data)
			{
				node = node->left;
			}
			else if (value > node->data)
			{
				node = node->right;
			}
			else
			{
				break;
			}
		}

		return node;
	}

	Node* AvlTree::_findMinimumValueNode(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}

		return node;
	}

	void AvlTree::_transplant(Node* u, Node* v)
	{
		if (u->parent == nullptr)
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

		if (v != nullptr)
		{
			v->parent = u->parent;
		}
	}

	void AvlTree::_insert(Node* node)
	{
		Node* y = nullptr;
		Node* x = this->_root;
		while (x != nullptr)
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
		if (y == nullptr)
		{
			this->_root = node;
		}
		else if (node->data < y->data)
		{
			y->left = node;
			this->_adjustAvlTreeHeight(y);
		}
		else
		{
			y->right = node;
			this->_adjustAvlTreeHeight(y);
		}
	}

	void AvlTree::_delete(Node* node)
	{
		if (node->left == nullptr)
		{
			this->_transplant(node, node->right);
		}
		else if (node->right == nullptr)
		{
			this->_transplant(node, node->left);
		}
		else
		{
			Node* y = this->_findMinimumValueNode(node->right);
			if (y->parent != node)
			{
				this->_transplant(y, y->right);
				y->right = node->right;
				y->right->parent = y;
			}
			this->_transplant(node, y);
			y->left = node->left;
			y->left->parent = y;
			delete node;
		}
	}

	AvlTree::AvlTree()
	{
		this->_root = nullptr;
	}

	void AvlTree::insertNode(int value)
	{
		Node* node = new Node(value, nullptr, nullptr, nullptr);
		this->_insert(node);
	}

	void AvlTree::deleteNode(int value)
	{
		Node* node = this->_findNodeByValue(value);
		if (node != nullptr)
		{
			this->_delete(node);
		}
	}
}