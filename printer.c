#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * printer -  function that finds formats for _printf
 * @i: variable
 * @args: argument
 * Return: NULL
 */

int printer(char i, va_list args)
{
	char *ss;
	char c, nts[20];
	int len;

	switch (i)
	{
		case 'c':
		    c = va_arg(args, int);
			write(1, &c, 1);
			return (1);
		case 's':
			ss = va_arg(args, char *);
			if (ss == NULL)
			{
				write(1, "(null)", 6);
				return (6);
			}
			len = _strlen(ss);
			write(1, ss, len);
			return (len);
		case 'i':
		case 'd':
			ss = num_to_string(va_arg(args, int), nts);
			len = _strlen(ss);
			write(1, ss, len);
			return (len);
		case '%':
			write(1, "%", 1);
			return (1);
		case ' ':
			write(1, " ", 1);
			return (-2);
		case '\0':
			return (-1);
		default:
			write(1, "%", 1);
			write(1, &i, 1);
			return (2);
	}
}
