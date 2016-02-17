#pragma once
#include "list.h"

typedef struct tStackNode
{
	struct tStackNode* next;
	void* data;
} StackNode;

typedef struct Stack
{
	StackNode* top;
	uint32 count;
} Stack;

extern Stack* Stack_Init();

extern void Stack_Delete(Stack* stack);

extern void Stack_Push(Stack* stack, void* data);

extern void* Stack_Pop(Stack* stack);

extern uint32 Stack_Count(Stack* stack);

extern bool Stack_IsEmpty(Stack* stack);
