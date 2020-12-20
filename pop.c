#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the stack.
 * @line: line number.
 * Return: nothing.
 **/
void pop(stack_t **stack, unsigned int line)
{
	stack_t *temp = (*stack);

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		close_stack(EXIT_FAILURE);
	}
	if (temp->prev == NULL)
	{
		free(temp);
		*stack = NULL;
	}
	else
	{
		temp->prev->next = NULL;
		*stack = temp->prev;
		free(temp);
	}
}
