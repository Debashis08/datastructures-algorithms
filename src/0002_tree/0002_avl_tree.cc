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
		Node* grandParent = parent->parent;

		if (child == parent->left)
		{
			// Right rotation
			parent->left = child->right;
			if (child->right != nullptr)
			{
				child->right->parent = parent;
			}
			child->right = parent;
			parent->parent = child;
		}
		else
		{
			// Left rotation
			parent->right = child->left;
			if (child->left != nullptr)
			{
				child->left->parent = parent;
			}
			child->left = parent;
			parent->parent = child;
		}

		// Update grandparent / root connection
		child->parent = grandParent;
		if (grandParent == nullptr)
		{
			this->_root = child;
		}
		else if (parent == grandParent->left)
		{
			grandParent->left = child;
		}
		else
		{
			grandParent->right = child;
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
			int leftHeight = (node->left != nullptr) ? node->left->height : 0;
			int rightHeight = (node->right != nullptr) ? node->right->height : 0;
			node->height = 1 + max(leftHeight, rightHeight);

			int heightDiff = this->_findChildHeightDifference(node);
			if (heightDiff > 1)
			{
				Node* grandParent = node;
				Node* parent = this->_findMaxHeightChild(node);
				Node* child = this->_findMaxHeightChild(parent);
				if ((parent == grandParent->left && child == parent->left)
					||
					(parent == grandParent->right && child == parent->right))
				{
					this->_rotate(grandParent, parent);

					int pLeftHeight = (parent->left != nullptr) ? parent->left->height : 0;
					int pRightHeight = (parent->right != nullptr) ? parent->right->height : 0;
					parent->height = 1 + max(pLeftHeight, pRightHeight);

					int gpLeftHeight = (grandParent->left != nullptr) ? grandParent->left->height : 0;
					int gpRightHeight = (grandParent->right != nullptr) ? grandParent->right->height : 0;
					grandParent->height = 1 + max(gpLeftHeight, gpRightHeight);

					// Continue upward from the new subtree root
					node = node->parent;
				}
				else
				{
					this->_rotate(parent, child);
					this->_rotate(grandParent, child);

					int pLeftHeight = (parent->left != nullptr) ? parent->left->height : 0;
					int pRightHeight = (parent->right != nullptr) ? parent->right->height : 0;
					parent->height = 1 + max(pLeftHeight, pRightHeight);

					int gpLeftHeight = (grandParent->left != nullptr) ? grandParent->left->height : 0;
					int gpRightHeight = (grandParent->right != nullptr) ? grandParent->right->height : 0;
					grandParent->height = 1 + max(gpLeftHeight, gpRightHeight);

					int cLeftHeight = (child->left != nullptr) ? child->left->height : 0;
					int cRightHeight = (child->right != nullptr) ? child->right->height : 0;
					child->height = 1 + max(cLeftHeight, cRightHeight);

					// Continue upward from the new subtree root
					node = child->parent;
				}
			}
			else
			{
				// Continue upward from the new subtree root
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
		Node* balanceStartNode = nullptr;
		if (node->left == nullptr)
		{
			balanceStartNode = node->parent;
			this->_transplant(node, node->right);
			delete node;
		}
		else if (node->right == nullptr)
		{
			balanceStartNode = node->parent;
			this->_transplant(node, node->left);
			delete node;
		}
		else
		{
			Node* y = this->_findMinimumValueNode(node->right);
			if (y->parent != node)
			{
				balanceStartNode = y->parent;
				this->_transplant(y, y->right);
				y->right = node->right;
				y->right->parent = y;
			}
			else
			{
				balanceStartNode = y;
			}

			this->_transplant(node, y);
			y->left = node->left;
			y->left->parent = y;
			delete node;
		}

		// Trigger height adjustment and rebalancing upward from balanceStartNode
		if (balanceStartNode != nullptr)
		{
			this->_adjustAvlTreeHeight(balanceStartNode);
		}
	}

	void AvlTree::_recursiveInorder(Node* node, vector<vector<int>>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		
		this->_recursiveInorder(node->left, result);
		result.push_back({node->data, node->height});
		this->_recursiveInorder(node->right, result);
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
	vector<vector<int>> AvlTree::recursiveInorderTraversal()
	{
		vector<vector<int>> result;
		this->_recursiveInorder(this->_root, result);
		return result;
	}
}