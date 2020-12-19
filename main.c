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
	stack_t *stack = NULL;
	unsigned int l_cnt = 1;
	size_t n = -1;
	char *buf = NULL;
	ssize_t l_size;
	void (*funct)(stack_t **, unsigned int) = NULL;
	build_t b = {NULL, NULL, STACK_MODE};

	if (agc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		close_stack(stack, EXIT_FAILURE);
	}

	b.fd = fopen(agv[1], "r");
	if (!b.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", agv[1]);
		close_stack(stack, EXIT_FAILURE);
	}
	l_size = getline(&buf, &n, b.fd);

	while (l_size != EOF)
	{
		b.tok = _strtok(buf, " \t\n");
		if(b.tok)
		{
			if (strcmp(b.tok[0],"push") == 0)
				push(&stack, l_cnt, b.tok[1]);
			else
			{
				funct = get_inst(b.tok[0]);
				if (!funct)
				{
					fprintf(stderr, "L%d: unknown instruction %s", l_cnt, b.tok[0]);
					close_stack(stack, EXIT_FAILURE);
				}
				funct(&stack, l_cnt);
			}
		}
		freeStrArr(b.tok);
		sfree(&buf);
		l_size = getline(&buf, &n, b.fd);
	}

	close_stack(stack, 0);
}
