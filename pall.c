#include "monty.h"
/**
 * pall - prints all the values on the stack, starting from the top.
 * @stack: pointer to the stack.
 * @line: the line number.
 * Return: nothing.
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%u\n", temp->n);
		temp = temp->prev;
	}
}
