#include "monty.h"

/**
 * stack - set the format of the doubly linked data chain to STACK_MODE
 * @stack: ptr to front of stack
 * @line: ByteCode line number
 */
void stack(stack_t **stack, unsigned int line)
{
	(void)(stack);
	(void)(line);

	b.mode = STACK_MODE;
}
