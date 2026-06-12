#pragma once

#include <map>
#include <vector>
using namespace std;

namespace SingleSourceShortestPathBellmanFord
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
		Node* MakeOrFindNode(int data);
		void InitializeSingleSource(Node* sourceNode);
		void Relax(Edge* edge);
		void GetShortestPath(Node* node, vector<int>& path);


	public:
		void PushDirectedEdge(int valueU, int valueV, int weight);
		bool FindSingleSourceShortestPathBellmanFord(int data);
		vector<int> GetShortestPathBellmanFord(int data);
	};
}