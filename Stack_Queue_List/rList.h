//
// Created by Илья on 025 25.09.19.
//

#ifndef DATA_STRUCTURES_RLIST_H
#define DATA_STRUCTURES_RLIST_H
#include <iostream>
#include "sList.h"


template <class T>
class rNode
{
private:
    T value;
    rNode<T>* next;
public:
    void setData(T data);
    void setNext(rNode<T>* pp);
    T getData();
    rNode<T>* getNext();
};

template <class T>
class rList
{
public:
    rList(int);
    void add(T);
    void append(T);
    void print();
    bool search(T);
private:
    rNode<T>* head;
    rNode<T>* tail;
};


template <class T>
rList<T>::rList(int a)
{
    head = NULL;
    tail = NULL;
}

template <class T>
void rList<T>::add(T info)
{
    if(head == NULL) //if our list is currently empty
    {
        head = new rNode<T>;
        head->setData(info);
        head->setNext(head);
        tail = head;
    }
    else //if not empty add to the end
    {
        rNode<T>* temp = new rNode<T>;
        temp->setData(info);
        temp->setNext(head);
        tail->setNext(temp);
        head = temp;
    }
}


template <class T>
void rList<T>::append(T info)
{
    if(head == NULL) //if our list is currently empty
    {
        head = new rNode<T>;
        head->setData(info);
        head->setNext(head);
        tail = head;
    }
    else //if not empty add to the end
    {
        rNode<T>* pp = head;
        while(pp && pp->getNext() != NULL && pp->getNext() != tail)
        {
            pp = pp->getNext();
        }
        rNode<T>* temp = new rNode<T>;
        temp->setData(info);
        temp->setNext(head);
        tail = temp;
        if (pp->getNext() != NULL)
            (pp->getNext())->setNext(temp);
        else
            pp->setNext(temp);

    }
}



template <class T>
void rList<T>::print()
{
    rNode<T>* pp = head;
    while(pp)
    {
        std::cout << pp->getData() << " ";
        pp = pp->getNext();
        if (pp == tail)
        {
            std::cout << pp->getData() << " ";
            break;
        }
    }
}


template <class T>
bool rList<T>::search(T info)
{
    rNode<T>* pp = head;
    while(pp)
    {
        if(pp->getData() == info){
            return true;
        }
        if (pp == tail){
            return false;
        }
        pp = pp->getNext();
    }
    return false;
}


template <class T>
void rNode<T>::setData(T data)
{
    value = data;
}


template <class T>
T rNode<T>::getData()
{
    return value;
}

template <class T>
rNode<T>* rNode<T>::getNext()
{
    return next;
}

template <class T>
void rNode<T>::setNext(rNode<T>* pp)
{
    next = pp;
}

#endif //DATA_STRUCTURES_RLIST_H
