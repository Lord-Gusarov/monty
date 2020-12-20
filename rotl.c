#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: ByteCode line
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack), *temp2;
	(void)line_number;

	if (*stack && (*stack)->prev)
	{
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}
		temp2 = (*stack)->prev;
		temp2->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = temp;
		temp->prev = *stack;
		*stack = temp2;
	}
}
