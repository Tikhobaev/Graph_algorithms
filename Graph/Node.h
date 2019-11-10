//
// Created by Илья on 031 31.10.19.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

#include <iostream>
#include <vector>
using std::vector;

class Node {
public:
    bool New;
    int Data;
    vector <Node*> Links;
    Node(int data){
        Data = data;
       Links = vector<Node*>();
    }
    void AddLink(Node* n){
        Links.push_back(n);
    }
};


#endif //DATA_STRUCTURES_NODE_H
