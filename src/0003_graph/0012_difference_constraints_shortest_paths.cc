#include "0012_difference_constraints_shortest_paths.h"
#include <climits>
using namespace std;

namespace dsa::difference_constraints_shortest_paths
{
	Node::Node(string data)
	{
		this->data = data;
		this->distance = INT_MAX;
	}

	Edge::Edge(Node* nodeU, Node* nodeV, int weight)
	{
		this->nodeU = nodeU;
		this->nodeV = nodeV;
		this->weight = weight;
	}

	// Graph private member methods
	Node* Graph::_makeOrFindNode(string data)
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

	void Graph::_pushDirectedEdge(string dataU, string dataV, int weight)
	{
		Node* nodeU = this->_makeOrFindNode(dataU);
		Node* nodeV = this->_makeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_edgeList.push_back(new Edge(nodeU, nodeV, weight));
	}

	void Graph::_initializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
		}
		sourceNode->distance = 0;
	}

	void Graph::_relax(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
		}
	}

	// Graph public member methods
	void Graph::pushAllDirectedEdges(vector<vector<int>> vectorA, vector<string> vectorX, vector<int> vectorB)
	{
		// creating the actual Graph
		string valueU = "";
		string valueV = "";
		int weight = 0;
		for (int i = 0; i < vectorA.size(); i++)
		{
			for (int j = 0; j < vectorX.size(); j++)
			{
				if (vectorA[i][j] == 1)
				{
					valueV= vectorX[j];
				}
				if (vectorA[i][j] == -1)
				{
					valueU = vectorX[j];
				}
			}
			weight = vectorB[i];
			this->_pushDirectedEdge(valueU, valueV, weight);
		}

		// creating all the edges from the additional vertex
		valueU = "";
		valueV = "";
		weight = 0;
		for (int i = 0; i < vectorX.size(); i++)
		{
			valueV = vectorX[i];
			this->_pushDirectedEdge(valueU, valueV, weight);
		}
	}

	bool Graph::findDifferenceConstraintsSolutionBellmanFord()
	{
		Node* source = this->_nodeMap[""];

		this->_initializeSingleSource(source);

		for (int i = 0; i < this->_nodeMap.size(); i++)
		{
			for (auto& edge : this->_edgeList)
			{
				this->_relax(edge);
			}
		}

		for (auto& edge : this->_edgeList)
		{
			if (edge->nodeV->distance > (edge->nodeU->distance + edge->weight))
			{
				return false;
			}
		}
		return true;
	}

	vector<pair<string, int>> Graph::getDifferenceConstrtaintsSolution()
	{
		vector<pair<string, int>> result;
		for (auto& node : this->_nodeMap)
		{
			if (node.second->data != "")
			{
				result.push_back({ node.second->data, node.second->distance });
			}
		}
		return result;
	}
}