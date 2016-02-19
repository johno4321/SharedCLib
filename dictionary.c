#include "dictionary.h"

Dictionary* Dictionary_Init()
{
	Dictionary* dict = (Dictionary *)malloc(sizeof(Dictionary));
	dict->items = (DictionaryItem *)malloc(sizeof(DictionaryItem) * 1);
	
	((DictionaryItem *)dict->items)->key = 0;
	((DictionaryItem *)dict->items)->data = null;

	dict->count = 0;
	dict->maxKey = 0;
	return dict;
}

void Dictionary_Delete(Dictionary* dictionary)
{
	free(dictionary->items);
	free(dictionary);
	dictionary = null;
}

bool Dictionary_HasKey(Dictionary* dictionary, uint32 key)
{
	if (dictionary->maxKey < key)
		return false;

	if ((DictionaryItem *)(dictionary->items + key)->data == null)
		return false;

	return true;
}

bool Dictionary_Add(Dictionary* dictionary, uint32 key, void* data)
{
	//do we need to realloc?
	if (key > dictionary->maxKey)
	{
		DictionaryItem* newItems = (DictionaryItem *)malloc(sizeof(DictionaryItem) * (key + 1));

		for (uint32 memoryWalker = 0; memoryWalker <= dictionary->maxKey; memoryWalker++)
		{
			((DictionaryItem *)(newItems + memoryWalker))->key = memoryWalker;
			((DictionaryItem *)(newItems + memoryWalker))->data = ((DictionaryItem *)(dictionary->items + memoryWalker))->data;
		}

		for (uint32 memoryWalker = dictionary->maxKey + 1; memoryWalker < key; memoryWalker++)
		{
			((DictionaryItem *)(newItems + memoryWalker))->key = memoryWalker;
			((DictionaryItem *)(newItems + memoryWalker))->data = null;
		}

		((DictionaryItem *)(newItems + key))->key = key;
		((DictionaryItem *)(newItems + key))->data = data;

		free(dictionary->items);
		dictionary->items = newItems;

		dictionary->maxKey = key;
		dictionary->count++;
		return true;
	}
	else if (!Dictionary_HasKey(dictionary, key))
	{
		DictionaryItem* item = (DictionaryItem *)(dictionary->items + key);
		item->key = key;
		item->data = data;
		dictionary->count++;
		return true;
	}

	return false;
}

void* Dictionary_Get(Dictionary* dictionary, uint32 key)
{
	if (key > dictionary->maxKey)
		return null;
	else if (Dictionary_HasKey(dictionary, key))
		return (DictionaryItem *)(dictionary->items + key)->data;
	else
		return null;
}

//TODO busted - need to think about how I copy out the return data value
void* Dictionary_Remove(Dictionary* dictionary, uint32 key)
{
	DictionaryItem* item;

	if (!Dictionary_HasKey(dictionary, key))
		return null;
	
	item = (DictionaryItem *)(dictionary->items + key);

	void* dataRt = item->data;
	item->data = null;
	return dataRt;
}