#include "list.h"

int main(int argc, char* argv[])
{
	int* val = (int *)1;
	struct List* list = InitList(val);

	for (int i = 0; i < 10; i++)
	{
		*val = i;
		AddAfterLastList(list, val);
	}
		
	struct ListNode* current = list->firstNode;
	int currentNodeValue = *(int *)current->data;

	while (current)
	{
		currentNodeValue = *(int *)current->data;
		
		printf("Data: %d Count: %d \n", currentNodeValue, list->count);
		
		current = RemoveAndReturnNextList(list, list->firstNode);
	}

	if (current != NULL)
		currentNodeValue = *(int *)current->data;
	else
		currentNodeValue = 0;

	printf("Data: %d Count: %d \n", currentNodeValue, list->count);

	DeleteList(list);

	if (list != NULL)
	{
		printf("List is not NULL");
	}

	return 0;
}