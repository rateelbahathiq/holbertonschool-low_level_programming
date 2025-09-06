#include "main.h"
#include <limits.h>

/**
 * scan_sign_before_digits - Scan prefix and compute final sign.
 * @s: Input string.
 * @idx: Out param; set to index of first digit or '\0' if none.
 *
 * Description:
 * Iterates over all chars before the first digit. Each '-' flips the sign;
 * '+' is ignored; other chars are ignored. Sets *idx to the position of the
 * first digit or to the string terminator if no digit exists.
 *
 * Return: +1 if result should be positive, -1 if negative.
 */
static int scan_sign_before_digits(char *s, int *idx)
{
	int i = 0;
	int sign = 1;

	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;

		i++;
	}

	*idx = i;

	return (sign);
}

/**
 * accumulate_digits_neg - Parse digits starting at index using neg accumulation.
 * @s: Input string.
 * @i: Starting index (must point at a digit).
 * @sign: Final sign (+1 or -1).
 *
 * Description:
 * Accumulates the value in the negative domain: res = res * 10 - d.
 * Checks for overflow/underflow before each step using INT_MIN only.
 *
 * Return: The parsed integer (clamped to INT_MIN/INT_MAX on overflow).
 */
static int accumulate_digits_neg(char *s, int i, int sign)
{
	int res = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		int d;

		d = s[i] - '0';

		/* Check: if res*10 - d would be < INT_MIN, clamp */
		if (res < (INT_MIN + d) / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);

		res = res * 10 - d;
		i++;
	}

	if (sign == 1)
		return (-res);

	return (res);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: Pointer to the input string.
 *
 * Return:
 * The converted integer. If no digits are found, returns 0.
 *
 * Notes:
 * - Counts all '-' and '+' before the first digit (odd '-' => negative).
 * - Ignores other characters before digits; stops after digit run.
 * - No arrays, no long; safe with -fsanitize=signed-integer-overflow.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;

	sign = scan_sign_before_digits(s, &i);

	if (s[i] == '\0')
		return (0);

	return (accumulate_digits_neg(s, i, sign));
}
