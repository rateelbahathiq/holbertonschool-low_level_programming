#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char tmp;

	/* find length */
	while (s[j] != '\0')
		j++;

	/* swap characters from start and end */
	for (i = 0, j = j - 1; i < j; i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
