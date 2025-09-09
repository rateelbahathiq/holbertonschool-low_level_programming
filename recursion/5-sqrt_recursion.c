#include "main.h"

/**
 * find_sqrt - Helper function to find square root recursively
 * @n: The number to find square root of
 * @i: Current guess
 *
 * Return: Natural square root, or -1 if none
 */
int find_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (find_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to compute the square root of
 *
 * Return: Natural square root, or -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}

