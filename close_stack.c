#include "monty.h"

/**
 * close_stack - Makes surs the build of the interpreter gets
 * closed/free, frees the node in the stacks and set the
 * appropiate exit status..
 * @str: string message.
 * Return: nothing.
 */
void close_stack(stack_t *stack, int status)
{
	if(b.fd)
		close(b.fd);
	if (b.tok)
		freeStrArr(b.tok);
	if(stack)
		free_stack(stack);
	exit(status);
}
