#pragma once

#include<map>
#include<vector>
using namespace std;

namespace MaximumBipartiteMatching
{
	enum Color
	{
		WHITE = -1,
		RED = 0,
		BLUE = 1
	};

	class Graph
	{
	private:
		int _noOfVertices;
		int _source;
		int _sink;
		int _maximumFlow;
		bool _flagParallelEdges;
		bool _isBipartite;
		vector<vector<int>> _adjMatrix;
		vector<vector<int>> _residualGraph;
		vector<int> _parent;
		vector<bool> _visited;
		vector<int> _color;
		vector<vector<int>> _matchings;
		void ResolveAntiParallelEdges();
		void ColorGraph();
		void AddAdditionalEdges();
		bool BreadthFirstSearch();
	public:
		void CreateGraph(int noOfVertices);
		void PushDirectedEdge(int valueU, int valueV);
		int FindMaximumBipartiteMatching();
		vector<vector<int>> GetMatchings();
	};
}