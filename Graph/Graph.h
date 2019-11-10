//
// Created by Илья on 031 31.10.19.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H

#include "Node.h"
#include <queue>
using std::cin;
using std::cout;
using std::queue;

struct edge{
    int n1;
    int n2;
    int weight;
};

class Graph {
public:
    int Count;
    vector<int> *Adj;
    Graph(int);
    void FillGraph();
    int FindDFS(int);
    int FindBFS(int);
    static void FindMinWay(int, vector<int>&, vector<vector<int>>&);
    static void Kruskal(vector<edge>&, vector<edge>&, const int);
    static void Prim(int , vector<vector<std::pair<int, int>>>&);
private:
    static int _Min(vector<bool>&, vector<int>&);
    int DFS(int, int, vector<bool>&);

};

#endif //DATA_STRUCTURES_GRAPH_H
