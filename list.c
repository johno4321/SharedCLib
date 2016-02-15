#include "list.h"

struct List* InitList(void* data)
{
	struct ListNode* node = malloc(sizeof(struct ListNode));

	struct List* list = malloc(sizeof(struct List));

	list->current = node;

	list->firstNode = node;
	list->lastNode = node;
	
	list->firstNode->data = data;
	list->firstNode->nextNode = NULL;
	list->firstNode->prevNode = NULL;
		
	list->count = 1;

	return list;
}

struct ListNode* AddBeforeFirstList(struct List* list, void* data)
{
	struct ListNode* node = malloc(sizeof(struct ListNode));
	
	node->data = data;

	node->nextNode = list->firstNode;
	node->prevNode = NULL;

	list->current = node;

	list->firstNode->prevNode = node;
	list->firstNode = node;
	list->count++;

	return node;
}

struct ListNode* AddAfterLastList(struct List* list, void* data)
{
	struct ListNode* node = malloc(sizeof(struct ListNode));

	node->data = data;

	node->nextNode = NULL;
	node->prevNode = list->lastNode;
	
	list->current = node;

	list->lastNode->nextNode = node;
	list->lastNode = node;
	list->count++;

	return node;
}

void DeleteList(struct List* list)
{
	struct ListNode* current = list->firstNode;
	struct ListNode* next = NULL;

	while (current)
	{
		next = current->nextNode;
		
		free(current);
		current = (struct ListNode*)NULL;

		if (next == NULL)
		{
			break;
		}

		current = next;
	}
	
	free(list);
	list = NULL;
}

struct ListNode* RemoveList(struct List* list, struct ListNode* node)
{
	struct ListNode* current = list->firstNode;

	while (1)
	{
		if (current == node)
		{
			if (node->nextNode != NULL)
			{
				node->nextNode->prevNode = node->prevNode;
			}

			if (node->prevNode != NULL)
			{
				node->prevNode->nextNode = node->nextNode;
			}

			if (list->firstNode == node)
			{
				list->firstNode = node->nextNode;
			}

			if (list->lastNode == node)
			{
				list->lastNode = list->lastNode->prevNode;
			}

			list->count--;

			return node;
		}

		current = current->nextNode;

		if (current == NULL)
			break;
	}

	return NULL;
}


struct ListNode* RemoveAndReturnNextList(struct List* list, struct ListNode* node)
{
	struct ListNode* removedNode = RemoveList(list, node);

	if (removedNode != NULL)
	{
		removedNode = removedNode->nextNode;
	}

	return removedNode;
}

struct ListNode* RemoveAndReturnPrevList(struct List* list, struct ListNode* node)
{
	struct ListNode* removedNode = RemoveList(list, node);

	if (removedNode != NULL)
	{
		removedNode = removedNode->prevNode;
	}

	return removedNode;
}	