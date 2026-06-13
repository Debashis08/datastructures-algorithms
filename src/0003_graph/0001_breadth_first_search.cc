#include "0001_breadth_first_search.h"
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <climits>
using namespace std;

namespace breadth_first_search
{
	Node::Node(int value)
	{
		this->data = value;
		this->distance = INT_MAX;
		this->color = WHITE;
		this->parent = nullptr;
	}

	Node* Graph::makeOrFindNode(int value)
	{
		Node* node = nullptr;
		if (this->_nodeMap.find(value) == this->_nodeMap.end())
		{
			node = new Node(value);
			this->_nodeMap[value] = node;
		}
		else
		{
			node = this->_nodeMap[value];
		}
		return node;
	}

	void Graph::breadthFirstSearch(Node* node)
	{
		node->color = WHITE;
		node->distance = 0;
		node->parent = nullptr;

		queue<Node*> nodeQueue;
		nodeQueue.push(node);

		while (nodeQueue.empty() != true)
		{
			Node* currentNode = nodeQueue.front();
			nodeQueue.pop();

			for (auto& adjacentNode : this->_adjlist[currentNode])
			{
				if (adjacentNode->color == WHITE)
				{
					adjacentNode->color = GRAY;
					adjacentNode->parent = currentNode;
					adjacentNode->distance = currentNode->distance + 1;
					nodeQueue.push(adjacentNode);
				}
			}
			currentNode->color = BLACK;
		}
	}

	void Graph::pushUndirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->makeOrFindNode(valueU);
		Node* nodeV = this->makeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_adjlist[nodeV].push_back(nodeU);
	}

	void Graph::BFS(int value)
	{
		this->breadthFirstSearch(this->_nodeMap[value]);
	}

	vector<pair<int, int>> Graph::showBFSResult()
	{
		vector<pair<int, int>> result;
		for (auto& node : this->_nodeMap)
		{
			result.push_back(make_pair(node.first, node.second->distance));
		}
		return result;
	}
}