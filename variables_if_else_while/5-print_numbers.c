#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10
 *
 * Description: Uses printf to print digits from 0 to 9
 * followed by a newline.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
		printf("%d", n);
	}
	printf("\n");
	return (0);
}
