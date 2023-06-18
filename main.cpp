// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"linkedlist.hpp"
int main()
{
    V::LinkedList<std::string>string_list;
    V::LinkedList<int>int_list;


    for (int i = 0; i < 150; ++i)int_list.append(i * i);
    string_list.append("Hello");//O(1)
    string_list.append("World");
    string_list.append("!");
    string_list.append("by Vishal!\n");
    string_list.display();//O(n)
    int_list.display();
}

