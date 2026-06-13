#pragma once

#include <map>
#include <vector>
#include <set>
using namespace std;

namespace all_pairs_shortest_paths_johnson
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
		Node* makeOrFindNode(int data);
		void pushAugmentedDirectedEdges(Node* sourceNode, Node* nodeV, int weight);
		void initializeSingleSource(Node* sourceNode);
		void relaxBellmanFord(Edge* edge);
		bool bellmanFord(Node* source);
		void relaxDijkstra(Edge* edge);
		void dijkstra(Node* source);
		void getShortestPath(int source, int destination, vector<int>& path);

	public:
		void pushDirectedEdge(int dataU, int dataV, int weight);
		bool findAllPairsShortestPathsJohnsonAlgorithm();
		vector<vector<int>> getAllPairsShortestPathsDistanceMatrix();
		vector<vector<int>> getAllPairsShortestPathsPathMatrix();
	};
}