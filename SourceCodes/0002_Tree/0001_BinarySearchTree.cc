#include "../Headers/0002_Tree/0001_BinarySearchTree.h"
#include<iostream>
#include<algorithm>
using namespace std;

namespace BinarySearchTree
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


	void BinarySearchTree::_InsertNode(Node* node)
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

	Node* BinarySearchTree::_FindNode(int value)
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

	Node* BinarySearchTree::_FindMinimumValueNode(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}

	Node* BinarySearchTree::_FindMaximumValueNode(Node* node)
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
		return node;
	}

	Node* BinarySearchTree::_FindSuccessorNode(Node* node)
	{
		if (node->right != nullptr)
		{
			return this->_FindMinimumValueNode(node->right);
		}
		Node* nodeY = node->parent;
		while (nodeY != nullptr && node == nodeY->right)
		{
			node = nodeY;
			nodeY = nodeY->parent;
		}
		return nodeY;
	}

	Node* BinarySearchTree::_FindPredecessorNode(Node* node)
	{
		if (node->left != nullptr)
		{
			return this->_FindMaximumValueNode(node->left);
		}
		Node* nodeY = node->parent;
		while (nodeY != nullptr && node == nodeY->left)
		{
			node = nodeY;
			nodeY = nodeY->parent;
		}
		return nodeY;
	}

	void BinarySearchTree::_Transplant(Node* nodeU, Node* nodeV)
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

	void BinarySearchTree::_DeleteNode(Node* node)
	{
		if (node->left == nullptr)
		{
			this->_Transplant(node, node->right);
		}
		else if (node->right == nullptr)
		{
			this->_Transplant(node, node->left);
		}
		else
		{
			Node* nodeY = this->_FindMinimumValueNode(node->right);
			if (nodeY->parent != node)
			{
				this->_Transplant(nodeY, nodeY->right);
				nodeY->right = node->right;
				nodeY->right->parent = nodeY;
			}
			this->_Transplant(node, nodeY);
			nodeY->left = node->left;
			nodeY->left->parent = nodeY;
			delete node;
		}
	}

	void BinarySearchTree::_RecursiveInorderTraversal(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		this->_RecursiveInorderTraversal(node->left, result);
		result.push_back(node->data);
		this->_RecursiveInorderTraversal(node->right, result);
	}

	void BinarySearchTree::_RecursivePreorderTraversal(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		result.push_back(node->data);
		this->_RecursivePreorderTraversal(node->left, result);
		this->_RecursivePreorderTraversal(node->right, result);
	}

	void BinarySearchTree::_RecursivePostorderTraversal(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		this->_RecursivePostorderTraversal(node->left, result);
		this->_RecursivePostorderTraversal(node->right, result);
		result.push_back(node->data);
	}

	void BinarySearchTree::_MorrisInorderTraversal(Node* node, vector<int>& result)
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

	void BinarySearchTree::_MorrisPreorderTraversal(Node* node, vector<int>& result)
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

	void BinarySearchTree::_MorrisPostorderTraversal(Node* node, vector<int>& result)
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

	void BinarySearchTree::InsertNode(int value)
	{
		Node* node = new Node(value, nullptr, nullptr, nullptr);
		this->_InsertNode(node);
	}

	void BinarySearchTree::DeleteNode(int value)
	{
		Node* node = this->_FindNode(value);
		this->_DeleteNode(node);
	}

	vector<int> BinarySearchTree::GetRecursiveInorderTravesalResult()
	{
		vector<int> result;
		this->_RecursiveInorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetRecursivePreorderTravesalResult()
	{
		vector<int> result;
		this->_RecursivePreorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetRecursivePostorderTravesalResult()
	{
		vector<int> result;
		this->_RecursivePostorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetMorrisInorderTraversalResult()
	{
		vector<int> result;
		this->_MorrisInorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetMorrisPreorderTraversalResult()
	{
		vector<int> result;
		this->_MorrisPreorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetMorrisPostorderTraversalResult()
	{
		vector<int> result;
		this->_MorrisPostorderTraversal(this->_root, result);
		return result;
	}
}