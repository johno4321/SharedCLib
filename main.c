#include "list.h"

int main(int argc, char* argv[])
{
	int i1 = 1;
	int i2 = 2;
	int i3 = 3;
	int i4 = 4;
	int i5 = 5;
	int i6 = 6;
	int i7 = 7;

	struct List* list;

	list = l_init(&i1);

	l_addAfterLast(list, &i2);
	l_addAfterLast(list, &i3);
	l_addAfterLast(list, &i4);
	l_addAfterLast(list, &i5);
	l_addAfterLast(list, &i6);
	l_addAfterLast(list, &i7);
	
	l_remove(list, list->firstNode);
	l_remove(list, list->lastNode);
		
	struct ListNode* current = list->firstNode;

	while (1)
	{
		int val = *(int *)current->data;

		printf("%d\n", val);
		
		current = current->nextNode;

		if (current == NULL)
			break;
	}

	l_delete(list);

	if (list != NULL)
	{
		printf("List is not NULL");
	}

	return 0;
}