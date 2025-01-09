#pragma once

#include<map>
#include<vector>
#include<list>
using namespace std;

namespace DirectedAcyclicGraphShortestPath
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
		Node* MakeOrFindNode(int data);
		void DepthFirstSearch(Node* node);
		void TopologicalSort();
		void InitializeSingleSource(Node* sourceNode);
		void Relax(Edge* edge);
		void GetShortestPath(Node* node, vector<int>& path);


	public:
		void PushDirectedEdge(int valueU, int valueV, int weight);
		void FindDAGShortestPath(int data);
		vector<int> GetDAGShortestPath(int data);
	};
}