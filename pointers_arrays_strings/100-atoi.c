#include "main.h"
#include <limits.h>

/**
 * _atoi - Convert a string to an integer.
 * @s: Pointer to the input string.
 *
 * Description:
 * This function converts a string into an integer by following these rules:
 * - All characters before the first digit are scanned.
 *   Every '-' sign flips the result sign, '+' is ignored.
 * - The number is built digit by digit until a non-digit is reached.
 * - If no digits are found, the function returns 0.
 * - The result is accumulated in the negative domain to avoid overflow
 *   when handling INT_MIN.
 * - Safe with -fsanitize=signed-integer-overflow.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0; /* keep result in non-positive form during accumulation */

	/* 1) Scan prefix: count '-' and '+' before the first digit */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;

		i++;
	}

	/* 2) If no digits are found */
	if (s[i] == '\0')
		return (0);

	/* 3) Read digit sequence */
	while (s[i] >= '0' && s[i] <= '9')
	{
		int d;

		d = s[i] - '0';

		/* Check underflow before applying: res = res * 10 - d */
		if (res < (INT_MIN + d) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}

		res = res * 10 - d;
		i++;
	}

	/* 4) Apply sign */
	if (sign == 1)
		return (-res);

	return (res);
}
