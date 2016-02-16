#include "tests.h"

void TestListAdd()
{
	int* val = malloc(sizeof(int));
	*val = (int)0;

	List* list = List_Init(val);

	for (int i = 1; i < 10; i++)
	{	
		val = malloc(sizeof(int));
		*val = i;
		List_AddAfterLast(list, val);
	}

	ListNode* current = list->firstNode;
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

void TestStringCompare()
{
	String* string1 = String_Init("string1");
	String* string2 = String_Init("string2");

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

void TestStringSubString()
{
	String* string = String_Init("this is my test string");
	String* subString =  String_Substring(string, 2, 2);

	String* expectedString = String_Init("is");
	
	if (String_Compare(subString, expectedString) == 0)
		printf("sub string works\n");
	else
		printf("sub string does not work\n");

	String_Delete(subString);
	String_Delete(expectedString);

	subString = String_Substring(string, 20, 4);
	expectedString = String_Init("ng");

	if (String_Compare(subString, expectedString) == 0)
		printf("sub string works\n");
	else
		printf("sub string does not work\n");

	String_Delete(subString);
	String_Delete(expectedString);

	String_Delete(string);
}