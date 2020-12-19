#include "monty.h"
/**
 * pall - prints all the values on the stack, starting from the top.
 * @stack: pointer to the stack.
 * @line: the line number.
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *temp = *stack;

	while(*temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return;
}
