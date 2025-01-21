#pragma once

#include<vector>
using namespace std;

namespace AllPairsShortestPathsFloydWarshall
{
	class Graph
	{
	private:
		int  _noOfVertices;
		vector<vector<int>> _adjMatrix;
		vector<vector<int>> _shortestPathMatrixFloydWarshall;
		vector<vector<int>> _predecessorMatrix;
		void InitializeDistanceAndPredecessors();
		void GetShortestPath(int source, int destination, vector<int>& path);
		
	public:
		void CreateGraph(int noOfVertices);
		void PushDirectedEdge(int valueU, int valueV, int weight);
		void FindAllPairsShortestPathsFloydWarshallSolution();
		vector<vector<int>> GetFloydWarshallShortestPath();
	};
}