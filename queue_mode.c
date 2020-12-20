#include "monty.h"

/**
 * queue - set the format of the doubly linked data chain to QUEUE_MODE
 * @stack: ptr to front of stack
 * @line: ByteCode line number
 */
void queue(stack_t **stack, unsigned int line)
{
	(void)(stack);
	(void)(line);

	b.mode = QUEUE_MODE;
}
