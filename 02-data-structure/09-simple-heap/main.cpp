#include <iostream>
#include "SimpleHeap.h"

using namespace heap;

int main()
{
    Heap<char> heap;
    heap.Insert('A', 1);
    heap.Insert('B', 2);
    heap.Insert('C', 3);

    std::cout << heap.Delete() << std::endl;

    heap.Insert('A', 1);
    heap.Insert('B', 2);
    heap.Insert('C', 3);

    while (!heap.IsEmpty())
        std::cout << heap.Delete() << std::endl;

    return 0;
}