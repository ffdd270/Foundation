#include <iostream>
#include "DoubleLinkedList.h"

int main()
{
    DLList<int> list;
    list.Insert(1);
    list.Insert(3);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(9);

    int* i = new int;
    list.First(i);

    std::cout << *i;

    return 0;
}