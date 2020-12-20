#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_number: ByteCode line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		close_stack(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_stack(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	temp->n = temp->n / (*stack)->n;
	pop(stack, line_number);
}
