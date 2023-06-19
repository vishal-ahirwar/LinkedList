// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"linkedlist.hpp"
#include<fstream>
#include<string>
int main()
{
    V::LinkedList<std::string>string_list;
    V::LinkedList<int>int_list;
    //std::fstream file;
    //while (true)
    //{

    //    printf("file path <> : ");
    //std::string filename{};
    //std::getline(std::cin, filename);

    //file.open(filename.c_str(), std::fstream::in);
    //if (file.is_open())
    //{
    //    std::string str{};
    //    while (!file.eof())
    //    {

    //    char c=file.get();
    //    str += c;
    //    }
    //    string_list.append(str);
    //    file.close();
    //}
    //else
    //    printf("file doesn't exist!\n");
    string_list.append("First");
    string_list.append(" Second");
    string_list.insert(3, "Third");
    string_list.insert(0, "Fourth");
    string_list.insert(1, "Random");
    string_list.insert(2, "2Random");
    string_list.insert(6, "2435Random");
    for (int i = 0; i < 5; ++i)int_list.append(i * i);
    string_list.display();//O(n)
    int_list.display();
    
    getchar();
}