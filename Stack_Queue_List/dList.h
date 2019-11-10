//
// Created by Илья on 025 25.09.19.
//

#ifndef DATA_STRUCTURES_DLIST_H
#define DATA_STRUCTURES_DLIST_H

#include <iostream>

template <class T>
class dNode
{
private:
    T value;
    dNode<T>* next;
    dNode<T>* prev;
public:
    void setData(T data);
    void setNext(dNode<T>* pp);
    void setPrev(dNode<T>* pp);
    T getData();
    dNode<T>* getNext();
    dNode<T>* getPrev();
};


template <class T>
class dList
{
public:
    dList(int);
    void add(T);
    void append(T);
    void print();
    bool search(T);
private:
    dNode<T>* head;
};


template <class T>
dList<T>::dList(int a)
{
    head = NULL;
}

template <class T>
void dList<T>::add(T info)
{
    if(head == NULL) //if our list is currently empty
    {
        head = new dNode<T>;
        head->setData(info);
        head->setNext(NULL);
        head->setPrev(NULL);
    }
    else //if not empty add to the end
    {
        dNode<T>* temp = new dNode<T>;
        temp->setData(info);
        temp->setNext(head);
        temp->setPrev(NULL);
        head->setPrev(temp);
        head = temp;
    }
}


template <class T>
void dList<T>::append(T info)
{
    if(head == NULL) //if our list is currently empty
    {
        head = new dNode<T>;
        head->setData(info);
        head->setNext(NULL);
        head->setPrev(NULL);
    }
    else //if not empty add to the end
    {
        dNode<T>* pp = head;
        while(pp && pp->getNext() != NULL)
        {
            pp = pp->getNext();
        }
        dNode<T>* temp = new dNode<T>;
        temp->setData(info);
        temp->setNext(NULL);
        temp->setPrev(pp);
        if (pp->getNext() != NULL)
            (pp->getNext())->setNext(temp);
        else
            pp->setNext(temp);

    }
}



template <class T>
void dList<T>::print()
{
    dNode<T>* pp = head;
    while(pp)
    {
        std::cout << pp->getData() << " ";
        pp = pp->getNext();
    }
}


template <class T>
bool dList<T>::search(T info)
{
    dNode<T>* pp = head;
    while(pp)
    {
        if(pp->getData() == info){
            return true;
        }
        pp = pp->getNext();
    }
    return false;
}


template <class T>
void dNode<T>::setData(T data)
{
    value = data;
}


template <class T>
T dNode<T>::getData()
{
    return value;
}

template <class T>
dNode<T>* dNode<T>::getNext()
{
    return next;
}

template <class T>
void dNode<T>::setNext(dNode<T>* pp)
{
    next = pp;
}


template <class T>
void dNode<T>::setPrev(dNode<T>* pp)
{
    prev = pp;
}


template <class T>
dNode<T>* dNode<T>::getPrev()
{
    return prev;
}


#endif //DATA_STRUCTURES_DLIST_H
