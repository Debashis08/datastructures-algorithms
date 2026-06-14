#pragma once

#include <map>
#include <vector>
#include <list>
using namespace std;

namespace dsa::directed_acyclic_graph_shortest_path
{
	enum color {WHITE, GRAY, BLACK};

	class Node
	{
	public:
		int data;
		int color;
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
		map<Node*, vector<Edge*>> _edgeMap;
		list<Node*> _topologicalSortedNodeList;
		Node* _makeOrFindNode(int data);
		void _depthFirstSearch(Node* node);
		void _topologicalSort();
		void _initializeSingleSource(Node* sourceNode);
		void _relax(Edge* edge);
		void _getShortestPath(Node* node, vector<int>& path);


	public:
		void pushDirectedEdge(int valueU, int valueV, int weight);
		void findDAGShortestPath(int data);
		vector<int> getDAGShortestPath(int data);
	};
}