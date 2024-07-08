//
// Created by Vishal Ahirwar on 09-07-2024.
//

#ifndef LINKEDLIST_LINKEDLIST_CUH
#define LINKEDLIST_LINKEDLIST_CUH
#include <string.h>
#include <iostream>

template<typename T>
struct Node
{
public:
    T data{};
    Node<T>*next{nullptr};
};
template<typename T>
class LinkedList
{

    Node<T>*head{};
public:
    Node<T>*getHead()const{return head;};
    LinkedList();
    ~LinkedList();
};
template<class T>
LinkedList<T>::LinkedList() {
    head=new Node<T>();
};

template<class T>
LinkedList<T>::~LinkedList()
{
    while(head)
    {
        Node<T>*temp_node{head->next};
        delete temp_node;
        head=temp_node;
    }
};

#endif //LINKEDLIST_LINKEDLIST_CUH
