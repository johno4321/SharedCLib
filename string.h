#pragma once
#include "common.h"

typedef struct
{
	char* buffer;
	uint32 length;
} String;

extern String* String_Init(char* value);
extern void String_Delete(String* string);

extern String* String_Append(String* string1, char* string2);
extern uint32 String_Length(char* value);
extern int16 String_Compare(String* string1, String* string2);
extern String* String_Substring(String* string, uint32 startIndex, uint32 count);
