#include "list.h"

List* List_Init(void* data)
{
	ListNode* node = malloc(sizeof(ListNode));
	if (node == NULL)
		return NULL;

	List* list = malloc(sizeof(List));
	if (list == NULL)
	{
		free(node);
		return NULL;
	}

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
	node->prevNode = null;

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

	node->nextNode = null;
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

	if (list == null)
		return;

	current = list->firstNode;
	next = null;

	while (current)
	{
		next = current->nextNode;
		
		free(current);
		current = (ListNode*)null;

		if (next == null)
		{
			break;
		}

		current = next;
	}
	
	free(list);
	list = null;
}

uint32 List_Count(List* list)
{
	return list->count;
}

ListNode* List_First(List* list)
{
	return list->firstNode;
}

ListNode* List_Last(List* list)
{
	return list->lastNode;
}

ListNode* List_Current(List* list)
{
	return list->current;
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
	if (list == NULL || node == NULL)
		return NULL;

	ListNode* current = list->firstNode;

	while (current != NULL)
	{
		if (current == node)
		{
			if (node->nextNode != NULL)
				node->nextNode->prevNode = node->prevNode;

			if (node->prevNode != NULL)
				node->prevNode->nextNode = node->nextNode;

			if (list->firstNode == node)
				list->firstNode = node->nextNode;

			if (list->lastNode == node)
				list->lastNode = node->prevNode;

			if (list->current == node)
				list->current = node->nextNode != NULL ? node->nextNode : node->prevNode;

			list->count--;

			return node;
		}

		current = current->nextNode;
	}

	return NULL;
}


ListNode* List_RemoveAndReturnNext(List* list, ListNode* node)
{
	ListNode* removedNode;
	
	removedNode = List_Remove(list, node);

	if (removedNode != null)
	{
		removedNode = removedNode->nextNode;
	}

	return removedNode;
}

ListNode* List_RemoveAndReturnPrev(List* list, ListNode* node)
{
	ListNode* removedNode;
	
	removedNode = List_Remove(list, node);

	if (removedNode != null)
	{
		removedNode = removedNode->prevNode;
	}

	return removedNode;
}