#include <iostream>
#include "UsefulHeap.h"

int CompareHighPriority(char d1, char d2)
{
    // 'A' - 'B' 는 음수인데, 'A' 의 우선순위가 높아야 하므로 d1 - d2 가 아닌 d2 - d1.
    return d2 - d1;
}

int main()
{
    Heap<char> heap(CompareHighPriority);

    heap.Insert('A');
    heap.Insert('B');
    heap.Insert('C');

    std::cout << heap.Delete() << std::endl;

    heap.Insert('A');
    heap.Insert('B');
    heap.Insert('C');

    while (!heap.IsEmpty())
        std::cout << heap.Delete() << std::endl;

    return 0;
}