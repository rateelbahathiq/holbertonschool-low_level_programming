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
	int res = 0; 

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;

		i++;
	}


	if (s[i] == '\0')
		return (0);

	
	while (s[i] >= '0' && s[i] <= '9')
	{
		int d;

		d = s[i] - '0';

	
		if (res < (INT_MIN + d) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}

		res = res * 10 - d;
		i++;
	}


	if (sign == 1)
		return (-res);

	return (res);
}
