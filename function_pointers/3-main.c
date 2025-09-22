#include <stdlib.h>
#include "3-calc.h"

/* Provided by checker */
int _putchar(char c);

/**
 * main - simple calculator
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with error code
 *         98 (wrong arg count), 99 (unknown op), 100 (div by zero)
 */
int main(int argc, char *argv[])
{
	int a = 0, b = 0, res, sign, i;
	unsigned int ux;
	int (*op)(int, int);
	char *p;

	/* print "Error\n" helper (inline) */
#define PRINT_ERROR() do { \
		_putchar('E'); _putchar('r'); _putchar('r'); _putchar('o'); \
		_putchar('r'); _putchar('\n'); \
	} while (0)

	if (argc != 4)
	{
		PRINT_ERROR();
		exit(98);
	}

	op = get_op_func(argv[2]);
	if (op == 0)
	{
		PRINT_ERROR();
		exit(99);
	}

	/* atoi for argv[1] (inline, no extra function symbols) */
	p = argv[1];
	while (*p == ' ' || *p == '\t' || *p == '\n' ||
	       *p == '\v' || *p == '\f' || *p == '\r')
		p++;
	sign = 1;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		a = (a * 10) + (*p - '0');
		p++;
	}
	a *= sign;

	/* atoi for argv[3] */
	p = argv[3];
	while (*p == ' ' || *p == '\t' || *p == '\n' ||
	       *p == '\v' || *p == '\f' || *p == '\r')
		p++;
	sign = 1;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		b = (b * 10) + (*p - '0');
		p++;
	}
	b *= sign;

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		PRINT_ERROR();
		exit(100);
	}

	res = op(a, b);

	/* print integer result (inline, no helper symbol) */
	if (res == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	if (res < 0)
	{
		_putchar('-');
		ux = (unsigned int)(-res);
	}
	else
	{
		ux = (unsigned int)res;
	}

	{
		char buf[12];
		int top = 0;

		while (ux != 0)
		{
			buf[top++] = (char)('0' + (ux % 10));
			ux /= 10;
		}
		for (i = top - 1; i >= 0; i--)
			_putchar(buf[i]);
		_putchar('\n');
	}

	return (0);
}
