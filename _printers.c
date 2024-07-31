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

/**
 * _print_integer - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int _print_integer(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_write('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_write(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_write(last + '0');

	return (i);
}

/**
 * _printf_decimal - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */

int _print_decimal(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit;
	int  i = 1;
	int exp = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_write('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_write(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_write(last + '0');

	return (i);
}
