//
// Created by Илья on 003 03.11.19.
//
#include <algorithm>
#include "Graph.h"
#include "DSet.h"
#include <set>
using std::set;
using std::make_pair;
using std::endl;
using std::pair;
Graph::Graph(int V){
    Count = V;
    Adj = new vector<int>[V];
}


void Graph::FillGraph(){
    for(int i = 0; i < Count; i++){
        cout << "Enter the number of adjacent nodes for node " << i+1 << "\n";
        int adj_n;
        cin >> adj_n;
        for(int k = 0; k < adj_n; k++){
            int N;
            cin >> N;
            Adj[i].push_back(N);
        }
    }
}


int Graph::FindDFS(int key){
    vector<bool> visited(Count);
    for(int i = 0; i < Count; i++){
        visited[i] = false;
    }
    return DFS(1, key, visited);
}


int Graph::DFS(int current, int key, vector<bool>& visited){
    visited[current - 1] = true;
    cout << current << " ";
    if (current == key){
        return current;
    }
    for(int i : Adj[current - 1]){
        if (!visited[i - 1]){
            return DFS(i,key, visited);
        }
    }
    return 0;
}


int Graph::FindBFS(int key){
    vector<bool> visited(Count);
    for(int i = 0; i < Count; i++){
        visited[i] = false;
    }
    queue<int> nodes;
    nodes.push(1);
    while(nodes.size()) {
        visited[nodes.front() - 1] = true;
        cout << nodes.front() << " ";
        if (nodes.front() == key) {
            return nodes.front();
        }
        for (int i : Adj[nodes.front() - 1]) {
            if (!visited[i - 1]) {
                nodes.push(i);
            }
        }
        nodes.pop();
    }
    return 0;
}

int Graph::_Min(vector<bool>& visited, vector<int>& minWays){
    int min = 20000;
    int indMin = 0;
    for(int i = 0; i < visited.size(); i++){
        if (visited[i] == false && minWays[i] < min){
            min = minWays[i];
            indMin = i;
        }
    }
    return indMin;
}

void Graph::FindMinWay(int destination, vector<int>& minWays, vector<vector<int>>& matrix) {
    int count = minWays.size();
    vector<bool> visited(count);
    int countOfVisited = 0;
    for (int i = 0; i < count; i++) {
        visited[i] = false;
        minWays[i] = 20000;
    }

    minWays[destination - 1] = 0;
    int current = destination - 1;

    while(countOfVisited < count){
        for (int j = 0; j < count; j++) {  // work with every adjacent node
            if (visited[j] == false && matrix[current][j] != 0){
                minWays[j] = std::min(minWays[current] + matrix[current][j], minWays[j]);
            }
        }
        visited[current] = true;
        countOfVisited++;
        current = _Min(visited, minWays);
    }
}

void Graph::Kruskal(vector<edge>& edges, vector<edge>& minSpanningTree, const int V){
    std::sort(edges.begin(), edges.end(), [](edge n1, edge n2){
        return n1.weight < n2.weight;
    });
    DSet set(V);
    for(int i = 0; i < V; i++){
        set.MakeSet(i + 1);
    }
    int e_size = edges.size();
    int counter = 0;  // count added edges
    for(int i = 0; i < e_size, counter != V - 1; i++){
        if (set.Find(edges[i].n1) != set.Find(edges[i].n2)) {
            minSpanningTree.push_back(edges[i]);
            set.Union(edges[i].n1, edges[i].n2);
            counter++;
        }
    }
}

void Graph::Prim(int N, vector<vector<std::pair<int, int>>>& g){
    int inf = 2000000;
    vector<int> min_way(N, inf);
    vector<int> parent(N, -1);
    vector<bool> isInTree(N, false);
    min_way[0] = 0;
    set<pair<int, int>> Q;
    Q.insert({0, 0});
    for(int i = 0; i < N; i++){
        if (Q.empty()){
            cout << "Enable to create MST";
        }
        int current = Q.begin()->second;
        Q.erase(Q.begin());
        isInTree[current] = true;
        if (parent[current] != -1){
            cout << current << " " <<parent[current] << "\n";
        }
        for(int j = 0; j < g[current].size(); j++){
            pair<int, int> current_edge = g[current][j];
            if (isInTree[current_edge.first] == false && current_edge.second < min_way[current_edge.first]){
                Q.erase({min_way[current_edge.first], current_edge.first});
                min_way[current_edge.first] = current_edge.second;
                parent[current_edge.first] = current;
                Q.insert({current_edge.second, current_edge.first});
            }
        }
    }
}