#include "monty.h"
/**
 * get_inst - returns the function related to the instruction.
 * @tok: instruction string.
 * Return: the appropiate function, or NULL if none found.
 */
void *get_inst(char *tok)
{
	instruction_t arr[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL},
	};
	int i = 0;
	while (arr[i].opcode != NULL)
	{
		if (strcmp(tok, arr[i].opcode) == 0)
			return (arr[i].f);
		i++;
	}
	return (NULL);
}
