#pragma once

#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

namespace strongly_connected_components
{
    enum color { WHITE, GRAY, BLACK };

    class Node
    {
    public:
        int data;
        int color;
        int discoveryTime;
        int finishingTime;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        int _time;
        map<Node*, list<Node*>> _adjlistG;
        map<Node*, list<Node*>> _adjlistT;
        map<int, Node*> _nodeMap;
        list<Node*> _nodesFinishingTimeOrder;
        vector<vector<int>> _allConnectedComponents;
        Node* makeOrFindNode(int value);
        void depthFirstSearchOnGraphG(Node* dFSNode);
        void depthFirstSearchOnGraphT(Node* dFSNode, vector<int>& connectedComponents);
    public:
        void pushDirectedEdge(int valueU, int valueV);
        void pushSingleNode(int valueU);
        void dFSOnGraphG();
        void dFSOnGraphT();
        vector<vector<int>> findAllStronglyConnectedComponents();
    };
}