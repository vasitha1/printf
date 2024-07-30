#include "main.h"

/**
 * _printf - Function that writes to standard output
 * @format: Formated string
 *
 * Return: Int number of characters printed (sucess), -1 if there is an error
 */
int _printf(const char *format, ...)
{
	unsigned int i, j, k, l, m, n, bytes_written, format_len, current_index;
	char *final_str, *type, **str_argument, *pt_back;
	va_list arguments;

	j = 0;/*To count the number of arguments*/
	l = 0;
	va_start(arguments, format);

	if (format == NULL)
	{
		write(2, "Error", 5);
		return (-1);
	}
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && i != 0 && (format[i - 1] != '%' && format[i - 1] != '\\'))
		{
			j++;
		}
	}
	type = malloc(j * sizeof(char));
	if (!type)
	{
		va_end(arguments);
		return (-1);
	}
	j = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && i != 0 && (format[i - 1] != '%' && format[i - 1] != '\\'))
		{
			type[j] = format[i + 1];
			j++;
		}
	}
	format_len = i - (2 * j);/*To remove the format specifiers counted*/
	
	str_argument = malloc(j * sizeof(char *));
	if (!str_argument)
	{
		free(type);
		va_end(arguments);
		return (-1);
	}
	for (k = 0; k < j; k++)
	{
		str_argument[k] = va_arg(arguments, char *);

		if (type[k] == 'c')
			l += 1;

		if (type[k] == 's')
		{
			pt_back = str_argument[k];
			while(*pt_back != '\0')
			{
				pt_back[k]++;
				l++;
			}
		}
	}
	va_end(arguments);
	k = 0;
	current_index = 0;
	final_str = malloc((format_len + l + 1) * sizeof(char));
	if (!final_str)
	{
		free(type);
		free(str_argument);
		return (-1);
	}
	for (m = 0; m < (i - j); m++)
	{
		if (format[m] == '%' && m != 0 && (format[m - 1] != '%' && format[m - 1] != '\\'))
		{
			if (type[k] == 'c')
			{
				final_str[current_index++] = *str_argument[k];
			}

			else if (type[k] == 's')
			{
				for (n = 0; *str_argument[n] != '\0'; n++)
				{
					final_str[current_index++] = *str_argument[k];
					str_argument[k]++;
				}
			}
			k++;
		}
		else if (format[m - 1] == '%' && final_str[current_index - 1] != '%')
			final_str[current_index++] = format[m];
	}
	final_str[current_index] = '\0';
	bytes_written = write(1, final_str, current_index);
	free(final_str);
	free(type);
	free(str_argument);
	return (bytes_written);
}
