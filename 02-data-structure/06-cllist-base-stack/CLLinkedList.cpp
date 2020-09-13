#include "CLLinkedList.h"

void ListInit(CList* plist)
{
	plist->tail = nullptr;
	plist->cur = nullptr;
	plist->before = nullptr;
	plist->numOfData = 0;
}

void LInsert(CList* plist, Data data)
{
	CNode* newNode = new CNode;
	newNode->data = data;


	if(plist->tail == nullptr)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	
	(plist->numOfData)++;
}

void LInsertFront(CList* plist, Data data)
{
	CNode* newNode = new CNode;
	newNode->data = data;

	if (plist->tail == nullptr)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

bool LFirst(CList* plist, Data* pdata)
{
	if (plist->tail == nullptr)
		return false;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return true;
}

bool LNext(CList* plist, Data* pdata)
{
	if (plist->tail == nullptr)
		return false;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return true;
}

Data LRemove(CList* plist)
{
	CNode* rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = nullptr;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete rpos;
	(plist->numOfData)--;
	return rdata;
}

int LCount(CList* plist)
{
	return plist->numOfData;
}
