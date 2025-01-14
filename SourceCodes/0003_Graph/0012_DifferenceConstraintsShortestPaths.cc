#include"../Headers/0003_Graph/0012_DifferenceConstraintsShortestPaths.h"
#include<climits>
using namespace std;

namespace DifferenceConstraintsShortestPaths
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

	// Graph Private Member Methods
	Node* Graph::MakeOrFindNode(string data)
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

	void Graph::PushDirectedEdge(string dataU, string dataV, int weight)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_edgeList.push_back(new Edge(nodeU, nodeV, weight));
	}

	void Graph::InitializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
		}
		sourceNode->distance = 0;
	}

	void Graph::Relax(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
		}
	}

	// Graph Public Member Methods
	void Graph::PushAllDirectedEdges(vector<vector<int>> vectorA, vector<string> vectorX, vector<int> vectorB)
	{
		// Creating the Actual Graph
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
			this->PushDirectedEdge(valueU, valueV, weight);
		}

		// Creating all the edges from the additional vertex
		valueU = "";
		valueV = "";
		weight = 0;
		for (int i = 0; i < vectorX.size(); i++)
		{
			valueV = vectorX[i];
			this->PushDirectedEdge(valueU, valueV, weight);
		}
	}

	bool Graph::FindDifferenceConstraintsSolutionBellmanFord()
	{
		Node* source = this->_nodeMap[""];

		this->InitializeSingleSource(source);

		for (int i = 0; i < this->_nodeMap.size(); i++)
		{
			for (auto& edge : this->_edgeList)
			{
				this->Relax(edge);
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

	vector<pair<string, int>> Graph::GetDifferenceConstrtaintsSolution()
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