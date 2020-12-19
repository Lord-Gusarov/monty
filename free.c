#include "monty.h"

/**
 * sfree - safely frees a string that was dinamically allocated
 * @toFree: string to be sfaely freed by checking if referencing to NULL first
 */
void sfree(char **toFree)
{
	if (toFree != NULL && *toFree != NULL)
	{
		free(*toFree);
		*toFree = NULL;
	}
}

/**
 * freeStrArr - Safely frees  an array of srings
 * @array: array to be freed
 * All frees are checked first for NULL
 */
void freeStrArr(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	while (array[i] != NULL)
	{
		sfree(&array[i]);
		i++;
	}
	free(array);
}

/**
 * free_stack - frees the all the linked data in a stack_t
 * doubly linked list
 * @stack: ptr to front of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->prev;
		free(stack);
		stack = tmp;
	}
}

