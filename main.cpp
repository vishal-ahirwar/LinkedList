#include <QCoreApplication>
#include"linkedlist.h"
#include"linkedlist.h"
#include<string>
typedef std::string str;
int main(int argc, char *argv[])
{
    LinkedList<str> student_list{};
    LinkedList<str> test_list=std::move(student_list);
    test_list.pushBack("Ryan Ronald");
    test_list.pushBack("Krish Kr");
    test_list.pushBack("Kyuoin Lyin");
    test_list.pushFront("okie");
    test_list.pushFront("1st");
    test_list.pushBack("last");
    test_list.display();
}
