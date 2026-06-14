#pragma once

#include <map>
#include <vector>
using namespace std;

namespace dsa::maximum_bipartite_matching
{
	enum color
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
		void _resolveAntiParallelEdges();
		void _colorGraph();
		void _addAdditionalEdges();
		bool _breadthFirstSearch();
	public:
		void createGraph(int noOfVertices);
		void pushDirectedEdge(int valueU, int valueV);
		int findMaximumBipartiteMatching();
		vector<vector<int>> getMatchings();
	};
}