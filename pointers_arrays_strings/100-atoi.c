#include "main.h"
#include <limits.h>

/**
 * _atoi - Convert a string to an integer.
 * @s: input C-string
 *
 * Behavior:
 * - Count ALL '+' and '-' that appear anywhere before the first digit.
 *   (odd number of '-' => negative; even => positive)
 * - Ignore other characters until the first digit.
 * - Read consecutive digits; stop at first non-digit after digits.
 * - If no digits, return 0.
 * - Accumulate in the negative domain to avoid -INT_MIN overflow.
 * - Overflow-safe with -fsanitize=signed-integer-overflow.
 *
 * Return: converted int value.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0; /* keep result non-positive during accumulation */

	/* 1) Scan prefix: flip sign for each '-' seen before first digit */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		/* '+' and any other char are ignored */
		i++;
	}

	/* 2) No digits? */
	if (s[i] == '\0')
		return (0);

	/* 3) Read digit run; build as negative: res = res*10 - d */
	while (s[i] >= '0' && s[i] <= '9')
	{
		int d = s[i] - '0';

		/* Check underflow before res = res*10 - d */
		/* If res < (INT_MIN + d) / 10, next step would go below INT_MIN */
		if (res < (INT_MIN + d) / 10)
		{
			/* Clamp to limits (optional, prevents UB with sanitizer) */
			return (sign == 1 ? INT_MAX : INT_MIN);
		}

		res = res * 10 - d;
		i++;
	}

	/* 4) Apply sign: res <= 0 here */
	if (sign == 1)
		return (-res);
	return (res);
}
