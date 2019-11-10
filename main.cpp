#include <iostream>
#include "Graph/Graph.h"
using std::cout;
using std::cin;
using std::endl;
int main() {
    vector<vector<std::pair<int, int>>> g = {{{1, 5}, {2, 9}, {4, 15}, {5, 6}},
                                             {{0, 5}, {2,7}},
                                             {{0, 9}, {1, 7}, {3, 8}, {4, 7}},
                                             {{2, 8}, {4, 5}},
                                             {{0, 15}, {2, 7}, {3, 5}, {5, 8}, {6, 9}},
                                             {{0, 6}, {4, 8}, {6, 11}},
                                             {{4, 9}, {5, 11}}};
    Graph::Prim(7, g);
    return 0;
}