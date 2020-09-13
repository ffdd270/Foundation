#include <iostream>
#include "CLLBaseStack.h"

int main()
{
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 1); SPush(&stack, 2);
    SPush(&stack, 3); SPush(&stack, 4);
    SPush(&stack, 5); SPush(&stack, 6);

    while(!SIsEmpty(&stack))
        std::cout << SPop(&stack) << " ";

    return 0;
}