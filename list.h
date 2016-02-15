#pragma once

#include "common.h"

struct ListNode
{
	void* data;
	struct ListNode* nextNode;
	struct ListNode* prevNode;
	
};

struct List
{
	struct ListNode* firstNode;
	struct ListNode* lastNode;
	struct ListNode* current;

	int count;
};

extern struct List* List_Init(void* data);
extern struct ListNode* List_AddBeforeFirst(struct List* list, void* data);
extern struct ListNode* List_AddAfterLast(struct List* list, void* data);
extern void List_Delete(struct List* list);
extern struct ListNode* List_Remove(struct List* list, struct ListNode* node);
extern struct ListNode* List_RemoveAndReturnNext(struct List* list, struct ListNode* node);
extern struct ListNode* List_RemoveAndReturnPrev(struct List* list, struct ListNode* node);