#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer, or 0 if no digits are found.
 *
 * Rules implemented:
 * - Ignore everything until either:
 *     (a) a digit, or
 *     (b) a contiguous block of '+'/'-' immediately followed by a digit.
 * - Only the contiguous sign block directly before the number affects the sign
 *   (parity of '-' signs). Any signs separated by spaces/letters are ignored.
 * - Stop at the first non-digit after the number starts.
 * - Clamp on overflow/underflow (INT_MAX / INT_MIN).
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	int res = 0;

	/* Find the start: either a digit, or a sign block immediately before a digit */
	while (s[i] != '\0' && !started)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			int j = i, neg_parity = 0;

			while (s[j] == '+' || s[j] == '-')
			{
				if (s[j] == '-')
					neg_parity ^= 1; /* flip parity */
				j++;
			}

			if (s[j] >= '0' && s[j] <= '9')
			{
				sign = neg_parity ? -1 : 1;
				i = j;
				started = 1;
				break;
			}
			/* signs not followed by a digit -> ignore them and continue scanning */
			i = j;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			sign = 1;
			started = 1;
			break;
		}
		else
		{
			i++;
		}
	}

	if (!started)
		return (0);

	/* Accumulate with overflow-safe guards */
	if (sign == 1)
	{
		for (; s[i] >= '0' && s[i] <= '9'; i++)
		{
			int d = s[i] - '0';

			/* Guard: res*10 + d <= INT_MAX */
			if (res > INT_MAX / 10 ||
			    (res == INT_MAX / 10 && d > (INT_MAX % 10)))
				return (INT_MAX);

			res = res * 10 + d;
		}
		return (res);
	}
	else
	{
		/* Build as negative directly: res = res*10 - d (keeps INT_MIN representable) */
		for (; s[i] >= '0' && s[i] <= '9'; i++)
		{
			int d = s[i] - '0';
			int last = -(INT_MIN % 10); /* typically 8 on 32-bit two's complement */

			/* Guard: res*10 - d >= INT_MIN */
			if (res < INT_MIN / 10 ||
			    (res == INT_MIN / 10 && d > last))
				return (INT_MIN);

			res = res * 10 - d;
		}
		return (res);
	}
}
