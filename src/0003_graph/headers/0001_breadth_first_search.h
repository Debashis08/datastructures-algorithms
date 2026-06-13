#pragma once

#include <list>
#include <map>
#include <utility>
#include <string>
#include <vector>
using namespace std;

namespace breadth_first_search
{
    enum color { WHITE, GRAY, BLACK };
    class Node
    {
    public:
        int data;
        int distance;
        int color;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        map<Node*, list<Node*>> _adjlist;
        map<int, Node*> _nodeMap;
        Node* makeOrFindNode(int value);
        void breadthFirstSearch(Node* node);
    public:
        void pushUndirectedEdge(int valueU, int valueV);
        void bfs(int value);
        vector<pair<int, int>> showBFSResult();
    };
}