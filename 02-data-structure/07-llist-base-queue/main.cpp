#include <iostream>

#include "LlistBaseQueue.h"

int main()
{
    LlQueue<int> queue;

    queue.Enqueue(1); queue.Enqueue(2);
    queue.Enqueue(3); queue.Enqueue(4);
    queue.Enqueue(5); queue.Enqueue(6);

    while (!queue.IsEmpty())
        std::cout << queue.Dequeue() << " ";

    return 0;
}