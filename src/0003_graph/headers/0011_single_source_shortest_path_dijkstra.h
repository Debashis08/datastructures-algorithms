#pragma once

#include <map>
#include <vector>
#include <set>
using namespace std;

namespace single_source_shortest_path_dijkstra
{
	class Node
	{
	public:
		int data;
		int distance;
		Node* parent;
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
		map<Node*, vector<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		map<Node*, vector<Edge*>> _edgeMap;
		multiset<Node*, CompareNodeDistance> _operationalSet;
		Node* _makeOrFindNode(int data);
		void _initializeSingleSource(Node* sourceNode);
		void _relax(Edge* edge);
		void _dijkstra(Node* source);
		void _getShortestPath(Node* node, vector<int>& path);

	public:
		void pushDirectedEdge(int valueU, int valueV, int weight);
		void findShortestPathDijkstra(int data);
		vector<int> getDijkstraShortestPath(int data);
	};
}