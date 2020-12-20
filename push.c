#include "monty.h"

/**
 * push - adds an element to the stack.
 * @stack: pointer to the stack.
 * @l_cnt: line number.
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int l_cnt)
{
	stack_t *new = NULL, *trv = (*stack);

	if (isint(b.tok[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l_cnt);
		close_stack(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
		malloc_failed();

	new->n = atoi(b.tok[1]);
	new->next = NULL;
	new->prev = NULL;

	if (!*stack)
	{
		*stack = new;
		return;
	}

	if (b.mode == STACK_MODE)
	{
		new->prev = *stack;
		(*stack)->next = new;
		*stack = new;
	}
	else
	{
		while (trv->prev)
			trv = trv->prev;
		new->next = trv;
		trv->prev = new;
	}
}
