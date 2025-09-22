#include <stdlib.h>
#include "3-calc.h"

/* Provided by checker */
int _putchar(char c);

/* tiny helper macro for "Error\n" */
#define PRINT_ERROR() do { \
	_putchar('E'); _putchar('r'); _putchar('r'); _putchar('o'); \
	_putchar('r'); _putchar('\n'); \
} while (0)

/**
 * main - simple calculator without if/loops
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exits with:
 *         98 (wrong arg count), 99 (unknown op), 100 (div by zero)
 */
int main(int argc, char *argv[])
{
	int a = 0, b = 0, res, sign, i;
	unsigned int ux;
	int (*op)(int, int);
	char *p;

	/* argc check (no if) */
	switch (argc)
	{
	case 4:
		break;
	default:
		PRINT_ERROR();
		exit(98);
	}

	op = get_op_func(argv[2]);

	/* unknown operator check (no if) */
	switch (op == 0)
	{
	case 1:
		PRINT_ERROR();
		exit(99);
	default:
		break;
	}

	/* ----- parse a ----- */
	p = argv[1];

trim_ws_a:
	switch (*p == ' ' || *p == '\t' || *p == '\n' ||
		*p == '\v' || *p == '\f' || *p == '\r')
	{
	case 1:
		p++;
		goto trim_ws_a;
	default:
		break;
	}

	sign = 1 - 2 * (*p == '-');
	p += (*p == '-' || *p == '+');

digits_a:
	switch (*p >= '0' && *p <= '9')
	{
	case 1:
		a = (a * 10) + (*p - '0');
		p++;
		goto digits_a;
	default:
		break;
	}
	a *= sign;

	/* ----- parse b ----- */
	p = argv[3];

trim_ws_b:
	switch (*p == ' ' || *p == '\t' || *p == '\n' ||
		*p == '\v' || *p == '\f' || *p == '\r')
	{
	case 1:
		p++;
		goto trim_ws_b;
	default:
		break;
	}

	sign = 1 - 2 * (*p == '-');
	p += (*p == '-' || *p == '+');

digits_b:
	switch (*p >= '0' && *p <= '9')
	{
	case 1:
		b = (b * 10) + (*p - '0');
		p++;
		goto digits_b;
	default:
		break;
	}
	b *= sign;

	/* div/mod by zero check (no if) */
	switch ((argv[2][0] == '/' || argv[2][0] == '%') && (b == 0))
	{
	case 1:
		PRINT_ERROR();
		exit(100);
	default:
		break;
	}

	res = op(a, b);

	/* handle zero result (no if) */
	switch (res == 0)
	{
	case 1:
		_putchar('0');
		_putchar('\n');
		return (0);
	default:
		break;
	}

	/* print result (no loops) */
	{
		int neg;
		char buf[12];
		int top;

		neg = (res < 0);
		switch (neg)
		{
		case 1:
			_putchar('-');
			ux = (unsigned int)(-res);
			break;
		default:
			ux = (unsigned int)res;
			break;
		}

		top = 0;

push_digits:
		buf[top++] = (char)('0' + (ux % 10));
		ux /= 10;
		switch (ux != 0)
		{
		case 1:
			goto push_digits;
		default:
			break;
		}

		i = top - 1;

print_rev:
		_putchar(buf[i]);
		i--;
		switch (i >= 0)
		{
		case 1:
			goto print_rev;
		default:
			break;
		}

		_putchar('\n');
	}

	return (0);
}
