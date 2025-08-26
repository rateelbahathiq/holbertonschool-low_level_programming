#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10
 *
 * Description: Uses putchar to print digits from 0 to 9
 * without using char type variables.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
		putchar(n + '0');
	}
	putchar('\n');
	return (0);
}
