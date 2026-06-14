#include "0001_binary_search_tree.h"
#include <iostream>
#include <algorithm>
using namespace std;

namespace binary_search_tree
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
		Node* nodeY = nullptr;
		Node* nodeX = this->_root;
		while (nodeX != nullptr)
		{
			nodeY = nodeX;
			if (node->data < nodeX->data)
			{
				nodeX = nodeX->left;
			}
			else
			{
				nodeX = nodeX->right;
			}
		}
		node->parent = nodeY;
		if (nodeY == nullptr)
		{
			this->_root = node;
		}
		else if (node->data < nodeY->data)
		{
			nodeY->left = node;
		}
		else
		{
			nodeY->right = node;
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
		Node* nodeY = node->parent;
		while (nodeY != nullptr && node == nodeY->right)
		{
			node = nodeY;
			nodeY = nodeY->parent;
		}
		return nodeY;
	}

	Node* BinarySearchTree::_findPredecessor(Node* node)
	{
		if (node->left != nullptr)
		{
			return this->_findMaximumValueNode(node->left);
		}
		Node* nodeY = node->parent;
		while (nodeY != nullptr && node == nodeY->left)
		{
			node = nodeY;
			nodeY = nodeY->parent;
		}
		return nodeY;
	}

	void BinarySearchTree::_transplant(Node* nodeU, Node* nodeV)
	{
		if (nodeU->parent == nullptr)
		{
			this->_root = nodeV;
		}
		else if (nodeU == nodeU->parent->left)
		{
			nodeU->parent->left = nodeV;
		}
		else
		{
			nodeU->parent->right = nodeV;
		}

		if (nodeV != nullptr)
		{
			nodeV->parent = nodeU->parent;
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
			Node* nodeY = this->_findMinimumValueNode(node->right);
			if (nodeY->parent != node)
			{
				this->_transplant(nodeY, nodeY->right);
				nodeY->right = node->right;
				nodeY->right->parent = nodeY;
			}
			this->_transplant(node, nodeY);
			nodeY->left = node->left;
			nodeY->left->parent = nodeY;
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