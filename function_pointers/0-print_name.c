#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: pointer to the string (name) to print
 * @f: function pointer that takes a char* and returns void
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
