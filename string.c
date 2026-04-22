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
	if (value == NULL)
		return NULL;

	uint32 stringLength = String_CalculateLength(value);
	String* string = malloc(sizeof(String));

	if (string == NULL)
		return NULL;

	size_t stringMemoryLength = sizeof(char) * (stringLength + 1);
	string->buffer = malloc(stringMemoryLength);

	if (string->buffer == NULL)
	{
		free(string);
		return NULL;
	}

	for (uint32 i = 0; i < stringLength; i++)
		*(string->buffer + i) = *(value + i);

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

String* String_Append(String* string1, char* string2)
{
	if (string1 == NULL || string2 == NULL)
		return NULL;

	uint32 string2Length = String_CalculateLength(string2);
	uint32 totalLength = string1->length + string2Length;
	char* buffer = malloc(sizeof(char) * (totalLength + 1));

	if (buffer == NULL)
		return NULL;

	for (uint32 i = 0; i < string1->length; i++)
	{
		*(buffer + i) = *(string1->buffer + i);
	}

	for (uint32 i = 0; i < string2Length; i++)
	{
		*(buffer + string1->length + i) = *(string2 + i);
	}

	*(buffer + totalLength) = STRING_END;
	
	String_Delete(string1);

	String* result = String_Init(buffer);
	free(buffer);
	return result;
}

uint32 String_Length(char* value)
{
	if (value == NULL)
		return 0;
	return String_CalculateLength(value);
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
	if (string == NULL)
		return NULL;

	char* subString = NULL;

	//if startIndex exceeds the length of the input string return NULL
	if (startIndex > string->length)
	{
		return NULL;
	}

	//work out the length of the string the user wants us to return
	uint32 subStringLength = count;

	//fix the count parm if required - don't want to overflow the buffer - only return as much as we can
	if (startIndex + count > string->length)
	{
		subStringLength = string->length - startIndex;
	}

	//create the sub string
	subString = malloc(sizeof(char) * (subStringLength + 1));
	
	for (uint32 index = 0; index < subStringLength; index++)
	{
		*(subString + index) = *(string->buffer + startIndex + index);
	}

	*(subString + subStringLength) = STRING_END;

	String* rtString = String_Init(subString);

	free(subString);

	return rtString;
}