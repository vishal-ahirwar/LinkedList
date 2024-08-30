#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
template<class T>
class LinkedList
{
    struct Node
    {
        T data{};
        Node*next{};
        Node(const T&t,Node*n=nullptr)
        {
            data=t;
            next=n;
        };
    };
private:
    Node*head{};
protected:
public:
    LinkedList()=default;
    ~LinkedList();
    LinkedList(const LinkedList&)=delete;
    LinkedList(LinkedList&&);

    LinkedList operator=(LinkedList&)=delete;
    void display()const;
    void pushBack(const T&);
    void pushFront(const T&);
    void popBack();
    void popFront();
};

template<class T>
void LinkedList<T>::display()const
{
    if(!head)return;
    Node*current_node=head;
    std::cout<<"[ ";
    while(current_node)
    {
        std::cout<<current_node<<" : "<<current_node->data<<", ";
        current_node=current_node->next;
    };
    std::cout<<"] \n";
};

template<class T>
void LinkedList<T>::pushBack(const T&t)
{
    if(!head)
    {
        Node*new_node=new Node(t);
        head=new_node;
        return;
    };

    Node*current_node=head;
    while(current_node->next)
    {
        current_node=current_node->next;
    };
    current_node->next=new Node(t,nullptr);
};

template<class T>
void LinkedList<T>::pushFront(const T&t)
{
    if(!head)
    {
        head=new Node(t,nullptr);
        return;
    };
    Node*new_head=new Node(t,nullptr);
    new_head->next=head;
    head=new_head;
    head->next=new_head->next;
};

template<class T>
void LinkedList<T>::popBack()
{

};

template<class T>
void LinkedList<T>::popFront()
{

};

template<class T>
LinkedList<T>::LinkedList(LinkedList&&list)
{

};

template<class T>
LinkedList<T>::~LinkedList()
{
    if(!head)return;
    Node*current_node=head;
    while(current_node->next)
    {
        Node*to_delete=current_node;
        current_node=to_delete->next;
        delete to_delete;
    };
    delete current_node;
};

#endif // LINKEDLIST_H
