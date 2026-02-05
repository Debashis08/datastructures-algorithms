#include <0003_Graph/0013_AllPairsShortestPathsFloydWarshall.h>
#include <climits>
using namespace std;

namespace AllPairsShortestPathsFloydWarshall
{
	// Graph Private Member Methods
	void Graph::InitializeDistanceAndPredecessors()
	{
		this->_shortestPathMatrixFloydWarshall = this->_adjMatrix;

		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if ((i == j) || this->_adjMatrix[i][j] == INT_MAX)
				{
					this->_predecessorMatrix[i][j] = -1;
				}
				else
				{
					this->_predecessorMatrix[i][j] = i + 1;
				}
			}
		}
	}

	void Graph::GetShortestPath(int source, int destination, vector<int>& path)
	{
		if (this->_predecessorMatrix[source - 1][destination - 1] != source)
		{
			int predecessor = this->_predecessorMatrix[source - 1][destination - 1];
			this->GetShortestPath(source, predecessor, path);
			path.push_back(predecessor);
		}
	}

	// Graph Public Member Methods
	void Graph::CreateGraph(int noOfVertices)
	{
		this->_noOfVertices = noOfVertices;
		this->_adjMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, INT_MAX));
		this->_shortestPathMatrixFloydWarshall = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, INT_MAX));
		this->_predecessorMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, INT_MAX));

		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (i == j)
				{
					this->_adjMatrix[i][j] = 0;
				}
			}
		}
	}

	void Graph::PushDirectedEdge(int valueU, int valueV, int weight)
	{
		this->_adjMatrix[valueU - 1][valueV - 1] = weight;
	}

	void Graph::FindAllPairsShortestPathsFloydWarshallSolution()
	{
		this->InitializeDistanceAndPredecessors();

		for (int k = 0; k < this->_noOfVertices; k++)
		{
			for (int i = 0; i < this->_noOfVertices; i++)
			{
				for (int j = 0; j < this->_noOfVertices; j++)
				{
					if ((this->_shortestPathMatrixFloydWarshall[i][j] > (this->_shortestPathMatrixFloydWarshall[i][k] + this->_shortestPathMatrixFloydWarshall[k][j])) 
						&& 
						(this->_shortestPathMatrixFloydWarshall[i][k] != INT_MAX && this->_shortestPathMatrixFloydWarshall[k][j] != INT_MAX))
					{
						this->_shortestPathMatrixFloydWarshall[i][j] = this->_shortestPathMatrixFloydWarshall[i][k] + this->_shortestPathMatrixFloydWarshall[k][j];
						this->_predecessorMatrix[i][j] = this->_predecessorMatrix[k][j];
					}
				}
			}
		}
	}

	vector<vector<int>> Graph::GetFloydWarshallShortestPath()
	{
		vector<vector<int>> result;
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (i != j)
				{
					vector<int> path = {};
					path.push_back(i + 1);
					this->GetShortestPath(i + 1, j + 1, path);
					path.push_back(j + 1);
					result.push_back(path);
				}
			}
		}
		return result;
	}
}