#include "monty.h"
/**
 * pstr - prints the string (char by char) starting at the top of the stack,
 * followed by a new line
 * @stack: pointer to the stack
 * @line: ByteCode line number
 **/
void pstr(stack_t **stack, unsigned int line)
{
	int n;
	stack_t *tmp = *stack;

	(void)(line);

	if (*stack)
	{
		while (tmp)
		{
			n = tmp->n;
			if (n <= 0 || n > 127)
				break;
			printf("%c", n);
			tmp = tmp->prev;
		}
	}
	printf("n");
}
