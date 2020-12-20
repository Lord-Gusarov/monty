#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the stack
 * @line: line number
 * Return: nothing
 **/
void pchar(stack_t **stack, unsigned int line)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		close_stack(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		close_stack(EXIT_FAILURE);
	}
	printf("%c\n", n);
}
