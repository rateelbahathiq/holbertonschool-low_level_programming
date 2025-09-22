#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: operator passed as argument
 *
 * Return: pointer to function that corresponds to the operator,
 *         or NULL if operator is not supported
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{0, 0}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (s[0] == ops[i].op[0] && s[1] == '\0')
			return (ops[i].f);
		i++;
	}
	return (0);
}
