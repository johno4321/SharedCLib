#include "string.h"

uint32 String_CalculateLength(char* value)
{
	uint32 length = 0;

	do
	{
		length++;
	} while (*(value + length) != STRING_END);

	return length;
}

String* String_Init(char* value)
{
	uint32 stringLength;

	String* string;

	stringLength = String_CalculateLength(value);
	string = malloc(sizeof(String));

	size_t stringMemoryLength = sizeof(char) * (stringLength + 1);
	string->buffer = malloc(stringMemoryLength);

	for (uint32 i = 0; i < stringLength; i++)
	{
		*(string->buffer + i) = *(value + i);
	}

	*(string->buffer + stringLength) = STRING_END;

	string->length = stringLength;

	return string;
}

void String_Delete(String* string)
{
	free(string->buffer);
	string->buffer = NULL;

	free(string);
	string = NULL;
}

int16 String_Compare(String* string1, String* string2)
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
		if (*string1Ptr == STRING_END)
			return 0;

		string1Ptr++;
		string2Ptr++;
	}

	return *string1Ptr < *string2Ptr ? -1 : 1;
}

//Returns a substring from the string passed in
//TODO this needs to be more defensive
String* String_Substring(String* string, uint32 startIndex, uint32 count)
{
	char* subString = NULL;

	//if startIndex exceeds the length of the input string return NULL
	if (startIndex > string->length)
	{
		return NULL;
	}

	//work out the length of the string the user wants us to return
	int subStringLength = count;

	//fix the count parm if required - don't want to overflow the buffer - only return as much as we can
	if (startIndex + count > string->length)
	{
		subStringLength = string->length - startIndex;
	}

	//create the sub string
	subString = malloc(sizeof(char) * (subStringLength + 1));
	
	for (int index = 0; index < subStringLength; index++)
	{
		*(subString + index) = *(string->buffer + startIndex + index);
	}

	*(subString + subStringLength) = STRING_END;

	String* rtString = String_Init(subString);

	free(subString);

	return rtString;
}