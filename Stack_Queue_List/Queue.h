//
// Created by Илья on 030 30.09.19.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include <iostream>

template <typename T>
class Queue {
public:
    Queue(int);
    ~Queue();
    void push(T);
    T pop();
    T getLast();
    void print();
    bool isEmpty();
private:
    T* queuePtr;
    const int size;
    int last;
};

template<typename T>
Queue<T>::Queue(int max_size):size(max_size)
{
    queuePtr = new T[size];
    last = -1;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] queuePtr;
}

template <typename T>
void Queue<T>::push(T val)
{
    if(last + 1 < size)
    {
        if (last >= 0)
        {
            for(int i = last+1; i >= 1; i--)
            {
                queuePtr[i] = queuePtr[i-1];
            }
        }
        queuePtr[0] = val;
        last++;
    }
    else
    {
        std::cout << "\nQueue if overflow\n";
    }
}


template <typename T>
void Queue<T>::print()
{
    if (last == -1)
    {
        std::cout << "\nQueue is empty\n";
        return;
    }
    std::cout << "Queue:\n";
    for(int i = 0; i <= last; i++)
    {
        std::cout << queuePtr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T Queue<T>::pop()
{
    if (last == -1)
    {
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
        return queuePtr[last--];
    }
}


template <typename T>
T Queue<T>::getLast()
{
    if (last == -1)
    {
        std::cout << "Stack is empty";
    }
    else
    {
        return queuePtr[last];
    }
}


template <typename T>
bool Queue<T>::isEmpty()
{
    return (last == -1);
}
#endif //DATA_STRUCTURES_QUEUE_H

