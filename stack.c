#include "stack.h"

Stack* Stack_Init()
{
	Stack* stack = malloc(sizeof(Stack));
	stack->count = 0;
	stack->top = null;
	
	return stack;
}

void Stack_Delete(Stack* stack)
{
	StackNode* current = stack->top;

	while (Stack_Pop(stack));
	
	free(stack);
	stack = null;
}

void Stack_Push(Stack* stack, void* data)
{
	StackNode* newTop = malloc(sizeof(StackNode));
	
	newTop->next = null;
	newTop->data = data;

	if (stack->count == 0)
	{
		stack->top = newTop;
	}
	else
	{
		newTop->next = stack->top;
		stack->top = newTop;
	}

	stack->count++;
}

void* Stack_Pop(Stack* stack)
{
	if (stack->count == 0)
		return null;

	void* rt = stack->top->data;
	
	StackNode* oldTop = stack->top;

	stack->top = stack->top->next;
	free(oldTop);

	stack->count--;

	return rt;
}

uint32 Stack_Count(Stack* stack)
{
	return stack->count;
}

bool Stack_IsEmpty(Stack* stack)
{
	return Stack_Count(stack) == 0;
}