#include <iostream>
#include "linkedlist.cuh"
#include "adt.cuh"

int main() {
    ADT::Array<std::string,10>anime{};
    LinkedList<int>some_names{};
    auto head_node= some_names.getHead();
    if (head_node)
    std::cout<<head_node->data<<"\n";
    return 0;
};

