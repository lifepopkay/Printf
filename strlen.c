#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _strlen - measures the length of a string
 * @str: string to be measured
 * Return: length of the string
 */
int _strlen(char *str)
{
	int count;

	count = 0;
	while (str && *str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
