#include "monty.h"
/**
 * _strtok - splits a string into words/tokens
 * @str: string to be splitted
 * @delims: set of char that can separate aword/token
 *
 * Return: The function returns a pointer to an array of strings (words)
 * NULL if str == NULL or str == ""
 */
char **_strtok(char *str, char *delims)
{
	char **m = NULL;
	int i, ii, w_idx = 0, wl = 0, wc = 0;

	if (str == NULL || str == '\0') /*keep eye out for last comparison*/
		return (NULL);
	wc = _wc(str, delims);
	if (wc > 0)
		m = malloc(sizeof(char *) * (wc + 1));
	if (m == NULL)
		return (NULL);
	m[wc] = NULL;
	for (i = 0; str[i] != '\0'; wl = 0)
	{
		while (str[i] != '\0' && strHasChar(delims, str[i]))
			i++;
		while (str[i] != '\0' && !strHasChar(delims, str[i]))
		{
			wl++, i++;
		}
		if (wl > 0)
		{
			m[w_idx] = malloc(sizeof(char) * (wl + 1));
			if (m[w_idx] == NULL)
			{
				while (w_idx > 0)
					free(m[--w_idx]);
				free(m);
				return (NULL);
			}
			m[w_idx][wl] = '\0';
			for (ii = 0; ii < wl; ii++)
				m[w_idx][ii] = str[i - (wl - ii)];
			w_idx++;
		}
	}

	return (m);
}
