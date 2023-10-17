#include "main.h"

/**
 * get_precision - a function that calculates the precision for printing
 * @format: a character string composed of zero or more directives
 * @i: an index pointer to the current position in the format string
 * @list: a list of arguments to be printed
 * Return: the precision as an integer, or -1 if there is no precision specified
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = 0;

	while (format[curr_i])
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
		curr_i++;
	}

	*i = curr_i - 1;

	return (precision);
}
