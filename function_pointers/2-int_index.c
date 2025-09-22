#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array using a comparison function
 * @array: pointer to the first element of the integer array
 * @size: number of elements in the array
 * @cmp: pointer to a function used to compare values
 *
 * Return: the index of the first element for which cmp does not return 0,
 *         or -1 if no element matches or if size <= 0 or on NULL input.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}
