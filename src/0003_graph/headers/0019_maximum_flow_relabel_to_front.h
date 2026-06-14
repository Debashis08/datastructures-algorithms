#pragma once

#include <vector>
#include <list>
using namespace std;

namespace maximum_flow_relabel_to_front
{
	class Graph
	{
	private:
		int _noOfVertices;
		int _source;
		int _sink;
		int _maximumFlow;
		vector<vector<int>> _adjMatrix;
		vector<vector<int>> _residualGraph;
		vector<int> _excessFlow;
		vector<int> _height;
		vector<bool> _visited;
		list<int> _nodeList;
		void _initializePreflow();
		void _discharge(int nodeU);
		void _push(int nodeU, int nodeV);
		void _relabel(int nodeU);
	public:
		void createGraph(int noOfVertices);
		void pushDirectedEdge(int valueU, int valueV, int capacity);
		int findMaximumFlowRelabelToFront();
	};
}