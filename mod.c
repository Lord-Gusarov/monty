#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of the stack by
 * the top element of the stack
 * @stack: pointer to the stack
 * @line_number: ByteCode line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		close_stack(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_stack(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	temp->n = temp->n % (*stack)->n;
	pop(stack, line_number);
}
