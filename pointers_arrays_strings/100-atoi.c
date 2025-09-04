#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value, or 0 if none
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	int res = 0;

	/* skip to first digit or sign block */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] >= '0' && s[i] <= '9')
			started = 1;
		if (!started)
			i++;
	}

	if (!started)
		return (0);

	/* build result with overflow guards */
	while (s[i] >= '0' && s[i] <= '9')
	{
		int d = s[i] - '0';

		if (sign == 1)
		{
			if (res > (INT_MAX - d) / 10)
				return (INT_MAX);
			res = res * 10 + d;
		}
		else
		{
			if (res < (INT_MIN + d) / 10)
				return (INT_MIN);
			res = res * 10 - d;
		}
		i++;
	}

	return (res);
}
