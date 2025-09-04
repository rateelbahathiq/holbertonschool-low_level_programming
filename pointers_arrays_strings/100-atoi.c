#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if no digits found.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	int res = 0;

	/* Scan prefix: count +/- and look for first digit */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
			; /* ignore */
		else if (s[i] >= '0' && s[i] <= '9')
			started = 1; /* first digit found */
		if (!started)
			i++;
	}

	if (!started)
		return (0);

	/* Accumulate with overflow-safe checks */
	if (sign == 1)
	{
		/* Build a non-negative number: res = res*10 + d */
		for (; s[i] >= '0' && s[i] <= '9'; i++)
		{
			int d = s[i] - '0';

			/* Guard: res*10 + d <= INT_MAX */
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && d > INT_MAX % 10))
				return (INT_MAX);

			res = res * 10 + d;
		}
		return (res);
	}
	else
	{
		/* Build a negative number directly: res = res*10 - d */
		for (; s[i] >= '0' && s[i] <= '9'; i++)
		{
			int d = s[i] - '0';

			/* Guard: res*10 - d >= INT_MIN */
			if (res < INT_MIN / 10 || (res == INT_MIN / 10 && d > -(INT_MIN % 10)))
				return (INT_MIN);

			res = res * 10 - d;
		}
		return (res);
	}
}
