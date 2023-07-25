#include "main.h"

/**
 * get_precision - Calculates the precision for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * @list: List of arguments to be printed.
 *
 * Return: Precision value. Returns -1 if precision is not specified.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if precision is specified by '.' */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Loop through the characters after '.' to extract precision value */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* Precision is specified as an argument, extract from va_list */
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	/* Update the current index to the end of precision specification */
	*i = curr_i - 1;

	return (precision);
}
