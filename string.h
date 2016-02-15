#pragma once

#include "common.h"

struct String
{
	char* buffer;
	int length;
};

struct String* InitString(int initalLength)
{
	struct String* string = malloc(sizeof(struct String));

	string->buffer = malloc(sizeof(char)* initalLength);
	string->length = initalLength;
		
	return string;
}

void DeleteString(struct String* string)
{
	free(string->buffer);
	string->buffer = NULL;

	free(string);
	string = NULL;
}