#include "queue.h"

Queue* Queue_Init()
{
	Queue* queue = malloc(sizeof(Queue));
	if (queue == NULL)
		return NULL;

	queue->count = 0;
	queue->head = NULL;
	queue->tail = NULL;

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
	if (queue == NULL)
		return NULL;

	if (queue->head == NULL)
		return NULL;

	//get the node to dequeue
	QueueNode* nodeToDequeue = queue->head;
	void* data = nodeToDequeue->data;

	//adjust the queue
	queue->head = nodeToDequeue->next;

	if (queue->head == NULL)
		queue->tail = NULL;

	free(nodeToDequeue);

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