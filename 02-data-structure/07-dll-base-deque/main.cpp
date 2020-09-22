#include <iostream>
#include "DLLDeque.h"

using namespace dlldeque;

int main()
{
    DLLDeque<int> deque;

    deque.AddFirst(3);
    deque.AddFirst(2);
    deque.AddFirst(1);

    deque.AddLast(4);
    deque.AddLast(5);
    deque.AddLast(6);

    while(!deque.IsEmpty())
        std::cout << deque.RemoveFirst() << " ";

    std::cout << std::endl;

    deque.AddFirst(3);
    deque.AddFirst(2);
    deque.AddFirst(1);

    deque.AddLast(4);
    deque.AddLast(5);
    deque.AddLast(6);


    while(!deque.IsEmpty())
        std::cout << deque.RemoveLast() << " ";

    return 0;
}