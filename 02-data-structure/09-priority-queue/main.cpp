#include <iostream>
#include <string>
#include "PriorityQueue.h"

int CompareHighPriority(const std::string s1, const std::string s2)
{
    if(s1 < s2)
        return 1;

    else if (s1 == s2)
        return 0;

    else
        return -1;
}

using namespace priorityqueue;

int main()
{
    PriorityQueue<std::string> dictionary(CompareHighPriority);

    dictionary.Enqueue("apple");
    dictionary.Enqueue("banana");
    dictionary.Enqueue("ability");
    dictionary.Enqueue("busker busker");
    dictionary.Enqueue("beat");
    dictionary.Enqueue("cook");
    dictionary.Enqueue("is");
    dictionary.Enqueue("angel");

    while(!dictionary.IsEmpty())
        std::cout << dictionary.Dequeue() << std::endl;

    return 0;
}