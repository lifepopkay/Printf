#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include "main.h"

/**
 * num_to_string - creates a string that represents a given integer
 * @num: integer to be represented
 * @str: empty string to be filled
 * Return: The representative string
 */
char *num_to_string(int num, char *str)
{
	char *start, *end, temp, *ptr;
	int i, len, is_negative;

	if (num == 0)
	{
		str = "0";
		return (str);
	}
	len = 0;
	is_negative = 0;
	ptr = str;
	if (num < 0)
	{
		if (num == INT_MIN)
			return ("-2147483648");
		len++;
		num = 0 - num;
		is_negative = 1;
	}
	for (i = 0; num > 0; i++)
	{
		*ptr++ = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative == 1)
		*ptr++ = '-';
	*ptr = '\0';
	end = ptr - 1;
	start = str;
	while (start < end)
	{
		temp = *start;
		*(start++) = *end;
		*(end--) = temp;
	}
	return (str);
}
