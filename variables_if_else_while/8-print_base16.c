#include <stdio.h>

/**
 * main - Prints all the numbers of base 16 in lowercase
 *
 * Description: Uses putchar to print digits 0–9 and
 * letters a–f, followed by a newline.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char ch;

	for (n = 0; n < 10; n++)
	{
		putchar(n + '0');
	}
	for (ch = 'a'; ch <= 'f'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
