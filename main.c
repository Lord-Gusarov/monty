#include "monty.h"

/**
 * main - runs the Monty ByteCodes interpreter
 * @agc: count of arguments passed to the program
 * @agv: array of strings, where each string is an argument
 * passed to the program
 *
 * Return: 0 if no errors
 */
int main(int agc, char **agv)
{
	unsigned int l_cnt = 1;
	size_t n = -1;
	char *buf = NULL, **tok;
	FILE *fd;
	ssize_t l_size;
	stack_t *stack = NULL;
	void (*funct)(stack_t **, unsigned int) = NULL;

	
	if (agc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		close_stack(stack, EXIT_FAILURE);
	}

	fd = fopen(agv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", agv[1]);
		close_stack(stack, EXIT_FAILURE);
	}
	l_size = getline(&buf, &n, fd);

	while (l_size != EOF)
	{
		tok = _strtok(buf, " \t\n");
		if(tok)
		{
			if (strcmp(tok[0],"push") == 0)
				push(&stack, l_cnt, tok[1]);
			else
			{
				funct = get_inst(tok[0]);
				if (!funct)
				{
					fprintf(stderr, "L%d: unknown instruction %s", l_cnt, tok[0]);
					close_stack(stack, EXIT_FAILURE);
				}
				funct(&stack, l_cnt);
			}
		}
		l_size = getline(&buf, &n, fd);
	}
	printf("s1 : %d\ns2 : %d\n", stack->n, stack->prev->n);

	close_stack(stack, 0);
}
