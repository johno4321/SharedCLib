#pragma once

#include "common.h"

typedef struct
{
	char* buffer;
	int length;
} String;

extern String* String_Init(char* value);
extern void String_Delete(String* string);

extern int String_Length(char* value);
extern int String_Compare(String* string1, String* string2);
extern String* String_Substring(String* string, int startIndex, int count);
