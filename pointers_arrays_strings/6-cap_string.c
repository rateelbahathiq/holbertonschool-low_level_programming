#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to modify
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else
		{
			j = 0;
			while (sep[j] != '\0')
			{
				if (str[i - 1] == sep[j] && (str[i] >= 'a' && str[i] <= 'z'))
				{
					str[i] = str[i] - 32;
					break;
				}
				j++;
			}
		}
		i++;
	}
	return (str);
}
