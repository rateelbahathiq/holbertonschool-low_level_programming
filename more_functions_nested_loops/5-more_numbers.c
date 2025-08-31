#include "main.h"

/**
 * more_numbers - Prints numbers 0 to 14, ten times
 *
 * Return: void
 */
void more_numbers(void)
{
	int line, num;

	for (line = 0; line < 10; line++)
	{
		for (num = 0; num <= 14; num++)
		{
			if (num > 9)
				_putchar((num / 10) + '0');
			_putchar((num % 10) + '0');
		}
		_putchar('\n');
	}
}
