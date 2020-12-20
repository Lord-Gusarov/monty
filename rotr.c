#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_number: ByteCode line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack), *temp2;
	(void)line_number;

	if (*stack && (*stack)->prev)
	{
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}
		temp2 = temp->next;
		temp->next = NULL;
		temp->prev = *stack;
		(*stack)->next = temp;
		temp2->prev = NULL;
		*stack = temp;
	}
}
