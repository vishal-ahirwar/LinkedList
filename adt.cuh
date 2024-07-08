//
// Created by Vishal Ahirwar on 09-07-2024.
//
#ifndef MACRO_ADT
#define MACRO_ADT
#include <iostream>
#include <typeinfo>
#include <cstdint>
#include "colors.cuh"
#define TYPE template<typename TEMPLATE, const int SIZE>

namespace ADT
{

void show_error(const std::string& str) {
    printf("%s[Error] : %s\n", ANSI_COLOR_RED, str.c_str());
};

void show_warning(const std::string& str) {
    printf("%s[Warning] : %s\n", ANSI_COLOR_YELLOW, str.c_str());
};

void show_message(const std::string& str) {
    printf("%s[Message] : %s\n", ANSI_COLOR_RESET, str.c_str());
};

TYPE
    class Array
{
public:
    static void swap(TEMPLATE& a, TEMPLATE& b)
    {
        TEMPLATE c = a;
        a = b;
        b = c;
    };

public:


    Array() :size(SIZE), data(new TEMPLATE[SIZE]), len(0) { show_warning("Constructor Called!"); };
    ~Array()
    {
        if (this->data != nullptr)delete[]this->data;
        show_warning("destructor Called!");
    };

    const auto get_size()const { return this->size; };
    const auto get_len()const { return this->len; };
    const auto* get_ptr()const { return this->data; };


    void append(const TEMPLATE&);

    void sort(int(*function)(const void*, const void*));
    int insert(const uint16_t& index, const TEMPLATE& value);
    //TODO Binary Search
    int binary_search(const TEMPLATE& value);

    int linear_search(const TEMPLATE& value);

    void left_rotate();
    void right_rotate();
    void left_shift();
    void right_shift();

    void reverse();
    void remove(const TEMPLATE&);
    void display()const;

    TEMPLATE* operator [](uint16_t index)
    {
        if (index <= len)
        {
            return &data[index];
        }
        else {
            return nullptr;
        }
    }
    ;

private:
    unsigned int size{};
    unsigned int len{};
    TEMPLATE* data{ nullptr };
    bool b_sorted{ false };
};

TYPE
    inline void Array<TEMPLATE, SIZE>::append(const TEMPLATE& value)
{
    if (len < size)
    {
        data[len++] = value;
    }
    else { show_error("Data structure is full"); };

};

TYPE
    inline int Array<TEMPLATE, SIZE>::insert(const uint16_t& index, const TEMPLATE& value)
{
    if (index > size || len == size)
    {
        show_error("Can't insert new element the structure is already full or the index is out of Array size!");
        return -1;
    }

    for (int i = len; i != index; --i)
    {
        data[i] = data[i - 1];
    };
    data[index] = value;
    ++len;
    return 1;
};

TYPE
    inline int Array<TEMPLATE, SIZE>::binary_search(const TEMPLATE& value)
{
    if (!b_sorted)
    {
        show_error("Array iss not sorted");
        return -1;
    };
    unsigned int low{ 0 }, high{ this->len }, mid{ 0 };
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (value == data[mid])return mid;
        else if (value < data[mid])high = mid - 1;
        else if (value > data[mid])low = mid + 1;
    };
    return int(-1);
}
TYPE
    inline int Array<TEMPLATE, SIZE>::linear_search(const TEMPLATE& value)
{
    b_sorted = false;
    for (uint16_t i = 0; i < len; ++i)
    {
        if (data[i] == value)
        {
            if (i == 0)return i;
            swap(data[i - 1], data[i]);//Memoization shifting elements slowly slowly
            /*swap(data[0], data[i]);*/
            return i - 1;
        };
    };

    return -1;
};
TYPE
    void Array<TEMPLATE, SIZE>::display()const
{
    show_message("Displaying Elements in Array : ");
    for (uint16_t i = 0; i < this->len; ++i)
    {
        std::cout << data[i] << ", ";
    };
    printf("\n");
};
TYPE
    void Array<TEMPLATE, SIZE>::sort(int(*function)(const void*, const void*))
{
    qsort(data, len, sizeof(TEMPLATE), function);
    b_sorted = true;
};

template<class TEMPLATE, int SIZE, int SIZE2>
void merge(Array<TEMPLATE, SIZE>& arr, const Array<TEMPLATE, SIZE2>& arr1)
{
    TEMPLATE* new_data = new TEMPLATE[arr.len + arr1.len];
    unsigned i{};
    for (i = 0; i < arr.len; ++i)new_data[i] = arr.data[i];
    for (unsigned j = 0; j < arr1.len; ++j, ++i)new_data[i] = arr1.data[j];
    delete[] arr.data;
    arr.len += arr1.len;
    arr.size += arr1.size;
    arr.data = new_data;
    new_data = nullptr;
};

TYPE
    void Array<TEMPLATE, SIZE>::left_rotate()
    {

        //TODO LeftRotate()
    };

TYPE
    void Array<TEMPLATE, SIZE>::right_rotate()
    {
        //TODO RightRotate()
    };

TYPE
    void Array<TEMPLATE, SIZE>::left_shift()
    {

        //TODO LeftShift()

    };

TYPE
    void Array<TEMPLATE, SIZE>::right_shift()
    {

        //TODO RightShift()
    };

TYPE
    void Array<TEMPLATE, SIZE>::reverse()
    {

        //TODO Reversing Array

    };

TYPE
    void Array<TEMPLATE, SIZE>::remove(const TEMPLATE& data_)
    {
        //TODO Deleting Element From Array
    };


}
#endif //LINKEDLIST_ADT_CUH
