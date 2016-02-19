#pragma once
#include "common.h"
#include "list.h"

typedef struct DictionaryItem
{
	uint32 key;
	void* data;

} DictionaryItem;

typedef struct Dictionary
{
	DictionaryItem* items;
	uint32 count;
	uint32 maxKey;

} Dictionary;

extern Dictionary* Dictionary_Init();
extern void Dictionary_Delete(Dictionary* dictionary);

extern bool Dictionary_HasKey(Dictionary* dictionary, uint32 key);
extern bool Dictionary_Add(Dictionary* dictionary, uint32 key, void* data);
extern void* Dictionary_Get(Dictionary* dictionary, uint32 key);
extern void* Dictionary_Remove(Dictionary* dictionary, uint32 key);