#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
template<class T>
class LinkedList
{
public:
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
    LinkedList(LinkedList&&)noexcept;

    LinkedList operator=(const LinkedList&)=delete;
    void display()const;
    void pushBack(const T&);
    void pushFront(const T&);
    void popBack();
    void popFront();
    [[nodiscard]]Node* search(const T&);
};

template<class T>
void LinkedList<T>::display()const
{
    if(!head)return;
    Node*current_node=head;
    std::cout<<"[ ";
    while(current_node)
    {
        std::cout<<current_node->data;
        if (current_node->next)std::cout << ", ";
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
    if (!head)return;
    Node* current_node = head;
    Node* previous_node = nullptr;
    while (current_node->next)
    {
        previous_node = current_node;
        current_node = current_node->next;
    };
    delete current_node;
    if(previous_node)
    previous_node->next = nullptr;
};

template<class T>
void LinkedList<T>::popFront()
{
    if (!head)return;
    Node* new_head = head->next;
    delete head;
    head = new_head;
};

template<class T>
LinkedList<T>::LinkedList(LinkedList&&list)noexcept
{
    this->head = list.head;
    list.head = nullptr;
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

template<class T>
typename LinkedList<T>::Node* LinkedList<T>::search(const T& value)
{
    //methods to improve searching
    //1.transposition
    //2.move to head

    //we are using move to head method for  optimizing linear search in linkedlist
    if (!head)return nullptr;
    Node* current_node = head;
    Node* previous_node = nullptr;
    while (current_node)
    {
        if (current_node->data == value)
        {
            if (previous_node == nullptr)return current_node;
            previous_node->next = current_node->next;
            current_node->next = head;
            head = current_node;
            return current_node;
        }
        previous_node = current_node;
        current_node = current_node->next;
    };
    return nullptr;
};
#endif // LINKEDLIST_H
