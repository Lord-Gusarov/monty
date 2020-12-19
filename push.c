#include "monty.h"

/**
 * push - adds an element to the stack.
 * @tok: element to be added.
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int l_cnt, char *tok)
{
	stack_t *new = NULL;

	if (isint(tok) == 0)
		close_stack(*stack, EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		close_stack(*stack, EXIT_FAILURE);
	}

	
	new->n = atoi(tok);
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
