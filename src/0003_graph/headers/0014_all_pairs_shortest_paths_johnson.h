#pragma once

#include <map>
#include <vector>
#include <set>
using namespace std;

namespace dsa::all_pairs_shortest_paths_johnson
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
		Node* _makeOrFindNode(int data);
		void _pushAugmentedDirectedEdges(Node* sourceNode, Node* nodeV, int weight);
		void _initializeSingleSource(Node* sourceNode);
		void _relaxBellmanFord(Edge* edge);
		bool _bellmanFord(Node* source);
		void _relaxDijkstra(Edge* edge);
		void _dijkstra(Node* source);
		void _getShortestPath(int source, int destination, vector<int>& path);

	public:
		void pushDirectedEdge(int dataU, int dataV, int weight);
		bool findAllPairsShortestPathsJohnsonAlgorithm();
		vector<vector<int>> getAllPairsShortestPathsDistanceMatrix();
		vector<vector<int>> getAllPairsShortestPathsPathMatrix();
	};
}