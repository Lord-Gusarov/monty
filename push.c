#include "monty.h"

/**
 * push - adds an element to the stack.
 * @tok: element to be added.
 * @stack: pointer to the stack.
 * @l_cnt: line number.
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int l_cnt)
{
	stack_t *new = NULL;

	if (isint(b.tok[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_cnt);
		close_stack(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		close_stack(EXIT_FAILURE);
	}

	new->n = atoi(b.tok[1]);
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}
	new->prev = *stack;
	(*stack)->next = new;
	*stack = new;
	return;
}
