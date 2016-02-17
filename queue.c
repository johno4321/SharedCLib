#include "queue.h"

Queue* Queue_Init()
{
	Queue* queue = malloc(sizeof(Queue));
	queue->count = 0;
	
	queue->head = null;
	queue->tail = null;

	return queue;
}

void Queue_Delete(Queue* queue)
{
	while (Queue_Dequeue(queue));
	
	queue->head = null;
	queue->tail = null;

	free(queue);
	queue = null;
}

void Queue_Enqueue(Queue* queue, void* data)
{
	QueueNode* newTail = malloc(sizeof(QueueNode));
	
	newTail->data = data;
	newTail->next = null;

	//are there any elements in the queue?
	if (queue->head == null)
	{
		queue->head = newTail;
		queue->tail = newTail;
	}
	else
	{ 
		queue->tail->next = newTail;
		queue->tail = newTail;
	}

	queue->count++;
}

void* Queue_Dequeue(Queue* queue)
{
	if (queue == null)
	{
		return null;
	}

	if (queue->head == null)
	{
		return null;
	}

	//get the node to dequeue
	QueueNode* nodeToDequeue = queue->head;
	void* data = nodeToDequeue->data;

	//adjust the queue
	queue->head = nodeToDequeue->next;

	if (queue->head == null)
	{
		queue->tail = null;
	}

	free(nodeToDequeue);
	nodeToDequeue = null;

	queue->count--;
	return data;
}

bool Queue_IsEmpty(Queue* queue)
{
	return Queue_Count(queue) == 0;
}

uint32 Queue_Count(Queue* queue)
{
	return queue->count;
}