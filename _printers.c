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

int _print_integer(va_list args)
{
	int count = 1, l = 0;
	unsigned int i = 0;

	i = va_arg(args, int);
	l = i;
	if (l < 0)
	{
		_write('-');
		l = l * -1;
		i = l;
		count += 1;
	}
	while (i < 9)
	{
		i = i / 10;
		count++;
	}

	_recursion_integer(l);
	return (count);
}

void _recursion_integer(int a)
{
	unsigned int i;

	i = a;
	if (i / 10)
		_recursion_integer(i / 10);
	_write(i % 10 + '0');
}
