//
// Created by Илья on 026 26.09.19.
//

#ifndef DATA_STRUCTURES_LSTACK_H
#define DATA_STRUCTURES_LSTACK_H


#include <iostream>

template <typename T>
class LStack
{
    struct Node
    {
        T value;
        Node* prev;
    };
public:
    LStack();
    ~LStack();
    void Push(T);
    T Pop();
    T Top();
    void print();
    bool isEmpty();
private:
    Node* top;
    int size;
};

template <typename T>
LStack<T>::LStack()
{
    top = new Node;
    top = NULL;
    size = 0;
}


template <typename T>
LStack<T>::~LStack()
{
    delete[] top;
}

template <typename T>
void LStack<T>::push(T val)
{
    size++;
    Node* new_node = new Node;
    new_node->value = val;
    new_node->prev = top;
    top = new_node;
}

template <typename T>
T LStack<T>::pop()
{
    if (size == 0)
    {
        std::cout << "Stack is empty";
    }
    else
    {
        Node* ex_top = top;
        top = top->prev;
        size--;
        return ex_top->value;
    }
}

template <typename T>
T LStack<T>::getTop()
{
    if (size == 0)
    {
        std::cout << "Stack is empty";
    }
    else
    {
        return top->value;
    }
}


template <typename T>
void LStack<T>::print()
{
    Node* currentNode = top;
    std::cout << "Stack:\n";
    while(currentNode)
    {
        std::cout << currentNode->value << " ";
        currentNode = currentNode->prev;
    }
    std::cout << std::endl;
}


template <typename T>
bool LStack<T>::isEmpty()
{
    return size == 0;
}

#endif //DATA_STRUCTURES_LSTACK_H
