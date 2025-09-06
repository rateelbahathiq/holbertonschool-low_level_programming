#include "main.h"
#include <limits.h>

/**
 * _atoi - Convert a string to an integer.
 * @s: input C-string
 *
 * Behavior:
 * - Count all '+' and '-' before the first digit (odd '-' => negative).
 * - Ignore other chars until digits; read consecutive digits only.
 * - Return 0 if no digits.
 * - Accumulate in negative domain to avoid -INT_MIN overflow.
 * - Overflow-safe under -fsanitize=signed-integer-overflow.
 *
 * Return: converted int value.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int res = 0; /* keep result non-positive during accumulation */

	/* 1) Scan prefix: flip sign on each '-' before first digit */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		/* '+' and other chars are ignored */
		i++;
	}

	/* 2) No digits? */
	if (s[i] == '\0')
		return (0);

	/* 3) Read digit run; build as negative: res = res*10 - d */
	while (s[i] >= '0' && s[i] <= '9')
	{
		int d;              /* <-- declaration only */
		d = s[i] - '0';     /* <-- indexing moved to a separate statement */

		/* Check underflow before res = res*10 - d */
		if (res < (INT_MIN + d) / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);

		res = res * 10 - d;
		i++;
	}

	/* 4) Apply sign */
	if (sign == 1)
		return (-res);
	return (res);
}
