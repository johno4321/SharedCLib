#include "string.h"

struct String* String_Init(char* value)
{
	int stringLength = String_Length(value);

	size_t stringMemoryLength = sizeof(char)* (stringLength + 1);
	struct String* string = malloc(sizeof(struct String));

	string->buffer = malloc(stringMemoryLength);

	memcpy(string->buffer, value, stringMemoryLength);

	string->length = stringLength;

	return string;
}

int String_Length(char* value)
{
	int length = 0;

	do
	{
		length++;
	} while (*(value + length) != (char)NULL);

	return length;
}

void String_Delete(struct String* string)
{
	free(string->buffer);
	string->buffer = NULL;

	free(string);
	string = NULL;
}

int String_Compare(struct String* string1, struct String* string2)
{
	if (string1 == NULL)
		return -1;
	else if (string2 == NULL)
		return 1;
	
	if (string1->length < string2->length)
		return 1;
	else if (string1->length > string2->length)
		return -1;

	char* string1Ptr = string1->buffer;
	char* string2Ptr = string2->buffer;
	
	while (*string1Ptr == *string2Ptr)
	{
		if (*string1Ptr == (char)NULL)
			return 0;

		string1Ptr++;
		string2Ptr++;
	}

	return *string1Ptr < *string2Ptr ? -1 : 1;
}