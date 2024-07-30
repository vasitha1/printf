#include "main.h"

/**
 * _print_char - Prints a char
 * @args: A list of variadic arguments
 *
 * Return: The length of the character
 */
int _print_char(va_list args)
{
	_write(va_arg(args, int));
	return (1);
}

/**
 * _print_string - Prints a string
 * @args: A list of variadic arguments
 *
 * Return: The length of the string
 */
int _print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i]);
			i++;
		}

		return (i);
	}
	_write('(');
	_write('n');
	_write('u');
	_write('l');
	_write('l');
	_write(')');
	return (6);
}
