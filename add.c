#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: stack from which to add
 * @line_number: ByteCode line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->prev;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		close_stack(*stack, EXIT_FAILURE);
	}
	(*stack)->n += temp->n;
	if (temp->prev == NULL)
	{
		free(temp);
		(*stack)->prev = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		(*stack)->prev = temp->prev;
		free(temp);
	}
	return;
}
