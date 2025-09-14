#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars and initializes it with a char
 * @size: number of elements to allocate
 * @c: character used to initialize the array
 *
 * Return: pointer to the new array, or NULL if size == 0 or malloc fails
 */
char *create_array(unsigned int size, char c)
{
	char *buf;
	unsigned int i;

	if (size == 0)
		return (NULL);

	buf = malloc(size * sizeof(char));
	if (buf == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		buf[i] = c;

	return (buf);
}
