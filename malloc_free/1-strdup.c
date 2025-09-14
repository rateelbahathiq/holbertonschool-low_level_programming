#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated duplicate of a string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string,
 *         NULL if str == NULL or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];

	dup[len] = '\0';

	return (dup);
}
