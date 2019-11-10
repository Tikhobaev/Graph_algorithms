//
// Created by Илья on 030 30.09.19.
//

#ifndef DATA_STRUCTURES_LQUEUE_H
#define DATA_STRUCTURES_LQUEUE_H


#include <iostream>

template <typename T>
class LQueue {
    struct Node
    {
        T value;
        Node* prev;
    };
public:
    LQueue();
    ~LQueue();
    void push(T);
    T pop();
    T getLast();
    void print();
    bool isEmpty();
private:
    Node* last;
    int size;
};

template<typename T>
LQueue<T>::LQueue()
{
    last = new Node;
    last = NULL;
    size = 0;
}

template <typename T>
LQueue<T>::~LQueue()
{
    delete[] last;
}

template <typename T>
void LQueue<T>::push(T val)
{
    Node* new_node = new Node;
    new_node->value = val;
    new_node->prev = NULL;

    Node* first = last;
    while(first && first->prev)
    {
        first = first->prev;
    }
    if (first)
        first->prev = new_node;
    if (size == 0)
        last = new_node;
    size++;
}


template <typename T>
void LQueue<T>::print()
{
    if (last == NULL)
    {
        std::cout << "\nQueue is empty\n";
        return;
    }
    std::cout << "Queue (reverse order):\n";
    Node* it = last;
    while(it)
    {
        std::cout << it->value << " ";
        it = it->prev;
    }
    std::cout << std::endl;
}

template <typename T>
T LQueue<T>::pop()
{
    if (size == 0)
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        Node* ex_prev = last;
        if (last->prev)
        {
            last = last->prev;
        }
        else
        {
            last = NULL;
        }
        size--;
        return ex_prev->value;
    }
}


template <typename T>
T LQueue<T>::getLast()
{
    if (size == 0)
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        return last->value;
    }
}


template <typename T>
bool LQueue<T>::isEmpty()
{
    return (size == 0);
}


#endif //DATA_STRUCTURES_LQUEUE_H
