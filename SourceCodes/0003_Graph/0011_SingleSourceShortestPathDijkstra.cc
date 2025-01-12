#include "../Headers/0003_Graph/0011_SingleSourceShortestPathDijkstra.h"
#include<climits>
using namespace std;

namespace SingleSourceShortestPathDijkstra
{
	Node::Node(int data)
	{
		this->data = data;
		this->distance = INT_MAX;
		this->parent = nullptr;
	}

	Edge::Edge(Node* nodeU, Node* nodeV, int weight)
	{
		this->nodeU = nodeU;
		this->nodeV = nodeV;
		this->weight = weight;
	}

	// Graph Private Member Methods
	Node* Graph::MakeOrFindNode(int data)
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

	void Graph::InitializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
			iterator.second->parent = nullptr;
		}
		sourceNode->distance = 0;
	}

	void Graph::Relax(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			this->_operationalSet.erase(edge->nodeV);
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
			this->_operationalSet.insert(edge->nodeV);
		}
	}

	void Graph::Dijkstra(Node* source)
	{
		this->InitializeSingleSource(source);

		for (auto& node : this->_nodeMap)
		{
			this->_operationalSet.insert(node.second);
		}

		while (!this->_operationalSet.empty())
		{
			Node* nodeU = *(this->_operationalSet.begin());
			this->_operationalSet.erase(nodeU);

			for (auto& edge : this->_edgeMap[nodeU])
			{
				this->Relax(edge);
			}
		}
	}

	void Graph::GetShortestPath(Node* node, vector<int>& path)
	{
		path.push_back(node->data);
		if (node->parent != nullptr)
		{
			this->GetShortestPath(node->parent, path);
		}
	}

	// Graph Public Member Methods
	void Graph::PushDirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_edgeMap[nodeU].push_back(new Edge(nodeU, nodeV, weight));
	}
	
	void Graph::FindShortestPathDijkstra(int data)
	{
		Node* source = this->_nodeMap[data];
		this->Dijkstra(source);
	}

	vector<int> Graph::GetDijkstraShortestPath(int data)
	{
		vector<int> path = {};
		Node* node = this->_nodeMap[data];
		this->GetShortestPath(node, path);
		reverse(path.begin(), path.end());
		return path;
	}
}