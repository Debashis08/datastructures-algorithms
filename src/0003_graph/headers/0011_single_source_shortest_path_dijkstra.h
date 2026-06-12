#pragma once

#include <map>
#include <vector>
#include <set>
using namespace std;

namespace SingleSourceShortestPathDijkstra
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
		Node* MakeOrFindNode(int data);
		void InitializeSingleSource(Node* sourceNode);
		void Relax(Edge* edge);
		void Dijkstra(Node* source);
		void GetShortestPath(Node* node, vector<int>& path);

	public:
		void PushDirectedEdge(int valueU, int valueV, int weight);
		void FindShortestPathDijkstra(int data);
		vector<int> GetDijkstraShortestPath(int data);
	};
}