#include "main.h"

/**
 * get_width - Calculates the width for printing.
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * @list: List of arguments to be printed.
 *
 * Return: Width value. If width is not specified, it returns 0.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the character is a digit */
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* Check if the character is '*' indicating width specified as an argument */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int); /* Extract width from va_list */
			break;
		}
		else
			break;
	}

	/* Update the current index to the end of width specification */
	*i = curr_i - 1;

	return (width);
}
