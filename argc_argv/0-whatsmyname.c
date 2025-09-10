#include <stdio.h>

/**
 * main - Prints the program name, followed by a new line
 * @argc: Argument count (unused)
 * @argv: Argument vector (contains program name at index 0)
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
