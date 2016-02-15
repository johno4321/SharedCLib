#pragma once

#include "common.h"

struct String
{
	char* buffer;
	int length;
};

extern struct String* String_Init(char* value);
extern int String_Length(char* value);
extern void String_Delete(struct String* string);
extern int String_Compare(struct String* string1, struct String* string2);
