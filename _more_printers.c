#include "main.h"

/**
  * _print_int_binary - Prints a int converted to binary
  * @args: A list of variadic arguments
  *
  * Return: The number of printed digits
  */
int _print_int_binary(va_list args)
{
	unsigned int x = 0;
	int b = 0;
	int new = 0;

	new = va_arg(args, int);
	x = new;
	if (new == 0)
	{
		_write('0');
		b += 1;
		return (b);
	}
	if (new < 0 && sizeof(new) != sizeof(unsigned int))
	{
		_write('%');
		_write('b');
		b += 2;
		return (b);
	}

	while (x > 0)
	{
		x = x / 2;
		b++;
	}
	_recursion_int_binary(new);
	return (b);
}

/**
  * _recursion_int_binary - Prints a binary
  * @a: integer to print
  *
  */
void _recursion_int_binary(int a)
{
	unsigned int t;

	t = a;
	if (t / 2)
		_recursion_int_binary(t / 2);
	_write(t % 2 + '0');


}
