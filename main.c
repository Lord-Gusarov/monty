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
	int l_cnt = 1;
	char *buf = NULL, **tok;
	FILE *fp;
	ssize_t l_size;

	if (agc != 2)
		error("USAGE: monty file\n");

	fd = fopen(agv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", agv[1]);
		error("hey");
	}
	l_size = getline(&buf, &line_buf_size, fd);

	while (line_size != EOF)
	{
		tok = _strtok(buf, " \t\n");
		if (tok[0] == "push")
			push(stack, l_cnt, tok[1]);
		funct = get_inst(tok[0]);
		if (!funct)
		{
			fprint(stderr, "L%d: unknown instruction %s", l_cnt, tok[0]);
			quit_error();
		}

		funct(&stack, l_cnt);

		l_size = getline(&line_buf, &line_buf_size, fd);
	}

	close_stack(stack, 0);
}
