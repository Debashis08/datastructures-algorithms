#pragma once

#include <map>
#include <vector>
#include <set>
using namespace std;

namespace AllPairsShortestPathsJohnson
{
	class Node
	{
	public:
		int data;
		int distance;
		Node* parent;
		int potentialWeight;
		Node(int data);
	};

	class Edge
	{
	public:
		Node* nodeU;
		Node* nodeV;
		int weight;
		Edge(Node* nodeU, Node* nodeV, int weight);
	};

	class CompareNodeDistance
	{
	public:
		bool operator()(const Node* nodeU, const Node* nodeV) const
		{
			return nodeU->distance < nodeV->distance;
		}
	};

	class Graph
	{
	private:
		int _noOfVertices=0;
		map<Node*, vector<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<Edge*> _edgeList;
		map<Node*, vector<Edge*>> _edgeMap;
		map<Node*, vector<Node*>> _augmentedAdjlist;
		vector<Edge*> _augmentedEdgeList;
		multiset<Node*, CompareNodeDistance> _operationalSet;
		vector<vector<int>> _shortestPathMatrix;
		vector<vector<int>> _predecessorMatrix;
		Node* MakeOrFindNode(int data);
		void PushAugmentedDirectedEdges(Node* sourceNode, Node* nodeV, int weight);
		void InitializeSingleSource(Node* sourceNode);
		void RelaxBellmanFord(Edge* edge);
		bool BellmanFord(Node* source);
		void RelaxDijkstra(Edge* edge);
		void Dijkstra(Node* source);
		void GetShortestPath(int source, int destination, vector<int>& path);

	public:
		void PushDirectedEdge(int dataU, int dataV, int weight);
		bool FindAllPairsShortestPathsJohnsonAlgorithm();
		vector<vector<int>> GetAllPairsShortestPathsDistanceMatrix();
		vector<vector<int>> GetAllPairsShortestPathsPathMatrix();
	};
}