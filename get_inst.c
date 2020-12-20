#include "monty.h"
/**
 * get_inst - returns the function related to the instruction.
 * @tok: instruction string.
 * Return: the appropiate function, or NULL if none found.
 */
void (*get_inst(char *tok))(stack_t **stack, unsigned int line)
{
	instruction_t arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
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
