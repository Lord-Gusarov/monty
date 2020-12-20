#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack from which to swap
 * @line_number: ByteCode line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack), *temp2;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		close_stack(EXIT_FAILURE);
	}
	temp2 = (*stack)->prev;
	if (temp2->prev == NULL)
	{
		temp2->prev = temp;
		temp2->next = NULL;
		temp->prev = NULL;
		temp->next = temp2;
		(*stack) = temp2;
	}
	else
	{
		temp2->prev->next = temp;
		temp->prev = temp2->prev;
		temp->next = temp2;
		temp2->prev = temp;
		temp2->next = NULL;
		(*stack) = temp2;
	}
}
