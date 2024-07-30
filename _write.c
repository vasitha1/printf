#include <unistd.h>

/**
 * _write - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On sucess 1
 * On error, -1 is returned, and error is set appropriately
 */

int _write(char c)
{
	return (write(1, &c, 1));
}
