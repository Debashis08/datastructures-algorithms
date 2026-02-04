#include <0003_Graph/0014_AllPairsShortestPathsJohnson.h>
#include <climits>
using namespace std;

namespace AllPairsShortestPathsJohnson
{
	Node::Node(int data)
	{
		this->data = data;
		this->distance = INT_MAX;
		this->parent = nullptr;
		this->potentialWeight = 0;
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

	void Graph::PushAugmentedDirectedEdges(Node* sourceNode, Node* nodeV, int weight)
	{
		this->_augmentedAdjlist[sourceNode].push_back(nodeV);
		this->_augmentedEdgeList.push_back(new Edge(sourceNode, nodeV, weight));
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

	void Graph::RelaxBellmanFord(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
		}
	}

	bool Graph::BellmanFord(Node* source)
	{
		this->InitializeSingleSource(source);

		for (int i = 0; i < this->_nodeMap.size() - 1; i++)
		{
			for (auto& edge : this->_augmentedEdgeList)
			{
				this->RelaxBellmanFord(edge);
			}
		}

		for (auto& edge : this->_augmentedEdgeList)
		{
			if (edge->nodeV->distance > (edge->nodeU->distance + edge->weight))
			{
				return false;
			}
		}
		return true;
	}

	void Graph::RelaxDijkstra(Edge* edge)
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
				this->RelaxDijkstra(edge);
			}
		}
	}

	void Graph::GetShortestPath(int source, int destination, vector<int>& path)
	{
		if (this->_predecessorMatrix[source - 1][destination - 1] != source)
		{
			int predecessor = this->_predecessorMatrix[source - 1][destination - 1];
			this->GetShortestPath(source, predecessor, path);
			path.push_back(predecessor);
		}
	}

	// Graph Public Member Methods
	void Graph::PushDirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		Edge* edge = new Edge(nodeU, nodeV, weight);
		this->_edgeMap[nodeU].push_back(edge);
		this->_edgeList.push_back(edge);
	}

	bool Graph::FindAllPairsShortestPathsJohnsonAlgorithm()
	{
		// Creating the graph G'
		this->_augmentedAdjlist = this->_adjlist;
		this->_augmentedEdgeList = this->_edgeList;

		// Source Node s
		Node* source = new Node(0);
		this->_nodeMap[0] = source;

		// Creating all the augmented edges in G'.E = G.E U {(s, v) : v in G.V
		for (auto& node : this->_nodeMap)
		{
			if (node.second != source)
			{
				this->PushAugmentedDirectedEdges(source, node.second, 0);
			}
		}

		if (this->BellmanFord(source) == false)
		{
			return false;
		}
		else
		{
			this->_nodeMap.erase(0);
			for (auto& node : this->_nodeMap)
			{
				node.second->potentialWeight = node.second->distance;
			}

			for (auto& edge : this->_edgeList)
			{
				edge->weight = edge->weight + edge->nodeU->potentialWeight - edge->nodeV->potentialWeight;
			}

			this->_noOfVertices = (int)this->_nodeMap.size();
			this->_shortestPathMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, -1));
			this->_predecessorMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, -1));
			for (auto& iteratorU : this->_nodeMap)
			{
				Node* nodeU = iteratorU.second;
				this->Dijkstra(nodeU);
				for (auto& iteratorV : this->_nodeMap)
				{
					Node* nodeV = iteratorV.second;
					this->_shortestPathMatrix[nodeU->data - 1][nodeV->data - 1] = nodeV->distance + nodeV->potentialWeight - nodeU->potentialWeight;
					this->_predecessorMatrix[nodeU->data - 1][nodeV->data - 1] = nodeV->parent != nullptr ? nodeV->parent->data : -1;
				}
			}
			return true;
		}
	}

	vector<vector<int>> Graph::GetAllPairsShortestPathsDistanceMatrix()
	{
		return this->_shortestPathMatrix;
	}

	vector<vector<int>> Graph::GetAllPairsShortestPathsPathMatrix()
	{
		vector<vector<int>> result;
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (i != j)
				{
					vector<int> path = {};
					path.push_back(i + 1);
					this->GetShortestPath(i + 1, j + 1, path);
					path.push_back(j + 1);
					result.push_back(path);
				}
			}
		}
		return result;
	}
}