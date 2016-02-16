#pragma once
#include "common.h"

typedef struct tListNode
{
	void* data;
	struct tListNode* nextNode;
	struct tListNode* prevNode;
	
} ListNode;

typedef struct
{
	ListNode* firstNode;
	ListNode* lastNode;
	ListNode* current;

	uint32 count;

} List;

extern List* List_Init(void* data);
extern void List_Delete(List* list);

extern uint32 List_Count(List* list);

extern ListNode* List_First(List* list);
extern ListNode* List_Last(List* list);
extern ListNode* List_Current(List* list);

extern ListNode* List_AddBeforeFirst(List* list, void* data);
extern ListNode* List_AddAfterLast(List* list, void* data);

extern ListNode* List_Remove(List* list, ListNode* node);
extern ListNode* List_RemoveAndReturnNext(List* list, ListNode* node);
extern ListNode* List_RemoveAndReturnPrev(List* list, ListNode* node);