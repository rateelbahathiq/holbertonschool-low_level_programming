#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything according to a format string
 * @format: list of types ('c' char, 'i' int, 'f' float, 's' char *)
 *
 * Notes:
 * - Unknown specifiers are ignored.
 * - If a string is NULL, prints (nil).
 * - Uses at most: 1 while, 1 if, no for/else/?:/do-while.
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	char *s;
	const char *sep = "";

	va_start(ap, format);
	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, (char)va_arg(ap, int));
			sep = ", ";
			break;
		case 'i':
			printf("%s%d", sep, va_arg(ap, int));
			sep = ", ";
			break;
		case 'f':
			printf("%s%f", sep, va_arg(ap, double));
			sep = ", ";
			break;
		case 's':
			s = va_arg(ap, char *);
			if (s == NULL)
				s = "(nil)";
			printf("%s%s", sep, s);
			sep = ", ";
			break;
		default:
			/* ignore unknown specifier */
			break;
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}
