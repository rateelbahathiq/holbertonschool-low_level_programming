#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: converted integer (0 if no digits)
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int res = 0;              /* build as NEGATIVE to avoid overflow */
	int cutoff = INT_MIN / 10;
	int limit = INT_MIN % 10; /* negative (e.g., -8) */

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

			/* Check overflow for: res = res * 10 - d */
			if (res < cutoff || (res == cutoff && -d < limit))
				return (sign == -1 ? INT_MIN : INT_MAX);

			res = res * 10 - d;
		}
		else if (started)
		{
			break;
		}
		i++;
	}

	/* If no digits were found, res remains 0 */
	if (sign == -1)
		return (res); /* already negative */

	/* Negating INT_MIN would overflow; clamp just in case */
	if (res == INT_MIN)
		return (INT_MAX);

	return (-res);
}
