#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string (must have enough space)
 * @src: Source string
 *
 * Return: Pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* Find end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Copy src into dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
