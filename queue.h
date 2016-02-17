#pragma once
#include "common.h"

typedef struct tQueueNode
{
	struct tQueueNode* next;
	void* data;

} QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	uint32 count;

} Queue;

extern Queue* Queue_Init();
extern void Queue_Delete(Queue* queue);
extern void Queue_Enqueue(Queue* queue, void* data);
extern void* Queue_Dequeue(Queue* queue);
extern bool Queue_IsEmpty(Queue* queue);
extern uint32 Queue_Count(Queue* queue);
