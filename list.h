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

extern struct List* l_init();
extern struct List* l_init(void* data);
extern struct ListNode* l_addBeforeFirst(struct List* list, void* data);
extern struct ListNode* l_addAfterLast(struct List* list, void* data);
extern void l_delete(struct List* list);
extern struct ListNode* l_remove(struct List* list, struct ListNode* node);