#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: the integer value of the string, or 0 if none
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int found_digit = 0;

	/* skip non-digit characters, track sign */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found_digit = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (found_digit)
			break;
		i++;
	}

	return (sign * num);
}
