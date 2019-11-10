//
// Created by Илья on 026 26.09.19.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H


#include <iostream>

template <typename T>
class Stack
{
public:
    Stack(int);
    ~Stack();
    void push(T);
    T pop();
    T getTop();
    void print();
    bool isEmpty();
private:
    T* stackPtr;
    const int size;
    int top;
};


template <typename T>
Stack<T>::Stack(int max_size):size(max_size)
{
    stackPtr = new T[size];
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] stackPtr;
}

template <typename T>
void Stack<T>::push(T val)
{
    if(top + 1 < size)
    {
        stackPtr[++top] = val;
    }
    else
    {
        std::cout << "\nStack if overflow\n";
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (top == 0)
    {
        std::cout << "Stack is empty";
    }
    else
    {
        return stackPtr[top--];
    }
}


template <typename T>
T Stack<T>::getTop()
{
    if (top == 0)
    {
        std::cout << "Stack is empty";
    }
    else
    {
        return stackPtr[top];
    }
}

template <typename T>
void Stack<T>::print()
{
    std::cout << "Stack:\n";
    for(int i = top; i >= 0; i--)
    {
        std::cout << stackPtr[i] << " ";
    }
    std::cout << std::endl;
}


template <typename T>
bool Stack<T>::isEmpty()
{
    return (top == 0 || top == -1);
}

#endif //DATA_STRUCTURES_STACK_H
