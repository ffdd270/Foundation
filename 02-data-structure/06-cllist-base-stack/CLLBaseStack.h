#pragma once
#include "CLLinkedList.h"

typedef int Data;

typedef struct _listStack
{
    CList* plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
bool SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);