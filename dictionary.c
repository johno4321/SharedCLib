#include "dictionary.h"

Dictionary* Dictionary_Init()
{
	Dictionary* dict = malloc(sizeof(Dictionary));
	dict->items = null;
	dict->count = 0;
	dict->maxKey = 0;
	return dict;
}

//TODO this is busted - fix it
void Dictionary_Delete(Dictionary* dictionary)
{
	free(dictionary);
	dictionary = null;
}

bool Dictionary_HasKey(Dictionary* dictionary, uint32 key)
{
	for (uint32 memoryWalker = 0; memoryWalker < dictionary->maxKey; memoryWalker++)
	{
		if ((DictionaryItem *)(dictionary->items[memoryWalker]) != null)
			return true;
	}

	return false;
}

bool Dictionary_Add(Dictionary* dictionary, uint32 key, void* data)
{
	//do we need to realloc?
	if (key > dictionary->maxKey)
	{
		dictionary->items = realloc(dictionary->items, sizeof(DictionaryItem) * key);
		DictionaryItem* item = (DictionaryItem *)(dictionary->items[key]);

		item->key = key;
		item->data = data;

		dictionary->maxKey = key;
		dictionary->count++;
		return true;
	}
	else if (!Dictionary_HasKey(dictionary, key))
	{
		DictionaryItem* item = (DictionaryItem *)(dictionary->items[key]);
		item->key = key;
		item->data = data;
		return true;
	}

	return false;
}

void* Dictionary_Get(Dictionary* dictionary, uint32 key)
{
	if (key > dictionary->maxKey)
	{
		return null;
	}

	return (DictionaryItem *)(dictionary->items[key]);
}

//TODO busted - need to think about how I copy out the return data value
void* Dictionary_Remove(Dictionary* dictionary, uint32 key)
{
	if (!Dictionary_HasKey(dictionary, key))
	{
		return null;
	}

	DictionaryItem* item = (DictionaryItem*)dictionary->items[key];

	item = null;

	void* dataRt = item->data;

	return dataRt;
}