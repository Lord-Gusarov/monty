#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the stack.
 * @line: line number.
 * Return: nothing.
 **/
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		close_stack(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
