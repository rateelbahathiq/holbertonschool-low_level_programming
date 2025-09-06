#include "main.h"
#include <limits.h>

/**
 * scan_sign_before_digits - Scan prefix and compute final sign.
 * @s: input string
 * @idx: out param: index of first digit or '\0' if none
 *
 * Return: +1 for positive, -1 for negative
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
 * accumulate_digits_neg - Parse digits using negative accumulation.
 * @s: input string
 * @i: starting index (must point at a digit)
 * @sign: final sign (+1 or -1)
 *
 * Return: parsed integer, clamped on overflow
 */
static int accumulate_digits_neg(char *s, int i, int sign)
{
	int res = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		int d;

		d = s[i] - '0';

		/* Check before: res = res * 10 - d */
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

/**
 * _atoi - Convert a string to an integer.
 * @s: pointer to input string
 *
 * Return: converted value, or 0 if no digits
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
