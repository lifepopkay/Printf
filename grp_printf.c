#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>

/**
 * _printf - prints a given text with proper format
 * @format: string to be printed
 * @...: variables to be added in string
 *
 * Return: the number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i;
	int count;
	int loct;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			loct = printer(format[++i], args);
			while (loct == -2)
			{
				count++;
				loct = printer(format[++i], args);
			}
			if (loct == -1)
				return (-1);
			count += loct;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
