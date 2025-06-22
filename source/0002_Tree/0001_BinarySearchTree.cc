#include "../include/0002_Tree/0001_BinarySearchTree.h"
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


	void BinarySearchTree::InsertBinarySearchTreeNode(Node* node)
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

	Node* BinarySearchTree::FindBinarySearchTreeNode(int value)
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

	Node* BinarySearchTree::FindBinarySearchTreeMinimumValueNode(Node* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}

	Node* BinarySearchTree::FindBinarySearchTreeMaximumValueNode(Node* node)
	{
		while (node->right != nullptr)
		{
			node = node->right;
		}
		return node;
	}

	Node* BinarySearchTree::FindSuccessorBinarySearchTreeNode(Node* node)
	{
		if (node->right != nullptr)
		{
			return this->FindBinarySearchTreeMinimumValueNode(node->right);
		}
		Node* nodeY = node->parent;
		while (nodeY != nullptr && node == nodeY->right)
		{
			node = nodeY;
			nodeY = nodeY->parent;
		}
		return nodeY;
	}

	Node* BinarySearchTree::FindPredecessorBinarySearchTreeNode(Node* node)
	{
		if (node->left != nullptr)
		{
			return this->FindBinarySearchTreeMaximumValueNode(node->left);
		}
		Node* nodeY = node->parent;
		while (nodeY != nullptr && node == nodeY->left)
		{
			node = nodeY;
			nodeY = nodeY->parent;
		}
		return nodeY;
	}

	void BinarySearchTree::TransplantBinarySearchTreeNode(Node* nodeU, Node* nodeV)
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

	void BinarySearchTree::DeleteBinarySearchTreeNode(Node* node)
	{
		if (node->left == nullptr)
		{
			this->TransplantBinarySearchTreeNode(node, node->right);
		}
		else if (node->right == nullptr)
		{
			this->TransplantBinarySearchTreeNode(node, node->left);
		}
		else
		{
			Node* nodeY = this->FindBinarySearchTreeMinimumValueNode(node->right);
			if (nodeY->parent != node)
			{
				this->TransplantBinarySearchTreeNode(nodeY, nodeY->right);
				nodeY->right = node->right;
				nodeY->right->parent = nodeY;
			}
			this->TransplantBinarySearchTreeNode(node, nodeY);
			nodeY->left = node->left;
			nodeY->left->parent = nodeY;
			delete node;
		}
	}

	void BinarySearchTree::RecursiveInorderTraversal(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		this->RecursiveInorderTraversal(node->left, result);
		result.push_back(node->data);
		this->RecursiveInorderTraversal(node->right, result);
	}

	void BinarySearchTree::RecursivePreorderTraversal(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		result.push_back(node->data);
		this->RecursivePreorderTraversal(node->left, result);
		this->RecursivePreorderTraversal(node->right, result);
	}

	void BinarySearchTree::RecursivePostorderTraversal(Node* node, vector<int>& result)
	{
		if (node == nullptr)
		{
			return;
		}
		this->RecursivePostorderTraversal(node->left, result);
		this->RecursivePostorderTraversal(node->right, result);
		result.push_back(node->data);
	}

	void BinarySearchTree::MorrisInorderTraversal(Node* node, vector<int>& result)
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

	void BinarySearchTree::MorrisPreorderTraversal(Node* node, vector<int>& result)
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

	void BinarySearchTree::MorrisPostorderTraversal(Node* node, vector<int>& result)
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
		this->InsertBinarySearchTreeNode(node);
	}

	void BinarySearchTree::DeleteNode(int value)
	{
		Node* node = this->FindBinarySearchTreeNode(value);
		this->DeleteBinarySearchTreeNode(node);
	}

	vector<int> BinarySearchTree::GetRecursiveInorderTravesalResult()
	{
		vector<int> result;
		this->RecursiveInorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetRecursivePreorderTravesalResult()
	{
		vector<int> result;
		this->RecursivePreorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetRecursivePostorderTravesalResult()
	{
		vector<int> result;
		this->RecursivePostorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetMorrisInorderTraversalResult()
	{
		vector<int> result;
		this->MorrisInorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetMorrisPreorderTraversalResult()
	{
		vector<int> result;
		this->MorrisPreorderTraversal(this->_root, result);
		return result;
	}

	vector<int> BinarySearchTree::GetMorrisPostorderTraversalResult()
	{
		vector<int> result;
		this->MorrisPostorderTraversal(this->_root, result);
		return result;
	}
}