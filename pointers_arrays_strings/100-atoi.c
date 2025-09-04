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

	/* scan until the first digit; count leading '-' signs */
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

	/* accumulate with overflow-safe guards */
	if (sign == 1)
	{
		for (; s[i] >= '0' && s[i] <= '9'; i++)
		{
			int d = s[i] - '0';

			/* ensure res*10 + d <= INT_MAX */
			if (res > INT_MAX / 10 ||
			    (res == INT_MAX / 10 && d > (INT_MAX % 10)))
				return (INT_MAX);

			res = res * 10 + d;
		}
		return (res);
	}
	else
	{
		/* keep result negative to represent INT_MIN safely */
		for (; s[i] >= '0' && s[i] <= '9'; i++)
		{
			int d = s[i] - '0';
			int last = -(INT_MIN % 10); /* boundary digit for INT_MIN */

			/* ensure res*10 - d >= INT_MIN */
			if (res < INT_MIN / 10 ||
			    (res == INT_MIN / 10 && d > last))
				return (INT_MIN);

			res = res * 10 - d;
		}
		return (res);
	}
}
