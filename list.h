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

extern struct List* InitList(void* data);
extern struct ListNode* AddBeforeFirstList(struct List* list, void* data);
extern struct ListNode* AddAfterLastList(struct List* list, void* data);
extern void DeleteList(struct List* list);
extern struct ListNode* RemoveList(struct List* list, struct ListNode* node);
extern struct ListNode* RemoveAndReturnNextList(struct List* list, struct ListNode* node);
extern struct ListNode* RemoveAndReturnPrevList(struct List* list, struct ListNode* node);