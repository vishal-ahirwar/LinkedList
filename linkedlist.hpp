#ifndef LINKEDLIST
#define LINKEDLIST
#include<iostream>
#define MACRO_LINKEDLIST template<class DATA_TYPE>
namespace V
{
MACRO_LINKEDLIST
struct Node
{
DATA_TYPE data{};
Node* next{};
};

MACRO_LINKEDLIST
class LinkedList
{
public:
		//TODO  Searching
Node<DATA_TYPE>* Search(const DATA_TYPE&);
		//TODO Sorting
void sort();
		//TODO Insert
void insert(const unsigned int&,const DATA_TYPE&);
		//TODO delete
void remove(const DATA_TYPE&);
void append(const DATA_TYPE&);//O(1)
void display()const;//O(n)
auto get_length()const { return this->len; };

private:

Node<DATA_TYPE>* head_node = nullptr;
Node<DATA_TYPE>* last_node = nullptr;//last or tail node 
unsigned int len{};
};
}
MACRO_LINKEDLIST
V::Node<DATA_TYPE>* V::LinkedList<DATA_TYPE>::Search(const DATA_TYPE&)
{
	return nullptr;
}
MACRO_LINKEDLIST
void V::LinkedList<DATA_TYPE>::sort()
{
}
MACRO_LINKEDLIST
void V::LinkedList<DATA_TYPE>::insert(const unsigned int&index, const DATA_TYPE&data)
{
	if (index > len)return;
	++len;
	V::Node<DATA_TYPE>* node = new Node<DATA_TYPE>();
	node->data = data;
	if (index == 0)
	{
		node->next = head_node;
		head_node = node;
	}
	else if (index==len)
	{
		last_node = last_node->next = node;
	}
	else
	{
		auto temp_head = head_node
			;
		for (int i = 0; i < index && temp_head != nullptr; ++i)
		{
			temp_head = temp_head->next;
		};
		node->next = temp_head->next;
		temp_head->next = node;
	}
}
MACRO_LINKEDLIST
void V::LinkedList<DATA_TYPE>::remove(const DATA_TYPE&)
{
}
MACRO_LINKEDLIST
void V::LinkedList<DATA_TYPE>::append(const DATA_TYPE& data)//O(1)
{
	++len;
	Node<DATA_TYPE>* node = new Node<DATA_TYPE>();
	node->data = data;
	node->next = nullptr;
	if (!last_node)
		last_node = head_node = node;
	else
		last_node = last_node->next = node;

}
MACRO_LINKEDLIST
void  V::LinkedList<DATA_TYPE>::display()const//O(n)
{
	Node<DATA_TYPE>* temp_node = head_node;
	while (temp_node)
	{
		std::cout << temp_node->data << " ";
		temp_node = temp_node->next;
	}printf("\n");
}
#endif
