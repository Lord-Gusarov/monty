#include "monty.h"

build_t b = {NULL, NULL, NULL, NULL, STACK_MODE};

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
	unsigned int l_cnt = 0;
	size_t n = -1;
	ssize_t l_size;
	void (*funct)(stack_t **, unsigned int) = NULL;

	validate_args(agc, agv);

	while ((l_size = getline(&b.buf, &n, b.fd)) != EOF)
	{
		l_cnt++;
		b.tok = _strtok(b.buf, " \t\n");
		if (b.tok && b.tok[0][0] != '#')
		{
			funct = get_inst(b.tok[0]);
			if (!funct)
			{
				fprintf(stderr, "L%d: unknown instruction %s", l_cnt, b.tok[0]);
				close_stack(EXIT_FAILURE);
			}
			funct(&b.stack, l_cnt);
		}
		sfree(&b.buf);
		freeStrArr(b.tok);
		b.tok = NULL;
	}
	close_stack(0);
	return (0);
}


/**
 * validate_args - validates the arguments being passed to the program
 * at program start-up
 * @argc: count of arguments
 * @argv: Array of string with al arguments
 *
 * Description: Takes cares of validating the amount of arguments being passed,
 * and the validity of the file to open. If the count is right the file is open
 * and the stream set in the BUILD_T global var of the program. If arguments
 * are not righta an error mesaage is sent to 'stderr', memory check to be
 * cleared and and program exited with status EXIT_FAILURE
 */
void validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		close_stack(EXIT_FAILURE);
	}

	b.fd = fopen(argv[1], "r");
	if (!b.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		close_stack(EXIT_FAILURE);
	}
}

