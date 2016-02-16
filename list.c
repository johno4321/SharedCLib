#include "list.h"

List* List_Init(void* data)
{
	ListNode* node;
	List* list;

	node = malloc(sizeof(ListNode));
	list = malloc(sizeof(List));

	list->current = node;

	list->firstNode = node;
	list->lastNode = node;
	
	list->firstNode->data = data;
	list->firstNode->nextNode = NULL;
	list->firstNode->prevNode = NULL;
		
	list->count = 1;

	return list;
}

ListNode* List_AddBeforeFirst(List* list, void* data)
{
	ListNode* node;
		
	node = malloc(sizeof(ListNode));
	
	node->data = data;

	node->nextNode = list->firstNode;
	node->prevNode = NULL;

	list->current = node;

	list->firstNode->prevNode = node;
	list->firstNode = node;
	list->count++;

	return node;
}

ListNode* List_AddAfterLast(List* list, void* data)
{
	ListNode* node;
	
	node = malloc(sizeof(ListNode));

	node->data = data;

	node->nextNode = NULL;
	node->prevNode = list->lastNode;
	
	list->current = node;

	list->lastNode->nextNode = node;
	list->lastNode = node;
	list->count++;

	return node;
}

void List_Delete(List* list)
{
	ListNode* current;
	ListNode* next;

	if (list == NULL)
		return;

	current = list->firstNode;
	next = NULL;

	while (current)
	{
		next = current->nextNode;
		
		free(current);
		current = (ListNode*)NULL;

		if (next == NULL)
		{
			break;
		}

		current = next;
	}
	
	free(list);
	list = NULL;
}

ListNode* List_First(List* list)
{
	return list->firstNode;
}

ListNode* List_Last(List* list)
{
	return list->lastNode;
}

ListNode* List_Next(List* list)
{
	if (list->current != list->firstNode)
	{
		list->current = list->firstNode;
	}
	else
	{
		list->current = list->current->nextNode;
	}

	return list->current;
}

ListNode* List_Remove(List* list, ListNode* node)
{
	ListNode* current;
	
	current = list->firstNode;

	while (True)
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


ListNode* List_RemoveAndReturnNext(List* list, ListNode* node)
{
	ListNode* removedNode;
	
	removedNode = List_Remove(list, node);

	if (removedNode != NULL)
	{
		removedNode = removedNode->nextNode;
	}

	return removedNode;
}

ListNode* List_RemoveAndReturnPrev(List* list, ListNode* node)
{
	ListNode* removedNode;
	
	removedNode = List_Remove(list, node);

	if (removedNode != NULL)
	{
		removedNode = removedNode->prevNode;
	}

	return removedNode;
}