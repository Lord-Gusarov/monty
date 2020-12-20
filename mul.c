#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @stack: stack from which to multiply
 * @line_number: ByteCode line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		close_stack(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	temp->n *= (*stack)->n;
	pop(stack, line_number);
}
