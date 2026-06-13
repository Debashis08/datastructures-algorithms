#include "0008_minimum_spanning_tree_prim_algorithm.h"
#include <climits>
using namespace std;


namespace minimum_spanning_tree_prim_algorithm
{
	Node::Node(int data)
	{
		this->data = data;
		this->parent = nullptr;
		this->key = INT_MAX;
		this->isInOperationalSet = false;
	}

	// Graph private member methods
	Node* Graph::makeOrFindNode(int data)
	{
		Node* node = nullptr;
		if (this->_nodeMap.find(data) == this->_nodeMap.end())
		{
			node = new Node(data);
			this->_nodeMap[data] = node;
		}
		else
		{
			node = this->_nodeMap[data];
		}
		return node;
	}

	// Graph public member methods
	void Graph::pushUndirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->makeOrFindNode(dataU);
		Node* nodeV = this->makeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back({nodeV, weight});
		this->_adjlist[nodeV].push_back({nodeU, weight});
	}

	void Graph::findMinimumSpanningTreePrimAlgorithm()
	{
		Node* root = this->_nodeMap.begin()->second;

		root->key = 0;
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->isInOperationalSet = true;
			this->_operationalSet.insert(iterator.second);
		}

		while (!this->_operationalSet.empty())
		{
			Node* nodeU = *(this->_operationalSet.begin());
			this->_operationalSet.erase(nodeU);
			nodeU->isInOperationalSet = false;

			for (auto& iterator : this->_adjlist[nodeU])
			{
				Node* nodeV = iterator.first;
				int weight = iterator.second;

				if (nodeV->isInOperationalSet && weight < nodeV->key)
				{
					this->_operationalSet.erase(nodeV);
					nodeV->key = weight;
					nodeV->parent = nodeU;
					this->_operationalSet.insert(nodeV);

				}
			}

			if (nodeU->parent != nullptr)
			{
				this->_minimumSpanningTree.push_back({ {nodeU->parent->data, nodeU->data}, nodeU->key });
			}
		}
	}

	vector<pair<pair<int, int>, int>> Graph::getMinimumSpanningTree()
	{
		return this->_minimumSpanningTree;
	}
}