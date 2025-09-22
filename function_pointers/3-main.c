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

#define PRINT_ERROR() do { \
		_putchar('E'); _putchar('r'); _putchar('r'); _putchar('o'); \
		_putchar('r'); _putchar('\n'); \
	} while (0)

	/* argc check without 'if' */
	switch (argc)
	{
	case 4:
		break;
	default:
		PRINT_ERROR();
		exit(98);
	}

	op = get_op_func(argv[2]);

	/* unknown operator check without 'if' */
	switch (op == 0)
	{
	case 1:
		PRINT_ERROR();
		exit(99);
	default:
		break;
	}

	/* parse a (trim spaces, sign, digits) */
	p = argv[1];
	while (*p == ' ' || *p == '\t' || *p == '\n' ||
	       *p == '\v' || *p == '\f' || *p == '\r')
		p++;
	sign = 1 - 2 * (*p == '-');
	p += (*p == '-' || *p == '+');
	while (*p >= '0' && *p <= '9')
	{
		a = (a * 10) + (*p - '0');
		p++;
	}
	a *= sign;

	/* parse b */
	p = argv[3];
	while (*p == ' ' || *p == '\t' || *p == '\n' ||
	       *p == '\v' || *p == '\f' || *p == '\r')
		p++;
	sign = 1 - 2 * (*p == '-');
	p += (*p == '-' || *p == '+');
	while (*p >= '0' && *p <= '9')
	{
		b = (b * 10) + (*p - '0');
		p++;
	}
	b *= sign;

	/* div/mod by zero check without 'if' */
	switch ((argv[2][0] == '/' || argv[2][0] == '%') && (b == 0))
	{
	case 1:
		PRINT_ERROR();
		exit(100);
	default:
		break;
	}

	res = op(a, b);

	/* print result (no if): handle sign with a single-iteration while,
	 * generate digits with do..while to cover zero, then print in reverse.
	 */
	{
		int neg = (res < 0);
		char buf[12];
		int top = 0;

		ux = neg ? (unsigned int)(-res) : (unsigned int)res;

		while (neg)
		{
			_putchar('-');
			neg = 0;
		}

		do {
			buf[top++] = (char)('0' + (ux % 10));
			ux /= 10;
		} while (ux != 0);

		for (i = top - 1; i >= 0; i--)
			_putchar(buf[i]);
		_putchar('\n');
	}

	return (0);
}
