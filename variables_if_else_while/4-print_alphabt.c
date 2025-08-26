#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase except q and e
 *
 * Description: Uses putchar to print all lowercase letters
 * except 'q' and 'e', followed by a newline.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		if (ch != 'e' && ch != 'q')
		{
			putchar(ch);
		}
	}
	putchar('\n');
	return (0);
}
