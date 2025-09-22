#include <stdlib.h>
#include "3-calc.h"

/* Provided by checker; declared in function_pointers project */
int _putchar(char c);

/**
 * print_str - prints a C-string using _putchar
 * @s: string to print
 *
 * Return: Nothing.
 */
static void print_str(const char *s)
{
	int i = 0;

	if (!s)
		return;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _atoi_simple - converts a string to int (handles optional +/- and digits)
 * @s: string to convert
 *
 * Return: converted integer (undefined on overflow, as usual for simple atoi)
 */
static int _atoi_simple(char *s)
{
	int sign = 1;
	int num = 0;

	while (*s == ' ' || *s == '\t' || *s == '\n' ||
	       *s == '\v' || *s == '\f' || *s == '\r')
		s++;

	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}

	return (sign * num);
}

/**
 * print_int - prints an integer using _putchar
 * @n: integer to print
 *
 * Return: Nothing.
 */
static void print_int(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		x = (unsigned int)(-n);
	}
	else
	{
		x = (unsigned int)n;
	}

	if (x / 10)
		print_int((int)(x / 10));
	_putchar((x % 10) + '0');
}

/**
 * main - simple calculator
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with error code
 */
int main(int argc, char *argv[])
{
	int a, b, res;
	int (*op)(int, int);

	if (argc != 4)
	{
		print_str("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);
	if (op == 0)
	{
		print_str("Error\n");
		exit(99);
	}

	a = _atoi_simple(argv[1]);
	b = _atoi_simple(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		print_str("Error\n");
		exit(100);
	}

	res = op(a, b);
	print_int(res);
	_putchar('\n');

	return (0);
}
