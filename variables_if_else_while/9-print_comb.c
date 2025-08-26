#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers
 *
 * Description: Numbers are printed in ascending order, separated by
 * comma and space. Only putchar is used, at most 4 times in code.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0');
		if (n != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
