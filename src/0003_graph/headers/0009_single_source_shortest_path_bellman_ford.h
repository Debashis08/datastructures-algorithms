#pragma once

#include <map>
#include <vector>
using namespace std;

namespace dsa::single_source_shortest_path_bellman_ford
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

	class Graph
	{
	private:
		map<Node*, vector<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<Edge*> _edgeList;
		Node* _makeOrFindNode(int data);
		void _initializeSingleSource(Node* sourceNode);
		void _relax(Edge* edge);
		void _getShortestPath(Node* node, vector<int>& path);


	public:
		void pushDirectedEdge(int valueU, int valueV, int weight);
		bool findSingleSourceShortestPathBellmanFord(int data);
		vector<int> getShortestPathBellmanFord(int data);
	};
}