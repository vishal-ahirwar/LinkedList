
#include"linkedlist.h"
#include"linkedlist.h"
#include<string>
typedef std::string str;
int main(int argc, char *argv[])
{
    LinkedList<int> list;
    for (auto i = 0; i < 10; ++i)list.pushBack(i);
    list.display();
    LinkedList<int>::Node* result=list.search(9);
    list.display();
    list.popFront();
    list.display();
    list.popFront();
    list.popBack();
    list.display();
    list.popBack();
    list.display();
    result=list.search(6);
    list.display();
    return result->data;
}
