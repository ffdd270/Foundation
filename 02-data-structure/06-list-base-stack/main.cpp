#include <iostream>
#include "ListBaseStack.h"

int main()
{
    ListStack<int> stack;

    stack.push(1); stack.push(2);
    stack.push(3); stack.push(4);
    stack.push(5); stack.push(6);

    while (!stack.isEmpty())
    {
        std::cout << stack.pop() << " ";
    }

    return 0;
}