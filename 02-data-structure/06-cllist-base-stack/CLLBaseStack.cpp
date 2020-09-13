#include "CLLBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->plist = new CList;
	ListInit(pstack->plist);
}

bool SIsEmpty(Stack* pstack)
{
	return (LCount(pstack->plist) == 0);
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack)
{
	Data data;
	LFirst(pstack->plist, &data);

	LRemove(pstack->plist);
	return data;
}

Data SPeek(Stack* pstack)
{
	Data data;
	LFirst(pstack->plist, &data);

	return data;
}
