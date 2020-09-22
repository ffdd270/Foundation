#include <iostream>
#include "ListBaseStack.h"

using namespace liststack;

int main()
{
    ListStack<int> stack;

    stack.Push(1); stack.Push(2);
    stack.Push(3); stack.Push(4);
    stack.Push(5); stack.Push(6);

    while (!stack.IsEmpty())
    {
        std::cout << stack.Pop() << " ";
    }

    return 0;
}