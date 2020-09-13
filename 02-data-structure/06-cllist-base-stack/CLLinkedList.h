#pragma once

typedef int Data;

typedef struct _cnode
{
	Data data;
	struct _cnode* next;
} CNode;

typedef struct _clinkedList
{
	CNode* tail;
	CNode* cur;
	CNode* before;
	int numOfData;
} CLInkedList;

typedef CLInkedList CList;

void ListInit(CList* plist);
void LInsert(CList* plist, Data data);
void LInsertFront(CList* plist, Data data);

bool LFirst(CList* plist, Data* pdata);
bool LNext(CList* plist, Data* pdata);

Data LRemove(CList* plist);
int LCount(CList* plist);