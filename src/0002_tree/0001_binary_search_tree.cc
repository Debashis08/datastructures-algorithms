#include "0001_binary_search_tree.h"

namespace dsa::binary_search_tree
{
	Node::Node(int data, Node* parent, Node* left, Node* right)
	{
		this->data = data;
		this->parent = parent;
		this->left = left;
		this->right = right;
	}

	BinarySearchTree::BinarySearchTree()
	{
		this->_root = nullptr;
	}

	void BinarySearchTree::_insert(Node* node)
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
		}
		else
		{
			y->right = node;
		}
	}

	Node* BinarySearchTree::_findNodeByValue(int value)
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

	Node* BinarySearchTree::_findMinimumValueNode(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}

	Node* BinarySearchTree::_findMaximumValueNode(Node* node)
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
		return node;
	}

	Node* BinarySearchTree::_findSuccessor(Node* node)
	{
		if (node->right != nullptr)
		{
			return this->_findMinimumValueNode(node->right);
		}
		Node* y = node->parent;
		while (y != nullptr && node == y->right)
		{
			node = y;
			y = y->parent;
		}
		return y;
	}

	Node* BinarySearchTree::_findPredecessor(Node* node)
	{
		if (node->left != nullptr)
		{
			return this->_findMaximumValueNode(node->left);
		}
		Node* y = node->parent;
		while (y != nullptr && node == y->left)
		{
			node = y;
			y = y->parent;
		}
		return y;
	}

	void BinarySearchTree::_transplant(Node* u, Node* v)
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

	void BinarySearchTree::_delete(Node* node)
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

	void BinarySearchTree::_recursiveInorder(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		this->_recursiveInorder(node->left, result);
		result.push_back(node->data);
		this->_recursiveInorder(node->right, result);
	}

	void BinarySearchTree::_recursivePreorder(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		result.push_back(node->data);
		this->_recursivePreorder(node->left, result);
		this->_recursivePreorder(node->right, result);
	}

	void BinarySearchTree::_recursivePostorder(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		this->_recursivePostorder(node->left, result);
		this->_recursivePostorder(node->right, result);
		result.push_back(node->data);
	}

	void BinarySearchTree::_morrisInorder(Node* node, vector<int>& result)
	{
		while (node != nullptr)
		{
			if (node->left == nullptr)
			{
				result.push_back(node->data);
				node = node->right;
			}
			else
			{
				Node* predecessor = node->left;
				while (predecessor->right != nullptr && predecessor->right != node)
				{
					predecessor = predecessor->right;
				}
				if (predecessor->right == nullptr)
				{
					predecessor->right = node;
					node = node->left;
				}
				else
				{
					predecessor->right = nullptr;
					result.push_back(node->data);
					node = node->right;
				}
			}
		}
	}

	void BinarySearchTree::_morrisPreorder(Node* node, vector<int>& result)
	{
		while (node != nullptr)
		{
			if (node->left == nullptr)
			{
				result.push_back(node->data);
				node = node->right;
			}
			else
			{
				Node* predecessor = node->left;
				while (predecessor->right != nullptr && predecessor->right != node)
				{
					predecessor = predecessor->right;
				}
				if (predecessor->right == nullptr)
				{
					predecessor->right = node;
					result.push_back(node->data);
					node = node->left;
				}
				else
				{
					predecessor->right = nullptr;
					node = node->right;
				}
			}
		}
	}

	void BinarySearchTree::_morrisPostorder(Node* node, vector<int>& result)
	{
		while (node != nullptr)
		{
			if (node->right == nullptr)
			{
				result.push_back(node->data);
				node = node->left;
			}
			else
			{
				Node* predecessor = node->right;
				while (predecessor->left != nullptr && predecessor->left != node)
				{
					predecessor = predecessor->left;
				}
				if (predecessor->left == nullptr)
				{
					predecessor->left = node;
					result.push_back(node->data);
					node = node->right;
				}
				else
				{
					predecessor->left = nullptr;
					node = node->left;
				}
			}
		}
		reverse(result.begin(), result.end());
	}

	void BinarySearchTree::insertNode(int value)
	{
		Node* node = new Node(value, nullptr, nullptr, nullptr);
		this->_insert(node);
	}

	void BinarySearchTree::deleteNode(int value)
	{
		Node* node = this->_findNodeByValue(value);
		this->_delete(node);
	}

	vector<int> BinarySearchTree::recursiveInorderTraversal()
	{
		vector<int> result;
		this->_recursiveInorder(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::recursivePreorderTravesal()
	{
		vector<int> result;
		this->_recursivePreorder(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::recursivePostorderTravesal()
	{
		vector<int> result;
		this->_recursivePostorder(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::morrisInorderTraversal()
	{
		vector<int> result;
		this->_morrisInorder(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::morrisPreorderTraversal()
	{
		vector<int> result;
		this->_morrisPreorder(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::morrisPostorderTraversal()
	{
		vector<int> result;
		this->_morrisPostorder(this->_root, result);
		return result;
	}
}