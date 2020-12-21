#include "monty.h"

/**
 * isint - determine if a string is composed only
 * of decimal digits
 * @str: string to check
 * Return: 1 if just digits, 0 otherwise
 */
int isint(char *str)
{
	if (str == NULL)
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
