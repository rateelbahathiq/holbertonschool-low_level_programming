#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: converted integer value, or 0 if no digits are found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int res = 0;            /* accumulate as NEGATIVE to avoid overflow */
	int cutoff = INT_MIN / 10;
	int limit = INT_MIN % 10;   /* negative (e.g., -8) */

	while (s[i] != '\0')
	{
		if (!started && (s[i] == '+' || s[i] == '-'))
		{
			if (s[i] == '-')
				sign = -sign;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int d = s[i] - '0';

			started = 1;

			/* Check would-be overflow for: res = res * 10 - d */
			if (res < cutoff || (res == cutoff && -d < limit))
			{
				return (sign == -1) ? INT_MIN : INT_MAX;
			}

			res = res * 10 - d;
		}
		else if (started)
		{
			break;
		}
		i++;
	}

	if (sign == -1)
		return (res);        /* already negative */

	if (res == INT_MIN)      /* negating INT_MIN would overflow */
		return (INT_MAX);

	return (-res);
}
