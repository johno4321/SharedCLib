#include "tests.h"

void TestList()
{
	int* val = malloc(sizeof(int));
	*val = (int)0;

	struct List* list = List_Init(val);

	for (int i = 1; i < 10; i++)
	{	
		val = malloc(sizeof(int));
		*val = i;
		List_AddAfterLast(list, val);
	}

	struct ListNode* current = list->firstNode;
	int currentNodeValue = *(int *)current->data;

	while (current)
	{
		currentNodeValue = *(int *)current->data;

		printf("Data: %d Count: %d \n", currentNodeValue, list->count);

		current = List_RemoveAndReturnNext(list, list->firstNode);
	}

	if (current != NULL)
		currentNodeValue = *(int *)current->data;
	else
		currentNodeValue = 0;

	printf("Data: %d Count: %d \n", currentNodeValue, list->count);

	List_Delete(list);

	if (list != NULL)
	{
		printf("List is not NULL\n");
	}
}

void TestString()
{
	struct String* string1 = String_Init("string1");
	struct String* string2 = String_Init("string2");

	int rt = String_Compare(string1, string2);

	String_Delete(string1);
	String_Delete(string2);

	printf("String compare return is %d\n", rt);

	string1 = String_Init("this is string1");
	string2 = String_Init("this is string1");

	rt = String_Compare(string1, string2);

	printf("String compare return is %d\n", rt);

	String_Delete(string1);
	String_Delete(string2);
}