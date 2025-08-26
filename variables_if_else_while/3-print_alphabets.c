#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, then uppercase
 *
 * Description: Uses putchar to print all lowercase letters
 * followed by uppercase letters, and a newline.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
	return (0);
}
