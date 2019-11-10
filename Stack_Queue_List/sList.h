//
// Created by Илья on 025 25.09.19.
//

#ifndef DATA_STRUCTURES_SLIST_H
#define DATA_STRUCTURES_SLIST_H

#include <iostream>


template <class T>
class Node
{
private:
    T value;
    Node<T>* next;
public:
    void setData(T data);
    void setNext(Node<T>* pp);
    T getData();
    Node<T>* getNext();
};


template <class T>
class List
{
public:
    List(T);
    ~List();
    Node<T>* getHead();
    void add(T);
    void append(T);
    void print();
    void removeLast();
    bool search(T);
private:
    Node<T>* head;
};


template <class T>
List<T>::List(T a)
{
    head = NULL;
}


template <class T>
List<T>::~List()
{
    delete[]head;
}

template <class T>
void List<T>::add(T info)
{
    if(head == NULL) //if our list is currently empty
    {
        head = new Node<T>;
        head->setData(info);
        head->setNext(NULL);
    }
    else //if not empty add to the end
    {
        Node<T>* temp = new Node<T>;
        temp->setData(info);
        temp->setNext(head);
        head = temp;

    }
}


template <class T>
void List<T>::append(T info)
{
    if(head == NULL) //if our list is currently empty
    {
        head = new Node<T>;
        head->setData(info);
        head->setNext(NULL);
    }
    else //if not empty add to the end
    {
        Node<T>* pp = head;
        while(pp && pp->getNext() != NULL)
        {
            pp = pp->getNext();
        }
        Node<T>* temp = new Node<T>;
        temp->setData(info);
        temp->setNext(NULL);
        if (pp->getNext() != NULL)
            (pp->getNext())->setNext(temp);
        else
            pp->setNext(temp);

    }
}



template <class T>
void List<T>::print()
{
    Node<T>* pp = head;
    while(pp)
    {
        std::cout << pp->getData() << " ";
        pp = pp->getNext();
    }
}


template <class T>
bool List<T>::search(T info)
{
    Node<T>* pp = head;
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
void List<T>::removeLast()
{
    Node<T>* pp = head;
    Node<T>* prev = head;
    if (head == NULL)
    {
        std::cout << "There are no elements for deleting";
        return;
    }
    while(pp && pp->getNext())
    {
        prev = pp;
        pp = pp->getNext();
    }
    if (head && head->getNext() == NULL)  // If there are one element
    {
        head = NULL;
    }
    prev->setNext(NULL);  // If there are two or more elements
}

template <class T>
Node<T>* List<T>::getHead()
{
    return head;
}

template <class T>
void Node<T>::setData(T data)
{
    value = data;
}


template <class T>
T Node<T>::getData()
{
    return value;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node<T>* pp)
{
    next = pp;
}



#endif //DATA_STRUCTURES_SLIST_H
