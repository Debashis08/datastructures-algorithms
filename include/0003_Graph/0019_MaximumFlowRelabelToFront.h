#pragma once

#include<vector>
#include<list>
using namespace std;

namespace MaximumFlowRelabelToFront
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
		void InitializePreflow();
		void Discharge(int nodeU);
		void Push(int nodeU, int nodeV);
		void Relabel(int nodeU);
	public:
		void CreateGraph(int noOfVertices);
		void PushDirectedEdge(int valueU, int valueV, int capacity);
		int FindMaximumFlowRelabelToFront();
	};
}